// rea decompile_all
// name: FUN_004052c0
// address: 0x4052c0
// body: available
// range: 0x4052c0-0x4055a2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl
FUN_004052c0(char *param_1,undefined4 param_2,int param_3,undefined4 param_4,char *param_5,
            undefined4 param_6,int param_7,undefined4 param_8,char *param_9,undefined4 param_10,
            int param_11,undefined4 param_12,char *param_13,undefined4 param_14,int param_15,
            undefined4 param_16,char *param_17,undefined4 param_18,int param_19,undefined4 param_20,
            char *param_21,undefined4 param_22,int param_23,undefined4 param_24,char *param_25,
            undefined4 param_26,int param_27)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined1 *puVar4;
  DWORD DVar5;
  undefined4 unaff_EBX;
  char *unaff_EBP;
  undefined4 unaff_ESI;
  char *pcVar6;
  int unaff_EDI;
  int *piVar7;
  undefined4 unaff_retaddr;
  int aiStack_324 [128];
  int in_stack_fffffefc;
  undefined4 in_stack_ffffff00;
  char *in_stack_ffffff04;
  undefined4 in_stack_ffffff08;
  int in_stack_ffffff0c;
  undefined4 in_stack_ffffff10;
  char *in_stack_ffffff14;
  undefined4 in_stack_ffffff18;
  int in_stack_ffffff1c;
  undefined4 in_stack_ffffff20;
  char *in_stack_ffffff24;
  undefined4 in_stack_ffffff28;
  int in_stack_ffffff2c;
  undefined4 in_stack_ffffff30;
  char *in_stack_ffffff34;
  undefined4 in_stack_ffffff38;
  int in_stack_ffffff3c;
  undefined4 in_stack_ffffff40;
  char *in_stack_ffffff44;
  undefined4 in_stack_ffffff48;
  int in_stack_ffffff4c;
  undefined4 in_stack_ffffff50;
  char *in_stack_ffffff54;
  undefined4 in_stack_ffffff58;
  int in_stack_ffffff5c;
  undefined4 in_stack_ffffff60;
  undefined *in_stack_ffffff64;
  undefined4 in_stack_ffffff68;
  int in_stack_ffffff6c;
  undefined4 in_stack_ffffff70;
  char *in_stack_ffffff74;
  undefined4 in_stack_ffffff78;
  int in_stack_ffffff7c;
  undefined4 in_stack_ffffff80;
  undefined *in_stack_ffffff84;
  undefined4 in_stack_ffffff88;
  int in_stack_ffffff8c;
  undefined4 in_stack_ffffff90;
  char *in_stack_ffffff94;
  undefined4 in_stack_ffffff98;
  int in_stack_ffffff9c;
  undefined4 in_stack_ffffffa0;
  char *in_stack_ffffffa4;
  undefined4 in_stack_ffffffa8;
  int in_stack_ffffffac;
  undefined4 in_stack_ffffffb0;
  char *in_stack_ffffffb4;
  undefined4 in_stack_ffffffb8;
  int in_stack_ffffffbc;
  undefined4 in_stack_ffffffc0;
  char *in_stack_ffffffc4;
  undefined4 in_stack_ffffffc8;
  int in_stack_ffffffcc;
  undefined4 in_stack_ffffffd0;
  char *in_stack_ffffffd4;
  undefined4 in_stack_ffffffd8;
  int in_stack_ffffffdc;
  undefined4 in_stack_ffffffe0;
  char *in_stack_ffffffe4;
  undefined4 in_stack_ffffffe8;
  int in_stack_ffffffec;
  undefined4 in_stack_fffffff0;
  char *in_stack_fffffff4;
  undefined4 in_stack_fffffff8;
  int in_stack_fffffffc;
  
  pcVar6 = (char *)0x0;
  piVar2 = FUN_00402290(DAT_0057c5d8,s_mission_txt_00563bd8,0);
  if (piVar2 == (int *)0x0) {
    FUN_0048e0a0();
  }
  iVar3 = FUN_00402840(DAT_0057c5d8,(undefined1 *)(aiStack_324 + 0x89),0x100,(int)piVar2);
  while (iVar3 != -1) {
    iVar3 = -1;
    piVar7 = aiStack_324 + 0x89;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      iVar1 = *piVar7;
      piVar7 = (int *)((int)piVar7 + 1);
    } while ((char)iVar1 != '\0');
    if (iVar3 == -2) break;
    puVar4 = operator_new(0x20);
    FUN_0054dd83(puVar4,&DAT_005630d0,aiStack_324 + 0x89);
    FUN_004014b0(&DAT_0057c590,puVar4);
    iVar3 = FUN_00402840(DAT_0057c5d8,(undefined1 *)(aiStack_324 + 0x89),0x100,(int)piVar2);
  }
  FUN_00402990(DAT_0057c5d8,(int)piVar2);
  DAT_0057c5f0 = (void *)0x0;
LAB_00405377:
  DVar5 = WaitForSingleObject(DAT_0057c0d8,10);
  if (DVar5 == 0) {
    Game_ShutdownSubsystems();
    if (DAT_0057ba10 != (undefined4 *)0x0) {
      (**(code **)*DAT_0057ba10)(1);
    }
    if (DAT_0057c5cc != (undefined4 *)0x0) {
      (**(code **)*DAT_0057c5cc)(1);
    }
    DAT_0057c5cc = (undefined4 *)0x0;
    return;
  }
  if (DAT_0056386c != 0) {
    DAT_0057c5b8 = DAT_0056386c;
  }
  switch(DAT_0056386c) {
  case 0x15:
    FUN_004050e0();
    if (pcVar6 != (char *)0x0) {
      FUN_00526700(DAT_0057c5e0,(undefined4 *)pcVar6);
    }
    pcVar6 = FUN_00476920(aiStack_324 + 0x88);
    break;
  case 0x16:
    if (pcVar6 != (char *)0x0) {
      FUN_00526700(DAT_0057c5e0,(undefined4 *)pcVar6);
    }
    piVar2 = aiStack_324 + 0x88;
    pcVar6 = FUN_00474df0(piVar2);
    Screen_MissionBriefing_Populate
              (pcVar6,piVar2,unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX,in_stack_fffffefc,
               in_stack_ffffff00,in_stack_ffffff04,in_stack_ffffff08,in_stack_ffffff0c,
               in_stack_ffffff10,in_stack_ffffff14,in_stack_ffffff18,in_stack_ffffff1c,
               in_stack_ffffff20,in_stack_ffffff24,in_stack_ffffff28,in_stack_ffffff2c,
               in_stack_ffffff30,in_stack_ffffff34,in_stack_ffffff38,in_stack_ffffff3c,
               in_stack_ffffff40,in_stack_ffffff44,in_stack_ffffff48,in_stack_ffffff4c,
               in_stack_ffffff50,in_stack_ffffff54,in_stack_ffffff58,in_stack_ffffff5c,
               in_stack_ffffff60,in_stack_ffffff64,in_stack_ffffff68,in_stack_ffffff6c,
               in_stack_ffffff70,in_stack_ffffff74,in_stack_ffffff78,in_stack_ffffff7c,
               in_stack_ffffff80,in_stack_ffffff84,in_stack_ffffff88,in_stack_ffffff8c,
               in_stack_ffffff90,in_stack_ffffff94,in_stack_ffffff98,in_stack_ffffff9c,
               in_stack_ffffffa0,in_stack_ffffffa4,in_stack_ffffffa8,in_stack_ffffffac,
               in_stack_ffffffb0,in_stack_ffffffb4,in_stack_ffffffb8,in_stack_ffffffbc,
               in_stack_ffffffc0,in_stack_ffffffc4,in_stack_ffffffc8,in_stack_ffffffcc,
               in_stack_ffffffd0,in_stack_ffffffd4,in_stack_ffffffd8,in_stack_ffffffdc,
               in_stack_ffffffe0,in_stack_ffffffe4,in_stack_ffffffe8,in_stack_ffffffec,
               in_stack_fffffff0,in_stack_fffffff4,in_stack_fffffff8,in_stack_fffffffc,unaff_retaddr
               ,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11,param_12,param_13,param_14,param_15,param_16,param_17,param_18,param_19,
               param_20,param_21,param_22,param_23,param_24,param_25,param_26,param_27);
    break;
  case 0x17:
    if (pcVar6 != (char *)0x0) {
      FUN_00526700(DAT_0057c5e0,(undefined4 *)pcVar6);
    }
    DAT_0057c5c0 = 0;
    Game_RunSession();
    DAT_0057c5c0 = 0;
    pcVar6 = (char *)0x0;
    FUN_00525a10(DAT_0057c5e0,1);
    goto LAB_00405377;
  case 0x18:
    if (pcVar6 != (char *)0x0) {
      FUN_00526700(DAT_0057c5e0,(undefined4 *)pcVar6);
    }
    pcVar6 = FUN_00472da0(aiStack_324 + 0x88);
    FreePlaySetup_InitWindow(pcVar6);
    break;
  case 0x19:
    if (DAT_0057c5f0 != (void *)0x0) goto switchD_004053a3_default;
    DAT_0057c5f0 = FUN_004750b0(aiStack_324 + 0x88);
    SubStartMenuA_InitSaveGamePage(DAT_0057c5f0);
    break;
  case 0x1a:
    goto switchD_004053a3_caseD_1a;
  case 0x1b:
    if (DAT_0057c5f0 != (void *)0x0) goto switchD_004053a3_default;
    DAT_0057c5f0 = FUN_0046e960(aiStack_324 + 0x88);
    FUN_004c7d80(DAT_0057c5f0);
    break;
  case 0x1c:
    if (pcVar6 != (char *)0x0) {
      FUN_00526700(DAT_0057c5e0,(undefined4 *)pcVar6);
    }
    pcVar6 = FUN_0046dbd0(aiStack_324 + 0x88);
    CharacterSelect_UpdateScreen(pcVar6);
    break;
  case 0x1d:
    FUN_004052a0();
    if (pcVar6 != (char *)0x0) {
      FUN_00526700(DAT_0057c5e0,(undefined4 *)pcVar6);
    }
    FUN_00525a10(DAT_0057c5e0,1);
    if ((char)DAT_0057bb54 != '\0') {
      Game_RunSession();
    }
  default:
switchD_004053a3_default:
    FUN_00525a10(DAT_0057c5e0,1);
    goto LAB_00405377;
  }
  FUN_00523d60(DAT_0057c5e0,in_stack_fffffefc);
  DAT_0056386c = 0;
  FUN_00525a10(DAT_0057c5e0,1);
  goto LAB_00405377;
switchD_004053a3_caseD_1a:
  if (pcVar6 != (char *)0x0) {
    FUN_00526700(DAT_0057c5e0,(undefined4 *)pcVar6);
  }
  pcVar6 = (char *)0x0;
  DAT_0056386c = 0;
  FUN_00525a10(DAT_0057c5e0,1);
  goto LAB_00405377;
}

