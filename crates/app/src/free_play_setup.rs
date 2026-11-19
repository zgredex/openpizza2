//! Reconstruction of `Screen_FreePlaySetup` (`0x472da0`, screen state `0x18`).
//!
//! The original dispatcher sends a free game here after Character Select and a
//! campaign to `Screen_MissionBriefing` (`0x474df0`). The screen's Start handler
//! (`0x4cd33d..0x4cd4cc`) commits the selected city record, population, game
//! length, difficulty and opponent slots before `Game_InitScenario`
//! (`0x481d90`) builds the world.
//!
//! This reconstruction models the traced Berlin defaults for one city. Back is
//! control `0x4e2` at 595,509 and Start is `0x4e3` at 595,550, matching the
//! original bottom-button layout.

use crate::widgets::PanelTiles;
use pc2_assets::{Fnt, GameInstall, TgaImage};
use pc2_sim::{CharacterProfile, GameMode, ScenarioSetup};

pub const WIDTH: u32 = 800;
pub const HEIGHT: u32 = 600;
const BUTTON_X: i32 = 595;
const BUTTON_WIDTH: u32 = 204;
const BUTTON_HEIGHT: u32 = 38;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Action {
    Back,
    Start,
}

impl Action {
    pub fn control_id(self) -> u16 {
        match self {
            Self::Back => 0x4e2,
            Self::Start => 0x4e3,
        }
    }

    pub fn label(self) -> &'static str {
        match self {
            Self::Back => "To main menu",
            Self::Start => "Start game",
        }
    }
}

#[derive(Clone, Debug)]
pub struct SetupButton {
    pub action: Action,
    pub x: i32,
    pub y: i32,
    pub width: u32,
    pub height: u32,
}

impl SetupButton {
    fn contains(&self, x: i32, y: i32) -> bool {
        x >= self.x
            && y >= self.y
            && x < self.x + self.width as i32
            && y < self.y + self.height as i32
    }
}

#[derive(Clone, Debug)]
pub struct FreePlaySetup {
    background: Vec<u8>,
    font: Fnt,
    panel: PanelTiles,
    profile: CharacterProfile,
    scenario: ScenarioSetup,
    buttons: [SetupButton; 2],
    selected: usize,
    hover: Option<usize>,
    status: Option<String>,
}

impl FreePlaySetup {
    pub fn load(
        install: &mut GameInstall,
        profile: CharacterProfile,
        scenario: ScenarioSetup,
    ) -> Result<Self, String> {
        let data = install
            .read_asset("pictures\\pe_freies_spiel.tga")
            .map_err(|error| format!("cannot read free play background: {error}"))?
            .ok_or_else(|| "missing pictures\\pe_freies_spiel.tga".to_string())?;
        let background =
            TgaImage::load(&data).map_err(|error| format!("free play background: {error}"))?;
        if background.width != WIDTH || background.height != HEIGHT {
            return Err(format!(
                "free play background is {}x{}, expected {}x{}",
                background.width, background.height, WIDTH, HEIGHT
            ));
        }
        let font_data = install
            .read_asset("fonts\\timesfont.fnt")
            .map_err(|error| format!("cannot read free play font: {error}"))?
            .ok_or_else(|| "missing fonts\\timesfont.fnt".to_string())?;
        let font = Fnt::load(&font_data).map_err(|error| format!("free play font: {error}"))?;
        let panel = PanelTiles::load(install, "textpbtranspgelb")?;
        let buttons = [
            SetupButton {
                action: Action::Back,
                x: BUTTON_X,
                y: 509,
                width: BUTTON_WIDTH,
                height: BUTTON_HEIGHT,
            },
            SetupButton {
                action: Action::Start,
                x: BUTTON_X,
                y: 550,
                width: BUTTON_WIDTH,
                height: BUTTON_HEIGHT,
            },
        ];
        Ok(Self {
            background: background.pixels,
            font,
            panel,
            profile,
            scenario,
            buttons,
            selected: 1,
            hover: None,
            status: None,
        })
    }

    pub fn profile(&self) -> &CharacterProfile {
        &self.profile
    }

    pub fn scenario(&self) -> &ScenarioSetup {
        &self.scenario
    }

    pub fn buttons(&self) -> &[SetupButton] {
        &self.buttons
    }

    pub fn selected(&self) -> usize {
        self.selected
    }

    pub fn selected_action(&self) -> Action {
        self.buttons[self.selected].action
    }

    pub fn set_selected(&mut self, index: usize) {
        if index < self.buttons.len() {
            self.selected = index;
        }
    }

    pub fn select_next(&mut self) {
        self.selected = (self.selected + 1) % self.buttons.len();
        self.hover = None;
    }

    pub fn select_previous(&mut self) {
        self.selected = (self.selected + self.buttons.len() - 1) % self.buttons.len();
        self.hover = None;
    }

    pub fn set_hover(&mut self, position: Option<(i32, i32)>) {
        self.hover = position.and_then(|(x, y)| self.button_at(x, y));
    }

    pub fn button_at(&self, x: i32, y: i32) -> Option<usize> {
        self.buttons.iter().position(|button| button.contains(x, y))
    }

    pub fn set_status(&mut self, status: impl Into<String>) {
        self.status = Some(status.into());
    }

    pub fn activate(&mut self) -> Action {
        self.selected_action()
    }

    pub fn click_at(&mut self, x: i32, y: i32) -> (bool, Option<Action>) {
        let Some(index) = self.button_at(x, y) else {
            return (false, None);
        };
        self.selected = index;
        (true, Some(self.activate()))
    }

    fn visual_state(&self, index: usize) -> usize {
        usize::from(self.hover == Some(index) || self.hover.is_none() && index == self.selected)
    }

    fn draw_text(&self, frame: &mut [u8], x: i32, y: i32, text: &str) {
        let _ = self
            .font
            .draw_text(frame, WIDTH, HEIGHT, x + 1, y + 1, text, [255, 255, 255]);
        let _ = self
            .font
            .draw_text(frame, WIDTH, HEIGHT, x, y, text, [0, 0, 0]);
    }

    pub fn render(&self) -> Vec<u8> {
        let mut frame = self.background.clone();
        self.draw_text(&mut frame, 36, 34, "Free play setup");
        let capital = self.scenario.starting_capital(self.profile.difficulty);
        self.draw_text(
            &mut frame,
            36,
            70,
            &format!(
                "Player: {}",
                if self.profile.player_name.is_empty() {
                    "(unnamed)"
                } else {
                    &self.profile.player_name
                }
            ),
        );
        self.draw_text(
            &mut frame,
            36,
            94,
            &format!(
                "Enterprise: {}",
                if self.profile.enterprise_name.is_empty() {
                    "(unnamed)"
                } else {
                    &self.profile.enterprise_name
                }
            ),
        );
        let rows = [
            format!(
                "City: {} ({})     Map: {}",
                self.scenario.city_name,
                self.scenario.city_code.to_ascii_uppercase(),
                self.scenario.map_name
            ),
            format!(
                "Population: {}     Game length: {} years",
                self.scenario.population, self.scenario.game_length_years
            ),
            format!(
                "Difficulty: {}     Starting capital: {}",
                self.profile.difficulty, capital
            ),
            format!(
                "Opponents: {} / {} / {}",
                self.scenario.opponents[0], self.scenario.opponents[1], self.scenario.opponents[2]
            ),
        ];
        let mut y = 398;
        for row in &rows {
            self.draw_text(&mut frame, 36, y, row);
            y += 24;
        }
        for (index, button) in self.buttons.iter().enumerate() {
            let state = self.visual_state(index);
            self.panel.draw(
                &mut frame,
                WIDTH,
                HEIGHT,
                button.x,
                button.y,
                button.width,
                button.height,
                state,
            );
            let measured = self.font.measure(button.action.label());
            let text_x = button.x + (button.width as i32 - measured as i32) / 2;
            let text_y = button.y + (41 - self.font.line_height as i32) / 2;
            let _ = self.font.draw_text(
                &mut frame,
                WIDTH,
                HEIGHT,
                text_x,
                text_y,
                button.action.label(),
                [0, 0, 0],
            );
        }
        if let Some(status) = &self.status {
            self.draw_text(&mut frame, 36, 556, status);
        }
        frame
    }
}

pub fn default_profile() -> CharacterProfile {
    CharacterProfile::new(
        1,
        0,
        0,
        0,
        0,
        1,
        0,
        0,
        [0, -2, 0, -1, 1, 0],
        String::new(),
        String::new(),
    )
    .with_mode(GameMode::FreeGame)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn buttons_match_original_positions() {
        let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("game");
        if !root.is_dir() {
            return;
        }
        let mut game = GameInstall::open(root).expect("installation");
        let setup = FreePlaySetup::load(
            &mut game,
            default_profile(),
            ScenarioSetup::free_play_berlin(),
        )
        .expect("setup screen");
        assert_eq!(setup.buttons()[0].action, Action::Back);
        assert_eq!(setup.buttons()[0].action.control_id(), 0x4e2);
        assert_eq!((setup.buttons()[0].x, setup.buttons()[0].y), (595, 509));
        assert_eq!(setup.buttons()[1].action, Action::Start);
        assert_eq!(setup.buttons()[1].action.control_id(), 0x4e3);
        assert_eq!((setup.buttons()[1].x, setup.buttons()[1].y), (595, 550));
    }
}
