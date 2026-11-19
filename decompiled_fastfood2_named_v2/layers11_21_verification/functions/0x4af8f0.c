// rea decompile_all
// name: FUN_004af8f0
// address: 0x4af8f0
// body: available
// range: 0x4af8f0-0x4afd00 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004af8f0(void *param_1)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  int local_274;
  int *local_270;
  int local_26c;
  int local_268;
  int local_264;
  int local_260 [8];
  char local_240 [256];
  int local_140 [16];
  int local_100 [64];
  
  iVar4 = 0x3e9;
  piVar3 = local_260;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = -1;
    piVar3 = piVar3 + 1;
  }
  do {
    Window_GadgetNotify_Button_SetState
              (param_1,iVar4,(uint)(iVar4 + -0x3e9 == DAT_0057d664 - DAT_0057d668));
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x3f6);
  Window_GadgetNotify_Text_SetText(param_1,0x3fd,*(undefined4 *)(&DAT_00583434 + DAT_0057d664 * 4));
  Window_GadgetNotify_Text_SetText(param_1,0x3fe,*(undefined4 *)(&DAT_00583888 + DAT_0057d664 * 4));
  DAT_0057d660 = FUN_004034d0(0,*(uint *)(&DAT_0056a560 + DAT_0057d664 * 4));
  iVar1 = *(int *)(&DAT_0056a560 + DAT_0057d664 * 4);
  if (iVar1 == 0) {
    pcVar6 = s__s_bik_00569bfc;
LAB_004afa35:
    puVar2 = &DAT_0056a1a0 + DAT_0057d664 * 0x20;
  }
  else if (iVar1 == 1) {
    if (DAT_0057d660 == 0) {
      puVar2 = &DAT_0056a1a0 + DAT_0057d664 * 0x20;
      pcVar6 = s__sm_bik_0056a5f8;
    }
    else {
      puVar2 = &DAT_0056a1a0 + DAT_0057d664 * 0x20;
      pcVar6 = s__sw_bik_0056a5f0;
    }
  }
  else {
    if (iVar1 != 2) goto LAB_004afa42;
    if (DAT_0057d660 == 0) {
      puVar2 = &DAT_0056a1a0 + DAT_0057d664 * 0x20;
      pcVar6 = s__smg_bik_0056a620;
    }
    else {
      if (DAT_0057d660 != 1) {
        pcVar6 = s__ssniper_bik_0056a600;
        goto LAB_004afa35;
      }
      puVar2 = &DAT_0056a1a0 + DAT_0057d664 * 0x20;
      pcVar6 = s__spistole_bik_0056a610;
    }
  }
  FUN_0054dd83(local_240,(byte *)pcVar6,puVar2);
LAB_004afa42:
  FUN_005314a0(param_1,0x881,&local_268,&local_26c);
  FUN_005311a0(param_1,0x881);
  FUN_00531bb0(param_1,0x881,local_268,local_26c,local_240,(undefined4 *)0x0);
  UI_StartButtonMovie(param_1,0x881,1);
  FUN_00549f50(DAT_0057ba0c,DAT_0057d664,DAT_0057d660);
  iVar1 = 0x9b4;
  do {
    FUN_005316f0(param_1,iVar1,(uint)(DAT_0057d664 < 8));
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x9c6);
  iVar1 = 50000;
  do {
    FUN_005311a0(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xc3aa);
  if (7 < DAT_0057d664) {
    iVar1 = 0x86f;
    do {
      Window_GadgetNotify_Text_SetText(param_1,iVar1,DAT_00582e4c);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x877);
    DAT_0057d660 = 0;
    return;
  }
  local_264 = 0;
  FUN_005314a0(param_1,0x42e,&local_268,&local_26c);
  FUN_004af620(local_100,local_260);
  local_270 = local_260;
  local_274 = 0;
  piVar3 = local_100;
  do {
    if (*local_270 == -1) {
      uVar7 = DAT_00582e4c;
    }
    else {
      uVar7 = *(undefined4 *)(&DAT_005840d4 + *local_270 * 4);
    }
    Window_GadgetNotify_Text_SetText(param_1,local_274 + 0x86f,uVar7);
    iVar4 = 0;
    iVar1 = local_264 + 50000;
    local_264 = local_264 + 8;
    do {
      FUN_0054dd83(local_240,(byte *)s_BEWERTUNG___02d_spr_00569f68,(*piVar3 * 0x10 + 0x32) / 100);
      FUN_00531850(param_1,iVar1,DAT_0057d658 * iVar4 + local_268,
                   DAT_0057d65c * local_274 + local_26c,local_240);
      iVar1 = iVar1 + 1;
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < 8);
    local_274 = local_274 + 1;
    local_270 = local_270 + 1;
  } while (local_274 < 8);
  FUN_005314a0(param_1,0x1f5d,&local_268,&local_26c);
  FUN_004af7a0(local_140);
  local_274 = 0;
  piVar3 = local_140;
  iVar1 = local_264 + 50000;
  while( true ) {
    iVar5 = 0;
    iVar4 = iVar1 + 2;
    do {
      FUN_0054dd83(local_240,(byte *)s_BEWERTUNG2___02d_spr_0056a5d8,(*piVar3 * 0x10 + 0x32) / 100);
      FUN_00531850(param_1,iVar1,DAT_0057d658 * iVar5 + local_268,
                   DAT_0057d65c * local_274 + local_26c,local_240);
      iVar1 = iVar1 + 1;
      iVar5 = iVar5 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar5 < 2);
    local_274 = local_274 + 1;
    if (8 < local_274) break;
    iVar1 = iVar4;
  }
  DAT_0057d660 = 0;
  return;
}

