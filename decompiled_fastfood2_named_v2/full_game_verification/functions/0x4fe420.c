// rea decompile_all
// name: Branch_ApplyProductSales
// address: 0x4fe420
// body: available
// range: 0x4fe420-0x4fe560 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Branch_ApplyProductSales(void *this,void *param_1)

{
  void *this_00;
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 local_1a0 [12];
  char local_16e [366];
  
                    /* Applies branch product sales or its fallback charges. */
  this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((int)param_1 + 0x30));
  if (*(int *)((int)this + *(int *)((int)this_00 + 0x4c) * 0x168 + 0x114) == 0) {
    Array_Copy68(param_1,local_1a0);
    if ((*(byte *)((int)param_1 + 0x1894) & 2) != 0) {
      Branch_AssignEntranceAndCustomerSlots(this,param_1,(int)local_1a0);
      Game_CanAffordWithCurrency(this_00,9,750.0,'\0',0xffffffff);
    }
    if ((*(byte *)((int)param_1 + 0x1894) & 0x20) != 0) {
      Branch_AutoTunePrice(param_1);
      Game_CanAffordWithCurrency(this_00,9,350.0,'\0',0xffffffff);
    }
    Array_ClearStride34((int)param_1);
    return;
  }
  Array_Copy68(param_1,local_1a0);
  iVar2 = 0;
  iVar1 = 0;
  pcVar4 = (char *)((int)param_1 + 0x1a08);
  do {
    if (pcVar4[iVar1] != '\0') {
      iVar2 = iVar2 + 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x18);
  if (2 < iVar2) {
    iVar1 = 0;
    pcVar3 = local_16e;
    do {
      if ((*pcVar3 == '\0') && (*pcVar4 != '\0')) {
        if (iVar1 < 8) {
          return;
        }
        break;
      }
      iVar1 = iVar1 + 1;
      pcVar3 = pcVar3 + 0x34;
      pcVar4 = pcVar4 + 3;
    } while (iVar1 < 8);
    Branch_AssignEntranceAndCustomerSlots(this,param_1,(int)local_1a0);
    Game_RefreshObjectCategoryBins(param_1);
    Game_UpdateMusicTheme((int)param_1,(int)local_1a0);
    Game_TryBuyCompletedHouse(this,param_1,(int)local_1a0);
    Array_ClearStride34((int)param_1);
    iVar1 = Company_RemoveAttachedBuildingObjects(param_1);
    if (iVar1 != 0) {
      Branch_AutoTunePrice(param_1);
    }
  }
  return;
}

