// rea decompile_all
// name: AI_Action_AssignSuppliers
// address: 0x4fd190
// body: available
// range: 0x4fd190-0x4fd2f9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall AI_Action_AssignSuppliers(void *this,uint param_1)

{
  int iVar1;
  void *this_00;
  void *this_01;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  int local_8;
  
                    /* Assigns the best supplier to each AI branch. */
  iVar3 = 0;
  if (0 < *(int *)(*(int *)((int)this + param_1 * 0x168 + 0x70) + 0x15c)) {
    do {
      iVar1 = Game_GetPlayerSubrecord(this,param_1,iVar3,1);
      if (iVar1 != 0) {
        AI_EnsureBranchStorage(this,param_1,iVar1);
        switch(*(undefined4 *)(iVar1 + 0x24)) {
        case 0:
          break;
        case 1:
          break;
        case 2:
          break;
        case 3:
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(*(int *)((int)this + param_1 * 0x168 + 0x70) + 0x15c));
  }
  iVar3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((int)this + param_1 * 0x168 + 0x40));
  this_00 = (void *)IDMap_Lookup((void *)(iVar3 + 0x180),0,(int *)0x0);
  if (this_00 != (void *)0x0) {
    this_01 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)this_00 + 0x28),
                                   (int *)0x0);
    iVar1 = 0;
    iVar4 = 0;
    do {
      iVar2 = Array_GetStride60(this_01,iVar4);
      BuildingValue_Compute(iVar3,this_01,iVar2);
      lVar5 = __ftol();
      if ((iVar4 == 0) || (iVar1 < (int)lVar5)) {
        iVar1 = (int)lVar5;
        local_8 = iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
    Storage_SetSupplierBuilding(this_00,local_8);
  }
  return 1;
}

