// rea decompile_all
// name: LeaseBuilding_UpdatePage
// address: 0x4be490
// body: available
// range: 0x4be490-0x4be52b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl LeaseBuilding_UpdatePage(void *param_1)

{
  int iVar1;
  void *this;
  undefined4 uVar2;
  
                    /* Refreshes the building-lease page and offers. */
  iVar1 = *(int *)((int)DAT_0057c670 + 0x218);
  this = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(iVar1 + 8));
  Window_GadgetNotify_Text_SetText(param_1,0x501,(int)this + 8);
  Personnel_SetEmployeePhotoByKey(param_1,0x1f4d,(int)this);
  DAT_0057d700 = Game_FindRecordByField34(this,iVar1);
  uVar2 = 100000;
  iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(iVar1 + 0x158) == 0) {
    if (*(int *)(iVar1 + 0x23c) != 0) {
      uVar2 = 150000;
    }
  }
  else {
    uVar2 = 0;
  }
  Gadget_SetTextf(param_1,0x1f5e,&DAT_005683a4,uVar2);
  StockPage_FillStorageDetails(param_1);
  return;
}

