// rea decompile_all
// name: FUN_00509cf0
// address: 0x509cf0
// body: available
// range: 0x509cf0-0x509e15 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool __thiscall FUN_00509cf0(void *this,void *param_1)

{
  undefined1 uVar1;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)((int)this + 200) == 0) {
    return false;
  }
  uVar1 = FUN_00505e00((int)this);
  if (CONCAT31(extraout_var,uVar1) == 0) {
    return (bool)uVar1;
  }
  if (*(short *)(*(int *)((int)this + 200) + 0x28) == -1) {
    return false;
  }
  iVar2 = FUN_00509bf0((int)this);
  if (0 < *(int *)((int)param_1 + 0x14)) {
    do {
      iVar3 = FUN_004017f0(param_1,iVar4,(int *)0x0);
      iVar3 = FUN_004f0cc0(*(void **)((int)this + 0xc4),1,
                           (int)*(short *)(*(int *)(iVar3 + 8) + 0x24));
      if (iVar3 == iVar2) {
        return true;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)((int)param_1 + 0x14));
  }
  FUN_004f4ed0(*(void **)((int)this + 0xc4));
  Map_DrawObjectList(*(void **)((int)this + 0xc4),1,param_1);
  iVar4 = FUN_004f14a0();
  Map_DrawObjectList(*(void **)((int)this + 0xc4),0,param_1);
  Object_ClearRecordFirstBytes(*(void **)((int)this + 0xc4),(int *)0x1);
  return iVar4 == 0;
}

