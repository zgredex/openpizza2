// rea decompile_all
// name: SubMenu_UpdateMenuPlanPage
// address: 0x4a6c20
// body: available
// range: 0x4a6c20-0x4a6f45 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl SubMenu_UpdateMenuPlanPage(void *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  undefined4 uVar8;
  int *local_130;
  int local_12c;
  int local_128;
  int local_124;
  int local_120 [8];
  char local_100 [256];
  
                    /* Updates the menu-plan page's groups, sliders, and recipe panels. */
  iVar1 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  iVar5 = 0;
  iVar6 = 0;
  piVar4 = local_120;
  do {
    iVar2 = Game_CountObjectsByState(DAT_0057c670,iVar6);
    iVar5 = iVar5 + iVar2;
    *piVar4 = iVar2;
    iVar6 = iVar6 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar6 < 8);
  iVar6 = 0;
  piVar4 = local_120;
  do {
    String_Format(local_100,&DAT_005686f4,(*piVar4 * 100) / iVar5);
    Window_GadgetNotify_Text_SetText(param_1,iVar6 + 0x452,local_100);
    iVar6 = iVar6 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar6 < 8);
  uVar8 = 0;
  lVar7 = __ftol();
  Window_GadgetNotify_Slider_SetValue(param_1,0x432,(int)lVar7,uVar8);
  uVar8 = 0;
  lVar7 = __ftol();
  Window_GadgetNotify_Slider_SetValue(param_1,0x431,(int)lVar7,uVar8);
  uVar8 = 0;
  lVar7 = __ftol();
  Window_GadgetNotify_Slider_SetValue(param_1,0x42f,(int)lVar7,uVar8);
  uVar8 = 0;
  lVar7 = __ftol();
  Window_GadgetNotify_Slider_SetValue(param_1,0x435,(int)lVar7,uVar8);
  uVar8 = 0;
  lVar7 = __ftol();
  Window_GadgetNotify_Slider_SetValue(param_1,0x434,(int)lVar7,uVar8);
  uVar8 = 0;
  lVar7 = __ftol();
  Window_GadgetNotify_Slider_SetValue(param_1,0x433,(int)lVar7,uVar8);
  iVar5 = 0x437;
  do {
    UI_RemoveObjectByKey(param_1,iVar5);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x449);
  piVar4 = (int *)(iVar1 + 200);
  iVar5 = 0;
  do {
    if (*piVar4 == 0) {
      iVar6 = *(int *)((int)&DAT_0056918c + iVar5);
    }
    else if (*piVar4 == 1) {
      iVar6 = *(int *)(iVar5 + 0x5691a4);
    }
    else {
      iVar6 = *(int *)(iVar5 + 0x5691bc);
    }
    UI_ShowChildByID(param_1,iVar6);
    iVar5 = iVar5 + 4;
    piVar4 = piVar4 + 1;
  } while (iVar5 < 0x18);
  local_12c = 200000;
  local_130 = &DAT_005691d4;
  piVar4 = (int *)(iVar1 + 0xfe4);
  while( true ) {
    UI_GetWindowObject(param_1,*local_130);
    Array_GetPairByKey(param_1,*local_130,&local_124,&local_128);
    iVar5 = 0;
    iVar1 = local_12c + 6;
    do {
      String_Format(local_100,(byte *)s_zutaten_zmi__02d_a_spr_005691f4,*piVar4 + 1);
      UI_AddSprite(param_1,local_12c,local_124 + iVar5,local_128,local_100);
      UI_SetObjectTextByKey(param_1,local_12c,(char *)(&DAT_00583544)[*piVar4]);
      iVar5 = iVar5 + 0x15;
      local_12c = local_12c + 1;
      piVar4 = piVar4 + 1;
    } while (iVar5 < 0x7e);
    local_130 = local_130 + 1;
    if (0x5691f3 < (int)local_130) break;
    local_12c = iVar1;
  }
  puVar3 = City_CollectVacantLots((int)DAT_0057c670);
  Gadget_SetTextf(param_1,0x1f4b,&DAT_005686f4,puVar3[5]);
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  UI_SetObjectTextByKey(param_1,0x1f4d,DAT_005822c8);
  UI_SetObjectTextByKey(param_1,0x1f50,DAT_0058235c);
  UI_SetObjectTextByKey(param_1,0x1f4f,DAT_00582344);
  UI_SetObjectTextByKey(param_1,0x1f4e,DAT_00582334);
  UI_SetObjectTextByKey(param_1,0x1f52,DAT_00582318);
  UI_SetObjectTextByKey(param_1,0x1f4c,DAT_00582488);
  UI_SetObjectTextByKey(param_1,0x1f53,DAT_00582480);
  UI_SetObjectTextByKey(param_1,0x1f51,DAT_00582478);
  return;
}

