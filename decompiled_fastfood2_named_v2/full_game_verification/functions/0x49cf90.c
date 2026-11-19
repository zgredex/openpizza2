// rea decompile_all
// name: CompanyRating_InitCompanyList
// address: 0x49cf90
// body: available
// range: 0x49cf90-0x49d141 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CompanyRating_InitCompanyList(void *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined1 local_100 [256];
  
                    /* Populates the company rating rows and selected score. */
  iVar1 = Game_GetPlayerBySlot(DAT_0057c670,DAT_0057cab4);
  _DAT_0057ca98 = *(int *)(iVar1 + 0x1d4);
  UI_QueueControlCommand(*(void **)((int)DAT_0057c670 + 0x25c),-0x18670,0x23,_DAT_0057ca98);
  UI_Group_ClearAll((int)param_1);
  UI_Group_Create(param_1,0,6,0x1f41);
  Window_GadgetNotify_Button_SetState(param_1,0x1f41,1);
  iVar1 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  String_Format(local_100,DAT_00582e3c,(&DAT_005834d4)[*(int *)(iVar1 + 0x1148)]);
  Window_GadgetNotify_Text_SetText(param_1,0x45d,local_100);
  iVar1 = 0;
  piVar3 = &DAT_0057ca9c;
  do {
    iVar2 = Game_GetPlayerBySlot(DAT_0057c670,iVar1);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x50) == 0)) {
      *piVar3 = iVar2;
      piVar3 = piVar3 + 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  iVar2 = 0;
  iVar1 = 0x45f;
  do {
    if (*(int *)((int)&DAT_0057ca9c + iVar2) == 0) {
      UI_RemoveObjectByKey(param_1,iVar1);
      UI_RemoveObjectByKey(param_1,*(int *)((int)&DAT_00568aac + iVar2));
      iVar4 = 0;
      do {
        UI_RemoveObjectByKey(param_1,*(int *)((int)&DAT_00568a94 + iVar2) + iVar4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0x12);
    }
    else {
      UI_ShowChildByID(param_1,iVar1);
      Window_GadgetNotify_Text_SetTextColor
                (param_1,iVar1,*(undefined4 *)(*(int *)((int)&DAT_0057ca9c + iVar2) + 0x1dc));
      Window_GadgetNotify_Text_SetText(param_1,iVar1,*(int *)((int)&DAT_0057ca9c + iVar2) + 8);
      UI_ShowChildByID(param_1,*(int *)((int)&DAT_00568aac + iVar2));
      iVar4 = 0;
      do {
        UI_RemoveObjectByKey(param_1,*(int *)((int)&DAT_00568a94 + iVar2) + iVar4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0x12);
    }
    iVar2 = iVar2 + 4;
    iVar4 = iVar1 + -0x45e;
    iVar1 = iVar1 + 1;
  } while (iVar4 < 6);
  CompanyRating_UpdateScoreText(param_1);
  return;
}

