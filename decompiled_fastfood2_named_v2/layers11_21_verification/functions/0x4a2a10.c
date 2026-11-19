// rea decompile_all
// name: FUN_004a2a10
// address: 0x4a2a10
// body: available
// range: 0x4a2a10-0x4a3041 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a2a10(void *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  
  iVar4 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar1 = FUN_004e2280(iVar4);
  iVar3 = 0x43c;
  do {
    FUN_00531740(param_1,iVar3);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x448);
  uVar2 = (uint)(iVar1 < 6);
  FUN_005316f0(param_1,0x451,uVar2);
  FUN_005316f0(param_1,0x456,uVar2);
  FUN_005316f0(param_1,0x458,uVar2);
  FUN_005316f0(param_1,0x457,uVar2);
  FUN_005316f0(param_1,0x459,uVar2);
  FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(*(int *)(iVar4 + 0x1d8) + 0x28),(int *)0x0);
  lVar5 = FUN_004d6390(4,iVar1);
  DAT_0057d010 = (int)lVar5;
  switch(iVar1) {
  case 1:
    Window_GadgetNotify_Text_SetText(param_1,0x451,DAT_00580d94);
    Window_GadgetNotify_Text_SetText(param_1,0x456,DAT_00580db4);
    Window_GadgetNotify_Text_SetText(param_1,0x458,DAT_00580d5c);
    Window_GadgetNotify_Text_SetText(param_1,0x457,DAT_00580d78);
    Window_GadgetNotify_Text_SetText(param_1,0x459,DAT_00580d10);
    UI_SetButtonSpriteByName(param_1,0x43c,PTR_s_newwerbung_spr_00568df4);
    UI_SetButtonSpriteByName(param_1,0x43d,PTR_s_newkonkurent_spr_00568df8);
    UI_SetButtonSpriteByName(param_1,0x43e,PTR_s_newgangster_spr_00568dfc);
    UI_SetButtonSpriteByName(param_1,0x43f,PTR_s_newpolizei_spr_00568e00);
    UI_SetButtonSpriteByName(param_1,0x440,PTR_s_newaergern_spr_00568e04);
    iVar4 = 0x43c;
    do {
      FUN_005316b0(param_1,iVar4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x441);
    break;
  case 2:
    Window_GadgetNotify_Text_SetText(param_1,0x451,DAT_00580d0c);
    Window_GadgetNotify_Text_SetText(param_1,0x456,DAT_00580d34);
    Window_GadgetNotify_Text_SetText(param_1,0x458,DAT_00580cc8._4_4_);
    Window_GadgetNotify_Text_SetText(param_1,0x457,DAT_00580ce8);
    Window_GadgetNotify_Text_SetText(param_1,0x459,DAT_00580b90);
    UI_SetButtonSpriteByName(param_1,0x43c,PTR_s_newwerbung_spr_00568df4);
    UI_SetButtonSpriteByName(param_1,0x43d,PTR_s_newmanager_spr_00568e08);
    UI_SetButtonSpriteByName(param_1,0x43e,PTR_s_newrezeptauto_spr_00568e0c);
    UI_SetButtonSpriteByName(param_1,0x43f,PTR_s_newgangster_spr_00568dfc);
    UI_SetButtonSpriteByName(param_1,0x440,PTR_s_newaergern_spr_00568e04);
    iVar4 = 0x43c;
    do {
      FUN_005316b0(param_1,iVar4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x441);
    break;
  case 3:
    Window_GadgetNotify_Text_SetText(param_1,0x451,DAT_00580b9c);
    Window_GadgetNotify_Text_SetText(param_1,0x456,DAT_00580b78);
    Window_GadgetNotify_Text_SetText(param_1,0x458,DAT_00580b84);
    Window_GadgetNotify_Text_SetText(param_1,0x457,DAT_00580b68);
    FUN_00531740(param_1,0x459);
    UI_SetButtonSpriteByName(param_1,0x43c,PTR_s_newgangster_spr_00568dfc);
    UI_SetButtonSpriteByName(param_1,0x43d,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(param_1,0x43e,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(param_1,0x43f,PTR_s_newaergern_spr_00568e04);
    iVar4 = 0x43c;
    do {
      FUN_005316b0(param_1,iVar4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x440);
    break;
  case 4:
    Window_GadgetNotify_Text_SetText(param_1,0x451,DAT_00580b6c);
    Window_GadgetNotify_Text_SetText(param_1,0x456,DAT_00580b50);
    Window_GadgetNotify_Text_SetText(param_1,0x458,DAT_00580b58);
    Window_GadgetNotify_Text_SetText(param_1,0x457,DAT_00580b30);
    Window_GadgetNotify_Text_SetText(param_1,0x459,DAT_00580b4c);
    UI_SetButtonSpriteByName(param_1,0x43c,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(param_1,0x43d,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(param_1,0x43e,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(param_1,0x43f,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(param_1,0x440,PTR_s_newaergern_spr_00568e04);
    iVar4 = 0x43c;
    do {
      FUN_005316b0(param_1,iVar4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x441);
    break;
  case 5:
    Window_GadgetNotify_Text_SetText(param_1,0x451,DAT_00580b48);
    Window_GadgetNotify_Text_SetText(param_1,0x456,DAT_00580b04);
    Window_GadgetNotify_Text_SetText(param_1,0x458,DAT_00580b1c);
    Window_GadgetNotify_Text_SetText(param_1,0x457,DAT_00580af0);
    Window_GadgetNotify_Text_SetText(param_1,0x459,DAT_00580afc);
    UI_SetButtonSpriteByName(param_1,0x43c,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(param_1,0x43d,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(param_1,0x43e,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(param_1,0x43f,PTR_s_newangreifen_spr_00568e10);
    UI_SetButtonSpriteByName(param_1,0x440,PTR_s_newaergern_spr_00568e04);
    iVar4 = 0x43c;
    do {
      FUN_005316b0(param_1,iVar4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x441);
  }
  iVar4 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(iVar4 + 0x150) == 0) {
    if (*(int *)(iVar4 + 0x160) == 0) {
      if (*(int *)(iVar4 + 0x234) != 0) {
        DAT_0057d010 = (DAT_0057d010 * 0xf) / 10;
      }
    }
    else {
      DAT_0057d010 = DAT_0057d010 / 2;
    }
  }
  else {
    DAT_0057d010 = 0;
  }
  if (5 < iVar1) {
LAB_004a3017:
    FUN_00531740(param_1,0x44d);
    FUN_00531740(param_1,0x44f);
    FUN_00531740(param_1,0x450);
    FUN_004a28f0(param_1);
    return;
  }
  if ((char)DAT_0057bb3c == '\0') {
    FUN_005316b0(param_1,0x44d);
    FUN_005316b0(param_1,0x44f);
    FUN_005316b0(param_1,0x450);
    Gadget_SetTextf(param_1,0x44f,&DAT_005683a4,DAT_0057d010);
  }
  else {
    if (DAT_0057bb38 <= iVar1) goto LAB_004a3017;
    FUN_005316b0(param_1,0x44d);
    FUN_005316b0(param_1,0x44f);
    FUN_005316b0(param_1,0x450);
    Gadget_SetTextf(param_1,0x44f,&DAT_005683a4,DAT_0057d010);
  }
  Gadget_SetTextf(param_1,0x450,(byte *)s__d__s_00568324,4);
  FUN_004a28f0(param_1);
  return;
}

