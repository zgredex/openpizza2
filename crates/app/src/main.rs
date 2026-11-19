use std::path::{Path, PathBuf};

mod actors;
mod campaign;
mod character_select;
mod free_play_setup;
mod menu;
mod overlay;
mod widgets;
use std::process::ExitCode;
use std::sync::Arc;
use std::time::Instant;

use pc2_assets::GameInstall;
use pc2_scene::{Scene, SceneOptions};
use pc2_sim::World;
use winit::application::ApplicationHandler;
use winit::event::{ElementState, KeyEvent, MouseButton, WindowEvent};
use winit::event_loop::{ActiveEventLoop, EventLoop};
use winit::keyboard::{Key, NamedKey};
use winit::window::{Window, WindowId};

const WINDOW_SHADER: &str = r#"
struct VertexOutput {
    @builtin(position) position: vec4<f32>,
    @location(0) uv: vec2<f32>,
};

@vertex
fn vs(@builtin(vertex_index) index: u32) -> VertexOutput {
    var positions = array<vec2<f32>, 6>(
        vec2<f32>(-1.0, -1.0),
        vec2<f32>( 1.0, -1.0),
        vec2<f32>( 1.0,  1.0),
        vec2<f32>(-1.0, -1.0),
        vec2<f32>( 1.0,  1.0),
        vec2<f32>(-1.0,  1.0),
    );
    var uvs = array<vec2<f32>, 6>(
        vec2<f32>(0.0, 1.0),
        vec2<f32>(1.0, 1.0),
        vec2<f32>(1.0, 0.0),
        vec2<f32>(0.0, 1.0),
        vec2<f32>(1.0, 0.0),
        vec2<f32>(0.0, 0.0),
    );
    var out: VertexOutput;
    out.position = vec4<f32>(positions[index], 0.0, 1.0);
    out.uv = uvs[index];
    return out;
}

@group(0) @binding(0) var source: texture_2d<f32>;
@group(0) @binding(1) var source_sampler: sampler;

@fragment
fn fs(in: VertexOutput) -> @location(0) vec4<f32> {
    return textureSample(source, source_sampler, in.uv);
}
"#;

#[derive(Clone, Debug)]
struct Args {
    install: PathBuf,
    map: PathBuf,
    center: Option<(i32, i32)>,
    width: u32,
    height: u32,
    output: PathBuf,
    json: Option<PathBuf>,
    window: bool,
    frames: u32,
    vulkan: bool,
    animate: bool,
    animation_frame: usize,
    playable: bool,
    replay: Option<String>,
    playable_script: Option<String>,
    explore: bool,
    branch_map: PathBuf,
    menu: bool,
    menu_script: Option<String>,
    menu_selected: Option<usize>,
    character_select: bool,
    character_script: Option<String>,
    campaign_start: bool,
    free_play_setup: bool,
    free_play_chain: bool,
    free_play_script: Option<String>,
    free_play_selected: Option<usize>,
    character_profile: Option<String>,
    scenario: Option<String>,
    free_game: bool,
    output_explicit: bool,
    branch_map_explicit: bool,
}

impl Default for Args {
    fn default() -> Self {
        Self {
            install: PathBuf::from("game"),
            map: PathBuf::from("game/Isokarten/Ber.iso"),
            center: None,
            width: 800,
            height: 600,
            output: PathBuf::from("berlin_crop.png"),
            json: None,
            window: false,
            frames: 0,
            vulkan: true,
            animate: false,
            animation_frame: 0,
            playable: false,
            replay: None,
            playable_script: None,
            explore: false,
            branch_map: PathBuf::from("game/Isokarten/Iso_Filiale_einf_klein.iso"),
            menu: false,
            menu_script: None,
            menu_selected: None,
            character_select: false,
            character_script: None,
            campaign_start: false,
            free_play_setup: false,
            free_play_chain: false,
            free_play_script: None,
            free_play_selected: None,
            character_profile: None,
            scenario: None,
            free_game: false,
            output_explicit: false,
            branch_map_explicit: false,
        }
    }
}

fn usage(program: &str) {
    eprintln!(
        "usage: {program} [options]\n\
         \n\
         --install PATH       installation root (default: game)\n\
         --map PATH           .iso map (default: game/Isokarten/Ber.iso)\n\
         --center X,Y         camera centre in map world coordinates\n\
         --width N            crop width (default: 800)\n\
         --height N           crop height (default: 600)\n\
         --output PATH        PNG output (default: berlin_crop.png)\n\
         --json PATH          write the ordered draw list as JSON\n\
         --window             open the Vulkan window instead of headless output\n\
         --frames N           close the window after N frames (0 = until Esc)\n\
         --animate            use decoded .ani tree-sway frames in the window\n\
         --animation-frame N  render still frame N of the animation\n\
         --playable           interactive branch: O open/close, -/+ price, Space step 5 min\n\
         --replay SCRIPT      headless world commands, e.g. open;step;step;step\n\
         --playable-script S  run world commands, plus lease=N and branch in Campaign Start\n\
         --explore            city camera + B branch / C city transition\n\
         --menu               rebuild the original main menu screen\n\
         --menu-script SCRIPT headless menu commands: up,down,enter,select:N\n\
         --menu-selected N    initial menu selection (0..5)\n\
         --character-select   original Start New Game character screen\n\
         --character-script S headless character-screen commands\n\
         --campaign-start     load the first installed campaign mission\n\
         --free-play-setup    original Free Play Setup screen (state 0x18)\n\
         --free-play-chain    headless menu -> character -> setup -> first-sale chain\n\
         --free-play-script S headless setup-screen commands\n\
         --free-play-selected N initial setup selection (0=Back, 1=Start)\n\
         --character-profile S internal Start-game profile handoff\n\
         --scenario S        internal Free Play Setup handoff (city/population/length/opponents)\n\
         --free-game         mark the profile as Start Free Game\n\
         --branch-map PATH    branch used by --explore and menu start (default Iso_Filiale_einf_klein)\n\
         --no-vulkan          skip the offscreen Vulkan round-trip in headless mode"
    );
}

fn parse_args() -> Result<Args, String> {
    let mut args = Args::default();
    let argv = std::env::args().collect::<Vec<_>>();
    let program = argv.first().cloned().unwrap_or_else(|| "pc2-viewer".into());
    let mut index = 1;
    while index < argv.len() {
        match argv[index].as_str() {
            "--install" => {
                index += 1;
                args.install = PathBuf::from(argv.get(index).ok_or("missing --install value")?);
            }
            "--map" => {
                index += 1;
                args.map = PathBuf::from(argv.get(index).ok_or("missing --map value")?);
            }
            "--center" => {
                index += 1;
                let value = argv.get(index).ok_or("missing --center value")?;
                let (x, y) = value.split_once(',').ok_or("--center expects X,Y")?;
                args.center = Some((
                    x.trim().parse().map_err(|_| "invalid --center X")?,
                    y.trim().parse().map_err(|_| "invalid --center Y")?,
                ));
            }
            "--width" => {
                index += 1;
                args.width = argv
                    .get(index)
                    .ok_or("missing --width value")?
                    .parse()
                    .map_err(|_| "invalid --width")?;
            }
            "--height" => {
                index += 1;
                args.height = argv
                    .get(index)
                    .ok_or("missing --height value")?
                    .parse()
                    .map_err(|_| "invalid --height")?;
            }
            "--output" => {
                index += 1;
                args.output = PathBuf::from(argv.get(index).ok_or("missing --output value")?);
                args.output_explicit = true;
            }
            "--json" => {
                index += 1;
                args.json = Some(PathBuf::from(
                    argv.get(index).ok_or("missing --json value")?,
                ));
            }
            "--window" => args.window = true,
            "--frames" => {
                index += 1;
                args.frames = argv
                    .get(index)
                    .ok_or("missing --frames value")?
                    .parse()
                    .map_err(|_| "invalid --frames")?;
            }
            "--no-vulkan" => args.vulkan = false,
            "--animate" => args.animate = true,
            "--playable" => args.playable = true,
            "--replay" => {
                index += 1;
                args.replay = Some(argv.get(index).ok_or("missing --replay value")?.clone());
            }
            "--playable-script" => {
                index += 1;
                args.playable_script = Some(
                    argv.get(index)
                        .ok_or("missing --playable-script value")?
                        .clone(),
                );
            }
            "--explore" => args.explore = true,
            "--menu" => args.menu = true,
            "--menu-script" => {
                index += 1;
                args.menu_script = Some(
                    argv.get(index)
                        .ok_or("missing --menu-script value")?
                        .clone(),
                );
            }
            "--menu-selected" => {
                index += 1;
                args.menu_selected = Some(
                    argv.get(index)
                        .ok_or("missing --menu-selected value")?
                        .parse()
                        .map_err(|_| "invalid --menu-selected")?,
                );
            }
            "--character-select" => args.character_select = true,
            "--campaign-start" => args.campaign_start = true,
            "--free-play-setup" => args.free_play_setup = true,
            "--free-play-chain" => args.free_play_chain = true,
            "--free-play-script" => {
                index += 1;
                args.free_play_script = Some(
                    argv.get(index)
                        .ok_or("missing --free-play-script value")?
                        .clone(),
                );
            }
            "--free-play-selected" => {
                index += 1;
                args.free_play_selected = Some(
                    argv.get(index)
                        .ok_or("missing --free-play-selected value")?
                        .parse()
                        .map_err(|_| "invalid --free-play-selected")?,
                );
            }
            "--free-game" => args.free_game = true,
            "--character-profile" => {
                index += 1;
                args.character_profile = Some(
                    argv.get(index)
                        .ok_or("missing --character-profile value")?
                        .clone(),
                );
            }
            "--scenario" => {
                index += 1;
                args.scenario = Some(argv.get(index).ok_or("missing --scenario value")?.clone());
            }
            "--character-script" => {
                index += 1;
                args.character_script = Some(
                    argv.get(index)
                        .ok_or("missing --character-script value")?
                        .clone(),
                );
            }
            "--branch-map" => {
                index += 1;
                args.branch_map =
                    PathBuf::from(argv.get(index).ok_or("missing --branch-map value")?);
                args.branch_map_explicit = true;
            }
            "--animation-frame" => {
                index += 1;
                args.animate = true;
                args.animation_frame = argv
                    .get(index)
                    .ok_or("missing --animation-frame value")?
                    .parse()
                    .map_err(|_| "invalid --animation-frame")?;
            }
            "--help" | "-h" => {
                usage(&program);
                std::process::exit(0);
            }
            other => return Err(format!("unknown argument: {other}")),
        }
        index += 1;
    }
    if args.width == 0 || args.height == 0 {
        return Err("crop dimensions must be non-zero".into());
    }
    Ok(args)
}

fn build_scene_map(
    args: &Args,
    map: &Path,
    animate: bool,
    animation_frame: usize,
) -> Result<Scene, String> {
    let mut install = GameInstall::open(&args.install)
        .map_err(|error| format!("cannot open installation: {error}"))?;
    let options = SceneOptions {
        center: args.center,
        width: args.width,
        height: args.height,
        animate: animate || animation_frame > 0,
        animation_frame,
        ..SceneOptions::default()
    };
    Scene::build(&mut install, map, &options)
        .map_err(|error| format!("cannot build scene: {error}"))
}

fn build_scene_with(args: &Args, animate: bool, animation_frame: usize) -> Result<Scene, String> {
    build_scene_map(args, &args.map, animate, animation_frame)
}

fn build_scene(args: &Args) -> Result<Scene, String> {
    build_scene_with(args, args.animate, args.animation_frame)
}

fn load_actors(args: &Args) -> Result<actors::Actors, String> {
    let mut install = GameInstall::open(&args.install)
        .map_err(|error| format!("cannot open installation: {error}"))?;
    actors::Actors::load(&mut install)
}

fn build_city_world(args: &Args, scene: &Scene) -> Result<Scene, String> {
    let mut install = GameInstall::open(&args.install)
        .map_err(|error| format!("cannot open installation: {error}"))?;
    let center = (
        scene.background_origin.0 + scene.background_width as i32 / 2,
        scene.background_origin.1 + scene.background_height as i32 / 2,
    );
    let options = SceneOptions {
        center: Some(center),
        width: scene.background_width,
        height: scene.background_height,
        ..SceneOptions::default()
    };
    let city = Scene::build(&mut install, &args.map, &options)
        .map_err(|error| format!("cannot build city world: {error}"))?;
    if !city.missing.is_empty() || !city.ambiguous.is_empty() {
        return Err(format!("unresolved layers in map {}", city.map_path));
    }
    Ok(city)
}

fn load_explore_scenes(args: &Args, scene: &Scene) -> Result<(Scene, Scene), String> {
    let city = build_city_world(args, scene)?;
    let branch = load_explore_branch(args)?;
    Ok((city, branch))
}

fn load_explore_branch(args: &Args) -> Result<Scene, String> {
    let branch_map = resolve_branch_map(args);
    let branch = build_scene_map(args, &branch_map, false, 0)
        .map_err(|error| format!("explore branch failed: {error}"))?;
    if !branch.missing.is_empty() || !branch.ambiguous.is_empty() {
        return Err(format!("unresolved layers in map {}", branch.map_path));
    }
    Ok(branch)
}

#[derive(Clone)]
struct CityWorld {
    width: u32,
    height: u32,
    pixels: Vec<u8>,
    lease_site: Option<(i32, i32)>,
}

fn city_crop(
    world: &CityWorld,
    view_width: u32,
    view_height: u32,
    camera_x: i32,
    camera_y: i32,
) -> Vec<u8> {
    let mut view = vec![18u8; (view_width * view_height * 4) as usize];
    for pixel in view.chunks_exact_mut(4) {
        pixel[3] = 255;
    }
    for y in 0..view_height {
        let source_y = camera_y + y as i32;
        if source_y < 0 || source_y >= world.height as i32 {
            continue;
        }
        for x in 0..view_width {
            let source_x = camera_x + x as i32;
            if source_x < 0 || source_x >= world.width as i32 {
                continue;
            }
            let source = ((source_y as u32 * world.width + source_x as u32) * 4) as usize;
            let target = ((y * view_width + x) * 4) as usize;
            view[target..target + 4].copy_from_slice(&world.pixels[source..source + 4]);
        }
    }
    view
}

fn print_scene(scene: &Scene) {
    println!("map: {}", scene.map_path);
    println!(
        "background: {} ({}) {}x{} origin ({}, {})",
        scene.background_key,
        scene.background_kind.label(),
        scene.background_width,
        scene.background_height,
        scene.background_origin.0,
        scene.background_origin.1
    );
    if let Some(floor) = &scene.floor_key {
        println!("floor: {floor}");
    }
    println!(
        "crop: center ({}, {}) origin ({}, {}) size {}x{}",
        scene.crop.center_x,
        scene.crop.center_y,
        scene.crop.x,
        scene.crop.y,
        scene.crop.width,
        scene.crop.height
    );
    println!(
        "grid: {}x{} view {}x{}",
        scene.grid_w, scene.grid_h, scene.view_w, scene.view_h
    );
    println!(
        "tiles: {} present, {} layers considered",
        scene.tiles_present, scene.layers_considered
    );
    println!(
        "draws: {} ordered, missing {}, ambiguous {}",
        scene.draws.len(),
        scene.missing.len(),
        scene.ambiguous.len()
    );
    if scene.animated_draws > 0 {
        println!(
            "animation: frame {}/{} on {} animated draws",
            scene.animation_frame, scene.animation_frames, scene.animated_draws
        );
    }
    println!("hash: {:016x}", scene.pixel_hash());
}

fn resolve_branch_map(args: &Args) -> PathBuf {
    if args.branch_map.is_absolute() {
        return args.branch_map.clone();
    }
    // The default value is repository-relative. Prefer --install so a viewer
    // started from outside the workspace still finds the shipped branch map.
    let relative = args
        .branch_map
        .strip_prefix("game")
        .unwrap_or(args.branch_map.as_path());
    let under_install = args.install.join(relative);
    if !args.branch_map_explicit && under_install.is_file() {
        return under_install;
    }
    if args.branch_map.is_file() {
        return args.branch_map.clone();
    }
    if under_install.is_file() {
        return under_install;
    }
    if let Some(name) = args.branch_map.file_name() {
        let fallback = args.install.join("Isokarten").join(name);
        if fallback.is_file() {
            return fallback;
        }
    }
    if args.branch_map_explicit {
        args.branch_map.clone()
    } else {
        under_install
    }
}

fn resolve_city_map(install: &Path, name: &str) -> Result<PathBuf, String> {
    let file = Path::new(name);
    if name.contains(['/', '\\', ':'])
        || !file
            .extension()
            .is_some_and(|extension| extension.eq_ignore_ascii_case("iso"))
    {
        return Err(format!("invalid city map basename: {name}"));
    }

    let directory = install.join("Isokarten");
    let exact = directory.join(file);
    if exact.is_file() {
        return Ok(exact);
    }
    // The original installation runs on a case-insensitive filesystem.
    let mut matches = std::fs::read_dir(&directory)
        .map_err(|error| format!("cannot list city maps in {}: {error}", directory.display()))?
        .filter_map(Result::ok)
        .filter(|entry| entry.file_name().eq_ignore_ascii_case(name))
        .map(|entry| entry.path())
        .filter(|path| path.is_file());
    match (matches.next(), matches.next()) {
        (Some(path), None) => Ok(path),
        (None, _) => Err(format!(
            "city map {name} not found in {}",
            directory.display()
        )),
        _ => Err(format!(
            "ambiguous city map {name} in {}",
            directory.display()
        )),
    }
}

fn menu_output_path(args: &Args) -> PathBuf {
    if args.output_explicit {
        args.output.clone()
    } else {
        PathBuf::from("main_menu.png")
    }
}

fn print_menu_info(menu: &menu::Menu) {
    println!("menu: background=pictures\\pe_startscreen.tga 800x600");
    println!(
        "menu: font=fonts\\timesfont.fnt line_height={}",
        menu.line_height()
    );
    println!("menu: items={}", menu.items().len());
    for (index, item) in menu.items().iter().enumerate() {
        println!(
            "menu: item {index} label=\"{}\" id=0x{:03x} x={} y={} w={} h={}",
            item.label(),
            item.id(),
            item.x,
            item.y,
            item.width,
            item.height
        );
    }
    println!(
        "menu: selected={} label=\"{}\"",
        menu.selected(),
        menu.selected_action().label()
    );
}

fn apply_menu_command(
    menu: &mut menu::Menu,
    command: &str,
) -> Result<Option<menu::MenuAction>, String> {
    let value = command.trim().to_ascii_lowercase();
    match value.as_str() {
        "" => Ok(None),
        "up" | "w" => {
            menu.select_previous();
            Ok(None)
        }
        "down" | "s" => {
            menu.select_next();
            Ok(None)
        }
        "enter" | "space" => {
            let action = menu.activate();
            println!(
                "menu: action={:?} id=0x{:03x} label=\"{}\"",
                action,
                action.control_id(),
                action.label()
            );
            Ok(Some(action))
        }
        "esc" | "quit" => {
            println!("menu: action=Quit id=0x3f6 label=\"Quit\"");
            Ok(Some(menu::MenuAction::Quit))
        }
        _ => {
            if let Some(index) = value.strip_prefix("select:") {
                let index = index
                    .parse::<usize>()
                    .map_err(|_| format!("invalid menu selection: {index}"))?;
                if index >= menu.items().len() {
                    return Err(format!(
                        "menu selection {index} is out of range 0..{}",
                        menu.items().len() - 1
                    ));
                }
                menu.set_selected(index);
                Ok(None)
            } else {
                Err(format!("unknown menu command: {command}"))
            }
        }
    }
}

fn character_output_path(args: &Args) -> PathBuf {
    if args.output_explicit {
        args.output.clone()
    } else {
        PathBuf::from("character_select.png")
    }
}

fn print_character_info(select: &character_select::CharacterSelect) {
    println!("character: background=pictures\\pe_charakterauswahl.tga 800x600");
    println!("character: controls={}", select.buttons().len());
    for (index, button) in select.buttons().iter().enumerate() {
        println!(
            "character: button {index} label=\"{}\" id=0x{:03x} x={} y={} w={} h={}",
            button.label,
            button.action.control_id(),
            button.x,
            button.y,
            button.width,
            button.height
        );
    }
    println!(
        "character: selected={} label=\"{}\"",
        select.selected(),
        select.selected_action().label()
    );
}

fn apply_character_command(
    select: &mut character_select::CharacterSelect,
    command: &str,
) -> Result<Option<character_select::CharacterSelectAction>, String> {
    let value = command.trim().to_ascii_lowercase();
    match value.as_str() {
        "" => Ok(None),
        "up" | "w" => {
            select.select_previous();
            Ok(None)
        }
        "down" | "s" => {
            select.select_next();
            Ok(None)
        }
        "enter" | "space" => {
            let action = select.activate();
            println!(
                "character: action={:?} id=0x{:03x} label=\"{}\"",
                action,
                action.control_id(),
                action.label()
            );
            Ok(Some(action))
        }
        "esc" | "escape" => {
            println!("character: action=Back id=0x434 label=\"To main menu\"");
            Ok(Some(character_select::CharacterSelectAction::Back))
        }
        _ => {
            if let Some(index) = value.strip_prefix("select:") {
                let index = index
                    .parse::<usize>()
                    .map_err(|_| format!("invalid character selection: {index}"))?;
                if index >= select.buttons().len() {
                    return Err(format!(
                        "character selection {index} is out of range 0..{}",
                        select.buttons().len() - 1
                    ));
                }
                select.set_selected(index);
                Ok(None)
            } else {
                Err(format!("unknown character command: {command}"))
            }
        }
    }
}

fn run_character_select(args: &Args) -> Result<(), String> {
    let mut install = GameInstall::open(&args.install)
        .map_err(|error| format!("cannot open installation: {error}"))?;
    let mut select = character_select::CharacterSelect::load(&mut install)?;
    select.set_mode(if args.free_game {
        pc2_sim::GameMode::FreeGame
    } else {
        pc2_sim::GameMode::Campaign
    });
    if let Some(encoded) = &args.character_profile {
        match character_select::decode_profile(encoded) {
            Ok(profile) => select.apply_profile(&profile),
            Err(error) => return Err(format!("invalid character profile: {error}")),
        }
    }
    print_character_info(&select);
    if let Some(script) = &args.character_script {
        for command in script.split(';') {
            if let Some(action) = apply_character_command(&mut select, command)? {
                println!("character: final_action={:?}", action);
                break;
            }
            println!(
                "character: selected={} label=\"{}\"",
                select.selected(),
                select.selected_action().label()
            );
        }
    }
    if args.window {
        let action = run_character_select_window(
            "Character select".into(),
            select,
            args.frames,
            args.install.clone(),
            resolve_branch_map(args),
        )?;
        println!("character: window_action={action:?}");
        return Ok(());
    }
    let output = character_output_path(args);
    let frame = select.render();
    pc2_scene::write_rgba_png(
        &output,
        character_select::WIDTH,
        character_select::HEIGHT,
        &frame,
    )
    .map_err(|error| format!("png failed: {error}"))?;
    println!("output: {}", output.display());
    if args.vulkan {
        match pc2_render::render_rgba(character_select::WIDTH, character_select::HEIGHT, &frame) {
            Ok(rendered) => {
                let mismatches = rendered
                    .pixels
                    .iter()
                    .zip(frame.iter())
                    .filter(|(left, right)| left != right)
                    .count();
                println!("backend: {}", rendered.backend);
                println!(
                    "vulkan: {}x{} readback, {} byte mismatches",
                    rendered.width, rendered.height, mismatches
                );
                if rendered.backend != "Vulkan" || mismatches != 0 {
                    return Err("Vulkan readback mismatch".into());
                }
            }
            Err(error) => return Err(format!("Vulkan failed: {error}")),
        }
    }
    println!("result: OK");
    Ok(())
}

fn setup_profile_and_scenario(
    args: &Args,
) -> Result<(pc2_sim::CharacterProfile, pc2_sim::ScenarioSetup), String> {
    let profile = match args.character_profile.as_deref() {
        Some(encoded) => character_select::decode_profile(encoded)
            .map_err(|error| format!("invalid character profile: {error}"))?,
        None => free_play_setup::default_profile(),
    };
    let scenario = match args.scenario.as_deref() {
        Some(encoded) => pc2_sim::ScenarioSetup::decode(encoded)
            .map_err(|error| format!("invalid scenario: {error}"))?,
        None => pc2_sim::ScenarioSetup::free_play_berlin(),
    };
    Ok((profile, scenario))
}

fn print_free_play_info(setup: &free_play_setup::FreePlaySetup) {
    println!(
        "free-play-setup: background=pictures\\pe_freies_spiel.tga 800x600 city={} name={} map={} population={} length={} opponents={:?} difficulty={} starting_capital={}",
        setup.scenario().city_code,
        setup.scenario().city_name,
        setup.scenario().map_name,
        setup.scenario().population,
        setup.scenario().game_length_years,
        setup.scenario().opponents,
        setup.profile().difficulty,
        setup
            .scenario()
            .starting_capital(setup.profile().difficulty)
    );
    for (index, button) in setup.buttons().iter().enumerate() {
        println!(
            "free-play-setup: button {index} label=\"{}\" id=0x{:03x} x={} y={} w={} h={}",
            button.action.label(),
            button.action.control_id(),
            button.x,
            button.y,
            button.width,
            button.height
        );
    }
    println!(
        "free-play-setup: selected={} label=\"{}\"",
        setup.selected(),
        setup.selected_action().label()
    );
}

fn apply_free_play_command(
    setup: &mut free_play_setup::FreePlaySetup,
    command: &str,
) -> Result<Option<free_play_setup::Action>, String> {
    let value = command.trim().to_ascii_lowercase();
    match value.as_str() {
        "" => Ok(None),
        "up" | "w" => {
            setup.select_previous();
            Ok(None)
        }
        "down" | "s" => {
            setup.select_next();
            Ok(None)
        }
        "enter" | "space" => {
            let action = setup.activate();
            println!(
                "free-play-setup: action={:?} id=0x{:03x} label=\"{}\"",
                action,
                action.control_id(),
                action.label()
            );
            Ok(Some(action))
        }
        "esc" | "escape" => {
            println!("free-play-setup: action=Back id=0x4e2 label=\"To main menu\"");
            Ok(Some(free_play_setup::Action::Back))
        }
        _ => {
            if let Some(index) = value.strip_prefix("select:") {
                let index = index
                    .parse::<usize>()
                    .map_err(|_| format!("invalid free play selection: {index}"))?;
                if index >= setup.buttons().len() {
                    return Err(format!(
                        "free play selection {index} is out of range 0..{}",
                        setup.buttons().len() - 1
                    ));
                }
                setup.set_selected(index);
                Ok(None)
            } else {
                Err(format!("unknown free play command: {command}"))
            }
        }
    }
}

fn run_free_play_chain(args: &Args) -> Result<(), String> {
    let mut install = GameInstall::open(&args.install)
        .map_err(|error| format!("cannot open installation: {error}"))?;
    let mut menu = menu::Menu::load(&mut install)?;
    menu.set_selected(1);
    let menu_action = menu.activate();
    if menu_action != menu::MenuAction::StartFreeGame {
        return Err(format!(
            "menu selected {menu_action:?}, expected StartFreeGame"
        ));
    }
    println!("free-play-chain: menu=StartFreeGame");

    let mut character = character_select::CharacterSelect::load(&mut install)?;
    character.set_mode(pc2_sim::GameMode::FreeGame);
    if let Some(encoded) = &args.character_profile {
        character.apply_profile(
            &character_select::decode_profile(encoded)
                .map_err(|error| format!("invalid character profile: {error}"))?,
        );
    }
    character.set_selected(1);
    let character_action = character.activate();
    if character_action != character_select::CharacterSelectAction::Start {
        return Err(format!(
            "character selected {character_action:?}, expected Start"
        ));
    }
    let profile = character.profile();
    let scenario = match args.scenario.as_deref() {
        Some(encoded) => pc2_sim::ScenarioSetup::decode(encoded)
            .map_err(|error| format!("invalid scenario: {error}"))?,
        None => pc2_sim::ScenarioSetup::free_play_berlin(),
    };
    println!(
        "free-play-chain: character=Start profile={}",
        character_select::encode_profile(&profile)
    );

    let mut setup = free_play_setup::FreePlaySetup::load(&mut install, profile, scenario)?;
    setup.set_selected(1);
    let setup_action = setup.activate();
    if setup_action != free_play_setup::Action::Start {
        return Err(format!("setup selected {setup_action:?}, expected Start"));
    }
    println!(
        "free-play-chain: setup=Start city={} map={} starting_capital={}",
        setup.scenario().city_code,
        setup.scenario().map_name,
        setup
            .scenario()
            .starting_capital(setup.profile().difficulty)
    );

    let session = Args {
        map: resolve_city_map(&args.install, &setup.scenario().map_name)?,
        character_profile: Some(character_select::encode_profile(setup.profile())),
        scenario: Some(setup.scenario().encode()),
        ..args.clone()
    };
    let preview = build_scene(&session)?;
    let (city, branch) = load_explore_scenes(&session, &preview)?;
    println!(
        "free-play-chain: loaded city={} hash={:016x} branch={}",
        city.map_path,
        city.pixel_hash(),
        branch.map_path
    );

    let mut world = initialize_world(&session)?;
    let commands = session
        .playable_script
        .as_deref()
        .unwrap_or("open;step;step;step;step");
    for command in commands.split(';').filter(|item| !item.trim().is_empty()) {
        apply_world_command(&mut world, command)?;
    }
    if world.snapshot().sales != 1 {
        return Err(format!("expected one sale, got {}", world.snapshot().sales));
    }
    println!("free-play-chain: world={}", world.snapshot_json());
    println!(
        "free-play-chain: first sale sales={} cash={:.6}",
        world.snapshot().sales,
        world.snapshot().cash
    );
    Ok(())
}

fn run_free_play_setup(args: &Args) -> Result<(), String> {
    let mut install = GameInstall::open(&args.install)
        .map_err(|error| format!("cannot open installation: {error}"))?;
    let (profile, scenario) = setup_profile_and_scenario(args)?;
    let mut setup = free_play_setup::FreePlaySetup::load(&mut install, profile, scenario)?;
    if let Some(index) = args.free_play_selected {
        if index >= setup.buttons().len() {
            return Err(format!(
                "free play selection {index} is out of range 0..{}",
                setup.buttons().len() - 1
            ));
        }
        setup.set_selected(index);
    }
    print_free_play_info(&setup);
    if let Some(script) = &args.free_play_script {
        for command in script.split(';') {
            if let Some(action) = apply_free_play_command(&mut setup, command)? {
                println!("free-play-setup: final_action={action:?}");
                break;
            }
            println!(
                "free-play-setup: selected={} label=\"{}\"",
                setup.selected(),
                setup.selected_action().label()
            );
        }
    }
    if args.window {
        let action = run_free_play_setup_window(
            "Free play setup".into(),
            setup,
            args.frames,
            args.install.clone(),
            resolve_branch_map(args),
        )?;
        println!("free-play-setup: window_action={action:?}");
        return Ok(());
    }
    let output = if args.output_explicit {
        args.output.clone()
    } else {
        PathBuf::from("free_play_setup.png")
    };
    let frame = setup.render();
    pc2_scene::write_rgba_png(
        &output,
        free_play_setup::WIDTH,
        free_play_setup::HEIGHT,
        &frame,
    )
    .map_err(|error| format!("png failed: {error}"))?;
    println!("output: {}", output.display());
    if args.vulkan {
        match pc2_render::render_rgba(free_play_setup::WIDTH, free_play_setup::HEIGHT, &frame) {
            Ok(rendered) => {
                let mismatches = rendered
                    .pixels
                    .iter()
                    .zip(frame.iter())
                    .filter(|(left, right)| left != right)
                    .count();
                println!("backend: {}", rendered.backend);
                println!(
                    "vulkan: {}x{} readback, {} byte mismatches",
                    rendered.width, rendered.height, mismatches
                );
                if rendered.backend != "Vulkan" || mismatches != 0 {
                    return Err("Vulkan readback mismatch".into());
                }
            }
            Err(error) => return Err(format!("Vulkan failed: {error}")),
        }
    }
    println!("result: OK");
    Ok(())
}

fn run_free_play_setup_window(
    title: String,
    setup: free_play_setup::FreePlaySetup,
    max_frames: u32,
    install: PathBuf,
    branch_map: PathBuf,
) -> Result<Option<free_play_setup::Action>, String> {
    let event_loop = EventLoop::new().map_err(|error| format!("event loop: {error}"))?;
    let mut app = WindowApp::new_free_play_setup(title, setup, max_frames, install, branch_map);
    event_loop
        .run_app(&mut app)
        .map_err(|error| format!("event loop: {error}"))?;
    if let Some(error) = app.error {
        return Err(error);
    }
    Ok(app.free_play_pending)
}

fn run_menu(args: &Args) -> Result<(), String> {
    let mut install = GameInstall::open(&args.install)
        .map_err(|error| format!("cannot open installation: {error}"))?;
    let mut menu = menu::Menu::load(&mut install)?;
    if let Some(index) = args.menu_selected {
        if index >= menu.items().len() {
            return Err(format!(
                "menu selection {index} is out of range 0..{}",
                menu.items().len() - 1
            ));
        }
        menu.set_selected(index);
    }
    print_menu_info(&menu);

    let mut action = None;
    if let Some(script) = &args.menu_script {
        for command in script.split(';') {
            if let Some(next) = apply_menu_command(&mut menu, command)? {
                action = Some(next);
                if matches!(
                    next,
                    menu::MenuAction::Quit
                        | menu::MenuAction::StartNewGame
                        | menu::MenuAction::StartFreeGame
                ) {
                    break;
                }
            }
            println!(
                "menu: selected={} label=\"{}\"",
                menu.selected(),
                menu.selected_action().label()
            );
        }
    }
    if let Some(action) = action {
        println!(
            "menu: final_action={:?} id=0x{:03x}",
            action,
            action.control_id()
        );
    }

    if args.window {
        let branch_map = resolve_branch_map(args);
        let window_action = run_menu_window(
            "Main menu".into(),
            menu,
            args.frames,
            args.install.clone(),
            branch_map,
        )?;
        println!("menu: window_action={window_action:?}");
        return Ok(());
    }

    let output = menu_output_path(args);
    let frame = menu.render();
    pc2_scene::write_rgba_png(&output, menu::MENU_WIDTH, menu::MENU_HEIGHT, &frame)
        .map_err(|error| format!("png failed: {error}"))?;
    println!("output: {}", output.display());
    if args.vulkan {
        match pc2_render::render_rgba(menu::MENU_WIDTH, menu::MENU_HEIGHT, &frame) {
            Ok(rendered) => {
                let mismatches = rendered
                    .pixels
                    .iter()
                    .zip(frame.iter())
                    .filter(|(left, right)| left != right)
                    .count();
                println!("backend: {}", rendered.backend);
                println!(
                    "vulkan: {}x{} readback, {} byte mismatches",
                    rendered.width, rendered.height, mismatches
                );
                if rendered.backend != "Vulkan" || mismatches != 0 {
                    return Err("Vulkan readback mismatch".into());
                }
            }
            Err(error) => return Err(format!("Vulkan failed: {error}")),
        }
    }
    println!("result: OK");
    Ok(())
}

fn run_menu_window(
    title: String,
    menu: menu::Menu,
    max_frames: u32,
    install: PathBuf,
    branch_map: PathBuf,
) -> Result<Option<menu::MenuAction>, String> {
    let event_loop = EventLoop::new().map_err(|error| format!("event loop: {error}"))?;
    let mut app = WindowApp::new_menu(title, menu, max_frames, install, branch_map);
    event_loop
        .run_app(&mut app)
        .map_err(|error| format!("event loop: {error}"))?;
    if let Some(error) = app.error {
        return Err(error);
    }
    Ok(app.menu_pending)
}

fn run_character_select_window(
    title: String,
    character: character_select::CharacterSelect,
    max_frames: u32,
    install: PathBuf,
    branch_map: PathBuf,
) -> Result<Option<character_select::CharacterSelectAction>, String> {
    let event_loop = EventLoop::new().map_err(|error| format!("event loop: {error}"))?;
    let mut app = WindowApp::new_character(title, character, max_frames, install, branch_map);
    event_loop
        .run_app(&mut app)
        .map_err(|error| format!("event loop: {error}"))?;
    if let Some(error) = app.error {
        return Err(error);
    }
    Ok(app.character_pending)
}

fn spawn_menu_viewer(install: &Path) -> Result<u32, String> {
    let program = std::env::current_exe()
        .map_err(|error| format!("cannot locate viewer executable: {error}"))?;
    let child = std::process::Command::new(program)
        .arg("--install")
        .arg(install)
        .arg("--menu")
        .arg("--window")
        .spawn()
        .map_err(|error| format!("cannot launch main menu: {error}"))?;
    Ok(child.id())
}

fn spawn_character_select_viewer(
    install: &Path,
    branch_map: &Path,
    free_game: bool,
    frames: u32,
) -> Result<u32, String> {
    let program = std::env::current_exe()
        .map_err(|error| format!("cannot locate viewer executable: {error}"))?;
    let mut command = std::process::Command::new(program);
    command
        .arg("--install")
        .arg(install)
        .arg("--branch-map")
        .arg(branch_map)
        .arg("--character-select")
        .arg("--window");
    if free_game {
        command.arg("--free-game");
    }
    if frames > 0 {
        command.arg("--frames").arg(frames.to_string());
    }
    let child = command
        .spawn()
        .map_err(|error| format!("cannot launch character select: {error}"))?;
    Ok(child.id())
}

fn spawn_free_play_setup_viewer(
    install: &Path,
    branch_map: &Path,
    frames: u32,
    profile: &pc2_sim::CharacterProfile,
    scenario: &pc2_sim::ScenarioSetup,
) -> Result<u32, String> {
    let program = std::env::current_exe()
        .map_err(|error| format!("cannot locate viewer executable: {error}"))?;
    let mut command = std::process::Command::new(program);
    command
        .arg("--install")
        .arg(install)
        .arg("--branch-map")
        .arg(branch_map)
        .arg("--free-play-setup")
        .arg("--window")
        .arg("--character-profile")
        .arg(character_select::encode_profile(profile))
        .arg("--scenario")
        .arg(scenario.encode());
    if frames > 0 {
        command.arg("--frames").arg(frames.to_string());
    }
    let child = command
        .spawn()
        .map_err(|error| format!("cannot launch free play setup: {error}"))?;
    Ok(child.id())
}

fn spawn_campaign_viewer(
    install: &Path,
    branch_map: &Path,
    frames: u32,
    profile: &pc2_sim::CharacterProfile,
) -> Result<u32, String> {
    let program = std::env::current_exe()
        .map_err(|error| format!("cannot locate viewer executable: {error}"))?;
    let mut command = std::process::Command::new(program);
    command
        .arg("--install")
        .arg(install)
        .arg("--branch-map")
        .arg(branch_map)
        .arg("--campaign-start")
        .arg("--window")
        .arg("--character-profile")
        .arg(character_select::encode_profile(profile));
    if frames > 0 {
        command.arg("--frames").arg(frames.to_string());
    }
    let child = command
        .spawn()
        .map_err(|error| format!("cannot launch campaign viewer: {error}"))?;
    Ok(child.id())
}

fn spawn_free_play_session(
    install: &Path,
    map: &Path,
    branch_map: &Path,
    frames: u32,
    profile: &pc2_sim::CharacterProfile,
    scenario: &pc2_sim::ScenarioSetup,
) -> Result<u32, String> {
    let program = std::env::current_exe()
        .map_err(|error| format!("cannot locate viewer executable: {error}"))?;
    let mut command = std::process::Command::new(program);
    command
        .arg("--install")
        .arg(install)
        .arg("--map")
        .arg(map)
        .arg("--window")
        .arg("--explore")
        .arg("--branch-map")
        .arg(branch_map)
        .arg("--character-profile")
        .arg(character_select::encode_profile(profile))
        .arg("--scenario")
        .arg(scenario.encode());
    if frames > 0 {
        command.arg("--frames").arg(frames.to_string());
    }
    let child = command
        .spawn()
        .map_err(|error| format!("cannot launch game viewer: {error}"))?;
    Ok(child.id())
}

fn apply_world_command(world: &mut World, command: &str) -> Result<(), String> {
    let command = command.trim();
    if command.eq_ignore_ascii_case("open") {
        world.set_open(true);
    } else if command.eq_ignore_ascii_case("close") {
        world.set_open(false);
    } else if command.eq_ignore_ascii_case("step") {
        world.step();
    } else if let Some(value) = command.strip_prefix("price=") {
        world.set_price(
            value
                .parse::<f64>()
                .map_err(|_| format!("invalid replay price: {command}"))?,
        );
    } else {
        return Err(format!("unknown replay command: {command}"));
    }
    Ok(())
}

fn decode_session_profile(args: &Args) -> Result<Option<pc2_sim::CharacterProfile>, String> {
    args.character_profile
        .as_deref()
        .map(character_select::decode_profile)
        .transpose()
        .map_err(|error| format!("invalid character profile: {error}"))
}

fn initialize_world(args: &Args) -> Result<World, String> {
    let profile = decode_session_profile(args)?;
    let scenario = match args.scenario.as_deref() {
        Some(encoded) => Some(
            pc2_sim::ScenarioSetup::decode(encoded)
                .map_err(|error| format!("invalid scenario: {error}"))?,
        ),
        None => profile.as_ref().map(|profile| match profile.mode {
            pc2_sim::GameMode::FreeGame => pc2_sim::ScenarioSetup::free_play_berlin(),
            pc2_sim::GameMode::Campaign => pc2_sim::ScenarioSetup::campaign_berlin(),
        }),
    };
    Ok(initialize_session(10 * 60 + 55, profile, scenario))
}

// Both the windowed startup and headless verification use this initializer.
fn initialize_session(
    minute: u32,
    profile: Option<pc2_sim::CharacterProfile>,
    scenario: Option<pc2_sim::ScenarioSetup>,
) -> World {
    let mut world = World::new(minute);
    world.set_open(false);
    if let Some(profile) = &profile {
        println!(
            "profile: mode={:?} gender={} head={} eyes={} hair={} mouth={} logo={} color={} difficulty={} attributes={:?} player={:?} enterprise={:?}",
            profile.mode,
            profile.gender,
            profile.head,
            profile.eyes,
            profile.hair,
            profile.mouth,
            profile.logo,
            profile.color,
            profile.difficulty,
            profile.attributes,
            profile.player_name,
            profile.enterprise_name
        );
    }
    if let Some(profile) = profile {
        world = world.with_profile(profile);
    }
    if let Some(scenario) = scenario {
        world = world.with_scenario(scenario);
    }
    if let Some(scenario) = world.scenario() {
        println!(
            "scenario: mode={:?} city={} name={} map={} population={} length={} opponents={:?} starting_capital={:.0}",
            scenario.mode,
            scenario.city_code,
            scenario.city_name,
            scenario.map_name,
            scenario.population,
            scenario.game_length_years,
            scenario.opponents,
            world.starting_capital()
        );
    }
    world
}

fn run_campaign_start(args: &Args) -> Result<(), String> {
    if args.scenario.is_some() {
        return Err("--campaign-start loads installed mission data. Use --replay with an explicit --scenario".into());
    }
    let mut install = GameInstall::open(&args.install)
        .map_err(|error| format!("cannot open installation: {error}"))?;
    let mut scenario = campaign::load_first_mission(&mut install)?;
    let map = resolve_city_map(&args.install, &scenario.map_name)?;
    scenario.map_name = map
        .file_name()
        .ok_or("campaign map has no basename")?
        .to_string_lossy()
        .into_owned();
    let session = Args {
        map,
        ..args.clone()
    };
    let preview = build_scene(&session)?;
    let city = build_city_world(&session, &preview)?;
    campaign::validate_lease_offer(&mut scenario, &city, &session.map)?;
    let profile = decode_session_profile(args)?
        .unwrap_or_else(free_play_setup::default_profile)
        .with_mode(pc2_sim::GameMode::Campaign);
    let title = scenario.city_name.clone();
    // GameClock_Reset zeros the clock counters for a newly constructed game.
    let mut world = initialize_session(0, Some(profile), Some(scenario));
    let mission = world
        .scenario()
        .and_then(|scenario| scenario.campaign_mission.as_ref())
        .ok_or("missing campaign mission state")?;
    let player_branches = mission
        .starting_branches
        .iter()
        .filter(|branch| branch.owner_slot == 0)
        .count();
    println!(
        "campaign: loaded city={} hash={:016x}",
        city.map_path,
        city.pixel_hash()
    );
    println!(
        "campaign: goals={:?} rivals={} player_start_hq={} rival_start_hq={} difficulty_percent={} player_starting_branches={}",
        mission.goal_ids, mission.rival_count, mission.player_start_hq, mission.rival_start_hq,
        mission.difficulty_percent, player_branches
    );
    for branch in &mission.starting_branches {
        println!(
            "campaign: starting_branch owner={} size={} style={} owned={}",
            branch.owner_slot, branch.size, branch.style, branch.owned
        );
    }
    println!("campaign: world={}", world.snapshot_json());
    if let Some(offer) = world.campaign_property_offer() {
        println!(
            "campaign: offer tile={} lease_charge={} source=static_initial_state",
            offer.tile_index, offer.price
        );
    }
    let branch = if world.campaign_property_offer().is_some()
        && (args.window || args.playable_script.is_some())
    {
        Some(load_explore_branch(&session)?)
    } else {
        None
    };
    if let Some(script) = &args.playable_script {
        let branch = branch
            .as_ref()
            .ok_or("campaign has no available branch site")?;
        run_campaign_script(&mut world, script, &branch.map_path)?;
        println!("campaign: result={}", world.snapshot_json());
    }
    if args.window || args.output_explicit {
        show_explore(&session, title, &preview, city, branch, world)?;
    }
    Ok(())
}

fn run_campaign_script(world: &mut World, script: &str, branch_map: &str) -> Result<(), String> {
    let mut in_branch = false;
    for command in script
        .split(';')
        .map(str::trim)
        .filter(|item| !item.is_empty())
    {
        if let Some(tile) = command.strip_prefix("lease=") {
            let tile: u32 = tile
                .parse()
                .map_err(|_| format!("invalid lease tile: {tile}"))?;
            let price = world.lease_campaign_property(tile)?;
            println!(
                "campaign: leased tile={tile} charge={price} cash={:.6} owned=false",
                world.snapshot().cash
            );
        } else if command == "branch" {
            if !world.can_enter_branch() {
                return Err("lease the campaign property before entering the branch".into());
            }
            in_branch = true;
            println!("campaign: entered branch={branch_map}");
        } else if in_branch {
            apply_world_command(world, command)?;
        } else {
            return Err(format!("enter the campaign branch first: {command}"));
        }
    }
    Ok(())
}

#[derive(Clone, Copy)]
enum LeasePrompt {
    Confirm,
    Failed(&'static str),
}

fn city_controls(world: &World, branch_loaded: bool, prompt: Option<LeasePrompt>) -> &'static str {
    if prompt.is_some() {
        "ENTER LEASE   ESC CANCEL"
    } else if branch_loaded && world.can_enter_branch() {
        "ARROWS/WASD PAN   B ENTER BRANCH"
    } else if branch_loaded && world.campaign_property_offer().is_some() {
        "ARROWS/WASD PAN   B VIEW STOREFRONT"
    } else {
        "ARROWS/WASD PAN"
    }
}

fn campaign_city_summary(world: &World, prompt: Option<LeasePrompt>) -> Option<String> {
    if let Some(LeasePrompt::Failed(error)) = prompt {
        return Some(error.to_string());
    }
    if let (Some(offer), Some(_)) = (world.campaign_property_offer(), prompt) {
        return Some(format!(
            "STOREFRONT {}   LEASE {}",
            offer.tile_index, offer.price
        ));
    }
    world
        .scenario()
        .filter(|scenario| scenario.campaign_mission.is_some())
        .map(|scenario| {
            format!(
                "CAMPAIGN {}   CASH {:.0}",
                scenario.city_name,
                world.snapshot().cash
            )
        })
}

fn show_explore(
    args: &Args,
    title: String,
    preview: &Scene,
    city: Scene,
    branch: Option<Scene>,
    world: World,
) -> Result<(), String> {
    let lease_site = world.campaign_property_offer().and_then(|offer| {
        city.draws
            .iter()
            .find(|draw| {
                draw.layer == 2 && draw.tile_y * city.grid_w + draw.tile_x == offer.tile_index
            })
            .map(|draw| {
                (
                    draw.world_x - city.background_origin.0,
                    draw.world_y - city.background_origin.1,
                )
            })
    });
    let city_world = CityWorld {
        width: city.crop.width,
        height: city.crop.height,
        pixels: city.pixels,
        lease_site,
    };
    let (width, height) = (args.width, args.height);
    let max_x = city_world.width.saturating_sub(width) as i32;
    let max_y = city_world.height.saturating_sub(height) as i32;
    let camera_x =
        (preview.crop.center_x - preview.background_origin.0 - width as i32 / 2).clamp(0, max_x);
    let camera_y =
        (preview.crop.center_y - preview.background_origin.1 - height as i32 / 2).clamp(0, max_y);
    let mut city_view = city_crop(&city_world, width, height, camera_x, camera_y);
    overlay::draw_city_status(
        &mut city_view,
        width,
        height,
        (camera_x, camera_y),
        (city_world.width, city_world.height),
        city_controls(&world, branch.is_some() || args.campaign_start, None),
        campaign_city_summary(&world, None).as_deref(),
    )?;
    if args.campaign_start && !args.window {
        pc2_scene::write_rgba_png(&args.output, width, height, &city_view)
            .map_err(|error| format!("png failed: {error}"))?;
        println!("output: {}", args.output.display());
        return Ok(());
    }
    let branch = if let Some(branch) = branch {
        println!(
            "explore: city {}x{}, branch {}",
            city_world.width, city_world.height, branch.map_path
        );
        Some((branch.pixels, load_actors(args)?))
    } else {
        None
    };
    run_explore_window(
        title,
        city_world,
        city_view,
        branch,
        width,
        height,
        args.frames,
        world,
        camera_x,
        camera_y,
    )
}

fn main() -> ExitCode {
    let args = match parse_args() {
        Ok(args) => args,
        Err(error) => {
            eprintln!("{error}");
            usage("pc2-viewer");
            return ExitCode::FAILURE;
        }
    };
    if args.character_select {
        return match run_character_select(&args) {
            Ok(()) => ExitCode::SUCCESS,
            Err(error) => {
                eprintln!("character select failed: {error}");
                ExitCode::FAILURE
            }
        };
    }
    if args.campaign_start {
        return match run_campaign_start(&args) {
            Ok(()) => ExitCode::SUCCESS,
            Err(error) => {
                eprintln!("campaign start failed: {error}");
                ExitCode::FAILURE
            }
        };
    }
    if args.free_play_chain {
        return match run_free_play_chain(&args) {
            Ok(()) => ExitCode::SUCCESS,
            Err(error) => {
                eprintln!("free play chain failed: {error}");
                ExitCode::FAILURE
            }
        };
    }
    if args.free_play_setup {
        return match run_free_play_setup(&args) {
            Ok(()) => ExitCode::SUCCESS,
            Err(error) => {
                eprintln!("free play setup failed: {error}");
                ExitCode::FAILURE
            }
        };
    }
    if args.menu {
        return match run_menu(&args) {
            Ok(()) => ExitCode::SUCCESS,
            Err(error) => {
                eprintln!("menu failed: {error}");
                ExitCode::FAILURE
            }
        };
    }

    let scene = match build_scene(&args) {
        Ok(scene) => scene,
        Err(error) => {
            eprintln!("failed: {error}");
            return ExitCode::FAILURE;
        }
    };
    print_scene(&scene);
    if !scene.missing.is_empty() || !scene.ambiguous.is_empty() {
        eprintln!("failed: unresolved map layers");
        return ExitCode::FAILURE;
    }

    if let Some(script) = &args.replay {
        let mut sim = match initialize_world(&args) {
            Ok(world) => world,
            Err(error) => {
                eprintln!("{error}");
                return ExitCode::FAILURE;
            }
        };
        let actor_set = match load_actors(&args) {
            Ok(actors) => actors,
            Err(error) => {
                eprintln!("actor load failed: {error}");
                return ExitCode::FAILURE;
            }
        };
        let mut display = scene.pixels.clone();
        for command in script.split(';').filter(|item| !item.trim().is_empty()) {
            if let Err(error) = apply_world_command(&mut sim, command) {
                eprintln!("{error}");
                return ExitCode::FAILURE;
            }
            println!("sim: {}", sim.snapshot_json());
            display = match actors::compose(
                &scene.pixels,
                scene.crop.width,
                scene.crop.height,
                &actor_set,
                &sim.snapshot(),
                sim.customer_visible(),
            ) {
                Ok(display) => display,
                Err(error) => {
                    eprintln!("actor compose failed: {error}");
                    return ExitCode::FAILURE;
                }
            };
            if let Err(error) = overlay::draw_status(
                &mut display,
                scene.crop.width,
                scene.crop.height,
                &sim.snapshot(),
                sim.profile(),
                sim.scenario(),
            ) {
                eprintln!("overlay failed: {error}");
                return ExitCode::FAILURE;
            }
        }
        if let Err(error) =
            pc2_scene::write_rgba_png(&args.output, scene.crop.width, scene.crop.height, &display)
        {
            eprintln!("png failed: {error}");
            return ExitCode::FAILURE;
        }
        println!("output: {}", args.output.display());
        if args.vulkan {
            match pc2_render::render_rgba(scene.crop.width, scene.crop.height, &display) {
                Ok(frame) => {
                    let mismatches = frame
                        .pixels
                        .iter()
                        .zip(display.iter())
                        .filter(|(left, right)| left != right)
                        .count();
                    println!("backend: {}", frame.backend);
                    println!(
                        "vulkan: {}x{} readback, {} byte mismatches",
                        frame.width, frame.height, mismatches
                    );
                    if frame.backend != "Vulkan" || mismatches != 0 {
                        return ExitCode::FAILURE;
                    }
                }
                Err(error) => {
                    eprintln!("Vulkan failed: {error}");
                    return ExitCode::FAILURE;
                }
            }
        }
        println!("result: OK");
        return ExitCode::SUCCESS;
    }

    if args.explore {
        let (world, branch) = match load_explore_scenes(&args, &scene) {
            Ok(scenes) => scenes,
            Err(error) => {
                eprintln!("explore failed: {error}");
                return ExitCode::FAILURE;
            }
        };
        let sim = match initialize_world(&args) {
            Ok(world) => world,
            Err(error) => {
                eprintln!("{error}");
                return ExitCode::FAILURE;
            }
        };
        return match show_explore(
            &args,
            "explore".to_string(),
            &scene,
            world,
            Some(branch),
            sim,
        ) {
            Ok(()) => ExitCode::SUCCESS,
            Err(error) => {
                eprintln!("explore window failed: {error}");
                ExitCode::FAILURE
            }
        };
    }

    if args.window {
        let title = Path::new(&scene.map_path)
            .file_stem()
            .and_then(|stem| stem.to_str())
            .unwrap_or("crop")
            .to_string();
        if args.playable {
            let mut sim = match initialize_world(&args) {
                Ok(world) => world,
                Err(error) => {
                    eprintln!("{error}");
                    return ExitCode::FAILURE;
                }
            };
            if let Some(script) = &args.playable_script {
                for command in script.split(';').filter(|item| !item.trim().is_empty()) {
                    if let Err(error) = apply_world_command(&mut sim, command) {
                        eprintln!("{error}");
                        return ExitCode::FAILURE;
                    }
                }
            }
            let actors = match load_actors(&args) {
                Ok(actors) => actors,
                Err(error) => {
                    eprintln!("actor load failed: {error}");
                    return ExitCode::FAILURE;
                }
            };
            let mut display = match actors::compose(
                &scene.pixels,
                scene.crop.width,
                scene.crop.height,
                &actors,
                &sim.snapshot(),
                sim.customer_visible(),
            ) {
                Ok(display) => display,
                Err(error) => {
                    eprintln!("actor compose failed: {error}");
                    return ExitCode::FAILURE;
                }
            };
            overlay::draw_status(
                &mut display,
                scene.crop.width,
                scene.crop.height,
                &sim.snapshot(),
                sim.profile(),
                sim.scenario(),
            )
            .map_err(|error| (error, ExitCode::FAILURE))
            .unwrap();
            println!("sim: {}", sim.snapshot_json());
            return match run_playable_window(
                title,
                scene.pixels,
                display,
                scene.crop.width,
                scene.crop.height,
                args.frames,
                sim,
                actors,
            ) {
                Ok(()) => ExitCode::SUCCESS,
                Err(error) => {
                    eprintln!("playable window failed: {error}");
                    ExitCode::FAILURE
                }
            };
        }
        let frames = if args.animate {
            let count = scene.animation_frames.max(1);
            let mut frames = Vec::with_capacity(count);
            for frame in 0..count {
                match build_scene_with(&args, true, frame) {
                    Ok(scene) => frames.push(scene.pixels),
                    Err(error) => {
                        eprintln!("animation frame {frame} failed: {error}");
                        return ExitCode::FAILURE;
                    }
                }
            }
            println!("animation: prepared {count} Vulkan frames");
            frames
        } else {
            vec![scene.pixels]
        };
        return match run_window(title, frames, args.width, args.height, args.frames) {
            Ok(()) => ExitCode::SUCCESS,
            Err(error) => {
                eprintln!("window failed: {error}");
                ExitCode::FAILURE
            }
        };
    }

    if let Err(error) = scene.write_png(&args.output) {
        eprintln!("png failed: {error}");
        return ExitCode::FAILURE;
    }
    println!("output: {}", args.output.display());
    if let Some(path) = &args.json {
        if let Err(error) = std::fs::write(path, scene.draw_list_json()) {
            eprintln!("json failed: {error}");
            return ExitCode::FAILURE;
        }
        println!("draw list: {}", path.display());
    }

    if args.vulkan {
        match pc2_render::render_rgba(scene.crop.width, scene.crop.height, &scene.pixels) {
            Ok(frame) => {
                let mismatches = frame
                    .pixels
                    .iter()
                    .zip(scene.pixels.iter())
                    .filter(|(left, right)| left != right)
                    .count();
                println!("adapter: {}", frame.adapter);
                println!("backend: {}", frame.backend);
                println!(
                    "vulkan: {}x{} readback, {} byte mismatches",
                    frame.width, frame.height, mismatches
                );
                if frame.backend != "Vulkan" || mismatches != 0 {
                    eprintln!("failed: Vulkan readback differs from the CPU crop");
                    return ExitCode::FAILURE;
                }
            }
            Err(error) => {
                eprintln!("Vulkan failed: {error}");
                return ExitCode::FAILURE;
            }
        }
    }

    println!("result: OK");
    ExitCode::SUCCESS
}

fn upload_frame(
    queue: &wgpu::Queue,
    texture: &wgpu::Texture,
    width: u32,
    height: u32,
    pixels: &[u8],
) {
    let padded_bytes_per_row = ((width * 4 + 255) / 256) * 256;
    let mut padded = vec![0u8; (padded_bytes_per_row * height) as usize];
    for y in 0..height {
        let source = (y * width * 4) as usize;
        let target = (y * padded_bytes_per_row) as usize;
        padded[target..target + (width * 4) as usize]
            .copy_from_slice(&pixels[source..source + (width * 4) as usize]);
    }
    queue.write_texture(
        wgpu::TexelCopyTextureInfo {
            texture,
            mip_level: 0,
            origin: wgpu::Origin3d::ZERO,
            aspect: wgpu::TextureAspect::All,
        },
        &padded,
        wgpu::TexelCopyBufferLayout {
            offset: 0,
            bytes_per_row: Some(padded_bytes_per_row),
            rows_per_image: Some(height),
        },
        wgpu::Extent3d {
            width,
            height,
            depth_or_array_layers: 1,
        },
    );
}

/// Keep the swapchain inside the adapter's maximum texture dimension while
/// preserving the window aspect ratio when a compositor hands us a 4K or
/// ultrawide resize.
fn clamp_surface_size(width: u32, height: u32, max_extent: u32) -> (u32, u32) {
    let width = width.max(1);
    let height = height.max(1);
    let max_extent = max_extent.max(1);
    let longest = width.max(height);
    if longest <= max_extent {
        return (width, height);
    }
    let scale = max_extent as u64;
    (
        ((width as u64 * scale / longest as u64) as u32).max(1),
        ((height as u64 * scale / longest as u64) as u32).max(1),
    )
}

struct Viewer {
    window: Arc<Window>,
    surface: wgpu::Surface<'static>,
    device: wgpu::Device,
    queue: wgpu::Queue,
    config: wgpu::SurfaceConfiguration,
    pipeline: wgpu::RenderPipeline,
    bind_group: wgpu::BindGroup,
    texture: wgpu::Texture,
    frames: Vec<Vec<u8>>,
    uploaded_frame: usize,
    width: u32,
    height: u32,
    frames_rendered: u32,
    max_frames: u32,
    max_surface_extent: u32,
}

impl Viewer {
    fn new(
        window: Arc<Window>,
        frames: Vec<Vec<u8>>,
        width: u32,
        height: u32,
    ) -> Result<Self, String> {
        if frames.is_empty() {
            return Err("viewer has no frames".into());
        }
        let expected = (width * height * 4) as usize;
        if frames.iter().any(|frame| frame.len() != expected) {
            return Err("viewer frame has the wrong size".into());
        }
        let mut instance_desc = wgpu::InstanceDescriptor::new_without_display_handle();
        instance_desc.backends = wgpu::Backends::VULKAN;
        let instance = wgpu::Instance::new(instance_desc);
        let surface = instance
            .create_surface(window.clone())
            .map_err(|error| format!("surface: {error}"))?;
        let adapter = pollster::block_on(instance.request_adapter(&wgpu::RequestAdapterOptions {
            power_preference: wgpu::PowerPreference::LowPower,
            compatible_surface: Some(&surface),
            force_fallback_adapter: false,
            apply_limit_buckets: false,
        }))
        .map_err(|error| format!("Vulkan adapter: {error}"))?;
        let info = adapter.get_info();
        println!("adapter: {}", info.name);
        println!("backend: {:?}", info.backend);
        if info.backend != wgpu::Backend::Vulkan {
            return Err("selected adapter is not Vulkan".into());
        }
        let (device, queue) = pollster::block_on(adapter.request_device(&wgpu::DeviceDescriptor {
            label: Some("pc2-viewer"),
            required_features: wgpu::Features::empty(),
            required_limits: wgpu::Limits::downlevel_defaults().using_resolution(adapter.limits()),
            ..Default::default()
        }))
        .map_err(|error| format!("Vulkan device: {error}"))?;
        let max_surface_extent = device.limits().max_texture_dimension_2d;
        let capabilities = surface.get_capabilities(&adapter);
        let format = capabilities
            .formats
            .iter()
            .copied()
            .find(|format| format.is_srgb())
            .or_else(|| capabilities.formats.first().copied())
            .ok_or("surface has no formats")?;
        let size = window.inner_size();
        let (surface_width, surface_height) =
            clamp_surface_size(size.width, size.height, max_surface_extent);
        let config = wgpu::SurfaceConfiguration {
            usage: wgpu::TextureUsages::RENDER_ATTACHMENT,
            format,
            color_space: wgpu::SurfaceColorSpace::Auto,
            width: surface_width,
            height: surface_height,
            present_mode: wgpu::PresentMode::AutoVsync,
            desired_maximum_frame_latency: 2,
            alpha_mode: wgpu::CompositeAlphaMode::Auto,
            view_formats: vec![],
        };
        surface.configure(&device, &config);

        let texture = device.create_texture(&wgpu::TextureDescriptor {
            label: Some("scene texture"),
            size: wgpu::Extent3d {
                width,
                height,
                depth_or_array_layers: 1,
            },
            mip_level_count: 1,
            sample_count: 1,
            dimension: wgpu::TextureDimension::D2,
            format: wgpu::TextureFormat::Rgba8UnormSrgb,
            usage: wgpu::TextureUsages::TEXTURE_BINDING | wgpu::TextureUsages::COPY_DST,
            view_formats: &[],
        });
        upload_frame(&queue, &texture, width, height, &frames[0]);
        let view = texture.create_view(&wgpu::TextureViewDescriptor::default());
        let sampler = device.create_sampler(&wgpu::SamplerDescriptor {
            label: Some("scene nearest"),
            mag_filter: wgpu::FilterMode::Nearest,
            min_filter: wgpu::FilterMode::Nearest,
            ..Default::default()
        });
        let bind_layout = device.create_bind_group_layout(&wgpu::BindGroupLayoutDescriptor {
            label: Some("scene bind layout"),
            entries: &[
                wgpu::BindGroupLayoutEntry {
                    binding: 0,
                    visibility: wgpu::ShaderStages::FRAGMENT,
                    ty: wgpu::BindingType::Texture {
                        sample_type: wgpu::TextureSampleType::Float { filterable: true },
                        view_dimension: wgpu::TextureViewDimension::D2,
                        multisampled: false,
                    },
                    count: None,
                },
                wgpu::BindGroupLayoutEntry {
                    binding: 1,
                    visibility: wgpu::ShaderStages::FRAGMENT,
                    ty: wgpu::BindingType::Sampler(wgpu::SamplerBindingType::Filtering),
                    count: None,
                },
            ],
        });
        let bind_group = device.create_bind_group(&wgpu::BindGroupDescriptor {
            label: Some("scene bind"),
            layout: &bind_layout,
            entries: &[
                wgpu::BindGroupEntry {
                    binding: 0,
                    resource: wgpu::BindingResource::TextureView(&view),
                },
                wgpu::BindGroupEntry {
                    binding: 1,
                    resource: wgpu::BindingResource::Sampler(&sampler),
                },
            ],
        });
        let shader = device.create_shader_module(wgpu::ShaderModuleDescriptor {
            label: Some("scene shader"),
            source: wgpu::ShaderSource::Wgsl(WINDOW_SHADER.into()),
        });
        let pipeline_layout = device.create_pipeline_layout(&wgpu::PipelineLayoutDescriptor {
            label: Some("scene pipeline layout"),
            bind_group_layouts: &[Some(&bind_layout)],
            immediate_size: 0,
        });
        let pipeline = device.create_render_pipeline(&wgpu::RenderPipelineDescriptor {
            label: Some("scene pipeline"),
            layout: Some(&pipeline_layout),
            vertex: wgpu::VertexState {
                module: &shader,
                entry_point: Some("vs"),
                compilation_options: Default::default(),
                buffers: &[],
            },
            primitive: wgpu::PrimitiveState::default(),
            depth_stencil: None,
            multisample: wgpu::MultisampleState::default(),
            fragment: Some(wgpu::FragmentState {
                module: &shader,
                entry_point: Some("fs"),
                compilation_options: Default::default(),
                targets: &[Some(wgpu::ColorTargetState {
                    format,
                    blend: Some(wgpu::BlendState::REPLACE),
                    write_mask: wgpu::ColorWrites::ALL,
                })],
            }),
            multiview_mask: None,
            cache: None,
        });
        println!(
            "surface: {}x{} {:?}",
            config.width, config.height, config.format
        );
        Ok(Self {
            window,
            surface,
            device,
            queue,
            config,
            pipeline,
            bind_group,
            texture,
            frames,
            uploaded_frame: 0,
            width,
            height,
            frames_rendered: 0,
            max_frames: 0,
            max_surface_extent,
        })
    }

    fn update_image(&mut self, pixels: &[u8]) {
        let expected = (self.width * self.height * 4) as usize;
        if pixels.len() != expected {
            return;
        }
        upload_frame(&self.queue, &self.texture, self.width, self.height, pixels);
        if self.frames.len() == 1 {
            self.frames[0].clear();
            self.frames[0].extend_from_slice(pixels);
        }
        self.uploaded_frame = 0;
    }

    fn resize(&mut self, width: u32, height: u32) {
        if width == 0 || height == 0 {
            return;
        }
        let (width, height) = clamp_surface_size(width, height, self.max_surface_extent);
        self.config.width = width;
        self.config.height = height;
        self.surface.configure(&self.device, &self.config);
    }

    fn render(&mut self) {
        if self.frames.len() > 1 {
            let phase = (self.frames_rendered as usize / 6) % self.frames.len();
            if phase != self.uploaded_frame {
                upload_frame(
                    &self.queue,
                    &self.texture,
                    self.width,
                    self.height,
                    &self.frames[phase],
                );
                self.uploaded_frame = phase;
            }
        }
        let frame = match self.surface.get_current_texture() {
            wgpu::CurrentSurfaceTexture::Success(frame) => frame,
            wgpu::CurrentSurfaceTexture::Suboptimal(frame) => frame,
            wgpu::CurrentSurfaceTexture::Outdated | wgpu::CurrentSurfaceTexture::Lost => {
                self.surface.configure(&self.device, &self.config);
                match self.surface.get_current_texture() {
                    wgpu::CurrentSurfaceTexture::Success(frame)
                    | wgpu::CurrentSurfaceTexture::Suboptimal(frame) => frame,
                    _ => return,
                }
            }
            _ => return,
        };
        let view = frame
            .texture
            .create_view(&wgpu::TextureViewDescriptor::default());
        let mut encoder = self
            .device
            .create_command_encoder(&wgpu::CommandEncoderDescriptor {
                label: Some("viewer encoder"),
            });
        {
            let mut pass = encoder.begin_render_pass(&wgpu::RenderPassDescriptor {
                label: Some("viewer pass"),
                color_attachments: &[Some(wgpu::RenderPassColorAttachment {
                    view: &view,
                    depth_slice: None,
                    resolve_target: None,
                    ops: wgpu::Operations {
                        load: wgpu::LoadOp::Clear(wgpu::Color::BLACK),
                        store: wgpu::StoreOp::Store,
                    },
                })],
                depth_stencil_attachment: None,
                timestamp_writes: None,
                occlusion_query_set: None,
                multiview_mask: None,
            });
            pass.set_pipeline(&self.pipeline);
            pass.set_bind_group(0, &self.bind_group, &[]);
            pass.draw(0..6, 0..1);
        }
        self.queue.submit(Some(encoder.finish()));
        self.queue.present(frame);
        self.frames_rendered += 1;
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum ViewMode {
    City,
    Branch,
}

struct WindowApp {
    frames: Option<Vec<Vec<u8>>>,
    title: String,
    width: u32,
    height: u32,
    viewer: Option<Viewer>,
    max_frames: u32,
    error: Option<String>,
    sim: Option<World>,
    base_frame: Option<Vec<u8>>,
    actors: Option<actors::Actors>,
    explore: bool,
    city_world: Option<CityWorld>,
    branch_base: Option<Vec<u8>>,
    lease_prompt: Option<LeasePrompt>,
    mode: ViewMode,
    camera_x: i32,
    camera_y: i32,
    menu: Option<menu::Menu>,
    menu_pending: Option<menu::MenuAction>,
    character: Option<character_select::CharacterSelect>,
    character_pending: Option<character_select::CharacterSelectAction>,
    free_play_setup: Option<free_play_setup::FreePlaySetup>,
    free_play_pending: Option<free_play_setup::Action>,
    cursor_position: Option<(i32, i32)>,
    game_install: Option<PathBuf>,
    game_branch_map: Option<PathBuf>,
    game_frames: u32,
}

impl WindowApp {
    fn new(title: String, frames: Vec<Vec<u8>>, width: u32, height: u32, max_frames: u32) -> Self {
        Self {
            frames: Some(frames),
            title,
            width,
            height,
            viewer: None,
            max_frames,
            error: None,
            sim: None,
            base_frame: None,
            actors: None,
            explore: false,
            city_world: None,
            branch_base: None,
            lease_prompt: None,
            mode: ViewMode::Branch,
            camera_x: 0,
            camera_y: 0,
            menu: None,
            menu_pending: None,
            character: None,
            character_pending: None,
            free_play_setup: None,
            free_play_pending: None,
            cursor_position: None,
            game_install: None,
            game_branch_map: None,
            game_frames: 0,
        }
    }

    fn new_playable(
        title: String,
        base: Vec<u8>,
        display: Vec<u8>,
        width: u32,
        height: u32,
        max_frames: u32,
        sim: World,
        actors: actors::Actors,
    ) -> Self {
        Self {
            frames: Some(vec![display]),
            title,
            width,
            height,
            viewer: None,
            max_frames,
            error: None,
            sim: Some(sim),
            base_frame: Some(base),
            actors: Some(actors),
            explore: false,
            city_world: None,
            branch_base: None,
            lease_prompt: None,
            mode: ViewMode::Branch,
            camera_x: 0,
            camera_y: 0,
            menu: None,
            menu_pending: None,
            character: None,
            character_pending: None,
            free_play_setup: None,
            free_play_pending: None,
            cursor_position: None,
            game_install: None,
            game_branch_map: None,
            game_frames: 0,
        }
    }

    #[allow(clippy::too_many_arguments)]
    fn new_explore(
        title: String,
        city_world: CityWorld,
        city_view: Vec<u8>,
        branch: Option<(Vec<u8>, actors::Actors)>,
        width: u32,
        height: u32,
        max_frames: u32,
        sim: World,
        camera_x: i32,
        camera_y: i32,
    ) -> Self {
        let (branch_base, actors) = branch.unzip();
        Self {
            frames: Some(vec![city_view]),
            title,
            width,
            height,
            viewer: None,
            max_frames,
            error: None,
            sim: Some(sim),
            base_frame: branch_base.clone(),
            actors,
            explore: true,
            city_world: Some(city_world),
            branch_base,
            lease_prompt: None,
            mode: ViewMode::City,
            camera_x,
            camera_y,
            menu: None,
            menu_pending: None,
            character: None,
            character_pending: None,
            free_play_setup: None,
            free_play_pending: None,
            cursor_position: None,
            game_install: None,
            game_branch_map: None,
            game_frames: 0,
        }
    }

    fn new_menu(
        title: String,
        menu: menu::Menu,
        max_frames: u32,
        install: PathBuf,
        branch_map: PathBuf,
    ) -> Self {
        let display = menu.render();
        Self {
            frames: Some(vec![display]),
            title,
            width: menu::MENU_WIDTH,
            height: menu::MENU_HEIGHT,
            viewer: None,
            max_frames,
            error: None,
            sim: None,
            base_frame: None,
            actors: None,
            explore: false,
            city_world: None,
            branch_base: None,
            lease_prompt: None,
            mode: ViewMode::Branch,
            camera_x: 0,
            camera_y: 0,
            menu: Some(menu),
            menu_pending: None,
            character: None,
            character_pending: None,
            free_play_setup: None,
            free_play_pending: None,
            cursor_position: None,
            game_install: Some(install),
            game_branch_map: Some(branch_map),
            game_frames: max_frames,
        }
    }

    fn new_character(
        title: String,
        character: character_select::CharacterSelect,
        max_frames: u32,
        install: PathBuf,
        branch_map: PathBuf,
    ) -> Self {
        let display = character.render();
        Self {
            frames: Some(vec![display]),
            title,
            width: character_select::WIDTH,
            height: character_select::HEIGHT,
            viewer: None,
            max_frames,
            error: None,
            sim: None,
            base_frame: None,
            actors: None,
            explore: false,
            city_world: None,
            branch_base: None,
            lease_prompt: None,
            mode: ViewMode::Branch,
            camera_x: 0,
            camera_y: 0,
            menu: None,
            menu_pending: None,
            character: Some(character),
            character_pending: None,
            free_play_setup: None,
            free_play_pending: None,
            cursor_position: None,
            game_install: Some(install),
            game_branch_map: Some(branch_map),
            game_frames: max_frames,
        }
    }

    fn new_free_play_setup(
        title: String,
        setup: free_play_setup::FreePlaySetup,
        max_frames: u32,
        install: PathBuf,
        branch_map: PathBuf,
    ) -> Self {
        let display = setup.render();
        Self {
            frames: Some(vec![display]),
            title,
            width: free_play_setup::WIDTH,
            height: free_play_setup::HEIGHT,
            viewer: None,
            max_frames,
            error: None,
            sim: None,
            base_frame: None,
            actors: None,
            explore: false,
            city_world: None,
            branch_base: None,
            lease_prompt: None,
            mode: ViewMode::Branch,
            camera_x: 0,
            camera_y: 0,
            menu: None,
            menu_pending: None,
            character: None,
            character_pending: None,
            free_play_setup: Some(setup),
            free_play_pending: None,
            cursor_position: None,
            game_install: Some(install),
            game_branch_map: Some(branch_map),
            game_frames: max_frames,
        }
    }

    fn refresh_character(&mut self) {
        let (Some(viewer), Some(character)) = (self.viewer.as_mut(), self.character.as_ref())
        else {
            return;
        };
        viewer.update_image(&character.render());
    }

    fn handle_character_key(&mut self, key: &Key) -> bool {
        let Some(character) = self.character.as_mut() else {
            return false;
        };
        if character.editing() {
            match key {
                Key::Character(text) => character.edit_char(text.as_str()),
                Key::Named(NamedKey::Backspace) => character.edit_backspace(),
                Key::Named(NamedKey::Enter) | Key::Named(NamedKey::Escape) => {
                    character.finish_edit()
                }
                _ => {}
            }
            self.refresh_character();
            return true;
        }
        match key {
            Key::Named(NamedKey::ArrowUp) => {
                character.select_previous();
                self.refresh_character();
                true
            }
            Key::Named(NamedKey::ArrowDown) => {
                character.select_next();
                self.refresh_character();
                true
            }
            Key::Character(text) if text.eq_ignore_ascii_case("w") => {
                character.select_previous();
                self.refresh_character();
                true
            }
            Key::Character(text) if text.eq_ignore_ascii_case("s") => {
                character.select_next();
                self.refresh_character();
                true
            }
            Key::Named(NamedKey::Enter) | Key::Named(NamedKey::Space) => {
                let action = character.activate();
                println!(
                    "character: action={:?} id=0x{:03x} label=\"{}\"",
                    action,
                    action.control_id(),
                    action.label()
                );
                self.finish_character_action(action);
                true
            }
            _ => false,
        }
    }

    fn finish_character_action(&mut self, action: character_select::CharacterSelectAction) {
        let (Some(install), Some(branch_map)) =
            (self.game_install.as_ref(), self.game_branch_map.as_ref())
        else {
            return;
        };
        let result = match action {
            character_select::CharacterSelectAction::Back => {
                spawn_menu_viewer(install).map(|pid| {
                    println!("character: launched main menu pid={pid}");
                })
            }
            character_select::CharacterSelectAction::Start => {
                let Some(character) = self.character.as_ref() else {
                    return;
                };
                let profile = character.profile();
                println!(
                    "character: profile={}",
                    character_select::encode_profile(&profile)
                );
                match profile.mode {
                    pc2_sim::GameMode::FreeGame => {
                        let scenario = pc2_sim::ScenarioSetup::free_play_berlin();
                        println!("character: free-play-setup={}", scenario.encode());
                        spawn_free_play_setup_viewer(
                            install,
                            branch_map,
                            self.game_frames,
                            &profile,
                            &scenario,
                        )
                        .map(|pid| {
                            println!("character: launched free play setup pid={pid}");
                        })
                    }
                    pc2_sim::GameMode::Campaign => {
                        spawn_campaign_viewer(install, branch_map, self.game_frames, &profile).map(
                            |pid| {
                                println!("character: launched campaign viewer pid={pid}");
                            },
                        )
                    }
                }
            }
        };
        match result {
            Ok(()) => self.character_pending = Some(action),
            Err(error) => {
                println!("character: launch failed: {error}");
                if let Some(character) = self.character.as_mut() {
                    character.set_status(format!("Could not continue: {error}"));
                }
                self.refresh_character();
            }
        }
    }

    fn activate_character_at_cursor(&mut self) -> bool {
        let Some(position) = self.cursor_position else {
            return false;
        };
        let Some(character) = self.character.as_mut() else {
            return false;
        };
        let (hit, action) = character.click_at(position.0, position.1);
        if !hit {
            return false;
        }
        if let Some(action) = action {
            println!(
                "character: action={:?} id=0x{:03x} label=\"{}\"",
                action,
                action.control_id(),
                action.label()
            );
            self.finish_character_action(action);
        } else {
            self.refresh_character();
            if let Some(character) = self.character.as_mut() {
                character.clear_pressed();
            }
        }
        true
    }

    fn refresh_free_play_setup(&mut self) {
        let (Some(viewer), Some(setup)) = (self.viewer.as_mut(), self.free_play_setup.as_ref())
        else {
            return;
        };
        viewer.update_image(&setup.render());
    }

    fn handle_free_play_setup_key(&mut self, key: &Key) -> bool {
        let Some(setup) = self.free_play_setup.as_mut() else {
            return false;
        };
        match key {
            Key::Named(NamedKey::ArrowUp) => {
                setup.select_previous();
                self.refresh_free_play_setup();
                true
            }
            Key::Named(NamedKey::ArrowDown) => {
                setup.select_next();
                self.refresh_free_play_setup();
                true
            }
            Key::Character(text) if text.eq_ignore_ascii_case("w") => {
                setup.select_previous();
                self.refresh_free_play_setup();
                true
            }
            Key::Character(text) if text.eq_ignore_ascii_case("s") => {
                setup.select_next();
                self.refresh_free_play_setup();
                true
            }
            Key::Named(NamedKey::Enter) | Key::Named(NamedKey::Space) => {
                let action = setup.activate();
                println!(
                    "free-play-setup: action={:?} id=0x{:03x} label=\"{}\"",
                    action,
                    action.control_id(),
                    action.label()
                );
                self.finish_free_play_setup_action(action);
                true
            }
            _ => false,
        }
    }

    fn finish_free_play_setup_action(&mut self, action: free_play_setup::Action) {
        let (Some(install), Some(branch_map)) =
            (self.game_install.as_ref(), self.game_branch_map.as_ref())
        else {
            return;
        };
        let result = match action {
            free_play_setup::Action::Back => spawn_menu_viewer(install).map(|pid| {
                println!("free-play-setup: launched main menu pid={pid}");
            }),
            free_play_setup::Action::Start => {
                let Some(setup) = self.free_play_setup.as_ref() else {
                    return;
                };
                let profile = setup.profile().clone();
                let scenario = setup.scenario().clone();
                println!(
                    "free-play-setup: start profile={}",
                    character_select::encode_profile(&profile)
                );
                println!("free-play-setup: start scenario={}", scenario.encode());
                resolve_city_map(install, &scenario.map_name).and_then(|city_map| {
                    spawn_free_play_session(
                        install,
                        &city_map,
                        branch_map,
                        self.game_frames,
                        &profile,
                        &scenario,
                    )
                    .map(|pid| {
                        println!(
                            "free-play-setup: launched city viewer pid={pid} map={}",
                            city_map.display()
                        );
                    })
                })
            }
        };
        match result {
            Ok(()) => self.free_play_pending = Some(action),
            Err(error) => {
                println!("free-play-setup: launch failed: {error}");
                if let Some(setup) = self.free_play_setup.as_mut() {
                    setup.set_status(format!("Could not continue: {error}"));
                }
                self.refresh_free_play_setup();
            }
        }
    }

    fn activate_free_play_at_cursor(&mut self) -> bool {
        let Some(position) = self.cursor_position else {
            return false;
        };
        let Some(setup) = self.free_play_setup.as_mut() else {
            return false;
        };
        let (hit, action) = setup.click_at(position.0, position.1);
        if !hit {
            return false;
        }
        if let Some(action) = action {
            println!(
                "free-play-setup: action={:?} id=0x{:03x} label=\"{}\"",
                action,
                action.control_id(),
                action.label()
            );
            self.finish_free_play_setup_action(action);
        } else {
            self.refresh_free_play_setup();
        }
        true
    }

    fn refresh_menu(&mut self) {
        let (Some(viewer), Some(menu)) = (self.viewer.as_mut(), self.menu.as_ref()) else {
            return;
        };
        viewer.update_image(&menu.render());
    }

    fn handle_menu_key(&mut self, key: &Key) -> bool {
        let Some(menu) = self.menu.as_mut() else {
            return false;
        };
        match key {
            Key::Named(NamedKey::ArrowUp) => {
                menu.select_previous();
                self.refresh_menu();
                true
            }
            Key::Named(NamedKey::ArrowDown) => {
                menu.select_next();
                self.refresh_menu();
                true
            }
            Key::Character(text) if text.eq_ignore_ascii_case("w") => {
                menu.select_previous();
                self.refresh_menu();
                true
            }
            Key::Character(text) if text.eq_ignore_ascii_case("s") => {
                menu.select_next();
                self.refresh_menu();
                true
            }
            Key::Named(NamedKey::Enter) | Key::Named(NamedKey::Space) => {
                let action = menu.activate();
                println!(
                    "menu: action={:?} id=0x{:03x} label=\"{}\"",
                    action,
                    action.control_id(),
                    action.label()
                );
                self.finish_menu_action(action);
                true
            }
            _ => false,
        }
    }

    fn finish_menu_action(&mut self, action: menu::MenuAction) {
        match action {
            menu::MenuAction::Quit => self.menu_pending = Some(action),
            menu::MenuAction::StartNewGame | menu::MenuAction::StartFreeGame => {
                let (Some(install), Some(branch_map)) =
                    (self.game_install.as_ref(), self.game_branch_map.as_ref())
                else {
                    return;
                };
                let free_game = action == menu::MenuAction::StartFreeGame;
                match spawn_character_select_viewer(
                    install,
                    branch_map,
                    free_game,
                    self.game_frames,
                ) {
                    Ok(pid) => {
                        println!("menu: launched character-select pid={pid}");
                        self.menu_pending = Some(action);
                    }
                    Err(error) => {
                        println!("menu: launch failed: {error}");
                        if let Some(menu) = self.menu.as_mut() {
                            menu.set_status(format!("Could not start game: {error}"));
                        }
                        self.refresh_menu();
                    }
                }
            }
            _ => self.refresh_menu(),
        }
    }

    fn activate_menu_at_cursor(&mut self) -> bool {
        let Some(position) = self.cursor_position else {
            return false;
        };
        let Some(menu) = self.menu.as_mut() else {
            return false;
        };
        let Some(index) = menu.button_at(position.0, position.1) else {
            return false;
        };
        menu.set_selected(index);
        menu.set_hover(Some(position));
        let action = menu.activate();
        println!(
            "menu: action={:?} id=0x{:03x} label=\"{}\"",
            action,
            action.control_id(),
            action.label()
        );
        self.finish_menu_action(action);
        true
    }

    fn refresh_explore(&mut self) {
        let (Some(viewer), Some(sim)) = (self.viewer.as_mut(), self.sim.as_ref()) else {
            return;
        };
        match self.mode {
            ViewMode::City => {
                let Some(world) = self.city_world.as_ref() else {
                    return;
                };
                let started = Instant::now();
                let mut view =
                    city_crop(world, self.width, self.height, self.camera_x, self.camera_y);
                if let (Some(_), Some((x, y))) = (self.lease_prompt, world.lease_site) {
                    overlay::draw_lease_marker(
                        &mut view,
                        self.width,
                        self.height,
                        x - self.camera_x,
                        y - self.camera_y,
                    );
                }
                if overlay::draw_city_status(
                    &mut view,
                    self.width,
                    self.height,
                    (self.camera_x, self.camera_y),
                    (world.width, world.height),
                    city_controls(sim, self.branch_base.is_some(), self.lease_prompt),
                    campaign_city_summary(sim, self.lease_prompt).as_deref(),
                )
                .is_ok()
                {
                    viewer.update_image(&view);
                    println!(
                        "explore: city camera {},{} crop_us={}",
                        self.camera_x,
                        self.camera_y,
                        started.elapsed().as_micros()
                    );
                }
            }
            ViewMode::Branch => {
                let (Some(base), Some(actors)) = (self.branch_base.as_ref(), self.actors.as_ref())
                else {
                    return;
                };
                let mut view = match actors::compose(
                    base,
                    self.width,
                    self.height,
                    actors,
                    &sim.snapshot(),
                    sim.customer_visible(),
                ) {
                    Ok(view) => view,
                    Err(_) => return,
                };
                if overlay::draw_status(
                    &mut view,
                    self.width,
                    self.height,
                    &sim.snapshot(),
                    sim.profile(),
                    sim.scenario(),
                )
                .is_ok()
                {
                    viewer.update_image(&view);
                    println!("explore: branch {}", sim.snapshot_json());
                }
            }
        }
    }

    fn handle_explore_key(&mut self, key: &Key) -> bool {
        if !self.explore {
            return false;
        }
        if self.mode == ViewMode::City {
            let step = 96;
            let Some(world) = self.city_world.as_ref() else {
                return false;
            };
            if self.lease_prompt.is_some() {
                if *key == Key::Named(NamedKey::Enter) {
                    let Some(sim) = self.sim.as_mut() else {
                        return true;
                    };
                    let Some(offer) = sim.campaign_property_offer() else {
                        return true;
                    };
                    match sim.lease_campaign_property(offer.tile_index) {
                        Ok(_) => {
                            self.lease_prompt = None;
                            self.mode = ViewMode::Branch;
                        }
                        Err(error) => self.lease_prompt = Some(LeasePrompt::Failed(error)),
                    }
                    self.refresh_explore();
                } else if *key == Key::Named(NamedKey::Escape) {
                    self.lease_prompt = None;
                    self.refresh_explore();
                }
                return true;
            }
            let max_x = (world.width.saturating_sub(self.width)) as i32;
            let max_y = (world.height.saturating_sub(self.height)) as i32;
            let mut handled = true;
            match key {
                Key::Named(NamedKey::ArrowLeft) => self.camera_x -= step,
                Key::Named(NamedKey::ArrowRight) => self.camera_x += step,
                Key::Named(NamedKey::ArrowUp) => self.camera_y -= step,
                Key::Named(NamedKey::ArrowDown) => self.camera_y += step,
                Key::Character(text) if text.eq_ignore_ascii_case("a") => self.camera_x -= step,
                Key::Character(text) if text.eq_ignore_ascii_case("d") => self.camera_x += step,
                Key::Character(text) if text.eq_ignore_ascii_case("w") => self.camera_y -= step,
                Key::Character(text) if text.eq_ignore_ascii_case("s") => self.camera_y += step,
                Key::Character(text)
                    if text.eq_ignore_ascii_case("b") && self.branch_base.is_some() =>
                {
                    if self.sim.as_ref().is_some_and(World::can_enter_branch) {
                        self.mode = ViewMode::Branch;
                    } else if let Some((x, y)) = world.lease_site {
                        self.camera_x = x - self.width as i32 / 2;
                        self.camera_y = y - self.height as i32 / 2;
                        self.lease_prompt = Some(LeasePrompt::Confirm);
                    }
                }
                _ => handled = false,
            }
            self.camera_x = self.camera_x.clamp(0, max_x);
            self.camera_y = self.camera_y.clamp(0, max_y);
            if handled {
                self.refresh_explore();
            }
            handled
        } else {
            match key {
                Key::Character(text) if text.eq_ignore_ascii_case("c") => {
                    self.mode = ViewMode::City;
                    self.refresh_explore();
                    true
                }
                _ => false,
            }
        }
    }

    fn refresh_playable(&mut self) {
        if self.explore {
            self.refresh_explore();
            return;
        }
        let (Some(sim), Some(base), Some(actors), Some(viewer)) = (
            self.sim.as_mut(),
            self.base_frame.as_ref(),
            self.actors.as_ref(),
            self.viewer.as_mut(),
        ) else {
            return;
        };
        let mut display = match actors::compose(
            base,
            self.width,
            self.height,
            actors,
            &sim.snapshot(),
            sim.customer_visible(),
        ) {
            Ok(display) => display,
            Err(_) => return,
        };
        if overlay::draw_status(
            &mut display,
            self.width,
            self.height,
            &sim.snapshot(),
            sim.profile(),
            sim.scenario(),
        )
        .is_ok()
        {
            viewer.update_image(&display);
            println!("sim: {}", sim.snapshot_json());
        }
    }
}

impl ApplicationHandler for WindowApp {
    fn resumed(&mut self, event_loop: &ActiveEventLoop) {
        if self.viewer.is_some() {
            return;
        }
        let Some(frames) = self.frames.take() else {
            self.error = Some("frames missing".into());
            event_loop.exit();
            return;
        };
        let attributes = Window::default_attributes()
            .with_title(format!("Pizza Connection 2 — {}", self.title))
            .with_inner_size(winit::dpi::LogicalSize::new(800, 600));
        let window = match event_loop.create_window(attributes) {
            Ok(window) => Arc::new(window),
            Err(error) => {
                self.error = Some(format!("window: {error}"));
                event_loop.exit();
                return;
            }
        };
        match Viewer::new(window, frames, self.width, self.height) {
            Ok(mut viewer) => {
                viewer.max_frames = self.max_frames;
                viewer.window.request_redraw();
                self.viewer = Some(viewer);
            }
            Err(error) => {
                self.error = Some(error);
                event_loop.exit();
            }
        }
    }

    fn window_event(
        &mut self,
        event_loop: &ActiveEventLoop,
        _window_id: WindowId,
        event: WindowEvent,
    ) {
        match event {
            WindowEvent::CloseRequested => event_loop.exit(),
            WindowEvent::Resized(size) => {
                if let Some(viewer) = &mut self.viewer {
                    viewer.resize(size.width, size.height);
                }
            }
            WindowEvent::RedrawRequested => {
                let Some(viewer) = &mut self.viewer else {
                    return;
                };
                viewer.render();
                if viewer.max_frames > 0 && viewer.frames_rendered >= viewer.max_frames {
                    println!("window: {} frames rendered", viewer.frames_rendered);
                    event_loop.exit();
                } else {
                    viewer.window.request_redraw();
                }
            }
            WindowEvent::CursorMoved { position, .. } => {
                if self.menu.is_some() || self.character.is_some() || self.free_play_setup.is_some()
                {
                    let (window_width, window_height) = self
                        .viewer
                        .as_ref()
                        .map(|viewer| {
                            let size = viewer.window.inner_size();
                            (size.width.max(1), size.height.max(1))
                        })
                        .unwrap_or((menu::MENU_WIDTH, menu::MENU_HEIGHT));
                    let x = (position.x * menu::MENU_WIDTH as f64 / window_width as f64) as i32;
                    let y = (position.y * menu::MENU_HEIGHT as f64 / window_height as f64) as i32;
                    self.cursor_position = Some((x, y));
                    if let Some(menu) = self.menu.as_mut() {
                        menu.set_hover(Some((x, y)));
                        self.refresh_menu();
                    } else if let Some(character) = self.character.as_mut() {
                        character.set_hover(Some((x, y)));
                        self.refresh_character();
                    } else if let Some(setup) = self.free_play_setup.as_mut() {
                        setup.set_hover(Some((x, y)));
                        self.refresh_free_play_setup();
                    }
                }
            }
            WindowEvent::CursorLeft { .. } => {
                self.cursor_position = None;
                if let Some(menu) = self.menu.as_mut() {
                    menu.set_hover(None);
                    self.refresh_menu();
                } else if let Some(character) = self.character.as_mut() {
                    character.set_hover(None);
                    self.refresh_character();
                } else if let Some(setup) = self.free_play_setup.as_mut() {
                    setup.set_hover(None);
                    self.refresh_free_play_setup();
                }
            }
            WindowEvent::MouseInput {
                state: ElementState::Pressed,
                button: MouseButton::Left,
                ..
            } => {
                if self.free_play_setup.is_some() {
                    if self.activate_free_play_at_cursor() && self.free_play_pending.is_some() {
                        event_loop.exit();
                    }
                } else if self.character.is_some() {
                    if self.activate_character_at_cursor() && self.character_pending.is_some() {
                        event_loop.exit();
                    }
                } else if self.activate_menu_at_cursor() && self.menu_pending.is_some() {
                    event_loop.exit();
                }
            }
            WindowEvent::KeyboardInput {
                event:
                    KeyEvent {
                        logical_key,
                        state: ElementState::Pressed,
                        ..
                    },
                ..
            } => {
                if self.menu.is_some() {
                    if logical_key == Key::Named(NamedKey::Escape) {
                        self.menu_pending = Some(menu::MenuAction::Quit);
                        event_loop.exit();
                        return;
                    }
                    if self.handle_menu_key(&logical_key) {
                        if self.menu_pending.is_some() {
                            event_loop.exit();
                        }
                        return;
                    }
                }
                if self.free_play_setup.is_some() {
                    if self.handle_free_play_setup_key(&logical_key) {
                        if self.free_play_pending.is_some() {
                            event_loop.exit();
                        }
                        return;
                    }
                    if logical_key == Key::Named(NamedKey::Escape) {
                        self.finish_free_play_setup_action(free_play_setup::Action::Back);
                        if self.free_play_pending.is_some() {
                            event_loop.exit();
                        }
                        return;
                    }
                }
                if self.character.is_some() {
                    if self.handle_character_key(&logical_key) {
                        if self.character_pending.is_some() {
                            event_loop.exit();
                        }
                        return;
                    }
                    if logical_key == Key::Named(NamedKey::Escape) {
                        self.finish_character_action(character_select::CharacterSelectAction::Back);
                        if self.character_pending.is_some() {
                            event_loop.exit();
                        }
                        return;
                    }
                }
                if self.handle_explore_key(&logical_key) {
                    return;
                }
                if logical_key == Key::Named(NamedKey::Escape) {
                    event_loop.exit();
                    return;
                }
                if self.explore && self.mode == ViewMode::City {
                    return;
                }
                let handled = match &logical_key {
                    Key::Character(text) => {
                        let value = text.as_str();
                        if value.eq_ignore_ascii_case("o") {
                            if let Some(sim) = &mut self.sim {
                                let open = sim.snapshot().open;
                                sim.set_open(!open);
                            }
                            true
                        } else if value == "+" || value == "=" {
                            if let Some(sim) = &mut self.sim {
                                let price = sim.snapshot().price;
                                sim.set_price(price + 1.0);
                            }
                            true
                        } else if value == "-" || value == "_" {
                            if let Some(sim) = &mut self.sim {
                                let price = sim.snapshot().price;
                                sim.set_price(price - 1.0);
                            }
                            true
                        } else if value.eq_ignore_ascii_case("n") {
                            if let Some(sim) = &mut self.sim {
                                sim.step();
                            }
                            true
                        } else {
                            false
                        }
                    }
                    Key::Named(NamedKey::Space) => {
                        if let Some(sim) = &mut self.sim {
                            sim.step();
                        }
                        true
                    }
                    Key::Named(NamedKey::ArrowUp) => {
                        if let Some(sim) = &mut self.sim {
                            let price = sim.snapshot().price;
                            sim.set_price(price + 1.0);
                        }
                        true
                    }
                    Key::Named(NamedKey::ArrowDown) => {
                        if let Some(sim) = &mut self.sim {
                            let price = sim.snapshot().price;
                            sim.set_price(price - 1.0);
                        }
                        true
                    }
                    _ => false,
                };
                if handled {
                    self.refresh_playable();
                }
            }
            _ => {}
        }
    }
}

#[allow(clippy::too_many_arguments)]
fn run_explore_window(
    title: String,
    city_world: CityWorld,
    city_view: Vec<u8>,
    branch: Option<(Vec<u8>, actors::Actors)>,
    width: u32,
    height: u32,
    max_frames: u32,
    sim: World,
    camera_x: i32,
    camera_y: i32,
) -> Result<(), String> {
    let event_loop = EventLoop::new().map_err(|error| format!("event loop: {error}"))?;
    let mut app = WindowApp::new_explore(
        title, city_world, city_view, branch, width, height, max_frames, sim, camera_x, camera_y,
    );
    event_loop
        .run_app(&mut app)
        .map_err(|error| format!("event loop: {error}"))?;
    if let Some(error) = app.error {
        return Err(error);
    }
    Ok(())
}

fn run_playable_window(
    title: String,
    base: Vec<u8>,
    display: Vec<u8>,
    width: u32,
    height: u32,
    max_frames: u32,
    sim: World,
    actors: actors::Actors,
) -> Result<(), String> {
    let event_loop = EventLoop::new().map_err(|error| format!("event loop: {error}"))?;
    let mut app =
        WindowApp::new_playable(title, base, display, width, height, max_frames, sim, actors);
    event_loop
        .run_app(&mut app)
        .map_err(|error| format!("event loop: {error}"))?;
    if let Some(error) = app.error {
        return Err(error);
    }
    Ok(())
}

fn run_window(
    title: String,
    frames: Vec<Vec<u8>>,
    width: u32,
    height: u32,
    max_frames: u32,
) -> Result<(), String> {
    let event_loop = EventLoop::new().map_err(|error| format!("event loop: {error}"))?;
    let mut app = WindowApp::new(title, frames, width, height, max_frames);
    event_loop
        .run_app(&mut app)
        .map_err(|error| format!("event loop: {error}"))?;
    if let Some(error) = app.error {
        return Err(error);
    }
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn city_crop_pans_without_reloading() {
        let mut pixels = Vec::new();
        for y in 0..3u32 {
            for x in 0..4u32 {
                pixels.extend_from_slice(&[x as u8 * 10, y as u8 * 10, 0, 255]);
            }
        }
        let world = CityWorld {
            width: 4,
            height: 3,
            pixels,
            lease_site: None,
        };
        let first = city_crop(&world, 2, 2, 0, 0);
        let moved = city_crop(&world, 2, 2, 2, 1);
        assert_eq!(&first[0..4], &[0, 0, 0, 255]);
        assert_eq!(&first[4..8], &[10, 0, 0, 255]);
        assert_eq!(&moved[0..4], &[20, 10, 0, 255]);
        assert_eq!(&moved[4..8], &[30, 10, 0, 255]);
        assert_ne!(first, moved);
    }

    #[test]
    fn default_branch_map_resolves_under_install() {
        let root = std::env::temp_dir().join(format!("pc2-menu-install-{}", std::process::id()));
        let branch_dir = root.join("Isokarten");
        std::fs::create_dir_all(&branch_dir).unwrap();
        let map = branch_dir.join("Iso_Filiale_einf_klein.iso");
        std::fs::write(&map, []).unwrap();
        let mut args = Args::default();
        args.install = root.clone();
        assert_eq!(resolve_branch_map(&args), map);
        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn surface_resize_clamps_to_downlevel_limit() {
        assert_eq!(clamp_surface_size(800, 600, 16384), (800, 600));
        assert_eq!(clamp_surface_size(3840, 2068, 2048), (2048, 1102));
        assert_eq!(clamp_surface_size(1200, 4800, 2048), (512, 2048));
        assert_eq!(clamp_surface_size(0, 0, 16384), (1, 1));
    }

    #[test]
    fn viewer_and_cli_share_world_event_sequence() {
        let mut viewer = World::new(10 * 60 + 55);
        viewer.set_open(false);
        viewer.set_open(true);
        let mut viewer_events = Vec::new();
        for _ in 0..4 {
            viewer_events.extend(viewer.step());
        }

        let mut cli = World::new(10 * 60 + 55);
        cli.set_open(false);
        cli.set_open(true);
        let cli_events = cli.advance_to(11 * 60 + 15);

        assert_eq!(viewer_events, cli_events);
        assert_eq!(viewer.world_snapshot(), cli.world_snapshot());
        assert_eq!(viewer.visit_state(), pc2_sim::VisitState::Idle);
        assert_eq!(viewer.snapshot().stock, 399.0);
        assert!((viewer.snapshot().cash - 10_013.420_524_712_366).abs() < 1e-9);
    }
}
