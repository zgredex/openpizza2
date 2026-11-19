//! Isometric scene builder for the shipped `.iso` maps.
//!
//! The builder projects map tiles with the same cell coordinates the loader
//! creates in `IsoMap_DeserializeGrid` (`0x4eb900`):
//!
//! ```text
//! world_x = ((grid_h - tile_y + tile_x) * view_w) / 2
//! world_y =  (tile_x + tile_y) * view_h / 2
//! ```
//!
//! Sprites are anchored at the bottom centre of that cell and sorted by their
//! ground line, which matches the painter order in `IsoMap_RenderFrame`
//! (`0x4ef9e0`): upper rows first, lower rows last. The background TGA is
//! placed at the map origin (`u28`, `u2c`); `ber.tga` is 4096x2048 and covers
//! 128x128 cells at the city zoom.

use std::collections::{BTreeMap, HashMap, HashSet};
use std::fs::File;
use std::path::Path;
use std::sync::Arc;

use pc2_assets::{normalize_key, Ani, GameInstall, IsoMap, IsoTile, Sprite, TgaImage};

#[derive(Debug)]
pub enum SceneError {
    Assets(pc2_assets::AssetsError),
    Io(std::io::Error),
    Png(png::EncodingError),
    MissingBackground(String),
    MissingSprite(String),
}

impl std::fmt::Display for SceneError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            SceneError::Assets(error) => write!(f, "{error}"),
            SceneError::Io(error) => write!(f, "{error}"),
            SceneError::Png(error) => write!(f, "{error}"),
            SceneError::MissingBackground(key) => write!(f, "missing background {key}"),
            SceneError::MissingSprite(name) => write!(f, "missing sprite {name}"),
        }
    }
}

impl std::error::Error for SceneError {}

impl From<pc2_assets::AssetsError> for SceneError {
    fn from(error: pc2_assets::AssetsError) -> Self {
        SceneError::Assets(error)
    }
}

impl From<std::io::Error> for SceneError {
    fn from(error: std::io::Error) -> Self {
        SceneError::Io(error)
    }
}

impl From<png::EncodingError> for SceneError {
    fn from(error: png::EncodingError) -> Self {
        SceneError::Png(error)
    }
}

pub type Result<T> = std::result::Result<T, SceneError>;

#[derive(Clone, Debug)]
pub struct SceneOptions {
    /// Camera centre in original map world coordinates. `None` uses the
    /// bounding-box centre of all named tile layers.
    pub center: Option<(i32, i32)>,
    pub width: u32,
    pub height: u32,
    /// Include the first layer in addition to the usual second layer.
    pub include_layer1: bool,
    /// Optional background key override, e.g. `backgrounds/ber.tga`.
    pub background: Option<String>,
    /// Replace animated map sprites with a decoded `.ani` frame.
    pub animate: bool,
    pub animation_frame: usize,
}

impl Default for SceneOptions {
    fn default() -> Self {
        Self {
            center: None,
            width: 800,
            height: 600,
            include_layer1: false,
            background: None,
            animate: false,
            animation_frame: 0,
        }
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum BackgroundKind {
    Tga,
    Sprite,
}

impl BackgroundKind {
    pub fn label(self) -> &'static str {
        match self {
            BackgroundKind::Tga => "tga",
            BackgroundKind::Sprite => "sprite",
        }
    }
}

#[derive(Clone, Debug)]
pub struct Draw {
    pub order: usize,
    pub asset: String,
    pub tile_x: u32,
    pub tile_y: u32,
    pub layer: u8,
    pub world_x: i32,
    pub world_y: i32,
    pub source_x: u32,
    pub source_y: u32,
    pub source_width: u32,
    pub source_height: u32,
    pub dest_x: i32,
    pub dest_y: i32,
    pub width: u32,
    pub height: u32,
    /// Present when the draw uses a decoded `.ani` frame.
    pub animation: Option<String>,
    pub animation_frame: Option<usize>,
    /// Decoded RGBA pixels for CPU composition and tests.
    pub pixels: Arc<Vec<u8>>,
}

#[derive(Clone, Debug)]
pub struct Crop {
    pub center_x: i32,
    pub center_y: i32,
    pub x: i32,
    pub y: i32,
    pub width: u32,
    pub height: u32,
}

#[derive(Clone, Debug)]
pub struct Scene {
    pub map_path: String,
    pub background_key: String,
    pub background_kind: BackgroundKind,
    pub floor_key: Option<String>,
    pub background_width: u32,
    pub background_height: u32,
    pub background_origin: (i32, i32),
    pub crop: Crop,
    pub grid_w: u32,
    pub grid_h: u32,
    pub view_w: u32,
    pub view_h: u32,
    pub tiles_present: usize,
    pub layers_considered: usize,
    pub animation_frame: usize,
    pub animation_frames: usize,
    pub animated_draws: usize,
    pub draws: Vec<Draw>,
    pub missing: Vec<(String, u32, u32, u8)>,
    pub ambiguous: Vec<(String, usize)>,
    pub background_crop: Vec<u8>,
    pub pixels: Vec<u8>,
}

impl Scene {
    pub fn build(
        install: &mut GameInstall,
        map_path: impl AsRef<Path>,
        options: &SceneOptions,
    ) -> Result<Self> {
        let map_path = map_path.as_ref();
        let map = IsoMap::load(map_path)?;
        if map.header.view_w == 0 || map.header.view_h == 0 {
            return Err(SceneError::MissingBackground(
                "map has a zero viewport".into(),
            ));
        }

        let mut background =
            load_background(install, &map, map_path, options.background.as_deref())?;
        let floor_key = patch_branch_floor(install, &mut background, map_path)?;

        let basename = sprite_index(install);
        let mut cache: HashMap<String, DecodedSprite> = HashMap::new();
        let mut ani_cache: HashMap<String, Arc<Ani>> = HashMap::new();
        let mut animation_frames = 1usize;
        let mut animated_draws = 0usize;
        let mut missing = Vec::new();
        let mut ambiguous = Vec::new();

        let mut layers = Vec::new();
        for tile in &map.tiles {
            if let Some(name) = &tile.layer1 {
                layers.push((tile, 1u8, name.clone(), tile.layer1_raw));
            }
            if let Some(name) = &tile.layer2 {
                layers.push((tile, 2u8, name.clone(), tile.layer2_raw));
            }
        }
        if !options.include_layer1 {
            layers.retain(|(_, layer, _, _)| *layer != 1);
        }

        let origin = (map.header.u28 as i32, map.header.u2c as i32);
        let center = options.center.unwrap_or_else(|| match background.kind {
            BackgroundKind::Tga => tile_center(&map),
            BackgroundKind::Sprite => (
                origin.0 + background.width as i32 / 2,
                origin.1 + background.height as i32 / 2,
            ),
        });
        let crop_x = center.0 - origin.0 - options.width as i32 / 2;
        let crop_y = center.1 - origin.1 - options.height as i32 / 2;
        let crop = Crop {
            center_x: center.0,
            center_y: center.1,
            x: crop_x,
            y: crop_y,
            width: options.width,
            height: options.height,
        };
        let mut background_pixels = vec![0u8; (options.width * options.height * 4) as usize];
        for y in 0..options.height as i32 {
            for x in 0..options.width as i32 {
                let target = ((y as u32 * options.width + x as u32) * 4) as usize;
                let source_x = crop_x + x;
                let source_y = crop_y + y;
                if source_x >= 0
                    && source_y >= 0
                    && source_x < background.width as i32
                    && source_y < background.height as i32
                {
                    let source =
                        ((source_y as u32 * background.width + source_x as u32) * 4) as usize;
                    background_pixels[target..target + 4]
                        .copy_from_slice(&background.pixels[source..source + 4]);
                } else {
                    background_pixels[target..target + 4].copy_from_slice(&[18, 20, 24, 255]);
                }
            }
        }

        let mut draws = Vec::new();
        let mut layers_considered = 0usize;
        for (tile, layer, name, _raw) in layers {
            layers_considered += 1;
            let key = normalize_key(&name);
            let Some(matches) = basename.get(&key) else {
                missing.push((name, tile.x, tile.y, layer));
                continue;
            };
            if matches.len() > 1 {
                ambiguous.push((name.clone(), matches.len()));
            }
            let (archive, entry) = &matches[0];
            let cache_key = format!("{archive}:{}", normalize_key(&entry.name));
            let mut animation_key = None;
            let mut animation_frame = None;
            let mut decoded = None;
            if options.animate {
                if let Some(key) = animation_asset_key(&name) {
                    let ani = if let Some(ani) = ani_cache.get(&key) {
                        Some(ani.clone())
                    } else if let Some(data) = install.read_asset(&key)? {
                        match Ani::load(&data) {
                            Ok(ani) => {
                                let ani = Arc::new(ani);
                                ani_cache.insert(key.clone(), ani.clone());
                                Some(ani)
                            }
                            Err(_) => None,
                        }
                    } else {
                        None
                    };
                    if let Some(ani) = ani {
                        if !ani.frames.is_empty() {
                            animation_frames = animation_frames.max(ani.frame_count);
                            let index = options.animation_frame % ani.frames.len();
                            let frame = &ani.frames[index];
                            if frame.width > 0 && frame.height > 0 {
                                decoded = Some(DecodedSprite {
                                    width: frame.width,
                                    height: frame.height,
                                    pixels: frame.pixels.clone(),
                                });
                                animation_key = Some(key);
                                animation_frame = Some(index);
                            }
                        }
                    }
                }
            }
            let decoded = if let Some(decoded) = decoded {
                decoded
            } else if let Some(decoded) = cache.get(&cache_key) {
                decoded.clone()
            } else {
                let data = install.read_entry(*archive, entry)?;
                let sprite = Sprite::load(&data)?;
                let decoded = DecodedSprite {
                    width: sprite.width,
                    height: sprite.height,
                    pixels: Arc::new(sprite.pixels),
                };
                cache.insert(cache_key, decoded.clone());
                decoded
            };
            let width = decoded.width;
            let height = decoded.height;
            if width == 0 || height == 0 {
                continue;
            }
            let (world_x, world_y) = tile_world(&map, tile);
            let full_x = world_x - origin.0 - width as i32 / 2;
            let full_y = world_y - origin.1 - height as i32;
            let left = full_x - crop_x;
            let top = full_y - crop_y;
            let x0 = left.max(0);
            let y0 = top.max(0);
            let x1 = (left + width as i32).min(options.width as i32);
            let y1 = (top + height as i32).min(options.height as i32);
            if x0 >= x1 || y0 >= y1 {
                continue;
            }
            draws.push(Draw {
                order: 0,
                asset: entry.name.clone(),
                tile_x: tile.x,
                tile_y: tile.y,
                layer,
                world_x,
                world_y,
                source_x: (x0 - left) as u32,
                source_y: (y0 - top) as u32,
                source_width: (x1 - x0) as u32,
                source_height: (y1 - y0) as u32,
                dest_x: x0,
                dest_y: y0,
                width,
                height,
                animation: animation_key.clone(),
                animation_frame,
                pixels: decoded.pixels,
            });
            if animation_key.is_some() {
                animated_draws += 1;
            }
        }

        draws.sort_by(|a, b| {
            a.world_y
                .cmp(&b.world_y)
                .then_with(|| {
                    (a.world_x - a.width as i32 / 2).cmp(&(b.world_x - b.width as i32 / 2))
                })
                .then_with(|| a.asset.cmp(&b.asset))
                .then_with(|| a.tile_y.cmp(&b.tile_y))
                .then_with(|| a.tile_x.cmp(&b.tile_x))
                .then_with(|| a.layer.cmp(&b.layer))
        });
        for (order, draw) in draws.iter_mut().enumerate() {
            draw.order = order;
        }

        let mut pixels = background_pixels.clone();
        for draw in &draws {
            for y in 0..draw.source_height {
                for x in 0..draw.source_width {
                    let source =
                        (((draw.source_y + y) * draw.width + draw.source_x + x) * 4) as usize;
                    let alpha = draw.pixels[source + 3] as u32;
                    if alpha == 0 {
                        continue;
                    }
                    let target =
                        (((draw.dest_y + y as i32) * options.width as i32 + draw.dest_x + x as i32)
                            * 4) as usize;
                    if alpha == 255 {
                        pixels[target..target + 3]
                            .copy_from_slice(&draw.pixels[source..source + 3]);
                    } else {
                        for channel in 0..3 {
                            let source_value = draw.pixels[source + channel] as u32;
                            let target_value = pixels[target + channel] as u32;
                            pixels[target + channel] =
                                ((source_value * alpha + target_value * (255 - alpha) + 127) / 255)
                                    as u8;
                        }
                    }
                }
            }
        }

        Ok(Self {
            map_path: map_path.display().to_string(),
            background_key: background.key,
            background_kind: background.kind,
            floor_key,
            background_width: background.width,
            background_height: background.height,
            background_origin: origin,
            crop,
            grid_w: map.header.grid_w,
            grid_h: map.header.grid_h,
            view_w: map.header.view_w,
            view_h: map.header.view_h,
            tiles_present: map.tiles.len(),
            layers_considered,
            animation_frame: options.animation_frame,
            animation_frames,
            animated_draws,
            draws,
            missing,
            ambiguous,
            background_crop: background_pixels,
            pixels,
        })
    }

    pub fn write_png(&self, path: impl AsRef<Path>) -> Result<()> {
        write_rgba_png(path, self.crop.width, self.crop.height, &self.pixels)
    }

    pub fn draw_list_json(&self) -> String {
        let mut out = String::new();
        out.push_str("{\n");
        out.push_str(&format!("  \"map\": \"{}\",\n", escape(&self.map_path)));
        out.push_str(&format!(
            "  \"background\": \"{}\",\n  \"background_kind\": \"{}\",\n",
            escape(&self.background_key),
            self.background_kind.label()
        ));
        out.push_str(&format!(
            "  \"floor\": {},\n",
            self.floor_key
                .as_ref()
                .map(|key| format!("\"{}\"", escape(key)))
                .unwrap_or_else(|| "null".into())
        ));
        out.push_str(&format!(
            "  \"background_size\": [{}, {}],\n",
            self.background_width, self.background_height
        ));
        out.push_str(&format!(
            "  \"background_origin\": [{}, {}],\n",
            self.background_origin.0, self.background_origin.1
        ));
        out.push_str(&format!(
            "  \"crop\": {{\"center\": [{}, {}], \"origin\": [{}, {}], \"size\": [{}, {}]}},\n",
            self.crop.center_x,
            self.crop.center_y,
            self.crop.x,
            self.crop.y,
            self.crop.width,
            self.crop.height
        ));
        out.push_str(&format!(
            "  \"grid\": [{}, {}],\n  \"view\": [{}, {}],\n",
            self.grid_w, self.grid_h, self.view_w, self.view_h
        ));
        out.push_str(&format!(
            "  \"tiles_present\": {},\n  \"layers_considered\": {},\n  \"draws\": {},\n",
            self.tiles_present,
            self.layers_considered,
            self.draws.len()
        ));
        out.push_str(&format!(
            "  \"animation_frame\": {},\n  \"animation_frames\": {},\n  \"animated_draws\": {},\n",
            self.animation_frame, self.animation_frames, self.animated_draws
        ));
        out.push_str("  \"missing\": [");
        for (index, (name, x, y, layer)) in self.missing.iter().enumerate() {
            if index > 0 {
                out.push_str(", ");
            }
            out.push_str(&format!(
                "{{\"name\": \"{}\", \"tile\": [{x}, {y}], \"layer\": {layer}}}",
                escape(name)
            ));
        }
        out.push_str("],\n  \"ambiguous\": [");
        for (index, (name, count)) in self.ambiguous.iter().enumerate() {
            if index > 0 {
                out.push_str(", ");
            }
            out.push_str(&format!(
                "{{\"name\": \"{}\", \"matches\": {count}}}",
                escape(name)
            ));
        }
        out.push_str("],\n  \"ordered_draws\": [\n");
        for (index, draw) in self.draws.iter().enumerate() {
            out.push_str(&format!(
                "    {{\"order\": {}, \"asset\": \"{}\", \"tile\": [{}, {}], \"layer\": {}, \"world\": [{}, {}], \"source\": [{}, {}, {}, {}], \"dest\": [{}, {}, {}, {}], \"animation\": {}, \"frame\": {}}}{}\n",
                draw.order,
                escape(&draw.asset),
                draw.tile_x,
                draw.tile_y,
                draw.layer,
                draw.world_x,
                draw.world_y,
                draw.source_x,
                draw.source_y,
                draw.source_width,
                draw.source_height,
                draw.dest_x,
                draw.dest_y,
                draw.source_width,
                draw.source_height,
                draw.animation
                    .as_ref()
                    .map(|name| format!("\"{}\"", escape(name)))
                    .unwrap_or_else(|| "null".into()),
                draw.animation_frame
                    .map(|frame| frame.to_string())
                    .unwrap_or_else(|| "null".into()),
                if index + 1 == self.draws.len() { "" } else { "," }
            ));
        }
        out.push_str("  ]\n}\n");
        out
    }

    pub fn pixel(&self, x: u32, y: u32) -> [u8; 4] {
        let offset = ((y * self.crop.width + x) * 4) as usize;
        [
            self.pixels[offset],
            self.pixels[offset + 1],
            self.pixels[offset + 2],
            self.pixels[offset + 3],
        ]
    }

    pub fn pixel_hash(&self) -> u64 {
        let mut hash = 0xcbf29ce484222325u64;
        for byte in &self.pixels {
            hash ^= *byte as u64;
            hash = hash.wrapping_mul(0x100000001b3);
        }
        hash
    }
}

fn patch_branch_floor(
    install: &mut GameInstall,
    background: &mut LoadedBackground,
    map_path: &Path,
) -> Result<Option<String>> {
    if background.kind != BackgroundKind::Sprite {
        return Ok(None);
    }
    let mut min_x = u32::MAX;
    let mut min_y = u32::MAX;
    let mut max_x = 0u32;
    let mut max_y = 0u32;
    for y in 0..background.height {
        for x in 0..background.width {
            let offset = ((y * background.width + x) * 4 + 3) as usize;
            if background.pixels[offset] == 0 {
                min_x = min_x.min(x);
                min_y = min_y.min(y);
                max_x = max_x.max(x);
                max_y = max_y.max(y);
            }
        }
    }
    if min_x == u32::MAX {
        return Ok(None);
    }
    let box_width = max_x - min_x + 1;
    let box_height = max_y - min_y + 1;

    let mut floor_key = None;
    if let Some(key) = branch_floor_key(map_path) {
        if let Some(data) = install.read_asset(&key)? {
            let floor = Sprite::load(&data)?;
            if floor.width > 0 && floor.height > 0 {
                let actual_key = install
                    .find_asset(&key)
                    .map(|(_, entry)| entry.name)
                    .unwrap_or_else(|| key.clone());
                let offset_x = min_x as i32 + (box_width as i32 - floor.width as i32) / 2;
                let offset_y = min_y as i32 + (box_height as i32 - floor.height as i32) / 2;
                for y in 0..floor.height {
                    for x in 0..floor.width {
                        let source = ((y * floor.width + x) * 4) as usize;
                        let alpha = floor.pixels[source + 3] as u32;
                        if alpha == 0 {
                            continue;
                        }
                        let target_x = offset_x + x as i32;
                        let target_y = offset_y + y as i32;
                        if target_x < 0
                            || target_y < 0
                            || target_x >= background.width as i32
                            || target_y >= background.height as i32
                        {
                            continue;
                        }
                        let target =
                            ((target_y as u32 * background.width + target_x as u32) * 4) as usize;
                        if alpha == 255 {
                            background.pixels[target..target + 3]
                                .copy_from_slice(&floor.pixels[source..source + 3]);
                            background.pixels[target + 3] = 255;
                        } else {
                            let target_alpha = background.pixels[target + 3] as u32;
                            let out_alpha = alpha + target_alpha * (255 - alpha) / 255;
                            for channel in 0..3 {
                                let source_value = floor.pixels[source + channel] as u32;
                                let target_value = background.pixels[target + channel] as u32;
                                background.pixels[target + channel] = ((source_value * alpha
                                    + target_value * target_alpha * (255 - alpha) / 255)
                                    / out_alpha.max(1))
                                    as u8;
                            }
                            background.pixels[target + 3] = out_alpha as u8;
                        }
                    }
                }
                floor_key = Some(actual_key);
            }
        }
    }

    // Branch backgrounds are alpha cut-outs for the floor. If a matching
    // floor sprite is unavailable, keep the window presentation opaque rather
    // than showing black through the transparent diamond.
    for pixel in background.pixels.chunks_exact_mut(4) {
        if pixel[3] == 0 {
            pixel.copy_from_slice(&[235, 235, 235, 255]);
        }
    }
    Ok(floor_key)
}

fn branch_floor_key(map_path: &Path) -> Option<String> {
    let stem = map_path
        .file_stem()
        .and_then(|stem| stem.to_str())
        .unwrap_or_default()
        .to_ascii_lowercase();
    let parts = stem.split('_').collect::<Vec<_>>();
    let (style, size) = if parts.len() == 4 && parts[0] == "iso" && parts[1] == "filiale" {
        (parts[2], parts[3])
    } else {
        return None;
    };
    Some(format!(
        "isodaten\\sprites\\filiale_{size}_boden{style}00.spr"
    ))
}

struct LoadedBackground {
    key: String,
    kind: BackgroundKind,
    width: u32,
    height: u32,
    pixels: Vec<u8>,
}

fn load_background(
    install: &mut GameInstall,
    map: &IsoMap,
    map_path: &Path,
    override_key: Option<&str>,
) -> Result<LoadedBackground> {
    let mut candidates = Vec::new();
    let mut seen = HashSet::new();
    let mut push = |candidate: String| {
        if !candidate.is_empty() && seen.insert(candidate.clone()) {
            candidates.push(candidate);
        }
    };
    if let Some(key) = override_key {
        push(key.to_string());
    } else {
        let map_stem = map_path
            .file_stem()
            .and_then(|stem| stem.to_str())
            .unwrap_or("ber")
            .to_ascii_lowercase();
        push(format!("backgrounds\\{map_stem}.tga"));
        let header_stem = map
            .header
            .background
            .rsplit_once('.')
            .map(|(stem, _)| stem)
            .unwrap_or(&map.header.background)
            .to_ascii_lowercase();
        if !header_stem.is_empty() {
            push(format!("backgrounds\\{header_stem}.tga"));
            push(format!("pictures\\{header_stem}.tga"));
            push(format!("isodaten\\sprites\\{header_stem}.spr"));
            if let Some(reordered) = reorder_filiale_background(&header_stem) {
                push(format!("isodaten\\sprites\\{reordered}.spr"));
            }
        }
    }

    for candidate in candidates {
        let Some(data) = install.read_asset(&candidate)? else {
            continue;
        };
        let key = install
            .find_asset(&candidate)
            .map(|(_, entry)| entry.name)
            .unwrap_or_else(|| candidate.clone());
        let lower = key.to_ascii_lowercase();
        if lower.ends_with(".tga") {
            let image = TgaImage::load(&data)?;
            return Ok(LoadedBackground {
                key,
                kind: BackgroundKind::Tga,
                width: image.width,
                height: image.height,
                pixels: image.pixels,
            });
        }
        if lower.ends_with(".spr") {
            let sprite = Sprite::load(&data)?;
            if sprite.width == 0 || sprite.height == 0 {
                continue;
            }
            return Ok(LoadedBackground {
                key,
                kind: BackgroundKind::Sprite,
                width: sprite.width,
                height: sprite.height,
                pixels: sprite.pixels,
            });
        }
    }
    Err(SceneError::MissingBackground(format!(
        "no background for {}",
        map_path.display()
    )))
}

fn reorder_filiale_background(stem: &str) -> Option<String> {
    let parts = stem.split('_').collect::<Vec<_>>();
    if parts.len() == 4 && parts[0] == "filiale" && parts[3] == "back" {
        return Some(format!("filiale_{}_{}_back", parts[2], parts[1]));
    }
    None
}

pub fn write_rgba_png(
    path: impl AsRef<Path>,
    width: u32,
    height: u32,
    pixels: &[u8],
) -> Result<()> {
    let file = File::create(path)?;
    let mut encoder = png::Encoder::new(file, width, height);
    encoder.set_color(png::ColorType::Rgba);
    encoder.set_depth(png::BitDepth::Eight);
    let mut writer = encoder.write_header()?;
    writer.write_image_data(pixels)?;
    Ok(())
}

fn animation_asset_key(sprite_name: &str) -> Option<String> {
    let lower = sprite_name.to_ascii_lowercase();
    let stem = lower.strip_suffix(".spr")?;
    if !stem.starts_with("b_allee_") {
        return None;
    }
    Some(format!("isodaten\\anims\\{stem}-{stem}.ani"))
}

fn tile_center(map: &IsoMap) -> (i32, i32) {
    let mut min_x = i32::MAX;
    let mut max_x = i32::MIN;
    let mut min_y = i32::MAX;
    let mut max_y = i32::MIN;
    for tile in &map.tiles {
        if tile.layer1.is_none() && tile.layer2.is_none() {
            continue;
        }
        let (x, y) = tile_world(map, tile);
        min_x = min_x.min(x);
        max_x = max_x.max(x);
        min_y = min_y.min(y);
        max_y = max_y.max(y);
    }
    if min_x == i32::MAX {
        (map.header.pixel_w as i32 / 2, map.header.pixel_h as i32 / 2)
    } else {
        ((min_x + max_x) / 2, (min_y + max_y) / 2)
    }
}

pub fn tile_world(map: &IsoMap, tile: &IsoTile) -> (i32, i32) {
    let x =
        (map.header.grid_h as i32 - tile.y as i32 + tile.x as i32) * map.header.view_w as i32 / 2;
    let y = (tile.x as i32 + tile.y as i32) * map.header.view_h as i32 / 2;
    (x, y)
}

fn sprite_index(install: &GameInstall) -> BTreeMap<String, Vec<(usize, pc2_assets::PakEntry)>> {
    let mut index: BTreeMap<String, Vec<(usize, pc2_assets::PakEntry)>> = BTreeMap::new();
    for (archive_index, archive) in install.archives.iter().enumerate() {
        for entry in &archive.entries {
            if !entry.name.to_ascii_lowercase().ends_with(".spr") {
                continue;
            }
            let basename = entry
                .name
                .rsplit(['\\', '/'])
                .next()
                .unwrap_or(&entry.name)
                .to_ascii_lowercase();
            index
                .entry(basename)
                .or_default()
                .push((archive_index, entry.clone()));
        }
    }
    index
}

#[derive(Clone, Debug)]
struct DecodedSprite {
    width: u32,
    height: u32,
    pixels: Arc<Vec<u8>>,
}

fn escape(value: &str) -> String {
    let mut out = String::with_capacity(value.len());
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

#[cfg(test)]
mod tests {
    use super::*;
    use std::path::{Path, PathBuf};

    fn install_root() -> PathBuf {
        Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("game")
    }

    fn berlin_scene() -> Option<Scene> {
        let root = install_root();
        if !root.join("Isokarten").join("Ber.iso").is_file() {
            return None;
        }
        let mut install = GameInstall::open(&root).unwrap();
        Some(
            Scene::build(
                &mut install,
                root.join("Isokarten").join("Ber.iso"),
                &SceneOptions::default(),
            )
            .unwrap(),
        )
    }

    fn fnv1a(bytes: &[u8]) -> u64 {
        let mut hash = 0xcbf29ce484222325u64;
        for byte in bytes {
            hash ^= *byte as u64;
            hash = hash.wrapping_mul(0x100000001b3);
        }
        hash
    }

    #[test]
    fn projection_matches_loader_cell_coordinates() {
        let mut install = GameInstall::open(install_root()).unwrap();
        let map = IsoMap::load(install_root().join("Isokarten").join("Ber.iso")).unwrap();
        assert_eq!((map.header.grid_w, map.header.grid_h), (164, 164));
        assert_eq!((map.header.view_w, map.header.view_h), (64, 32));
        let tile = |x, y| IsoTile {
            index: 0,
            x,
            y,
            flags: 0,
            layer1_raw: u32::MAX,
            layer2_raw: u32::MAX,
            layer1: None,
            layer2: None,
        };
        assert_eq!(tile_world(&map, &tile(0, 0)), (5248, 0));
        assert_eq!(tile_world(&map, &tile(1, 0)), (5280, 16));
        assert_eq!(tile_world(&map, &tile(0, 1)), (5216, 16));
        let _ = &mut install;
    }

    #[test]
    fn berlin_crop_is_deterministic_and_complete() {
        let Some(scene) = berlin_scene() else {
            return;
        };
        assert_eq!(scene.tiles_present, 2166);
        assert_eq!(scene.layers_considered, 1861);
        assert_eq!(scene.draws.len(), 125);
        assert!(scene.missing.is_empty(), "{:?}", scene.missing);
        assert!(scene.ambiguous.is_empty());
        assert_eq!(scene.crop.center_x, 5056);
        assert_eq!(scene.crop.center_y, 2464);
        assert_eq!(scene.crop.x, 1872);
        assert_eq!(scene.crop.y, 820);
        assert_eq!(scene.pixels.len(), 800 * 600 * 4);
        assert_eq!(scene.pixel_hash(), 0x8bde_36a2_6c5c_0ff0);

        let first = scene.draw_list_json();
        let Some(second) = berlin_scene() else {
            return;
        };
        assert_eq!(first, second.draw_list_json());
    }

    #[test]
    fn berlin_crop_has_foreground_occlusion() {
        let Some(scene) = berlin_scene() else {
            return;
        };
        for later in scene.draws.iter().rev() {
            for y in 0..later.source_height {
                for x in 0..later.source_width {
                    let source =
                        (((later.source_y + y) * later.width + later.source_x + x) * 4) as usize;
                    if later.pixels[source + 3] != 255 {
                        continue;
                    }
                    let px = later.dest_x + x as i32;
                    let py = later.dest_y + y as i32;
                    let covered_earlier = scene.draws.iter().any(|earlier| {
                        if earlier.order >= later.order
                            || px < earlier.dest_x
                            || py < earlier.dest_y
                            || px >= earlier.dest_x + earlier.source_width as i32
                            || py >= earlier.dest_y + earlier.source_height as i32
                        {
                            return false;
                        }
                        let sx = earlier.source_x + (px - earlier.dest_x) as u32;
                        let sy = earlier.source_y + (py - earlier.dest_y) as u32;
                        let index = ((sy * earlier.width + sx) * 4 + 3) as usize;
                        earlier.pixels[index] != 0
                    });
                    if covered_earlier {
                        assert_eq!(
                            scene.pixel(px as u32, py as u32),
                            [
                                later.pixels[source],
                                later.pixels[source + 1],
                                later.pixels[source + 2],
                                255
                            ]
                        );
                        return;
                    }
                }
            }
        }
        panic!("crop has no foreground occlusion");
    }

    #[test]
    fn tree_sway_animation_changes_frames() {
        let root = install_root();
        let path = root.join("Isokarten").join("Ber.iso");
        if !path.is_file() {
            return;
        }
        let mut install = GameInstall::open(&root).unwrap();
        let options = SceneOptions {
            animate: true,
            animation_frame: 0,
            ..SceneOptions::default()
        };
        let first = Scene::build(&mut install, &path, &options).unwrap();
        assert_eq!(first.animation_frames, 12);
        assert_eq!(first.animated_draws, 14);
        assert_eq!(first.draws.len(), 125);
        assert_eq!(first.pixel_hash(), 0xb864_69a2_67e9_de92);
        let json = first.draw_list_json();
        assert!(json.contains("b_allee_a-b_allee_a.ani"));
        assert!(json.contains("\"frame\": 0"));

        let options = SceneOptions {
            animate: true,
            animation_frame: 1,
            ..SceneOptions::default()
        };
        let second = Scene::build(&mut install, &path, &options).unwrap();
        assert_eq!(second.animated_draws, 14);
        assert_eq!(second.pixel_hash(), 0xdd41_d009_408d_354d);
        assert_ne!(first.pixels, second.pixels);
    }

    #[test]
    fn branch_room_uses_sprite_background() {
        let root = install_root();
        let path = root.join("Isokarten").join("Iso_Filiale_einf_klein.iso");
        if !path.is_file() {
            return;
        }
        let mut install = GameInstall::open(&root).unwrap();
        let scene = Scene::build(&mut install, &path, &SceneOptions::default()).unwrap();
        assert_eq!(scene.background_kind, BackgroundKind::Sprite);
        assert_eq!(
            scene.background_key,
            "isodaten\\sprites\\filiale_klein_einf_back.spr"
        );
        assert_eq!(
            scene.floor_key.as_deref(),
            Some("isodaten\\sprites\\filiale_klein_bodeneinf00.spr")
        );
        assert_eq!(
            (scene.background_width, scene.background_height),
            (799, 551)
        );
        assert_eq!((scene.grid_w, scene.grid_h), (260, 260));
        assert_eq!((scene.view_w, scene.view_h), (16, 8));
        assert_eq!(scene.tiles_present, 40);
        assert_eq!(scene.layers_considered, 40);
        assert_eq!(scene.draws.len(), 39);
        assert!(scene.missing.is_empty());
        assert!(scene.ambiguous.is_empty());
        assert_eq!(scene.pixel_hash(), 0xd89d_2e0a_fb9d_a048);
    }

    #[test]
    fn all_branch_maps_resolve_their_backgrounds() {
        let root = install_root();
        let maps = root.join("Isokarten");
        if !maps.is_dir() {
            return;
        }
        let mut install = GameInstall::open(&root).unwrap();
        let mut count = 0;
        for entry in std::fs::read_dir(&maps).unwrap() {
            let path = entry.unwrap().path();
            let name = path
                .file_name()
                .and_then(|name| name.to_str())
                .unwrap_or("");
            if !name.starts_with("Iso_Filiale_") || !name.ends_with(".iso") {
                continue;
            }
            let scene = Scene::build(&mut install, &path, &SceneOptions::default()).unwrap();
            assert_eq!(scene.background_kind, BackgroundKind::Sprite, "{name}");
            assert!(scene.floor_key.is_some(), "{name}");
            assert!(scene.missing.is_empty(), "{name}");
            assert!(scene.ambiguous.is_empty(), "{name}");
            assert!(!scene.draws.is_empty(), "{name}");
            count += 1;
        }
        assert_eq!(count, 15);
    }

    #[test]
    fn eight_and_sixteen_bit_samples_decode() {
        let root = install_root();
        if !root.is_dir() {
            return;
        }
        let mut install = GameInstall::open(&root).unwrap();
        let eight = install
            .read_asset("isodaten\\sprites\\b_laub_b.spr")
            .unwrap()
            .expect("8bpp tree");
        let tree = Sprite::load(&eight).unwrap();
        assert_eq!((tree.width, tree.height, tree.bpp), (144, 106, 8));
        assert_eq!(fnv1a(&tree.pixels), 0x8c14_4b3b_f0b9_4e51);
        assert!(tree.pixels.chunks_exact(4).any(|pixel| pixel[3] == 255));
        assert!(tree
            .pixels
            .chunks_exact(4)
            .any(|pixel| pixel[1] > 64 && pixel[0] < 80));

        let sixteen = install
            .read_asset("sprites\\pb07__01.spr")
            .unwrap()
            .expect("16bpp sample");
        let sample = Sprite::load(&sixteen).unwrap();
        assert_eq!((sample.width, sample.height, sample.bpp), (29, 29, 16));
        assert_eq!(sample.flags & 0x10, 0x10);
        assert_eq!(fnv1a(&sample.pixels), 0x4b1d_a7c6_da62_6011);
        assert!(sample.pixels.chunks_exact(4).any(|pixel| pixel[3] == 255));
    }
}
