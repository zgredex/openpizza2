// rea decompile_all
// name: FUN_004bb120
// address: 0x4bb120
// body: available
// range: 0x4bb120-0x4bb4d1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004bb120(void *param_1,char param_2)

{
  void *this;
  int iVar1;
  int iVar2;
  void *this_00;
  int iVar3;
  int iVar4;
  undefined4 extraout_EDX;
  undefined4 unaff_EDI;
  undefined4 uVar5;
  char *pcVar6;
  
  this = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                              (int *)0x0);
  iVar4 = *(int *)(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                  0x48);
  iVar1 = FUN_004d8090((int)this);
  iVar2 = FUN_00482820((int)DAT_0057c670);
  if (iVar1 == iVar2) {
    if (param_2 == '\0') goto LAB_004bb1a6;
    uVar5 = 0xe;
  }
  else if (*(int *)((int)this + iVar4 * 4 + 0xcc8) < 0x28) {
    if (param_2 == '\0') goto LAB_004bb1a6;
    uVar5 = 0xd;
  }
  else {
    if (param_2 == '\0') goto LAB_004bb1a6;
    uVar5 = 0;
  }
  FUN_005499f0(DAT_0057ba0c,0x18,uVar5,'\x01');
LAB_004bb1a6:
  iVar1 = FUN_00488be0(DAT_0057c670,iVar1);
  if (iVar1 == 0) {
    iVar2 = DAT_00582adc;
  }
  else {
    iVar2 = iVar1 + 8;
  }
  FUN_0052f9b0(param_1,0x1fc9,iVar2);
  FUN_004a66d0(param_1,0x1ff3,iVar1);
  FUN_0052f080(param_1,0x1fd3,&DAT_005683a4,*(undefined4 *)((int)this + iVar4 * 4 + 0xdac));
  iVar1 = *(int *)((int)this + iVar4 * 4 + 0xcc8);
  iVar2 = 0x3c - iVar1;
  if (iVar2 / 2 < 0) {
    pcVar6 = s__d____00568834;
  }
  else {
    pcVar6 = s___d____005692f8;
  }
  FUN_0052f080(param_1,0x1fac,(byte *)pcVar6,iVar2 / 2);
  FUN_0052f080(param_1,0x1fb0,&DAT_005686f4,((int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3) + 0x4b);
  FUN_0052fd70(param_1,0x1fa8,iVar1,0);
  iVar1 = *(int *)((int)DAT_0057c670 + 0x21c);
  if (*(int *)(iVar1 + 0xa4) == 0xc) {
    FUN_005316b0(param_1,0x1fd6);
    FUN_005316b0(param_1,0x1fd9);
    FUN_005316b0(param_1,0x1fda);
    FUN_005316b0(param_1,0x1fdd);
    FUN_005316b0(param_1,0x1fde);
    iVar1 = *(int *)(iVar1 + 0xfc);
    iVar2 = *(int *)(iVar1 + 0x2c);
    iVar1 = FUN_00488be0(DAT_0057c670,*(int *)(iVar1 + 8));
    this_00 = (void *)IDMap_Lookup((void *)(iVar1 + 0x148),iVar2,(int *)0x0);
    if (this_00 == (void *)0x0) {
      FUN_0052f080(param_1,0x1fd7,&DAT_00568310,unaff_EDI);
      FUN_0052f9b0(param_1,0x1fda,&DAT_00579aec);
      iVar1 = 0;
    }
    else {
      FUN_0052f080(param_1,0x1fd7,(byte *)((int)this_00 + 4),unaff_EDI);
      FUN_0052f9b0(param_1,0x1fda,DAT_005829ac);
      iVar1 = FUN_004787f0(this_00,5);
      iVar2 = FUN_00478be0(this_00,extraout_EDX,5);
      iVar3 = FUN_00478320(this_00,5);
      iVar1 = (iVar3 + iVar1 + iVar2) / 3;
    }
    FUN_0052f080(param_1,0x1fde,&DAT_005686f4,iVar1);
  }
  else {
    FUN_0052f9b0(param_1,0x1fd7,DAT_00580b7c);
    FUN_00531740(param_1,0x1fd6);
    FUN_00531740(param_1,0x1fd9);
    FUN_00531740(param_1,0x1fda);
    FUN_00531740(param_1,0x1fdd);
    FUN_00531740(param_1,0x1fde);
  }
  iVar1 = FUN_004dc660(this,0,iVar4);
  FUN_0052f080(param_1,0x1ff1,&DAT_005686f4,iVar1);
  iVar1 = FUN_004dc660(this,0,-1);
  FUN_0052f080(param_1,0x1ff2,&DAT_005686f4,iVar1);
  iVar1 = FUN_004dc660(this,1,iVar4);
  FUN_0052f080(param_1,0x1fe3,&DAT_005686f4,iVar1);
  iVar1 = FUN_004dc660(this,1,-1);
  FUN_0052f080(param_1,0x1fe4,&DAT_005686f4,iVar1);
  iVar1 = FUN_004dc660(this,2,iVar4);
  FUN_0052f080(param_1,0x1fe6,&DAT_005686f4,iVar1);
  iVar1 = FUN_004dc660(this,2,-1);
  FUN_0052f080(param_1,0x1fe7,&DAT_005686f4,iVar1);
  iVar4 = FUN_004dc660(this,3,iVar4);
  FUN_0052f080(param_1,0x1fe9,&DAT_005686f4,iVar4);
  iVar4 = FUN_004dc660(this,3,-1);
  FUN_0052f080(param_1,0x1fea,&DAT_005686f4,iVar4);
  return;
}

