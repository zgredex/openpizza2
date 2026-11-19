// rea decompile_all
// name: FUN_004a6990
// address: 0x4a6990
// body: available
// range: 0x4a6990-0x4a6bc3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a6990(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 unaff_EDI;
  int local_5c [3];
  undefined1 local_50 [32];
  int local_30 [4];
  undefined4 local_20;
  undefined4 local_1c;
  int local_18 [4];
  undefined4 local_8;
  undefined4 local_4;
  
  iVar5 = *(int *)(DAT_0057c670 + 0x224 + *(int *)(DAT_0057c670 + 0x2f0) * 4);
  iVar1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar3 = *(int *)(iVar5 + 4);
  UI_ComposeOverlayWindowFromRecord(param_1,0x2357,iVar3);
  Window_GadgetNotify_Text_SetText(param_1,0x515,iVar5 + 0xc);
  FUN_0054dd83(local_50,(byte *)s__d__s_00568324,*(undefined4 *)(iVar3 + 0x40));
  Window_GadgetNotify_Text_SetText(param_1,0x514,local_50);
  FUN_0054dd83(local_50,&DAT_005686f4,*(undefined4 *)(iVar5 + 0x2c));
  Window_GadgetNotify_Text_SetText(param_1,0x513,local_50);
  FUN_0054dd83(local_50,&DAT_005686f4,*(int *)(iVar5 + 0x30) + 1);
  Window_GadgetNotify_Text_SetText(param_1,0x2331,local_50);
  local_30[0] = *(int *)(iVar5 + 0x3c);
  local_30[1] = *(undefined4 *)(iVar5 + 0x40);
  local_30[2] = *(undefined4 *)(iVar5 + 0x44);
  local_30[3] = *(undefined4 *)(iVar5 + 0x48);
  local_20 = *(undefined4 *)(iVar5 + 0x4c);
  local_1c = *(undefined4 *)(iVar5 + 0x50);
  local_18[0] = *(undefined4 *)(iVar5 + 0x54);
  local_18[1] = *(undefined4 *)(iVar5 + 0x58);
  local_18[2] = *(undefined4 *)(iVar5 + 0x5c);
  local_18[3] = *(undefined4 *)(iVar5 + 0x60);
  local_8 = *(undefined4 *)(iVar5 + 100);
  local_4 = *(undefined4 *)(iVar5 + 0x68);
  piVar4 = local_30;
  iVar3 = 0x2342;
  do {
    UI_PrintSignedValue(param_1,iVar3 + -6,*piVar4);
    UI_PrintSignedValue(param_1,iVar3,piVar4[6]);
    UI_PrintSignedValue(param_1,iVar3 + 6,piVar4[6] + *piVar4);
    piVar4 = piVar4 + 1;
    iVar2 = iVar3 + -0x2341;
    iVar3 = iVar3 + 1;
  } while (iVar2 < 6);
  Window_GadgetNotify_Text_SetText(param_1,0x51b,iVar1 + 8);
  FUN_004a66d0(param_1,0x2358,iVar1);
  iVar1 = *(int *)(iVar5 + 0xa0);
  iVar3 = 0;
  local_5c[0] = 0;
  local_5c[1] = 0;
  local_5c[2] = 0;
  if (0 < iVar1) {
    do {
      iVar2 = FUN_004017f0((void *)(iVar5 + 0x8c),iVar3,(int *)0x0);
      iVar2 = *(int *)(iVar2 + 4);
      if (iVar2 == 0) {
        local_5c[2] = local_5c[2] + 1;
      }
      else if (iVar2 == 1) {
        local_5c[0] = local_5c[0] + 1;
      }
      else if (iVar2 == 2) {
        local_5c[1] = local_5c[1] + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  piVar4 = local_5c;
  iVar5 = 0x2352;
  do {
    iVar1 = *piVar4;
    if (iVar1 == 0) {
      Gadget_SetTextf(param_1,iVar5,DAT_00582e4c,unaff_EDI);
    }
    else {
      Gadget_SetTextf(param_1,iVar5,&DAT_005686f4,iVar1);
      UI_DrawAwardMedals(param_1,iVar5 + -3,iVar1,iVar5 + -0x2352);
    }
    piVar4 = piVar4 + 1;
    iVar1 = iVar5 + -0x2351;
    iVar5 = iVar5 + 1;
  } while (iVar1 < 3);
  return;
}

