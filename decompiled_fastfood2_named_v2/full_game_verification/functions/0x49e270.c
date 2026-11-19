// rea decompile_all
// name: CompanyRecipeIngredients_Update
// address: 0x49e270
// body: available
// range: 0x49e270-0x49e5a8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl CompanyRecipeIngredients_Update(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  float10 fVar6;
  undefined8 uVar7;
  undefined1 local_20 [32];
  
                    /* Fills the selected company recipe's ingredient list and cost. */
  iVar1 = 0;
  DAT_0057cc34 = *(void **)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) +
                           0x1d4);
  piVar4 = &DAT_0057cadc;
  piVar3 = (int *)((int)DAT_0057cc34 + 100);
  do {
    if (*piVar3 != 0) {
      *piVar4 = iVar1;
      piVar4 = piVar4 + 1;
    }
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar1 < 0x56);
  DAT_0057cad8 = 0;
  UI_Group_ClearAll((int)param_1);
  UI_Group_Create(param_1,0,2,0x1f41);
  UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x25c),-0x18670,0x23,(int)DAT_0057cc34);
  if (DAT_00568b48 == 0) {
    uVar7 = 0x100001f42;
  }
  else {
    uVar7 = 0x100001f41;
  }
  Window_GadgetNotify_Button_SetState(param_1,(int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
  puVar2 = (undefined4 *)Game_CountActiveStats((int)DAT_0057cc34);
  Save_LoadOrInit(puVar2);
  PlayerStats_Reset((int)DAT_0057cc34);
  iVar1 = Game_CountActiveStats((int)DAT_0057cc34);
  if (iVar1 == 0) {
    iVar1 = 0;
    do {
      UI_RemoveObjectByKey(param_1,*(int *)((int)&DAT_00568b4c + iVar1));
      UI_RemoveObjectByKey(param_1,*(int *)((int)&DAT_00568b78 + iVar1));
      iVar1 = iVar1 + 4;
    } while (iVar1 < 0x2c);
    UI_RemoveObjectByKey(param_1,0x428);
    UI_RemoveObjectByKey(param_1,0x440);
    UI_RemoveObjectByKey(param_1,0x4f0);
    UI_RemoveObjectByKey(param_1,0x507);
    UI_RemoveObjectByKey(param_1,0x452);
    UI_RemoveObjectByKey(param_1,0x1f41);
    UI_RemoveObjectByKey(param_1,0x1f42);
    UI_RemoveObjectByKey(param_1,0x1f43);
    UI_RemoveObjectByKey(param_1,0x1f44);
    iVar1 = 0;
    do {
      Rating_UpdateBarByKey(param_1,0x4e7,iVar1,0,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    return;
  }
  iVar1 = 0;
  do {
    UI_ShowChildByID(param_1,*(int *)((int)&DAT_00568b4c + iVar1));
    UI_ShowChildByID(param_1,*(int *)((int)&DAT_00568b78 + iVar1));
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x2c);
  UI_ShowChildByID(param_1,0x428);
  UI_ShowChildByID(param_1,0x440);
  UI_ShowChildByID(param_1,0x4f0);
  UI_ShowChildByID(param_1,0x1f41);
  UI_ShowChildByID(param_1,0x1f42);
  UI_ShowChildByID(param_1,0x1f43);
  UI_ShowChildByID(param_1,0x1f44);
  UI_ShowChildByID(param_1,0x452);
  iVar1 = Game_CountActiveStats((int)DAT_0057cc34);
  if (iVar1 < 0xc) {
    UI_RemoveObjectByKey(param_1,0x428);
    iVar1 = 0xb - iVar1;
    if (0 < iVar1) {
      iVar5 = 0;
      do {
        UI_RemoveObjectByKey(param_1,*(int *)((int)&DAT_00568b74 + iVar5));
        UI_RemoveObjectByKey(param_1,*(int *)((int)&DAT_00568ba0 + iVar5));
        iVar5 = iVar5 + -4;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  else {
    if (iVar1 < DAT_0057cad8 + 0xb) {
      DAT_0057cad8 = iVar1 + -0xb;
    }
    Window_GadgetNotify_Slider_SetRange(param_1,0x428,0,(iVar1 * 5 + -0x37) * 0x14,0);
    Window_GadgetNotify_Slider_SetValue(param_1,0x428,DAT_0057cad8 * 100,0);
    Window_GadgetNotify_Slider_SetChangeNotify(param_1,0x428,1);
  }
  RecipeInfo_FillNutritionRows(param_1,DAT_0057cad8);
  fVar6 = Game_GetPlayerWeightedStat((int)DAT_0057cc34);
  String_Format(local_20,(byte *)s__0_2f__005688b8,SUB84((double)fVar6,0));
  Window_GadgetNotify_Text_SetText(param_1,0x4f0,local_20);
  iVar1 = 0;
  do {
    iVar5 = Game_MapInputIndex(DAT_0057cc34,iVar1);
    Rating_UpdateBarByKey(param_1,0x4e7,iVar1,iVar5,DAT_0058155c);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  return;
}

