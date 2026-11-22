# Regenerating UI builders for VC6

`tools/generate_ui_builder.py` translates the checked-in named decompiler exports for builders with a linear sequence of known UI methods, local null guards, and optional gradient assignments. It writes generated C++ and matcher receipts to a fresh scratch directory. The named export and PE index provide the method identities. Before generating source, the tool checks the entire ordered direct-call sequence and the stack cleanup at every modeled callee's reachable returns. A clean extraction establishes those facts. The strict VC6 matcher provides full-body verification.

Run with the pinned [VC6 toolchain](../VC6_TOOLCHAIN.md) and a Python environment containing Capstone 5.0.7.

```sh
python tools/generate_ui_builder.py \
  --address 0x443520 --address 0x4556f0 \
  --out /tmp/pc2-ui-builders --verify
```

Both builders passed the strict verifier under pinned VC6 with `/O2 /TP`. `StatisticsView_CreateWindow` matched 1,107 bytes and 43 call sites. `SubMenu_BuildGuardAssignment` matched 1,257 bytes and 51 call sites. The verified spans also linked into a byte-identical scratch PE. `report.json` gives the generation and match verdicts with input hashes, and each `.match.json` preserves the full compiler, relocation, and diff evidence.

For extraction only, omit `--verify`. Unsupported statements, mismatched
callees, and unsupported control flow stop the translator.

## Verify the full cohort

The batch tool selects contiguous indexed functions whose named exports have
the supported window-builder signature and at least one common UI creation
call. Use a fresh scratch directory.

```sh
python tools/verify_ui_builder_batch.py --out /tmp/pc2-ui-full --jobs 4
python tools/verify_ui_builder_batch.py --out /tmp/pc2-ui-full-repeat \
  --reuse /tmp/pc2-ui-full --jobs 4
```

Use `--scan-only` for extraction and call verification without VC6.
`--reuse` checks the previous object and recipe hashes, then reruns strict
matching against the current PE and symbol facts. It compiles candidates
without a reusable object. The batch saves `report.json`, full per-function
receipts, a byte-identical `linked.exe`, and a linked manifest usable by
`replay_worklist.py --overlay-manifest`.

The original 70 builders passed strict verification under `/O2 /TP`,
covering 362,189 code bytes. This included all 29,960 bytes of
`Window_BuildStatisticsBranchBalancePage`. The broader selector added 44
strict matches totaling 66,974 bytes, including the main menu, save and
load screens, and options panels. Recovering `UI_AddInputField` and its
color setters added Character Select, AI Debug Status, and Request Dialog
for another 5,606 bytes. The batch now links **117 strict builders covering
434,769 code bytes** into a byte-identical scratch PE.

The broader scan reports three unsupported exports at `0x4275a0`,
`0x42d990`, and `0x474df0`. The tool saves its report and linked image
before returning a nonzero exit code for these unsupported inputs.

Three shared text-button methods enabled 43 builders in the original cohort.
Three named callback references and optional whitespace before a call's
opening parenthesis enabled the last four in that cohort. Named callback
targets must be unique in the pinned symbol index and pushed by the
original builder.

## Word-sized layout arguments

The first statistics compile matched through byte 723. `Window_GadgetNotify_Text_SetLayout` then received `0x0000ffff` in the generated code where the PE emits `push -1`. The callee at `0x52f9d0` reads only the low word of its third and fourth argument slots. Modeling both as `short` preserves the value the callee reads and lets VC6 emit the same signed push. The declaration applies to all translated builders.

## Panel updater pilot

```sh
python tools/verify_ui_updater_pilot.py --out /tmp/pc2-ui-updaters --verify --jobs 3
```

Use a fresh directory. Omit `--verify` to generate the candidates and check
the original calls without Wine. Use `--address` to select one pilot target.
The report records recovered variadic group arguments, original and emitted
call checks, and the strict byte total. Each compile writes a separate
matcher receipt. Check `strict_bytes` for the match result.

The pilot validates the shared method table's stack cleanup against the pinned
PE. It recovers the child IDs missing from `UI_Group_Create` exports by reading
the original pushes and caller cleanup. The two submenu variants call the
list deleting destructor through vtable slot zero with flag 1. The compiler
check verifies this dispatch sequence in both emitted functions. The reused
Variant 1 draft now calls the original player field getter at `0x4e2280` at
the group-size branch.

All three candidates compiled with pinned VC6 SP3 and `/O2 /TP`.

| Candidate | Original bytes | Differing bytes | First divergence |
| --- | ---: | ---: | --- |
| `SubMenu_UpdateButtonStatesVariant1` | 893 | 43 | `+0x3c`, count store scheduled ahead of the panel pointer reload |
| `SubMenu_UpdateButtonStatesVariant2` | 920 | 255 | `+0x235`, the four hide calls are placed later than in the PE |
| `RecipeKitchen_UpdateTabButtons` | 953 | 262 | `+0x3c`, count store scheduled ahead of the panel pointer reload |

Variant 1 and the kitchen updater preserve the full direct-call order.
Variant 2 emits all 41 direct calls, with a different order between branch
blocks. The pilot added zero strict bytes.
