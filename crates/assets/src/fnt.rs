//! Decoder for the shipped `.fnt` bitmap fonts.
//!
//! `Font_Load (0x535180)` reads five 0xE0-byte per-character tables, 224
//! little-endian glyph byte counts, a 4-byte line-height/max-width word, and
//! then the concatenated RLE glyph streams. Character indices start at `0x20`
//! (space), so each table covers `' '` through `0xFF`.
//!
//! Each glyph stream stores `height` rows. A row consumes `width / 2` pixels:
//! a zero byte is followed by a skip count, `0x0F` is a solid pixel, and the
//! remaining values are antialias coverage levels. The stored width is twice
//! the raster width because the original renderer draws two horizontal pixels
//! per source sample.

use std::path::PathBuf;

use crate::{AssetsError, Result};

const GLYPH_COUNT: usize = 224;
const WIDTHS_OFFSET: usize = 0x000;
const HEIGHTS_OFFSET: usize = 0x0e0;
const X_OFFSETS_OFFSET: usize = 0x1c0;
const Y_OFFSETS_OFFSET: usize = 0x2a0;
const LENGTHS_OFFSET: usize = 0x380;
const ADVANCES_OFFSET: usize = 0x540;
const METRICS_OFFSET: usize = 0x620;
const BITMAP_OFFSET: usize = 0x624;

#[derive(Clone, Debug, PartialEq)]
pub struct Glyph {
    /// Raster width after the original x2 scaling.
    pub width: u16,
    pub height: u16,
    pub x_offset: u8,
    pub y_offset: u8,
    /// Row-major 8-bit coverage values, `width * height`.
    pub coverage: Vec<u8>,
}

#[derive(Clone, Debug)]
pub struct Fnt {
    glyphs: Vec<Option<Glyph>>,
    advances: [u8; GLYPH_COUNT],
    /// Baseline-to-baseline distance used by the UI text controls.
    pub line_height: u16,
    /// Largest glyph width recorded by the font file.
    pub max_width: u16,
}

impl Fnt {
    pub fn load(data: &[u8]) -> Result<Self> {
        if data.len() < BITMAP_OFFSET {
            return Err(AssetsError::Truncated(
                PathBuf::from("<fnt>"),
                "font header",
            ));
        }
        let mut lengths = [0usize; GLYPH_COUNT];
        let mut total = 0usize;
        for (index, length) in lengths.iter_mut().enumerate() {
            let offset = LENGTHS_OFFSET + index * 2;
            *length = u16::from_le_bytes([data[offset], data[offset + 1]]) as usize;
            total += *length;
        }
        if total > data.len() - BITMAP_OFFSET {
            return Err(AssetsError::Truncated(
                PathBuf::from("<fnt>"),
                "font glyph streams",
            ));
        }

        let mut advances = [0u8; GLYPH_COUNT];
        advances.copy_from_slice(&data[ADVANCES_OFFSET..ADVANCES_OFFSET + GLYPH_COUNT]);
        let metrics =
            u32::from_le_bytes(data[METRICS_OFFSET..METRICS_OFFSET + 4].try_into().unwrap());
        let line_height = metrics as u16;
        let max_width = (metrics >> 16) as u16;

        let mut glyphs = Vec::with_capacity(GLYPH_COUNT);
        let mut stream = BITMAP_OFFSET;
        for index in 0..GLYPH_COUNT {
            let width = data[WIDTHS_OFFSET + index] as u16 / 2;
            let height = data[HEIGHTS_OFFSET + index] as u16;
            let x_offset = data[X_OFFSETS_OFFSET + index];
            let y_offset = data[Y_OFFSETS_OFFSET + index];
            let length = lengths[index];
            let end = stream + length;
            if width == 0 || height == 0 || length == 0 {
                glyphs.push(None);
                stream = end;
                continue;
            }
            let mut coverage = Vec::with_capacity((width * height) as usize);
            let mut position = stream;
            for row in 0..height {
                let mut written = 0u16;
                while written < width {
                    if position >= end {
                        return Err(AssetsError::Truncated(PathBuf::from("<fnt>"), "glyph row"));
                    }
                    let token = data[position];
                    position += 1;
                    if token == 0 {
                        if position >= end {
                            return Err(AssetsError::Truncated(
                                PathBuf::from("<fnt>"),
                                "glyph skip",
                            ));
                        }
                        let skip = data[position] as u16;
                        position += 1;
                        let skip = skip.min(width - written);
                        coverage.resize(coverage.len() + skip as usize, 0);
                        written += skip;
                    } else {
                        let alpha = if token >= 15 { 255 } else { token * 17 };
                        coverage.push(alpha);
                        written += 1;
                    }
                }
                if written != width {
                    return Err(AssetsError::Bounds(
                        PathBuf::from("<fnt>"),
                        format!("glyph {index} row {row} overruns its width"),
                    ));
                }
            }
            if position != end {
                return Err(AssetsError::Bounds(
                    PathBuf::from("<fnt>"),
                    format!("glyph {index} leaves trailing bytes"),
                ));
            }
            glyphs.push(Some(Glyph {
                width,
                height,
                x_offset,
                y_offset,
                coverage,
            }));
            stream = end;
        }

        Ok(Self {
            glyphs,
            advances,
            line_height,
            max_width,
        })
    }

    pub fn glyph(&self, ch: char) -> Option<&Glyph> {
        let code = ch as u32;
        if !(0x20..0x100).contains(&code) {
            return None;
        }
        self.glyphs[(code - 0x20) as usize].as_ref()
    }

    pub fn advance(&self, ch: char) -> u32 {
        let code = ch as u32;
        if (0x20..0x100).contains(&code) {
            self.advances[(code - 0x20) as usize] as u32
        } else {
            0
        }
    }

    pub fn measure(&self, text: &str) -> u32 {
        text.chars().map(|ch| self.advance(ch)).sum()
    }

    #[allow(clippy::too_many_arguments)]
    pub fn draw_text(
        &self,
        target: &mut [u8],
        target_width: u32,
        target_height: u32,
        x: i32,
        y: i32,
        text: &str,
        color: [u8; 3],
    ) -> Result<()> {
        if target.len() != (target_width * target_height * 4) as usize {
            return Err(AssetsError::Bounds(
                PathBuf::from("<fnt>"),
                "text target has the wrong size".into(),
            ));
        }
        let mut pen_x = x;
        for ch in text.chars() {
            if let Some(glyph) = self.glyph(ch) {
                for row in 0..glyph.height as i32 {
                    for column in 0..glyph.width as i32 {
                        let coverage = glyph.coverage[(row * glyph.width as i32 + column) as usize];
                        if coverage == 0 {
                            continue;
                        }
                        let px = pen_x + glyph.x_offset as i32 + column;
                        let py = y + glyph.y_offset as i32 + row;
                        if px < 0
                            || py < 0
                            || px >= target_width as i32
                            || py >= target_height as i32
                        {
                            continue;
                        }
                        let offset = ((py as u32 * target_width + px as u32) * 4) as usize;
                        let alpha = coverage as u32;
                        for channel in 0..3 {
                            let value = color[channel] as u32;
                            let old = target[offset + channel] as u32;
                            target[offset + channel] =
                                ((value * alpha + old * (255 - alpha) + 127) / 255) as u8;
                        }
                        target[offset + 3] = 255;
                    }
                }
            }
            pen_x += self.advance(ch) as i32;
        }
        Ok(())
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::path::Path;

    fn shipped_font() -> Option<Vec<u8>> {
        let path = Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("extracted")
            .join("fonts")
            .join("timesfont.fnt");
        std::fs::read(path).ok()
    }

    #[test]
    fn shipped_times_font_decodes() {
        let Some(data) = shipped_font() else {
            return;
        };
        let font = Fnt::load(&data).unwrap();
        assert_eq!(font.line_height, 23);
        assert_eq!(font.max_width, 18);
        let a = font.glyph('A').expect("A glyph");
        assert_eq!(a.width, 16);
        assert_eq!(a.height, 14);
        assert_eq!(a.x_offset, 0);
        assert_eq!(a.y_offset, 4);
        assert!(a.coverage.iter().any(|value| *value != 0));
        assert_eq!(font.advance('A'), 16);
        assert!(font.measure("Start new game") > 100);
    }

    #[test]
    fn draw_text_blends_into_target() {
        let Some(data) = shipped_font() else {
            return;
        };
        let font = Fnt::load(&data).unwrap();
        let mut target = vec![255u8; 200 * 40 * 4];
        font.draw_text(&mut target, 200, 40, 2, 2, "A", [0, 0, 0])
            .unwrap();
        assert!(target.chunks_exact(4).any(|pixel| pixel[0] < 255));
    }
}
