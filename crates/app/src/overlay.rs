//! Small built-in 5x7 status overlay for the playable branch view.

use pc2_sim::{
    CharacterProfile, Employee, EmployeeCandidate, EmployeeRole, GameMode, ScenarioSetup, Snapshot,
};

const SCALE: u32 = 2;
const GLYPH_WIDTH: u32 = 5;
const ADVANCE: u32 = GLYPH_WIDTH + 1;

fn glyph(ch: char) -> [u8; 7] {
    match ch.to_ascii_uppercase() {
        'A' => [
            0b01110, 0b10001, 0b10001, 0b11111, 0b10001, 0b10001, 0b10001,
        ],
        'B' => [
            0b11110, 0b10001, 0b10001, 0b11110, 0b10001, 0b10001, 0b11110,
        ],
        'C' => [
            0b01111, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b01111,
        ],
        'D' => [
            0b11110, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b11110,
        ],
        'E' => [
            0b11111, 0b10000, 0b10000, 0b11110, 0b10000, 0b10000, 0b11111,
        ],
        'F' => [
            0b11111, 0b10000, 0b10000, 0b11110, 0b10000, 0b10000, 0b10000,
        ],
        'G' => [
            0b01111, 0b10000, 0b10000, 0b10111, 0b10001, 0b10001, 0b01110,
        ],
        'H' => [
            0b10001, 0b10001, 0b10001, 0b11111, 0b10001, 0b10001, 0b10001,
        ],
        'I' => [
            0b11111, 0b00100, 0b00100, 0b00100, 0b00100, 0b00100, 0b11111,
        ],
        'K' => [
            0b10001, 0b10010, 0b10100, 0b11000, 0b10100, 0b10010, 0b10001,
        ],
        'L' => [
            0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b11111,
        ],
        'M' => [
            0b10001, 0b11011, 0b10101, 0b10101, 0b10001, 0b10001, 0b10001,
        ],
        'N' => [
            0b10001, 0b11001, 0b10101, 0b10011, 0b10001, 0b10001, 0b10001,
        ],
        'O' => [
            0b01110, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b01110,
        ],
        'P' => [
            0b11110, 0b10001, 0b10001, 0b11110, 0b10000, 0b10000, 0b10000,
        ],
        'Q' => [
            0b01110, 0b10001, 0b10001, 0b10001, 0b10101, 0b10010, 0b01101,
        ],
        'R' => [
            0b11110, 0b10001, 0b10001, 0b11110, 0b10100, 0b10010, 0b10001,
        ],
        'S' => [
            0b01111, 0b10000, 0b10000, 0b01110, 0b00001, 0b00001, 0b11110,
        ],
        'T' => [
            0b11111, 0b00100, 0b00100, 0b00100, 0b00100, 0b00100, 0b00100,
        ],
        'U' => [
            0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b01110,
        ],
        'V' => [
            0b10001, 0b10001, 0b10001, 0b10001, 0b10001, 0b01010, 0b00100,
        ],
        'W' => [
            0b10001, 0b10001, 0b10001, 0b10101, 0b10101, 0b11011, 0b10001,
        ],
        'X' => [
            0b10001, 0b10001, 0b01010, 0b00100, 0b01010, 0b10001, 0b10001,
        ],
        'Y' => [
            0b10001, 0b10001, 0b01010, 0b00100, 0b00100, 0b00100, 0b00100,
        ],
        'Z' => [
            0b11111, 0b00001, 0b00010, 0b00100, 0b01000, 0b10000, 0b11111,
        ],
        '0' => [
            0b01110, 0b10001, 0b10011, 0b10101, 0b11001, 0b10001, 0b01110,
        ],
        '1' => [
            0b00100, 0b01100, 0b00100, 0b00100, 0b00100, 0b00100, 0b01110,
        ],
        '2' => [
            0b01110, 0b10001, 0b00001, 0b00010, 0b00100, 0b01000, 0b11111,
        ],
        '3' => [
            0b11111, 0b00010, 0b00100, 0b00010, 0b00001, 0b10001, 0b01110,
        ],
        '4' => [
            0b00010, 0b00110, 0b01010, 0b10010, 0b11111, 0b00010, 0b00010,
        ],
        '5' => [
            0b11111, 0b10000, 0b11110, 0b00001, 0b00001, 0b10001, 0b01110,
        ],
        '6' => [
            0b00110, 0b01000, 0b10000, 0b11110, 0b10001, 0b10001, 0b01110,
        ],
        '7' => [
            0b11111, 0b00001, 0b00010, 0b00100, 0b01000, 0b01000, 0b01000,
        ],
        '8' => [
            0b01110, 0b10001, 0b10001, 0b01110, 0b10001, 0b10001, 0b01110,
        ],
        '9' => [
            0b01110, 0b10001, 0b10001, 0b01111, 0b00001, 0b00010, 0b01100,
        ],
        ':' => [
            0b00000, 0b00100, 0b00100, 0b00000, 0b00100, 0b00100, 0b00000,
        ],
        '.' => [
            0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00110, 0b00110,
        ],
        ',' => [
            0b00000, 0b00000, 0b00000, 0b00000, 0b00110, 0b00110, 0b00100,
        ],
        '$' => [
            0b00100, 0b01111, 0b10100, 0b01110, 0b00101, 0b11110, 0b00100,
        ],
        '-' => [
            0b00000, 0b00000, 0b00000, 0b11111, 0b00000, 0b00000, 0b00000,
        ],
        '/' => [
            0b00001, 0b00010, 0b00010, 0b00100, 0b01000, 0b01000, 0b10000,
        ],
        '+' => [
            0b00000, 0b00100, 0b00100, 0b11111, 0b00100, 0b00100, 0b00000,
        ],
        '=' => [
            0b00000, 0b00000, 0b11111, 0b00000, 0b11111, 0b00000, 0b00000,
        ],
        '[' => [
            0b01110, 0b01000, 0b01000, 0b01000, 0b01000, 0b01000, 0b01110,
        ],
        ']' => [
            0b01110, 0b00010, 0b00010, 0b00010, 0b00010, 0b00010, 0b01110,
        ],
        _ => [0; 7],
    }
}

fn blend(frame: &mut [u8], width: u32, height: u32, x: i32, y: i32, color: [u8; 4]) {
    if x < 0 || y < 0 || x >= width as i32 || y >= height as i32 {
        return;
    }
    let offset = ((y as u32 * width + x as u32) * 4) as usize;
    let alpha = color[3] as u32;
    if alpha == 255 {
        frame[offset..offset + 4].copy_from_slice(&color);
    } else {
        for channel in 0..3 {
            frame[offset + channel] = ((color[channel] as u32 * alpha
                + frame[offset + channel] as u32 * (255 - alpha)
                + 127)
                / 255) as u8;
        }
        frame[offset + 3] = 255;
    }
}

fn fill_rect(
    frame: &mut [u8],
    width: u32,
    height: u32,
    x: i32,
    y: i32,
    w: i32,
    h: i32,
    color: [u8; 4],
) {
    for py in y..y + h {
        for px in x..x + w {
            blend(frame, width, height, px, py, color);
        }
    }
}

fn draw_text(
    frame: &mut [u8],
    width: u32,
    height: u32,
    mut x: i32,
    y: i32,
    text: &str,
    color: [u8; 4],
) {
    for ch in text.chars() {
        let rows = glyph(ch);
        for (row, bits) in rows.iter().enumerate() {
            for column in 0..GLYPH_WIDTH {
                if bits & (1 << (GLYPH_WIDTH - 1 - column)) != 0 {
                    for sy in 0..SCALE {
                        for sx in 0..SCALE {
                            blend(
                                frame,
                                width,
                                height,
                                x + (column * SCALE + sx) as i32,
                                y + (row as u32 * SCALE + sy) as i32,
                                color,
                            );
                        }
                    }
                }
            }
        }
        x += (ADVANCE * SCALE) as i32;
    }
}

fn clock_text(minutes: u32) -> String {
    format!("{:02}:{:02}", (minutes / 60) % 24, minutes % 60)
}

pub fn draw_status(
    frame: &mut [u8],
    width: u32,
    height: u32,
    snapshot: &Snapshot,
    profile: Option<&CharacterProfile>,
    scenario: Option<&ScenarioSetup>,
) -> Result<(), String> {
    if frame.len() != (width * height * 4) as usize {
        return Err("overlay frame has the wrong size".into());
    }
    let panel_x = 12;
    let panel_y = 12;
    let (panel_w, panel_h) = if scenario.is_some() {
        (620, 256)
    } else if profile.is_some() {
        (620, 232)
    } else {
        (520, 184)
    };
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        panel_h,
        [8, 10, 14, 210],
    );
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        2,
        [210, 170, 80, 255],
    );
    let line_height = 24;
    let mut y = panel_y + 12;
    let open_color = if snapshot.open {
        [120, 230, 130, 255]
    } else {
        [240, 120, 110, 255]
    };
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        y,
        if snapshot.open {
            "BRANCH: OPEN"
        } else {
            "BRANCH: CLOSED"
        },
        open_color,
    );
    y += line_height;
    if let Some(profile) = profile {
        let mode = match profile.mode {
            GameMode::Campaign => "CAMPAIGN",
            GameMode::FreeGame => "FREE GAME",
        };
        draw_text(
            frame,
            width,
            height,
            panel_x + 14,
            y,
            &format!(
                "PLAYER: {}   MODE: {}",
                if profile.player_name.is_empty() {
                    "(unnamed)"
                } else {
                    &profile.player_name
                },
                mode
            ),
            [235, 235, 235, 255],
        );
        y += line_height;
        draw_text(
            frame,
            width,
            height,
            panel_x + 14,
            y,
            &format!(
                "COMPANY: {}",
                if profile.enterprise_name.is_empty() {
                    "(unnamed)"
                } else {
                    &profile.enterprise_name
                }
            ),
            [235, 235, 235, 255],
        );
        y += line_height;
    }
    if let Some(scenario) = scenario {
        draw_text(
            frame,
            width,
            height,
            panel_x + 14,
            y,
            &format!(
                "CITY: {} ({})   POP: {}   LENGTH: {}Y   OPP: {}/{}/{}",
                scenario.city_name,
                scenario.city_code.to_ascii_uppercase(),
                scenario.population,
                scenario.game_length_years,
                scenario.opponents[0],
                scenario.opponents[1],
                scenario.opponents[2]
            ),
            [235, 235, 235, 255],
        );
        y += line_height;
    }
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        y,
        &format!(
            "CLOCK: {}   CASH: {:.2}",
            clock_text(snapshot.clock_minutes),
            snapshot.cash
        ),
        [235, 235, 235, 255],
    );
    y += line_height;
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        y,
        &format!(
            "STOCK: {:.0}/{:.0}   PRICE: {:.2}",
            snapshot.stock, snapshot.stock_capacity, snapshot.price
        ),
        [235, 235, 235, 255],
    );
    y += line_height;
    let last = snapshot
        .last_sale
        .as_ref()
        .map(|sale| {
            format!(
                "LAST SALE: {:.2}  STOCK -{}",
                sale.cash_delta, sale.servings
            )
        })
        .unwrap_or_else(|| "LAST SALE: NONE".to_string());
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        y,
        &last,
        [235, 235, 235, 255],
    );
    y += line_height;
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        y,
        &format!(
            "SERVED: {}   SALES: {}   LOST: {}",
            snapshot.customers_served, snapshot.sales, snapshot.customers_lost
        ),
        [235, 235, 235, 255],
    );
    y += line_height;
    if scenario.is_some() {
        draw_text(
            frame,
            width,
            height,
            panel_x + 14,
            y,
            "1/2/3 HIRE   W WAREHOUSE   S SUPPLIER   V ROUTE   R RECIPE   H HOURS",
            [200, 200, 210, 255],
        );
        y += line_height;
    }
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        y,
        "O OPEN/CLOSE   P PARTY   -/+ PRICE   SPACE STEP",
        [200, 200, 210, 255],
    );
    Ok(())
}

/// Mission strip shared by the city and branch views.
pub fn draw_briefing(
    frame: &mut [u8],
    width: u32,
    height: u32,
    city: &str,
    goals: &str,
    next_action: &str,
) -> Result<(), String> {
    let panel_x = 80;
    let panel_y = 80;
    let panel_w = 640i32;
    let panel_h = 240i32;
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        panel_h,
        [8, 10, 14, 242],
    );
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        2,
        [210, 170, 80, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 16,
        panel_y + 14,
        &format!("MISSION BRIEFING - {city}"),
        [210, 170, 80, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 16,
        panel_y + 44,
        "OBJECTIVES",
        [235, 235, 235, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 16,
        panel_y + 68,
        goals,
        [220, 220, 220, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 16,
        panel_y + 112,
        "NEXT ACTION",
        [120, 210, 250, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 16,
        panel_y + 136,
        next_action,
        [235, 235, 235, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 16,
        panel_y + 184,
        "ENTER / ESC DISMISS",
        [200, 200, 210, 255],
    );
    Ok(())
}

pub fn draw_hours_panel(
    frame: &mut [u8],
    width: u32,
    height: u32,
    open: u8,
    close: u8,
    edit_close: bool,
    status: Option<&str>,
) -> Result<(), String> {
    let panel_x = 120;
    let panel_y = 160;
    let panel_w = 420i32;
    let panel_h = 150i32;
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        panel_h,
        [8, 10, 14, 238],
    );
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        2,
        [120, 210, 250, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 12,
        "OPENING HOURS",
        [120, 210, 250, 255],
    );
    let open_mark = if edit_close { " " } else { ">" };
    let close_mark = if edit_close { ">" } else { " " };
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 42,
        &format!("{open_mark} OPEN  {open:02}:00"),
        [235, 235, 235, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 66,
        &format!("{close_mark} CLOSE {close:02}:00"),
        [235, 235, 235, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 98,
        "1 OPEN  2 CLOSE  +/- HOUR  ENTER SAVE  ESC",
        [200, 200, 210, 255],
    );
    if let Some(status) = status {
        draw_text(
            frame,
            width,
            height,
            panel_x + 14,
            panel_y + 120,
            status,
            [235, 210, 150, 255],
        );
    }
    Ok(())
}

pub fn draw_result_screen(
    frame: &mut [u8],
    width: u32,
    height: u32,
    city: &str,
    goals: &str,
    cash: f64,
    revenue: f64,
) -> Result<(), String> {
    let panel_x = 80;
    let panel_y = 80;
    let panel_w = 640i32;
    let panel_h = 260i32;
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        panel_h,
        [8, 10, 14, 245],
    );
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        3,
        [110, 230, 130, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 18,
        panel_y + 16,
        &format!("{city} COMPLETE"),
        [110, 230, 130, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 18,
        panel_y + 48,
        "ALL MISSION OBJECTIVES COMPLETE",
        [235, 235, 235, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 18,
        panel_y + 82,
        goals,
        [220, 220, 220, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 18,
        panel_y + 126,
        &format!("CASH {cash:.2}   REVENUE {revenue:.2}"),
        [235, 235, 235, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 18,
        panel_y + 170,
        "ENTER CONTINUE   S SAVE   L LOAD",
        [200, 200, 210, 255],
    );
    Ok(())
}

pub fn draw_branch_reason(frame: &mut [u8], width: u32, height: u32, reason: &str) {
    let y = height.saturating_sub(28) as i32;
    fill_rect(frame, width, height, 12, y - 6, 360, 24, [8, 10, 14, 210]);
    draw_text(frame, width, height, 22, y, reason, [240, 180, 120, 255]);
}

pub fn draw_mission_hud(
    frame: &mut [u8],
    width: u32,
    height: u32,
    summary: &str,
    goals: &str,
    complete: bool,
) {
    let panel_x = 12;
    let panel_y = height.saturating_sub(92) as i32;
    let panel_w = width.saturating_sub(24) as i32;
    let panel_h = 80;
    let border = if complete {
        [110, 230, 130, 255]
    } else {
        [210, 170, 80, 255]
    };
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        panel_h,
        [8, 10, 14, 220],
    );
    fill_rect(frame, width, height, panel_x, panel_y, panel_w, 2, border);
    draw_text(
        frame,
        width,
        height,
        panel_x + 12,
        panel_y + 8,
        summary,
        [235, 235, 235, 255],
    );
    let max_chars = ((panel_w - 24) / (ADVANCE * SCALE) as i32).max(20) as usize;
    let (line_one, line_two) = if goals.chars().count() <= max_chars {
        (goals, "")
    } else {
        let cut = goals
            .char_indices()
            .take(max_chars + 1)
            .filter(|(_, ch)| *ch == ' ')
            .map(|(index, _)| index)
            .last()
            .unwrap_or(goals.len());
        (&goals[..cut], goals[cut..].trim_start())
    };
    draw_text(
        frame,
        width,
        height,
        panel_x + 12,
        panel_y + 28,
        line_one,
        [200, 200, 210, 255],
    );
    if !line_two.is_empty() {
        draw_text(
            frame,
            width,
            height,
            panel_x + 12,
            panel_y + 44,
            line_two,
            [200, 200, 210, 255],
        );
    }
    if complete {
        draw_text(
            frame,
            width,
            height,
            panel_x + 12,
            panel_y + 60,
            "MISSION COMPLETE",
            [120, 230, 130, 255],
        );
    }
}

pub fn draw_lease_marker(frame: &mut [u8], width: u32, height: u32, x: i32, y: i32) {
    let color = [120, 210, 250, 255];
    fill_rect(frame, width, height, x - 13, y - 3, 27, 2, color);
    fill_rect(frame, width, height, x - 1, y - 7, 2, 10, color);
}

pub fn draw_hq_marker(
    frame: &mut [u8],
    width: u32,
    height: u32,
    x: i32,
    y: i32,
    progress: Option<f32>,
) {
    let color = [120, 230, 150, 255];
    fill_rect(frame, width, height, x - 12, y - 12, 25, 25, color);
    fill_rect(frame, width, height, x - 4, y - 4, 9, 9, [20, 50, 30, 255]);
    if let Some(progress) = progress {
        let clamped = progress.clamp(0.0, 1.0);
        fill_rect(
            frame,
            width,
            height,
            x - 16,
            y + 17,
            33,
            5,
            [20, 40, 26, 255],
        );
        let filled = (31.0 * clamped) as i32;
        fill_rect(
            frame,
            width,
            height,
            x - 15,
            y + 18,
            filled.max(0),
            3,
            [250, 210, 90, 255],
        );
    }
}

pub fn draw_rival_marker(frame: &mut [u8], width: u32, height: u32, x: i32, y: i32, pending: bool) {
    let color = if pending {
        [250, 210, 90, 255]
    } else {
        [245, 100, 100, 255]
    };
    fill_rect(frame, width, height, x - 12, y - 12, 25, 4, color);
    fill_rect(frame, width, height, x - 12, y + 8, 25, 4, color);
    fill_rect(frame, width, height, x - 3, y - 16, 7, 32, color);
}

pub fn draw_mission_panel(
    frame: &mut [u8],
    width: u32,
    height: u32,
    title: &str,
    detail: &str,
    status: Option<&str>,
) -> Result<(), String> {
    let panel_x = 120;
    let panel_y = 160;
    let panel_w = 480i32;
    let panel_h = 160i32;
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        panel_h,
        [8, 10, 14, 238],
    );
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        2,
        [210, 170, 80, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 12,
        title,
        [210, 170, 80, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 42,
        detail,
        [235, 235, 235, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 76,
        "ENTER CONFIRM   ESC CLOSE",
        [200, 200, 210, 255],
    );
    if let Some(status) = status {
        draw_text(
            frame,
            width,
            height,
            panel_x + 14,
            panel_y + 108,
            status,
            [235, 210, 150, 255],
        );
    }
    Ok(())
}

pub fn draw_recipe_editor(
    frame: &mut [u8],
    width: u32,
    height: u32,
    tomato: u32,
    cheese: u32,
    saved: bool,
    on_menu: bool,
    price: f64,
    status: Option<&str>,
) -> Result<(), String> {
    if frame.len() != (width * height * 4) as usize {
        return Err("overlay frame has the wrong size".into());
    }
    let panel_x = 48;
    let panel_y = 48;
    let panel_w = 560i32;
    let panel_h = 210i32;
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        panel_h,
        [10, 12, 16, 238],
    );
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        2,
        [220, 150, 230, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 12,
        "RECIPE EDITOR",
        [220, 150, 230, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 38,
        &format!("TOMATO {tomato}   CHEESE {cheese}"),
        [235, 235, 235, 255],
    );
    let saved_line = if saved {
        format!(
            "SAVED {}   MENU {}   PRICE {:.2}",
            tomato + cheese,
            if on_menu { "YES" } else { "NO" },
            price
        )
    } else {
        "NOT SAVED".to_string()
    };
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 62,
        &saved_line,
        [235, 235, 235, 255],
    );
    let preview_x = panel_x + 360;
    let preview_y = panel_y + 34;
    fill_rect(
        frame,
        width,
        height,
        preview_x,
        preview_y,
        120,
        120,
        [225, 190, 130, 255],
    );
    fill_rect(
        frame,
        width,
        height,
        preview_x + 10,
        preview_y + 10,
        100,
        100,
        [240, 210, 150, 255],
    );
    let tomato_dots = tomato.min(25) as i32;
    for i in 0..tomato_dots {
        let x = preview_x + 14 + (i % 5) * 20;
        let y = preview_y + 14 + (i / 5) * 20;
        fill_rect(frame, width, height, x, y, 12, 12, [220, 60, 55, 255]);
    }
    let cheese_dots = cheese.min(25) as i32;
    for i in 0..cheese_dots {
        let x = preview_x + 14 + (i % 5) * 20 + 6;
        let y = preview_y + 14 + (i / 5) * 20 + 6;
        fill_rect(frame, width, height, x, y, 8, 8, [250, 220, 80, 255]);
    }
    draw_text(
        frame,
        width,
        height,
        preview_x + 10,
        preview_y + 102,
        "PIZZA PREVIEW",
        [110, 80, 30, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 96,
        "T ADD TOMATO   C ADD CHEESE   ENTER SAVE",
        [200, 200, 210, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 120,
        "A ADD TO MENU   +/- PRICE   ESC CLOSE",
        [200, 200, 210, 255],
    );
    if let Some(status) = status {
        draw_text(
            frame,
            width,
            height,
            panel_x + 14,
            panel_y + 152,
            status,
            [235, 210, 150, 255],
        );
    }
    Ok(())
}

pub fn draw_supply_marker(frame: &mut [u8], width: u32, height: u32, x: i32, y: i32) {
    let color = [245, 180, 80, 255];
    fill_rect(frame, width, height, x - 15, y - 3, 31, 2, color);
    fill_rect(frame, width, height, x - 3, y - 11, 7, 15, color);
    fill_rect(frame, width, height, x - 7, y - 7, 15, 7, color);
}

pub fn draw_supply_office(
    frame: &mut [u8],
    width: u32,
    height: u32,
    storage_id: Option<u32>,
    warehouse_name: Option<&str>,
    supplier: Option<&str>,
    route_enabled: bool,
    stock: f64,
    due_hour: Option<u8>,
    status: Option<&str>,
) -> Result<(), String> {
    if frame.len() != (width * height * 4) as usize {
        return Err("overlay frame has the wrong size".into());
    }
    let panel_x = 48;
    let panel_y = 48;
    let panel_w = 560i32;
    let panel_h = 210i32;
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        panel_h,
        [8, 10, 14, 238],
    );
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        2,
        [245, 180, 80, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 12,
        "SUPPLY OFFICE",
        [245, 180, 80, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 38,
        &format!(
            "STORAGE {}   {}",
            storage_id.map_or("UNASSIGNED".to_string(), |id| id.to_string()),
            warehouse_name.unwrap_or("NO WAREHOUSE")
        ),
        [235, 235, 235, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 62,
        &format!("SUPPLIER: {}", supplier.unwrap_or("NONE")),
        [235, 235, 235, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 86,
        &format!(
            "ROUTE: {}   STOCK {:.0}",
            if route_enabled {
                "ATRIUM ENABLED"
            } else {
                "DISABLED"
            },
            stock
        ),
        [235, 235, 235, 255],
    );
    let control = if storage_id.is_none() {
        "ENTER LEASE LONDON 1   ESC CLOSE"
    } else if supplier.is_none() {
        "S SELECT CENTRAL MARKET PARTNERS   ESC CLOSE"
    } else if !route_enabled {
        "R ENABLE ATRIUM ROUTE   ESC CLOSE"
    } else {
        &format!("ROUTE ACTIVE   FIRST BATCH {:02}:00", due_hour.unwrap_or(9))
    };
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 120,
        control,
        [200, 200, 210, 255],
    );
    if let Some(status) = status {
        draw_text(
            frame,
            width,
            height,
            panel_x + 14,
            panel_y + 148,
            status,
            [235, 210, 150, 255],
        );
    }
    Ok(())
}

pub fn draw_lease_terms(
    frame: &mut [u8],
    width: u32,
    height: u32,
    tile: u32,
    price: u32,
    fee: u32,
    cash: f64,
) -> Result<(), String> {
    if frame.len() != (width * height * 4) as usize {
        return Err("overlay frame has the wrong size".into());
    }
    let panel_w = 420i32;
    let panel_h = 180i32;
    let panel_x = (width as i32 - panel_w) / 2;
    let panel_y = height as i32 - panel_h - 24;
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        panel_h,
        [8, 10, 14, 235],
    );
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        2,
        [120, 210, 250, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 12,
        "VACANT STOREFRONT",
        [120, 210, 250, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 36,
        &format!("PROPERTY {tile}   LEASE {price}   FEE {fee}"),
        [235, 235, 235, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 60,
        &format!("TOTAL {}   CASH {:.2}", price.saturating_add(fee), cash),
        [235, 235, 235, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 88,
        "ENTER CONFIRM   ESC CANCEL",
        [200, 200, 210, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 108,
        "CLICK CONFIRM / CANCEL",
        [160, 190, 200, 255],
    );
    Ok(())
}

pub fn draw_lease_buttons(frame: &mut [u8], width: u32, height: u32) -> Result<(), String> {
    if frame.len() != (width * height * 4) as usize {
        return Err("overlay frame has the wrong size".into());
    }
    let (confirm, cancel) = crate::lease_button_rects(width, height);
    draw_button(frame, width, height, confirm, "CONFIRM");
    draw_button(frame, width, height, cancel, "CANCEL");
    Ok(())
}

fn draw_button(frame: &mut [u8], width: u32, height: u32, rect: (i32, i32, u32, u32), label: &str) {
    let (x, y, w, h) = rect;
    let (w, h) = (w as i32, h as i32);
    fill_rect(frame, width, height, x, y, w, h, [30, 62, 88, 255]);
    fill_rect(frame, width, height, x, y, w, 1, [140, 220, 250, 255]);
    draw_text(
        frame,
        width,
        height,
        x + 12,
        y + 8,
        label,
        [240, 240, 240, 255],
    );
}

fn employee_role_label(role: EmployeeRole) -> &'static str {
    match role {
        EmployeeRole::Cook => "COOK",
        EmployeeRole::Service => "SERVICE",
        EmployeeRole::Errand => "ERRAND",
    }
}

pub fn draw_employment_office(
    frame: &mut [u8],
    width: u32,
    height: u32,
    selected: usize,
    candidates: &[EmployeeCandidate],
    roster: &[Employee],
    branch_id: u32,
    status: Option<&str>,
) -> Result<(), String> {
    if frame.len() != (width * height * 4) as usize {
        return Err("overlay frame has the wrong size".into());
    }
    let panel_x = 48;
    let panel_y = 48;
    let panel_w = 560i32;
    let panel_h = 228i32;
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        panel_h,
        [8, 10, 14, 238],
    );
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        2,
        [120, 210, 250, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 12,
        "EMPLOYMENT OFFICE",
        [120, 210, 250, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 34,
        &format!("BRANCH {branch_id}   ROSTER {}", roster.len()),
        [235, 235, 235, 255],
    );
    let mut y = panel_y + 60;
    for (index, candidate) in candidates.iter().enumerate() {
        let marker = if index == selected { ">" } else { " " };
        let hired = roster.iter().any(|employee| employee.id == candidate.id);
        let suffix = if hired { "  HIRED" } else { "" };
        draw_text(
            frame,
            width,
            height,
            panel_x + 14,
            y,
            &format!(
                "{marker} CANDIDATE {}   {}{suffix}",
                candidate.id,
                employee_role_label(candidate.role)
            ),
            if hired {
                [150, 220, 150, 255]
            } else {
                [235, 235, 235, 255]
            },
        );
        y += 22;
    }
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 160,
        "UP/DOWN SELECT   ENTER HIRE   ESC CLOSE",
        [200, 200, 210, 255],
    );
    if let Some(status) = status {
        draw_text(
            frame,
            width,
            height,
            panel_x + 14,
            panel_y + 184,
            status,
            [235, 210, 150, 255],
        );
    }
    Ok(())
}

pub fn draw_city_status(
    frame: &mut [u8],
    width: u32,
    height: u32,
    camera: (i32, i32),
    city_size: (u32, u32),
    controls: &str,
    campaign_summary: Option<&str>,
) -> Result<(), String> {
    if frame.len() != (width * height * 4) as usize {
        return Err("overlay frame has the wrong size".into());
    }
    let panel_x = 12;
    let panel_y = 12;
    let panel_w = 520;
    let panel_h = 112;
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        panel_h,
        [8, 10, 14, 210],
    );
    fill_rect(
        frame,
        width,
        height,
        panel_x,
        panel_y,
        panel_w,
        2,
        [90, 170, 230, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 12,
        "CITY VIEW",
        [120, 210, 250, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 36,
        &format!(
            "CAMERA: {},{}  MAP: {}x{}",
            camera.0, camera.1, city_size.0, city_size.1
        ),
        [235, 235, 235, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 60,
        controls,
        [200, 200, 210, 255],
    );
    draw_text(
        frame,
        width,
        height,
        panel_x + 14,
        panel_y + 84,
        campaign_summary.unwrap_or("CITY CROP IS CACHED; NO MAP RELOAD"),
        [170, 170, 180, 255],
    );
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;
    use pc2_sim::BranchSim;

    #[test]
    fn overlay_draws_status_text() {
        let mut frame = vec![0u8; 800 * 600 * 4];
        let sim = BranchSim::new();
        draw_status(&mut frame, 800, 600, &sim.snapshot(), None, None).unwrap();
        assert!(frame
            .chunks_exact(4)
            .any(|pixel| pixel[3] == 255 && pixel[0] > 0));
        assert_ne!(frame, vec![0u8; 800 * 600 * 4]);
    }
}
