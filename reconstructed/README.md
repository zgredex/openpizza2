# Reconstructed C code

This tree turns evidence-backed decompiled functions into normal C that a host
compiler can build. It is deliberately **not** byte-exact yet: the goal is a
readable, testable reconstruction with explicit layouts.

Current batches:

- `settings/` — settings block layout, `Settings_InitDefaults` behavior, and the
  defaults that the Unicorn probe `tools/emulate_settings_defaults.py` observes.
- `ingredient/` — `Ingredient` prefix layout and `Game_SetBuildingDesc`, checked
  against the Olives descriptor read back by
  `tools/emulate_ingredient_desc.py`.
- `mission/` — `MissionState` layout, the campaign branch of
  `Game_InitDateState`, and the London goal ids 0/1/2 from
  `Mission_EvaluateGoals`, tested against the existing 9/9 Unicorn mission
  fixture.
- `branch/` — one-serving branch economy, price formula and sale arithmetic
  using the Rust-verified constants (`13.420524712365806` cash delta at price
  `12`).
- `menu/` — main-menu controls, hit testing, selection, hover and activation
  status restored from `Screen_MainMenu`.
- `city/` — city/branch state, London lease, HQ/rat mission actions and branch
  sale integration.
- `test_game` — one executable linking settings, ingredient, menu, mission,
  branch and city modules through the full London loop.

Build and run:

```bash
make -C reconstructed check
```

Layout offsets are anchored with `_Static_assert`, so an accidental field
insertion fails the build instead of silently changing the ABI.
