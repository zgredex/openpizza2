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
for another 5,606 bytes. A final parser fix accepts whitespace before a
call's closing semicolon; this added `Screen_MissionGoals` (`0x42d990`,
1,105 bytes). The parser also learned local `char[64]` buffers,
`IDMap_Lookup`, `String_Format`, and the `DAT_0057c670` pointer global;
that added `OfficeView_CreateWindow` (`0x4275a0`, 902 bytes). A final
if/else format-selection shape added `Screen_MissionBriefing` (`0x474df0`,
691 bytes). The batch now links **120 strict builders covering 437,467 code
bytes** into a byte-identical scratch PE.

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

### Relocation-aware block comparison

```sh
python tools/compare_match_blocks.py \
  --object /tmp/pc2-ui-updaters/0x4cec60.obj \
  --receipt /tmp/pc2-ui-updaters/0x4cec60.match.json \
  --out /tmp/pc2-ui-updater-blocks.json
```

The comparison requires the original PE and COFF hashes from the matcher
receipt. It applies resolved relocations at candidate sites, decodes
reachable blocks, and pairs them using the entry, unique instruction
encodings, and corresponding edges with the same call targets. It reports
the first differing instruction in each pair and lists unpaired blocks and
unresolved relocations. The pairing is diagnostic. The strict verdict
comes from the matcher receipt.

The positive control, strict builder `0x4556f0`, gave 29 equal block pairs
with no unpaired blocks. The original updater pilot objects gave 10 of 13,
10 of 21, and 6 of 9 equal pairs for Variant 1, Variant 2, and Kitchen.

Four source shapes per function tested the shared count spill in Variant 1
and Kitchen. An early panel alias, an explicit snapshot of the count, and a
volatile pointer view all reproduced the baseline code. An inlined helper
that takes the receiver and stores the count moved both functions past
`+0x3c` while preserving direct-call order. The comparison also exposed a
four-byte store to `0x57ca2c` in Kitchen. The original instruction at
`0x4cff59` clears one byte. The generator now guards the original operand
width and declares the field as an unsigned byte.

The integrated build has **35 differing bytes and 11 of 13 equal block
pairs** for Variant 1, and **252 differing bytes and 7 of 9 equal block
pairs** for Kitchen. The linked Kitchen candidate now clears a single byte.
Both candidates still miss the strict check. The earlier table records the
baseline values before these changes.

### Strict match for Submenu Variant 1

Six shared count-read variants tested how VC6 reads the volatile count and
forms the integer visibility flag. The inlined signed predicate takes the
count by value, so the call site still performs one volatile read. It
recreated the reload-before-`xor` sequence in Variant 1 and improved Kitchen
from 252 to 194 diagnostic differences.

For Variant 1, staging the player slot through an inlined adapter and reusing
the object-address local for the key after the slot lookup reproduced the
entire 57-instruction final block. The combined changes pass strict matching
for all **893 bytes** at `0x4cec60`. The block comparison reports 13 equal
pairs out of 13. The full pilot verifies all three candidates and emits
`linked.exe` and its manifest for the strict span. The linked image compares
byte-for-byte with the original executable. Variant 2 and Kitchen still have
255 and 194 diagnostic differences, respectively.

### Kitchen updater at 23 differences

Twelve VC6 variants isolated the count read and current-player lookup. The
best combined candidate snapshots the volatile count into the existing
integer local, then forms the visibility flag. The lookup names the player
slot and company ID, then stages the player receiver through that same local.
The integrated result retains all 49 direct calls in order and the original
one-byte flag clear.

The candidate has the original 953-byte extent, no unresolved relocation
checks, and **eight of nine equal block pairs**. All remaining **23 byte
differences** are in boolean instruction scheduling and register selection
between offsets `+0x150` and `+0x1db`. At the first count reload, the
original puts the count in EBP and the flag in EDX. The candidate uses EDX
and EAX. The kitchen updater remains short of a strict match. The same
verification run reconfirmed Submenu Variant 1 and linked its 893 bytes
into a byte-identical scratch executable.

### Kitchen updater at two differences

Eight variants tested local reuse across the two tab selections and the
volatile count read. Reusing one signed local for both selections and the
direct count snapshot removed 21 of the 23 differences. Four follow-up
variants tested an existing local, an inline output reference, an inline
visibility setter, and the setter's integer return type. All retained the
same two differences.

The independently relocated candidate differs at `+0x150` (`6c` to `44`,
the count load) and `+0x156` (`ed` to `c0`, the test). The original uses
EBP and the candidate uses EAX for the same value. The 953-byte extent,
49 ordered calls, and one-byte flag clear still agree. Kitchen adds zero
strict bytes. Submenu Variant 1 still verifies and links its 893 bytes.
