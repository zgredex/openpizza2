# Native Vulkan sprite and Bink source patch — integration requirements

This patch **adds a native 2D Vulkan renderer and a native Bink 1 FFmpeg decoder**.
It does not fake completion of the full game renderer port. It is a concrete
implementation of the GPU destination, deliberately not an RGB565 frame uploader
or a DirectDraw/Win32 API replacement. The recovered game is not wired to it yet.

## Build and run separately (requires development packages)

```sh
cd tools/pcrecomp_pc2/native_vk
make
./smoke                         # colored GPU sprites with clipping/blending
./smoke /path/to/extracted.bik  # Bink -> FFmpeg -> Vulkan movie + SDL audio
```

This code requires: SDL2, Vulkan headers/loader/driver, `glslc`, and FFmpeg
libavformat, libavcodec, libavutil, libswscale and libswresample development
packages. On Arch Linux install the corresponding development libraries; a
32-bit host additionally requires **32-bit** versions of all linked libraries.
Do not assume the 64-bit smoke build proves i686 compatibility.

The display must expose an X11 or Wayland Vulkan surface; `SDL_VIDEODRIVER=dummy`
is for the existing headless test host, not this graphical smoke test.

## How the real game must be rewired

The public `main.c` still assigns `hle_dd_frame_hook = pc2_dd_frame_hook` and
calls `hle_screen_open`, which lives in `win32hle`. Those are NOT part of this
native backend. Do not simply point the frame hook at `pc2_vk_draw`—that would
keep the CPU renderer and fail the full-port goal.

Delete DirectDraw as the game's render architecture only after the recovered
renderer can dispatch these operations directly into `pc2_vk_*`:

1. `0x5243c0 Window_RenderFrame`: construct one GPU frame from scene commands.
2. `UI_RenderScene`: traverse the existing display list / UI widgets without
   painting the entire scene into `renderer + 0x28` first.
3. `0x539980 Gfx_BlitClipped16` and other sprite/font/tile draw operations:
   look up or upload decoded source sprites, then emit `pc2_vk_draw` quads,
   reproducing source clipping, palette/colorkey, ordering and blend modes.
4. `0x538da0 Surface_BlitRectRetry`: no longer participates in frame display.
5. Create the actual `SDL_WINDOW_VULKAN` window and initialize `pc2_vk_create`.
6. Remove `hle_dd_blit_hook`, `hle_dd_frame_hook`, DirectDraw surface creation,
   CPU frame presentation, and all DirectDraw imports from the active render
   code and linked runtime. A `grep` or runtime dispatch audit must prove zero
   active DirectDraw calls.
7. Keep normal game state and non-graphics interfaces separate. Recompilation
   dispatch ABI and guest-pointer layout must be preserved until its native
   calls are replaced deliberately, not by one global `memcpy`/blit hook.

The Bink replacement is also a **direct gameplay call-site replacement**, not a
`BinkOpen` shim:

- `0x4ce9d0 Movie_Play` owns the movie window/cutscene lifecycle.
- The decoder API calls are concentrated in the original code near
  `0x52af32`–`0x52bc70`.
- Read the movie's data bytes from `movie.pak` through the existing archive
  decoder, then call `pc2_movie_open_memory` on those actual bytes.
- Drive `pc2_movie_next`, use timestamps for pacing and call
  `pc2_movie_draw` on the same renderer/swapchain as sprites.
- Call `pc2_movie_release_gpu(movie,renderer)` before `pc2_movie_close(movie)`.
- Verify each installed Bink variant with the real FFmpeg decoder; header
  inspection alone is not enough. Newer Bink2 variants may require a decoder
  not available in the installed FFmpeg release.

## Native draw semantics still needing code work

`pc2_vk_draw` is a **quad** draw. A full sprite renderer must additionally
reconstruct source and destination rectangle clipping, palette decode,
color-key alpha, ROP/blending differences, text glyphs, animations, dirty
rectangles, cursor order, tiled maps and any render-to-texture operations used
by the game. Do not report success until these match the existing replays.

The conservative implementation waits for GPU queue idle during texture
updates and before each frame. It is correct-first and not a final batching,
async-upload, or descriptor-pool strategy. Implement an upload ring and frame
fences after a playable renderer cutover, not before.

## Verification and forbidden shortcuts

- `./smoke`: actual native GPU sprite/clip and Bink playback evidence.
- A real game build must still pass main menu, character select, gameplay,
  camera scrolling, mouse, saves and cutscene transition tests.
- Render parity must be measured from *source draw commands*, NOT by uploading
  `renderer+0x28` or the HLE primary surface to a Vulkan texture.
- Do not keep `win32hle` DirectDraw objects behind Vulkan wrapper names.
- Do not silently fall back to SDL_Renderer, OpenGL, DirectDraw or black frames.
- Do not claim this patch provides a playable full game port before call-site
  integration and verification are complete.
