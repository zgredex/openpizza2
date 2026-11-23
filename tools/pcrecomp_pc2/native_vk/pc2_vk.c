/* OpenPizza2 native Vulkan 2D backend.
 * Compiles as C11. Implements actual GPU texture sampling/blending, not a
 * DirectDraw compatibility layer or upload of the completed CPU framebuffer.
 * Conservative queue-idle synchronization is used for correctness first.
 */
#include "pc2_vk.h"
#include <SDL2/SDL_vulkan.h>
#include <vulkan/vulkan.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

#define CANVAS_W 800.0f
#define CANVAS_H 600.0f
#define TEXTURE_FORMAT VK_FORMAT_R8G8B8A8_UNORM
typedef struct {
    VkRenderPass pass;
    VkPipeline rgba;
    VkPipeline premultiplied;
} quad_pass;

struct pc2_vk_texture {
    pc2_vk *owner;
    VkImage image;
    VkDeviceMemory memory;
    VkImageView view;
    VkDescriptorSet set;
    VkFramebuffer framebuffer;
    uint32_t width, height;
    int layout_initialized;
    int retired;
    pc2_vk_texture *retired_next;
};
struct pc2_vk {
    SDL_Window *window;
    VkInstance instance;
    VkSurfaceKHR surface;
    VkPhysicalDevice physical;
    VkDevice device;
    VkQueue queue;
    uint32_t family;
    uint32_t max_image_size;
    uint32_t max_target_width, max_target_height;
    VkCommandPool pool;
    VkCommandBuffer command;
    VkSwapchainKHR swapchain;
    VkFormat swap_format;
    VkExtent2D extent;
    VkImage *images;
    VkImageView *views;
    VkFramebuffer *framebuffers;
    VkSemaphore *render_done; /* indexed by acquired image */
    uint32_t image_count;
    uint32_t current_image;
    VkSemaphore acquired;
    VkPipelineLayout layout;
    quad_pass swap_pass;
    quad_pass target_pass;
    VkRenderPass target_load_pass;
    VkDescriptorSetLayout descriptor_layout;
    VkDescriptorPool descriptor_pool;
    VkSampler sampler;
    VkViewport viewport;
    VkPipeline bound_pipeline;
    pc2_vk_texture *active_target;
    pc2_vk_texture *retired_textures;
    int active;
    char error[256];
    char shader_dir[512];
};
static int fail(pc2_vk *r, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(r->error, sizeof r->error, fmt, ap);
    va_end(ap);
    fprintf(stderr, "[pc2-vulkan] %s\n", r->error);
    return 0;
}
const char *pc2_vk_error(const pc2_vk *r) { return r ? r->error : "null renderer"; }
static int gpu_ok(pc2_vk *r, VkResult v, const char *what) {
    return v == VK_SUCCESS || fail(r, "%s: VkResult=%d", what, (int)v);
}
static uint32_t find_memory(pc2_vk *r, uint32_t allowed, VkMemoryPropertyFlags flags) {
    VkPhysicalDeviceMemoryProperties p;
    vkGetPhysicalDeviceMemoryProperties(r->physical, &p);
    for (uint32_t i = 0; i < p.memoryTypeCount; ++i)
        if ((allowed & (1u << i)) && (p.memoryTypes[i].propertyFlags & flags) == flags)
            return i;
    return UINT32_MAX;
}
static int alloc_memory(pc2_vk *r, VkMemoryRequirements req, VkMemoryPropertyFlags props,
                        VkDeviceMemory *out) {
    uint32_t type = find_memory(r, req.memoryTypeBits, props);
    if (type == UINT32_MAX) return fail(r, "memory type unavailable");
    VkMemoryAllocateInfo ai = { .sType=VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
                                .allocationSize=req.size, .memoryTypeIndex=type };
    return gpu_ok(r, vkAllocateMemory(r->device, &ai, NULL, out), "vkAllocateMemory");
}
static int buffer_create(pc2_vk *r, VkDeviceSize size, VkBufferUsageFlags usage,
                         VkBuffer *buf, VkDeviceMemory *mem) {
    VkBufferCreateInfo bi = {.sType=VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
                             .size=size, .usage=usage, .sharingMode=VK_SHARING_MODE_EXCLUSIVE};
    if (!gpu_ok(r, vkCreateBuffer(r->device, &bi, NULL, buf), "create staging buffer")) return 0;
    VkMemoryRequirements req;
    vkGetBufferMemoryRequirements(r->device, *buf, &req);
    if (!alloc_memory(r, req, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT|
                            VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, mem)) {
        vkDestroyBuffer(r->device, *buf, NULL); *buf = VK_NULL_HANDLE; return 0;
    }
    if (gpu_ok(r, vkBindBufferMemory(r->device, *buf, *mem, 0), "bind staging buffer"))
        return 1;
    vkDestroyBuffer(r->device, *buf, NULL);
    vkFreeMemory(r->device, *mem, NULL);
    *buf = VK_NULL_HANDLE;
    *mem = VK_NULL_HANDLE;
    return 0;
}
static int one_time_begin(pc2_vk *r, VkCommandBuffer *cmd) {
    VkCommandBufferAllocateInfo ai = { .sType=VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
        .commandPool=r->pool, .level=VK_COMMAND_BUFFER_LEVEL_PRIMARY, .commandBufferCount=1 };
    if (!gpu_ok(r, vkAllocateCommandBuffers(r->device, &ai, cmd), "upload cmd allocate")) return 0;
    VkCommandBufferBeginInfo bi={.sType=VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
                                 .flags=VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT};
    if (!gpu_ok(r, vkBeginCommandBuffer(*cmd, &bi), "upload cmd begin")) {
        vkFreeCommandBuffers(r->device, r->pool, 1, cmd); return 0;
    }
    return 1;
}
static int one_time_end(pc2_vk *r, VkCommandBuffer cmd) {
    if (!gpu_ok(r, vkEndCommandBuffer(cmd), "upload cmd end")) {
        vkFreeCommandBuffers(r->device, r->pool, 1, &cmd); return 0;
    }
    VkSubmitInfo si={.sType=VK_STRUCTURE_TYPE_SUBMIT_INFO,
                     .commandBufferCount=1, .pCommandBuffers=&cmd};
    int ok = gpu_ok(r, vkQueueSubmit(r->queue, 1, &si, VK_NULL_HANDLE), "upload submit");
    if (ok) ok = gpu_ok(r, vkQueueWaitIdle(r->queue), "upload wait");
    vkFreeCommandBuffers(r->device, r->pool, 1, &cmd);
    return ok;
}
static void transition(VkCommandBuffer cmd, VkImage image, VkImageLayout old,
                       VkImageLayout next, VkAccessFlags src, VkAccessFlags dst,
                       VkPipelineStageFlags src_stage, VkPipelineStageFlags dst_stage) {
    VkImageMemoryBarrier b={.sType=VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
        .srcAccessMask=src, .dstAccessMask=dst,
        .oldLayout=old, .newLayout=next,
        .srcQueueFamilyIndex=VK_QUEUE_FAMILY_IGNORED,
        .dstQueueFamilyIndex=VK_QUEUE_FAMILY_IGNORED,
        .image=image,
        .subresourceRange={VK_IMAGE_ASPECT_COLOR_BIT,0,1,0,1}};
    vkCmdPipelineBarrier(cmd,src_stage,dst_stage,0,0,NULL,0,NULL,1,&b);
}

static void quad_pass_destroy(pc2_vk *r, quad_pass *quad) {
    if (quad->rgba) vkDestroyPipeline(r->device, quad->rgba, NULL);
    if (quad->premultiplied) vkDestroyPipeline(r->device, quad->premultiplied, NULL);
    if (quad->pass) vkDestroyRenderPass(r->device, quad->pass, NULL);
    *quad = (quad_pass){0};
}

static void swap_destroy(pc2_vk *r) {
    if (!r->device) return;
    vkDeviceWaitIdle(r->device);
    if (r->framebuffers) for (uint32_t i=0; i<r->image_count; ++i)
        if (r->framebuffers[i]) vkDestroyFramebuffer(r->device,r->framebuffers[i],NULL);
    if (r->views) for (uint32_t i=0; i<r->image_count; ++i)
        if (r->views[i]) vkDestroyImageView(r->device,r->views[i],NULL);
    if (r->render_done) for (uint32_t i=0; i<r->image_count; ++i)
        if (r->render_done[i]) vkDestroySemaphore(r->device,r->render_done[i],NULL);
    free(r->framebuffers); free(r->views); free(r->render_done); free(r->images);
    r->framebuffers=NULL; r->views=NULL; r->render_done=NULL; r->images=NULL;
    r->image_count=0;
    quad_pass_destroy(r, &r->swap_pass);
    if (r->swapchain) vkDestroySwapchainKHR(r->device,r->swapchain,NULL);
    r->swapchain=VK_NULL_HANDLE;
}
static VkShaderModule shader_load(pc2_vk *r, const char *file) {
    char path[1024]; snprintf(path,sizeof path,"%s/%s",r->shader_dir,file);
    FILE *f=fopen(path,"rb");
    if (!f) { fail(r,"missing SPIR-V shader: %s",path); return VK_NULL_HANDLE; }
    if (fseek(f,0,SEEK_END)!=0) {fclose(f);return VK_NULL_HANDLE;}
    long len=ftell(f); rewind(f);
    if (len<=0 || (len%4)!=0 || len>8*1024*1024) {fclose(f);fail(r,"invalid shader %s",path);return VK_NULL_HANDLE;}
    void *data=malloc((size_t)len);
    if (!data) {fclose(f);return VK_NULL_HANDLE;}
    int read_ok=fread(data,1,(size_t)len,f)==(size_t)len;
    fclose(f);
    VkShaderModule mod=VK_NULL_HANDLE;
    if (read_ok) {
        VkShaderModuleCreateInfo ci={.sType=VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
            .codeSize=(size_t)len,.pCode=(const uint32_t*)data};
        gpu_ok(r,vkCreateShaderModule(r->device,&ci,NULL,&mod),"shader module");
    }
    free(data);return mod;
}
static int render_pass_create(pc2_vk *r, VkFormat format, int offscreen, int load,
                              VkRenderPass *pass) {
    VkAttachmentDescription att={.format=format,.samples=VK_SAMPLE_COUNT_1_BIT,
        .loadOp=load ? VK_ATTACHMENT_LOAD_OP_LOAD : VK_ATTACHMENT_LOAD_OP_CLEAR,
        .storeOp=VK_ATTACHMENT_STORE_OP_STORE,
        .initialLayout=load ? VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL : VK_IMAGE_LAYOUT_UNDEFINED,
        .finalLayout=offscreen ? VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL
                               : VK_IMAGE_LAYOUT_PRESENT_SRC_KHR};
    VkAttachmentReference ref={0,VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL};
    VkSubpassDescription sub={.pipelineBindPoint=VK_PIPELINE_BIND_POINT_GRAPHICS,
        .colorAttachmentCount=1,.pColorAttachments=&ref};
    VkSubpassDependency deps[2]={{.srcSubpass=VK_SUBPASS_EXTERNAL,.dstSubpass=0,
        .srcStageMask=VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
        .srcAccessMask=offscreen ? VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT : 0,
        .dstStageMask=VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
        .dstAccessMask=VK_ACCESS_COLOR_ATTACHMENT_READ_BIT|VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT},
        {.srcSubpass=0,.dstSubpass=VK_SUBPASS_EXTERNAL,
         .srcStageMask=VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
         .dstStageMask=VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT|VK_PIPELINE_STAGE_TRANSFER_BIT,
         .srcAccessMask=VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
         .dstAccessMask=VK_ACCESS_SHADER_READ_BIT|VK_ACCESS_TRANSFER_READ_BIT}};
    VkRenderPassCreateInfo rp={.sType=VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO,
        .attachmentCount=1,.pAttachments=&att,.subpassCount=1,.pSubpasses=&sub,
        .dependencyCount=offscreen ? 2u : 1u,.pDependencies=deps};
    return gpu_ok(r,vkCreateRenderPass(r->device,&rp,NULL,pass),"render pass");
}

static int quad_pass_create(pc2_vk *r, quad_pass *quad, VkFormat format, int offscreen) {
    if (!render_pass_create(r,format,offscreen,0,&quad->pass)) return 0;
    VkShaderModule vert=shader_load(r,"quad.vert.spv");
    VkShaderModule frag=shader_load(r,"quad.frag.spv");
    if (!vert || !frag) {
        if (vert) vkDestroyShaderModule(r->device,vert,NULL);
        if (frag) vkDestroyShaderModule(r->device,frag,NULL);
        quad_pass_destroy(r, quad);
        return 0;
    }
    VkPipelineShaderStageCreateInfo stages[2]={
        {.sType=VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
         .stage=VK_SHADER_STAGE_VERTEX_BIT,.module=vert,.pName="main"},
        {.sType=VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
         .stage=VK_SHADER_STAGE_FRAGMENT_BIT,.module=frag,.pName="main"}};
    VkPipelineVertexInputStateCreateInfo vi={.sType=VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO};
    VkPipelineInputAssemblyStateCreateInfo ia={.sType=VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO,
        .topology=VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST};
    VkPipelineViewportStateCreateInfo vp={.sType=VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO,
        .viewportCount=1,.scissorCount=1};
    VkPipelineRasterizationStateCreateInfo rs={.sType=VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO,
        .polygonMode=VK_POLYGON_MODE_FILL,.cullMode=VK_CULL_MODE_NONE,
        .frontFace=VK_FRONT_FACE_COUNTER_CLOCKWISE,.lineWidth=1};
    VkPipelineMultisampleStateCreateInfo ms={.sType=VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO,
        .rasterizationSamples=VK_SAMPLE_COUNT_1_BIT};
    VkPipelineColorBlendAttachmentState ba={.blendEnable=VK_TRUE,
        .srcColorBlendFactor=VK_BLEND_FACTOR_SRC_ALPHA,
        .dstColorBlendFactor=VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
        .colorBlendOp=VK_BLEND_OP_ADD,
        .srcAlphaBlendFactor=VK_BLEND_FACTOR_ONE,
        .dstAlphaBlendFactor=VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
        .alphaBlendOp=VK_BLEND_OP_ADD,.colorWriteMask=0xf};
    VkPipelineColorBlendStateCreateInfo blend={.sType=VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
        .attachmentCount=1,.pAttachments=&ba};
    VkDynamicState dyns[2]={VK_DYNAMIC_STATE_VIEWPORT,VK_DYNAMIC_STATE_SCISSOR};
    VkPipelineDynamicStateCreateInfo dyn={.sType=VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO,
        .dynamicStateCount=2,.pDynamicStates=dyns};
    VkGraphicsPipelineCreateInfo ci={.sType=VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO,
        .stageCount=2,.pStages=stages,.pVertexInputState=&vi,.pInputAssemblyState=&ia,
        .pViewportState=&vp,.pRasterizationState=&rs,.pMultisampleState=&ms,
        .pColorBlendState=&blend,.pDynamicState=&dyn,.layout=r->layout,
        .renderPass=quad->pass,.subpass=0};
    int ok=gpu_ok(r,vkCreateGraphicsPipelines(r->device,VK_NULL_HANDLE,1,&ci,NULL,&quad->rgba),
                  "sprite pipeline");
    if (ok) {
        ba.srcColorBlendFactor=VK_BLEND_FACTOR_ONE;
        ok=gpu_ok(r,vkCreateGraphicsPipelines(r->device,VK_NULL_HANDLE,1,&ci,NULL,&quad->premultiplied),
                  "premultiplied sprite pipeline");
    }
    vkDestroyShaderModule(r->device,vert,NULL);
    vkDestroyShaderModule(r->device,frag,NULL);
    if (!ok) quad_pass_destroy(r, quad);
    return ok;
}
static int swap_create(pc2_vk *r) {
    int w=0,h=0;
    SDL_Vulkan_GetDrawableSize(r->window,&w,&h);
    if (w<=0 || h<=0) return fail(r,"window drawable size is zero");
    VkSurfaceCapabilitiesKHR caps;
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(r->physical,r->surface,&caps);
    uint32_t nf=0;
    vkGetPhysicalDeviceSurfaceFormatsKHR(r->physical,r->surface,&nf,NULL);
    if (!nf) return fail(r,"surface has no supported formats");
    VkSurfaceFormatKHR *formats=calloc(nf,sizeof *formats);
    vkGetPhysicalDeviceSurfaceFormatsKHR(r->physical,r->surface,&nf,formats);
    VkSurfaceFormatKHR fmt=formats[0];
    for (uint32_t i=0;i<nf;++i) if (formats[i].format==VK_FORMAT_B8G8R8A8_UNORM) {fmt=formats[i];break;}
    free(formats);
    r->swap_format=fmt.format;
    r->extent=caps.currentExtent;
    if (r->extent.width==UINT32_MAX) {
        r->extent.width=(uint32_t)w; r->extent.height=(uint32_t)h;
        if (r->extent.width<caps.minImageExtent.width) r->extent.width=caps.minImageExtent.width;
        if (r->extent.height<caps.minImageExtent.height) r->extent.height=caps.minImageExtent.height;
        if (r->extent.width>caps.maxImageExtent.width) r->extent.width=caps.maxImageExtent.width;
        if (r->extent.height>caps.maxImageExtent.height) r->extent.height=caps.maxImageExtent.height;
    }
    uint32_t count=caps.minImageCount+1;
    if (caps.maxImageCount && count>caps.maxImageCount) count=caps.maxImageCount;
    VkSwapchainCreateInfoKHR sci={.sType=VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,
        .surface=r->surface,.minImageCount=count,.imageFormat=fmt.format,
        .imageColorSpace=fmt.colorSpace,.imageExtent=r->extent,.imageArrayLayers=1,
        .imageUsage=VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,.imageSharingMode=VK_SHARING_MODE_EXCLUSIVE,
        .preTransform=caps.currentTransform,.compositeAlpha=VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,
        .presentMode=VK_PRESENT_MODE_FIFO_KHR,.clipped=VK_TRUE};
    if (!(caps.supportedCompositeAlpha & VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR)) {
        VkCompositeAlphaFlagBitsKHR choices[]={VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR,
            VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR,VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR};
        for (int i=0;i<3;i++) if (caps.supportedCompositeAlpha&choices[i]) {sci.compositeAlpha=choices[i];break;}
    }
    if (!gpu_ok(r,vkCreateSwapchainKHR(r->device,&sci,NULL,&r->swapchain),"create swapchain")) return 0;
    vkGetSwapchainImagesKHR(r->device,r->swapchain,&r->image_count,NULL);
    r->images=calloc(r->image_count,sizeof *r->images);
    r->views=calloc(r->image_count,sizeof *r->views);
    r->framebuffers=calloc(r->image_count,sizeof *r->framebuffers);
    r->render_done=calloc(r->image_count,sizeof *r->render_done);
    if (!r->images||!r->views||!r->framebuffers||!r->render_done)
        return fail(r,"swapchain array allocation failed");
    vkGetSwapchainImagesKHR(r->device,r->swapchain,&r->image_count,r->images);
    if (!quad_pass_create(r,&r->swap_pass,r->swap_format,0)) return 0;
    VkSemaphoreCreateInfo semi={.sType=VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO};
    for (uint32_t i=0;i<r->image_count;++i) {
        VkImageViewCreateInfo vi={.sType=VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            .image=r->images[i],.viewType=VK_IMAGE_VIEW_TYPE_2D,.format=r->swap_format,
            .subresourceRange={VK_IMAGE_ASPECT_COLOR_BIT,0,1,0,1}};
        if (!gpu_ok(r,vkCreateImageView(r->device,&vi,NULL,&r->views[i]),"swap image view")) return 0;
        VkFramebufferCreateInfo fi={.sType=VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO,
            .renderPass=r->swap_pass.pass,.attachmentCount=1,.pAttachments=&r->views[i],
            .width=r->extent.width,.height=r->extent.height,.layers=1};
        if (!gpu_ok(r,vkCreateFramebuffer(r->device,&fi,NULL,&r->framebuffers[i]),"swap framebuffer")) return 0;
        if (!gpu_ok(r,vkCreateSemaphore(r->device,&semi,NULL,&r->render_done[i]),"present semaphore")) return 0;
    }
    float scale=fminf((float)r->extent.width/CANVAS_W,(float)r->extent.height/CANVAS_H);
    r->viewport=(VkViewport){.x=((float)r->extent.width-CANVAS_W*scale)*0.5f,
        .y=((float)r->extent.height-CANVAS_H*scale)*0.5f,
        .width=CANVAS_W*scale,.height=CANVAS_H*scale,.minDepth=0,.maxDepth=1};
    return 1;
}
int pc2_vk_resize(pc2_vk *r) {
    if (!r || !r->window || r->active) return 0;
    swap_destroy(r);
    return swap_create(r);
}
static pc2_vk *renderer_create(SDL_Window *window, const char *shader_dir) {
    pc2_vk *r=calloc(1,sizeof *r);
    if (!r) return NULL;
    r->window=window;
    snprintf(r->shader_dir,sizeof r->shader_dir,"%s",shader_dir?shader_dir:"native_vk/shaders");
    unsigned int ne=0;
    const char **extensions=NULL;
    if (window) {
        if (!SDL_Vulkan_GetInstanceExtensions(window,&ne,NULL)) {
            fail(r,"SDL Vulkan instance extensions: %s",SDL_GetError());goto bad;
        }
        extensions=calloc(ne,sizeof *extensions);
        if (!extensions) goto bad;
        if (!SDL_Vulkan_GetInstanceExtensions(window,&ne,extensions)) {free(extensions);goto bad;}
    }
    VkApplicationInfo app={.sType=VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pApplicationName="OpenPizza2",.apiVersion=VK_API_VERSION_1_0};
    VkInstanceCreateInfo ii={.sType=VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pApplicationInfo=&app,.enabledExtensionCount=ne,.ppEnabledExtensionNames=extensions};
    VkResult result=vkCreateInstance(&ii,NULL,&r->instance);
    free(extensions);
    if (!gpu_ok(r,result,"vkCreateInstance")) goto bad;
    if (window && !SDL_Vulkan_CreateSurface(window,r->instance,&r->surface)) {
        fail(r,"SDL Vulkan surface: %s",SDL_GetError());goto bad;
    }
    uint32_t count=0;
    vkEnumeratePhysicalDevices(r->instance,&count,NULL);
    if (!count) {fail(r,"no Vulkan physical devices");goto bad;}
    VkPhysicalDevice *devices=calloc(count,sizeof *devices);
    if (!devices) goto bad;
    vkEnumeratePhysicalDevices(r->instance,&count,devices);
    for (uint32_t i=0;i<count&&!r->physical;++i) {
        uint32_t nf=0;
        vkGetPhysicalDeviceQueueFamilyProperties(devices[i],&nf,NULL);
        VkQueueFamilyProperties *families=calloc(nf,sizeof *families);
        if (!families) continue;
        vkGetPhysicalDeviceQueueFamilyProperties(devices[i],&nf,families);
        for (uint32_t j=0;j<nf;++j) {
            if (!(families[j].queueFlags&VK_QUEUE_GRAPHICS_BIT)) continue;
            if (!window) {r->physical=devices[i];r->family=j;break;}
            VkBool32 present=VK_FALSE;
            vkGetPhysicalDeviceSurfaceSupportKHR(devices[i],j,r->surface,&present);
            if (present) {
                uint32_t ext_count=0;
                vkEnumerateDeviceExtensionProperties(devices[i],NULL,&ext_count,NULL);
                VkExtensionProperties *exts=calloc(ext_count,sizeof *exts);
                int has_swapchain=0;
                if (exts) {
                    vkEnumerateDeviceExtensionProperties(devices[i],NULL,&ext_count,exts);
                    for (uint32_t k=0;k<ext_count;++k)
                        if (!strcmp(exts[k].extensionName,VK_KHR_SWAPCHAIN_EXTENSION_NAME)) has_swapchain=1;
                    free(exts);
                }
                if (has_swapchain) {r->physical=devices[i];r->family=j;break;}
            }
        }
        free(families);
    }
    free(devices);
    if (!r->physical) {fail(r,"no suitable Vulkan graphics queue");goto bad;}
    VkPhysicalDeviceProperties properties;
    vkGetPhysicalDeviceProperties(r->physical,&properties);
    r->max_image_size=properties.limits.maxImageDimension2D;
    r->max_target_width=properties.limits.maxFramebufferWidth;
    r->max_target_height=properties.limits.maxFramebufferHeight;
    fprintf(stderr,"[pc2-vulkan] GPU: %s\n",properties.deviceName);
    float priority=1.0f;
    VkDeviceQueueCreateInfo qi={.sType=VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
        .queueFamilyIndex=r->family,.queueCount=1,.pQueuePriorities=&priority};
    const char *ext=VK_KHR_SWAPCHAIN_EXTENSION_NAME;
    VkDeviceCreateInfo di={.sType=VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
        .queueCreateInfoCount=1,.pQueueCreateInfos=&qi,
        .enabledExtensionCount=window ? 1u : 0u,.ppEnabledExtensionNames=window ? &ext : NULL};
    if (!gpu_ok(r,vkCreateDevice(r->physical,&di,NULL,&r->device),"vkCreateDevice")) goto bad;
    vkGetDeviceQueue(r->device,r->family,0,&r->queue);
    VkCommandPoolCreateInfo pi={.sType=VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
        .flags=VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,.queueFamilyIndex=r->family};
    if (!gpu_ok(r,vkCreateCommandPool(r->device,&pi,NULL,&r->pool),"command pool")) goto bad;
    VkCommandBufferAllocateInfo ci={.sType=VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
        .commandPool=r->pool,.level=VK_COMMAND_BUFFER_LEVEL_PRIMARY,.commandBufferCount=1};
    if (!gpu_ok(r,vkAllocateCommandBuffers(r->device,&ci,&r->command),"command buffer")) goto bad;
    VkDescriptorSetLayoutBinding binding={.binding=0,.descriptorCount=1,
        .descriptorType=VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,.stageFlags=VK_SHADER_STAGE_FRAGMENT_BIT};
    VkDescriptorSetLayoutCreateInfo dli={.sType=VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
        .bindingCount=1,.pBindings=&binding};
    if (!gpu_ok(r,vkCreateDescriptorSetLayout(r->device,&dli,NULL,&r->descriptor_layout),"descriptor layout")) goto bad;
    VkPushConstantRange range={.stageFlags=VK_SHADER_STAGE_VERTEX_BIT,.offset=0,.size=48};
    VkPipelineLayoutCreateInfo pli={.sType=VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
        .setLayoutCount=1,.pSetLayouts=&r->descriptor_layout,.pushConstantRangeCount=1,.pPushConstantRanges=&range};
    if (!gpu_ok(r,vkCreatePipelineLayout(r->device,&pli,NULL,&r->layout),"pipeline layout")) goto bad;
    VkDescriptorPoolSize dps={VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,16384};
    VkDescriptorPoolCreateInfo dpi={.sType=VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO,
        .flags=VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT,.maxSets=16384,.poolSizeCount=1,.pPoolSizes=&dps};
    if (!gpu_ok(r,vkCreateDescriptorPool(r->device,&dpi,NULL,&r->descriptor_pool),"texture descriptor pool")) goto bad;
    VkSamplerCreateInfo si={.sType=VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,
        .magFilter=VK_FILTER_NEAREST,.minFilter=VK_FILTER_NEAREST,
        .mipmapMode=VK_SAMPLER_MIPMAP_MODE_NEAREST,
        .addressModeU=VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
        .addressModeV=VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
        .addressModeW=VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,.maxLod=0};
    if (!gpu_ok(r,vkCreateSampler(r->device,&si,NULL,&r->sampler),"sprite sampler")) goto bad;
    VkSemaphoreCreateInfo smi={.sType=VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO};
    if (window) {
        if (!gpu_ok(r,vkCreateSemaphore(r->device,&smi,NULL,&r->acquired),"acquire semaphore")) goto bad;
        if (!swap_create(r)) goto bad;
    }
    return r;
bad:
    pc2_vk_destroy(r);
    return NULL;
}

pc2_vk *pc2_vk_create(SDL_Window *window, const char *shader_dir) {
    if (!window || !(SDL_GetWindowFlags(window)&SDL_WINDOW_VULKAN)) {
        fprintf(stderr,"[pc2-vulkan] SDL window must be created with SDL_WINDOW_VULKAN\n");return NULL;
    }
    return renderer_create(window, shader_dir);
}

pc2_vk *pc2_vk_create_offscreen(const char *shader_dir) {
    return renderer_create(NULL, shader_dir);
}
enum { PIXELS_RGBA8, PIXELS_RGB565 };

static int source_pitch(uint32_t w, uint32_t h, uint32_t *pitch, int format) {
    if (!w || !h || w > 16384 || h > 16384) return 0;
    uint32_t row = w * (format == PIXELS_RGB565 ? 2u : 4u);
    if (!*pitch) *pitch = row;
    return *pitch >= row && (h - 1u) <= (SIZE_MAX - row) / *pitch;
}

static int upload_texture(pc2_vk *r, pc2_vk_texture *t, const uint8_t *pixels,
                          uint32_t pitch, int format, int key);

static pc2_vk_texture *texture_alloc(pc2_vk *r, uint32_t w, uint32_t h, VkImageUsageFlags usage) {
    if (!w || !h || w > r->max_image_size || h > r->max_image_size) return NULL;
    pc2_vk_texture *t=calloc(1,sizeof *t);
    if (!t) return NULL;
    t->owner=r;
    t->width=w;t->height=h;
    VkImageCreateInfo ii={.sType=VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
        .imageType=VK_IMAGE_TYPE_2D,.format=TEXTURE_FORMAT,
        .extent={w,h,1},.mipLevels=1,.arrayLayers=1,
        .samples=VK_SAMPLE_COUNT_1_BIT,.tiling=VK_IMAGE_TILING_OPTIMAL,
        .usage=usage,
        .sharingMode=VK_SHARING_MODE_EXCLUSIVE,.initialLayout=VK_IMAGE_LAYOUT_UNDEFINED};
    if (!gpu_ok(r,vkCreateImage(r->device,&ii,NULL,&t->image),"sprite image")) goto bad;
    VkMemoryRequirements req; vkGetImageMemoryRequirements(r->device,t->image,&req);
    if (!alloc_memory(r,req,VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,&t->memory)) goto bad;
    if (!gpu_ok(r,vkBindImageMemory(r->device,t->image,t->memory,0),"bind sprite image")) goto bad;
    VkImageViewCreateInfo vi={.sType=VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
        .image=t->image,.viewType=VK_IMAGE_VIEW_TYPE_2D,.format=TEXTURE_FORMAT,
        .subresourceRange={VK_IMAGE_ASPECT_COLOR_BIT,0,1,0,1}};
    if (!gpu_ok(r,vkCreateImageView(r->device,&vi,NULL,&t->view),"sprite view")) goto bad;
    VkDescriptorSetAllocateInfo da={.sType=VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,
        .descriptorPool=r->descriptor_pool,.descriptorSetCount=1,.pSetLayouts=&r->descriptor_layout};
    if (!gpu_ok(r,vkAllocateDescriptorSets(r->device,&da,&t->set),"sprite descriptor")) goto bad;
    VkDescriptorImageInfo image={.sampler=r->sampler,.imageView=t->view,
        .imageLayout=VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL};
    VkWriteDescriptorSet write={.sType=VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
        .dstSet=t->set,.dstBinding=0,.descriptorCount=1,
        .descriptorType=VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,.pImageInfo=&image};
    vkUpdateDescriptorSets(r->device,1,&write,0,NULL);
    return t;
bad: pc2_vk_texture_destroy(r,t);return NULL;
}

static pc2_vk_texture *texture_create(pc2_vk *r, uint32_t w, uint32_t h,
                                     const void *pixels, uint32_t pitch, int format, int key) {
    if (!r || !pixels || !source_pitch(w, h, &pitch, format)) return NULL;
    pc2_vk_texture *t=texture_alloc(r,w,h,VK_IMAGE_USAGE_SAMPLED_BIT|VK_IMAGE_USAGE_TRANSFER_DST_BIT);
    if (!t) return NULL;
    if (upload_texture(r,t,pixels,pitch,format,key)) return t;
    pc2_vk_texture_destroy(r,t);
    return NULL;
}

pc2_vk_texture *pc2_vk_target_create(pc2_vk *r, uint32_t w, uint32_t h) {
    uint32_t pitch=0;
    if (!r || w > r->max_target_width || h > r->max_target_height ||
        !source_pitch(w,h,&pitch,PIXELS_RGBA8)) return NULL;
    if (!r->target_pass.pass && !quad_pass_create(r,&r->target_pass,TEXTURE_FORMAT,1)) return NULL;
    pc2_vk_texture *t=texture_alloc(r,w,h,VK_IMAGE_USAGE_SAMPLED_BIT|
                                          VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT|
                                          VK_IMAGE_USAGE_TRANSFER_SRC_BIT);
    if (!t) return NULL;
    VkFramebufferCreateInfo framebuffer={.sType=VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO,
        .renderPass=r->target_pass.pass,.attachmentCount=1,.pAttachments=&t->view,
        .width=w,.height=h,.layers=1};
    if (gpu_ok(r,vkCreateFramebuffer(r->device,&framebuffer,NULL,&t->framebuffer),
               "texture framebuffer")) return t;
    pc2_vk_texture_destroy(r,t);
    return NULL;
}

pc2_vk_texture *pc2_vk_texture_create(pc2_vk *r, uint32_t w, uint32_t h,
                                     const uint8_t *rgba, uint32_t pitch) {
    return texture_create(r, w, h, rgba, pitch, PIXELS_RGBA8, -1);
}

pc2_vk_texture *pc2_vk_texture_create_rgb565(pc2_vk *r, uint32_t w, uint32_t h,
                                            const void *pixels, uint32_t pitch, int key) {
    if (key < -1 || key > 0xffff) return NULL;
    return texture_create(r, w, h, pixels, pitch, PIXELS_RGB565, key);
}

int pc2_vk_texture_update(pc2_vk *r, pc2_vk_texture *t, const uint8_t *rgba, uint32_t pitch) {
    if (!r || !t || t->owner!=r || t->retired || t->framebuffer || !rgba || r->active ||
        !source_pitch(t->width, t->height, &pitch, PIXELS_RGBA8))
        return 0;
    return upload_texture(r, t, rgba, pitch, PIXELS_RGBA8, -1);
}

int pc2_vk_texture_update_rgb565(pc2_vk *r, pc2_vk_texture *t,
                                const void *pixels, uint32_t pitch, int key) {
    if (!r || !t || t->owner!=r || t->retired || t->framebuffer || !pixels || r->active ||
        key < -1 || key > 0xffff ||
        !source_pitch(t->width, t->height, &pitch, PIXELS_RGB565))
        return 0;
    return upload_texture(r, t, pixels, pitch, PIXELS_RGB565, key);
}

static void rgb565_to_rgba(uint8_t *rgba, const uint8_t *pixels, uint32_t width, int key) {
    for (uint32_t x = 0; x < width; ++x) {
        int value = pixels[2*x] | (pixels[2*x+1] << 8);
        rgba[4*x]   = (uint8_t)(((value >> 11) & 31) * 255 / 31);
        rgba[4*x+1] = (uint8_t)(((value >> 5) & 63) * 255 / 63);
        rgba[4*x+2] = (uint8_t)((value & 31) * 255 / 31);
        rgba[4*x+3] = value == key ? 0 : 255;
    }
}

static int upload_texture(pc2_vk *r, pc2_vk_texture *t, const uint8_t *pixels,
                          uint32_t pitch, int format, int key) {
    /* A fresh texture can be uploaded during graphics command recording.
       An existing image may only change between frames so queued quads keep
       their original pixels. Both operations complete on the graphics queue. */
    if (t->layout_initialized && !gpu_ok(r, vkQueueWaitIdle(r->queue), "sprite upload wait"))
        return 0;
    VkDeviceSize bytes=(VkDeviceSize)t->width*t->height*4u;
    VkBuffer stage=VK_NULL_HANDLE; VkDeviceMemory memory=VK_NULL_HANDLE;
    if (!buffer_create(r,bytes,VK_BUFFER_USAGE_TRANSFER_SRC_BIT,&stage,&memory)) return 0;
    void *mapped=NULL;
    if (!gpu_ok(r,vkMapMemory(r->device,memory,0,bytes,0,&mapped),"map sprite upload")) goto bad;
    for (uint32_t y = 0; y < t->height; ++y) {
        uint8_t *dest = (uint8_t *)mapped + (size_t)y*t->width*4;
        const uint8_t *source = pixels + (size_t)y*pitch;
        if (format == PIXELS_RGB565) rgb565_to_rgba(dest, source, t->width, key);
        else memcpy(dest, source, (size_t)t->width*4);
    }
    vkUnmapMemory(r->device,memory);
    VkCommandBuffer cmd;
    if (!one_time_begin(r,&cmd)) goto bad;
    /* Image transitions old SHADER_READ_ONLY -> TRANSFER_DST on subsequent updates. */
    transition(cmd,t->image,t->layout_initialized?VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:VK_IMAGE_LAYOUT_UNDEFINED,
        VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
        t->layout_initialized?VK_ACCESS_SHADER_READ_BIT:0,VK_ACCESS_TRANSFER_WRITE_BIT,
        t->layout_initialized?VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT:VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
        VK_PIPELINE_STAGE_TRANSFER_BIT);
    VkBufferImageCopy region={.bufferOffset=0,.bufferRowLength=0,.bufferImageHeight=0,
        .imageSubresource={VK_IMAGE_ASPECT_COLOR_BIT,0,0,1},.imageExtent={t->width,t->height,1}};
    vkCmdCopyBufferToImage(cmd,stage,t->image,VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,1,&region);
    transition(cmd,t->image,VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
        VK_ACCESS_TRANSFER_WRITE_BIT,VK_ACCESS_SHADER_READ_BIT,
        VK_PIPELINE_STAGE_TRANSFER_BIT,VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT);
    int ok=one_time_end(r,cmd);
    if (ok) t->layout_initialized=1;
    vkDestroyBuffer(r->device,stage,NULL); vkFreeMemory(r->device,memory,NULL);
    return ok;
bad:
    if (stage) vkDestroyBuffer(r->device,stage,NULL);
    if (memory) vkFreeMemory(r->device,memory,NULL);
    return 0;
}
static void release_texture(pc2_vk *r, pc2_vk_texture *t) {
    if (t->set) vkFreeDescriptorSets(r->device,r->descriptor_pool,1,&t->set);
    if (t->framebuffer) vkDestroyFramebuffer(r->device,t->framebuffer,NULL);
    if (t->view) vkDestroyImageView(r->device,t->view,NULL);
    if (t->image) vkDestroyImage(r->device,t->image,NULL);
    if (t->memory) vkFreeMemory(r->device,t->memory,NULL);
    free(t);
}

static void release_retired_textures(pc2_vk *r) {
    while (r->retired_textures) {
        pc2_vk_texture *t = r->retired_textures;
        r->retired_textures = t->retired_next;
        release_texture(r, t);
    }
}

void pc2_vk_texture_destroy(pc2_vk *r,pc2_vk_texture *t) {
    if (!r || !t || t->owner!=r || t->retired) return;
    if (!t->layout_initialized && t!=r->active_target) {
        release_texture(r, t);
        return;
    }
    t->retired=1;
    t->retired_next = r->retired_textures;
    r->retired_textures = t;
}

static int wait_frame(pc2_vk *r) {
    if (!gpu_ok(r,vkQueueWaitIdle(r->queue),"frame wait")) return 0;
    release_retired_textures(r);
    return 1;
}

static VkViewport target_viewport(pc2_vk_texture *target) {
    return (VkViewport){.width=(float)target->width,.height=(float)target->height,.maxDepth=1};
}

static int begin_pass(pc2_vk *r, VkRenderPass pass, VkFramebuffer framebuffer, VkExtent2D extent,
                      const VkViewport *viewport, const VkClearValue *clear) {
    if (!gpu_ok(r,vkResetCommandBuffer(r->command,0),"command reset")) return 0;
    VkCommandBufferBeginInfo cb={.sType=VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
                                 .flags=VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT};
    if (!gpu_ok(r,vkBeginCommandBuffer(r->command,&cb),"command begin")) return 0;
    VkRenderPassBeginInfo rp={.sType=VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
        .renderPass=pass,.framebuffer=framebuffer,
        .renderArea={{0,0},extent},.clearValueCount=clear ? 1u : 0u,.pClearValues=clear};
    vkCmdBeginRenderPass(r->command,&rp,VK_SUBPASS_CONTENTS_INLINE);
    vkCmdSetViewport(r->command,0,1,viewport);
    r->bound_pipeline=VK_NULL_HANDLE;
    r->active=1;
    return 1;
}

int pc2_vk_begin(pc2_vk *r,float red,float green,float blue,float alpha) {
    if (!r||!r->window||!r->swapchain||r->active||!wait_frame(r)) return 0;
    VkResult v=vkAcquireNextImageKHR(r->device,r->swapchain,UINT64_MAX,r->acquired,
                                      VK_NULL_HANDLE,&r->current_image);
    if (v==VK_ERROR_OUT_OF_DATE_KHR) {if (!pc2_vk_resize(r)) return 0;
        v=vkAcquireNextImageKHR(r->device,r->swapchain,UINT64_MAX,r->acquired,
                               VK_NULL_HANDLE,&r->current_image);}
    if (v!=VK_SUCCESS && v!=VK_SUBOPTIMAL_KHR) return gpu_ok(r,v,"acquire swap image");
    VkClearValue clear={.color={{red,green,blue,alpha}}};
    return begin_pass(r,r->swap_pass.pass,r->framebuffers[r->current_image],r->extent,&r->viewport,&clear);
}

static int begin_target(pc2_vk *r, pc2_vk_texture *t, const VkClearValue *clear) {
    if (!r||!t||t->owner!=r||t->retired||!t->framebuffer||r->active||
        (!clear&&!t->layout_initialized)||!wait_frame(r)) return 0;
    VkRenderPass pass=r->target_pass.pass;
    if (!clear) {
        /* Both passes use the same attachment and dependencies. The load
           operation and initial layout may differ without affecting compatibility. */
        if (!r->target_load_pass && !render_pass_create(r,TEXTURE_FORMAT,1,1,&r->target_load_pass))
            return 0;
        pass=r->target_load_pass;
    }
    VkExtent2D extent={t->width,t->height};
    VkViewport viewport=target_viewport(t);
    if (!begin_pass(r,pass,t->framebuffer,extent,&viewport,clear)) return 0;
    r->active_target=t;
    return 1;
}

int pc2_vk_begin_target(pc2_vk *r, pc2_vk_texture *t, float red,float green,float blue,float alpha) {
    const VkClearValue clear={.color={{red*alpha,green*alpha,blue*alpha,alpha}}};
    return begin_target(r,t,&clear);
}

int pc2_vk_begin_target_load(pc2_vk *r, pc2_vk_texture *t) {
    return begin_target(r,t,NULL);
}

void pc2_vk_draw(pc2_vk *r,pc2_vk_texture *t,float x,float y,float w,float h,
                 float u0,float v0,float u1,float v1,int cx,int cy,int cw,int ch) {
    if (!r||!r->active||!t||t->owner!=r||t->retired||!t->layout_initialized||
        t==r->active_target||w<=0||h<=0||cw<=0||ch<=0) return;
    float canvas_w=CANVAS_W, canvas_h=CANVAS_H;
    VkViewport viewport=r->viewport;
    VkExtent2D extent=r->extent;
    const quad_pass *pass=&r->swap_pass;
    if (r->active_target) {
        pc2_vk_texture *target=r->active_target;
        canvas_w=(float)target->width;
        canvas_h=(float)target->height;
        viewport=target_viewport(target);
        extent=(VkExtent2D){target->width,target->height};
        pass=&r->target_pass;
    }
    float sx=viewport.width/canvas_w, sy=viewport.height/canvas_h;
    float left=fmaxf(viewport.x+cx*sx,viewport.x);
    float top=fmaxf(viewport.y+cy*sy,viewport.y);
    float right=fminf(viewport.x+((float)cx+cw)*sx,viewport.x+viewport.width);
    float bottom=fminf(viewport.y+((float)cy+ch)*sy,viewport.y+viewport.height);
    right=fminf(right,(float)extent.width);
    bottom=fminf(bottom,(float)extent.height);
    if (right<=left||bottom<=top) return;
    VkRect2D scissor={{(int32_t)floorf(left),(int32_t)floorf(top)},
        {(uint32_t)(ceilf(right)-floorf(left)),(uint32_t)(ceilf(bottom)-floorf(top))}};
    if (scissor.offset.x+(int)scissor.extent.width>(int)extent.width)
        scissor.extent.width=extent.width-scissor.offset.x;
    if (scissor.offset.y+(int)scissor.extent.height>(int)extent.height)
        scissor.extent.height=extent.height-scissor.offset.y;
    VkPipeline pipeline=t->framebuffer ? pass->premultiplied : pass->rgba;
    if (pipeline!=r->bound_pipeline) {
        vkCmdBindPipeline(r->command,VK_PIPELINE_BIND_POINT_GRAPHICS,pipeline);
        r->bound_pipeline=pipeline;
    }
    vkCmdSetScissor(r->command,0,1,&scissor);
    struct {float rect[4];float uv[4];float canvas[2];float pad[2];} push={
        {x,y,w,h},{u0,v0,u1,v1},{canvas_w,canvas_h},{0,0}};
    vkCmdPushConstants(r->command,r->layout,VK_SHADER_STAGE_VERTEX_BIT,0,sizeof push,&push);
    vkCmdBindDescriptorSets(r->command,VK_PIPELINE_BIND_POINT_GRAPHICS,r->layout,0,1,&t->set,0,NULL);
    vkCmdDraw(r->command,6,1,0,0);
}

void pc2_vk_draw_rect(pc2_vk *r, pc2_vk_texture *t,
                     float x, float y, float w, float h,
                     int sx, int sy, int sw, int sh,
                     int cx, int cy, int cw, int ch) {
    if (!t || sw <= 0 || sh <= 0) return;
    int left = sx < 0 ? 0 : sx;
    int top = sy < 0 ? 0 : sy;
    int64_t right = (int64_t)sx + sw;
    int64_t bottom = (int64_t)sy + sh;
    if (right > t->width) right = t->width;
    if (bottom > t->height) bottom = t->height;
    if (right <= left || bottom <= top) return;
    if (left != sx || right != (int64_t)sx + sw) {
        float scale = w / sw;
        x += (float)((int64_t)left - sx) * scale;
        w = (float)(right - left) * scale;
    }
    if (top != sy || bottom != (int64_t)sy + sh) {
        float scale = h / sh;
        y += (float)((int64_t)top - sy) * scale;
        h = (float)(bottom - top) * scale;
    }
    pc2_vk_draw(r, t, x, y, w, h,
                (float)left / t->width, (float)top / t->height,
                (float)right / t->width, (float)bottom / t->height, cx, cy, cw, ch);
}

int pc2_vk_end(pc2_vk *r) {
    if (!r||!r->active) return 0;
    pc2_vk_texture *target=r->active_target;
    r->active_target=NULL;
    r->active=0;
    vkCmdEndRenderPass(r->command);
    if (!gpu_ok(r,vkEndCommandBuffer(r->command),"command end")) return 0;
    VkSubmitInfo submit={.sType=VK_STRUCTURE_TYPE_SUBMIT_INFO,
                         .commandBufferCount=1,.pCommandBuffers=&r->command};
    if (target) {
        if (!gpu_ok(r,vkQueueSubmit(r->queue,1,&submit,VK_NULL_HANDLE),"texture render submit"))
            return 0;
        target->layout_initialized=1;
        return 1;
    }
    VkPipelineStageFlags wait_stage=VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    submit.waitSemaphoreCount=1;
    submit.pWaitSemaphores=&r->acquired;
    submit.pWaitDstStageMask=&wait_stage;
    submit.signalSemaphoreCount=1;
    submit.pSignalSemaphores=&r->render_done[r->current_image];
    if (!gpu_ok(r,vkQueueSubmit(r->queue,1,&submit,VK_NULL_HANDLE),"frame submit")) return 0;
    VkPresentInfoKHR present={.sType=VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,
        .waitSemaphoreCount=1,.pWaitSemaphores=&r->render_done[r->current_image],
        .swapchainCount=1,.pSwapchains=&r->swapchain,.pImageIndices=&r->current_image};
    VkResult v=vkQueuePresentKHR(r->queue,&present);
    if (v==VK_ERROR_OUT_OF_DATE_KHR||v==VK_SUBOPTIMAL_KHR) return pc2_vk_resize(r);
    return gpu_ok(r,v,"present");
}

int pc2_vk_target_read_rgba(pc2_vk *r, pc2_vk_texture *t,
                           uint8_t *rgba, size_t size, uint32_t pitch) {
    if (!r||r->active||!t||t->owner!=r||t->retired||!t->framebuffer||
        !t->layout_initialized||!rgba||!source_pitch(t->width,t->height,&pitch,PIXELS_RGBA8))
        return 0;
    uint32_t row_bytes=t->width*4;
    if (size<(size_t)(t->height-1)*pitch+row_bytes) return 0;
    VkDeviceSize bytes=(VkDeviceSize)row_bytes*t->height;
    VkBuffer stage=VK_NULL_HANDLE;
    VkDeviceMemory memory=VK_NULL_HANDLE;
    if (!buffer_create(r,bytes,VK_BUFFER_USAGE_TRANSFER_DST_BIT,&stage,&memory)) return 0;
    int ok=0;
    VkCommandBuffer cmd;
    if (!one_time_begin(r,&cmd)) goto done;
    transition(cmd,t->image,VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
        VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,VK_ACCESS_SHADER_READ_BIT|VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
        VK_ACCESS_TRANSFER_READ_BIT,VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT|VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
        VK_PIPELINE_STAGE_TRANSFER_BIT);
    VkBufferImageCopy region={.imageSubresource={VK_IMAGE_ASPECT_COLOR_BIT,0,0,1},
                              .imageExtent={t->width,t->height,1}};
    vkCmdCopyImageToBuffer(cmd,t->image,VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,stage,1,&region);
    transition(cmd,t->image,VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
        VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,VK_ACCESS_TRANSFER_READ_BIT,VK_ACCESS_SHADER_READ_BIT,
        VK_PIPELINE_STAGE_TRANSFER_BIT,VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT);
    VkBufferMemoryBarrier host={.sType=VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
        .srcAccessMask=VK_ACCESS_TRANSFER_WRITE_BIT,.dstAccessMask=VK_ACCESS_HOST_READ_BIT,
        .srcQueueFamilyIndex=VK_QUEUE_FAMILY_IGNORED,.dstQueueFamilyIndex=VK_QUEUE_FAMILY_IGNORED,
        .buffer=stage,.size=bytes};
    vkCmdPipelineBarrier(cmd,VK_PIPELINE_STAGE_TRANSFER_BIT,VK_PIPELINE_STAGE_HOST_BIT,
                         0,0,NULL,1,&host,0,NULL);
    if (!one_time_end(r,cmd)) goto done;
    void *mapped=NULL;
    if (!gpu_ok(r,vkMapMemory(r->device,memory,0,bytes,0,&mapped),"map texture readback")) goto done;
    for (uint32_t y=0; y<t->height; ++y)
        memcpy(rgba+(size_t)y*pitch,(const uint8_t *)mapped+(size_t)y*row_bytes,row_bytes);
    vkUnmapMemory(r->device,memory);
    ok=1;
done:
    vkDestroyBuffer(r->device,stage,NULL);
    vkFreeMemory(r->device,memory,NULL);
    return ok;
}

void pc2_vk_destroy(pc2_vk *r) {
    if (!r) return;
    swap_destroy(r);
    if (r->device) {
        release_retired_textures(r);
        if (r->target_load_pass) vkDestroyRenderPass(r->device,r->target_load_pass,NULL);
        quad_pass_destroy(r,&r->target_pass);
        if (r->acquired) vkDestroySemaphore(r->device,r->acquired,NULL);
        if (r->sampler) vkDestroySampler(r->device,r->sampler,NULL);
        if (r->descriptor_pool) vkDestroyDescriptorPool(r->device,r->descriptor_pool,NULL);
        if (r->layout) vkDestroyPipelineLayout(r->device,r->layout,NULL);
        if (r->descriptor_layout) vkDestroyDescriptorSetLayout(r->device,r->descriptor_layout,NULL);
        if (r->pool) vkDestroyCommandPool(r->device,r->pool,NULL);
        vkDestroyDevice(r->device,NULL);
    }
    if (r->surface) vkDestroySurfaceKHR(r->instance,r->surface,NULL);
    if (r->instance) vkDestroyInstance(r->instance,NULL);
    free(r);
}
