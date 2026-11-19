//! Parser for the shipped `.iso` isometric maps.

use std::fs;
use std::path::Path;

use crate::{AssetsError, Result};

const HEADER_SIZE: usize = 0x7c;
const LIST_RECORD_SIZE: usize = 34;
const TILE_FIXED_SIZE: usize = 30;
const NAME_SIZE: usize = 50;

#[derive(Clone, Debug, Default)]
pub struct IsoHeader {
    pub name_mode: u32,
    pub view_w: u32,
    pub view_h: u32,
    pub tile_w: u32,
    pub tile_h: u32,
    pub grid_w: u32,
    pub grid_h: u32,
    pub pixel_w: u32,
    pub pixel_h: u32,
    pub u28: u32,
    pub u2c: u32,
    pub list1: u32,
    pub list2: u32,
    pub background: String,
}

#[derive(Clone, Debug)]
pub struct IsoTile {
    pub index: u32,
    pub x: u32,
    pub y: u32,
    pub flags: u32,
    pub layer1_raw: u32,
    pub layer2_raw: u32,
    pub layer1: Option<String>,
    pub layer2: Option<String>,
}

#[derive(Clone, Debug)]
pub struct IsoMap {
    pub header: IsoHeader,
    pub tiles: Vec<IsoTile>,
}

fn u32_at(data: &[u8], offset: usize) -> u32 {
    u32::from_le_bytes(data[offset..offset + 4].try_into().unwrap())
}

fn name_at(data: &[u8], offset: usize) -> String {
    let bytes = &data[offset..offset + NAME_SIZE];
    let end = bytes
        .iter()
        .position(|byte| *byte == 0)
        .unwrap_or(NAME_SIZE);
    String::from_utf8_lossy(&bytes[..end]).to_string()
}

impl IsoMap {
    pub fn load(path: impl AsRef<Path>) -> Result<Self> {
        let path = path.as_ref();
        let data = fs::read(path)?;
        if data.len() < HEADER_SIZE + 8 {
            return Err(AssetsError::Truncated(path.to_path_buf(), "iso header"));
        }
        let header = IsoHeader {
            name_mode: u32_at(&data, 4),
            view_w: u32_at(&data, 8),
            view_h: u32_at(&data, 0xc),
            tile_w: u32_at(&data, 0x10),
            tile_h: u32_at(&data, 0x14),
            grid_w: u32_at(&data, 0x18),
            grid_h: u32_at(&data, 0x1c),
            pixel_w: u32_at(&data, 0x20),
            pixel_h: u32_at(&data, 0x24),
            u28: u32_at(&data, 0x28),
            u2c: u32_at(&data, 0x2c),
            list1: u32_at(&data, 0x74),
            list2: u32_at(&data, 0x78),
            background: name_at(&data, 0x50),
        };
        let total = (header.grid_w as usize)
            .checked_mul(header.grid_h as usize)
            .ok_or_else(|| AssetsError::Bounds(path.to_path_buf(), "iso grid overflow".into()))?;
        let mut offset =
            HEADER_SIZE + (header.list1 as usize + header.list2 as usize) * LIST_RECORD_SIZE;
        if offset > data.len() {
            return Err(AssetsError::Truncated(
                path.to_path_buf(),
                "iso object tables",
            ));
        }
        let mut tiles = Vec::new();
        let mut index = 0usize;
        while index < total {
            if offset + 4 > data.len() {
                return Err(AssetsError::Truncated(path.to_path_buf(), "iso tile flag"));
            }
            let flag = u32_at(&data, offset);
            offset += 4;
            if flag == 1 {
                if offset + 4 > data.len() {
                    return Err(AssetsError::Truncated(path.to_path_buf(), "iso run"));
                }
                let run = u32_at(&data, offset) as usize;
                offset += 4;
                if index + run > total {
                    return Err(AssetsError::Bounds(
                        path.to_path_buf(),
                        format!("iso run overflows grid at tile {index}"),
                    ));
                }
                index += run;
                continue;
            }
            if offset + TILE_FIXED_SIZE > data.len() {
                return Err(AssetsError::Truncated(path.to_path_buf(), "iso tile"));
            }
            let flags = u32_at(&data, offset);
            offset += TILE_FIXED_SIZE;
            let mut layers = [None, None];
            let mut raws = [u32::MAX; 2];
            for (layer_index, layer) in layers.iter_mut().enumerate() {
                if offset + 4 > data.len() {
                    return Err(AssetsError::Truncated(path.to_path_buf(), "iso layer id"));
                }
                let raw = u32_at(&data, offset);
                raws[layer_index] = raw;
                offset += 4;
                if header.name_mode == 0 && raw < 0x8000_0000 {
                    if offset + NAME_SIZE > data.len() {
                        return Err(AssetsError::Truncated(path.to_path_buf(), "iso layer name"));
                    }
                    let name = name_at(&data, offset);
                    offset += NAME_SIZE;
                    if !name.is_empty() {
                        *layer = Some(name);
                    }
                }
            }
            tiles.push(IsoTile {
                index: index as u32,
                x: (index % header.grid_w as usize) as u32,
                y: (index / header.grid_w as usize) as u32,
                flags,
                layer1_raw: raws[0],
                layer2_raw: raws[1],
                layer1: layers[0].take(),
                layer2: layers[1].take(),
            });
            index += 1;
        }
        Ok(Self { header, tiles })
    }
}
