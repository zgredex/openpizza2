// rea decompile_all
// name: BranchInfoPanel_Update
// address: 0x4c47d0
// body: available
// range: 0x4c47d0-0x4c4acc inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl BranchInfoPanel_Update(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_20 [32];
  
                    /* Fills the branch/plan info card and rating rows. */
  StringTable_SortIndexArray((int *)&DAT_0057da20,(int *)&DAT_0057db88);
  iVar3 = *(int *)((int)DAT_0057c670 + 0x218);
  this = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(iVar3 + 8));
  DAT_0057dcf0 = (void *)Game_FindPlanByTarget(this,iVar3);
  iVar1 = IDMap_Lookup((void *)((int)this + 0x148),*(int *)((int)DAT_0057dcf0 + 0xc),(int *)0x0);
  Window_GadgetNotify_Text_SetText(param_1,0x1f42,iVar1 + 4);
  Window_GadgetNotify_Text_SetText(param_1,0x41b,(int)this + 8);
  iVar1 = 0x41d;
  Window_GadgetNotify_Text_SetText(param_1,0x41d,DAT_00582e4c);
  Window_GadgetNotify_Text_SetText(param_1,0x41e,DAT_00582e4c);
  Window_GadgetNotify_Text_SetText(param_1,0x41f,DAT_00582e4c);
  Window_GadgetNotify_Text_SetText(param_1,0x420,DAT_00582e4c);
  if ((*(byte *)((int)DAT_0057dcf0 + 0x14) & 8) != 0) {
    iVar1 = 0x41e;
    Window_GadgetNotify_Text_SetText(param_1,0x41d,DAT_00582ad8);
  }
  iVar2 = iVar1;
  if ((*(byte *)((int)DAT_0057dcf0 + 0x14) & 4) != 0) {
    iVar2 = iVar1 + 1;
    Window_GadgetNotify_Text_SetText(param_1,iVar1,DAT_00581a50);
  }
  iVar1 = iVar2;
  if ((*(byte *)((int)DAT_0057dcf0 + 0x14) & 2) != 0) {
    iVar1 = iVar2 + 1;
    Window_GadgetNotify_Text_SetText(param_1,iVar2,DAT_00580e7c);
  }
  iVar2 = iVar1;
  if ((*(byte *)((int)DAT_0057dcf0 + 0x14) & 1) != 0) {
    iVar2 = iVar1 + 1;
    Window_GadgetNotify_Text_SetText(param_1,iVar1,DAT_00581f80);
  }
  if (*(int *)((int)DAT_0057dcf0 + 0x14) == 0) {
    Window_GadgetNotify_Text_SetText(param_1,iVar2,DAT_005826e4);
  }
  if (*(int *)((int)DAT_0057dcf0 + 0x18) == 0) {
    uVar4 = DAT_00580f68;
  }
  else {
    uVar4 = *(undefined4 *)(&DAT_00583540 + *(int *)((int)DAT_0057dcf0 + 0x18) * 4);
  }
  Window_GadgetNotify_Text_SetText(param_1,0x422,uVar4);
  if (*(int *)((int)DAT_0057dcf0 + 0x1c) == -1) {
    iVar1 = DAT_00582634;
  }
  else {
    iVar1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((int)DAT_0057dcf0 + 0x1c));
    iVar1 = iVar1 + 8;
  }
  Window_GadgetNotify_Text_SetText(param_1,0x424,iVar1);
  Window_GadgetNotify_Text_SetText
            (param_1,0x4b8,
             *(undefined4 *)
              (&DAT_00583504 + *(int *)(&DAT_0057db88 + *(int *)((int)DAT_0057dcf0 + 0x10) * 4) * 4)
            );
  Gadget_SetText(param_1,0x417,DAT_005824c4);
  iVar3 = *(int *)(iVar3 + 8);
  iVar1 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
  if (iVar3 == iVar1) {
    Window_GadgetNotify_Text_SetText(param_1,0x425,DAT_005829f4);
    String_Format(local_20,&DAT_005683a4,0xdac);
    Window_GadgetNotify_Text_SetText(param_1,0x426,local_20);
    Window_GadgetNotify_Text_SetText(param_1,0x425,DAT_005829e8);
    uVar4 = DAT_00582f00;
  }
  else {
    Window_GadgetNotify_Text_SetText(param_1,0x425,DAT_00581b28);
    String_Format(local_20,&DAT_005683a4,*(int *)((int)DAT_0057dcf0 + 0x20) * 10);
    Window_GadgetNotify_Text_SetText(param_1,0x426,local_20);
    Window_GadgetNotify_Text_SetText(param_1,0x425,DAT_00582f98);
    uVar4 = DAT_00582708;
  }
  Gadget_SetText(param_1,0x417,uVar4);
  iVar3 = 0;
  do {
    iVar1 = GamePlan_ComputeCategoryEffect(DAT_0057dcf0,*(int *)((int)this + 0x48),iVar3);
    iVar1 = Math_PiecewiseLinear(iVar1);
    Rating_UpdateBarByKey(param_1,0x4ae,iVar3,iVar1,DAT_00582858);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  return;
}

