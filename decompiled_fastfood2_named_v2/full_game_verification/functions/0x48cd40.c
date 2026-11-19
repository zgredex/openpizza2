// rea decompile_all
// name: Game_IsBuildingAssignedToOtherCompany
// address: 0x48cd40
// body: available
// range: 0x48cd40-0x48cdc5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Game_IsBuildingAssignedToOtherCompany(void *this,int param_1,int param_2)

{
  void *this_00;
  void *pvVar1;
  int iVar2;
  
  pvVar1 = (void *)Game_GetPlayerBySlot(this,param_2);
  this_00 = *(void **)((int)this + *(int *)((int)this + 0x2ec) * 4 + 0x200);
  if ((pvVar1 != this_00) && (pvVar1 != (void *)0x0)) {
    if (param_1 < 0x14) {
      iVar2 = IDMap_Lookup((void *)((int)pvVar1 + 0x148),param_1,(int *)0x0);
      pvVar1 = (void *)0x0;
      if (iVar2 == 0) goto LAB_0048cdc0;
      iVar2 = *(int *)(iVar2 + 0x16f0);
    }
    else if (param_1 < 0x28) {
      iVar2 = IDMap_Lookup((void *)((int)pvVar1 + 0x180),param_1 + -0x14,(int *)0x0);
      pvVar1 = (void *)0x0;
      if (iVar2 == 0) goto LAB_0048cdc0;
      iVar2 = *(int *)(iVar2 + 0x34);
    }
    else {
      iVar2 = *(int *)((int)pvVar1 + 0x1d8);
      pvVar1 = (void *)0x0;
      if (iVar2 == 0) goto LAB_0048cdc0;
    }
    pvVar1 = (void *)Game_IsValueAssignedToCompany(this_00,iVar2);
    if ((char)pvVar1 != '\0') {
      return CONCAT31((int3)((uint)pvVar1 >> 8),1);
    }
  }
LAB_0048cdc0:
  return (uint)pvVar1 & 0xffffff00;
}

