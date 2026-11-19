//! Visible branch actors: the static waiter and the kid customer animation.

use std::sync::Arc;

use pc2_assets::{Ani, GameInstall, Sprite};
use pc2_sim::Snapshot;

pub struct ActorFrame {
    pub width: u32,
    pub height: u32,
    pub pixels: Arc<Vec<u8>>,
}

pub struct Actors {
    pub staff: ActorFrame,
    pub customer: Vec<ActorFrame>,
}

impl Actors {
    pub fn load(install: &mut GameInstall) -> Result<Self, String> {
        let staff_data = install
            .read_asset("sprites\\m_service_m01.spr")
            .map_err(|error| error.to_string())?
            .ok_or("m_service_m01.spr is missing")?;
        let staff = Sprite::load(&staff_data).map_err(|error| error.to_string())?;
        let customer_data = install
            .read_asset("isodaten\\anims\\kid_m_sma.ani")
            .map_err(|error| error.to_string())?
            .ok_or("kid_m_sma.ani is missing")?;
        let customer = Ani::load(&customer_data).map_err(|error| error.to_string())?;
        let customer = customer
            .frames
            .into_iter()
            .take(24)
            .map(|frame| ActorFrame {
                width: frame.width,
                height: frame.height,
                pixels: frame.pixels,
            })
            .collect::<Vec<_>>();
        if customer.is_empty() {
            return Err("kid_m_sma.ani has no frames".into());
        }
        Ok(Self {
            staff: ActorFrame {
                width: staff.width,
                height: staff.height,
                pixels: Arc::new(staff.pixels),
            },
            customer,
        })
    }
}

fn blend(
    frame: &mut [u8],
    width: u32,
    height: u32,
    actor: &ActorFrame,
    x: i32,
    y: i32,
    scale: i32,
) {
    for sy in 0..actor.height as i32 {
        for sx in 0..actor.width as i32 {
            let source = ((sy as u32 * actor.width + sx as u32) * 4) as usize;
            let alpha = actor.pixels[source + 3] as u32;
            if alpha == 0 {
                continue;
            }
            for oy in 0..scale {
                for ox in 0..scale {
                    let px = x + sx * scale + ox;
                    let py = y + sy * scale + oy;
                    if px < 0 || py < 0 || px >= width as i32 || py >= height as i32 {
                        continue;
                    }
                    let target = ((py as u32 * width + px as u32) * 4) as usize;
                    if alpha == 255 {
                        frame[target..target + 4]
                            .copy_from_slice(&actor.pixels[source..source + 4]);
                    } else {
                        for channel in 0..3 {
                            let value = actor.pixels[source + channel] as u32;
                            let old = frame[target + channel] as u32;
                            frame[target + channel] =
                                ((value * alpha + old * (255 - alpha) + 127) / 255) as u8;
                        }
                        frame[target + 3] = 255;
                    }
                }
            }
        }
    }
}

pub fn compose(
    base: &[u8],
    width: u32,
    height: u32,
    actors: &Actors,
    snapshot: &Snapshot,
    customer_visible: bool,
) -> Result<Vec<u8>, String> {
    if base.len() != (width * height * 4) as usize {
        return Err("actor frame has the wrong size".into());
    }
    let mut frame = base.to_vec();
    if !snapshot.open {
        return Ok(frame);
    }
    // Waiter behind the counter; kid customer on the dining floor. The kid is
    // a small-frame animation, so draw it at 2x to read at this zoom.
    blend(&mut frame, width, height, &actors.staff, 340, 440, 1);
    if customer_visible {
        // The animation follows the authoritative world clock, not the
        // legacy 15-minute branch step counter.
        let frame_index = (snapshot.clock_minutes / 5) as usize % actors.customer.len();
        let customer = &actors.customer[frame_index];
        blend(&mut frame, width, height, customer, 470, 420, 2);
    }
    Ok(frame)
}

#[cfg(test)]
mod tests {
    use super::*;
    use pc2_sim::BranchSim;

    fn solid_actor(width: u32, height: u32, color: [u8; 4]) -> ActorFrame {
        ActorFrame {
            width,
            height,
            pixels: Arc::new(color.repeat((width * height) as usize)),
        }
    }

    #[test]
    fn actors_only_show_when_open() {
        let actors = Actors {
            staff: solid_actor(2, 2, [255, 0, 0, 255]),
            customer: vec![solid_actor(2, 2, [0, 255, 0, 255])],
        };
        let base = vec![0u8; 800 * 600 * 4];
        let mut sim = BranchSim::new();
        let closed = compose(&base, 800, 600, &actors, &sim.snapshot(), false).unwrap();
        assert_eq!(closed, base);
        sim.set_open(true);
        let open = compose(&base, 800, 600, &actors, &sim.snapshot(), true).unwrap();
        assert_ne!(open, base);
        assert_eq!(&open[((440 * 800) + 340) * 4..][0..4], &[255, 0, 0, 255]);
    }
}
