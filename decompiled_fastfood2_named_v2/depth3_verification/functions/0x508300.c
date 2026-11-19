// rea decompile_all
// name: FUN_00508300
// address: 0x508300
// body: available
// range: 0x508300-0x508662 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00508300(void *param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint extraout_EDX;
  uint extraout_EDX_00;
  int *piVar5;
  undefined2 uVar6;
  void *local_4;
  
  local_4 = (void *)0x0;
  iVar2 = *(int *)((int)param_1 + 0xf4);
  if (iVar2 != 0) {
    local_4 = (void *)FUN_00489820(DAT_0057c670,*(int *)(iVar2 + 8),*(int *)(iVar2 + 0x2c));
    param_2 = extraout_EDX;
  }
  if ((((*(int *)((int)param_1 + 0xf4) == 0) || (local_4 == (void *)0x0)) ||
      (bVar1 = FUN_00480880((int)local_4), param_2 = extraout_EDX_00,
      CONCAT31(extraout_var,bVar1) != 0)) || (*(int *)((int)param_1 + 0x30) == 0x10)) {
    FUN_0050e310(param_1,param_2,1);
    return;
  }
  *(undefined4 *)((int)param_1 + 0x54) = 0;
  *(undefined4 *)((int)param_1 + 0x74) = 1;
  FUN_0050e710(param_1,1);
  FUN_004d28f0(*(void **)((int)param_1 + 0xf4),param_1);
  FUN_005086e0((int)param_1);
  FUN_00508c20(param_1,1,*(undefined4 *)((int)local_4 + 0x14e0));
  iVar2 = FUN_0050d750((int)param_1);
  if (iVar2 != 0) {
    FUN_0050e840((int)param_1);
    FUN_00509240((int)param_1);
  }
  switch(*(undefined4 *)((int)param_1 + 0x30)) {
  case 0x16:
    *(int *)((int)local_4 + 0x1884) = *(int *)((int)local_4 + 0x1884) + 1;
    iVar2 = *(int *)((int)local_4 + 0x30);
    iVar3 = FUN_00482820((int)DAT_0057c670);
    if ((iVar2 == iVar3) && (*(int *)((int)param_1 + 0xa4) == 2)) {
      iVar2 = 3;
      piVar4 = *(int **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xac);
      piVar5 = piVar4;
      do {
        piVar5 = piVar5 + 1;
        if ((*piVar5 == 0xe) && (FUN_004f5fa0(piVar4,0xe), 3 < piVar4[0x12])) {
          Game_CompleteMissionStage();
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    break;
  case 0x1d:
    *(int *)((int)local_4 + 0x1890) = *(int *)((int)local_4 + 0x1890) + 1;
    break;
  case 0x1e:
    *(int *)((int)local_4 + 0x1888) = *(int *)((int)local_4 + 0x1888) + 1;
    break;
  case 0x1f:
    if (*(int *)((int)param_1 + 0xa4) < 0xe) {
      *(int *)((int)local_4 + 0x188c) = *(int *)((int)local_4 + 0x188c) + 1;
      iVar2 = *(int *)((int)local_4 + 0x30);
      iVar3 = FUN_00482820((int)DAT_0057c670);
      if (iVar2 == iVar3) {
        iVar2 = 3;
        piVar4 = *(int **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xac);
        piVar5 = piVar4;
        do {
          piVar5 = piVar5 + 1;
          if ((*piVar5 == 0xe) && (FUN_004f5fa0(piVar4,0xe), 3 < piVar4[0x12])) {
            Game_CompleteMissionStage();
          }
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
  }
  switch(*(undefined4 *)((int)param_1 + 0x30)) {
  case 10:
    iVar3 = *(int *)((int)param_1 + 0x10c);
    iVar2 = 0xc;
    if (iVar3 == 0) {
      FUN_00507550(param_1,0x1a);
    }
    else if (iVar3 == 1) {
      FUN_00507550(param_1,0x1b);
    }
    else if (iVar3 == 2) {
      FUN_00507550(param_1,0x1c);
    }
    break;
  default:
    goto switchD_005084d1_caseD_b;
  case 0xd:
    iVar2 = FUN_0050e810((int)param_1);
    goto LAB_005084e4;
  case 0x11:
    iVar2 = 0x14;
    break;
  case 0x13:
    iVar2 = 0x34;
    break;
  case 0x14:
    iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 0x20),*(int *)((int)param_1 + 0x50),(int *)0x0
                        );
    if (*(char *)(iVar2 + 0x825) == '\x01') {
      uVar6 = 0x11;
    }
    else {
      uVar6 = 0x10;
    }
    FUN_00507550(param_1,uVar6);
    if (((*(int *)((int)param_1 + 0xa4) == 4) &&
        (piVar4 = (int *)FUN_0047f400(local_4,*(int *)((int)param_1 + 0x88)), piVar4 != (int *)0x0))
       && (0 < *piVar4)) {
      FUN_0050e4c0(param_1,0x10);
      iVar2 = 0x1c;
      break;
    }
    goto LAB_005085d5;
  case 0x17:
  case 0x1d:
    iVar2 = -1;
LAB_005084e4:
    FUN_0050b6d0(param_1,iVar2);
    iVar2 = FUN_0050e4a0((int)param_1);
    iVar2 = iVar2 + 0x1c;
    break;
  case 0x1f:
    if (*(int *)((int)param_1 + 0xa4) != -1) {
      FUN_0050e4c0(param_1,0x10);
      iVar2 = 0x1c;
      switch(*(undefined4 *)((int)param_1 + 0xa4)) {
      case 3:
      case 7:
      case 9:
      case 0xd:
        FUN_00507550(param_1,0x15);
        break;
      case 0x11:
        FUN_00507550(param_1,0x22);
      }
      break;
    }
LAB_005085d5:
    FUN_0050e4c0(param_1,0);
switchD_005084d1_caseD_b:
    iVar2 = 0xc;
    break;
  case 0x20:
    iVar2 = 0xc;
    FUN_0047fe10(local_4,1);
  }
  FUN_00509060(param_1,iVar2);
  FUN_005090e0((int)param_1);
  if ((*(char *)((int)local_4 + 0x16f5) == '\0') && (*(int *)((int)local_4 + 0x2c) == 0)) {
    FUN_0050e890(param_1,5);
    return;
  }
  FUN_0050e890(param_1,7);
  return;
}

