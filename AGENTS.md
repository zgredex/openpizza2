# Agent Notes

## Working style

- Inspect before changing: read `git log`, `git status`, `tools/pcrecomp_pc2/README.md`,
  `tools/pcrecomp_pc2/TRACE_CAPTURE.md`, and existing scenarios before starting a
  replay.
- Reuse existing tooling and prior evidence. Do not rebuild what is already
  committed or re-run a solved milestone.
- If the user has committed a fix, treat it as authoritative. Inspect it, adopt
  its approach, and discard superseded experimental edits instead of layering
  more probes on top.
- Keep the worktree clean. Commit focused changes with concrete evidence.
  Never commit generated C, `/tmp` artifacts, or temporary probe code.

## PC2 replay and tracing

- The non-headless Vulkan path owns its SDL window, Vulkan surface and input
  pump in `pc2_vulkan.c`. Do not reintroduce `hle_screen_gl`,
  `hle_screen_gl_picture`, the win32hle window/frame-hook presenter, or the
  `screen.c` module; the Makefile excludes it. `PC2_HEADLESS=1` is the native
  headless capture path.
- `Movie_Play` is native: `pc2_native_movie.c` reads `movie.pak` and
  `native_vk/pc2_movie.c` decodes it with the private 32-bit FFmpeg build.
  Do not reintroduce `bink.c` or the Bink DLL calls; `PC2_MOVIE_CAPTURE` is the
  frame-level check and headless runs intentionally skip movies.
- Use the headless capture runner for UI work:
  `python3 tools/pcrecomp_pc2/capture.py run <scenario> --work ... --out ...`.
  Use `--skip-build` when the instrumented host is already current.
- Never brute-force UI coordinates by repeating long headless runs. Derive
  coordinates from the decompiled UI layout or from an observed transition,
  then encode the path as a scenario.
- Prefer `wait_function`, `wait_value`, and `assert_value` over fixed delays.
  Every click should have an observed effect; a posted click alone is not
  evidence.
- Capture short, bounded phases around the action. Read `report.json`,
  `host.log`, and the state watches. Check unresolved `ICALL`/dispatch edges.
- Verify gameplay with guest state, not pixels or byte counts alone:
  branch/player IDs, roster membership, employee IDs and roles, stock changes,
  sales records, cash deltas, and clock progression.
- Use `PC2_TRACE_STAFF` and `PC2_TRACE_SALES` for staffing and order traces.
  Keep trace output bounded.
- Treat `london-staff.json` and `london-operations.json` as the reference
  replays. Extend them rather than creating a parallel click driver.

## Code changes

- When setting up or restoring matching tools, follow
  [the pinned VC6 SP3 runbook](reconstructed/match/VC6_TOOLCHAIN.md).
- Put durable changes in committed source, not in generated C.
- Add lift seeds in `tools/pcrecomp_pc2/lift.py`; the build asserts seeded
  functions are present in the dispatch table.
- Add generated-C instrumentation through
  `tools/pcrecomp_pc2/trace_points.py`, and make it idempotent.
- Keep host-side presentation changes guest-layout-neutral. Preserve the
  existing guest branches unless the task proves they must change.
- Before claiming completion, run the exact scenario/command and show the
  state transition and final checkpoint.

## Failure handling

- If a run is interrupted, inspect the existing log and artifacts before
  rerunning.
- If the first transition fails, report the first failed handler or state
  transition, not a speculative downstream cause.
- Do not ask the user to decide routine implementation details. Ask only when
  blocked by missing credentials, unavailable input, or an explicit product
  choice.
