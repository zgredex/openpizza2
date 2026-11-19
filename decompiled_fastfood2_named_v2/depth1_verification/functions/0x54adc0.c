// rea decompile_all
// name: FUN_0054adc0
// address: 0x54adc0
// body: available
// range: 0x54adc0-0x54ae5d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_0054adc0(void *this,void *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_2;
  if (*(int *)((int)this + 0x34) != 0) {
    return 0;
  }
  iVar3 = *(int *)((int)this + 0x20);
  *(void **)((int)this + 0x34) = param_1;
  *(int *)((int)this + 0x2c) = param_2;
  param_2 = *(int *)((int)this + 0x18) + -10;
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (8 < param_2) goto LAB_0054ae50;
  do {
    iVar1 = FUN_004017f0((void *)((int)this + 4),param_2,(int *)0x0);
    if ((iVar1 != 0) && (iVar2 = Array_GetRecordByKeyPtr(param_1,iVar4), iVar2 == 0)) {
      FUN_0054aec0(this,iVar1,iVar4,iVar3);
      *(int *)(iVar1 + 0xc) = iVar3;
      *(undefined4 *)(iVar1 + 0x20) = 0;
      *(void **)(iVar1 + 0x18) = this;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + *(int *)((int)this + 0x28);
    }
    param_2 = param_2 + 1;
  } while (param_2 < 9);
LAB_0054ae50:
  *(undefined4 *)((int)this + 0x30) = 1;
  return 1;
}

