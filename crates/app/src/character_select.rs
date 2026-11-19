//! Reconstruction of `Screen_CharacterSelect` (`0x46dbd0`).
//!
//! REA establishes the background, sprite placements, face compositor, text
//! controls and callback actions. The screen is entered from Start New Game /
//! Start Free Game.

use pc2_assets::{Fnt, GameInstall, Sprite, TgaImage};
use pc2_sim::{CharacterProfile, GameMode};

use crate::menu::load_labels;
use crate::widgets::{blend_pixel, draw_sprite, PanelTiles};

pub const WIDTH: u32 = 800;
pub const HEIGHT: u32 = 600;
const BUTTON_WIDTH: u32 = 204;
const BUTTON_HEIGHT: u32 = 38;
const FACE_COUNT: usize = 10;
const LOGO_COUNT: usize = 8;
const COLOR_COUNT: usize = 8;

const SELECT_PLAYER_TITLE: usize = 0x879;
const CHARACTERISTICS_TITLE: usize = 0x730;
const ENTERPRISES_TITLE: usize = 0x8a9;
const DIFFICULTY_TITLE: usize = 0x865;
const DIFFICULTY_EASY: usize = 0x7c4;
const DIFFICULTY_NAMES: usize = 0x3f4;
const PLAYER_NAME_LABEL: usize = 0x87b;
const ENTERPRISE_NAME_LABEL: usize = 0x8ab;
const HAIR_LABEL: usize = 0x797;
const EYES_LABEL: usize = 0x6ee;
const MOUTH_LABEL: usize = 0x812;
const CHIN_LABEL: usize = 0x7c5;
const BUYER_LABEL: usize = 0x735;
const GANGSTERS_LABEL: usize = 0x767;
const SPECIALIST_LABEL: usize = 0x74b;
const POLITICIANS_LABEL: usize = 0x836;
const SELLER_LABEL: usize = 0x8b4;
const GUARD_LABEL: usize = 0x8be;
const LOGO_LABEL: usize = 0x1b5;
const COLOR_LABEL: usize = 0x74c;
const BACK_LABEL: usize = 0x8dc;
const START_LABEL: usize = 0x877;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum CharacterSelectAction {
    Back,
    Start,
}

impl CharacterSelectAction {
    pub fn label(self) -> &'static str {
        match self {
            Self::Back => "To main menu",
            Self::Start => "Start game",
        }
    }

    pub fn control_id(self) -> u16 {
        match self {
            Self::Back => 0x434,
            Self::Start => 0x435,
        }
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Appearance {
    Hair,
    Eyes,
    Mouth,
    Head,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Field {
    Player,
    Enterprise,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum UiAction {
    Appearance(Appearance, i32),
    Attribute(usize, i32),
    Gender(usize),
    Logo(i32),
    Color(i32),
    Difficulty(i32),
    Focus(Field),
    Back,
    Start,
}

#[derive(Clone, Debug)]
struct HitRegion {
    x: i32,
    y: i32,
    width: u32,
    height: u32,
    action: UiAction,
}

impl HitRegion {
    fn contains(&self, x: i32, y: i32) -> bool {
        x >= self.x
            && y >= self.y
            && x < self.x + self.width as i32
            && y < self.y + self.height as i32
    }
}

#[derive(Clone, Debug)]
pub struct SelectButton {
    pub action: CharacterSelectAction,
    pub label: String,
    pub x: i32,
    pub y: i32,
    pub width: u32,
    pub height: u32,
    green: bool,
}

impl SelectButton {
    pub fn contains(&self, x: i32, y: i32) -> bool {
        x >= self.x
            && y >= self.y
            && x < self.x + self.width as i32
            && y < self.y + self.height as i32
    }
}

#[derive(Clone, Debug)]
struct FaceSet {
    head: Vec<Sprite>,
    eyes: Vec<Sprite>,
    hair: Vec<Sprite>,
    mouth: Vec<Sprite>,
}

#[derive(Clone, Debug)]
struct Faces {
    male: FaceSet,
    female: FaceSet,
}

#[derive(Clone, Debug)]
struct Sprites {
    pb22: Vec<Sprite>,
    pb24: Vec<Sprite>,
    pb26: Vec<Sprite>,
    pb27: Vec<Sprite>,
    photo_frame: Sprite,
    gender_m: Vec<Sprite>,
    gender_w: Vec<Sprite>,
    logo_window: Sprite,
    light_field: Vec<Sprite>,
    sliders: Vec<Sprite>,
}

#[derive(Clone, Debug)]
pub struct CharacterSelect {
    background: Vec<u8>,
    times: Fnt,
    times14: Fnt,
    verdana8: Fnt,
    labels: Vec<String>,
    sprites: Sprites,
    faces: Faces,
    playlogs: Vec<Vec<Sprite>>,
    yellow_panel: PanelTiles,
    green_panel: PanelTiles,
    buttons: Vec<SelectButton>,
    regions: Vec<HitRegion>,
    selected: usize,
    hover: Option<usize>,
    hover_region: Option<usize>,
    pressed_region: Option<usize>,
    interacted: bool,
    status: Option<String>,
    help: Option<String>,
    gender: usize,
    head: usize,
    eyes: usize,
    hair: usize,
    mouth: usize,
    logo: usize,
    color: usize,
    difficulty: usize,
    difficulty_touched: bool,
    attributes: [i32; 6],
    player_name: String,
    enterprise_name: String,
    focus: Option<Field>,
    mode: GameMode,
}

impl CharacterSelect {
    pub fn load(install: &mut GameInstall) -> Result<Self, String> {
        let background = TgaImage::load(&load_asset(install, "pictures\\pe_charakterauswahl.tga")?)
            .map_err(|error| format!("character-select background: {error}"))?;
        if background.width != WIDTH || background.height != HEIGHT {
            return Err(format!(
                "character-select background is {}x{}",
                background.width, background.height
            ));
        }
        let times = load_font(install, "fonts\\timesfont.fnt")?;
        let times14 = load_font(install, "fonts\\times14.fnt")?;
        let verdana8 = load_font(install, "fonts\\verdana8.fnt")?;
        let labels = load_labels(&install.root)?;
        let sprites = Sprites {
            pb22: load_sequence(install, "sprites\\pb22_%02d.spr", 3)?,
            pb24: load_sequence(install, "sprites\\pb24_%02d.spr", 3)?,
            pb26: load_sequence(install, "sprites\\pb26_%02d.spr", 3)?,
            pb27: load_sequence(install, "sprites\\pb27_%02d.spr", 3)?,
            photo_frame: load_sprite(install, "sprites\\fotorahmen00.spr")?,
            gender_m: load_sequence(install, "sprites\\geschlecht_m_%02d.spr", 3)?,
            gender_w: load_sequence(install, "sprites\\geschlecht_w_%02d.spr", 3)?,
            logo_window: load_sprite(install, "sprites\\logofenster.spr")?,
            light_field: load_sequence(install, "sprites\\leuchtfeld_00_%02d.spr", 3)?,
            sliders: load_sequence(install, "sprites\\sl02_%02d.spr", 9)?,
        };
        let faces = Faces {
            male: load_face_set(install, "m")?,
            female: load_face_set(install, "f")?,
        };
        let playlogs = load_playlogs(install)?;
        let yellow_panel = PanelTiles::load(install, "textpbtranspgelb")?;
        let green_panel = PanelTiles::load(install, "textpbtranspgruen")?;
        let mut screen = Self {
            background: background.pixels,
            times,
            times14,
            verdana8,
            labels,
            sprites,
            faces,
            playlogs,
            yellow_panel,
            green_panel,
            buttons: vec![
                SelectButton {
                    action: CharacterSelectAction::Back,
                    label: String::new(),
                    x: 595,
                    y: 509,
                    width: BUTTON_WIDTH,
                    height: BUTTON_HEIGHT,
                    green: false,
                },
                SelectButton {
                    action: CharacterSelectAction::Start,
                    label: String::new(),
                    x: 595,
                    y: 551,
                    width: BUTTON_WIDTH,
                    height: BUTTON_HEIGHT,
                    green: true,
                },
            ],
            regions: Vec::new(),
            selected: 0,
            hover: None,
            hover_region: None,
            pressed_region: None,
            interacted: false,
            status: None,
            help: None,
            gender: 1,
            head: 0,
            eyes: 0,
            hair: 0,
            mouth: 0,
            logo: 1,
            color: 0,
            difficulty: 0,
            difficulty_touched: false,
            attributes: [0, -2, 0, -1, 1, 0],
            player_name: String::new(),
            enterprise_name: String::new(),
            focus: None,
            mode: GameMode::Campaign,
        };
        screen.buttons[0].label = label(&screen.labels, BACK_LABEL)?.to_string();
        screen.buttons[1].label = label(&screen.labels, START_LABEL)?.to_string();
        screen.build_regions();
        Ok(screen)
    }

    fn build_regions(&mut self) {
        let mut regions = Vec::new();
        for (feature, y) in [
            (Appearance::Hair, 140),
            (Appearance::Eyes, 172),
            (Appearance::Mouth, 206),
            (Appearance::Head, 239),
        ] {
            regions.push(HitRegion {
                x: 66,
                y,
                width: 29,
                height: 25,
                action: UiAction::Appearance(feature, -1),
            });
            regions.push(HitRegion {
                x: 173,
                y,
                width: 29,
                height: 25,
                action: UiAction::Appearance(feature, 1),
            });
        }
        for (index, y) in [140, 173, 207, 239, 273, 305].into_iter().enumerate() {
            regions.push(HitRegion {
                x: 299,
                y,
                width: 29,
                height: 25,
                action: UiAction::Attribute(index, -1),
            });
            regions.push(HitRegion {
                x: 455,
                y,
                width: 29,
                height: 25,
                action: UiAction::Attribute(index, 1),
            });
        }
        for (y, action) in [(208, 0), (239, 1)] {
            regions.push(HitRegion {
                x: 630,
                y,
                width: 29,
                height: 25,
                action: if action == 0 {
                    UiAction::Logo(-1)
                } else {
                    UiAction::Color(-1)
                },
            });
            regions.push(HitRegion {
                x: 737,
                y,
                width: 29,
                height: 25,
                action: if action == 0 {
                    UiAction::Logo(1)
                } else {
                    UiAction::Color(1)
                },
            });
        }
        regions.push(HitRegion {
            x: 71,
            y: 74,
            width: 27,
            height: 41,
            action: UiAction::Gender(1),
        });
        regions.push(HitRegion {
            x: 174,
            y: 71,
            width: 31,
            height: 31,
            action: UiAction::Gender(0),
        });
        regions.push(HitRegion {
            x: 617,
            y: 455,
            width: 175,
            height: 22,
            action: UiAction::Difficulty(0),
        });
        regions.push(HitRegion {
            x: 51,
            y: 347,
            width: 170,
            height: 25,
            action: UiAction::Focus(Field::Player),
        });
        regions.push(HitRegion {
            x: 616,
            y: 347,
            width: 170,
            height: 25,
            action: UiAction::Focus(Field::Enterprise),
        });
        for (index, button) in self.buttons.iter().enumerate() {
            regions.push(HitRegion {
                x: button.x,
                y: button.y,
                width: button.width,
                height: button.height,
                action: if index == 0 {
                    UiAction::Back
                } else {
                    UiAction::Start
                },
            });
        }
        self.regions = regions;
    }

    pub fn set_mode(&mut self, mode: GameMode) {
        self.mode = mode;
    }

    pub fn apply_profile(&mut self, profile: &CharacterProfile) {
        self.mode = profile.mode;
        self.gender = profile.gender.min(1) as usize;
        self.head = profile.head.min(9) as usize;
        self.eyes = profile.eyes.min(9) as usize;
        self.hair = profile.hair.min(9) as usize;
        self.mouth = profile.mouth.min(9) as usize;
        self.logo = profile.logo.min(7) as usize;
        self.color = profile.color.min(7) as usize;
        self.difficulty = profile.difficulty.min(10) as usize;
        self.attributes = profile.attributes;
        self.player_name = profile.player_name.clone();
        self.enterprise_name = profile.enterprise_name.clone();
    }

    pub fn profile(&self) -> CharacterProfile {
        CharacterProfile::new(
            self.gender as u8,
            self.head as u8,
            self.eyes as u8,
            self.hair as u8,
            self.mouth as u8,
            self.logo as u8,
            self.color as u8,
            self.difficulty as u8,
            self.attributes,
            self.player_name.clone(),
            self.enterprise_name.clone(),
        )
        .with_mode(self.mode)
    }

    pub fn buttons(&self) -> &[SelectButton] {
        &self.buttons
    }

    pub fn selected(&self) -> usize {
        self.selected
    }

    pub fn selected_action(&self) -> CharacterSelectAction {
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
        self.interacted = true;
    }

    pub fn select_previous(&mut self) {
        self.selected = (self.selected + self.buttons.len() - 1) % self.buttons.len();
        self.hover = None;
        self.interacted = true;
    }

    pub fn set_hover(&mut self, position: Option<(i32, i32)>) {
        self.hover_region = position.and_then(|(x, y)| {
            self.regions
                .iter()
                .rposition(|region| region.contains(x, y))
        });
        self.hover = position.and_then(|(x, y)| self.button_at(x, y));
        self.help = self.hover_region.and_then(|index| {
            let action = self.regions[index].action;
            match action {
                UiAction::Back => label(&self.labels, 0x602).ok().map(str::to_string),
                UiAction::Start => label(&self.labels, 0x603).ok().map(str::to_string),
                UiAction::Difficulty(_) => label(&self.labels, 0x601).ok().map(str::to_string),
                UiAction::Focus(_) => label(&self.labels, 0x600).ok().map(str::to_string),
                UiAction::Attribute(..) => label(&self.labels, 0x605).ok().map(str::to_string),
                _ => None,
            }
        });
        if self.hover.is_some() {
            self.interacted = true;
        }
    }

    pub fn clear_pressed(&mut self) {
        self.pressed_region = None;
    }

    pub fn button_at(&self, x: i32, y: i32) -> Option<usize> {
        self.buttons.iter().position(|button| button.contains(x, y))
    }

    pub fn set_status(&mut self, status: impl Into<String>) {
        self.status = Some(status.into());
    }

    pub fn activate(&mut self) -> CharacterSelectAction {
        self.selected_action()
    }

    pub fn editing(&self) -> bool {
        self.focus.is_some()
    }

    pub fn edit_char(&mut self, text: &str) {
        let Some(field) = self.focus else {
            return;
        };
        let target = match field {
            Field::Player => &mut self.player_name,
            Field::Enterprise => &mut self.enterprise_name,
        };
        for ch in text.chars() {
            if ch.is_ascii_graphic() || ch == ' ' {
                if target.len() < 20 {
                    target.push(ch);
                }
            }
        }
    }

    pub fn edit_backspace(&mut self) {
        let Some(field) = self.focus else {
            return;
        };
        match field {
            Field::Player => {
                self.player_name.pop();
            }
            Field::Enterprise => {
                self.enterprise_name.pop();
            }
        }
    }

    pub fn finish_edit(&mut self) {
        self.focus = None;
    }

    fn apply(&mut self, action: UiAction) -> Option<CharacterSelectAction> {
        match action {
            UiAction::Appearance(feature, delta) => {
                let value = match feature {
                    Appearance::Hair => &mut self.hair,
                    Appearance::Eyes => &mut self.eyes,
                    Appearance::Mouth => &mut self.mouth,
                    Appearance::Head => &mut self.head,
                };
                *value = wrap(*value as i32 + delta, FACE_COUNT);
            }
            UiAction::Attribute(index, delta) => {
                if index < self.attributes.len() {
                    self.attributes[index] = (self.attributes[index] + delta).clamp(-3, 3);
                }
            }
            UiAction::Gender(gender) => self.gender = gender.min(1),
            UiAction::Logo(delta) => self.logo = wrap(self.logo as i32 + delta, LOGO_COUNT),
            UiAction::Color(delta) => self.color = wrap(self.color as i32 + delta, COLOR_COUNT),
            UiAction::Difficulty(value) => {
                if value > 0 {
                    self.difficulty = ((self.difficulty as i32 + value).clamp(0, 10)) as usize;
                }
                self.difficulty_touched = true;
            }
            UiAction::Focus(field) => self.focus = Some(field),
            UiAction::Back => return Some(CharacterSelectAction::Back),
            UiAction::Start => return Some(CharacterSelectAction::Start),
        }
        None
    }

    pub fn click_at(&mut self, x: i32, y: i32) -> (bool, Option<CharacterSelectAction>) {
        let action = self
            .regions
            .iter()
            .rev()
            .find(|region| region.contains(x, y))
            .map(|region| region.action);
        let Some(action) = action else {
            return (false, None);
        };
        self.pressed_region = self
            .regions
            .iter()
            .rposition(|region| region.contains(x, y));
        if matches!(action, UiAction::Difficulty(_)) {
            let span = 175u32.saturating_sub(11);
            let value = ((x - 617).max(0) as u32 * 10 / span).min(10);
            self.difficulty = value as usize;
            self.difficulty_touched = true;
            return (true, None);
        }
        (true, self.apply(action))
    }

    fn attribute_total(&self) -> i32 {
        self.attributes.iter().sum()
    }

    fn visual_state(&self, index: usize) -> usize {
        let active = match self.hover {
            Some(hovered) => index == hovered,
            None => self.interacted && index == self.selected,
        };
        usize::from(active)
    }

    fn face_set(&self) -> &FaceSet {
        if self.gender == 1 {
            &self.faces.male
        } else {
            &self.faces.female
        }
    }

    pub fn render(&self) -> Vec<u8> {
        let mut frame = self.background.clone();
        self.draw_sprites(&mut frame);
        self.draw_text(&mut frame);
        for (index, button) in self.buttons.iter().enumerate() {
            let panel = if button.green {
                &self.green_panel
            } else {
                &self.yellow_panel
            };
            panel.draw(
                &mut frame,
                WIDTH,
                HEIGHT,
                button.x,
                button.y,
                button.width,
                button.height,
                self.visual_state(index),
            );
            draw_centered(
                &self.times,
                &mut frame,
                button.x,
                button.y + 9,
                button.width,
                &button.label,
                [0, 0, 0],
            );
        }
        if let Some(status) = &self.status {
            self.verdana8
                .draw_text(&mut frame, WIDTH, HEIGHT, 222, 512, status, [70, 20, 10])
                .ok();
        } else if let Some(help) = &self.help {
            draw_help(&self.verdana8, &mut frame, help);
        }
        frame
    }

    fn region_index(&self, action: UiAction) -> Option<usize> {
        self.regions
            .iter()
            .position(|region| region.action == action)
    }

    fn action_state(&self, action: UiAction) -> usize {
        let Some(index) = self.region_index(action) else {
            return 0;
        };
        if self.pressed_region == Some(index) {
            2
        } else if self.hover_region == Some(index) {
            1
        } else {
            0
        }
    }

    fn draw_state_sprite(
        &self,
        frame: &mut [u8],
        sprites: &[Sprite],
        x: i32,
        y: i32,
        action: UiAction,
    ) {
        if let Some(sprite) = sprites.get(self.action_state(action)) {
            draw_sprite(frame, WIDTH, HEIGHT, sprite, x, y);
        }
    }

    fn draw_sprites(&self, frame: &mut [u8]) {
        for (y, feature) in [
            (140, Appearance::Hair),
            (171, Appearance::Eyes),
            (206, Appearance::Mouth),
            (238, Appearance::Head),
        ] {
            self.draw_state_sprite(
                frame,
                &self.sprites.pb22,
                66,
                y,
                UiAction::Appearance(feature, -1),
            );
            self.draw_state_sprite(
                frame,
                &self.sprites.pb24,
                173,
                y,
                UiAction::Appearance(feature, 1),
            );
        }
        for (index, y) in [140, 172, 206, 239, 273, 304].into_iter().enumerate() {
            self.draw_state_sprite(
                frame,
                &self.sprites.pb26,
                299,
                y,
                UiAction::Attribute(index, -1),
            );
            self.draw_state_sprite(
                frame,
                &self.sprites.pb27,
                455,
                y,
                UiAction::Attribute(index, 1),
            );
        }
        self.draw_state_sprite(frame, &self.sprites.pb22, 630, 208, UiAction::Logo(-1));
        self.draw_state_sprite(frame, &self.sprites.pb24, 737, 208, UiAction::Logo(1));
        self.draw_state_sprite(frame, &self.sprites.pb22, 630, 239, UiAction::Color(-1));
        self.draw_state_sprite(frame, &self.sprites.pb24, 737, 239, UiAction::Color(1));
        draw_sprite(frame, WIDTH, HEIGHT, &self.sprites.photo_frame, 100, 57);
        draw_face(
            frame,
            self.face_set(),
            self.head,
            self.mouth,
            self.eyes,
            self.hair,
        );
        self.draw_state_sprite(frame, &self.sprites.gender_m, 71, 74, UiAction::Gender(1));
        self.draw_state_sprite(frame, &self.sprites.gender_w, 174, 71, UiAction::Gender(0));
        draw_sprite(frame, WIDTH, HEIGHT, &self.sprites.logo_window, 626, 54);
        if let Some(row) = self.playlogs.get(self.logo) {
            if let Some(logo) = row.get(self.color) {
                draw_sprite(frame, WIDTH, HEIGHT, logo, 633, 61);
            }
        }
        let player_state = usize::from(self.focus == Some(Field::Player));
        let enterprise_state = usize::from(self.focus == Some(Field::Enterprise));
        if let Some(field) = self.sprites.light_field.get(player_state) {
            draw_sprite(frame, WIDTH, HEIGHT, field, 42, 343);
        }
        if let Some(field) = self.sprites.light_field.get(enterprise_state) {
            draw_sprite(frame, WIDTH, HEIGHT, field, 604, 343);
        }
        if let Some(slider) = self.sprites.sliders.first() {
            let span = 175 - slider.width;
            let x = 617 + (self.difficulty as u32 * span / 10) as i32;
            draw_sprite(frame, WIDTH, HEIGHT, slider, x, 461);
        }
    }

    fn draw_text(&self, frame: &mut [u8]) {
        draw_centered(
            &self.times,
            frame,
            13,
            5,
            560,
            label(&self.labels, SELECT_PLAYER_TITLE).unwrap_or(""),
            [0, 0, 0],
        );
        draw_centered(
            &self.times,
            frame,
            608,
            5,
            180,
            label(&self.labels, ENTERPRISES_TITLE).unwrap_or(""),
            [0, 0, 0],
        );
        draw_centered(
            &self.times,
            frame,
            259,
            77,
            310,
            label(&self.labels, CHARACTERISTICS_TITLE).unwrap_or(""),
            [0, 0, 0],
        );
        draw_centered(
            &self.times,
            frame,
            44,
            304,
            180,
            label(&self.labels, PLAYER_NAME_LABEL).unwrap_or(""),
            [0, 0, 0],
        );
        draw_centered(
            &self.times,
            frame,
            609,
            304,
            180,
            label(&self.labels, ENTERPRISE_NAME_LABEL).unwrap_or(""),
            [0, 0, 0],
        );
        for (key, y) in [
            (HAIR_LABEL, 140),
            (EYES_LABEL, 172),
            (MOUTH_LABEL, 206),
            (CHIN_LABEL, 239),
        ] {
            draw_centered(
                &self.times,
                frame,
                91,
                y,
                83,
                label(&self.labels, key).unwrap_or(""),
                [0, 0, 0],
            );
        }
        for (key, y) in [
            (BUYER_LABEL, 140),
            (GANGSTERS_LABEL, 173),
            (SPECIALIST_LABEL, 207),
            (POLITICIANS_LABEL, 239),
            (SELLER_LABEL, 273),
            (GUARD_LABEL, 305),
        ] {
            draw_centered(
                &self.times,
                frame,
                323,
                y,
                133,
                label(&self.labels, key).unwrap_or(""),
                [0, 0, 0],
            );
        }
        for (index, value) in self.attributes.iter().enumerate() {
            let y = [140, 173, 207, 239, 273, 305][index];
            let color = if *value < 0 {
                [255, 0, 0]
            } else if *value > 0 {
                [0, 160, 0]
            } else {
                [0, 0, 0]
            };
            draw_centered(&self.times, frame, 501, y, 40, &value.to_string(), color);
        }
        let total = self.attribute_total();
        draw_centered(
            &self.times,
            frame,
            501,
            360,
            40,
            &total.to_string(),
            if total < 0 { [150, 0, 0] } else { [0, 0, 0] },
        );
        draw_centered(
            &self.times,
            frame,
            609,
            425,
            180,
            label(&self.labels, DIFFICULTY_TITLE).unwrap_or(""),
            [0, 0, 0],
        );
        let difficulty_label = if self.difficulty_touched {
            label(&self.labels, DIFFICULTY_NAMES + self.difficulty).unwrap_or("")
        } else {
            label(&self.labels, DIFFICULTY_EASY).unwrap_or("")
        };
        draw_centered(
            &self.times,
            frame,
            609,
            478,
            180,
            difficulty_label,
            [0, 0, 0],
        );
        draw_centered(
            &self.times,
            frame,
            655,
            208,
            83,
            label(&self.labels, LOGO_LABEL).unwrap_or(""),
            [0, 0, 0],
        );
        draw_centered(
            &self.times,
            frame,
            655,
            239,
            83,
            label(&self.labels, COLOR_LABEL).unwrap_or(""),
            [0, 0, 0],
        );
        let player = if self.player_name.is_empty() {
            "Player"
        } else {
            &self.player_name
        };
        let enterprise = if self.enterprise_name.is_empty() {
            "Enterprise"
        } else {
            &self.enterprise_name
        };
        let player_color = if self.player_name.is_empty() {
            [134, 134, 134]
        } else {
            [0, 0, 0]
        };
        let enterprise_color = if self.enterprise_name.is_empty() {
            [134, 134, 134]
        } else {
            [0, 0, 0]
        };
        self.times14
            .draw_text(frame, WIDTH, HEIGHT, 51, 347, player, player_color)
            .ok();
        self.times14
            .draw_text(frame, WIDTH, HEIGHT, 616, 347, enterprise, enterprise_color)
            .ok();
        if let Some(focus) = self.focus {
            let x = match focus {
                Field::Player => 55 + self.times14.measure(player) as i32,
                Field::Enterprise => 620 + self.times14.measure(enterprise) as i32,
            };
            self.times14
                .draw_text(frame, WIDTH, HEIGHT, x, 347, "|", [40, 40, 40])
                .ok();
        }
    }
}

fn draw_help(font: &Fnt, frame: &mut [u8], text: &str) {
    let mut line = String::new();
    let mut y = 512;
    for word in text.split_whitespace() {
        let candidate = if line.is_empty() {
            word.to_string()
        } else {
            format!("{line} {word}")
        };
        if font.measure(&candidate) > 345 && !line.is_empty() {
            font.draw_text(frame, WIDTH, HEIGHT, 224, y, &line, [40, 30, 20])
                .ok();
            y += font.line_height as i32;
            line = word.to_string();
        } else {
            line = candidate;
        }
    }
    if !line.is_empty() {
        font.draw_text(frame, WIDTH, HEIGHT, 224, y, &line, [40, 30, 20])
            .ok();
    }
}

fn draw_face(
    frame: &mut [u8],
    face: &FaceSet,
    head: usize,
    mouth: usize,
    eyes: usize,
    hair: usize,
) {
    let mut surface = vec![0u8; 60 * 50 * 4];
    for part in [
        face.head.get(head),
        face.mouth.get(mouth),
        face.eyes.get(eyes),
        face.hair.get(hair),
    ]
    .into_iter()
    .flatten()
    {
        draw_sprite(
            &mut surface,
            60,
            50,
            part,
            part.hotspot_x as i32,
            part.hotspot_y as i32,
        );
    }
    for y in 0..50 {
        for x in 0..60 {
            let offset = ((y * 60 + x) * 4) as usize;
            let pixel = [
                surface[offset],
                surface[offset + 1],
                surface[offset + 2],
                surface[offset + 3],
            ];
            if pixel[3] != 0 {
                blend_pixel(frame, WIDTH, HEIGHT, 105 + x, 62 + y, pixel);
            }
        }
    }
}

pub fn encode_profile(profile: &CharacterProfile) -> String {
    let attributes = profile
        .attributes
        .iter()
        .map(i32::to_string)
        .collect::<Vec<_>>()
        .join(",");
    format!(
        "mode={};gender={};head={};eyes={};hair={};mouth={};logo={};color={};difficulty={};attrs={};player={};enterprise={}",
        if profile.mode == GameMode::FreeGame { "free" } else { "campaign" },
        profile.gender,
        profile.head,
        profile.eyes,
        profile.hair,
        profile.mouth,
        profile.logo,
        profile.color,
        profile.difficulty,
        attributes,
        escape_field(&profile.player_name),
        escape_field(&profile.enterprise_name),
    )
}

pub fn decode_profile(value: &str) -> Result<CharacterProfile, String> {
    let mut mode = GameMode::Campaign;
    let mut gender = 1;
    let mut head = 0;
    let mut eyes = 0;
    let mut hair = 0;
    let mut mouth = 0;
    let mut logo = 1;
    let mut color = 0;
    let mut difficulty = 0;
    let mut attributes = [0, -2, 0, -1, 1, 0];
    let mut player_name = String::new();
    let mut enterprise_name = String::new();
    for item in value.split(';') {
        let Some((key, raw)) = item.split_once('=') else {
            continue;
        };
        let number = |raw: &str| {
            raw.parse::<i32>()
                .map_err(|_| format!("invalid character profile value: {raw}"))
        };
        match key {
            "mode" => {
                mode = if raw == "free" {
                    GameMode::FreeGame
                } else {
                    GameMode::Campaign
                }
            }
            "gender" => gender = number(raw)?.clamp(0, 1) as u8,
            "head" => head = number(raw)?.clamp(0, 9) as u8,
            "eyes" => eyes = number(raw)?.clamp(0, 9) as u8,
            "hair" => hair = number(raw)?.clamp(0, 9) as u8,
            "mouth" => mouth = number(raw)?.clamp(0, 9) as u8,
            "logo" => logo = number(raw)?.clamp(0, 7) as u8,
            "color" => color = number(raw)?.clamp(0, 7) as u8,
            "difficulty" => difficulty = number(raw)?.clamp(0, 10) as u8,
            "attrs" => {
                let mut parsed = [0; 6];
                for (slot, value) in parsed.iter_mut().zip(raw.split(',')) {
                    *slot = number(value)?.clamp(-3, 3);
                }
                attributes = parsed;
            }
            "player" => player_name = unescape_field(raw),
            "enterprise" => enterprise_name = unescape_field(raw),
            _ => {}
        }
    }
    Ok(CharacterProfile::new(
        gender,
        head,
        eyes,
        hair,
        mouth,
        logo,
        color,
        difficulty,
        attributes,
        player_name,
        enterprise_name,
    )
    .with_mode(mode))
}

fn escape_field(value: &str) -> String {
    value
        .replace('%', "%25")
        .replace(';', "%3B")
        .replace('=', "%3D")
        .replace('\n', "%0A")
}

fn unescape_field(value: &str) -> String {
    value
        .replace(
            "%0A", "
",
        )
        .replace("%3D", "=")
        .replace("%3B", ";")
        .replace("%25", "%")
}

fn wrap(value: i32, count: usize) -> usize {
    value.rem_euclid(count as i32) as usize
}

fn label(labels: &[String], index: usize) -> Result<&str, String> {
    labels
        .get(index)
        .map(String::as_str)
        .ok_or_else(|| format!("language.ldf has no string at index {index}"))
}

fn draw_centered(
    font: &Fnt,
    frame: &mut [u8],
    x: i32,
    y: i32,
    width: u32,
    text: &str,
    color: [u8; 3],
) {
    if text.is_empty() {
        return;
    }
    let measured = font.measure(text);
    let text_x = x + (width as i32 - measured as i32) / 2;
    font.draw_text(frame, WIDTH, HEIGHT, text_x, y, text, color)
        .ok();
}

fn load_asset(install: &mut GameInstall, name: &str) -> Result<Vec<u8>, String> {
    install
        .read_asset(name)
        .map_err(|error| format!("cannot read {name}: {error}"))?
        .ok_or_else(|| format!("missing character-select resource: {name}"))
}

fn load_font(install: &mut GameInstall, name: &str) -> Result<Fnt, String> {
    Fnt::load(&load_asset(install, name)?).map_err(|error| format!("font {name}: {error}"))
}

fn load_sprite(install: &mut GameInstall, name: &str) -> Result<Sprite, String> {
    Sprite::load(&load_asset(install, name)?).map_err(|error| format!("sprite {name}: {error}"))
}

fn load_sequence(
    install: &mut GameInstall,
    pattern: &str,
    count: usize,
) -> Result<Vec<Sprite>, String> {
    let mut out = Vec::with_capacity(count);
    for index in 0..count {
        out.push(load_sprite(
            install,
            &pattern.replace("%02d", &format!("{index:02}")),
        )?);
    }
    Ok(out)
}

fn load_face_set(install: &mut GameInstall, suffix: &str) -> Result<FaceSet, String> {
    Ok(FaceSet {
        head: load_sequence(
            install,
            &format!("sprites\\pizzaimages\\head_{suffix}_%02d.spr"),
            FACE_COUNT,
        )?,
        eyes: load_sequence(
            install,
            &format!("sprites\\pizzaimages\\augen_{suffix}_%02d.spr"),
            FACE_COUNT,
        )?,
        hair: load_sequence(
            install,
            &format!("sprites\\pizzaimages\\haare_{suffix}_%02d.spr"),
            FACE_COUNT,
        )?,
        mouth: load_sequence(
            install,
            &format!("sprites\\pizzaimages\\mund_{suffix}_%02d.spr"),
            FACE_COUNT,
        )?,
    })
}

fn load_playlogs(install: &mut GameInstall) -> Result<Vec<Vec<Sprite>>, String> {
    let mut rows = Vec::with_capacity(LOGO_COUNT);
    for logo in 1..=LOGO_COUNT {
        let mut row = Vec::with_capacity(COLOR_COUNT);
        for color in 1..=COLOR_COUNT {
            row.push(load_sprite(
                install,
                &format!("sprites\\playlog_{logo}_0{color}_00.spr"),
            )?);
        }
        rows.push(row);
    }
    Ok(rows)
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::path::Path;

    #[test]
    fn label_indices_are_valid_for_installed_english_table() {
        let labels = load_labels(
            Path::new(env!("CARGO_MANIFEST_DIR"))
                .join("..")
                .join("..")
                .join("game")
                .as_path(),
        )
        .unwrap();
        assert_eq!(
            label(&labels, SELECT_PLAYER_TITLE).unwrap(),
            "Select player character"
        );
        assert_eq!(label(&labels, BACK_LABEL).unwrap(), "To main menu");
        assert_eq!(label(&labels, START_LABEL).unwrap(), "Start game");
        assert_eq!(label(&labels, DIFFICULTY_NAMES).unwrap(), "Dishwasher");
    }

    #[test]
    fn appearance_and_attributes_wrap_and_clamp() {
        let Some(mut screen) = shipped_screen() else {
            return;
        };
        screen.apply(UiAction::Appearance(Appearance::Hair, -1));
        assert_eq!(screen.hair, 9);
        screen.apply(UiAction::Appearance(Appearance::Hair, 1));
        assert_eq!(screen.hair, 0);
        for _ in 0..10 {
            screen.apply(UiAction::Attribute(0, 1));
        }
        assert_eq!(screen.attributes[0], 3);
        for _ in 0..10 {
            screen.apply(UiAction::Attribute(0, -1));
        }
        assert_eq!(screen.attributes[0], -3);
    }

    #[test]
    fn gender_logo_color_and_difficulty_update_state() {
        let Some(mut screen) = shipped_screen() else {
            return;
        };
        let face = screen.render();
        screen.apply(UiAction::Gender(0));
        assert_eq!(screen.gender, 0);
        assert_ne!(face, screen.render());
        let before_logo = screen.render();
        screen.apply(UiAction::Logo(1));
        screen.apply(UiAction::Color(1));
        assert_eq!((screen.logo, screen.color), (2, 1));
        let changed_logo = screen.render();
        assert_ne!(before_logo, changed_logo);
        screen.apply(UiAction::Logo(1));
        assert_ne!(changed_logo, screen.render());
        screen.apply(UiAction::Difficulty(10));
        assert_eq!(screen.difficulty, 10);
    }

    #[test]
    fn profile_roundtrips_through_branch_arguments() {
        let Some(screen) = shipped_screen() else {
            return;
        };
        let mut profile = screen.profile();
        profile.mode = GameMode::FreeGame;
        profile.player_name = "Ada;=Name".into();
        profile.enterprise_name = "Pizza%Co".into();
        let encoded = encode_profile(&profile);
        assert_eq!(decode_profile(&encoded).unwrap(), profile);
    }

    #[test]
    fn hover_help_and_pressed_state_are_wired() {
        let Some(mut screen) = shipped_screen() else {
            return;
        };
        screen.set_hover(Some((650, 520)));
        assert!(screen.help.is_some());
        assert!(screen.help.as_ref().unwrap().contains("Main Menu"));
        assert_eq!(screen.action_state(UiAction::Back), 1);
        let (hit, _) = screen.click_at(66, 145);
        assert!(hit);
        assert!(screen.pressed_region.is_some());
        assert_eq!(
            screen.action_state(UiAction::Appearance(Appearance::Hair, -1)),
            2
        );
        screen.clear_pressed();
        assert_eq!(
            screen.action_state(UiAction::Appearance(Appearance::Hair, -1)),
            0
        );
    }

    #[test]
    fn mouse_hit_regions_map_to_controls() {
        let Some(mut screen) = shipped_screen() else {
            return;
        };
        let hair = screen.hair;
        assert!(screen.click_at(66, 145).0);
        assert_eq!(screen.hair, (hair + 9) % 10);
        assert!(screen.click_at(700, 461).0);
        assert_eq!(screen.difficulty, 5);
        assert!(screen.click_at(60, 350).0);
        assert!(screen.editing());
        screen.finish_edit();
        assert_eq!(
            screen.click_at(600, 520).1,
            Some(CharacterSelectAction::Back)
        );
        assert_eq!(
            screen.click_at(600, 560).1,
            Some(CharacterSelectAction::Start)
        );
    }

    #[test]
    fn text_fields_accept_edits() {
        let Some(mut screen) = shipped_screen() else {
            return;
        };
        screen.apply(UiAction::Focus(Field::Player));
        screen.edit_char("Ada");
        screen.edit_backspace();
        screen.edit_char("a");
        assert_eq!(screen.player_name, "Ada");
        screen.finish_edit();
        assert!(!screen.editing());
    }

    #[test]
    fn attribute_total_tracks_the_six_scores() {
        let Some(mut screen) = shipped_screen() else {
            return;
        };
        assert_eq!(screen.attribute_total(), -2);
        screen.apply(UiAction::Attribute(1, 1));
        assert_eq!(screen.attribute_total(), -1);
        screen.apply(UiAction::Attribute(1, -1));
        assert_eq!(screen.attribute_total(), -2);
    }

    fn shipped_screen() -> Option<CharacterSelect> {
        let root = Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("game");
        if !root.is_dir() {
            return None;
        }
        let mut install = GameInstall::open(root).ok()?;
        CharacterSelect::load(&mut install).ok()
    }
}
