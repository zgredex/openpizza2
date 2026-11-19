//! Reconstruction of `Screen_MainMenu` (`0x476920`).
//!
//! The shipped `Pe_Startscreen.tga` background is 800x600. The original
//! creates six `TIMESFONT.fnt` text buttons on it:
//!
//! | Control | Label | x | y |
//! |---|---|---:|---:|
//! | `0x3ee` | Start new game | 595 | 6 |
//! | `0x3ef` | Start free game | 595 | 48 |
//! | `0x3f0` | Continue game | 595 | 91 |
//! | `0x3f1` | Options | 595 | 133 |
//! | `0x3f7` | Credits | 595 | 175 |
//! | `0x3f6` | Quit | 595 | 560 |
//!
//! `Gadget_SetButtonTextLayout(..., 2, 0xcc, ...)` centers each label in the
//! 204-pixel-wide row. The callback at `0x4ceb80` maps the control IDs to the
//! screen transitions documented in `MAIN_MENU_TRACE.md`.

use std::path::Path;

use crate::widgets::PanelTiles;
use pc2_assets::{Fnt, GameInstall, TgaImage};

pub const MENU_WIDTH: u32 = 800;
pub const MENU_HEIGHT: u32 = 600;
const BUTTON_X: i32 = 595;
const BUTTON_WIDTH: u32 = 204;
const BUTTON_HEIGHT: u32 = 38;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum MenuAction {
    StartNewGame,
    StartFreeGame,
    ContinueGame,
    Options,
    Credits,
    Quit,
}

impl MenuAction {
    pub fn label(self) -> &'static str {
        match self {
            Self::StartNewGame => "Start new game",
            Self::StartFreeGame => "Start free game",
            Self::ContinueGame => "Continue game",
            Self::Options => "Options",
            Self::Credits => "Credits",
            Self::Quit => "Quit",
        }
    }

    pub fn control_id(self) -> u16 {
        match self {
            Self::StartNewGame => 0x3ee,
            Self::StartFreeGame => 0x3ef,
            Self::ContinueGame => 0x3f0,
            Self::Options => 0x3f1,
            Self::Quit => 0x3f6,
            Self::Credits => 0x3f7,
        }
    }
}

#[derive(Clone, Debug)]
pub struct MenuItem {
    pub action: MenuAction,
    pub label: String,
    pub x: i32,
    pub y: i32,
    pub width: u32,
    pub height: u32,
}

impl MenuItem {
    pub fn label(&self) -> &str {
        &self.label
    }

    pub fn id(&self) -> u16 {
        self.action.control_id()
    }

    pub fn contains(&self, x: i32, y: i32) -> bool {
        x >= self.x
            && y >= self.y
            && x < self.x + self.width as i32
            && y < self.y + self.height as i32
    }
}

#[derive(Clone, Debug)]
pub struct Menu {
    background: Vec<u8>,
    font: Fnt,
    items: Vec<MenuItem>,
    panel: PanelTiles,
    selected: usize,
    hover: Option<usize>,
    interacted: bool,
    status: Option<String>,
}

impl Menu {
    pub fn load(install: &mut GameInstall) -> Result<Self, String> {
        let background = load_first(
            install,
            &[
                "pictures\\pe_startscreen.tga",
                "pictures\\startscreen00.tga",
            ],
        )?;
        let background =
            TgaImage::load(&background).map_err(|error| format!("menu background: {error}"))?;
        if background.width != MENU_WIDTH || background.height != MENU_HEIGHT {
            return Err(format!(
                "menu background is {}x{}, expected {}x{}",
                background.width, background.height, MENU_WIDTH, MENU_HEIGHT
            ));
        }
        let font_data = load_first(install, &["fonts\\timesfont.fnt", "fonts\\times14.fnt"])?;
        let font = Fnt::load(&font_data).map_err(|error| format!("menu font: {error}"))?;
        let labels = load_labels(&install.root)?;
        let panel = PanelTiles::load(install, "textpbtranspgelb")?;
        Ok(Self {
            background: background.pixels,
            font,
            items: vec![
                item(
                    MenuAction::StartNewGame,
                    labels[START_NEW_GAME_INDEX].clone(),
                    6,
                ),
                item(
                    MenuAction::StartFreeGame,
                    labels[START_FREE_GAME_INDEX].clone(),
                    48,
                ),
                item(
                    MenuAction::ContinueGame,
                    labels[CONTINUE_GAME_INDEX].clone(),
                    91,
                ),
                item(MenuAction::Options, labels[OPTIONS_INDEX].clone(), 133),
                item(MenuAction::Credits, labels[CREDITS_INDEX].clone(), 175),
                item(MenuAction::Quit, labels[QUIT_INDEX].clone(), 560),
            ],
            panel,
            selected: 0,
            hover: None,
            interacted: false,
            status: None,
        })
    }

    pub fn items(&self) -> &[MenuItem] {
        &self.items
    }

    pub fn line_height(&self) -> u16 {
        self.font.line_height
    }

    pub fn selected(&self) -> usize {
        self.selected
    }

    pub fn selected_action(&self) -> MenuAction {
        self.items[self.selected].action
    }

    pub fn set_selected(&mut self, index: usize) {
        if index < self.items.len() {
            self.selected = index;
        }
    }

    pub fn select_next(&mut self) {
        self.selected = (self.selected + 1) % self.items.len();
        self.hover = None;
        self.interacted = true;
    }

    pub fn select_previous(&mut self) {
        self.selected = (self.selected + self.items.len() - 1) % self.items.len();
        self.hover = None;
        self.interacted = true;
    }

    pub fn set_hover(&mut self, position: Option<(i32, i32)>) {
        self.hover = position.and_then(|(x, y)| self.button_at(x, y));
        if self.hover.is_some() {
            self.interacted = true;
        }
    }

    pub fn button_at(&self, x: i32, y: i32) -> Option<usize> {
        self.items.iter().position(|item| item.contains(x, y))
    }

    pub fn set_status(&mut self, status: impl Into<String>) {
        self.status = Some(status.into());
    }

    pub fn activate(&mut self) -> MenuAction {
        let action = self.selected_action();
        match action {
            MenuAction::ContinueGame => self.set_status("No saved games found."),
            MenuAction::Options => self.set_status("Options screen is not rebuilt yet."),
            MenuAction::Credits => self.set_status("Pizza Connection 2 menu reconstruction."),
            MenuAction::Quit => self.status = None,
            MenuAction::StartNewGame | MenuAction::StartFreeGame => {
                self.set_status("Starting a new game...")
            }
        }
        action
    }

    fn visual_state(&self, index: usize) -> usize {
        let active = match self.hover {
            Some(hovered) => index == hovered,
            None => self.interacted && index == self.selected,
        };
        usize::from(active)
    }

    pub fn render(&self) -> Vec<u8> {
        let mut frame = self.background.clone();
        for (index, item) in self.items.iter().enumerate() {
            let state = self.visual_state(index);
            self.panel.draw(
                &mut frame,
                MENU_WIDTH,
                MENU_HEIGHT,
                item.x,
                item.y,
                item.width,
                item.height,
                state,
            );
            let measured = self.font.measure(item.label());
            let text_x = item.x + (item.width as i32 - measured as i32) / 2;
            // The original centers the 23-pixel text line inside the
            // 41-pixel sprite canvas, then draws it over the 38-pixel panel.
            let text_y = item.y + (41 - self.font.line_height as i32) / 2;
            let _ = self.font.draw_text(
                &mut frame,
                MENU_WIDTH,
                MENU_HEIGHT,
                text_x,
                text_y,
                item.label(),
                [0, 0, 0],
            );
        }
        if let Some(status) = &self.status {
            draw_status(&self.font, &mut frame, status);
        }
        frame
    }
}

const START_NEW_GAME_INDEX: usize = 0x81d;
const START_FREE_GAME_INDEX: usize = 0x762;
const CONTINUE_GAME_INDEX: usize = 0x876;
const OPTIONS_INDEX: usize = 0x73b;
const CREDITS_INDEX: usize = 0x724;
const QUIT_INDEX: usize = 0x708;

fn item(action: MenuAction, label: String, y: i32) -> MenuItem {
    MenuItem {
        action,
        label,
        x: BUTTON_X,
        y,
        width: BUTTON_WIDTH,
        height: BUTTON_HEIGHT,
    }
}

pub(crate) fn load_labels(root: &Path) -> Result<Vec<String>, String> {
    let path = root.join("language.ldf");
    let data = std::fs::read(&path)
        .map_err(|error| format!("cannot read menu labels {}: {error}", path.display()))?;
    let labels = parse_ldf(&data)?;
    for (name, index) in [
        ("Start new game", START_NEW_GAME_INDEX),
        ("Start free game", START_FREE_GAME_INDEX),
        ("Continue game", CONTINUE_GAME_INDEX),
        ("Options", OPTIONS_INDEX),
        ("Credits", CREDITS_INDEX),
        ("Quit", QUIT_INDEX),
    ] {
        if index >= labels.len() {
            return Err(format!(
                "language.ldf has {} strings, but {name} needs index {index}",
                labels.len()
            ));
        }
    }
    Ok(labels)
}

/// Decode the installed language table: `u32 count` followed by
/// NUL-terminated CP1252 strings, with no trailing bytes.
fn parse_ldf(data: &[u8]) -> Result<Vec<String>, String> {
    if data.len() < 4 {
        return Err("language.ldf is shorter than its 4-byte count".into());
    }
    let count = u32::from_le_bytes(data[0..4].try_into().unwrap()) as usize;
    let mut position = 4usize;
    let mut strings = Vec::with_capacity(count);
    for index in 0..count {
        let end = data[position..]
            .iter()
            .position(|byte| *byte == 0)
            .ok_or_else(|| format!("language.ldf string {index} is not terminated"))?;
        strings.push(decode_cp1252(&data[position..position + end]));
        position += end + 1;
    }
    if position != data.len() {
        return Err(format!(
            "language.ldf has {} trailing bytes after {count} strings",
            data.len() - position
        ));
    }
    Ok(strings)
}

pub(crate) fn decode_cp1252(bytes: &[u8]) -> String {
    bytes
        .iter()
        .map(|byte| match byte {
            0x80 => '€',
            0x82 => '‚',
            0x83 => 'ƒ',
            0x84 => '„',
            0x85 => '…',
            0x86 => '†',
            0x87 => '‡',
            0x88 => 'ˆ',
            0x89 => '‰',
            0x8a => 'Š',
            0x8b => '‹',
            0x8c => 'Œ',
            0x8e => 'Ž',
            0x91 => '‘',
            0x92 => '’',
            0x93 => '“',
            0x94 => '”',
            0x95 => '•',
            0x96 => '–',
            0x97 => '—',
            0x98 => '˜',
            0x99 => '™',
            0x9a => 'š',
            0x9b => '›',
            0x9c => 'œ',
            0x9e => 'ž',
            0x9f => 'Ÿ',
            0x81 | 0x8d | 0x8f | 0x90 | 0x9d => '\u{fffd}',
            _ if *byte < 0x80 => *byte as char,
            _ => *byte as char,
        })
        .collect()
}

fn load_first(install: &mut GameInstall, names: &[&str]) -> Result<Vec<u8>, String> {
    for name in names {
        if let Some(data) = install
            .read_asset(name)
            .map_err(|error| format!("cannot read {name}: {error}"))?
        {
            return Ok(data);
        }
    }
    Err(format!("missing menu resource: {}", names.join(" or ")))
}

fn draw_status(font: &Fnt, frame: &mut Vec<u8>, status: &str) {
    let left = 612;
    let mut top = 250;
    for line in wrap(status, 19) {
        let _ = font.draw_text(
            frame,
            MENU_WIDTH,
            MENU_HEIGHT,
            left,
            top,
            &line,
            [42, 30, 18],
        );
        top += font.line_height as i32;
    }
}

fn wrap(text: &str, width: usize) -> Vec<String> {
    let mut lines = Vec::new();
    let mut line = String::new();
    for word in text.split_whitespace() {
        if !line.is_empty() && line.len() + 1 + word.len() > width {
            lines.push(line);
            line = String::new();
        }
        if !line.is_empty() {
            line.push(' ');
        }
        line.push_str(word);
    }
    if !line.is_empty() {
        lines.push(line);
    }
    lines
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::path::Path;

    fn shipped_menu() -> Option<Menu> {
        let root = Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("game");
        if !root.is_dir() {
            return None;
        }
        let mut install = GameInstall::open(root).ok()?;
        Menu::load(&mut install).ok()
    }

    #[test]
    fn menu_matches_original_control_table() {
        let Some(menu) = shipped_menu() else {
            return;
        };
        let expected = [
            (MenuAction::StartNewGame, 0x3ee, 6),
            (MenuAction::StartFreeGame, 0x3ef, 48),
            (MenuAction::ContinueGame, 0x3f0, 91),
            (MenuAction::Options, 0x3f1, 133),
            (MenuAction::Credits, 0x3f7, 175),
            (MenuAction::Quit, 0x3f6, 560),
        ];
        assert_eq!(menu.items().len(), expected.len());
        for (item, (action, id, y)) in menu.items().iter().zip(expected) {
            assert_eq!(item.action, action);
            assert_eq!(item.id(), id);
            assert_eq!(item.x, 595);
            assert_eq!(item.y, y);
            assert_eq!(item.width, 204);
            assert_eq!(item.height, 38);
        }
    }

    #[test]
    fn menu_navigation_wraps_and_hit_tests() {
        let Some(mut menu) = shipped_menu() else {
            return;
        };
        assert_eq!(menu.selected_action(), MenuAction::StartNewGame);
        menu.select_previous();
        assert_eq!(menu.selected_action(), MenuAction::Quit);
        menu.select_next();
        assert_eq!(menu.selected_action(), MenuAction::StartNewGame);
        assert_eq!(menu.button_at(650, 12), Some(0));
        assert_eq!(menu.button_at(650, 140), Some(3));
        assert_eq!(menu.button_at(650, 566), Some(5));
        assert_eq!(menu.button_at(10, 10), None);
    }

    #[test]
    fn menu_labels_come_from_language_ldf() {
        let labels = b"\x03\x00\x00\x00Start\x00Free\x00Quit\x00";
        assert_eq!(parse_ldf(labels).unwrap(), ["Start", "Free", "Quit"]);
        let cp1252 = b"\x01\x00\x00\x00Gr\xfc\xdfe\x00";
        assert_eq!(parse_ldf(cp1252).unwrap(), ["Grüße"]);
        assert!(parse_ldf(b"\x01\x00\x00\x00unterminated").is_err());
    }

    #[test]
    fn menu_labels_load_from_install_language_file() {
        let root = std::env::temp_dir().join(format!("pc2-menu-labels-{}", std::process::id()));
        std::fs::create_dir_all(&root).unwrap();
        let mut labels = vec![String::new(); CONTINUE_GAME_INDEX + 1];
        labels[START_NEW_GAME_INDEX] = "Begin adventure".into();
        let mut data = (labels.len() as u32).to_le_bytes().to_vec();
        for label in &labels {
            data.extend_from_slice(label.as_bytes());
            data.push(0);
        }
        std::fs::write(root.join("language.ldf"), data).unwrap();
        let loaded = load_labels(&root).unwrap();
        assert_eq!(loaded[START_NEW_GAME_INDEX], "Begin adventure");
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn hovered_row_replaces_keyboard_selection_highlight() {
        let Some(mut menu) = shipped_menu() else {
            return;
        };
        menu.select_next();
        assert_eq!(menu.selected(), 1);
        assert_eq!(menu.visual_state(1), 1);
        menu.set_hover(Some((650, 12)));
        assert_eq!(menu.hover, Some(0));
        assert_eq!(menu.visual_state(0), 1);
        assert_eq!(menu.visual_state(1), 0);
        menu.set_hover(None);
        assert_eq!(menu.visual_state(1), 1);
    }

    #[test]
    fn menu_draws_original_button_frames_and_hover_state() {
        let Some(mut menu) = shipped_menu() else {
            return;
        };
        let base = menu.background.clone();
        let normal = menu.render();
        let border = ((6 * MENU_WIDTH + 597) * 4) as usize;
        assert_ne!(&normal[border..border + 4], &base[border..border + 4]);
        let normal_interior = ((20 * MENU_WIDTH + 700) * 4) as usize;
        menu.set_hover(Some((650, 12)));
        let hovered = menu.render();
        assert_ne!(
            &normal[normal_interior..normal_interior + 4],
            &hovered[normal_interior..normal_interior + 4]
        );
    }

    #[test]
    fn menu_renders_background_and_labels() {
        let Some(mut menu) = shipped_menu() else {
            return;
        };
        menu.set_selected(2);
        let frame = menu.render();
        assert_eq!(frame.len(), (MENU_WIDTH * MENU_HEIGHT * 4) as usize);
        assert_eq!(&frame[0..4], &[55, 56, 47, 255]);
        let changed = frame
            .chunks_exact(4)
            .filter(|pixel| pixel[0] < 80 && pixel[1] < 80)
            .count();
        assert!(changed > 100, "menu labels should darken pixels");
    }
}
