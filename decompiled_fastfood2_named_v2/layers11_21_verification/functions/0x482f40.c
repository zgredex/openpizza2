// rea decompile_all
// name: FUN_00482f40
// address: 0x482f40
// body: available
// range: 0x482f40-0x4830db inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00482f40(void *this,char param_1)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  char *pcVar6;
  int local_104;
  char local_100 [256];
  
  iVar1 = *(int *)(*(int *)((int)this + 0x224) + 0xac);
  if (*(int *)(iVar1 + 0xd4) < 10) {
    if (param_1 != '\0') {
      if (*(undefined4 **)((int)this + 0x26c) != (undefined4 *)0x0) {
        Window_DestroyChild(DAT_0057c5e0,*(undefined4 **)((int)this + 0x26c));
      }
      pvVar2 = FUN_0046d290(&local_104);
      *(void **)((int)this + 0x26c) = pvVar2;
    }
    iVar1 = *(int *)(iVar1 + 0xd4);
    if (iVar1 == 0) {
      uVar5 = DAT_00582ab8;
    }
    else {
      uVar5 = DAT_005819b8;
    }
    Gadget_SetText(*(void **)((int)this + 0x26c),0x433,uVar5);
    Window_GadgetNotify_Text_SetText
              (*(void **)((int)this + 0x26c),0x43a,*(undefined4 *)(&DAT_0058335c + iVar1 * 4));
    Window_GadgetNotify_Text_SetText
              (*(void **)((int)this + 0x26c),0x439,*(undefined4 *)(&DAT_005834ac + iVar1 * 4));
    FUN_005491c0(DAT_0057ba0c,iVar1,'\0','\x01');
    piVar4 = &DAT_00567da4;
    piVar3 = (int *)(&DAT_00567dfc + iVar1 * 0xc);
    do {
      if (*piVar3 == 0) {
        FUN_00531740(*(void **)((int)this + 0x26c),*piVar4);
      }
      else {
        FUN_005316b0(*(void **)((int)this + 0x26c),*piVar4);
        FUN_0054dd83(local_100,(byte *)s__s_spr_005680ec,
                     *(undefined4 *)(&DAT_00567dd4 + *piVar3 * 4));
        UI_SetButtonSpriteByName(*(void **)((int)this + 0x26c),*piVar4,local_100);
      }
      piVar4 = piVar4 + 1;
      piVar3 = piVar3 + 1;
    } while ((int)piVar4 < 0x567db0);
    if (*(int *)(&DAT_00567db0 + iVar1 * 4) == 1) {
      pcVar6 = s_rb01_00_spr_005680e0;
    }
    else {
      pcVar6 = s_rb03_00_spr_005680d4;
    }
    UI_SetButtonSpriteByName(*(void **)((int)this + 0x26c),0x46a,pcVar6);
    if (param_1 != '\0') {
      Window_ShowWindowById(DAT_0057c5e0,local_104);
    }
  }
  else if (*(int *)((int)this + 0x26c) != 0) {
    Game_DestroyEventWindow((int)this);
    return;
  }
  return;
}

