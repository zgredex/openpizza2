// rea decompile_all
// name: FUN_005287a0
// address: 0x5287a0
// body: available
// range: 0x5287a0-0x528814 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_005287a0(void *this,void *param_1)

{
  if ((*(int *)((int)this + 0x44) != 0) && (*(void **)((int)this + 0x54) != (void *)0x0)) {
    FUN_0053d570(*(void **)((int)this + 0x54),(int)param_1,*(uint **)((int)this + 0x38),
                 *(int *)((int)this + 0x3c));
    if (*(int *)((int)this + 0x48) != -1) {
      FUN_00535570(*(void **)((int)this + 0x4c),
                   *(int *)((int)this + 0x30) + *(int *)((int)this + 0x38),
                   *(int *)((int)*(void **)((int)this + 0x4c) + 0x9b0) * *(int *)((int)this + 0x48)
                   + *(int *)((int)this + 0x34) + *(int *)((int)this + 0x3c),0);
      FUN_00535500(*(void **)((int)this + 0x4c),*(undefined4 *)((int)this + 0x60));
      Font_DrawTextLine(*(void **)((int)this + 0x4c),param_1,
                        *(int *)((int)this + *(int *)((int)this + 0x48) * 4 + 0x6c));
    }
  }
  return;
}

