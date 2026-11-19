// rea decompile_all
// name: FUN_004b8a20
// address: 0x4b8a20
// body: available
// range: 0x4b8a20-0x4b8d9e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004b8a20(void *param_1)

{
  void *this;
  void *this_00;
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 local_40 [64];
  
  piVar1 = (int *)IDMap_Lookup((void *)(DAT_0057d6c4 + 0x1500),DAT_0057d6bc,(int *)0x0);
  iVar2 = FUN_004d3930(*piVar1);
  FUN_0052f9b0(param_1,0x515,iVar2);
  FUN_0054dd83(local_40,&DAT_005686f4,*(undefined4 *)(*piVar1 + 0x38));
  FUN_0052f9b0(param_1,0x518,local_40);
  FUN_0052f9b0(param_1,0x517,*(undefined4 *)(&DAT_005832a8 + (uint)*(byte *)(*piVar1 + 0x824) * 4));
  iVar2 = FUN_004d4000(*piVar1);
  FUN_0054dd83(local_40,&DAT_005686f4,iVar2);
  FUN_0052f9b0(param_1,0x514,local_40);
  FUN_0054dd83(local_40,&DAT_005683a4,*(undefined4 *)(*piVar1 + 0x3c));
  FUN_0052f9b0(param_1,0x513,local_40);
  FUN_0052f9b0(param_1,0x502,*(undefined4 *)(&DAT_005832d4 + (uint)*(byte *)(*piVar1 + 0x824) * 4));
  FUN_0052fd00(param_1,0x2329,0,100,0);
  FUN_0052fd00(param_1,0x232b,0,100,0);
  FUN_0052fd00(param_1,0x232d,0,100,0);
  FUN_0052fd00(param_1,0x232f,0,100,0);
  FUN_0052fd00(param_1,9000,0,100,0);
  FUN_0052fd00(param_1,0x232a,0,100,0);
  FUN_0052fd00(param_1,0x232c,0,100,0);
  FUN_0052fd00(param_1,0x232e,0,100,0);
  uVar5 = 0;
  iVar2 = Rating_ClampAdjusted(*piVar1);
  FUN_0052fd70(param_1,0x2329,iVar2,uVar5);
  uVar5 = 0;
  iVar2 = Rating_AdjustA(*piVar1);
  FUN_0052fd70(param_1,0x232b,iVar2,uVar5);
  FUN_0052fd70(param_1,0x232d,*(undefined4 *)(*piVar1 + 0xc),0);
  uVar5 = 0;
  iVar2 = Rating_AdjustB(*piVar1);
  FUN_0052fd70(param_1,0x232f,iVar2,uVar5);
  uVar5 = 0;
  iVar2 = *(int *)(*piVar1 + 0x14);
  iVar3 = Rating_ClampAdjusted(*piVar1);
  FUN_0052fd70(param_1,9000,iVar3 + iVar2,uVar5);
  uVar5 = 0;
  iVar2 = *(int *)(*piVar1 + 0x18);
  iVar3 = Rating_AdjustA(*piVar1);
  FUN_0052fd70(param_1,0x232a,iVar3 + iVar2,uVar5);
  FUN_0052fd70(param_1,0x232c,*(int *)(*piVar1 + 0x1c) + *(int *)(*piVar1 + 0xc),0);
  uVar5 = 0;
  iVar2 = *(int *)(*piVar1 + 0x20);
  iVar3 = Rating_AdjustB(*piVar1);
  FUN_0052fd70(param_1,0x232e,iVar3 + iVar2,uVar5);
  FUN_0054bb00(param_1,0x2332,*piVar1);
  uVar4 = State_GetFlags(*piVar1);
  if ((char)uVar4 == '\0') {
    FUN_00531740(param_1,0x50d);
    FUN_00531740(param_1,0x50e);
    FUN_00531740(param_1,0x50f);
  }
  else {
    FUN_005316b0(param_1,0x50d);
    FUN_005316b0(param_1,0x50e);
    FUN_005316b0(param_1,0x50f);
  }
  this = *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  FUN_0052f080(param_1,0x2335,&DAT_005683a4,5000);
  this_00 = *(void **)((int)this + 0x1d8);
  if (this_00 == (void *)0x0) {
    iVar2 = 0;
    uVar5 = 0xff;
  }
  else {
    iVar2 = FUN_004d2ae0(this_00,0x1e);
    if (iVar2 == 0) {
      uVar5 = 0xff;
    }
    else {
      uVar5 = 0;
    }
  }
  FUN_0052f910(param_1,0x233b,uVar5);
  FUN_0052f080(param_1,0x233b,&DAT_005686f4,iVar2);
  iVar2 = *(int *)(DAT_0057d6c4 + 0x16f0);
  iVar3 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
  iVar2 = FUN_0048a130(DAT_0057c670,0x1c,0x1e,iVar2,iVar3);
  FUN_0052f080(param_1,0x2337,&DAT_005686f4,iVar2);
  iVar2 = FUN_004e27d0(this,DAT_0057d6c4,0x1e,-1);
  FUN_0052f080(param_1,0x2339,&DAT_005686f4,iVar2);
  return;
}

