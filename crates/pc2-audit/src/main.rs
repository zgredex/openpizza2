use std::collections::BTreeMap;
use std::path::PathBuf;
use std::process::ExitCode;

use pc2_assets::{Ani, GameInstall, PcxImage, Sprite, TgaImage};

#[derive(Default, Clone)]
struct Stats {
    total: usize,
    decoded: usize,
    header_only: usize,
    unsupported: usize,
    errors: usize,
    examples: Vec<String>,
}

impl Stats {
    fn note(&mut self, outcome: Outcome, name: &str) {
        self.total += 1;
        match outcome {
            Outcome::Decoded => self.decoded += 1,
            Outcome::Header => self.header_only += 1,
            Outcome::Unsupported => self.unsupported += 1,
            Outcome::Error => {
                self.errors += 1;
                if self.examples.len() < 8 {
                    self.examples.push(name.to_string());
                }
            }
        }
    }
}

#[derive(Clone, Copy, PartialEq, Eq)]
enum Outcome {
    Decoded,
    Header,
    Unsupported,
    Error,
}

fn fnt_ok(data: &[u8]) -> bool {
    if data.len() < 0x624 {
        return false;
    }
    let mut total = 0usize;
    for index in 0..224 {
        let offset = 0x380 + index * 2;
        total += u16::from_le_bytes([data[offset], data[offset + 1]]) as usize;
    }
    data.len() == 0x624 + total
}

fn pcx_ok(data: &[u8]) -> bool {
    if data.len() < 128 || data[0] != 0x0a || data[2] != 1 {
        return false;
    }
    let bits = data[3];
    let xmin = u16::from_le_bytes([data[4], data[5]]) as u32;
    let ymin = u16::from_le_bytes([data[6], data[7]]) as u32;
    let xmax = u16::from_le_bytes([data[8], data[9]]) as u32;
    let ymax = u16::from_le_bytes([data[10], data[11]]) as u32;
    let planes = data[65];
    let bytes_per_line = u16::from_le_bytes([data[66], data[67]]) as u32;
    bits > 0 && xmax >= xmin && ymax >= ymin && planes > 0 && bytes_per_line > 0
}

fn palette_db_ok(data: &[u8]) -> bool {
    if data.len() < 4 {
        return false;
    }
    let count = u32::from_le_bytes(data[0..4].try_into().unwrap()) as usize;
    data.len() == 4 + count * 0x300
}

fn audit(extension: &str, data: &[u8]) -> Outcome {
    match extension {
        "spr" => match Sprite::load(data) {
            Ok(_) => Outcome::Decoded,
            Err(_) => Outcome::Error,
        },
        "ani" => match Ani::load(data) {
            Ok(_) => Outcome::Decoded,
            Err(_) => Outcome::Error,
        },
        "tga" => match TgaImage::load(data) {
            Ok(_) => Outcome::Decoded,
            Err(_) => Outcome::Error,
        },
        "fnt" => {
            if fnt_ok(data) {
                Outcome::Decoded
            } else {
                Outcome::Error
            }
        }
        "pcx" => {
            if pcx_ok(data) && PcxImage::load(data).is_ok() {
                Outcome::Decoded
            } else {
                Outcome::Error
            }
        }
        "wav" => {
            if data.len() >= 12 && &data[0..4] == b"RIFF" && &data[8..12] == b"WAVE" {
                Outcome::Header
            } else {
                Outcome::Error
            }
        }
        "bik" => {
            if data.starts_with(b"BIK") {
                Outcome::Header
            } else {
                Outcome::Error
            }
        }
        "txt" | "ini" => {
            if data.len() > 4 {
                Outcome::Decoded
            } else {
                Outcome::Error
            }
        }
        "tab" => {
            if data.len() % 2 == 0 && !data.is_empty() {
                Outcome::Decoded
            } else {
                Outcome::Error
            }
        }
        "db" => {
            if palette_db_ok(data) {
                Outcome::Decoded
            } else {
                Outcome::Error
            }
        }
        "idx" => {
            if data.len() >= 4 {
                let count = u32::from_le_bytes(data[0..4].try_into().unwrap()) as usize;
                if count == 2467 {
                    Outcome::Decoded
                } else {
                    Outcome::Header
                }
            } else {
                Outcome::Error
            }
        }
        "pix" | "bin" => {
            if data.is_empty() {
                Outcome::Error
            } else {
                Outcome::Header
            }
        }
        _ => Outcome::Unsupported,
    }
}

fn main() -> ExitCode {
    let mut args = std::env::args();
    let program = args.next().unwrap_or_else(|| "pc2-audit".into());
    let mut install_path = PathBuf::from("game");
    let mut json = false;
    let mut check = false;
    while let Some(arg) = args.next() {
        match arg.as_str() {
            "--install" => {
                install_path = args
                    .next()
                    .map(PathBuf::from)
                    .unwrap_or_else(|| PathBuf::from("game"));
            }
            "--json" => json = true,
            "--check" => check = true,
            "-h" | "--help" => {
                println!("usage: {program} [--install PATH] [--json] [--check]");
                return ExitCode::SUCCESS;
            }
            other => {
                eprintln!("unknown argument: {other}");
                return ExitCode::FAILURE;
            }
        }
    }
    let mut install = match GameInstall::open(&install_path) {
        Ok(install) => install,
        Err(error) => {
            eprintln!("audit failed: {error}");
            return ExitCode::FAILURE;
        }
    };
    let mut stats: BTreeMap<String, Stats> = BTreeMap::new();
    for archive_index in 0..install.archives.len() {
        let entries = install.archives[archive_index].entries.clone();
        for entry in entries {
            let extension = entry
                .name
                .rsplit_once('.')
                .map(|(_, ext)| ext.to_ascii_lowercase())
                .unwrap_or_default();
            let data = match install.read_entry(archive_index, &entry) {
                Ok(data) => data,
                Err(_) => {
                    stats
                        .entry(extension)
                        .or_default()
                        .note(Outcome::Error, &entry.name);
                    continue;
                }
            };
            let outcome = audit(&extension, &data);
            stats
                .entry(extension)
                .or_default()
                .note(outcome, &entry.name);
        }
    }
    if json {
        println!("{{");
        println!("  \"install\": \"{}\",", install.root.display());
        println!("  \"formats\": {{");
        let format_count = stats.len();
        for (index, (extension, format_stats)) in stats.iter().enumerate() {
            println!(
                "    \"{}\": {{\"total\": {}, \"decoded\": {}, \"header_only\": {}, \"unsupported\": {}, \"errors\": {}}}{}",
                extension,
                format_stats.total,
                format_stats.decoded,
                format_stats.header_only,
                format_stats.unsupported,
                format_stats.errors,
                if index + 1 == format_count { "" } else { "," }
            );
        }
        println!("  }}");
        println!("}}");
    } else {
        println!(
            "{:<6} {:>6} {:>8} {:>12} {:>12} {:>7}",
            "ext", "total", "decoded", "header-only", "unsupported", "errors"
        );
        for (extension, stats) in &stats {
            println!(
                "{:<6} {:>6} {:>8} {:>12} {:>12} {:>7}",
                extension,
                stats.total,
                stats.decoded,
                stats.header_only,
                stats.unsupported,
                stats.errors
            );
            for example in &stats.examples {
                println!("       error: {example}");
            }
        }
    }
    let total: usize = stats.values().map(|stats| stats.total).sum();
    let decoded: usize = stats.values().map(|stats| stats.decoded).sum();
    let header_only: usize = stats.values().map(|stats| stats.header_only).sum();
    let unsupported: usize = stats.values().map(|stats| stats.unsupported).sum();
    let errors: usize = stats.values().map(|stats| stats.errors).sum();
    println!(
        "summary: {total} entries, {decoded} decoded, {header_only} header-only, {unsupported} unsupported, {errors} errors"
    );
    if check
        && (total != 9142
            || decoded != 7542
            || header_only != 1600
            || unsupported != 0
            || errors != 0)
    {
        eprintln!("asset audit mismatch");
        return ExitCode::FAILURE;
    }
    ExitCode::SUCCESS
}
