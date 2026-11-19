//! TGA decoder for the shipped UI and map backgrounds.
//!
//! Supports uncompressed and RLE colour-mapped images (types 1/9), true-colour
//! images (types 2/10, 16/24/32bpp) and 8-bit grayscale (type 3/11).

use crate::{AssetsError, Result};

#[derive(Clone, Debug)]
pub struct TgaImage {
    pub width: u32,
    pub height: u32,
    /// RGBA8, row-major, top-left origin.
    pub pixels: Vec<u8>,
}

impl TgaImage {
    pub fn load(data: &[u8]) -> Result<Self> {
        if data.len() < 18 {
            return Err(AssetsError::Truncated(
                std::path::PathBuf::from("<tga>"),
                "tga header",
            ));
        }
        let id_length = data[0] as usize;
        let cmap_type = data[1];
        let image_type = data[2];
        let cmap_length = u16::from_le_bytes([data[5], data[6]]) as usize;
        let cmap_depth = data[7] as usize;
        let width = u16::from_le_bytes([data[12], data[13]]) as u32;
        let height = u16::from_le_bytes([data[14], data[15]]) as u32;
        let bpp = data[16] as usize;
        let descriptor = data[17];
        if width == 0 || height == 0 {
            return Err(AssetsError::Bounds(
                std::path::PathBuf::from("<tga>"),
                "zero image size".into(),
            ));
        }
        let mut offset = 18 + id_length;
        if offset > data.len() {
            return Err(AssetsError::Truncated(
                std::path::PathBuf::from("<tga>"),
                "tga image id",
            ));
        }

        let mut palette = Vec::new();
        if cmap_type != 0 {
            let entry_bytes = cmap_depth / 8;
            if entry_bytes != 3 && entry_bytes != 4 {
                return Err(AssetsError::Bounds(
                    std::path::PathBuf::from("<tga>"),
                    format!("unsupported tga palette depth {cmap_depth}"),
                ));
            }
            let bytes = cmap_length * entry_bytes;
            if offset + bytes > data.len() {
                return Err(AssetsError::Truncated(
                    std::path::PathBuf::from("<tga>"),
                    "tga palette",
                ));
            }
            palette = data[offset..offset + bytes].to_vec();
            offset += bytes;
        }

        let top_origin = descriptor & 0x20 != 0;
        let pixel_bytes = (bpp + 7) / 8;
        if pixel_bytes == 0 {
            return Err(AssetsError::Bounds(
                std::path::PathBuf::from("<tga>"),
                format!("unsupported tga bpp {bpp}"),
            ));
        }
        let count = (width * height) as usize;
        let mut pixels = vec![0u8; count * 4];
        let mut source_index = 0usize;

        let store = |index: usize, rgba: [u8; 4], pixels: &mut Vec<u8>| {
            if index >= count {
                return;
            }
            let source_y = index as u32 / width;
            let y = if top_origin {
                source_y
            } else {
                height - 1 - source_y
            };
            let x = index as u32 % width;
            let target = ((y * width + x) * 4) as usize;
            pixels[target..target + 4].copy_from_slice(&rgba);
        };

        let palette_entry = |value: usize| -> [u8; 4] {
            let entry_bytes = cmap_depth / 8;
            let entry = value * entry_bytes;
            if entry + 3 > palette.len() {
                return [0, 0, 0, 0];
            }
            [
                palette[entry + 2],
                palette[entry + 1],
                palette[entry],
                if entry_bytes == 4 {
                    palette[entry + 3]
                } else {
                    255
                },
            ]
        };

        let read_color = |data: &[u8], position: usize| -> Option<([u8; 4], usize)> {
            let next = position + pixel_bytes;
            if next > data.len() {
                return None;
            }
            let value = match pixel_bytes {
                1 => [data[position], 0, 0, 255],
                2 => {
                    let word = u16::from_le_bytes([data[position], data[position + 1]]);
                    [
                        (((word >> 10) & 31) * 255 / 31) as u8,
                        (((word >> 5) & 31) * 255 / 31) as u8,
                        ((word & 31) * 255 / 31) as u8,
                        255,
                    ]
                }
                3 => [data[position + 2], data[position + 1], data[position], 255],
                4 => [
                    data[position + 2],
                    data[position + 1],
                    data[position],
                    data[position + 3],
                ],
                _ => return None,
            };
            Some((value, next))
        };

        let rle = matches!(image_type, 9 | 10 | 11);
        let mapped = matches!(image_type, 1 | 9);
        let grayscale = matches!(image_type, 3 | 11);
        if !mapped && !grayscale && image_type != 2 && image_type != 10 {
            return Err(AssetsError::Bounds(
                std::path::PathBuf::from("<tga>"),
                format!("unsupported tga image type {image_type}"),
            ));
        }
        if mapped && (bpp != 8 || palette.is_empty()) {
            return Err(AssetsError::Bounds(
                std::path::PathBuf::from("<tga>"),
                "colour-mapped tga must use 8bpp indices".into(),
            ));
        }

        if rle {
            while source_index < count {
                if offset >= data.len() {
                    return Err(AssetsError::Truncated(
                        std::path::PathBuf::from("<tga>"),
                        "tga rle packet",
                    ));
                }
                let header = data[offset];
                offset += 1;
                let run = (header & 0x7f) as usize + 1;
                if header & 0x80 != 0 {
                    let Some((color, next)) = read_color(data, offset) else {
                        return Err(AssetsError::Truncated(
                            std::path::PathBuf::from("<tga>"),
                            "tga rle color",
                        ));
                    };
                    offset = next;
                    let rgba = if mapped || grayscale {
                        palette_entry(color[0] as usize)
                    } else {
                        color
                    };
                    for _ in 0..run {
                        store(source_index, rgba, &mut pixels);
                        source_index += 1;
                    }
                } else {
                    for _ in 0..run {
                        let Some((color, next)) = read_color(data, offset) else {
                            return Err(AssetsError::Truncated(
                                std::path::PathBuf::from("<tga>"),
                                "tga rle raw color",
                            ));
                        };
                        offset = next;
                        let rgba = if mapped || grayscale {
                            palette_entry(color[0] as usize)
                        } else {
                            color
                        };
                        store(source_index, rgba, &mut pixels);
                        source_index += 1;
                    }
                }
            }
        } else {
            for _ in 0..count {
                let Some((color, next)) = read_color(data, offset) else {
                    return Err(AssetsError::Truncated(
                        std::path::PathBuf::from("<tga>"),
                        "tga pixels",
                    ));
                };
                offset = next;
                let rgba = if mapped || grayscale {
                    palette_entry(color[0] as usize)
                } else {
                    color
                };
                store(source_index, rgba, &mut pixels);
                source_index += 1;
            }
        }

        Ok(Self {
            width,
            height,
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

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn colour_mapped_bottom_up() {
        let mut data = vec![0u8; 18];
        data[1] = 1;
        data[2] = 1;
        data[5..7].copy_from_slice(&2u16.to_le_bytes());
        data[7] = 24;
        data[12..14].copy_from_slice(&2u16.to_le_bytes());
        data[14..16].copy_from_slice(&2u16.to_le_bytes());
        data[16] = 8;
        data.extend_from_slice(&[0, 0, 255, 0, 255, 0]);
        data.extend_from_slice(&[0, 1, 1, 0]);
        let image = TgaImage::load(&data).unwrap();
        assert_eq!(image.pixel(0, 0), [0, 255, 0, 255]);
        assert_eq!(image.pixel(1, 0), [255, 0, 0, 255]);
        assert_eq!(image.pixel(0, 1), [255, 0, 0, 255]);
        assert_eq!(image.pixel(1, 1), [0, 255, 0, 255]);
    }

    #[test]
    fn rle_truecolour() {
        let mut data = vec![0u8; 18];
        data[2] = 10;
        data[12..14].copy_from_slice(&2u16.to_le_bytes());
        data[14..16].copy_from_slice(&1u16.to_le_bytes());
        data[16] = 24;
        data[17] = 0x20;
        // Two raw red pixels then one RLE green pixel.
        data.extend_from_slice(&[1, 0, 0, 255, 0, 0, 255]);
        data.extend_from_slice(&[0x80, 0, 255, 0]);
        let image = TgaImage::load(&data).unwrap();
        assert_eq!(image.pixel(0, 0), [255, 0, 0, 255]);
        assert_eq!(image.pixel(1, 0), [255, 0, 0, 255]);
    }
}
