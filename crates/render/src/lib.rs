//! Minimal Vulkan-backed renderer bring-up.
//!
//! The first roadmap renderer deliverable is two overlapping textured quads.
//! This module runs headlessly against `wgpu`'s Vulkan backend, renders into a
//! 64x64 target, and returns the RGBA pixels for deterministic checks.

use std::borrow::Cow;

use bytemuck::{Pod, Zeroable};

pub const TARGET_SIZE: u32 = 64;

#[derive(Clone, Copy, Debug, Pod, Zeroable)]
#[repr(C)]
struct Vertex {
    position: [f32; 2],
    uv: [f32; 2],
}

#[derive(Debug)]
pub struct QuadResult {
    pub adapter: String,
    pub backend: String,
    pub pixels: Vec<u8>,
}

impl QuadResult {
    pub fn pixel(&self, x: u32, y: u32) -> [u8; 4] {
        let offset = ((y * TARGET_SIZE + x) * 4) as usize;
        [
            self.pixels[offset],
            self.pixels[offset + 1],
            self.pixels[offset + 2],
            self.pixels[offset + 3],
        ]
    }
}

const SHADER: &str = r#"
struct VertexOutput {
    @builtin(position) position: vec4<f32>,
    @location(0) uv: vec2<f32>,
};

@vertex
fn vs(@location(0) position: vec2<f32>, @location(1) uv: vec2<f32>) -> VertexOutput {
    var out: VertexOutput;
    out.position = vec4<f32>(position, 0.0, 1.0);
    out.uv = uv;
    return out;
}

@group(0) @binding(0) var source: texture_2d<f32>;
@group(0) @binding(1) var source_sampler: sampler;

@fragment
fn fs(in: VertexOutput) -> @location(0) vec4<f32> {
    return textureSample(source, source_sampler, in.uv);
}
"#;

fn quad_vertices(min: f32, max: f32) -> [Vertex; 6] {
    let corners = [
        (min, min, 0.0, 1.0),
        (max, min, 1.0, 1.0),
        (max, max, 1.0, 0.0),
        (min, min, 0.0, 1.0),
        (max, max, 1.0, 0.0),
        (min, max, 0.0, 0.0),
    ];
    corners.map(|(x, y, u, v)| Vertex {
        position: [x, y],
        uv: [u, v],
    })
}

fn solid_texture(device: &wgpu::Device, queue: &wgpu::Queue, color: [u8; 4]) -> wgpu::Texture {
    let texture = device.create_texture(&wgpu::TextureDescriptor {
        label: Some("solid 2x2"),
        size: wgpu::Extent3d {
            width: 2,
            height: 2,
            depth_or_array_layers: 1,
        },
        mip_level_count: 1,
        sample_count: 1,
        dimension: wgpu::TextureDimension::D2,
        format: wgpu::TextureFormat::Rgba8UnormSrgb,
        usage: wgpu::TextureUsages::TEXTURE_BINDING | wgpu::TextureUsages::COPY_DST,
        view_formats: &[],
    });
    let data = color.repeat(4);
    queue.write_texture(
        wgpu::TexelCopyTextureInfo {
            texture: &texture,
            mip_level: 0,
            origin: wgpu::Origin3d::ZERO,
            aspect: wgpu::TextureAspect::All,
        },
        &data,
        wgpu::TexelCopyBufferLayout {
            offset: 0,
            bytes_per_row: Some(8),
            rows_per_image: Some(2),
        },
        wgpu::Extent3d {
            width: 2,
            height: 2,
            depth_or_array_layers: 1,
        },
    );
    texture
}

pub fn render_two_quads() -> Result<QuadResult, String> {
    let mut instance_desc = wgpu::InstanceDescriptor::new_without_display_handle();
    instance_desc.backends = wgpu::Backends::VULKAN;
    let instance = wgpu::Instance::new(instance_desc);
    let adapter = pollster::block_on(instance.request_adapter(&wgpu::RequestAdapterOptions {
        power_preference: wgpu::PowerPreference::LowPower,
        compatible_surface: None,
        force_fallback_adapter: false,
        apply_limit_buckets: false,
    }))
    .map_err(|error| format!("Vulkan adapter request failed: {error}"))?;
    let info = adapter.get_info();
    let (device, queue) = pollster::block_on(adapter.request_device(&wgpu::DeviceDescriptor {
        label: Some("pc2-render"),
        required_features: wgpu::Features::empty(),
        required_limits: wgpu::Limits::downlevel_defaults(),
        ..Default::default()
    }))
    .map_err(|error| format!("Vulkan device request failed: {error}"))?;

    let target = device.create_texture(&wgpu::TextureDescriptor {
        label: Some("quad target"),
        size: wgpu::Extent3d {
            width: TARGET_SIZE,
            height: TARGET_SIZE,
            depth_or_array_layers: 1,
        },
        mip_level_count: 1,
        sample_count: 1,
        dimension: wgpu::TextureDimension::D2,
        format: wgpu::TextureFormat::Rgba8UnormSrgb,
        usage: wgpu::TextureUsages::RENDER_ATTACHMENT | wgpu::TextureUsages::COPY_SRC,
        view_formats: &[],
    });
    let target_view = target.create_view(&wgpu::TextureViewDescriptor::default());

    let red = solid_texture(&device, &queue, [255, 0, 0, 255]);
    let green = solid_texture(&device, &queue, [0, 255, 0, 255]);
    let red_view = red.create_view(&wgpu::TextureViewDescriptor::default());
    let green_view = green.create_view(&wgpu::TextureViewDescriptor::default());
    let sampler = device.create_sampler(&wgpu::SamplerDescriptor {
        label: Some("nearest"),
        mag_filter: wgpu::FilterMode::Nearest,
        min_filter: wgpu::FilterMode::Nearest,
        ..Default::default()
    });

    let bind_layout = device.create_bind_group_layout(&wgpu::BindGroupLayoutDescriptor {
        label: Some("texture bind layout"),
        entries: &[
            wgpu::BindGroupLayoutEntry {
                binding: 0,
                visibility: wgpu::ShaderStages::FRAGMENT,
                ty: wgpu::BindingType::Texture {
                    sample_type: wgpu::TextureSampleType::Float { filterable: true },
                    view_dimension: wgpu::TextureViewDimension::D2,
                    multisampled: false,
                },
                count: None,
            },
            wgpu::BindGroupLayoutEntry {
                binding: 1,
                visibility: wgpu::ShaderStages::FRAGMENT,
                ty: wgpu::BindingType::Sampler(wgpu::SamplerBindingType::Filtering),
                count: None,
            },
        ],
    });
    let bind_red = device.create_bind_group(&wgpu::BindGroupDescriptor {
        label: Some("red bind"),
        layout: &bind_layout,
        entries: &[
            wgpu::BindGroupEntry {
                binding: 0,
                resource: wgpu::BindingResource::TextureView(&red_view),
            },
            wgpu::BindGroupEntry {
                binding: 1,
                resource: wgpu::BindingResource::Sampler(&sampler),
            },
        ],
    });
    let bind_green = device.create_bind_group(&wgpu::BindGroupDescriptor {
        label: Some("green bind"),
        layout: &bind_layout,
        entries: &[
            wgpu::BindGroupEntry {
                binding: 0,
                resource: wgpu::BindingResource::TextureView(&green_view),
            },
            wgpu::BindGroupEntry {
                binding: 1,
                resource: wgpu::BindingResource::Sampler(&sampler),
            },
        ],
    });

    let shader = device.create_shader_module(wgpu::ShaderModuleDescriptor {
        label: Some("two quads"),
        source: wgpu::ShaderSource::Wgsl(Cow::Borrowed(SHADER)),
    });
    let pipeline_layout = device.create_pipeline_layout(&wgpu::PipelineLayoutDescriptor {
        label: Some("quad pipeline layout"),
        bind_group_layouts: &[Some(&bind_layout)],
        immediate_size: 0,
    });
    let pipeline = device.create_render_pipeline(&wgpu::RenderPipelineDescriptor {
        label: Some("quad pipeline"),
        layout: Some(&pipeline_layout),
        vertex: wgpu::VertexState {
            module: &shader,
            entry_point: Some("vs"),
            compilation_options: Default::default(),
            buffers: &[Some(wgpu::VertexBufferLayout {
                array_stride: std::mem::size_of::<Vertex>() as u64,
                step_mode: wgpu::VertexStepMode::Vertex,
                attributes: &[
                    wgpu::VertexAttribute {
                        format: wgpu::VertexFormat::Float32x2,
                        offset: 0,
                        shader_location: 0,
                    },
                    wgpu::VertexAttribute {
                        format: wgpu::VertexFormat::Float32x2,
                        offset: 8,
                        shader_location: 1,
                    },
                ],
            })],
        },
        primitive: wgpu::PrimitiveState::default(),
        depth_stencil: None,
        multisample: wgpu::MultisampleState::default(),
        fragment: Some(wgpu::FragmentState {
            module: &shader,
            entry_point: Some("fs"),
            compilation_options: Default::default(),
            targets: &[Some(wgpu::ColorTargetState {
                format: wgpu::TextureFormat::Rgba8UnormSrgb,
                blend: Some(wgpu::BlendState::REPLACE),
                write_mask: wgpu::ColorWrites::ALL,
            })],
        }),
        multiview_mask: None,
        cache: None,
    });

    let red_vertices = quad_vertices(-0.8, 0.2);
    let green_vertices = quad_vertices(-0.2, 0.8);
    let vertex_buffer = |label: &str| {
        device.create_buffer(&wgpu::BufferDescriptor {
            label: Some(label),
            size: std::mem::size_of_val(&red_vertices) as u64,
            usage: wgpu::BufferUsages::VERTEX | wgpu::BufferUsages::COPY_DST,
            mapped_at_creation: false,
        })
    };
    let red_buffer = vertex_buffer("red quad");
    let green_buffer = vertex_buffer("green quad");
    queue.write_buffer(&red_buffer, 0, bytemuck::cast_slice(&red_vertices));
    queue.write_buffer(&green_buffer, 0, bytemuck::cast_slice(&green_vertices));

    let readback = device.create_buffer(&wgpu::BufferDescriptor {
        label: Some("target readback"),
        size: (TARGET_SIZE * TARGET_SIZE * 4) as u64,
        usage: wgpu::BufferUsages::COPY_DST | wgpu::BufferUsages::MAP_READ,
        mapped_at_creation: false,
    });
    let mut encoder = device.create_command_encoder(&wgpu::CommandEncoderDescriptor {
        label: Some("quad encoder"),
    });
    {
        let mut pass = encoder.begin_render_pass(&wgpu::RenderPassDescriptor {
            label: Some("two quads"),
            color_attachments: &[Some(wgpu::RenderPassColorAttachment {
                view: &target_view,
                depth_slice: None,
                resolve_target: None,
                ops: wgpu::Operations {
                    load: wgpu::LoadOp::Clear(wgpu::Color::BLACK),
                    store: wgpu::StoreOp::Store,
                },
            })],
            depth_stencil_attachment: None,
            timestamp_writes: None,
            occlusion_query_set: None,
            multiview_mask: None,
        });
        pass.set_pipeline(&pipeline);
        pass.set_bind_group(0, &bind_red, &[]);
        pass.set_vertex_buffer(0, red_buffer.slice(..));
        pass.draw(0..6, 0..1);
        pass.set_bind_group(0, &bind_green, &[]);
        pass.set_vertex_buffer(0, green_buffer.slice(..));
        pass.draw(0..6, 0..1);
    }
    encoder.copy_texture_to_buffer(
        wgpu::TexelCopyTextureInfo {
            texture: &target,
            mip_level: 0,
            origin: wgpu::Origin3d::ZERO,
            aspect: wgpu::TextureAspect::All,
        },
        wgpu::TexelCopyBufferInfo {
            buffer: &readback,
            layout: wgpu::TexelCopyBufferLayout {
                offset: 0,
                bytes_per_row: Some(TARGET_SIZE * 4),
                rows_per_image: Some(TARGET_SIZE),
            },
        },
        wgpu::Extent3d {
            width: TARGET_SIZE,
            height: TARGET_SIZE,
            depth_or_array_layers: 1,
        },
    );
    queue.submit(Some(encoder.finish()));

    let slice = readback.slice(..);
    let (sender, receiver) = std::sync::mpsc::channel();
    slice.map_async(wgpu::MapMode::Read, move |result| {
        let _ = sender.send(result);
    });
    device
        .poll(wgpu::PollType::wait_indefinitely())
        .map_err(|error| format!("poll failed: {error:?}"))?;
    receiver
        .recv()
        .map_err(|error| format!("map channel failed: {error}"))?
        .map_err(|error| format!("map failed: {error}"))?;
    let pixels = slice
        .get_mapped_range()
        .map_err(|error| format!("mapped range failed: {error:?}"))?
        .to_vec();
    let _ = slice;
    readback.unmap();

    Ok(QuadResult {
        adapter: info.name,
        backend: format!("{:?}", info.backend),
        pixels,
    })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn vulkan_two_quads() {
        let result = render_two_quads().expect("Vulkan render");
        assert_eq!(
            result.pixels.len(),
            (TARGET_SIZE * TARGET_SIZE * 4) as usize
        );
        assert_eq!(result.backend, "Vulkan");
        assert_eq!(result.pixel(8, 56), [255, 0, 0, 255]);
        assert_eq!(result.pixel(56, 8), [0, 255, 0, 255]);
        assert_eq!(result.pixel(32, 32), [0, 255, 0, 255]);
    }
}

#[derive(Debug)]
pub struct RenderedFrame {
    pub adapter: String,
    pub backend: String,
    pub width: u32,
    pub height: u32,
    pub pixels: Vec<u8>,
}

impl RenderedFrame {
    pub fn pixel(&self, x: u32, y: u32) -> [u8; 4] {
        let offset = ((y * self.width + x) * 4) as usize;
        [
            self.pixels[offset],
            self.pixels[offset + 1],
            self.pixels[offset + 2],
            self.pixels[offset + 3],
        ]
    }
}

/// Render a CPU-decoded RGBA image into an offscreen Vulkan texture and read it
/// back. The scene viewer uses this to prove the same crop that is written as
/// a PNG also passes through the Vulkan path.
pub fn render_rgba(width: u32, height: u32, rgba: &[u8]) -> Result<RenderedFrame, String> {
    if width == 0 || height == 0 {
        return Err("image dimensions must be non-zero".into());
    }
    if rgba.len() != (width * height * 4) as usize {
        return Err(format!(
            "RGBA length {} does not match {width}x{height}",
            rgba.len()
        ));
    }

    let mut instance_desc = wgpu::InstanceDescriptor::new_without_display_handle();
    instance_desc.backends = wgpu::Backends::VULKAN;
    let instance = wgpu::Instance::new(instance_desc);
    let adapter = pollster::block_on(instance.request_adapter(&wgpu::RequestAdapterOptions {
        power_preference: wgpu::PowerPreference::LowPower,
        compatible_surface: None,
        force_fallback_adapter: false,
        apply_limit_buckets: false,
    }))
    .map_err(|error| format!("Vulkan adapter request failed: {error}"))?;
    let info = adapter.get_info();
    let (device, queue) = pollster::block_on(adapter.request_device(&wgpu::DeviceDescriptor {
        label: Some("pc2-render"),
        required_features: wgpu::Features::empty(),
        required_limits: wgpu::Limits::downlevel_defaults(),
        ..Default::default()
    }))
    .map_err(|error| format!("Vulkan device request failed: {error}"))?;

    let texture = device.create_texture(&wgpu::TextureDescriptor {
        label: Some("scene upload"),
        size: wgpu::Extent3d {
            width,
            height,
            depth_or_array_layers: 1,
        },
        mip_level_count: 1,
        sample_count: 1,
        dimension: wgpu::TextureDimension::D2,
        format: wgpu::TextureFormat::Rgba8UnormSrgb,
        usage: wgpu::TextureUsages::TEXTURE_BINDING | wgpu::TextureUsages::COPY_DST,
        view_formats: &[],
    });
    let padded_bytes_per_row = ((width * 4 + 255) / 256) * 256;
    let mut padded = vec![0u8; (padded_bytes_per_row * height) as usize];
    for y in 0..height {
        let source = (y * width * 4) as usize;
        let target = (y * padded_bytes_per_row) as usize;
        padded[target..target + (width * 4) as usize]
            .copy_from_slice(&rgba[source..source + (width * 4) as usize]);
    }
    queue.write_texture(
        wgpu::TexelCopyTextureInfo {
            texture: &texture,
            mip_level: 0,
            origin: wgpu::Origin3d::ZERO,
            aspect: wgpu::TextureAspect::All,
        },
        &padded,
        wgpu::TexelCopyBufferLayout {
            offset: 0,
            bytes_per_row: Some(padded_bytes_per_row),
            rows_per_image: Some(height),
        },
        wgpu::Extent3d {
            width,
            height,
            depth_or_array_layers: 1,
        },
    );

    let target = device.create_texture(&wgpu::TextureDescriptor {
        label: Some("scene target"),
        size: wgpu::Extent3d {
            width,
            height,
            depth_or_array_layers: 1,
        },
        mip_level_count: 1,
        sample_count: 1,
        dimension: wgpu::TextureDimension::D2,
        format: wgpu::TextureFormat::Rgba8UnormSrgb,
        usage: wgpu::TextureUsages::RENDER_ATTACHMENT | wgpu::TextureUsages::COPY_SRC,
        view_formats: &[],
    });
    let target_view = target.create_view(&wgpu::TextureViewDescriptor::default());
    let source_view = texture.create_view(&wgpu::TextureViewDescriptor::default());
    let sampler = device.create_sampler(&wgpu::SamplerDescriptor {
        label: Some("scene nearest"),
        mag_filter: wgpu::FilterMode::Nearest,
        min_filter: wgpu::FilterMode::Nearest,
        ..Default::default()
    });
    let bind_layout = device.create_bind_group_layout(&wgpu::BindGroupLayoutDescriptor {
        label: Some("scene bind layout"),
        entries: &[
            wgpu::BindGroupLayoutEntry {
                binding: 0,
                visibility: wgpu::ShaderStages::FRAGMENT,
                ty: wgpu::BindingType::Texture {
                    sample_type: wgpu::TextureSampleType::Float { filterable: true },
                    view_dimension: wgpu::TextureViewDimension::D2,
                    multisampled: false,
                },
                count: None,
            },
            wgpu::BindGroupLayoutEntry {
                binding: 1,
                visibility: wgpu::ShaderStages::FRAGMENT,
                ty: wgpu::BindingType::Sampler(wgpu::SamplerBindingType::Filtering),
                count: None,
            },
        ],
    });
    let bind_group = device.create_bind_group(&wgpu::BindGroupDescriptor {
        label: Some("scene bind"),
        layout: &bind_layout,
        entries: &[
            wgpu::BindGroupEntry {
                binding: 0,
                resource: wgpu::BindingResource::TextureView(&source_view),
            },
            wgpu::BindGroupEntry {
                binding: 1,
                resource: wgpu::BindingResource::Sampler(&sampler),
            },
        ],
    });
    let shader = device.create_shader_module(wgpu::ShaderModuleDescriptor {
        label: Some("scene shader"),
        source: wgpu::ShaderSource::Wgsl(Cow::Borrowed(SHADER)),
    });
    let pipeline_layout = device.create_pipeline_layout(&wgpu::PipelineLayoutDescriptor {
        label: Some("scene pipeline layout"),
        bind_group_layouts: &[Some(&bind_layout)],
        immediate_size: 0,
    });
    let pipeline = device.create_render_pipeline(&wgpu::RenderPipelineDescriptor {
        label: Some("scene pipeline"),
        layout: Some(&pipeline_layout),
        vertex: wgpu::VertexState {
            module: &shader,
            entry_point: Some("vs"),
            compilation_options: Default::default(),
            buffers: &[Some(wgpu::VertexBufferLayout {
                array_stride: std::mem::size_of::<Vertex>() as u64,
                step_mode: wgpu::VertexStepMode::Vertex,
                attributes: &[
                    wgpu::VertexAttribute {
                        format: wgpu::VertexFormat::Float32x2,
                        offset: 0,
                        shader_location: 0,
                    },
                    wgpu::VertexAttribute {
                        format: wgpu::VertexFormat::Float32x2,
                        offset: 8,
                        shader_location: 1,
                    },
                ],
            })],
        },
        primitive: wgpu::PrimitiveState::default(),
        depth_stencil: None,
        multisample: wgpu::MultisampleState::default(),
        fragment: Some(wgpu::FragmentState {
            module: &shader,
            entry_point: Some("fs"),
            compilation_options: Default::default(),
            targets: &[Some(wgpu::ColorTargetState {
                format: wgpu::TextureFormat::Rgba8UnormSrgb,
                blend: Some(wgpu::BlendState::REPLACE),
                write_mask: wgpu::ColorWrites::ALL,
            })],
        }),
        multiview_mask: None,
        cache: None,
    });
    let vertices = quad_vertices(-1.0, 1.0);
    let vertex_buffer = device.create_buffer(&wgpu::BufferDescriptor {
        label: Some("scene quad"),
        size: std::mem::size_of_val(&vertices) as u64,
        usage: wgpu::BufferUsages::VERTEX | wgpu::BufferUsages::COPY_DST,
        mapped_at_creation: false,
    });
    queue.write_buffer(&vertex_buffer, 0, bytemuck::cast_slice(&vertices));

    let readback = device.create_buffer(&wgpu::BufferDescriptor {
        label: Some("scene readback"),
        size: (padded_bytes_per_row * height) as u64,
        usage: wgpu::BufferUsages::COPY_DST | wgpu::BufferUsages::MAP_READ,
        mapped_at_creation: false,
    });
    let mut encoder = device.create_command_encoder(&wgpu::CommandEncoderDescriptor {
        label: Some("scene encoder"),
    });
    {
        let mut pass = encoder.begin_render_pass(&wgpu::RenderPassDescriptor {
            label: Some("scene pass"),
            color_attachments: &[Some(wgpu::RenderPassColorAttachment {
                view: &target_view,
                depth_slice: None,
                resolve_target: None,
                ops: wgpu::Operations {
                    load: wgpu::LoadOp::Clear(wgpu::Color::BLACK),
                    store: wgpu::StoreOp::Store,
                },
            })],
            depth_stencil_attachment: None,
            timestamp_writes: None,
            occlusion_query_set: None,
            multiview_mask: None,
        });
        pass.set_pipeline(&pipeline);
        pass.set_bind_group(0, &bind_group, &[]);
        pass.set_vertex_buffer(0, vertex_buffer.slice(..));
        pass.draw(0..6, 0..1);
    }
    encoder.copy_texture_to_buffer(
        wgpu::TexelCopyTextureInfo {
            texture: &target,
            mip_level: 0,
            origin: wgpu::Origin3d::ZERO,
            aspect: wgpu::TextureAspect::All,
        },
        wgpu::TexelCopyBufferInfo {
            buffer: &readback,
            layout: wgpu::TexelCopyBufferLayout {
                offset: 0,
                bytes_per_row: Some(padded_bytes_per_row),
                rows_per_image: Some(height),
            },
        },
        wgpu::Extent3d {
            width,
            height,
            depth_or_array_layers: 1,
        },
    );
    queue.submit(Some(encoder.finish()));
    let slice = readback.slice(..);
    let (sender, receiver) = std::sync::mpsc::channel();
    slice.map_async(wgpu::MapMode::Read, move |result| {
        let _ = sender.send(result);
    });
    device
        .poll(wgpu::PollType::wait_indefinitely())
        .map_err(|error| format!("poll failed: {error:?}"))?;
    receiver
        .recv()
        .map_err(|error| format!("map channel failed: {error}"))?
        .map_err(|error| format!("map failed: {error}"))?;
    let mapped = slice
        .get_mapped_range()
        .map_err(|error| format!("mapped range failed: {error:?}"))?;
    let mut pixels = vec![0u8; (width * height * 4) as usize];
    for y in 0..height {
        let source = (y * padded_bytes_per_row) as usize;
        let target = (y * width * 4) as usize;
        pixels[target..target + (width * 4) as usize]
            .copy_from_slice(&mapped[source..source + (width * 4) as usize]);
    }
    drop(mapped);
    let _ = slice;
    readback.unmap();

    Ok(RenderedFrame {
        adapter: info.name,
        backend: format!("{:?}", info.backend),
        width,
        height,
        pixels,
    })
}

#[cfg(test)]
mod render_tests {
    use super::*;

    #[test]
    fn vulkan_roundtrips_rgba_texture() {
        let width = 3;
        let height = 2;
        let pixels = vec![
            255, 0, 0, 255, 0, 255, 0, 255, 0, 0, 255, 255, 10, 20, 30, 255, 40, 50, 60, 255, 70,
            80, 90, 255,
        ];
        let frame = render_rgba(width, height, &pixels).expect("Vulkan render");
        assert_eq!(frame.backend, "Vulkan");
        assert_eq!(frame.pixels, pixels);
    }
}
