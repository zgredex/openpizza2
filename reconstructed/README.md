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
- `mission/` — `MissionState` layout and the campaign branch of
  `Game_InitDateState`, with the goal/progress/completed offsets used by the
  existing Unicorn mission probe.

Build and run:

```bash
make -C reconstructed check
```

Layout offsets are anchored with `_Static_assert`, so an accidental field
insertion fails the build instead of silently changing the ABI.
