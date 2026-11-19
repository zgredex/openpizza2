// rea decompile_all
// name: FUN_00535d70
// address: 0x535d70
// body: available
// range: 0x535d70-0x535e09 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int * __thiscall FUN_00535d70(void *this,int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_300 [192];
  
  *(undefined2 *)((int)this + 0x206) = 0xffff;
  *(undefined1 *)((int)this + 0x208) = 0;
  if (param_3 == 0) {
    puVar1 = operator_new(0x300);
    *(undefined4 **)this = puVar1;
    for (iVar2 = 0xc0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = *param_2;
      param_2 = param_2 + 1;
      puVar1 = puVar1 + 1;
    }
    Palette_Convert256(this,param_1);
    return this;
  }
  *(undefined4 **)this = local_300;
  puVar1 = local_300;
  for (iVar2 = 0xc0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_2;
    param_2 = param_2 + 1;
    puVar1 = puVar1 + 1;
  }
  Palette_Convert256(this,param_1);
  *(undefined4 *)this = 0;
  return this;
}

