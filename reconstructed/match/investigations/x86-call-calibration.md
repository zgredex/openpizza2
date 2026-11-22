# x86 call evidence and synthetic calibration

`tools/x86_call_abi.py` reads contiguous functions from the pinned PE and inventory. It follows in-range direct branches from each entry and groups the reachable static call sites by callee. Each top callee reports its most common local staging pattern. This includes push and stack-store counts, the nearest explicit writes to ECX and EDX, and an immediate stack adjustment after the call. Run with Capstone 5.0.7 from the headless host environment or an existing environment with that package.

```sh
python tools/x86_call_abi.py --address 0x433790 --json-out /tmp/pc2-call-summary.json
```

Repeat `--address` for up to eight functions. The report records PE and index hashes. It omits ordered call sites and argument values. Staging is a bounded local observation, so pushes can include register saves and registers can be set outside the window. Treat the observations as leads for ABI verification. Indirect call targets and paths reached only through indirect branches remain unobserved.

The pinned `0x433790` run decoded 7,258 instructions and found 1,153 direct static call sites. All 870 sites grouped under `UI_AddSprite` showed four local pushes and an explicit ECX write from another register. This establishes a caller-side pattern for the analyzed paths.

## Synthetic VC6 comparisons

The calibrator generates two independent invented page builders. The grid builder varies literals, const locals, a zero expression, and a loop. The badge builder checks the literal versus const-local comparison on a separate call shape. Every variant uses `/TP` with `/Od` or `/O2`. The tool's inputs are fixed synthetic source templates, and the twelve-case budget can be reduced with `--limit`.

```sh
python tools/calibrate_page_shapes.py --out /tmp/pc2-synthetic-pages --compile
python tools/calibrate_page_shapes.py --out /tmp/pc2-synthetic-pages --inspect
```

Use the [pinned VC6 setup](../VC6_TOOLCHAIN.md) for compilation. Omitting `--compile` just writes the synthetic sources and planned recipes. `--inspect` verifies the recorded source and object hashes and writes a separate `inspection.json` without compiling again. The comparison reports the first differing offset over the span ending at the last reachable instruction. It checks REL32 sites and names separately from raw COFF bytes. Compiler provenance and all generated artifacts stay in the scratch directory.

All twelve recipes compiled under the pinned VC6. At `/Od`, the grid and badge const-local variants each gained 10 bytes over their literal form and first differed at offset 3. At `/O2`, both pairs had identical reachable span bytes and REL32 sites and names. The grid zero-expression form also converged to the literal form at `/O2`. These are results for the two synthetic builders.
