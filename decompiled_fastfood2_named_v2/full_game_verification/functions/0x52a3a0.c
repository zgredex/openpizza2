// rea decompile_all
// name: UI_SetClampedValue
// address: 0x52a3a0
// body: available
// range: 0x52a3a0-0x52a437 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall UI_SetClampedValue(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 local_104 [260];
  
  if (*(int *)((int)this + 0x388) != 0) {
    iVar1 = *(int *)((int)this + 0x9c);
    iVar2 = *(int *)((int)this + 0xa0);
    if (iVar1 < iVar2) {
      if (param_1 < iVar1) {
        param_1 = iVar1;
      }
      if (iVar2 < param_1) {
        param_1 = iVar2;
      }
    }
    else {
      if (iVar1 < param_1) {
        param_1 = iVar1;
      }
      if (param_1 < iVar2) {
        param_1 = iVar2;
      }
    }
  }
  *(int *)((int)this + param_2 * 4 + 0x8c) = param_1;
  if (*(int *)((int)this + 0xb8) != 0) {
    String_Format(local_104,*(byte **)((int)this + 0xbc),param_1);
    (**(code **)(**(int **)((int)this + 0xb8) + 0xc))(0xe,0,local_104);
  }
  return;
}

