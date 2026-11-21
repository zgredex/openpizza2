//! Faithful recipe-editor composition from the shipped `SUBMENUE` and
//! `R_*` sprites. The window is the original 0x231,0xda submenu position,
//! with the original recipe tabs and ingredient slots.

use pc2_assets::{Fnt, GameInstall, Sprite};

pub struct RecipeScreen {
    background: Sprite,
    tabs: Vec<(Sprite, i32, i32)>,
    slot: Sprite,
    font: Fnt,
}

impl RecipeScreen {
    pub fn load(install: &mut GameInstall) -> Result<Self, String> {
        let background = sprite(install, "sprites\\submenue.spr")?;
        let slot = sprite(install, "sprites\\zutabpb__00.spr")?;
        let mut tabs = Vec::new();
        for (name, y) in [
            ("r_info__00.spr", 3),
            ("r_neurezept__00.spr", 0x21),
            ("r_zutaten__00.spr", 0x3f),
            ("r_speisekarte__00.spr", 0x5d),
            ("r_rezautomatik__00.spr", 0x7b),
            ("r_infowett__00.spr", 0xb7),
            ("r_neurezeptwett__00.spr", 0xd5),
            ("r_zutatenwett__00.spr", 0xf3),
            ("r_lupe__00.spr", 0x111),
        ] {
            tabs.push((sprite(install, &format!("sprites\\{name}"))?, 568, 248 + y));
        }
        let font_data = install
            .read_asset("fonts\\verdana8.fnt")
            .map_err(|error| error.to_string())?
            .ok_or("missing fonts\\verdana8.fnt")?;
        let font = Fnt::load(&font_data).map_err(|error| error.to_string())?;
        Ok(Self {
            background,
            tabs,
            slot,
            font,
        })
    }

    pub fn render(
        &self,
        frame: &mut [u8],
        width: u32,
        height: u32,
        tomato: u32,
        cheese: u32,
        price: f64,
        on_menu: bool,
        saved: bool,
    ) {
        blend(frame, width, height, &self.background, 561, 218);
        for (sprite, x, y) in &self.tabs {
            blend(frame, width, height, sprite, *x, *y);
        }
        for row in 0..3 {
            for column in 0..3 {
                blend(
                    frame,
                    width,
                    height,
                    &self.slot,
                    561 + 62 + column * 48,
                    218 + 68 + row * 38,
                );
            }
        }
        let mut text = |text: &str, x: i32, y: i32| {
            let _ = self
                .font
                .draw_text(frame, width, height, x, y, text, [0, 0, 0]);
        };
        text("CREATE RECIPE", 605, 223);
        text(&format!("TOMATO {tomato}"), 624, 292);
        text(&format!("CHEESE {cheese}"), 672, 292);
        text(&format!("PRICE {price:.2}"), 616, 445);
        text(&format!("WEIGHT {}", tomato + cheese), 616, 456);
        text(if on_menu { "ON MENU" } else { "NOT ON MENU" }, 616, 470);
        text(if saved { "SAVED" } else { "NEW" }, 616, 484);
    }
}

fn sprite(install: &mut GameInstall, name: &str) -> Result<Sprite, String> {
    let data = install
        .read_asset(name)
        .map_err(|error| error.to_string())?
        .ok_or_else(|| format!("missing {name}"))?;
    Sprite::load(&data).map_err(|error| format!("{name}: {error}"))
}

fn blend(frame: &mut [u8], width: u32, height: u32, sprite: &Sprite, x: i32, y: i32) {
    for row in 0..sprite.height as i32 {
        for column in 0..sprite.width as i32 {
            let dx = x + column;
            let dy = y + row;
            if dx < 0 || dy < 0 || dx >= width as i32 || dy >= height as i32 {
                continue;
            }
            let source = ((row as u32 * sprite.width + column as u32) * 4) as usize;
            let alpha = sprite.pixels[source + 3] as u32;
            if alpha == 0 {
                continue;
            }
            let target = ((dy as u32 * width + dx as u32) * 4) as usize;
            for channel in 0..3 {
                let src = sprite.pixels[source + channel] as u32;
                let dst = frame[target + channel] as u32;
                frame[target + channel] = ((src * alpha + dst * (255 - alpha)) / 255) as u8;
            }
            frame[target + 3] = 255;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::path::Path;

    #[test]
    fn original_recipe_assets_render() {
        let root = Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("game");
        if !root.is_dir() {
            return;
        }
        let mut install = GameInstall::open(root).unwrap();
        let screen = RecipeScreen::load(&mut install).unwrap();
        let mut frame = vec![0u8; 800 * 600 * 4];
        for pixel in frame.chunks_exact_mut(4) {
            pixel[3] = 255;
        }
        screen.render(&mut frame, 800, 600, 30, 20, 15.0, true, true);
        assert!(frame.chunks_exact(4).any(|pixel| pixel[0] > 0));
        pc2_scene::write_rgba_png(
            Path::new("/tmp/opencode/original_recipe_screen.png"),
            800,
            600,
            &frame,
        )
        .unwrap();
    }
}
