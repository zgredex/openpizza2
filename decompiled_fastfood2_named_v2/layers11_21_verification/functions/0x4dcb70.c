// rea decompile_all
// name: FUN_004dcb70
// address: 0x4dcb70
// body: available
// range: 0x4dcb70-0x4dcc0e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004dcb70(void *this,int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = FUN_004034d0(0,3);
  } while (uVar1 == param_2);
  switch(uVar1) {
  case 0:
    uVar2 = *(undefined4 *)((int)this + param_1 * 4 + 0x200);
    *(undefined4 *)((int)this + param_1 * 4 + 0x200) = param_3;
    return uVar2;
  case 1:
    uVar2 = *(undefined4 *)((int)this + param_1 * 4 + 0x240);
    *(undefined4 *)((int)this + param_1 * 4 + 0x240) = param_3;
    return uVar2;
  case 2:
    uVar2 = *(undefined4 *)((int)this + param_1 * 4 + 0x220);
    *(undefined4 *)((int)this + param_1 * 4 + 0x220) = param_3;
    return uVar2;
  case 3:
    uVar2 = *(undefined4 *)((int)this + param_1 * 4 + 0x260);
    *(undefined4 *)((int)this + param_1 * 4 + 0x260) = param_3;
  }
  return uVar2;
}

