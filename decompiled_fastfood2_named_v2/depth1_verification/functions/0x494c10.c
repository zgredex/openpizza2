// rea decompile_all
// name: FUN_00494c10
// address: 0x494c10
// body: available
// range: 0x494c10-0x4951ee inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_00494c10(void *param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int *piVar5;
  longlong lVar6;
  undefined4 uVar7;
  int local_28;
  int local_24;
  int local_20 [8];
  
  iVar2 = Game_GetPlayerFieldC20
                    (*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  if (iVar2 < 2) {
    FUN_00531740(param_1,0x1fa8);
  }
  if (3 < DAT_0057c6d8) {
    FUN_004949a0(param_1);
    pvVar1 = *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    iVar3 = FUN_004ddcc0((int)pvVar1);
    iVar2 = *(int *)(iVar3 + 0x68);
    iVar3 = *(int *)(iVar3 + 0x50);
    if (*(void **)((int)pvVar1 + 0x1d8) == (void *)0x0) {
      local_28 = 0;
      uVar7 = 0xff;
    }
    else {
      local_28 = Game_CountFreeBuildingsByType(*(void **)((int)pvVar1 + 0x1d8),0x17);
      if (local_28 == 0) {
        uVar7 = 0xff;
      }
      else {
        uVar7 = 0;
      }
    }
    FUN_0052f910(param_1,0x1f64,uVar7);
    FUN_0052f080(param_1,0x1f64,&DAT_005686f4,local_28);
    local_28 = Game_CountFreeSlots(DAT_0057c670,0x17);
    if (local_28 == 0) {
      uVar7 = 0xff;
    }
    else {
      uVar7 = 0;
    }
    FUN_0052f910(param_1,0x1f6a,uVar7);
    FUN_0052f080(param_1,0x1f6a,&DAT_005686f4,local_28);
    local_28 = *(int *)((int)pvVar1 + 100);
    FUN_0052f080(param_1,0x1f6c,&DAT_005686f4,local_28);
    puVar4 = FUN_004e25b0(pvVar1,0x17,0);
    FUN_0052f080(param_1,0x1f6e,&DAT_005686f4,puVar4);
    puVar4 = FUN_004e25b0(pvVar1,0x17,1);
    FUN_0052f080(param_1,0x1f70,&DAT_005686f4,puVar4);
    puVar4 = FUN_004e25b0(pvVar1,0x17,2);
    FUN_0052f080(param_1,0x1f72,&DAT_005686f4,puVar4);
    FUN_0052f9b0(param_1,0x5c6,DAT_00582930);
    FUN_0052f080(param_1,0x5c2,&DAT_005683a4,(((iVar2 + iVar3) * -0x1e + 100) * 500) / 100);
    FUN_0052f9b0(param_1,0x5c4,DAT_0057c6f4 + 4);
    iVar2 = 0;
    do {
      FUN_004a80e0(param_1,0x5af,iVar2,0,0);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    return;
  }
  if ((void *)(&DAT_0057c6e0)[DAT_0057c6d8] != (void *)0x0) {
    DAT_0057c6f0 = (int *)FUN_004017f0((void *)(&DAT_0057c6e0)[DAT_0057c6d8],DAT_0057c6dc,(int *)0x0
                                      );
  }
  if (DAT_0057c6f0 == (int *)0x0) {
    DAT_0057c6dc = 0;
    DAT_0057c6f0 = (int *)FUN_004017f0((void *)(&DAT_0057c6e0)[DAT_0057c6d8],0,(int *)0x0);
    if (DAT_0057c6f0 == (int *)0x0) {
      return;
    }
  }
  FUN_004949a0(param_1);
  iVar2 = 0x1f53;
  do {
    FUN_00531740(param_1,iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1f57);
  iVar2 = 0x1f5b;
  do {
    FUN_00531740(param_1,iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1f63);
  iVar3 = (uint)*(byte *)(*DAT_0057c6f0 + 0x824) * 4;
  iVar2 = *(int *)(&DAT_00568770 + iVar3);
  iVar3 = *(int *)(&DAT_00568780 + iVar3);
  FUN_005316b0(param_1,iVar2);
  FUN_0052fd00(param_1,iVar2,0,7,0);
  FUN_0052fce0(param_1,iVar2,1);
  FUN_0052fd70(param_1,iVar2,DAT_00568790,0);
  FUN_005316b0(param_1,iVar3);
  FUN_005316b0(param_1,iVar3 + 1);
  Array_GetPairByKey(param_1,0x1f48,&local_28,&local_24);
  local_28 = local_28 + 2 + DAT_00568790 * 0x14;
  if (DAT_00568790 < 1) {
    iVar2 = local_28 + 0x8c;
  }
  else {
    iVar2 = local_28 + -0x14;
  }
  FUN_00531400(param_1,iVar3,iVar2,local_24);
  if (DAT_00568790 < 7) {
    iVar2 = local_28 + 0x14;
  }
  else {
    iVar2 = local_28 + -0x8c;
  }
  FUN_00531400(param_1,iVar3 + 1,iVar2,local_24);
  pvVar1 = *(void **)((int)DAT_0057c670 + 0x9c);
  iVar2 = FUN_004d3930(*DAT_0057c6f0);
  FUN_0052f9b0(param_1,0x5c4,iVar2);
  FUN_0052f080(param_1,0x5c7,&DAT_005686f4,*(undefined4 *)(*DAT_0057c6f0 + 0x38));
  FUN_0052f9b0(param_1,0x5c6,
               *(undefined4 *)(&DAT_005832a8 + (uint)*(byte *)(*DAT_0057c6f0 + 0x824) * 4));
  iVar2 = Rating_GetComposite(*DAT_0057c6f0);
  FUN_0052f080(param_1,0x5c3,&DAT_005686f4,iVar2);
  FUN_004ddcc0(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  lVar6 = FUN_004d3990(*DAT_0057c6f0);
  FUN_0052f080(param_1,0x5c2,&DAT_005683a4,(int)lVar6);
  FUN_0052f9b0(param_1,0x48a,
               *(undefined4 *)(&DAT_005832d4 + (uint)*(byte *)(*DAT_0057c6f0 + 0x824) * 4));
  FUN_0052fd00(param_1,0x466,0,100,0);
  FUN_0052fd00(param_1,0x468,0,100,0);
  FUN_0052fd00(param_1,0x465,0,100,0);
  FUN_0052fd00(param_1,0x469,0,100,0);
  uVar7 = 0;
  iVar2 = FUN_004d3f90(*DAT_0057c6f0);
  FUN_0052fd70(param_1,0x466,iVar2,uVar7);
  uVar7 = 0;
  iVar2 = FUN_004d3fc0(*DAT_0057c6f0);
  FUN_0052fd70(param_1,0x468,iVar2,uVar7);
  FUN_0052fd70(param_1,0x469,*(undefined4 *)(*DAT_0057c6f0 + 0xc),0);
  uVar7 = 0;
  iVar2 = FUN_004d3fe0(*DAT_0057c6f0);
  FUN_0052fd70(param_1,0x465,iVar2,uVar7);
  FUN_0054bb00(param_1,0x1f43,*DAT_0057c6f0);
  Rating_ComputeEightCategories((int *)*DAT_0057c6f0,local_20);
  iVar2 = 0;
  piVar5 = local_20;
  do {
    FUN_004a80e0(param_1,0x5af,iVar2,*piVar5,DAT_00582f94);
    iVar2 = iVar2 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar2 < 8);
  iVar2 = Game_CountObjectsByType(pvVar1,0);
  FUN_0052f080(param_1,0x5c9,&DAT_005686f4,iVar2);
  iVar2 = Game_CountObjectsByType(pvVar1,2);
  FUN_0052f080(param_1,0x5ca,&DAT_005686f4,iVar2);
  iVar2 = Game_CountObjectsByType(pvVar1,3);
  FUN_0052f080(param_1,0x5cb,&DAT_005686f4,iVar2);
  iVar2 = Game_CountObjectsByType(pvVar1,1);
  FUN_0052f080(param_1,0x5cc,&DAT_005686f4,iVar2);
  return;
}

