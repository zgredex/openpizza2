use std::process::ExitCode;

use pc2_sim::{ClockEvent, ClockReplay};

fn parse_time(value: &str) -> Result<u32, String> {
    let (hour, minute) = value
        .split_once(':')
        .ok_or_else(|| format!("invalid time {value}; expected HH:MM"))?;
    let hour: u32 = hour.parse().map_err(|_| "invalid hour")?;
    let minute: u32 = minute.parse().map_err(|_| "invalid minute")?;
    if hour > 23 || minute > 59 || minute % 5 != 0 {
        return Err(format!("invalid clock time {value}"));
    }
    Ok(hour * 60 + minute)
}

fn label(minute: u32) -> String {
    let day = minute / (24 * 60);
    let minute_of_day = minute % (24 * 60);
    if day == 0 {
        format!("{:02}:{:02}", minute_of_day / 60, minute_of_day % 60)
    } else {
        format!(
            "D+{} {:02}:{:02}",
            day,
            minute_of_day / 60,
            minute_of_day % 60
        )
    }
}

fn print_events(events: &[ClockEvent]) {
    for event in events {
        match event {
            ClockEvent::Tick { minute } => println!("{} tick", label(*minute)),
            ClockEvent::Hourly {
                minute,
                hour,
                hour_index,
            } => {
                println!("{} hourly hour={hour} index={hour_index}", label(*minute))
            }
            ClockEvent::Phase(phase) => println!("  phase {phase}"),
            ClockEvent::Arrival { minute, queue } => {
                println!("{} arrival queue={queue}", label(*minute))
            }
            ClockEvent::ProductionStart { minute } => {
                println!("{} production_start", label(*minute))
            }
            ClockEvent::QueueService {
                minute,
                remaining_queue,
            } => {
                println!(
                    "{} queue_service remaining={remaining_queue}",
                    label(*minute)
                )
            }
            ClockEvent::Sale {
                minute,
                stock,
                cash_delta,
            } => {
                println!(
                    "{} sale stock={stock:.0} cash_delta={cash_delta:.6}",
                    label(*minute)
                )
            }
            ClockEvent::Departure { minute } => println!("{} departure", label(*minute)),
            ClockEvent::QuarterBoundary { minute, hour } => {
                println!("{} quarter_boundary hour={hour}", label(*minute))
            }
        }
    }
}

fn main() -> ExitCode {
    let mut args = std::env::args().skip(1);
    let mut start = 10 * 60 + 55;
    let mut end = 11 * 60 + 5;
    let mut queue = 0u32;
    let mut resume_check = false;
    let mut snapshot_at: Option<u32> = None;
    while let Some(arg) = args.next() {
        match arg.as_str() {
            "--start" => match args.next().and_then(|value| parse_time(&value).ok()) {
                Some(value) => start = value,
                None => return ExitCode::FAILURE,
            },
            "--end" => match args.next().and_then(|value| parse_time(&value).ok()) {
                Some(value) => end = value,
                None => return ExitCode::FAILURE,
            },
            "--queue" => {
                queue = args
                    .next()
                    .and_then(|value| value.parse().ok())
                    .unwrap_or(0)
            }
            "--snapshot-resume" => resume_check = true,
            "--snapshot-at" => {
                let value = match args.next().and_then(|value| parse_time(&value).ok()) {
                    Some(value) => value,
                    None => return ExitCode::FAILURE,
                };
                snapshot_at = Some(value);
                resume_check = true;
            }
            "-h" | "--help" => {
                println!("usage: pc2-clock [--start HH:MM] [--end HH:MM] [--queue N] [--snapshot-at HH:MM] [--snapshot-resume]");
                return ExitCode::SUCCESS;
            }
            other => {
                eprintln!("unknown argument: {other}");
                return ExitCode::FAILURE;
            }
        }
    }
    if end < start {
        end += 24 * 60;
    }
    let mut replay = ClockReplay::new(start).with_queue(queue);
    let mut events = Vec::new();
    if let Some(at) = snapshot_at {
        if at > start {
            events.extend(replay.advance_to(at));
        }
    }
    let snapshot = replay.world_snapshot();
    let suffix = replay.advance_to(end);
    events.extend(suffix.iter().cloned());
    print_events(&events);
    let hourly = events
        .iter()
        .filter(|event| matches!(event, ClockEvent::Hourly { .. }))
        .count();
    let quarter = events
        .iter()
        .filter(|event| matches!(event, ClockEvent::QuarterBoundary { .. }))
        .count();
    println!("hourly_count={hourly}");
    println!("quarter_boundary_count={quarter}");
    if resume_check {
        let mut restored = ClockReplay::from_snapshot(&snapshot);
        let resumed = restored.advance_to(end);
        let identical = resumed == suffix && restored.snapshot() == replay.snapshot();
        println!(
            "snapshot_resume={}",
            if identical { "identical" } else { "DIFFERENT" }
        );
        if !identical {
            return ExitCode::FAILURE;
        }
    }
    println!("branch_clock={}", label(replay.snapshot().clock_minutes));
    println!("final={}", label(end));
    ExitCode::SUCCESS
}
