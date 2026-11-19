// rea decompile_all
// name: FUN_004aa340
// address: 0x4aa340
// body: available
// range: 0x4aa340-0x4aa537 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004aa340(void *param_1)

{
  void *this;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  
  FUN_005480c0(DAT_0057ba0c,0x19,0);
  this = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                              (int *)0x0);
  iVar3 = *(int *)(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                  0x48);
  iVar1 = *(int *)((int)this + iVar3 * 4 + 0xd40);
  Window_GadgetNotify_Slider_SetValue(param_1,0x1fa8,iVar1,0);
  iVar1 = (100 - iVar1) / 3;
  if (iVar1 == 0) {
    Window_GadgetNotify_Text_SetText(param_1,0x1fb0,&DAT_00569308);
  }
  else {
    Gadget_SetTextf(param_1,0x1fb0,(byte *)s___d____00569300,iVar1);
  }
  iVar1 = FUN_004da700(this,iVar3);
  Gadget_SetTextf(param_1,0x1fac,(byte *)s__d____00568834,iVar1);
  Gadget_SetTextf(param_1,0x1fd3,&DAT_005683a4,*(undefined4 *)((int)this + iVar3 * 4 + 0xdac));
  iVar1 = FUN_004d8090((int)this);
  iVar1 = FUN_00488be0(DAT_0057c670,iVar1);
  if (iVar1 == 0) {
    iVar5 = DAT_00582adc;
  }
  else {
    iVar5 = iVar1 + 8;
  }
  Window_GadgetNotify_Text_SetText(param_1,0x1fc9,iVar5);
  FUN_004a66d0(param_1,0x1fd4,iVar1);
  iVar3 = *(int *)((int)this + iVar3 * 4 + 0xcc8);
  iVar1 = 0x3c - iVar3;
  if (iVar1 / 2 < 0) {
    pcVar4 = s__d____00568834;
  }
  else {
    pcVar4 = s___d____005692f8;
  }
  Gadget_SetTextf(param_1,0x1fc5,(byte *)pcVar4,iVar1 / 2);
  Gadget_SetTextf(param_1,0x1fc7,&DAT_005686f4,((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3) + 0x4b);
  Window_GadgetNotify_Slider_SetValue(param_1,0x1fc3,iVar3,0);
  iVar3 = 0;
  puVar2 = (undefined4 *)((int)this + 0xd8c);
  do {
    Gadget_SetTextf(param_1,DAT_005692ec + iVar3,&DAT_005686f4,puVar2[-1]);
    Gadget_SetTextf(param_1,DAT_005692f0 + iVar3 * 2,&DAT_005686f4,*puVar2);
    iVar1 = puVar2[1];
    if (iVar1 < 1) {
      uVar6 = 0;
    }
    else {
      uVar6 = 0xff;
    }
    Window_GadgetNotify_Text_SetTextColor(param_1,DAT_005692f4 + iVar3,uVar6);
    Gadget_SetTextf(param_1,DAT_005692f4 + iVar3,&DAT_005686f4,iVar1);
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 3;
  } while (iVar3 < 3);
  return;
}

