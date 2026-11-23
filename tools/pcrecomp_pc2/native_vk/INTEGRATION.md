# Native Vulkan sprite and Bink source patch — integration requirements

The game host presents the CPU-rendered RGB565 frame through Vulkan and plays
Bink movies through FFmpeg. The separate native quad renderer supports source
textures, color keys, and clipping. The game still needs to emit source draws
to that renderer.

## Build and run separately (requires development packages)

```sh
cd tools/pcrecomp_pc2/native_vk
make
./smoke                         # colored GPU sprites with clipping/blending
./smoke /path/to/extracted.bik  # Bink -> FFmpeg -> Vulkan movie + SDL audio
make check-source-quads        # optional X11 pixel readback test
```

This code requires: SDL2, Vulkan headers/loader/driver, `glslc`, and FFmpeg
libavformat, libavcodec, libavutil, libswscale and libswresample development
packages. On Arch Linux install the corresponding development libraries; a
32-bit host additionally requires **32-bit** versions of all linked libraries.
Do not assume the 64-bit smoke build proves i686 compatibility.

The display must expose an X11 or Wayland Vulkan surface; `SDL_VIDEODRIVER=dummy`
is for the existing headless test host, not this graphical smoke test.

## How the real game must be rewired

The host opens its SDL Vulkan window through `pc2_vulkan_open` and retrieves
completed frames in `pc2_native_present` from DirectDraw or the GDI window.
Maintain one swapchain owner when replacing that presentation path.

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

The existing Bink replacement already intercepts `Movie_Play` and reads
compressed data from `movie.pak`. When switching swapchain owners, route movies
through the same renderer as sprites:

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

Set `"env": {"PC2_TRACE_DRAW": "1"}` in a copy of an existing capture scenario,
build the capture host, and run the scenario with `capture.py run`. Read the
`[draw]` entries in `host.log`. The hook logs up to 32 entries per sampled
function. Sprite entries record the guest receiver and render target argument.
Use these values to identify which operations populate each render target
before choosing the source decoder and frame boundary to port.

The menu-to-character-select replay reached screens 21 and 28 with
zero unresolved dispatches in the captured click phase. Its draw log contained
`Sprite_BlitAlphaRLEAlt`, `Sprite_Blit24Bit`, and `Font_DrawGlyphClipped`
entries. It hit `Surface_BlitRectRetry` and did not sample any
`Gfx_BlitClipped16` entries. A cutover for this replay needs the source sprite
and glyph calls and the DirectDraw presentation branch. Start with
`Sprite_BlitAlphaRLEAlt` and track its target separately from
`Sprite_Blit24Bit`, which used a different target in the sampled calls.
The `[draw-source]` records for `Sprite_BlitAlphaRLEAlt` include the
runtime encoding flags, depth, dimensions, transparency key, placement and
destination pixel format. Decode against these observed inputs before choosing
which sprite variants to enable in the Vulkan path.
The first 64 sampled calls used flags `0x03`, depth 8 and color key
`0xe6`. The three 12×17 sprites reported source lengths of 82, 82 and 94
bytes at sprite offset `0x18`. These match the shapes and compressed lengths
of the installed `sc_03.spr`, `sc_04.spr` and `sc_05.spr` assets. The indexed
decoder accepts the exact source payload and the game's 256-entry palette
for that draw. The source-quad smoke covers decoding, upload, color-key
transparency and GPU readback.

### Live indexed panel comparison

Set `PC2_VK_LIVE_INDEXED_SHADERS` in the capture scenario's `env` to the
absolute directory containing `quad.vert.spv` and `quad.frag.spv`. Build
the capture host and run the existing menu-click replay. This enables a
diagnostic Vulkan mirror for up to 16 compatible 8-bit indexed surfaces.
It seeds each target once from the legacy pixels, then preserves
the Vulkan target across up to 64 live draws per surface in game order. The original
blitter supplies the reference after each draw. Check `host.log` for
`[vk-live]` and require zero mismatches for every draw.

Set `PC2_VK_LIVE_INDEXED_PUBLISH=1` alongside the shader path to test the
compositor bridge. This copies opaque pixels from the Vulkan result into
the legacy surface and suppresses the original indexed raster store after
a successful readback. The lifted sprite traversal still runs and preserves
the guest calling convention. Transparent pixels keep their existing values.
Look for `[vk-live] published indexed draw` in `host.log`.

The publication replay handled 98 indexed draws across three surfaces.
Before draw 16 on the 175×8 surface, the renderer released and reconfigured
the same guest object. `Mem_FillWord` then filled its reused pixel buffer
with `0x07c0`. The old mirror kept stale pixels because both addresses were
unchanged. It now checks for guest writes before each draw and refreshes the
Vulkan target if needed. The replay detected 660 changed pixels before the
draw and matched the CPU surface after all 98 draws. The publication replay
matched the 800×600 CPU menu capture byte for byte and reached character
select with zero unresolved dispatches. Final composition and presentation
still use the legacy surface in this capture-only mode.

The capture host records guest `Mem_FillWord` commands. When a recorded
fill covers a tracked target and its contents confirm there have been no
later writes, the target is initialized or reset with a Vulkan clear.
In the menu-click replay all four target initializations and resets used
this clear path with RGB565 color `0x07c0`, including the 175×8 reuse before
draw 16. The mirror matched all 98 draws, and publication retained the
byte-identical menu frame. Other guest pixel changes still use the
compatibility upload path.

### Indexed sprite target parity

Add `"PC2_INDEXED_SPRITE_FIXTURE": "/tmp/pc2-menu-indexed.spr1"` to the
`env` of a copy of the `menu-click.json` scenario, then run it with the
capture host. The first compatible indexed draw writes its bounded encoded
source, RGB565 palette, and target crop before and after the original blit.
This currently covers 8-bit color-key RLE with an optional bottom clip.

```sh
make -C tools/pcrecomp_pc2/native_vk indexed-target-test
tools/pcrecomp_pc2/native_vk/indexed-target-test /tmp/pc2-menu-indexed.spr1 \
    tools/pcrecomp_pc2/native_vk/shaders
```

The check uses the before crop as a reference background, draws the decoded
sprite into an offscreen Vulkan target, samples it into a second target and
checks every pixel against the original after crop. It needs a Vulkan
driver. It can run without SDL video or a compositor.

## Full game renderer acceptance

To isolate the main-menu frame, set `PC2_TRACE_MENU_COMPOSITION=1` in the
menu-click capture scenario. The bounded `[menu-draw]` log records source
format, renderer object, and backing pixel pointer on settled screen 21.
The verified replay showed a 16-bit `Sprite_Blit24Bit` background, 8-bit
`0x17` alpha sprites, and `Font_DrawGlyphClipped` writing the renderer
that `Surface_BlitRectRetry` presents. The renderer object stayed constant
across the sampled presents while the backing pointer changed. A native
menu frame needs all three source-draw paths in order and a GPU-owned
replacement for that backbuffer and present operation.

Set `PC2_VK_MENU_BITMAP_SHADERS` in the same capture scenario to the
absolute shader directory to verify the background path. The capture host
uploads the original 16-bit bitmap from `Sprite_Blit24Bit` and draws it
into an 800×600 Vulkan target. It compares the result immediately after
the legacy bitmap draw, before the sprites and glyphs are added. The
screen-21 replay matched all 480,000 pixels on 32-bit RADV and reached
character select with zero unresolved dispatches.

Replay the menu through character select, then London through camera
scrolling and opening a branch panel. At each checkpoint record actual
Vulkan submissions by draw family and compare the GPU frame against the
legacy renderer under identical input. Include fonts, cursor, effects and
transitions in the comparison. The native renderer must allocate and update
its own render targets, including intermediate targets used as later inputs.
Run the suite on native Wayland. Complete the cutover by building and running
the supported scenarios with the DirectDraw and GDI raster implementations
removed from the game host link.

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
