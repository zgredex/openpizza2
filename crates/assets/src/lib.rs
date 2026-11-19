//! Read-only asset layer for the Pizza Connection 2 installation.
//!
//! The first modern-engine deliverable is a headless inventory of the five
//! shipped `.pak` archives. Parsing follows `PAK_FORMAT.md` and the Python
//! reference implementation in `tools/pak_tool.py`.

use std::collections::BTreeMap;
use std::fs::{self, File};
use std::io::{Read, Seek, SeekFrom};
use std::path::{Path, PathBuf};

pub mod ani;
pub mod fnt;
pub mod iso;
pub mod pcx;
pub mod spr;
pub mod tga;

pub use ani::{Ani, AniFrame};
pub use fnt::{Fnt, Glyph};
pub use iso::{IsoHeader, IsoMap, IsoTile};
pub use pcx::PcxImage;
pub use spr::Sprite;
pub use tga::TgaImage;

pub const MAGIC: &[u8] = b"ResourceFile-ID-7654\n\r\x1a";
pub const HEADER_SIZE: u64 = 0x6c;
pub const ENTRY_SIZE: usize = 0x14;

#[derive(Debug)]
pub enum AssetsError {
    Io(std::io::Error),
    InvalidMagic(PathBuf),
    Truncated(PathBuf, &'static str),
    Bounds(PathBuf, String),
    BadName(PathBuf, usize),
}

impl std::fmt::Display for AssetsError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            AssetsError::Io(error) => write!(f, "{error}"),
            AssetsError::InvalidMagic(path) => {
                write!(f, "{}: not a ResourceFile-ID-7654 archive", path.display())
            }
            AssetsError::Truncated(path, what) => {
                write!(f, "{}: truncated {what}", path.display())
            }
            AssetsError::Bounds(path, detail) => {
                write!(f, "{}: {detail}", path.display())
            }
            AssetsError::BadName(path, index) => {
                write!(
                    f,
                    "{}: entry {index} has an invalid name offset",
                    path.display()
                )
            }
        }
    }
}

impl std::error::Error for AssetsError {}

impl From<std::io::Error> for AssetsError {
    fn from(error: std::io::Error) -> Self {
        AssetsError::Io(error)
    }
}

pub type Result<T> = std::result::Result<T, AssetsError>;

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct PakEntry {
    pub index: usize,
    pub name: String,
    pub size: u32,
    pub rel_offset: u32,
    pub meta0: u32,
    pub meta1: u32,
}

impl PakEntry {
    pub fn offset(&self) -> u64 {
        HEADER_SIZE + self.rel_offset as u64
    }
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct PakSummary {
    pub file: String,
    pub entries: usize,
    pub index_size: u32,
    pub payload_bytes: u64,
    pub obfuscated: bool,
}

#[derive(Debug)]
pub struct PakArchive {
    pub path: PathBuf,
    pub index_size: u32,
    pub header64: u32,
    pub obfuscated: bool,
    pub entries: Vec<PakEntry>,
    file_len: u64,
    file: File,
}

impl PakArchive {
    pub fn open(path: impl AsRef<Path>) -> Result<Self> {
        let path = path.as_ref().to_path_buf();
        let mut file = File::open(&path)?;
        let file_len = file.metadata()?.len();
        if file_len < HEADER_SIZE {
            return Err(AssetsError::Truncated(path, "header"));
        }
        let mut header = [0u8; HEADER_SIZE as usize];
        file.read_exact(&mut header)?;
        if !header.starts_with(MAGIC) {
            return Err(AssetsError::InvalidMagic(path));
        }
        let index_size = u32::from_le_bytes(header[0x60..0x64].try_into().unwrap());
        let header64 = u32::from_le_bytes(header[0x64..0x68].try_into().unwrap());
        let obfuscated = u32::from_le_bytes(header[0x68..0x6c].try_into().unwrap()) != 0;
        if HEADER_SIZE + index_size as u64 > file_len {
            return Err(AssetsError::Truncated(path, "index"));
        }
        let mut encoded = vec![0u8; index_size as usize];
        file.read_exact(&mut encoded)?;
        let decoded: Vec<u8> = if obfuscated {
            encoded
                .iter()
                .enumerate()
                .map(|(i, byte)| (byte.wrapping_sub((i & 0xff) as u8)) ^ 0xaa)
                .collect()
        } else {
            encoded
        };
        if decoded.len() < 4 {
            return Err(AssetsError::Truncated(path, "entry count"));
        }
        let count = u32::from_le_bytes(decoded[0..4].try_into().unwrap()) as usize;
        let names_base =
            4usize
                .checked_add(count.checked_mul(ENTRY_SIZE).ok_or_else(|| {
                    AssetsError::Bounds(path.clone(), "entry count overflow".into())
                })?)
                .ok_or_else(|| AssetsError::Bounds(path.clone(), "entry table overflow".into()))?;
        if names_base > decoded.len() {
            return Err(AssetsError::Truncated(path, "entry table"));
        }
        let mut entries = Vec::with_capacity(count);
        for index in 0..count {
            let base = 4 + index * ENTRY_SIZE;
            let read_u32 = |offset: usize| {
                u32::from_le_bytes(
                    decoded[base + offset..base + offset + 4]
                        .try_into()
                        .unwrap(),
                )
            };
            let (meta0, meta1, size, rel_offset, name_rel) = (
                read_u32(0),
                read_u32(4),
                read_u32(8),
                read_u32(0xc),
                read_u32(0x10),
            );
            let name_start = names_base
                .checked_add(name_rel as usize)
                .ok_or_else(|| AssetsError::BadName(path.clone(), index))?;
            if name_start >= decoded.len() {
                return Err(AssetsError::BadName(path.clone(), index));
            }
            let name_end = decoded[name_start..]
                .iter()
                .position(|byte| *byte == 0)
                .map(|offset| name_start + offset)
                .ok_or_else(|| AssetsError::BadName(path.clone(), index))?;
            let name = decode_cp1252(&decoded[name_start..name_end]);
            let end = HEADER_SIZE + rel_offset as u64 + size as u64;
            if end > file_len {
                return Err(AssetsError::Bounds(
                    path.clone(),
                    format!("entry {index} ({name}) extends past EOF"),
                ));
            }
            entries.push(PakEntry {
                index,
                name,
                size,
                rel_offset,
                meta0,
                meta1,
            });
        }
        Ok(Self {
            path,
            index_size,
            header64,
            obfuscated,
            entries,
            file_len,
            file,
        })
    }

    pub fn summary(&self) -> PakSummary {
        PakSummary {
            file: self
                .path
                .file_name()
                .and_then(|name| name.to_str())
                .unwrap_or_default()
                .to_string(),
            entries: self.entries.len(),
            index_size: self.index_size,
            payload_bytes: self.entries.iter().map(|entry| entry.size as u64).sum(),
            obfuscated: self.obfuscated,
        }
    }

    pub fn payload_bytes(&self) -> u64 {
        self.entries.iter().map(|entry| entry.size as u64).sum()
    }

    pub fn find(&self, name: &str) -> Option<&PakEntry> {
        let needle = normalize_key(name);
        self.entries
            .iter()
            .find(|entry| normalize_key(&entry.name) == needle)
    }

    pub fn read_entry(&mut self, entry: &PakEntry) -> Result<Vec<u8>> {
        let end = entry.offset() + entry.size as u64;
        if end > self.file_len {
            return Err(AssetsError::Bounds(
                self.path.clone(),
                format!("entry {} exceeds EOF", entry.index),
            ));
        }
        self.file.seek(SeekFrom::Start(entry.offset()))?;
        let mut data = vec![0u8; entry.size as usize];
        self.file.read_exact(&mut data)?;
        Ok(data)
    }
}

#[derive(Debug)]
pub struct GameInstall {
    pub root: PathBuf,
    pub archives: Vec<PakArchive>,
    pub loose_files: Vec<PathBuf>,
}

impl GameInstall {
    pub fn open(root: impl AsRef<Path>) -> Result<Self> {
        let root = root.as_ref().to_path_buf();
        let resources = root.join("Resources");
        let mut paths = Vec::new();
        if resources.is_dir() {
            for entry in fs::read_dir(&resources)? {
                let path = entry?.path();
                if path
                    .extension()
                    .and_then(|ext| ext.to_str())
                    .map(|ext| ext.eq_ignore_ascii_case("pak"))
                    .unwrap_or(false)
                {
                    paths.push(path);
                }
            }
        }
        paths.sort();
        let mut archives = Vec::with_capacity(paths.len());
        for path in paths {
            archives.push(PakArchive::open(path)?);
        }
        let mut loose_files = Vec::new();
        collect_loose_files(&root, &root, &mut loose_files)?;
        Ok(Self {
            root,
            archives,
            loose_files,
        })
    }

    pub fn entry_count(&self) -> usize {
        self.archives.iter().map(|pak| pak.entries.len()).sum()
    }

    pub fn payload_bytes(&self) -> u64 {
        self.archives.iter().map(PakArchive::payload_bytes).sum()
    }

    pub fn read_entry(&mut self, archive: usize, entry: &PakEntry) -> Result<Vec<u8>> {
        self.archives
            .get_mut(archive)
            .ok_or_else(|| {
                AssetsError::Bounds(self.root.clone(), "archive index out of range".into())
            })?
            .read_entry(entry)
    }

    pub fn find_asset(&self, name: &str) -> Option<(usize, PakEntry)> {
        for (index, pak) in self.archives.iter().enumerate() {
            if let Some(entry) = pak.find(name) {
                return Some((index, entry.clone()));
            }
        }
        None
    }

    pub fn read_asset(&mut self, name: &str) -> Result<Option<Vec<u8>>> {
        let Some((archive, entry)) = self.find_asset(name) else {
            return Ok(None);
        };
        self.read_entry(archive, &entry).map(Some)
    }

    pub fn extension_counts(&self) -> BTreeMap<String, usize> {
        let mut counts = BTreeMap::new();
        for pak in &self.archives {
            for entry in &pak.entries {
                let extension = entry
                    .name
                    .rsplit_once('.')
                    .map(|(_, ext)| ext.to_ascii_lowercase())
                    .unwrap_or_default();
                *counts.entry(extension).or_insert(0) += 1;
            }
        }
        counts
    }
}

fn collect_loose_files(root: &Path, current: &Path, out: &mut Vec<PathBuf>) -> Result<()> {
    for entry in fs::read_dir(current)? {
        let path = entry?.path();
        if path.is_dir() {
            collect_loose_files(root, &path, out)?;
        } else {
            let resources = root.join("Resources");
            if path.starts_with(&resources)
                && path
                    .extension()
                    .and_then(|ext| ext.to_str())
                    .map(|ext| ext.eq_ignore_ascii_case("pak"))
                    .unwrap_or(false)
            {
                continue;
            }
            out.push(path);
        }
    }
    Ok(())
}

pub fn normalize_key(name: &str) -> String {
    name.replace('/', "\\").to_ascii_lowercase()
}

fn decode_cp1252(bytes: &[u8]) -> String {
    let mut text = String::with_capacity(bytes.len());
    for &byte in bytes {
        let ch = match byte {
            0x80 => '\u{20ac}',
            0x82 => '\u{201a}',
            0x83 => '\u{0192}',
            0x84 => '\u{201e}',
            0x85 => '\u{2026}',
            0x86 => '\u{2020}',
            0x87 => '\u{2021}',
            0x88 => '\u{02c6}',
            0x89 => '\u{2030}',
            0x8a => '\u{0160}',
            0x8b => '\u{2039}',
            0x8c => '\u{0152}',
            0x8e => '\u{017d}',
            0x91 => '\u{2018}',
            0x92 => '\u{2019}',
            0x93 => '\u{201c}',
            0x94 => '\u{201d}',
            0x95 => '\u{2022}',
            0x96 => '\u{2013}',
            0x97 => '\u{2014}',
            0x98 => '\u{02dc}',
            0x99 => '\u{2122}',
            0x9a => '\u{0161}',
            0x9b => '\u{203a}',
            0x9c => '\u{0153}',
            0x9e => '\u{017e}',
            0x9f => '\u{0178}',
            _ => char::from(byte),
        };
        text.push(ch);
    }
    text
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::io::Write;

    fn build_synthetic_pak(path: &Path) {
        let names = ["daten\\one.txt", "sprites\\two.spr"];
        let payloads: [&[u8]; 2] = [b"hello", b"world!"];
        let mut name_table = Vec::new();
        let mut payload = Vec::new();
        for (name, data) in names.iter().zip(payloads) {
            name_table.extend_from_slice(name.as_bytes());
            name_table.push(0);
            payload.extend_from_slice(data);
        }
        let index_len = 4 + names.len() * ENTRY_SIZE + name_table.len();
        let mut entries = Vec::new();
        let mut payload_offset = 0u32;
        for (index, (name, data)) in names.iter().zip(payloads).enumerate() {
            let name_rel = name_table
                .windows(name.len() + 1)
                .position(|window| {
                    window[..name.len()] == name.as_bytes()[..] && window[name.len()] == 0
                })
                .unwrap() as u32;
            entries.push((
                index as u32,
                index as u32 + 10,
                data.len() as u32,
                index_len as u32 + payload_offset,
                name_rel,
            ));
            payload_offset += data.len() as u32;
        }
        let mut decoded = Vec::new();
        decoded.extend_from_slice(&(entries.len() as u32).to_le_bytes());
        for entry in &entries {
            decoded.extend_from_slice(&entry.0.to_le_bytes());
            decoded.extend_from_slice(&entry.1.to_le_bytes());
            decoded.extend_from_slice(&entry.2.to_le_bytes());
            decoded.extend_from_slice(&entry.3.to_le_bytes());
            decoded.extend_from_slice(&entry.4.to_le_bytes());
        }
        decoded.extend_from_slice(&name_table);
        let encoded: Vec<u8> = decoded
            .iter()
            .enumerate()
            .map(|(i, byte)| ((byte ^ 0xaa).wrapping_add((i & 0xff) as u8)))
            .collect();
        let mut file = File::create(path).unwrap();
        let mut header = [0u8; HEADER_SIZE as usize];
        header[..MAGIC.len()].copy_from_slice(MAGIC);
        header[0x60..0x64].copy_from_slice(&(encoded.len() as u32).to_le_bytes());
        header[0x64..0x68].copy_from_slice(&100u32.to_le_bytes());
        header[0x68..0x6c].copy_from_slice(&1u32.to_le_bytes());
        file.write_all(&header).unwrap();
        file.write_all(&encoded).unwrap();
        file.write_all(&payload).unwrap();
    }

    #[test]
    fn synthetic_archive_roundtrips() {
        let path = std::env::temp_dir().join(format!("pc2-pak-{}.pak", std::process::id()));
        build_synthetic_pak(&path);
        let mut pak = PakArchive::open(&path).unwrap();
        assert_eq!(pak.entries.len(), 2);
        assert_eq!(pak.header64, 100);
        assert!(pak.obfuscated);
        let entry = pak.find("daten/one.txt").unwrap().clone();
        assert_eq!(pak.read_entry(&entry).unwrap(), b"hello");
        assert_eq!(pak.payload_bytes(), 11);
        fs::remove_file(path).unwrap();
    }

    #[test]
    fn real_install_inventory() {
        let root = Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("game");
        if !root.is_dir() {
            return;
        }
        let mut install = GameInstall::open(&root).unwrap();
        assert_eq!(install.archives.len(), 5);
        assert_eq!(install.entry_count(), 9142);
        assert_eq!(install.payload_bytes(), 448_651_308);
        assert_eq!(install.archives[0].summary().file, "iso.pak");
        let ber = install
            .archives
            .iter()
            .enumerate()
            .find_map(|(index, pak)| {
                pak.find("daten\\ber.ini")
                    .map(|entry| (index, entry.clone()))
            })
            .expect("ber.ini in main.pak");
        let data = install.read_entry(ber.0, &ber.1).unwrap();
        assert!(!data.is_empty());
        assert!(data.starts_with(b"//"));
    }
}
