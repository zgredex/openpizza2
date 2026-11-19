//! Shared UI widgets recovered from the original interface code.

use pc2_assets::{GameInstall, Sprite};

#[derive(Clone, Debug)]
pub struct PanelTiles {
    tiles: Vec<Sprite>,
}

impl PanelTiles {
    /// Load one of the original 3x3 state sets, such as
    /// `textpbtranspgelb` or `textpbtranspgruen`.
    pub fn load(install: &mut GameInstall, base: &str) -> Result<Self, String> {
        let mut tiles = Vec::with_capacity(9);
        for index in 0..9 {
            let name = format!("sprites\\{base}_{index:02}.spr");
            let data = install
                .read_asset(&name)
                .map_err(|error| format!("cannot read {name}: {error}"))?
                .ok_or_else(|| format!("missing panel resource: {name}"))?;
            tiles.push(Sprite::load(&data).map_err(|error| format!("panel {name}: {error}"))?);
        }
        Ok(Self { tiles })
    }

    #[allow(clippy::too_many_arguments)]
    pub fn draw(
        &self,
        frame: &mut [u8],
        width: u32,
        height: u32,
        x: i32,
        y: i32,
        panel_width: u32,
        panel_height: u32,
        state: usize,
    ) {
        // The files are column-major: state 0 uses 0/3/6, state 1 uses 1/4/7,
        // and state 2 uses 2/5/8. The middle slice stretches horizontally.
        if state + 6 >= self.tiles.len() {
            return;
        }
        let left = &self.tiles[state];
        let middle = &self.tiles[state + 3];
        let right = &self.tiles[state + 6];
        let left_width = left.width.min(panel_width);
        let right_width = right.width.min(panel_width.saturating_sub(left_width));
        let middle_width = panel_width.saturating_sub(left_width + right_width);
        draw_sprite_scaled(frame, width, height, left, x, y, left_width, panel_height);
        draw_sprite_scaled(
            frame,
            width,
            height,
            middle,
            x + left_width as i32,
            y,
            middle_width,
            panel_height,
        );
        draw_sprite_scaled(
            frame,
            width,
            height,
            right,
            x + (panel_width - right_width) as i32,
            y,
            right_width,
            panel_height,
        );
    }
}

pub fn draw_sprite(frame: &mut [u8], width: u32, height: u32, sprite: &Sprite, x: i32, y: i32) {
    draw_sprite_scaled(
        frame,
        width,
        height,
        sprite,
        x,
        y,
        sprite.width,
        sprite.height,
    );
}

pub fn draw_sprite_scaled(
    frame: &mut [u8],
    width: u32,
    height: u32,
    sprite: &Sprite,
    x: i32,
    y: i32,
    target_width: u32,
    target_height: u32,
) {
    if sprite.width == 0 || sprite.height == 0 || target_width == 0 || target_height == 0 {
        return;
    }
    for ty in 0..target_height {
        let sy = (ty * sprite.height / target_height).min(sprite.height - 1);
        for tx in 0..target_width {
            let sx = (tx * sprite.width / target_width).min(sprite.width - 1);
            let source = ((sy * sprite.width + sx) * 4) as usize;
            let rgba = [
                sprite.pixels[source],
                sprite.pixels[source + 1],
                sprite.pixels[source + 2],
                sprite.pixels[source + 3],
            ];
            blend_pixel(frame, width, height, x + tx as i32, y + ty as i32, rgba);
        }
    }
}

pub fn blend_pixel(frame: &mut [u8], width: u32, height: u32, x: i32, y: i32, rgba: [u8; 4]) {
    if x < 0 || y < 0 || x >= width as i32 || y >= height as i32 {
        return;
    }
    let offset = ((y as u32 * width + x as u32) * 4) as usize;
    let alpha = rgba[3] as u32;
    if alpha == 0 {
        return;
    }
    for channel in 0..3 {
        let value = rgba[channel] as u32;
        let old = frame[offset + channel] as u32;
        frame[offset + channel] = ((value * alpha + old * (255 - alpha) + 127) / 255) as u8;
    }
    frame[offset + 3] = 255;
}
