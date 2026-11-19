// rea decompile_all
// name: Window_UpdateBranchInfoPage
// address: 0x4b83f0
// body: available
// range: 0x4b83f0-0x4b8790 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Window_UpdateBranchInfoPage(void *param_1,char param_2)

{
  void *this;
  int iVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 unaff_EBP;
  uint uVar4;
  undefined4 unaff_EDI;
  bool bVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined1 local_340 [64];
  undefined1 local_300 [64];
  undefined1 local_2c0 [64];
  undefined1 local_280 [64];
  undefined1 local_240 [64];
  undefined1 local_200 [256];
  byte local_100 [256];
  
                    /* Updates the branch info page's type, flags, owner, and ratings. */
  puVar6 = local_340;
  FUN_0054dd83(local_340,DAT_00582e4c,unaff_EDI);
  puVar7 = local_300;
  FUN_0054dd83(puVar7,DAT_00582e4c,puVar6);
  puVar6 = local_2c0;
  FUN_0054dd83(puVar6,DAT_00582e4c,puVar7);
  FUN_0054dd83(local_280,DAT_00582e4c,puVar6);
  if (param_2 == '\0') {
    this = *(void **)((int)DAT_0057c670 + 0x9c);
    DAT_0057d6b8 = (void *)FUN_00488be0(DAT_0057c670,*(int *)((int)this + 0x30));
  }
  else {
    iVar1 = *(int *)((int)DAT_0057c670 + 0x218);
    DAT_0057d6b8 = (void *)FUN_00488be0(DAT_0057c670,*(int *)(iVar1 + 8));
    this = (void *)FUN_004017f0((void *)((int)DAT_0057d6b8 + 0x148),*(int *)(iVar1 + 0x2c),
                                (int *)0x0);
    FUN_0052f9b0(param_1,0x483,(int)this + 4);
  }
  iVar1 = FUN_004e34a0(DAT_0057d6b8,*(int *)((int)this + 0x3c));
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x20) < 1)) {
    FUN_0052f9b0(param_1,0x495,DAT_005829f0);
    FUN_0052f9b0(param_1,0x496,DAT_005829f0);
    pbVar3 = DAT_00582e4c;
  }
  else {
    FUN_0054dd83(local_240,&DAT_005630d0,*(undefined4 *)(&DAT_00583504 + *(int *)(iVar1 + 0x10) * 4)
                );
    FUN_0052f9b0(param_1,0x495,local_240);
    bVar5 = (*(byte *)(iVar1 + 0x14) & 8) != 0;
    if (bVar5) {
      FUN_0054dd83(local_340,&DAT_005630d0,DAT_00582654);
    }
    uVar4 = (uint)bVar5;
    if ((*(byte *)(iVar1 + 0x14) & 4) != 0) {
      FUN_0054dd83(local_340 + uVar4 * 0x40,&DAT_005630d0,DAT_00582910);
      uVar4 = uVar4 + 1;
    }
    if ((*(byte *)(iVar1 + 0x14) & 2) != 0) {
      FUN_0054dd83(local_340 + uVar4 * 0x40,&DAT_005630d0,DAT_00581af0);
      uVar4 = uVar4 + 1;
    }
    if ((*(byte *)(iVar1 + 0x14) & 1) != 0) {
      FUN_0054dd83(local_340 + uVar4 * 0x40,&DAT_005630d0,DAT_00581b80);
      uVar4 = uVar4 + 1;
    }
    if (uVar4 < 3) {
      if (uVar4 == 2) {
        FUN_0054dd83(local_200,(byte *)s__s__s_0056a8a8,local_340);
      }
      else {
        FUN_0054dd83(local_200,&DAT_005630d0,local_340);
      }
      FUN_0054dd83(local_100,DAT_00582e4c,unaff_EBP);
    }
    else if (uVar4 == 3) {
      FUN_0054dd83(local_200,(byte *)s__s__s_0056a8a8,local_340);
      FUN_0054dd83(local_100,&DAT_005630d0,local_2c0);
    }
    else {
      FUN_0054dd83(local_200,(byte *)s__s__s_0056a8a8,local_340);
      FUN_0054dd83(local_100,(byte *)s__s__s_0056a8a8,local_2c0);
    }
    if (*(int *)(iVar1 + 0x14) == 0) {
      puVar7 = local_200;
      FUN_0054dd83(puVar7,&DAT_005630d0,DAT_005826e4);
      FUN_0054dd83(local_100,DAT_00582e4c,puVar7);
    }
    FUN_0052f9b0(param_1,0x496,local_200);
    pbVar3 = local_100;
  }
  FUN_0052f9b0(param_1,0x4aa,pbVar3);
  FUN_0052f9b0(param_1,0x488,(int)DAT_0057d6b8 + 8);
  if (param_2 == '\0') {
    iVar1 = 0x1f51;
  }
  else {
    iVar1 = 0x1f53;
  }
  Personnel_SetEmployeePhotoByKey(param_1,iVar1,(int)DAT_0057d6b8);
  FUN_00491c80(param_1,0x4a0,*(int *)((int)DAT_0057d6b8 + 0x48),(int)this);
  iVar1 = 0;
  do {
    iVar8 = DAT_00582998;
    iVar2 = FUN_0047a3b0(this,iVar1,1);
    Rating_UpdateBarByKey(param_1,0x46f,iVar1,iVar2,iVar8);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  return;
}

