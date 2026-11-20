use std::path::Path;

use pc2_assets::GameInstall;
use pc2_scene::Scene;
use pc2_sim::{CampaignBranch, CampaignMission, CampaignPropertyOffer, ScenarioSetup};

use crate::menu::decode_cp1252;

// Lifted lease dialog: 2812 rent plus a 1000 fee; HUD 500000 -> 496188.
const LONDON_LEASE: CampaignPropertyOffer = CampaignPropertyOffer {
    tile_index: 13_694,
    price: 2_812,
    fee: 1_000,
};

pub fn load_first_mission(install: &mut GameInstall) -> Result<ScenarioSetup, String> {
    let mission_list = match read(install, "update\\mission.txt")? {
        Some(data) => data,
        None => read(install, "daten\\mission.txt")?
            .ok_or("missing campaign mission list (update\\mission.txt or daten\\mission.txt)")?,
    };
    let mission_list = decode_cp1252(&mission_list);
    let short = mission_list
        .lines()
        .map(without_comment)
        .find(|line| !line.is_empty())
        .ok_or("campaign mission list is empty")?;
    if !short
        .bytes()
        .all(|byte| byte.is_ascii_alphanumeric() || byte == b'_')
    {
        return Err(format!("invalid campaign city code: {short:?}"));
    }
    let path = format!("daten\\{short}.ini");
    let data = read(install, &path)?.ok_or_else(|| format!("missing campaign resource {path}"))?;
    parse_mission(short, &decode_cp1252(&data)).map_err(|error| format!("{path}: {error}"))
}

fn read(install: &mut GameInstall, path: &str) -> Result<Option<Vec<u8>>, String> {
    install
        .read_asset(path)
        .map_err(|error| format!("cannot read campaign resource {path}: {error}"))
}

fn without_comment(line: &str) -> &str {
    line.split_once("//")
        .map_or(line, |(value, _)| value)
        .trim()
}

fn parse_mission(short: &str, ini: &str) -> Result<ScenarioSetup, String> {
    let entries: Vec<_> = ini
        .lines()
        .map(without_comment)
        .filter(|line| !line.is_empty())
        .map(|line| {
            let (key, value) = line.split_once(char::is_whitespace).unwrap_or((line, ""));
            (key, value.trim())
        })
        .collect();
    let field = |key: &str| {
        let mut values = entries.iter().filter(|(name, _)| *name == key);
        let (_, value) = values.next().ok_or_else(|| format!("missing {key}"))?;
        if values.next().is_some() {
            return Err(format!("duplicate {key}"));
        }
        Ok(*value)
    };
    let text = |key| {
        field(key)?
            .strip_prefix('"')
            .and_then(|value| value.strip_suffix('"'))
            .filter(|value| !value.is_empty())
            .ok_or_else(|| format!("invalid {key}"))
    };
    let number = |key| {
        field(key)?
            .parse::<u32>()
            .map_err(|_| format!("invalid {key}"))
    };
    let city_code = text("SHORT")?;
    if !city_code.eq_ignore_ascii_case(short) {
        return Err(format!(
            "SHORT {city_code:?} does not match mission city {short:?}"
        ));
    }
    let rival_count = number("GEGNERANZAHL")?;
    if rival_count > 5 {
        return Err("GEGNERANZAHL is outside 0..=5".into());
    }
    let goal_ids = numbers("ZIELE", field("ZIELE")?)?;
    if goal_ids.is_empty() {
        return Err("ZIELE is empty".into());
    }
    let starting_branches = entries
        .iter()
        .filter(|(key, _)| *key == "FILIALEN")
        .map(|(_, value)| {
            let values = numbers("FILIALEN", value)?;
            match values.as_slice() {
                [owner, size @ 0..=2, style @ 0..=4, owned @ 0..=1] if *owner <= rival_count => {
                    Ok(CampaignBranch {
                        owner_slot: *owner as u8,
                        size: *size as u8,
                        style: *style as u8,
                        owned: *owned == 1,
                    })
                }
                _ => Err(format!("invalid FILIALEN row: {value}")),
            }
        })
        .collect::<Result<_, String>>()?;
    let mission = CampaignMission {
        starting_cash: number("STARTGELD")?,
        difficulty_percent: number("SCHWIERIGKEITGRAD")?,
        goal_ids,
        rival_count: rival_count as u8,
        player_start_hq: number("STARTHQ")?,
        rival_start_hq: number("GEGNER_STARTHQ")?,
        starting_branches,
        property_offer: (city_code.eq_ignore_ascii_case("lon")
            && field("MIETEN").ok() == Some("70")
            && field("BESONDERHEIT").ok() == Some("1"))
        .then_some(LONDON_LEASE),
    };
    Ok(ScenarioSetup::from_campaign_mission(
        city_code.to_owned(),
        text("NAME")?.to_owned(),
        number("BEVOELKERUNG")?,
        number("SPIELZEIT")?,
        mission,
    ))
}

fn numbers(key: &str, value: &str) -> Result<Vec<u32>, String> {
    value
        .split_whitespace()
        .map(|item| {
            item.parse::<u32>()
                .map_err(|_| format!("invalid {key}: {item}"))
        })
        .collect()
}

pub fn validate_lease_offer(
    scenario: &mut ScenarioSetup,
    scene: &Scene,
    map: &Path,
) -> Result<(), String> {
    let Some(mission) = scenario.campaign_mission.as_mut() else {
        return Ok(());
    };
    let Some(offer) = mission.property_offer else {
        return Ok(());
    };
    // The provisional city-quote calculation uses the shipped London geometry.
    // Bind it to those map bytes so a changed neighborhood does not get this quote.
    let map = std::fs::read(map)
        .map_err(|error| format!("cannot verify lease map {}: {error}", scene.map_path))?;
    let hash = map.iter().fold(0xcbf29ce484222325u64, |hash, byte| {
        (hash ^ u64::from(*byte)).wrapping_mul(0x100000001b3)
    });
    if hash != 0x80299d373e017b9a
        || !scene.draws.iter().any(|draw| {
            draw.layer == 2
                && draw.tile_y * scene.grid_w + draw.tile_x == offer.tile_index
                && draw
                    .asset
                    .to_ascii_lowercase()
                    .ends_with("h_leerpizz_a1.spr")
        })
    {
        mission.property_offer = None;
    }
    Ok(())
}
