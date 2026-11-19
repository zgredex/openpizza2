//! Decoder for the shipped `.ani` animation frames.
//!
//! Layout recovered from `Anim_Load` (`0x532c40`):
//!
//! ```text
//! 0x00 u32 record_count       (0x98-byte render-template records follow)
//! 0x04 u32 frame_count
//! 0x08 u32 hotspot_x
//! 0x0c u32 magic 0xca42xxxx
//! 0x14 u8  flags
//! 0x15 u8  bpp
//! 0x16 u16 stride
//! 0x18 u16 height
//! ...                             0x1c-byte sprite header block
//! 0x30 record[record_count]       0x98 bytes each
//!      u32 data_size
//!      data[data_size]:
//!          u16 widths[frame_count]
//!          u16 heights[frame_count]
//!          u16 hotspot_x[frame_count]
//!          u16 hotspot_y[frame_count]
//!          u32 frame_sizes[frame_count]  (u16 when magic low < 2)
//!          frame pixel streams
//!          BGR palette[0x300]
//! ```
//!
//! The tree sway files (`b_allee_*`) use opaque 8bpp run streams, the same
//! `0xff <run>` token format as city sprites.

use std::sync::Arc;

use crate::spr::decode_8bit_rle;
use crate::{AssetsError, Result};

#[derive(Clone, Debug)]
pub struct AniFrame {
    pub width: u32,
    pub height: u32,
    pub pixels: Arc<Vec<u8>>,
}

#[derive(Clone, Debug)]
pub struct Ani {
    pub frame_count: usize,
    pub frames: Vec<AniFrame>,
}

impl Ani {
    pub fn load(data: &[u8]) -> Result<Self> {
        if data.len() < 0x30 {
            return Err(AssetsError::Truncated(
                std::path::PathBuf::from("<ani>"),
                "ani header",
            ));
        }
        let record_count = u32::from_le_bytes(data[0..4].try_into().unwrap()) as usize;
        let frame_count = u32::from_le_bytes(data[4..8].try_into().unwrap()) as usize;
        let magic = u32::from_le_bytes(data[0x0c..0x10].try_into().unwrap());
        let valid_magic = magic & 0xffff_0000 == 0xca42_0000;
        if frame_count == 0 || frame_count > 10_000 {
            return Err(AssetsError::Bounds(
                std::path::PathBuf::from("<ani>"),
                format!("invalid frame count {frame_count}"),
            ));
        }
        let flags = data[0x14];
        let bpp = data[0x15];
        if bpp != 8 && bpp != 16 {
            return Err(AssetsError::Bounds(
                std::path::PathBuf::from("<ani>"),
                format!("unsupported ani bpp={bpp}"),
            ));
        }
        let color_key = u32::from_le_bytes(data[0x2c..0x30].try_into().unwrap()) as u16;
        let data_offset = 0x30usize
            .checked_add(record_count.checked_mul(0x98).ok_or_else(|| {
                AssetsError::Bounds(std::path::PathBuf::from("<ani>"), "record overflow".into())
            })?)
            .ok_or_else(|| {
                AssetsError::Bounds(std::path::PathBuf::from("<ani>"), "header overflow".into())
            })?;
        if data_offset + 4 > data.len() {
            return Err(AssetsError::Truncated(
                std::path::PathBuf::from("<ani>"),
                "ani data size",
            ));
        }
        // The stored size includes its own four-byte field.
        let stored_size =
            u32::from_le_bytes(data[data_offset..data_offset + 4].try_into().unwrap()) as usize;
        let block_size = stored_size.saturating_sub(4);
        let block_start = data_offset + 4;
        if block_start + block_size > data.len() || block_size < 0x300 {
            return Err(AssetsError::Truncated(
                std::path::PathBuf::from("<ani>"),
                "ani frame block",
            ));
        }
        let block = &data[block_start..block_start + block_size];
        let table_bytes = 8 * frame_count;
        let size_bytes = if !valid_magic || (magic & 0xffff) < 2 {
            2
        } else {
            4
        };
        if table_bytes + size_bytes * frame_count + 0x300 > block.len() {
            return Err(AssetsError::Truncated(
                std::path::PathBuf::from("<ani>"),
                "ani frame table",
            ));
        }
        let read_u16 = |offset: usize| {
            u16::from_le_bytes(block[offset..offset + 2].try_into().unwrap()) as u32
        };
        let widths = (0..frame_count)
            .map(|index| read_u16(index * 2))
            .collect::<Vec<_>>();
        let heights = (0..frame_count)
            .map(|index| read_u16(2 * frame_count + index * 2))
            .collect::<Vec<_>>();
        let mut cursor = table_bytes;
        let sizes = (0..frame_count)
            .map(|_index| {
                if size_bytes == 4 {
                    let value =
                        u32::from_le_bytes(block[cursor..cursor + 4].try_into().unwrap()) as usize;
                    cursor += 4;
                    value
                } else {
                    let value = read_u16(cursor) as usize;
                    cursor += 2;
                    value
                }
            })
            .collect::<Vec<_>>();
        let palette_bytes = if bpp == 8 { 0x300 } else { 0 };
        if block.len() < palette_bytes {
            return Err(AssetsError::Truncated(
                std::path::PathBuf::from("<ani>"),
                "ani palette",
            ));
        }
        let palette = &block[block.len() - palette_bytes..];
        let mut offset = table_bytes + size_bytes * frame_count;
        let mut frames = Vec::with_capacity(frame_count);
        for index in 0..frame_count {
            let width = widths[index];
            let height = heights[index];
            let size = sizes[index];
            if width == 0 || height == 0 {
                frames.push(AniFrame {
                    width: 0,
                    height: 0,
                    pixels: Arc::new(Vec::new()),
                });
                continue;
            }
            if offset + size > block.len() - palette_bytes {
                return Err(AssetsError::Truncated(
                    std::path::PathBuf::from("<ani>"),
                    "ani frame stream",
                ));
            }
            let body = &block[offset..offset + size];
            let pixels = if !valid_magic && size == (width * height) as usize {
                // `numbd.ani`/`numbh.ani` use the invalid-magic fallback and
                // store one-byte coverage masks rather than 16-bit pixels.
                decode_mask8(body, width, height)
            } else if bpp == 8 && flags & 0x10 == 0 {
                decode_8bit_rle(body, palette, width, height, color_key as u8)
            } else if bpp == 8 {
                decode_8bit_alpha(body, palette, width, height)
            } else if flags & 0x10 == 0 {
                decode_16bit_raw(body, width, height, color_key)
            } else {
                decode_16bit_alpha(body, width, height)
            };
            frames.push(AniFrame {
                width,
                height,
                pixels: Arc::new(pixels),
            });
            offset += size;
        }
        Ok(Self {
            frame_count,
            frames,
        })
    }
}

fn decode_mask8(body: &[u8], width: u32, height: u32) -> Vec<u8> {
    let mut pixels = vec![0u8; (width * height * 4) as usize];
    for index in 0..(width * height) as usize {
        let value = body.get(index).copied().unwrap_or(0);
        let target = index * 4;
        pixels[target] = value;
        pixels[target + 1] = value;
        pixels[target + 2] = value;
        pixels[target + 3] = if value == 0 { 0 } else { 255 };
    }
    pixels
}

fn decode_8bit_alpha(body: &[u8], palette: &[u8], width: u32, height: u32) -> Vec<u8> {
    let mut pixels = vec![0u8; (width * height * 4) as usize];
    let mut x = 0u32;
    let mut y = 0u32;
    let mut i = 0usize;
    while i + 2 <= body.len() && y < height {
        let alpha = body[i];
        let index = body[i + 1];
        i += 2;
        if alpha == 0 {
            x += index as u32;
        } else {
            if x < width {
                let base = index as usize * 3;
                let target = ((y * width + x) * 4) as usize;
                pixels[target] = palette[base + 2];
                pixels[target + 1] = palette[base + 1];
                pixels[target + 2] = palette[base];
                pixels[target + 3] = if alpha >= 0x3c {
                    255
                } else {
                    (alpha as u32 * 255 / 0x3c) as u8
                };
            }
            x += 1;
        }
        while x >= width {
            x -= width;
            y += 1;
        }
    }
    pixels
}

fn decode_16bit_raw(body: &[u8], width: u32, height: u32, key: u16) -> Vec<u8> {
    let mut pixels = vec![0u8; (width * height * 4) as usize];
    for index in 0..(width * height) as usize {
        let offset = index * 2;
        if offset + 2 > body.len() {
            break;
        }
        let value = u16::from_le_bytes([body[offset], body[offset + 1]]);
        if value == key {
            continue;
        }
        let target = index * 4;
        pixels[target] = (((value >> 10) & 31) * 255 / 31) as u8;
        pixels[target + 1] = (((value >> 5) & 31) * 255 / 31) as u8;
        pixels[target + 2] = ((value & 31) * 255 / 31) as u8;
        pixels[target + 3] = 255;
    }
    pixels
}

fn decode_16bit_alpha(body: &[u8], width: u32, height: u32) -> Vec<u8> {
    let mut pixels = vec![0u8; (width * height * 4) as usize];
    let mut x = 0u32;
    let mut y = 0u32;
    let mut i = 0usize;
    while i + 4 <= body.len() && y < height {
        let alpha = u16::from_le_bytes([body[i], body[i + 1]]);
        let value = u16::from_le_bytes([body[i + 2], body[i + 3]]);
        i += 4;
        if alpha == 0 {
            x += value as u32;
        } else {
            if x < width {
                let target = ((y * width + x) * 4) as usize;
                pixels[target] = (((value >> 10) & 31) * 255 / 31) as u8;
                pixels[target + 1] = (((value >> 5) & 31) * 255 / 31) as u8;
                pixels[target + 2] = ((value & 31) * 255 / 31) as u8;
                let a = (alpha >> 8) as u8;
                pixels[target + 3] = if a >= 0x3c {
                    255
                } else {
                    (a as u32 * 255 / 0x3c) as u8
                };
            }
            x += 1;
        }
        while x >= width {
            x -= width;
            y += 1;
        }
    }
    pixels
}

#[cfg(test)]
mod tests {
    use super::*;

    fn fnv1a(bytes: &[u8]) -> u64 {
        let mut hash = 0xcbf29ce484222325u64;
        for byte in bytes {
            hash ^= *byte as u64;
            hash = hash.wrapping_mul(0x100000001b3);
        }
        hash
    }

    #[test]
    fn tree_sway_frames_decode() {
        let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("extracted")
            .join("isodaten")
            .join("anims")
            .join("b_allee_a-b_allee_a.ani");
        if !path.is_file() {
            return;
        }
        let ani = Ani::load(&std::fs::read(path).unwrap()).unwrap();
        assert_eq!(ani.frame_count, 12);
        assert_eq!((ani.frames[0].width, ani.frames[0].height), (44, 72));
        assert_eq!(fnv1a(&ani.frames[0].pixels), 0x6cd5_e532_6904_55f0);
        assert_eq!(fnv1a(&ani.frames[1].pixels), 0xaa33_f95e_8fc7_18b5);
    }
}
