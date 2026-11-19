// rea decompile_all
// name: FUN_004b2240
// address: 0x4b2240
// body: available
// range: 0x4b2240-0x4b284b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004b2240(void *param_1)

{
  undefined4 uVar1;
  void *this;
  int iVar2;
  int iVar3;
  int local_24;
  undefined1 local_20 [32];
  
  local_24 = 0;
  FUN_00532310(param_1,&LAB_004b0d20,0);
  if (DAT_0057d690 != 0) {
    FUN_005271d0(DAT_0057c5e0,DAT_0057d690);
  }
  DAT_0057d690 = FUN_00527090(DAT_0057c5e0,s_VERDANA10_fnt_00563e64);
  DAT_0057d68c = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  DAT_0057d688 = 0;
  FUN_0052f9b0(param_1,0x1389,DAT_00582d28);
  uVar1 = 500;
  iVar3 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(iVar3 + 0xe0) == 0) {
    if (*(int *)(iVar3 + 0x1c4) != 0) {
      uVar1 = 0x2ee;
    }
  }
  else {
    uVar1 = 0;
  }
  String_Format(local_20,DAT_00581eb8,uVar1);
  FUN_0052f830(param_1,0x485,local_20);
  String_Format(local_20,(byte *)s___d___00568730,0x32);
  FUN_0052f830(param_1,0x484,local_20);
  iVar3 = 6000;
  do {
    FUN_0052fce0(param_1,iVar3,1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x178c);
  this = *(void **)(DAT_0057c670 + 0x9c);
  if (this != (void *)0x0) {
    DAT_0056a6d8 = *(int *)((int)this + 0x3c);
  }
  if (DAT_0056a6d8 == -1) {
    if (0 < *(int *)(DAT_0057d68c + 0x15c)) {
LAB_004b23a2:
      DAT_0056a6d8 = 0;
      this = (void *)IDMap_Lookup((void *)(DAT_0057d68c + 0x148),0,(int *)0x0);
    }
    if (this != (void *)0x0) goto LAB_004b23bb;
LAB_004b23e5:
    FUN_0052f830(param_1,0x1f5f,DAT_00581328);
  }
  else {
    this = (void *)IDMap_Lookup((void *)(DAT_0057d68c + 0x148),DAT_0056a6d8,(int *)0x0);
    if (this == (void *)0x0) {
      if (0 < *(int *)(DAT_0057d68c + 0x15c)) goto LAB_004b23a2;
      goto LAB_004b23e5;
    }
LAB_004b23bb:
    local_24 = FUN_0047aac0(this,0xffffffff);
    FUN_0052f830(param_1,0x1f5f,(int)this + 4);
    if (0 < local_24) {
      iVar3 = 1;
      goto LAB_004b23fa;
    }
  }
  iVar3 = 0;
LAB_004b23fa:
  FUN_005316f0(param_1,0x44f,iVar3);
  FUN_005316f0(param_1,0x450,iVar3);
  FUN_005316f0(param_1,0x52c,iVar3);
  FUN_005316f0(param_1,0x52e,iVar3);
  FUN_005316f0(param_1,0x52d,iVar3);
  FUN_005316f0(param_1,0x527,iVar3);
  FUN_005316f0(param_1,0x52a,iVar3);
  FUN_005316f0(param_1,0x528,iVar3);
  FUN_005316f0(param_1,0x529,iVar3);
  FUN_005316f0(param_1,0x451,iVar3);
  FUN_005316f0(param_1,0x47f,iVar3);
  FUN_005316f0(param_1,0x52f,iVar3);
  FUN_005316f0(param_1,0x538,iVar3);
  FUN_005316f0(param_1,0x541,iVar3);
  FUN_005316f0(param_1,0x54a,iVar3);
  FUN_005316f0(param_1,0x553,iVar3);
  FUN_005316f0(param_1,0x55c,iVar3);
  FUN_005316f0(param_1,0x565,iVar3);
  iVar2 = 0x178c;
  do {
    FUN_00531740(param_1,iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1794);
  iVar2 = 0x57d;
  do {
    FUN_00531470(param_1,iVar2,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x584);
  FUN_00531740(param_1,5000);
  FUN_00531740(param_1,0x1389);
  FUN_005316f0(param_1,0x1f53,iVar3);
  if (local_24 != 0) {
    if ((DAT_0056a6d0 == -1) ||
       (iVar3 = IDMap_Lookup((void *)((int)this + 0x1500),DAT_0056a6d0,(int *)0x0), iVar3 == 0)) {
      DAT_0056a6d0 = 0;
    }
    if (local_24 < 8) {
      FUN_00531740(param_1,0x451);
      for (; local_24 < 7; local_24 = local_24 + 1) {
        FUN_004b10e0(param_1,local_24,(int *)0x0);
        FUN_00531740(param_1,local_24 + 0x1794);
      }
    }
    else {
      if (-1 < DAT_0056a6d0) {
        DAT_0057d688 = DAT_0056a6d0;
      }
      if (local_24 < DAT_0057d688 + 7) {
        DAT_0057d688 = local_24 + -7;
      }
      FUN_0052fd00(param_1,0x451,0,(local_24 * 5 + -0x23) * 0x14,0);
      FUN_0052fd70(param_1,0x451,DAT_0057d688 * 100,0);
      FUN_0052fce0(param_1,0x451,1);
    }
    FUN_004b1f40(param_1,DAT_0057d688,DAT_0057d68c,DAT_0056a6d8,DAT_0056a6d0);
    FUN_004b1e80(param_1);
    FUN_004b1a50(param_1,DAT_0057d68c,DAT_0056a6d8,'\x01',DAT_0056a6d0);
    iVar3 = 0;
    do {
      iVar2 = FUN_004787f0(this,iVar3);
      FUN_004a80e0(param_1,0x518,iVar3,iVar2,DAT_005826d8);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    iVar3 = *(int *)(DAT_0057d68c + 0x48);
    iVar2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((int)this + 0x34),(int *)0x0);
    if (*(int *)(iVar2 + 0xc20 + iVar3 * 4) < 2) {
      FUN_00531740(param_1,5000);
      FUN_00531740(param_1,0x1389);
      FUN_00531740(param_1,0x480);
      FUN_00531740(param_1,0x483);
      FUN_00531740(param_1,0x484);
      FUN_00531740(param_1,0x485);
    }
    return;
  }
  iVar3 = 51000;
  do {
    iVar2 = FUN_0052ff20(param_1,iVar3 + -1000);
    if (iVar2 != 0) {
      FUN_005311a0(param_1,iVar3 + -1000);
    }
    iVar2 = FUN_0052ff20(param_1,iVar3);
    if (iVar2 != 0) {
      FUN_005311a0(param_1,iVar3);
    }
    iVar2 = iVar3 + -50999;
    iVar3 = iVar3 + 1;
  } while (iVar2 < 7);
  iVar3 = 6000;
  do {
    FUN_00531740(param_1,iVar3);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x178c);
  iVar3 = 0x1794;
  do {
    FUN_00531740(param_1,iVar3);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x179b);
  FUN_0052fd00(param_1,0x453,0,100,0);
  FUN_0052fd00(param_1,0x455,0,100,0);
  FUN_0052fd00(param_1,0x457,0,100,0);
  FUN_0052fd00(param_1,0x459,0,100,0);
  FUN_0052fd70(param_1,0x453,0,0);
  FUN_0052fd70(param_1,0x455,0,0);
  FUN_0052fd70(param_1,0x457,0,0);
  FUN_0052fd70(param_1,0x459,0,0);
  DAT_0056a6d0 = 0xffffffff;
  FUN_0052f9b0(param_1,0x472,DAT_00581b30);
  FUN_0052f9b0(param_1,0x578,DAT_00581b30);
  iVar3 = 0;
  do {
    FUN_004b10e0(param_1,iVar3,(int *)0x0);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 7);
  iVar3 = 0;
  do {
    FUN_004a80e0(param_1,0x518,iVar3,0,0);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  return;
}

