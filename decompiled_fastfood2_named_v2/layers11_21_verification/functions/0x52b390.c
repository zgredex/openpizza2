// rea decompile_all
// name: FUN_0052b390
// address: 0x52b390
// body: available
// range: 0x52b390-0x52b4a9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0052b390(void *this,int param_1,int param_2,int param_3)

{
  switch(*(undefined4 *)((int)this + 0xa4)) {
  case 0:
    if (*(void **)((int)this + 0x94) != (void *)0x0) {
      if (*(undefined2 **)((int)this + 0x9c) != (undefined2 *)0xffffffff) {
        FUN_0053d840(*(void **)((int)this + 0x94),*(undefined2 **)((int)this + 0x9c));
      }
      FUN_0053d570(*(void **)((int)this + 0x94),param_1,
                   (uint *)(*(int *)((int)this + 0x38) + param_2),
                   *(int *)((int)this + 0x3c) + param_3);
      return;
    }
    break;
  case 1:
    if (*(void **)((int)this + 0x54) != (void *)0x0) {
      FUN_005343d0(*(void **)((int)this + 0x54),param_1,*(int *)((int)this + 0x98));
      return;
    }
    break;
  case 2:
    if (*(void **)((int)this + 0x54) != (void *)0x0) {
      FUN_005374e0(*(void **)((int)this + 0x54),param_1,*(int *)((int)this + 0x38) + param_2,
                   *(int *)((int)this + 0x3c) + param_3,-9999,-9999,0,0);
      return;
    }
    break;
  case 3:
    if (*(void **)((int)this + 0x54) != (void *)0x0) {
      FUN_005374e0(*(void **)((int)this + 0x54),param_1,*(int *)((int)this + 0x38) + param_2,
                   *(int *)((int)this + 0x3c) + param_3,-9999,-9999,0,0);
    }
  }
  return;
}

