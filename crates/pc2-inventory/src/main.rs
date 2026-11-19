//! Headless inventory of the installed Pizza Connection 2 archives.

use std::path::PathBuf;
use std::process::ExitCode;

use pc2_assets::{normalize_key, GameInstall};

const EXPECTED_PAKS: usize = 5;
const EXPECTED_ENTRIES: usize = 9142;
const EXPECTED_PAYLOAD: u64 = 448_651_308;

fn escape_json(value: &str) -> String {
    let mut out = String::with_capacity(value.len() + 2);
    for ch in value.chars() {
        match ch {
            '"' => out.push_str("\\\""),
            '\\' => out.push_str("\\\\"),
            '\n' => out.push_str("\\n"),
            '\r' => out.push_str("\\r"),
            '\t' => out.push_str("\\t"),
            ch if ch < ' ' => out.push_str(&format!("\\u{:04x}", ch as u32)),
            ch => out.push(ch),
        }
    }
    out
}

fn usage(program: &str) {
    eprintln!(
        "usage: {program} [--install PATH] [--check] [--read KEY]\n\
         \n\
         --install PATH  installation root (default: game)\n\
         --check         exit non-zero unless the five shipped PAK totals match\n\
         --read KEY      read one archive entry and print its byte count"
    );
}

fn main() -> ExitCode {
    let args = std::env::args().collect::<Vec<_>>();
    let program = args
        .first()
        .cloned()
        .unwrap_or_else(|| "pc2-inventory".into());
    let mut install_path = PathBuf::from("game");
    let mut check = false;
    let mut read_key: Option<String> = None;
    let mut index = 1;
    while index < args.len() {
        match args[index].as_str() {
            "--install" => {
                index += 1;
                if index >= args.len() {
                    usage(&program);
                    return ExitCode::FAILURE;
                }
                install_path = PathBuf::from(&args[index]);
            }
            "--check" => check = true,
            "--read" => {
                index += 1;
                if index >= args.len() {
                    usage(&program);
                    return ExitCode::FAILURE;
                }
                read_key = Some(args[index].clone());
            }
            "--help" | "-h" => {
                usage(&program);
                return ExitCode::SUCCESS;
            }
            other => {
                eprintln!("unknown argument: {other}");
                usage(&program);
                return ExitCode::FAILURE;
            }
        }
        index += 1;
    }

    let mut install = match GameInstall::open(&install_path) {
        Ok(install) => install,
        Err(error) => {
            eprintln!("inventory failed: {error}");
            return ExitCode::FAILURE;
        }
    };

    let entries = install.entry_count();
    let payload = install.payload_bytes();
    let mut extensions = install.extension_counts().into_iter().collect::<Vec<_>>();
    extensions.sort_by(|a, b| b.1.cmp(&a.1).then_with(|| a.0.cmp(&b.0)));

    println!("{{");
    println!(
        "  \"install\": \"{}\",",
        escape_json(&install.root.display().to_string())
    );
    println!("  \"pak_count\": {},", install.archives.len());
    println!("  \"loose_files\": {},", install.loose_files.len());
    println!("  \"entries\": {entries},");
    println!("  \"payload_bytes\": {payload},");
    println!("  \"archives\": [");
    for (position, pak) in install.archives.iter().enumerate() {
        let summary = pak.summary();
        println!("    {{");
        println!("      \"file\": \"{}\",", escape_json(&summary.file));
        println!("      \"entries\": {},", summary.entries);
        println!("      \"index_size\": {},", summary.index_size);
        println!("      \"payload_bytes\": {},", summary.payload_bytes);
        println!("      \"obfuscated\": {}", summary.obfuscated);
        println!(
            "    }}{}",
            if position + 1 == install.archives.len() {
                ""
            } else {
                ","
            }
        );
    }
    println!("  ],");
    println!("  \"extensions\": {{");
    for (position, (extension, count)) in extensions.iter().enumerate() {
        println!(
            "    \"{}\": {}{}",
            escape_json(extension),
            count,
            if position + 1 == extensions.len() {
                ""
            } else {
                ","
            }
        );
    }
    println!("  }}");
    println!("}}");

    if let Some(key) = read_key {
        let needle = normalize_key(&key);
        let found = install
            .archives
            .iter()
            .enumerate()
            .find_map(|(index, pak)| pak.find(&needle).map(|entry| (index, entry.clone())));
        match found {
            Some((archive, entry)) => match install.read_entry(archive, &entry) {
                Ok(data) => println!(
                    "read {} bytes from {}:{}",
                    data.len(),
                    install.archives[archive].summary().file,
                    entry.name
                ),
                Err(error) => {
                    eprintln!("read failed: {error}");
                    return ExitCode::FAILURE;
                }
            },
            None => {
                eprintln!("entry not found: {key}");
                return ExitCode::FAILURE;
            }
        }
    }

    if check
        && (install.archives.len() != EXPECTED_PAKS
            || entries != EXPECTED_ENTRIES
            || payload != EXPECTED_PAYLOAD)
    {
        eprintln!(
            "inventory mismatch: paks={} entries={entries} payload={payload} \
             (expected {EXPECTED_PAKS}, {EXPECTED_ENTRIES}, {EXPECTED_PAYLOAD})",
            install.archives.len()
        );
        return ExitCode::FAILURE;
    }
    ExitCode::SUCCESS
}
