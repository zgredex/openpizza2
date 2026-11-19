//! Decoder for the two shipped 8-bit PCX pictures.

use crate::{AssetsError, Result};

#[derive(Clone, Debug)]
pub struct PcxImage {
    pub width: u32,
    pub height: u32,
    pub pixels: Vec<u8>,
}

impl PcxImage {
    pub fn load(data: &[u8]) -> Result<Self> {
        if data.len() < 128 || data[0] != 0x0a || data[2] != 1 {
            return Err(AssetsError::Bounds(
                std::path::PathBuf::from("<pcx>"),
                "not an RLE PCX".into(),
            ));
        }
        let bpp = data[3];
        let xmin = u16::from_le_bytes([data[4], data[5]]) as u32;
        let ymin = u16::from_le_bytes([data[6], data[7]]) as u32;
        let xmax = u16::from_le_bytes([data[8], data[9]]) as u32;
        let ymax = u16::from_le_bytes([data[10], data[11]]) as u32;
        let planes = data[65] as u32;
        let bytes_per_line = u16::from_le_bytes([data[66], data[67]]) as usize;
        if bpp != 8 || planes != 1 || xmax < xmin || ymax < ymin || bytes_per_line == 0 {
            return Err(AssetsError::Bounds(
                std::path::PathBuf::from("<pcx>"),
                format!("unsupported PCX bpp={bpp} planes={planes}"),
            ));
        }
        let width = xmax - xmin + 1;
        let height = ymax - ymin + 1;
        if data.len() < 128 + 769 || data[data.len() - 769] != 0x0c {
            return Err(AssetsError::Truncated(
                std::path::PathBuf::from("<pcx>"),
                "PCX palette",
            ));
        }
        let palette = &data[data.len() - 768..];
        let mut indices = vec![0u8; bytes_per_line * height as usize];
        let mut source = 128usize;
        let mut target = 0usize;
        while target < indices.len() {
            if source >= data.len() - 769 {
                return Err(AssetsError::Truncated(
                    std::path::PathBuf::from("<pcx>"),
                    "PCX scanline data",
                ));
            }
            let value = data[source];
            source += 1;
            if value & 0xc0 == 0xc0 {
                let run = (value & 0x3f) as usize;
                if source >= data.len() - 769 {
                    return Err(AssetsError::Truncated(
                        std::path::PathBuf::from("<pcx>"),
                        "PCX run value",
                    ));
                }
                let color = data[source];
                source += 1;
                for _ in 0..run {
                    if target < indices.len() {
                        indices[target] = color;
                        target += 1;
                    }
                }
            } else {
                indices[target] = value;
                target += 1;
            }
        }
        let mut pixels = vec![0u8; (width * height * 4) as usize];
        for y in 0..height as usize {
            for x in 0..width as usize {
                let value = indices[y * bytes_per_line + x] as usize;
                let target = (y * width as usize + x) * 4;
                pixels[target] = palette[value * 3];
                pixels[target + 1] = palette[value * 3 + 1];
                pixels[target + 2] = palette[value * 3 + 2];
                pixels[target + 3] = 255;
            }
        }
        Ok(Self {
            width,
            height,
            pixels,
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn rle_pcx_roundtrip() {
        let mut data = vec![0u8; 128];
        data[0] = 0x0a;
        data[2] = 1;
        data[3] = 8;
        data[8..10].copy_from_slice(&1u16.to_le_bytes());
        data[10..12].copy_from_slice(&0u16.to_le_bytes());
        data[65] = 1;
        data[66..68].copy_from_slice(&2u16.to_le_bytes());
        data.extend_from_slice(&[0xc1, 1, 4]);
        data.push(0x0c);
        let mut palette = vec![0u8; 768];
        palette[3..6].copy_from_slice(&[255, 0, 0]);
        palette[12..15].copy_from_slice(&[0, 255, 0]);
        data.extend_from_slice(&palette);
        let image = PcxImage::load(&data).unwrap();
        assert_eq!((image.width, image.height), (2, 1));
        assert_eq!(&image.pixels[0..4], &[255, 0, 0, 255]);
        assert_eq!(&image.pixels[4..8], &[0, 255, 0, 255]);
    }
}
