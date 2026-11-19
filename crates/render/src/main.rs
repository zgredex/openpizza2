use std::process::ExitCode;

fn main() -> ExitCode {
    match pc2_render::render_two_quads() {
        Ok(result) => {
            println!("adapter: {}", result.adapter);
            println!("backend: {}", result.backend);
            println!(
                "size: {}x{}",
                pc2_render::TARGET_SIZE,
                pc2_render::TARGET_SIZE
            );
            println!("red corner: {:?}", result.pixel(8, 56));
            println!("green corner: {:?}", result.pixel(56, 8));
            println!("overlap center: {:?}", result.pixel(32, 32));
            if result.backend == "Vulkan"
                && result.pixel(8, 56) == [255, 0, 0, 255]
                && result.pixel(56, 8) == [0, 255, 0, 255]
                && result.pixel(32, 32) == [0, 255, 0, 255]
            {
                println!("result: OK");
                ExitCode::SUCCESS
            } else {
                println!("result: FAILED");
                ExitCode::FAILURE
            }
        }
        Err(error) => {
            eprintln!("result: FAILED: {error}");
            ExitCode::FAILURE
        }
    }
}
