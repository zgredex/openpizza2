# Regenerating UI builders for VC6

`tools/generate_ui_builder.py` translates the checked-in named decompiler exports for builders with a linear sequence of known UI methods, local null guards, and optional gradient assignments. It writes generated C++ and matcher receipts to a fresh scratch directory. The named export and PE index provide the method identities. Before generating source, the tool checks the entire ordered direct-call sequence and the stack cleanup at every modeled callee's reachable returns. A clean extraction establishes those facts. The strict VC6 matcher provides full-body verification.

Run with the pinned [VC6 toolchain](../VC6_TOOLCHAIN.md) and a Python environment containing Capstone 5.0.7.

```sh
python tools/generate_ui_builder.py \
  --address 0x443520 --address 0x4556f0 \
  --out /tmp/pc2-ui-builders --verify
```

Both builders passed the strict verifier under pinned VC6 with `/O2 /TP`. `StatisticsView_CreateWindow` matched 1,107 bytes and 43 call sites. `SubMenu_BuildGuardAssignment` matched 1,257 bytes and 51 call sites. The verified spans also linked into a byte-identical scratch PE. `report.json` gives the generation and match verdicts with input hashes, and each `.match.json` preserves the full compiler, relocation, and diff evidence.

For extraction only, omit `--verify`. The same translator accepts `Window_BuildStatisticsBranchBalancePage` at `0x433790` with 1,153 direct sites. This is an extraction result for that address. Use its [investigation](0x433790/worklog.md) for code-generation status. Unsupported statements, mismatched callees, and unsupported control flow stop the translator.

## Word-sized layout arguments

The first statistics compile matched through byte 723. `Window_GadgetNotify_Text_SetLayout` then received `0x0000ffff` in the generated code where the PE emits `push -1`. The callee at `0x52f9d0` reads only the low word of its third and fourth argument slots. Modeling both as `short` preserves the value the callee reads and lets VC6 emit the same signed push. The declaration applies to all translated builders.
