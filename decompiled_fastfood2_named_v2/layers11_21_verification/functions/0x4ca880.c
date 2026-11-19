// rea decompile_all
// name: EndResults_RefreshScreen
// address: 0x4ca880
// body: available
// range: 0x4ca880-0x4cac62 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl EndResults_RefreshScreen(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_10c;
  int local_108;
  int *local_104;
  char local_100 [256];
  
                    /* Rebuilds the end-of-game results screen and selected tab. */
  FUN_0048d530(DAT_0057c670,&DAT_0057de18);
  iVar5 = 0x4be;
  local_104 = &DAT_0057de18;
  local_108 = 0x4fa;
  iVar6 = 0x5a8;
  do {
    iVar2 = FUN_00488be0(DAT_0057c670,iVar6 + -0x5a8);
    if (iVar2 == 0) {
      FUN_00531740(param_1,iVar6);
      FUN_00531740(param_1,iVar6 + -0xb);
      local_10c = 6;
      iVar2 = local_108 + -0x24;
      do {
        FUN_00531740(param_1,iVar2);
        iVar2 = iVar2 + 1;
        local_10c = local_10c + -1;
      } while (local_10c != 0);
      local_10c = 6;
      iVar2 = local_108;
      do {
        FUN_00531740(param_1,iVar2);
        iVar2 = iVar2 + 1;
        local_10c = local_10c + -1;
      } while (local_10c != 0);
      local_10c = 6;
      iVar2 = local_108 + 0x24;
      do {
        FUN_00531740(param_1,iVar2);
        iVar2 = iVar2 + 1;
        local_10c = local_10c + -1;
      } while (local_10c != 0);
      local_10c = 6;
      iVar2 = local_108 + 0x48;
      do {
        FUN_00531740(param_1,iVar2);
        iVar2 = iVar2 + 1;
        local_10c = local_10c + -1;
      } while (local_10c != 0);
      *local_104 = 0;
      FUN_00531740(param_1,iVar5 + 1);
      Window_GadgetNotify_Text_SetText(param_1,iVar5,DAT_00582e4c);
      Window_GadgetNotify_Text_SetText(param_1,iVar5 + 2,DAT_00582e4c);
      FUN_00531740(param_1,iVar6 + -0x1f);
    }
    else {
      Window_GadgetNotify_Text_SetText(param_1,iVar5,iVar2 + 8);
      Gadget_SetTextf(param_1,iVar5 + 2,&DAT_005686f4,*(undefined4 *)(*local_104 + 0x11c));
      iVar1 = *(int *)(iVar2 + 0x1e0);
      iVar7 = iVar6;
      iVar3 = FUN_004e2250(iVar2);
      UI_SetPlayerLogoSprite(param_1,iVar1,iVar3,iVar7);
      FUN_0054dd83(local_100,(byte *)s_LOGOS__0_d_spr_00568eb8,*(int *)(iVar2 + 0x1e0) + 1);
      UI_SetButtonSpriteByName(param_1,iVar6 + -0x1f,local_100);
      Window_GadgetNotify_Text_SetTextColor(param_1,iVar5,*(undefined4 *)(iVar2 + 0x1dc));
      Window_GadgetNotify_Text_SetTextColor(param_1,iVar5 + 1,*(undefined4 *)(iVar2 + 0x1dc));
      Window_GadgetNotify_Text_SetTextColor(param_1,iVar5 + 2,*(undefined4 *)(iVar2 + 0x1dc));
    }
    local_108 = local_108 + 6;
    local_104 = local_104 + 1;
    iVar5 = iVar5 + 3;
    iVar2 = iVar6 + -0x5a7;
    iVar6 = iVar6 + 1;
  } while (iVar2 < 6);
  FUN_004caca0(param_1);
  Window_GadgetNotify_Text_SetText(param_1,0x429,DAT_00582e4c);
  Gadget_SetButtonState(param_1,0x5a6,1);
  FUN_00531470(param_1,0x5a6,0);
  switch(DAT_0057c5c0) {
  case 1:
    Gadget_SetText(param_1,0x5a3,DAT_00581838);
    uVar4 = DAT_00581010;
    break;
  case 2:
    Gadget_SetText(param_1,0x5a3,DAT_00581bfc);
    uVar4 = DAT_00582848;
    break;
  default:
    goto switchD_004caad2_caseD_3;
  case 4:
    uVar4 = DAT_00582ea4;
    goto LAB_004cab38;
  case 5:
    Gadget_SetText(param_1,0x5a3,DAT_00582ea4);
    uVar4 = DAT_00581010;
    goto LAB_004cab66;
  case 6:
    uVar4 = DAT_00581838;
LAB_004cab38:
    Gadget_SetText(param_1,0x5a3,uVar4);
    uVar4 = DAT_00581010;
    break;
  case 7:
    Gadget_SetText(param_1,0x5a3,DAT_00581990);
    uVar4 = DAT_00581074;
LAB_004cab66:
  }
  Gadget_SetText(param_1,0x5a4,uVar4);
switchD_004caad2_caseD_3:
  if (DAT_0056b270 == -1) {
    Gadget_SetButtonState(param_1,0x4d0,1);
    EndResultPoints_FillOverview(param_1);
    return;
  }
  Window_GadgetNotify_Button_SetState(param_1,(&DAT_0056b274)[DAT_0056b270],1);
  switch(DAT_0056b270) {
  case 0:
    EndResultPoints_FillBuildingTable(param_1);
    return;
  case 1:
    EndResultPoints_FillMissionTable(param_1);
    return;
  case 2:
    EndResultPoints_FillPersonnelTable(param_1);
    return;
  case 3:
    EndResults_FillBalancePage(param_1);
    return;
  case 4:
    EndResults_FillAdvertisingPage(param_1);
    return;
  case 5:
    EndResults_FillRecipePage(param_1);
    return;
  case 6:
    EndResults_FillSyndicatePage(param_1);
    return;
  case 7:
    EndResults_FillRatingPage(param_1);
  }
  return;
}

