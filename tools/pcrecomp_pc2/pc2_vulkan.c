/*
 * Native Vulkan window and presentation for the recovered game.
 *
 * This module owns the SDL window, the Vulkan instance/surface/swapchain,
 * the RGB565 upload, and the SDL-to-Win32 input pump. The guest's DirectDraw
 * framebuffer is still supplied by win32hle, but there is no win32hle window,
 * SDL renderer, frame-hook presenter, or GL bridge in the Vulkan path.
 */
#include "pc2_vulkan.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>
#include <vulkan/vulkan.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "win32hle.h"

#include "pc2_present_vert.h"
#include "pc2_present_frag.h"

#define MAX_FRAMES 2

typedef struct {
    SDL_Window *window;
    VkInstance instance;
    VkSurfaceKHR surface;
    VkPhysicalDevice physical;
    VkPhysicalDeviceMemoryProperties memory;
    VkDevice device;
    VkQueue queue;
    uint32_t queue_family;

    VkSwapchainKHR swapchain;
    VkFormat format;
    VkExtent2D extent;
    uint32_t image_count;
    VkImage *images;
    VkImageView *views;
    VkFramebuffer *framebuffers;
    VkRenderPass render_pass;
    VkPipeline pipeline;
    VkPipelineLayout pipeline_layout;
    VkDescriptorSetLayout descriptor_layout;
    VkDescriptorPool descriptor_pool;
    VkDescriptorSet descriptor_set;
    VkSampler sampler;
    VkShaderModule vertex_shader;
    VkShaderModule fragment_shader;

    VkCommandPool command_pool;
    VkCommandBuffer commands[MAX_FRAMES];
    VkSemaphore image_available[MAX_FRAMES];
    VkFence in_flight[MAX_FRAMES];
    VkSemaphore *render_finished;
    uint32_t frame;

    VkImage texture;
    VkDeviceMemory texture_memory;
    VkImageView texture_view;
    uint32_t texture_w, texture_h;
    int texture_initialized;

    VkBuffer staging;
    VkDeviceMemory staging_memory;
    void *staging_map;
    VkDeviceSize staging_size;

    VkBuffer capture_buffer;
    VkDeviceMemory capture_memory;
    void *capture_map;
    VkDeviceSize capture_size;
    char capture_path[1024];
    int capture_done;

    int viewport_x, viewport_y, viewport_w, viewport_h;
    int src_w, src_h;
    int initialized;
    int active;
    int failed;
    int logged_bpp;
    int cursor_shown;
    int fullscreen;
    int want_relative, relative;
    double rel_fx, rel_fy;
    void (*poll)(void);
    void (*present)(void);
    uint64_t frames_presented;
} vk_state;

static vk_state vk;

static int vk_ok(VkResult result, const char *what)
{
    if (result == VK_SUCCESS) return 0;
    fprintf(stderr, "[vulkan] %s failed: %d\n", what, (int)result);
    return -1;
}

static int has_extension(const VkExtensionProperties *props, uint32_t count, const char *name)
{
    for (uint32_t i = 0; i < count; i++)
        if (strcmp(props[i].extensionName, name) == 0) return 1;
    return 0;
}

static int find_memory_type(uint32_t bits, VkMemoryPropertyFlags wanted, uint32_t *out)
{
    for (uint32_t i = 0; i < vk.memory.memoryTypeCount; i++)
        if ((bits & (1u << i)) && (vk.memory.memoryTypes[i].propertyFlags & wanted) == wanted) {
            *out = i;
            return 0;
        }
    return -1;
}

static int create_buffer(VkDeviceSize size, VkBufferUsageFlags usage,
                         VkMemoryPropertyFlags properties, VkBuffer *buffer,
                         VkDeviceMemory *memory, void **mapped)
{
    VkBufferCreateInfo info = {0};
    info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    info.size = size;
    info.usage = usage;
    info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    if (vk_ok(vkCreateBuffer(vk.device, &info, NULL, buffer), "vkCreateBuffer")) return -1;

    VkMemoryRequirements req;
    vkGetBufferMemoryRequirements(vk.device, *buffer, &req);
    uint32_t type = 0;
    if (find_memory_type(req.memoryTypeBits, properties, &type) != 0) {
        fprintf(stderr, "[vulkan] no memory type for buffer\n");
        vkDestroyBuffer(vk.device, *buffer, NULL);
        *buffer = VK_NULL_HANDLE;
        return -1;
    }
    VkMemoryAllocateInfo allocate = {0};
    allocate.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocate.allocationSize = req.size;
    allocate.memoryTypeIndex = type;
    if (vk_ok(vkAllocateMemory(vk.device, &allocate, NULL, memory), "vkAllocateMemory")) {
        vkDestroyBuffer(vk.device, *buffer, NULL);
        *buffer = VK_NULL_HANDLE;
        return -1;
    }
    vkBindBufferMemory(vk.device, *buffer, *memory, 0);
    if (mapped) {
        if (vk_ok(vkMapMemory(vk.device, *memory, 0, VK_WHOLE_SIZE, 0, mapped), "vkMapMemory")) {
            return -1;
        }
    }
    return 0;
}

static void destroy_buffer(VkBuffer *buffer, VkDeviceMemory *memory, void **mapped)
{
    if (*mapped) {
        vkUnmapMemory(vk.device, *memory);
        *mapped = NULL;
    }
    if (*buffer) vkDestroyBuffer(vk.device, *buffer, NULL);
    if (*memory) vkFreeMemory(vk.device, *memory, NULL);
    *buffer = VK_NULL_HANDLE;
    *memory = VK_NULL_HANDLE;
}

static int create_image(uint32_t w, uint32_t h, VkFormat format,
                        VkImageUsageFlags usage, VkImage *image,
                        VkDeviceMemory *memory, VkImageView *view)
{
    VkImageCreateInfo info = {0};
    info.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    info.imageType = VK_IMAGE_TYPE_2D;
    info.format = format;
    info.extent.width = w;
    info.extent.height = h;
    info.extent.depth = 1;
    info.mipLevels = 1;
    info.arrayLayers = 1;
    info.samples = VK_SAMPLE_COUNT_1_BIT;
    info.tiling = VK_IMAGE_TILING_OPTIMAL;
    info.usage = usage;
    info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    info.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    if (vk_ok(vkCreateImage(vk.device, &info, NULL, image), "vkCreateImage")) return -1;

    VkMemoryRequirements req;
    vkGetImageMemoryRequirements(vk.device, *image, &req);
    uint32_t type = 0;
    if (find_memory_type(req.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, &type) != 0) {
        fprintf(stderr, "[vulkan] no device-local image memory\n");
        return -1;
    }
    VkMemoryAllocateInfo allocate = {0};
    allocate.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocate.allocationSize = req.size;
    allocate.memoryTypeIndex = type;
    if (vk_ok(vkAllocateMemory(vk.device, &allocate, NULL, memory), "vkAllocateMemory(image)")) return -1;
    vkBindImageMemory(vk.device, *image, *memory, 0);

    VkImageViewCreateInfo view_info = {0};
    view_info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    view_info.image = *image;
    view_info.viewType = VK_IMAGE_VIEW_TYPE_2D;
    view_info.format = format;
    view_info.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    view_info.subresourceRange.levelCount = 1;
    view_info.subresourceRange.layerCount = 1;
    return vk_ok(vkCreateImageView(vk.device, &view_info, NULL, view), "vkCreateImageView");
}

static void destroy_image(VkImage *image, VkDeviceMemory *memory, VkImageView *view)
{
    if (*view) vkDestroyImageView(vk.device, *view, NULL);
    if (*image) vkDestroyImage(vk.device, *image, NULL);
    if (*memory) vkFreeMemory(vk.device, *memory, NULL);
    *image = VK_NULL_HANDLE;
    *memory = VK_NULL_HANDLE;
    *view = VK_NULL_HANDLE;
}

static int choose_surface_format(VkSurfaceKHR surface, VkFormat *format,
                                 VkColorSpaceKHR *color_space)
{
    uint32_t count = 0;
    vkGetPhysicalDeviceSurfaceFormatsKHR(vk.physical, surface, &count, NULL);
    if (!count) return -1;
    VkSurfaceFormatKHR *formats = calloc(count, sizeof(*formats));
    vkGetPhysicalDeviceSurfaceFormatsKHR(vk.physical, surface, &count, formats);

    /* Only UNORM formats keep the RGB565 expansion byte-exact. An sRGB
     * swapchain would gamma-encode the shader output and change the colours. */
    static const VkFormat wanted[] = {
        VK_FORMAT_B8G8R8A8_UNORM,
        VK_FORMAT_R8G8B8A8_UNORM,
    };
    int found = 0;
    VkSurfaceFormatKHR chosen = formats[0];
    for (size_t w = 0; w < sizeof(wanted) / sizeof(wanted[0]) && !found; w++) {
        for (uint32_t i = 0; i < count; i++) {
            if (formats[i].format == wanted[w] &&
                formats[i].colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
                chosen = formats[i];
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        for (uint32_t i = 0; i < count; i++) {
            if (formats[i].format == VK_FORMAT_B8G8R8A8_UNORM ||
                formats[i].format == VK_FORMAT_R8G8B8A8_UNORM) {
                chosen = formats[i];
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        fprintf(stderr, "[vulkan] no UNORM 8-bit surface format (count=%u)\n", count);
        free(formats);
        return -1;
    }

    /* A capture reads the swapchain back as 8-bit RGBA/BGRA. */
    if (vk.capture_path[0] &&
        chosen.format != VK_FORMAT_B8G8R8A8_UNORM &&
        chosen.format != VK_FORMAT_R8G8B8A8_UNORM) {
        fprintf(stderr, "[vulkan] capture disabled for swapchain format %d\n",
                (int)chosen.format);
        vk.capture_path[0] = '\0';
    }

    *format = chosen.format;
    *color_space = chosen.colorSpace;
    fprintf(stderr, "[vulkan] surface format %d colour-space %d\n",
            (int)chosen.format, (int)chosen.colorSpace);
    free(formats);
    return 0;
}

static int create_pipeline(void)
{
    VkAttachmentDescription attachment = {0};
    attachment.format = vk.format;
    attachment.samples = VK_SAMPLE_COUNT_1_BIT;
    attachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    attachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    attachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    attachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    attachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

    VkAttachmentReference color_ref = {0};
    color_ref.attachment = 0;
    color_ref.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkSubpassDescription subpass = {0};
    subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount = 1;
    subpass.pColorAttachments = &color_ref;

    VkSubpassDependency dependency = {0};
    dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
    dependency.dstSubpass = 0;
    dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

    VkRenderPassCreateInfo render_info = {0};
    render_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    render_info.attachmentCount = 1;
    render_info.pAttachments = &attachment;
    render_info.subpassCount = 1;
    render_info.pSubpasses = &subpass;
    render_info.dependencyCount = 1;
    render_info.pDependencies = &dependency;
    if (vk_ok(vkCreateRenderPass(vk.device, &render_info, NULL, &vk.render_pass), "vkCreateRenderPass"))
        return -1;

    VkPipelineShaderStageCreateInfo stages[2] = {{0}};
    stages[0].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    stages[0].stage = VK_SHADER_STAGE_VERTEX_BIT;
    stages[0].module = vk.vertex_shader;
    stages[0].pName = "main";
    stages[1].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    stages[1].stage = VK_SHADER_STAGE_FRAGMENT_BIT;
    stages[1].module = vk.fragment_shader;
    stages[1].pName = "main";

    VkPipelineVertexInputStateCreateInfo vertex_input = {0};
    vertex_input.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;

    VkPipelineInputAssemblyStateCreateInfo assembly = {0};
    assembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    assembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;

    VkPipelineViewportStateCreateInfo viewport_state = {0};
    viewport_state.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    viewport_state.viewportCount = 1;
    viewport_state.scissorCount = 1;

    VkPipelineRasterizationStateCreateInfo raster = {0};
    raster.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    raster.polygonMode = VK_POLYGON_MODE_FILL;
    raster.cullMode = VK_CULL_MODE_NONE;
    raster.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;
    raster.lineWidth = 1.0f;

    VkPipelineMultisampleStateCreateInfo multisample = {0};
    multisample.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    multisample.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;

    VkPipelineDepthStencilStateCreateInfo depth = {0};
    depth.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
    depth.depthTestEnable = VK_FALSE;
    depth.depthWriteEnable = VK_FALSE;

    VkPipelineColorBlendAttachmentState blend_attachment = {0};
    blend_attachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT |
                                      VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
    VkPipelineColorBlendStateCreateInfo blend = {0};
    blend.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    blend.attachmentCount = 1;
    blend.pAttachments = &blend_attachment;

    VkDynamicState dynamic_states[2] = {VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR};
    VkPipelineDynamicStateCreateInfo dynamic = {0};
    dynamic.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    dynamic.dynamicStateCount = 2;
    dynamic.pDynamicStates = dynamic_states;

    VkGraphicsPipelineCreateInfo pipeline_info = {0};
    pipeline_info.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    pipeline_info.stageCount = 2;
    pipeline_info.pStages = stages;
    pipeline_info.pVertexInputState = &vertex_input;
    pipeline_info.pInputAssemblyState = &assembly;
    pipeline_info.pViewportState = &viewport_state;
    pipeline_info.pRasterizationState = &raster;
    pipeline_info.pMultisampleState = &multisample;
    pipeline_info.pDepthStencilState = &depth;
    pipeline_info.pColorBlendState = &blend;
    pipeline_info.pDynamicState = &dynamic;
    pipeline_info.layout = vk.pipeline_layout;
    pipeline_info.renderPass = vk.render_pass;
    pipeline_info.subpass = 0;
    return vk_ok(vkCreateGraphicsPipelines(vk.device, VK_NULL_HANDLE, 1,
                                           &pipeline_info, NULL, &vk.pipeline),
                 "vkCreateGraphicsPipelines");
}

static void destroy_swapchain(void)
{
    if (!vk.device) return;
    vkDeviceWaitIdle(vk.device);
    for (uint32_t i = 0; i < vk.image_count; i++) {
        if (vk.framebuffers && vk.framebuffers[i]) vkDestroyFramebuffer(vk.device, vk.framebuffers[i], NULL);
        if (vk.views && vk.views[i]) vkDestroyImageView(vk.device, vk.views[i], NULL);
    }
    free(vk.framebuffers); vk.framebuffers = NULL;
    free(vk.views); vk.views = NULL;
    free(vk.images); vk.images = NULL;
    if (vk.pipeline) vkDestroyPipeline(vk.device, vk.pipeline, NULL);
    if (vk.render_pass) vkDestroyRenderPass(vk.device, vk.render_pass, NULL);
    if (vk.render_finished) {
        for (uint32_t i = 0; i < vk.image_count; i++)
            if (vk.render_finished[i]) vkDestroySemaphore(vk.device, vk.render_finished[i], NULL);
        free(vk.render_finished); vk.render_finished = NULL;
    }
    if (vk.swapchain) vkDestroySwapchainKHR(vk.device, vk.swapchain, NULL);
    vk.swapchain = VK_NULL_HANDLE;
    vk.image_count = 0;
    vk.pipeline = VK_NULL_HANDLE;
    vk.render_pass = VK_NULL_HANDLE;
    destroy_buffer(&vk.capture_buffer, &vk.capture_memory, &vk.capture_map);
    vk.capture_size = 0;
}

static int create_swapchain(int width, int height)
{
    VkSurfaceCapabilitiesKHR caps;
    if (vk_ok(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(vk.physical, vk.surface, &caps),
              "vkGetPhysicalDeviceSurfaceCapabilitiesKHR"))
        return -1;

    VkExtent2D extent;
    if (caps.currentExtent.width != UINT32_MAX) {
        extent = caps.currentExtent;
    } else {
        extent.width = (uint32_t)width;
        extent.height = (uint32_t)height;
        if (extent.width < caps.minImageExtent.width) extent.width = caps.minImageExtent.width;
        if (extent.width > caps.maxImageExtent.width) extent.width = caps.maxImageExtent.width;
        if (extent.height < caps.minImageExtent.height) extent.height = caps.minImageExtent.height;
        if (extent.height > caps.maxImageExtent.height) extent.height = caps.maxImageExtent.height;
    }
    if (extent.width == 0 || extent.height == 0) return 1;

    VkColorSpaceKHR color_space = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
    if (choose_surface_format(vk.surface, &vk.format, &color_space) != 0) return -1;

    uint32_t image_count = caps.minImageCount + 1;
    if (caps.maxImageCount && image_count > caps.maxImageCount) image_count = caps.maxImageCount;

    VkSwapchainCreateInfoKHR info = {0};
    info.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    info.surface = vk.surface;
    info.minImageCount = image_count;
    info.imageFormat = vk.format;
    info.imageColorSpace = color_space;
    info.imageExtent = extent;
    info.imageArrayLayers = 1;
    info.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    info.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    info.preTransform = caps.currentTransform;
    info.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    info.presentMode = VK_PRESENT_MODE_FIFO_KHR;
    info.clipped = VK_TRUE;
    if (vk_ok(vkCreateSwapchainKHR(vk.device, &info, NULL, &vk.swapchain), "vkCreateSwapchainKHR"))
        return -1;
    vk.extent = extent;

    vkGetSwapchainImagesKHR(vk.device, vk.swapchain, &vk.image_count, NULL);
    vk.images = calloc(vk.image_count, sizeof(*vk.images));
    vk.views = calloc(vk.image_count, sizeof(*vk.views));
    vk.framebuffers = calloc(vk.image_count, sizeof(*vk.framebuffers));
    vk.render_finished = calloc(vk.image_count, sizeof(*vk.render_finished));
    vkGetSwapchainImagesKHR(vk.device, vk.swapchain, &vk.image_count, vk.images);

    for (uint32_t i = 0; i < vk.image_count; i++) {
        VkImageViewCreateInfo view_info = {0};
        view_info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        view_info.image = vk.images[i];
        view_info.viewType = VK_IMAGE_VIEW_TYPE_2D;
        view_info.format = vk.format;
        view_info.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        view_info.subresourceRange.levelCount = 1;
        view_info.subresourceRange.layerCount = 1;
        if (vk_ok(vkCreateImageView(vk.device, &view_info, NULL, &vk.views[i]),
                  "vkCreateImageView(swapchain)"))
            return -1;
        VkSemaphoreCreateInfo semaphore_info = {0};
        semaphore_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
        if (vk_ok(vkCreateSemaphore(vk.device, &semaphore_info, NULL, &vk.render_finished[i]),
                  "vkCreateSemaphore(render)"))
            return -1;
    }

    if (create_pipeline() != 0) return -1;

    for (uint32_t i = 0; i < vk.image_count; i++) {
        VkFramebufferCreateInfo fb_info = {0};
        fb_info.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        fb_info.renderPass = vk.render_pass;
        fb_info.attachmentCount = 1;
        fb_info.pAttachments = &vk.views[i];
        fb_info.width = vk.extent.width;
        fb_info.height = vk.extent.height;
        fb_info.layers = 1;
        if (vk_ok(vkCreateFramebuffer(vk.device, &fb_info, NULL, &vk.framebuffers[i]),
                  "vkCreateFramebuffer"))
            return -1;
    }

    if (vk.capture_path[0]) {
        vk.capture_size = (VkDeviceSize)vk.extent.width * vk.extent.height * 4;
        if (create_buffer(vk.capture_size, VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                          VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
                          &vk.capture_buffer, &vk.capture_memory, &vk.capture_map) != 0)
            return -1;
    }

    fprintf(stderr, "[vulkan] swapchain %ux%u format=%d present=FIFO images=%u\n",
            vk.extent.width, vk.extent.height, (int)vk.format, vk.image_count);
    return 0;
}

static int recreate_swapchain(int width, int height)
{
    destroy_swapchain();
    vk.frame = 0;
    return create_swapchain(width, height);
}

static int ensure_texture(uint32_t w, uint32_t h)
{
    if (vk.texture && vk.texture_w == w && vk.texture_h == h) return 0;
    vkDeviceWaitIdle(vk.device);
    destroy_image(&vk.texture, &vk.texture_memory, &vk.texture_view);
    if (create_image(w, h, VK_FORMAT_R8G8B8A8_UNORM,
                     VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT,
                     &vk.texture, &vk.texture_memory, &vk.texture_view) != 0)
        return -1;
    vk.texture_w = w;
    vk.texture_h = h;
    vk.texture_initialized = 0;

    VkDescriptorImageInfo image_info = {0};
    image_info.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
    image_info.imageView = vk.texture_view;
    image_info.sampler = vk.sampler;
    VkWriteDescriptorSet write = {0};
    write.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    write.dstSet = vk.descriptor_set;
    write.dstBinding = 0;
    write.descriptorCount = 1;
    write.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    write.pImageInfo = &image_info;
    vkUpdateDescriptorSets(vk.device, 1, &write, 0, NULL);
    return 0;
}

static int ensure_staging(uint32_t w, uint32_t h)
{
    VkDeviceSize size = (VkDeviceSize)w * h * 4;
    if (vk.staging && vk.staging_size >= size) return 0;
    vkDeviceWaitIdle(vk.device);
    destroy_buffer(&vk.staging, &vk.staging_memory, &vk.staging_map);
    if (create_buffer(size, VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
                      VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
                      &vk.staging, &vk.staging_memory, &vk.staging_map) != 0)
        return -1;
    vk.staging_size = size;
    return 0;
}

static void image_barrier(VkCommandBuffer cmd, VkImage image,
                          VkImageLayout old_layout, VkImageLayout new_layout,
                          VkAccessFlags src_access, VkAccessFlags dst_access,
                          VkPipelineStageFlags src_stage, VkPipelineStageFlags dst_stage)
{
    VkImageMemoryBarrier barrier = {0};
    barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    barrier.oldLayout = old_layout;
    barrier.newLayout = new_layout;
    barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrier.image = image;
    barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    barrier.subresourceRange.levelCount = 1;
    barrier.subresourceRange.layerCount = 1;
    barrier.srcAccessMask = src_access;
    barrier.dstAccessMask = dst_access;
    vkCmdPipelineBarrier(cmd, src_stage, dst_stage, 0, 0, NULL, 0, NULL, 1, &barrier);
}

static int frame_has_content(const uint8_t *pixels, int w, int h, int pitch)
{
    int nonzero = 0, distinct = 0;
    uint32_t seen[64];
    for (int y = 0; y < h; y += 8) {
        const uint16_t *row = (const uint16_t *)(pixels + (size_t)y * pitch);
        for (int x = 0; x < w; x += 8) {
            uint16_t v = row[x];
            if (v) nonzero++;
            int found = 0;
            for (int i = 0; i < distinct; i++) if (seen[i] == v) { found = 1; break; }
            if (!found && distinct < 64) seen[distinct++] = v;
        }
    }
    return nonzero > 200 && distinct > 8;
}

static void write_source_ppm(const char *path, const uint8_t *pixels,
                               int w, int h, int pitch)
{
    FILE *f = fopen(path, "wb");
    if (!f) return;
    fprintf(f, "P6\n%d %d\n255\n", w, h);
    for (int y = 0; y < h; y++) {
        const uint16_t *row = (const uint16_t *)(pixels + (size_t)y * pitch);
        for (int x = 0; x < w; x++) {
            uint16_t v = row[x];
            unsigned char rgb[3] = {
                (unsigned char)(((v >> 11) & 0x1f) * 255 / 31),
                (unsigned char)(((v >> 5) & 0x3f) * 255 / 63),
                (unsigned char)((v & 0x1f) * 255 / 31)};
            fwrite(rgb, 1, 3, f);
        }
    }
    fclose(f);
    fprintf(stderr, "[vulkan] source frame %s %dx%d\n", path, w, h);
}

static void write_capture(const char *path)
{
    uint32_t w = vk.extent.width, h = vk.extent.height;
    FILE *f = fopen(path, "wb");
    if (!f) { fprintf(stderr, "[vulkan] capture open failed: %s\n", path); return; }
    fprintf(f, "P6\n%u %u\n255\n", w, h);
    const uint8_t *src = (const uint8_t *)vk.capture_map;
    uint32_t checksum = 2166136261u;
    for (uint32_t y = 0; y < h; y++) {
        for (uint32_t x = 0; x < w; x++) {
            const uint8_t *p = src + ((size_t)y * w + x) * 4;
            uint8_t rgb[3];
            if (vk.format == VK_FORMAT_B8G8R8A8_UNORM) {
                rgb[0] = p[2]; rgb[1] = p[1]; rgb[2] = p[0];
            } else {
                rgb[0] = p[0]; rgb[1] = p[1]; rgb[2] = p[2];
            }
            for (int i = 0; i < 3; i++) checksum = (checksum ^ rgb[i]) * 16777619u;
            fwrite(rgb, 1, 3, f);
        }
    }
    fclose(f);
    fprintf(stderr, "[vulkan] captured presented frame %s %ux%u checksum=%08X\n",
            path, w, h, checksum);
}

static int draw_frame(const uint8_t *pixels, int w, int h, int pitch, int menu_ready)
{
    if (ensure_texture((uint32_t)w, (uint32_t)h) != 0) { vk.failed = 1; return -1; }
    if (ensure_staging((uint32_t)w, (uint32_t)h) != 0) { vk.failed = 1; return -1; }

    uint8_t *dst = (uint8_t *)vk.staging_map;
    for (int y = 0; y < h; y++) {
        const uint16_t *row = (const uint16_t *)(pixels + (size_t)y * pitch);
        for (int x = 0; x < w; x++) {
            uint16_t v = row[x];
            uint8_t r = (uint8_t)(((v >> 11) & 0x1f) * 255 / 31);
            uint8_t g = (uint8_t)(((v >> 5) & 0x3f) * 255 / 63);
            uint8_t b = (uint8_t)((v & 0x1f) * 255 / 31);
            uint8_t *p = dst + ((size_t)y * w + x) * 4;
            p[0] = r; p[1] = g; p[2] = b; p[3] = 255;
        }
    }

    if (vk_ok(vkWaitForFences(vk.device, 1, &vk.in_flight[vk.frame], VK_TRUE, UINT64_MAX),
              "vkWaitForFences"))
        { vk.failed = 1; return -1; }

    uint32_t image_index;
    VkResult acquired = vkAcquireNextImageKHR(vk.device, vk.swapchain, UINT64_MAX,
                                             vk.image_available[vk.frame], VK_NULL_HANDLE,
                                             &image_index);
    if (acquired == VK_ERROR_OUT_OF_DATE_KHR) {
        /* Keep the fence signaled: this frame is dropped without a submit, and
         * resetting it here would make the next frame wait forever. */
        int dw, dh;
        SDL_Vulkan_GetDrawableSize(vk.window, &dw, &dh);
        if (dw <= 0 || dh <= 0) return 1;
        int result = recreate_swapchain(dw, dh);
        if (result < 0) vk.failed = 1;
        return result;
    }
    if (acquired != VK_SUCCESS && acquired != VK_SUBOPTIMAL_KHR) {
        fprintf(stderr, "[vulkan] acquire failed: %d\n", (int)acquired);
        vk.failed = 1;
        return -1;
    }
    vkResetFences(vk.device, 1, &vk.in_flight[vk.frame]);

    int dw = (int)vk.extent.width, dh = (int)vk.extent.height;
    int vw = dw, vh = (int)((int64_t)dw * h / w);
    if (vh > dh) { vh = dh; vw = (int)((int64_t)dh * w / h); }
    int vx = (dw - vw) / 2, vy = (dh - vh) / 2;
    vk.viewport_x = vx; vk.viewport_y = vy; vk.viewport_w = vw; vk.viewport_h = vh;

    int capture = vk.capture_path[0] && !vk.capture_done && menu_ready &&
                  frame_has_content(pixels, w, h, pitch);
    if (capture) {
        const char *source_path = getenv("PC2_VULKAN_SOURCE");
        if (source_path && *source_path) write_source_ppm(source_path, pixels, w, h, pitch);
    }

    VkCommandBuffer cmd = vk.commands[vk.frame];
    vkResetCommandBuffer(cmd, 0);
    VkCommandBufferBeginInfo begin = {0};
    begin.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    begin.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    vkBeginCommandBuffer(cmd, &begin);

    image_barrier(cmd, vk.texture,
                  vk.texture_initialized ? VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL
                                         : VK_IMAGE_LAYOUT_UNDEFINED,
                  VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                  vk.texture_initialized ? VK_ACCESS_SHADER_READ_BIT : 0,
                  VK_ACCESS_TRANSFER_WRITE_BIT,
                  vk.texture_initialized ? VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT
                                         : VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                  VK_PIPELINE_STAGE_TRANSFER_BIT);
    VkBufferImageCopy region = {0};
    region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    region.imageSubresource.layerCount = 1;
    region.imageExtent.width = (uint32_t)w;
    region.imageExtent.height = (uint32_t)h;
    region.imageExtent.depth = 1;
    vkCmdCopyBufferToImage(cmd, vk.staging, vk.texture,
                           VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &region);
    image_barrier(cmd, vk.texture,
                  VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                  VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
                  VK_ACCESS_TRANSFER_WRITE_BIT, VK_ACCESS_SHADER_READ_BIT,
                  VK_PIPELINE_STAGE_TRANSFER_BIT,
                  VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT);
    vk.texture_initialized = 1;

    VkClearValue clear = {0};
    clear.color.float32[0] = 0.0f;
    clear.color.float32[1] = 0.0f;
    clear.color.float32[2] = 0.0f;
    clear.color.float32[3] = 1.0f;
    VkRenderPassBeginInfo pass = {0};
    pass.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    pass.renderPass = vk.render_pass;
    pass.framebuffer = vk.framebuffers[image_index];
    pass.renderArea.extent = vk.extent;
    pass.clearValueCount = 1;
    pass.pClearValues = &clear;
    vkCmdBeginRenderPass(cmd, &pass, VK_SUBPASS_CONTENTS_INLINE);
    vkCmdBindPipeline(cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, vk.pipeline);
    vkCmdBindDescriptorSets(cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, vk.pipeline_layout,
                            0, 1, &vk.descriptor_set, 0, NULL);
    VkViewport viewport = {0};
    viewport.x = (float)vx;
    viewport.y = (float)vy;
    viewport.width = (float)vw;
    viewport.height = (float)vh;
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;
    VkRect2D scissor = {{vx, vy}, {(uint32_t)vw, (uint32_t)vh}};
    vkCmdSetViewport(cmd, 0, 1, &viewport);
    vkCmdSetScissor(cmd, 0, 1, &scissor);
    vkCmdDraw(cmd, 3, 1, 0, 0);
    vkCmdEndRenderPass(cmd);

    if (capture) {
        image_barrier(cmd, vk.images[image_index],
                      VK_IMAGE_LAYOUT_PRESENT_SRC_KHR, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                      VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT, VK_ACCESS_TRANSFER_READ_BIT,
                      VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                      VK_PIPELINE_STAGE_TRANSFER_BIT);
        VkBufferImageCopy copy = {0};
        copy.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        copy.imageSubresource.layerCount = 1;
        copy.imageExtent.width = vk.extent.width;
        copy.imageExtent.height = vk.extent.height;
        copy.imageExtent.depth = 1;
        vkCmdCopyImageToBuffer(cmd, vk.images[image_index],
                               VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                               vk.capture_buffer, 1, &copy);
        image_barrier(cmd, vk.images[image_index],
                      VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
                      VK_ACCESS_TRANSFER_READ_BIT, 0,
                      VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT);
    }

    vkEndCommandBuffer(cmd);

    VkPipelineStageFlags wait_stage = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    VkSubmitInfo submit = {0};
    submit.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit.waitSemaphoreCount = 1;
    submit.pWaitSemaphores = &vk.image_available[vk.frame];
    submit.pWaitDstStageMask = &wait_stage;
    submit.commandBufferCount = 1;
    submit.pCommandBuffers = &cmd;
    submit.signalSemaphoreCount = 1;
    submit.pSignalSemaphores = &vk.render_finished[image_index];
    if (vk_ok(vkQueueSubmit(vk.queue, 1, &submit, vk.in_flight[vk.frame]), "vkQueueSubmit"))
        { vk.failed = 1; return -1; }

    if (capture) {
        vkWaitForFences(vk.device, 1, &vk.in_flight[vk.frame], VK_TRUE, UINT64_MAX);
        write_capture(vk.capture_path);
        vk.capture_done = 1;
    }

    VkPresentInfoKHR present = {0};
    present.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
    present.waitSemaphoreCount = 1;
    present.pWaitSemaphores = &vk.render_finished[image_index];
    present.swapchainCount = 1;
    present.pSwapchains = &vk.swapchain;
    present.pImageIndices = &image_index;
    VkResult presented = vkQueuePresentKHR(vk.queue, &present);
    if (presented == VK_ERROR_OUT_OF_DATE_KHR || presented == VK_ERROR_SURFACE_LOST_KHR) {
        int nw, nh;
        SDL_Vulkan_GetDrawableSize(vk.window, &nw, &nh);
        if (nw > 0 && nh > 0) {
            int result = recreate_swapchain(nw, nh);
            if (result < 0) vk.failed = 1;
            return result;
        }
    } else if (presented != VK_SUCCESS && presented != VK_SUBOPTIMAL_KHR) {
        fprintf(stderr, "[vulkan] present failed: %d\n", (int)presented);
        vk.failed = 1;
        return -1;
    }

    vk.frame = (vk.frame + 1) % MAX_FRAMES;
    vk.frames_presented++;
    if (getenv("PC2_VULKAN_STATS") && vk.frames_presented % 300 == 0)
        fprintf(stderr, "[vulkan] presented=%llu swapchain=%ux%u\n",
                (unsigned long long)vk.frames_presented,
                vk.extent.width, vk.extent.height);
    return 0;
}

static void pc2_vulkan_warp(int x, int y);
static void pc2_vulkan_relative(int on);
static int init_vulkan(SDL_Window *window);

int pc2_vulkan_open(const char *title, void (*poll)(void), void (*present)(void))
{
    memset(&vk, 0, sizeof(vk));
    vk.poll = poll;
    vk.present = present;
    vk.viewport_w = 800;
    vk.viewport_h = 600;
    vk.src_w = 800;
    vk.src_h = 600;

    const char *capture = getenv("PC2_VULKAN_CAPTURE");
    if (capture && *capture)
        snprintf(vk.capture_path, sizeof(vk.capture_path), "%s", capture);

    SDL_SetHint(SDL_HINT_NO_SIGNAL_HANDLERS, "1");
    if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "[vulkan] SDL video: %s\n", SDL_GetError());
        return -1;
    }

    int width = 1280, height = 960;
    const char *size = getenv("PC2_VULKAN_WINDOW");
    if (size && *size) {
        int w = 0, h = 0;
        if (sscanf(size, "%dx%d", &w, &h) == 2 && w > 0 && h > 0)
            width = w, height = h;
    } else if (vk.capture_path[0]) {
        width = 800, height = 600;
    }

    vk.window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                 width, height,
                                 SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE |
                                 SDL_WINDOW_ALLOW_HIGHDPI);
    if (!vk.window) {
        fprintf(stderr, "[vulkan] window: %s\n", SDL_GetError());
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
        return -1;
    }
    SDL_ShowCursor(SDL_DISABLE);
    fprintf(stderr, "[vulkan] window %dx%d driver=%s\n", width, height,
            SDL_GetCurrentVideoDriver());

    if (init_vulkan(vk.window) != 0) {
        SDL_DestroyWindow(vk.window);
        vk.window = NULL;
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
        return -1;
    }

    hle_cursor_hook = pc2_vulkan_warp;
    hle_input_relative_hook = pc2_vulkan_relative;
    hle_set_pump_hook(pc2_vulkan_pump);
    return 0;
}

static int init_vulkan(SDL_Window *window)
{
    vk.window = window;
    vk.viewport_w = 800;
    vk.viewport_h = 600;
    vk.src_w = 800;
    vk.src_h = 600;

    if (!window) {
        fprintf(stderr, "[vulkan] no SDL window\n");
        return -1;
    }

    if (SDL_Vulkan_LoadLibrary(NULL) != 0) {
        fprintf(stderr, "[vulkan] SDL_Vulkan_LoadLibrary: %s\n", SDL_GetError());
        return -1;
    }

    unsigned extension_count = 0;
    if (!SDL_Vulkan_GetInstanceExtensions(window, &extension_count, NULL)) {
        fprintf(stderr, "[vulkan] instance extensions: %s\n", SDL_GetError());
        return -1;
    }
    const char **extensions = calloc(extension_count, sizeof(*extensions));
    if (!SDL_Vulkan_GetInstanceExtensions(window, &extension_count, extensions)) {
        fprintf(stderr, "[vulkan] instance extensions: %s\n", SDL_GetError());
        free(extensions);
        return -1;
    }
    VkApplicationInfo app = {0};
    app.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app.pApplicationName = "OpenPizza2";
    app.applicationVersion = 1;
    app.pEngineName = "PC2 native";
    app.engineVersion = 1;
    app.apiVersion = VK_API_VERSION_1_0;
    VkInstanceCreateInfo instance_info = {0};
    instance_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instance_info.pApplicationInfo = &app;
    instance_info.enabledExtensionCount = extension_count;
    instance_info.ppEnabledExtensionNames = extensions;
    if (vk_ok(vkCreateInstance(&instance_info, NULL, &vk.instance), "vkCreateInstance")) {
        free(extensions);
        return -1;
    }
    free(extensions);

    if (!SDL_Vulkan_CreateSurface(window, vk.instance, &vk.surface)) {
        fprintf(stderr, "[vulkan] SDL_Vulkan_CreateSurface: %s\n", SDL_GetError());
        return -1;
    }

    uint32_t device_count = 0;
    vkEnumeratePhysicalDevices(vk.instance, &device_count, NULL);
    if (!device_count) {
        fprintf(stderr, "[vulkan] no physical devices\n");
        return -1;
    }
    VkPhysicalDevice *devices = calloc(device_count, sizeof(*devices));
    vkEnumeratePhysicalDevices(vk.instance, &device_count, devices);
    int chosen = -1, best = -1;
    for (uint32_t i = 0; i < device_count; i++) {
        VkPhysicalDeviceProperties props;
        vkGetPhysicalDeviceProperties(devices[i], &props);
        uint32_t families = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(devices[i], &families, NULL);
        VkQueueFamilyProperties *queue_props = calloc(families, sizeof(*queue_props));
        vkGetPhysicalDeviceQueueFamilyProperties(devices[i], &families, queue_props);
        int graphics = -1, present = 0;
        for (uint32_t f = 0; f < families; f++) {
            VkBool32 supports = 0;
            vkGetPhysicalDeviceSurfaceSupportKHR(devices[i], f, vk.surface, &supports);
            if ((queue_props[f].queueFlags & VK_QUEUE_GRAPHICS_BIT) && supports) {
                graphics = (int)f;
                present = 1;
                break;
            }
        }
        free(queue_props);
        uint32_t ext_count = 0;
        vkEnumerateDeviceExtensionProperties(devices[i], NULL, &ext_count, NULL);
        VkExtensionProperties *exts = calloc(ext_count, sizeof(*exts));
        vkEnumerateDeviceExtensionProperties(devices[i], NULL, &ext_count, exts);
        int swapchain = has_extension(exts, ext_count, VK_KHR_SWAPCHAIN_EXTENSION_NAME);
        free(exts);
        int score = (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU ? 100 : 10) +
                    (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU ? 50 : 0);
        fprintf(stderr, "[vulkan] device %u: %s type=%d api=%u.%u.%u driver=%u graphics=%d present=%d swapchain=%d\n",
                i, props.deviceName, (int)props.deviceType,
                VK_VERSION_MAJOR(props.apiVersion), VK_VERSION_MINOR(props.apiVersion),
                VK_VERSION_PATCH(props.apiVersion), props.driverVersion, graphics, present, swapchain);
        if (graphics >= 0 && swapchain && score > best) {
            best = score;
            chosen = (int)i;
            vk.queue_family = (uint32_t)graphics;
        }
    }
    if (chosen < 0) {
        fprintf(stderr, "[vulkan] no graphics+present+swapchain device\n");
        free(devices);
        return -1;
    }
    vk.physical = devices[chosen];
    free(devices);
    vkGetPhysicalDeviceMemoryProperties(vk.physical, &vk.memory);

    float priority = 1.0f;
    VkDeviceQueueCreateInfo queue_info = {0};
    queue_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queue_info.queueFamilyIndex = vk.queue_family;
    queue_info.queueCount = 1;
    queue_info.pQueuePriorities = &priority;
    const char *device_extensions[] = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
    VkDeviceCreateInfo device_info = {0};
    device_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    device_info.queueCreateInfoCount = 1;
    device_info.pQueueCreateInfos = &queue_info;
    device_info.enabledExtensionCount = 1;
    device_info.ppEnabledExtensionNames = device_extensions;
    if (vk_ok(vkCreateDevice(vk.physical, &device_info, NULL, &vk.device), "vkCreateDevice"))
        return -1;
    vkGetDeviceQueue(vk.device, vk.queue_family, 0, &vk.queue);

    VkShaderModuleCreateInfo shader_info = {0};
    shader_info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    shader_info.codeSize = sizeof(pc2_present_vert_spv);
    shader_info.pCode = pc2_present_vert_spv;
    if (vk_ok(vkCreateShaderModule(vk.device, &shader_info, NULL, &vk.vertex_shader),
              "vkCreateShaderModule(vert)"))
        return -1;
    shader_info.codeSize = sizeof(pc2_present_frag_spv);
    shader_info.pCode = pc2_present_frag_spv;
    if (vk_ok(vkCreateShaderModule(vk.device, &shader_info, NULL, &vk.fragment_shader),
              "vkCreateShaderModule(frag)"))
        return -1;

    VkDescriptorSetLayoutBinding binding = {0};
    binding.binding = 0;
    binding.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    binding.descriptorCount = 1;
    binding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
    VkDescriptorSetLayoutCreateInfo layout_info = {0};
    layout_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    layout_info.bindingCount = 1;
    layout_info.pBindings = &binding;
    if (vk_ok(vkCreateDescriptorSetLayout(vk.device, &layout_info, NULL, &vk.descriptor_layout),
              "vkCreateDescriptorSetLayout"))
        return -1;
    VkPipelineLayoutCreateInfo pipeline_layout_info = {0};
    pipeline_layout_info.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipeline_layout_info.setLayoutCount = 1;
    pipeline_layout_info.pSetLayouts = &vk.descriptor_layout;
    if (vk_ok(vkCreatePipelineLayout(vk.device, &pipeline_layout_info, NULL, &vk.pipeline_layout),
              "vkCreatePipelineLayout"))
        return -1;

    VkDescriptorPoolSize pool_size = {0};
    pool_size.type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    pool_size.descriptorCount = 1;
    VkDescriptorPoolCreateInfo pool_info = {0};
    pool_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    pool_info.maxSets = 1;
    pool_info.poolSizeCount = 1;
    pool_info.pPoolSizes = &pool_size;
    if (vk_ok(vkCreateDescriptorPool(vk.device, &pool_info, NULL, &vk.descriptor_pool),
              "vkCreateDescriptorPool"))
        return -1;
    VkDescriptorSetAllocateInfo set_info = {0};
    set_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    set_info.descriptorPool = vk.descriptor_pool;
    set_info.descriptorSetCount = 1;
    set_info.pSetLayouts = &vk.descriptor_layout;
    if (vk_ok(vkAllocateDescriptorSets(vk.device, &set_info, &vk.descriptor_set),
              "vkAllocateDescriptorSets"))
        return -1;

    VkSamplerCreateInfo sampler_info = {0};
    sampler_info.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
    sampler_info.magFilter = VK_FILTER_NEAREST;
    sampler_info.minFilter = VK_FILTER_NEAREST;
    sampler_info.mipmapMode = VK_SAMPLER_MIPMAP_MODE_NEAREST;
    sampler_info.addressModeU = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
    sampler_info.addressModeV = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
    sampler_info.addressModeW = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
    sampler_info.maxLod = 0.0f;
    if (vk_ok(vkCreateSampler(vk.device, &sampler_info, NULL, &vk.sampler), "vkCreateSampler"))
        return -1;

    VkCommandPoolCreateInfo command_pool_info = {0};
    command_pool_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    command_pool_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    command_pool_info.queueFamilyIndex = vk.queue_family;
    if (vk_ok(vkCreateCommandPool(vk.device, &command_pool_info, NULL, &vk.command_pool),
              "vkCreateCommandPool"))
        return -1;
    VkCommandBufferAllocateInfo command_info = {0};
    command_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    command_info.commandPool = vk.command_pool;
    command_info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    command_info.commandBufferCount = MAX_FRAMES;
    if (vk_ok(vkAllocateCommandBuffers(vk.device, &command_info, vk.commands),
              "vkAllocateCommandBuffers"))
        return -1;
    for (int i = 0; i < MAX_FRAMES; i++) {
        VkSemaphoreCreateInfo semaphore_info = {0};
        semaphore_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
        if (vk_ok(vkCreateSemaphore(vk.device, &semaphore_info, NULL, &vk.image_available[i]),
                  "vkCreateSemaphore(image)"))
            return -1;
        VkFenceCreateInfo fence_info = {0};
        fence_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        fence_info.flags = VK_FENCE_CREATE_SIGNALED_BIT;
        if (vk_ok(vkCreateFence(vk.device, &fence_info, NULL, &vk.in_flight[i]),
                  "vkCreateFence"))
            return -1;
    }

    int dw = 0, dh = 0;
    SDL_Vulkan_GetDrawableSize(window, &dw, &dh);
    if (dw > 0 && dh > 0) {
        int result = create_swapchain(dw, dh);
        if (result < 0) {
            vk.active = 0;
            return -1;
        }
    }

    vk.initialized = 1;
    vk.active = 1;
    fprintf(stderr, "[vulkan] ready (native Vulkan presentation, nearest filtering, FIFO)\n");
    return 0;
}

int pc2_vulkan_present(const unsigned char *pixels, int w, int h, int pitch,
                       int bpp, int menu_ready)
{
    if (!vk.initialized || vk.failed) return 0;
    if (bpp != 16) {
        if (!vk.logged_bpp) {
            fprintf(stderr, "[vulkan] unsupported frame bpp=%d (presentation skipped)\n", bpp);
            vk.logged_bpp = 1;
        }
        return 0;
    }
    if (w <= 0 || h <= 0 || !pixels) return 0;
    vk.src_w = w;
    vk.src_h = h;

    int dw = 0, dh = 0;
    SDL_Vulkan_GetDrawableSize(vk.window, &dw, &dh);
    if (dw <= 0 || dh <= 0) return 0;   /* minimized: keep the swapchain, skip */
    if (!vk.swapchain || (uint32_t)dw != vk.extent.width || (uint32_t)dh != vk.extent.height) {
        int result = recreate_swapchain(dw, dh);
        if (result < 0) { vk.failed = 1; return -1; }
        if (result > 0) return 0;
    }
    return draw_frame(pixels, w, h, pitch, menu_ready);
}

void pc2_vulkan_viewport(int *x, int *y, int *w, int *h)
{
    if (x) *x = vk.viewport_x;
    if (y) *y = vk.viewport_y;
    if (w) *w = vk.viewport_w;
    if (h) *h = vk.viewport_h;
}

SDL_Window *pc2_vulkan_window(void)
{
    return vk.window;
}

/* SDL scancode -> Windows virtual-key code, as win32hle's old screen pump
 * translated it. Kept here because the window and its input now belong to
 * the native presenter. */
static int vk_of(SDL_Scancode s)
{
    if (s >= SDL_SCANCODE_A && s <= SDL_SCANCODE_Z) return 'A' + (s - SDL_SCANCODE_A);
    if (s >= SDL_SCANCODE_1 && s <= SDL_SCANCODE_9) return '1' + (s - SDL_SCANCODE_1);
    if (s >= SDL_SCANCODE_F1 && s <= SDL_SCANCODE_F12) return 0x70 + (s - SDL_SCANCODE_F1);
    if (s >= SDL_SCANCODE_KP_1 && s <= SDL_SCANCODE_KP_9) return 0x61 + (s - SDL_SCANCODE_KP_1);
    switch (s) {
    case SDL_SCANCODE_0: return '0';
    case SDL_SCANCODE_KP_0: return 0x60;
    case SDL_SCANCODE_RETURN: case SDL_SCANCODE_KP_ENTER: return 0x0D;
    case SDL_SCANCODE_ESCAPE: return 0x1B;
    case SDL_SCANCODE_BACKSPACE: return 0x08;
    case SDL_SCANCODE_TAB: return 0x09;
    case SDL_SCANCODE_SPACE: return 0x20;
    case SDL_SCANCODE_LSHIFT: case SDL_SCANCODE_RSHIFT: return 0x10;
    case SDL_SCANCODE_LCTRL: case SDL_SCANCODE_RCTRL: return 0x11;
    case SDL_SCANCODE_LALT: case SDL_SCANCODE_RALT: return 0x12;
    case SDL_SCANCODE_PAUSE: return 0x13;
    case SDL_SCANCODE_CAPSLOCK: return 0x14;
    case SDL_SCANCODE_PAGEUP: return 0x21;
    case SDL_SCANCODE_PAGEDOWN: return 0x22;
    case SDL_SCANCODE_END: return 0x23;
    case SDL_SCANCODE_HOME: return 0x24;
    case SDL_SCANCODE_LEFT: return 0x25;
    case SDL_SCANCODE_UP: return 0x26;
    case SDL_SCANCODE_RIGHT: return 0x27;
    case SDL_SCANCODE_DOWN: return 0x28;
    case SDL_SCANCODE_INSERT: return 0x2D;
    case SDL_SCANCODE_DELETE: return 0x2E;
    case SDL_SCANCODE_KP_MULTIPLY: return 0x6A;
    case SDL_SCANCODE_KP_PLUS: return 0x6B;
    case SDL_SCANCODE_KP_MINUS: return 0x6D;
    case SDL_SCANCODE_KP_PERIOD: return 0x6E;
    case SDL_SCANCODE_KP_DIVIDE: return 0x6F;
    case SDL_SCANCODE_SEMICOLON: return 0xBA;
    case SDL_SCANCODE_EQUALS: return 0xBB;
    case SDL_SCANCODE_COMMA: return 0xBC;
    case SDL_SCANCODE_MINUS: return 0xBD;
    case SDL_SCANCODE_PERIOD: return 0xBE;
    case SDL_SCANCODE_SLASH: return 0xBF;
    case SDL_SCANCODE_GRAVE: return 0xC0;
    case SDL_SCANCODE_LEFTBRACKET: return 0xDB;
    case SDL_SCANCODE_BACKSLASH: return 0xDC;
    case SDL_SCANCODE_RIGHTBRACKET: return 0xDD;
    case SDL_SCANCODE_APOSTROPHE: return 0xDE;
    default: return 0;
    }
}

/* the PC/AT set-1 scan code, which lParam carries */
static uint32_t scan_of(SDL_Scancode s)
{
    static const uint8_t t[SDL_NUM_SCANCODES] = {
        [SDL_SCANCODE_ESCAPE] = 0x01, [SDL_SCANCODE_1] = 2, [SDL_SCANCODE_2] = 3, [SDL_SCANCODE_3] = 4, [SDL_SCANCODE_4] = 5,
        [SDL_SCANCODE_5] = 6, [SDL_SCANCODE_6] = 7, [SDL_SCANCODE_7] = 8, [SDL_SCANCODE_8] = 9, [SDL_SCANCODE_9] = 10,
        [SDL_SCANCODE_0] = 11, [SDL_SCANCODE_MINUS] = 12, [SDL_SCANCODE_EQUALS] = 13, [SDL_SCANCODE_BACKSPACE] = 14,
        [SDL_SCANCODE_TAB] = 15, [SDL_SCANCODE_Q] = 16, [SDL_SCANCODE_W] = 17, [SDL_SCANCODE_E] = 18, [SDL_SCANCODE_R] = 19,
        [SDL_SCANCODE_T] = 20, [SDL_SCANCODE_Y] = 21, [SDL_SCANCODE_U] = 22, [SDL_SCANCODE_I] = 23, [SDL_SCANCODE_O] = 24,
        [SDL_SCANCODE_P] = 25, [SDL_SCANCODE_LEFTBRACKET] = 26, [SDL_SCANCODE_RIGHTBRACKET] = 27, [SDL_SCANCODE_RETURN] = 28,
        [SDL_SCANCODE_LCTRL] = 29, [SDL_SCANCODE_A] = 30, [SDL_SCANCODE_S] = 31, [SDL_SCANCODE_D] = 32, [SDL_SCANCODE_F] = 33,
        [SDL_SCANCODE_G] = 34, [SDL_SCANCODE_H] = 35, [SDL_SCANCODE_J] = 36, [SDL_SCANCODE_K] = 37, [SDL_SCANCODE_L] = 38,
        [SDL_SCANCODE_SEMICOLON] = 39, [SDL_SCANCODE_APOSTROPHE] = 40, [SDL_SCANCODE_GRAVE] = 41, [SDL_SCANCODE_LSHIFT] = 42,
        [SDL_SCANCODE_BACKSLASH] = 43, [SDL_SCANCODE_Z] = 44, [SDL_SCANCODE_X] = 45, [SDL_SCANCODE_C] = 46, [SDL_SCANCODE_V] = 47,
        [SDL_SCANCODE_B] = 48, [SDL_SCANCODE_N] = 49, [SDL_SCANCODE_M] = 50, [SDL_SCANCODE_COMMA] = 51, [SDL_SCANCODE_PERIOD] = 52,
        [SDL_SCANCODE_SLASH] = 53, [SDL_SCANCODE_RSHIFT] = 54, [SDL_SCANCODE_LALT] = 56, [SDL_SCANCODE_SPACE] = 57,
        [SDL_SCANCODE_CAPSLOCK] = 58, [SDL_SCANCODE_F1] = 59, [SDL_SCANCODE_F2] = 60, [SDL_SCANCODE_F3] = 61, [SDL_SCANCODE_F4] = 62,
        [SDL_SCANCODE_F5] = 63, [SDL_SCANCODE_F6] = 64, [SDL_SCANCODE_F7] = 65, [SDL_SCANCODE_F8] = 66, [SDL_SCANCODE_F9] = 67,
        [SDL_SCANCODE_F10] = 68, [SDL_SCANCODE_F11] = 87, [SDL_SCANCODE_F12] = 88, [SDL_SCANCODE_HOME] = 71, [SDL_SCANCODE_UP] = 72,
        [SDL_SCANCODE_PAGEUP] = 73, [SDL_SCANCODE_LEFT] = 75, [SDL_SCANCODE_RIGHT] = 77, [SDL_SCANCODE_END] = 79,
        [SDL_SCANCODE_DOWN] = 80, [SDL_SCANCODE_PAGEDOWN] = 81, [SDL_SCANCODE_INSERT] = 82, [SDL_SCANCODE_DELETE] = 83 };
    return (unsigned)s < SDL_NUM_SCANCODES ? t[s] : 0;
}

/* Window points -> game pixels through the current Vulkan viewport. */
static void guest_coords(int x, int y, int *gx, int *gy)
{
    int ww = 0, wh = 0, dw = 0, dh = 0;
    SDL_GetWindowSize(vk.window, &ww, &wh);
    SDL_Vulkan_GetDrawableSize(vk.window, &dw, &dh);
    if (ww <= 0 || wh <= 0 || dw <= 0 || dh <= 0) {
        *gx = x, *gy = y;
        return;
    }
    int px = x * dw / ww, py = y * dh / wh;
    int sw = vk.src_w > 0 ? vk.src_w : 800;
    int sh = vk.src_h > 0 ? vk.src_h : 600;
    if (vk.viewport_w <= 0 || vk.viewport_h <= 0) {
        *gx = px, *gy = py;
    } else {
        *gx = (px - vk.viewport_x) * sw / vk.viewport_w;
        *gy = (py - vk.viewport_y) * sh / vk.viewport_h;
    }
    if (*gx < 0) *gx = 0;
    if (*gy < 0) *gy = 0;
    if (*gx >= sw) *gx = sw - 1;
    if (*gy >= sh) *gy = sh - 1;
}

static void pc2_vulkan_warp(int x, int y)
{
    if (!vk.window || vk.viewport_w <= 0 || vk.viewport_h <= 0) return;
    int ww = 0, wh = 0, dw = 0, dh = 0;
    SDL_GetWindowSize(vk.window, &ww, &wh);
    SDL_Vulkan_GetDrawableSize(vk.window, &dw, &dh);
    if (ww <= 0 || wh <= 0 || dw <= 0 || dh <= 0) return;
    int sw = vk.src_w > 0 ? vk.src_w : 800;
    int sh = vk.src_h > 0 ? vk.src_h : 600;
    int px = vk.viewport_x + x * vk.viewport_w / sw;
    int py = vk.viewport_y + y * vk.viewport_h / sh;
    SDL_WarpMouseInWindow(vk.window, px * ww / dw, py * wh / dh);
}

static void pc2_vulkan_relative(int on)
{
    vk.want_relative = on != 0;
}

static void pc2_vulkan_update_relative(void)
{
    int focus = (SDL_GetWindowFlags(vk.window) & SDL_WINDOW_INPUT_FOCUS) != 0;
    int rel = vk.want_relative && focus;
    if (rel == vk.relative) return;
    SDL_SetRelativeMouseMode(rel ? SDL_TRUE : SDL_FALSE);
    vk.relative = rel;
    vk.rel_fx = vk.rel_fy = 0;
    fprintf(stderr, "[vulkan] mouse %s\n",
            rel ? "relative: the game has its movement" : "absolute");
}

static void pc2_vulkan_update_cursor(void)
{
    int show = hle_screen_cursor_hook ? hle_screen_cursor_hook() : 1;
    if (show == vk.cursor_shown) return;
    vk.cursor_shown = show;
    if (show) {
        SDL_SetCursor(SDL_GetDefaultCursor());
        SDL_ShowCursor(SDL_ENABLE);
    } else {
        SDL_ShowCursor(SDL_DISABLE);
    }
    fprintf(stderr, "[vulkan] cursor: %s\n", show ? "the system arrow" : "drawn by the game");
}

void pc2_vulkan_pump(void)
{
    if (!vk.initialized) return;
    pc2_vulkan_update_cursor();
    pc2_vulkan_update_relative();

    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_QUIT: {
            uint32_t h = hle_first_hwnd();
            if (h) hle_post_message(h, 0x0010 /* WM_CLOSE */, 0, 0);
            else hle_exit(0);
            break;
        }
        case SDL_KEYDOWN: case SDL_KEYUP: {
            SDL_Scancode sc = e.key.keysym.scancode;
            if ((sc == SDL_SCANCODE_RETURN && (e.key.keysym.mod & KMOD_ALT)) ||
                sc == SDL_SCANCODE_F11) {
                if (e.type == SDL_KEYDOWN) {
                    vk.fullscreen = !vk.fullscreen;
                    SDL_SetWindowFullscreen(vk.window,
                        vk.fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
                }
                break;
            }
            int vkcode = vk_of(sc);
            if (vkcode) hle_input_key(e.type == SDL_KEYDOWN, (uint32_t)vkcode, scan_of(sc));
            break;
        }
        case SDL_MOUSEMOTION: {
            if (vk.relative) {
                int ww = 0, wh = 0, dw = 0, dh = 0;
                SDL_GetWindowSize(vk.window, &ww, &wh);
                SDL_Vulkan_GetDrawableSize(vk.window, &dw, &dh);
                double pd_w = (ww > 0 && dw > 0) ? (double)vk.viewport_w * ww / dw : 0.0;
                double pd_h = (wh > 0 && dh > 0) ? (double)vk.viewport_h * wh / dh : 0.0;
                int sw = vk.src_w > 0 ? vk.src_w : 800;
                int sh = vk.src_h > 0 ? vk.src_h : 600;
                if (pd_w > 0.0 && pd_h > 0.0) {
                    vk.rel_fx += (double)e.motion.xrel * sw / pd_w;
                    vk.rel_fy += (double)e.motion.yrel * sh / pd_h;
                    int dx = (int)vk.rel_fx, dy = (int)vk.rel_fy;
                    vk.rel_fx -= dx, vk.rel_fy -= dy;
                    if (dx || dy) hle_input_motion(dx, dy);
                }
                break;
            }
            int gx, gy;
            guest_coords(e.motion.x, e.motion.y, &gx, &gy);
            hle_input_mouse(0x0200 /* WM_MOUSEMOVE */, gx, gy);
            break;
        }
        case SDL_MOUSEBUTTONDOWN: case SDL_MOUSEBUTTONUP: {
            int gx, gy, down = e.type == SDL_MOUSEBUTTONDOWN;
            if (vk.relative) hle_input_position(&gx, &gy);
            else guest_coords(e.button.x, e.button.y, &gx, &gy);
            uint32_t m = e.button.button == SDL_BUTTON_RIGHT
                       ? (down ? 0x0204 : 0x0205)   /* WM_RBUTTONDOWN/UP */
                       : e.button.button == SDL_BUTTON_MIDDLE
                       ? (down ? 0x0207 : 0x0208)   /* WM_MBUTTONDOWN/UP */
                       : (down ? 0x0201 : 0x0202);  /* WM_LBUTTONDOWN/UP */
            hle_input_mouse(m, gx, gy);
            break;
        }
        case SDL_MOUSEWHEEL: {
            int y = e.wheel.direction == SDL_MOUSEWHEEL_FLIPPED ? e.wheel.y : -e.wheel.y;
            if (y) hle_input_wheel(y * 120);
            break;
        }
        default: break;
        }
    }
    if (vk.poll) vk.poll();
    if (vk.present) vk.present();
}

void pc2_vulkan_shutdown(void)
{
    if (!vk.initialized) {
        if (vk.window) SDL_DestroyWindow(vk.window);
        vk.window = NULL;
        return;
    }
    vkDeviceWaitIdle(vk.device);
    destroy_swapchain();
    destroy_image(&vk.texture, &vk.texture_memory, &vk.texture_view);
    destroy_buffer(&vk.staging, &vk.staging_memory, &vk.staging_map);
    if (vk.sampler) vkDestroySampler(vk.device, vk.sampler, NULL);
    if (vk.descriptor_pool) vkDestroyDescriptorPool(vk.device, vk.descriptor_pool, NULL);
    if (vk.pipeline_layout) vkDestroyPipelineLayout(vk.device, vk.pipeline_layout, NULL);
    if (vk.descriptor_layout) vkDestroyDescriptorSetLayout(vk.device, vk.descriptor_layout, NULL);
    if (vk.fragment_shader) vkDestroyShaderModule(vk.device, vk.fragment_shader, NULL);
    if (vk.vertex_shader) vkDestroyShaderModule(vk.device, vk.vertex_shader, NULL);
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (vk.image_available[i]) vkDestroySemaphore(vk.device, vk.image_available[i], NULL);
        if (vk.in_flight[i]) vkDestroyFence(vk.device, vk.in_flight[i], NULL);
    }
    if (vk.command_pool) vkDestroyCommandPool(vk.device, vk.command_pool, NULL);
    if (vk.device) vkDestroyDevice(vk.device, NULL);
    if (vk.surface) vkDestroySurfaceKHR(vk.instance, vk.surface, NULL);
    if (vk.instance) vkDestroyInstance(vk.instance, NULL);
    SDL_SetRelativeMouseMode(SDL_FALSE);
    if (vk.window) SDL_DestroyWindow(vk.window);
    vk.window = NULL;
    SDL_Vulkan_UnloadLibrary();
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    memset(&vk, 0, sizeof(vk));
}

int pc2_vulkan_active(void)
{
    return vk.active;
}
