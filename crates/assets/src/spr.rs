//! Decoder for the shipped `.spr` sprites.
//!
//! The pixel stream comes first and, for 8bpp sprites, the 0x300-byte BGR
//! palette follows it. `Sprite_Load` (`0x53c7f0`) reads the palette at
//! `data_offset + pixel_stream_size`; the earlier Python exporter had the two
//! blocks reversed, which produced correct silhouettes but noisy colours.
//!
//! Formats seen in the shipped corpus:
//!
//! * `flags & 0x10`: two-byte (8bpp) or four-byte (16bpp) alpha/RLE tokens.
//! * other 8bpp sprites: one byte per pixel with `0xff <run>` transparent runs.
//! * other 16bpp sprites: raw little-endian RGB555 with a colour key.

use crate::{AssetsError, Result};

#[derive(Clone, Debug)]
pub struct Sprite {
    pub width: u32,
    pub height: u32,
    pub canvas_width: u32,
    pub canvas_height: u32,
    pub hotspot_x: i16,
    pub hotspot_y: i16,
    pub bpp: u8,
    pub flags: u8,
    /// RGBA8, row-major, top-left origin.
    pub pixels: Vec<u8>,
}

impl Sprite {
    pub fn load(data: &[u8]) -> Result<Self> {
        if data.len() < 0x21 {
            return Err(AssetsError::Truncated(
                std::path::PathBuf::from("<spr>"),
                "spr header",
            ));
        }
        let bpp = data[6];
        let flags = data[5];
        let stride = u16::from_le_bytes(data[7..9].try_into().unwrap()) as u32;
        let height = u16::from_le_bytes(data[9..0x0b].try_into().unwrap()) as u32;
        let hotspot_x = i16::from_le_bytes(data[0x0b..0x0d].try_into().unwrap());
        let hotspot_y = i16::from_le_bytes(data[0x0d..0x0f].try_into().unwrap());
        let canvas_width = u16::from_le_bytes(data[0x13..0x15].try_into().unwrap()) as u32;
        let canvas_height = u16::from_le_bytes(data[0x15..0x17].try_into().unwrap()) as u32;
        let data_size = u32::from_le_bytes(data[0x19..0x1d].try_into().unwrap()) as usize;
        let color_key = u32::from_le_bytes(data[0x1d..0x21].try_into().unwrap()) as u16;
        if bpp != 8 && bpp != 16 {
            return Err(AssetsError::Bounds(
                std::path::PathBuf::from("<spr>"),
                format!("unsupported bpp {bpp}"),
            ));
        }
        let width = stride / (bpp as u32 / 8);
        if width == 0 || height == 0 {
            // `isodaten/sprites/blinki.spr` is a deliberately blank 0x0
            // sprite with a 64x64 canvas. Treat it as empty rather than as a
            // corrupt asset so a map layer can resolve to an invisible sprite.
            return Ok(Self {
                width: 0,
                height: 0,
                canvas_width,
                canvas_height,
                hotspot_x,
                hotspot_y,
                bpp,
                flags,
                pixels: Vec::new(),
            });
        }
        let payload = &data[0x21..];
        if payload.len() < data_size {
            return Err(AssetsError::Truncated(
                std::path::PathBuf::from("<spr>"),
                "spr pixel stream",
            ));
        }
        let body = &payload[..data_size];
        let palette = if bpp == 8 {
            if payload.len() < data_size + 0x300 {
                return Err(AssetsError::Truncated(
                    std::path::PathBuf::from("<spr>"),
                    "spr palette",
                ));
            }
            Some(&payload[data_size..data_size + 0x300])
        } else {
            None
        };

        let mut pixels = vec![0u8; (width * height * 4) as usize];
        let mut put = |x: u32, y: u32, rgba: [u8; 4]| {
            if x < width && y < height {
                let offset = ((y * width + x) * 4) as usize;
                pixels[offset..offset + 4].copy_from_slice(&rgba);
            }
        };

        if bpp == 8 {
            let palette = palette.unwrap();
            let color = |index: u8| {
                let base = index as usize * 3;
                [palette[base + 2], palette[base + 1], palette[base], 255]
            };
            if flags & 0x10 != 0 {
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
                        let mut rgba = color(index);
                        rgba[3] = alpha8(alpha);
                        put(x, y, rgba);
                        x += 1;
                    }
                    while x >= width {
                        x -= width;
                        y += 1;
                    }
                }
            } else if body.len() >= (width * height) as usize {
                pixels = decode_8bit_raw(body, palette, width, height, color_key as u8);
            } else {
                pixels = decode_8bit_rle(body, palette, width, height, color_key as u8);
            }
        } else {
            let key = color_key;
            if flags & 0x10 != 0 {
                let mut x = 0u32;
                let mut y = 0u32;
                let mut i = 0usize;
                while i + 4 <= body.len() && y < height {
                    let alpha_word = u16::from_le_bytes(body[i..i + 2].try_into().unwrap());
                    let value = u16::from_le_bytes(body[i + 2..i + 4].try_into().unwrap());
                    i += 4;
                    if alpha_word == 0 {
                        x += value as u32;
                    } else {
                        let mut rgba = rgb555(value);
                        rgba[3] = alpha8((alpha_word >> 8) as u8);
                        put(x, y, rgba);
                        x += 1;
                    }
                    while x >= width {
                        x -= width;
                        y += 1;
                    }
                }
            } else {
                let mut x = 0u32;
                let mut y = 0u32;
                for pair in body.chunks_exact(2) {
                    let value = u16::from_le_bytes([pair[0], pair[1]]);
                    if value != key {
                        put(x, y, rgb555(value));
                    }
                    x += 1;
                    if x >= width {
                        x = 0;
                        y += 1;
                    }
                }
            }
        }

        Ok(Self {
            width,
            height,
            canvas_width: canvas_width.max(width),
            canvas_height: canvas_height.max(height),
            hotspot_x,
            hotspot_y,
            bpp,
            flags,
            pixels,
        })
    }

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

fn decode_8bit_raw(
    body: &[u8],
    palette: &[u8],
    width: u32,
    height: u32,
    transparent: u8,
) -> Vec<u8> {
    let mut pixels = vec![0u8; (width * height * 4) as usize];
    for index in 0..(width * height) as usize {
        let value = body[index];
        if value == transparent {
            continue;
        }
        let base = value as usize * 3;
        let offset = index * 4;
        pixels[offset] = palette[base + 2];
        pixels[offset + 1] = palette[base + 1];
        pixels[offset + 2] = palette[base];
        pixels[offset + 3] = 255;
    }
    pixels
}

/// Decode the opaque 8bpp run stream used by city sprites and `.ani`
/// frames: each byte is a palette index, while `0xff <run>` advances by
/// `run` transparent pixels.
pub(crate) fn decode_8bit_rle(
    body: &[u8],
    palette: &[u8],
    width: u32,
    height: u32,
    escape: u8,
) -> Vec<u8> {
    let mut pixels = vec![0u8; (width * height * 4) as usize];
    let mut x = 0u32;
    let mut y = 0u32;
    let mut i = 0usize;
    while i < body.len() && y < height {
        let byte = body[i];
        i += 1;
        if byte == escape && i < body.len() {
            x += body[i] as u32;
            i += 1;
        } else {
            if x < width {
                let base = byte as usize * 3;
                let offset = ((y * width + x) * 4) as usize;
                pixels[offset] = palette[base + 2];
                pixels[offset + 1] = palette[base + 1];
                pixels[offset + 2] = palette[base];
                pixels[offset + 3] = 255;
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

fn alpha8(alpha: u8) -> u8 {
    if alpha >= 0x3c {
        255
    } else {
        (alpha as u32 * 255 / 0x3c) as u8
    }
}

fn rgb555(color: u16) -> [u8; 4] {
    [
        (((color >> 10) & 31) * 255 / 31) as u8,
        (((color >> 5) & 31) * 255 / 31) as u8,
        ((color & 31) * 255 / 31) as u8,
        255,
    ]
}

#[cfg(test)]
mod tests {
    use super::*;

    fn build_sprite(
        width: u16,
        height: u16,
        flags: u8,
        bpp: u8,
        body: &[u8],
        palette: Option<&[u8]>,
    ) -> Vec<u8> {
        let mut data = vec![0u8; 0x21];
        data[4] = 8;
        data[5] = flags;
        data[6] = bpp;
        data[7..9].copy_from_slice(&(width * (bpp as u16 / 8)).to_le_bytes());
        data[9..0x0b].copy_from_slice(&height.to_le_bytes());
        data[0x13..0x15].copy_from_slice(&width.to_le_bytes());
        data[0x15..0x17].copy_from_slice(&height.to_le_bytes());
        data[0x19..0x1d].copy_from_slice(&(body.len() as u32).to_le_bytes());
        data[0x1d..0x21].copy_from_slice(&255u32.to_le_bytes());
        data.extend_from_slice(body);
        if let Some(palette) = palette {
            data.extend_from_slice(palette);
        }
        data
    }

    #[test]
    fn palette_follows_pixel_stream() {
        let mut palette = vec![0u8; 0x300];
        palette[0..3].copy_from_slice(&[10, 20, 30]);
        let body = [0u8, 1u8, 0xff, 1u8];
        let data = build_sprite(2, 3, 0x07, 8, &body, Some(&palette));
        let sprite = Sprite::load(&data).unwrap();
        assert_eq!((sprite.width, sprite.height), (2, 3));
        assert_eq!(sprite.pixel(0, 0), [30, 20, 10, 255]);
        assert_eq!(sprite.pixel(1, 0), [0, 0, 0, 255]);
        assert_eq!(sprite.pixel(0, 1), [0, 0, 0, 0]);
        assert_eq!(sprite.pixel(1, 1), [0, 0, 0, 0]);
    }

    #[test]
    fn alpha_tokens_are_blended() {
        let mut palette = vec![0u8; 0x300];
        palette[3..6].copy_from_slice(&[1, 2, 3]);
        let body = [0x3c, 1, 0, 0];
        let data = build_sprite(1, 1, 0x17, 8, &body, Some(&palette));
        let sprite = Sprite::load(&data).unwrap();
        assert_eq!(sprite.pixel(0, 0), [3, 2, 1, 255]);
    }
}
