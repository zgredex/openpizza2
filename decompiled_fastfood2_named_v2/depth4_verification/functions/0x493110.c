// rea decompile_all
// name: FUN_00493110
// address: 0x493110
// body: available
// range: 0x493110-0x49369f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_00493110(void *param_1,char param_2,char param_3)

{
  uint uVar1;
  byte bVar2;
  undefined3 extraout_var;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined1 local_20 [32];
  
  iVar6 = *(int *)(DAT_0057c670 + 0x21c);
  if ((iVar6 != 0) && (param_3 != '\0')) {
    bVar2 = FUN_0050e550(iVar6);
    FUN_005499f0(DAT_0057ba0c,*(int *)(iVar6 + 0x30),CONCAT31(extraout_var,bVar2),
                 *(int *)(iVar6 + 0x24) == 0);
  }
  DAT_0057c6d0 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  FUN_0052f9b0(param_1,0x1389,DAT_00582d28);
  iVar6 = 6000;
  do {
    FUN_0052fce0(param_1,iVar6,1);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x178c);
  if (param_2 == '\0') {
    _param_3 = *(void **)(DAT_0057c670 + 0x9c);
  }
  else {
    iVar6 = FUN_004017f0((void *)(DAT_0057c670 + 0x20),
                         *(int *)(*(int *)(DAT_0057c670 + 0x21c) + 0x50),(int *)0x0);
    _param_3 = (void *)0x0;
    if (iVar6 == 0) goto LAB_00493269;
    _param_3 = (void *)FUN_004017f0((void *)(DAT_0057c6d0 + 0x148),*(int *)(iVar6 + 0x820),
                                    (int *)0x0);
    if (_param_3 == (void *)0x0) {
      _param_3 = *(void **)(DAT_0057c670 + 0x9c);
    }
    iVar7 = 0;
    iVar3 = FUN_0047aac0(_param_3,0xffffffff);
    if (0 < iVar3) {
      do {
        piVar4 = (int *)FUN_004017f0((void *)((int)_param_3 + 0x1500),iVar7,(int *)0x0);
        if (*piVar4 == iVar6) {
          DAT_0056872c = iVar7;
        }
        iVar7 = iVar7 + 1;
        iVar3 = FUN_0047aac0(_param_3,0xffffffff);
      } while (iVar7 < iVar3);
    }
    FUN_0052f9b0(param_1,0x1f41,(int)_param_3 + 4);
  }
  if (_param_3 != (void *)0x0) {
    DAT_00568728 = *(int *)((int)_param_3 + 0x3c);
  }
LAB_00493269:
  iVar3 = FUN_0047aac0(_param_3,0xffffffff);
  uVar1 = (uint)(0 < iVar3);
  FUN_005316f0(param_1,0x44f,uVar1);
  FUN_005316f0(param_1,0x450,uVar1);
  FUN_005316f0(param_1,0x52c,uVar1);
  FUN_005316f0(param_1,0x52e,uVar1);
  FUN_005316f0(param_1,0x52d,uVar1);
  FUN_005316f0(param_1,0x527,uVar1);
  FUN_005316f0(param_1,0x52a,uVar1);
  FUN_005316f0(param_1,0x528,uVar1);
  FUN_005316f0(param_1,0x529,uVar1);
  FUN_005316f0(param_1,0x451,uVar1);
  FUN_005316f0(param_1,0x47f,uVar1);
  FUN_005316f0(param_1,0x52f,uVar1);
  FUN_005316f0(param_1,0x538,uVar1);
  FUN_005316f0(param_1,0x541,uVar1);
  FUN_005316f0(param_1,0x54a,uVar1);
  FUN_005316f0(param_1,0x553,uVar1);
  FUN_005316f0(param_1,0x55c,uVar1);
  FUN_005316f0(param_1,0x565,uVar1);
  uVar5 = 500;
  iVar6 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(iVar6 + 0xe0) == 0) {
    if (*(int *)(iVar6 + 0x1c4) != 0) {
      uVar5 = 0x2ee;
    }
  }
  else {
    uVar5 = 0;
  }
  FUN_0054dd83(local_20,DAT_00581eb8,uVar5);
  FUN_0052f830(param_1,0x485,local_20);
  FUN_0054dd83(local_20,(byte *)s___d___00568730,0x32);
  FUN_0052f830(param_1,0x484,local_20);
  iVar6 = 0x178c;
  do {
    FUN_00531740(param_1,iVar6);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x1794);
  FUN_00531740(param_1,5000);
  FUN_00531740(param_1,0x1389);
  FUN_005316f0(param_1,0x2332,(uint)(0 < iVar3));
  if (iVar3 == 0) {
    iVar6 = 51000;
    do {
      iVar3 = FUN_0052ff20(param_1,iVar6 + -1000);
      if (iVar3 != 0) {
        UI_RemoveObject(param_1,iVar6 + -1000);
      }
      iVar3 = FUN_0052ff20(param_1,iVar6);
      if (iVar3 != 0) {
        UI_RemoveObject(param_1,iVar6);
      }
      iVar3 = iVar6 + -50999;
      iVar6 = iVar6 + 1;
    } while (iVar3 < 7);
    iVar6 = 6000;
    do {
      FUN_00531740(param_1,iVar6);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x178c);
    iVar6 = 0x1794;
    do {
      FUN_00531740(param_1,iVar6);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x179b);
    FUN_0052fd70(param_1,0x2329,0,0);
    FUN_0052fd70(param_1,0x232b,0,0);
    FUN_0052fd70(param_1,0x232d,0,0);
    FUN_0052fd70(param_1,0x232f,0,0);
    FUN_0052fd70(param_1,9000,0,0);
    FUN_0052fd70(param_1,0x232a,0,0);
    FUN_0052fd70(param_1,0x232c,0,0);
    FUN_0052fd70(param_1,0x232e,0,0);
    DAT_0056872c = 0xffffffff;
    FUN_0052f9b0(param_1,0x52b,DAT_00582680);
    FUN_0052f9b0(param_1,0x472,DAT_00581b30);
    iVar6 = 0;
    do {
      FUN_004a80e0(param_1,0x518,iVar6,0,0);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 8);
    return;
  }
  if ((DAT_0056872c == -1) ||
     (iVar6 = FUN_004017f0((void *)((int)_param_3 + 0x1500),DAT_0056872c,(int *)0x0), iVar6 == 0)) {
    DAT_0056872c = 0;
  }
  if (iVar3 < 8) {
    FUN_00531740(param_1,0x451);
    for (; iVar3 < 7; iVar3 = iVar3 + 1) {
      FUN_00531740(param_1,iVar3 + 0x1794);
    }
    DAT_0057c6d4 = 0;
  }
  else {
    if (iVar3 < DAT_0057c6d4 + 7) {
      DAT_0057c6d4 = iVar3 + -7;
    }
    if (DAT_0057c6d4 < 0) {
      DAT_0057c6d4 = 0;
    }
    FUN_0052fd00(param_1,0x451,0,(iVar3 * 5 + -0x23) * 0x14,0);
    FUN_0052fd70(param_1,0x451,DAT_0057c6d4 * 100,0);
    FUN_0052fce0(param_1,0x451,1);
  }
  iVar6 = 0;
  FUN_004b1f40(param_1,DAT_0057c6d4,DAT_0057c6d0,DAT_00568728,DAT_0056872c);
  FUN_004b1a50(param_1,DAT_0057c6d0,DAT_00568728,'\0',DAT_0056872c);
  do {
    iVar3 = DAT_005826d8;
    iVar7 = FUN_004787f0(_param_3,iVar6);
    FUN_004a80e0(param_1,0x518,iVar6,iVar7,iVar3);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 8);
  return;
}

