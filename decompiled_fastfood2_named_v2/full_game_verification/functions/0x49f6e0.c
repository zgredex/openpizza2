// rea decompile_all
// name: Screen_RecipeMenu_Construct
// address: 0x49f6e0
// body: available
// range: 0x49f6e0-0x49fa1a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Screen_RecipeMenu_Construct(void *param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
                    /* Builds the recipe-book screen and loads the current recipe. */
  Array_SetField14ByKey(param_1,0x411,0);
  Array_SetField14ByKey(param_1,0x412,0);
  Array_SetField14ByKey(param_1,0x413,0);
  Array_SetField14ByKey(param_1,0x414,0);
  Array_SetField14ByKey(param_1,0x415,0);
  UI_SetPosition(param_1,&LAB_0049f200,0);
  UI_AddUniquePair(param_1,0x3f5,0x131);
  UI_AddUniquePair(param_1,0x3f6,0x133);
  iVar2 = Game_CountRecordsForSelectedPlayer(DAT_0057c670,*(int *)((int)DAT_0057c670 + 0x2f4),-1);
  if (iVar2 == 0) {
    UI_Group_Create(param_1,0,4,0x3fc);
    Window_GadgetNotify_Button_SetState(param_1,0x3fb,0);
    UI_SetChildVisibleByID(param_1,0x3fb,0);
  }
  else {
    UI_Group_Create(param_1,0,5,0x3fc);
    if ((*(int *)((int)DAT_0057c670 + 0x9c) == 0) &&
       (iVar2 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200),
       *(int *)(iVar2 + 0x15c) != 0)) {
      uVar3 = IDMap_Lookup((void *)(iVar2 + 0x148),0,(int *)0x0);
      *(undefined4 *)((int)DAT_0057c670 + 0x9c) = uVar3;
      Sound_SelectCurrentTrack(DAT_0057ba0c);
    }
  }
  Game_UpdateDateLabels(DAT_0057c670,param_1);
  Personnel_SetEmployeePhotoByKey
            (param_1,0x1f46,
             *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  DAT_0057cd98 = *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  iVar2 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x290) * 4 + 0x298);
  if (iVar2 == 10) {
    puVar4 = *(undefined4 **)((int)DAT_0057c670 + 0x98);
  }
  else if ((iVar2 < 6) || (8 < iVar2)) {
    puVar4 = *(undefined4 **)((int)DAT_0057c670 + 0x98);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)
               IDMap_Lookup((void *)((int)DAT_0057cd98 + 0x110),DAT_0057cd9c,(int *)0x0);
    }
    else {
      DAT_0057cd9c = Game_FindCompanyIndex(DAT_0057cd98,(int)puVar4);
    }
  }
  else {
    puVar4 = *(undefined4 **)((int)DAT_0057cd98 + 0x1d4);
  }
  RecipeMenu_SetCurrentRecipe(param_1,puVar4);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = DAT_00581ad0;
  }
  else {
    *(undefined4 **)((int)DAT_0057c670 + 0x98) = puVar4;
    puVar4 = puVar4 + 1;
  }
  Window_GadgetNotify_Text_SetText(param_1,0x40f,puVar4);
  uVar3 = Game_HasIdleOtherPlayer(DAT_0057c670);
  if (((char)uVar3 == '\0') ||
     (*(int *)(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0x50)
      == -1)) {
    UI_RemoveObjectByKey(param_1,0x434);
    UI_RemoveObjectByKey(param_1,0x435);
    UI_RemoveObjectByKey(param_1,0x437);
  }
  else {
    iVar2 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    UI_ShowChildByID(param_1,0x434);
    UI_ShowChildByID(param_1,0x435);
    UI_ShowChildByID(param_1,0x437);
    Gadget_SetTextf(param_1,0x435,(byte *)s__d__s_00568324,*(undefined4 *)(iVar2 + 0x114c));
  }
  MapBadgeAnim_SetWindow(*(void **)((int)DAT_0057c670 + 0x2d9c),param_1,0x1f42);
  uVar1 = *(undefined8 *)
           (*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0x108);
  Sound_SetListenerPosition
            (*(void **)((int)DAT_0057c670 + 0x2d9c),(int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0);
  UI_SetChildLabelText(param_1,0x43b,1,(char *)0x0);
  if (*(int *)(*(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xac) + 0xd0) == 0) {
    Mission_ShowObjectiveDialog(DAT_0057c670,'\x01');
  }
  iVar2 = 0x1f47;
  do {
    UI_RemoveObjectByKey(param_1,iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1fa6);
  return;
}

