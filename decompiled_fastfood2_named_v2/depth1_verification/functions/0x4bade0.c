// rea decompile_all
// name: FUN_004bade0
// address: 0x4bade0
// body: available
// range: 0x4bade0-0x4bb0b2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004bade0(void *param_1,char param_2)

{
  void *this;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_c [3];
  
  local_c[0] = DAT_00581fe8;
  local_c[1] = DAT_00582aec;
  local_c[2] = DAT_00582fbc;
  if (param_2 != '\0') {
    FUN_005499f0(DAT_0057ba0c,10,0,'\x01');
  }
  this = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                              (int *)0x0);
  iVar4 = *(int *)((int)DAT_0057c670 + 0x21c);
  iVar1 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  iVar3 = *(int *)((int)this + *(int *)(iVar1 + 0x48) * 4 + 0xd40);
  FUN_0052fd70(param_1,0x1fa8,iVar3,0);
  iVar3 = (100 - iVar3) / 3;
  if (iVar3 == 0) {
    FUN_0052f9b0(param_1,0x1fb0,&DAT_00569308);
  }
  else {
    FUN_0052f080(param_1,0x1fb0,(byte *)s___d____00569300,iVar3);
  }
  iVar1 = Stats_GetPlayerSharePercent(this,*(int *)(iVar1 + 0x48));
  FUN_0052f080(param_1,0x1fac,(byte *)s__d____00568834,iVar1);
  iVar1 = *(int *)(iVar4 + 0xa4);
  iVar3 = *(int *)(iVar4 + 0xfc);
  iVar2 = FUN_00488be0(DAT_0057c670,*(int *)(iVar3 + 8));
  if (iVar2 != 0) {
    iVar3 = FUN_004017f0((void *)(iVar2 + 0x148),*(int *)(iVar3 + 0x2c),(int *)0x0);
    if ((iVar3 != 0) && (iVar1 == 0xc)) {
      FUN_0052f9b0(param_1,0x1fef,local_c[*(int *)(iVar4 + 0x10c)]);
      FUN_0052f9b0(param_1,0x1fbc,iVar3 + 4);
      if (*(int *)(iVar4 + 0x108) == 2) {
        uVar5 = DAT_00580ebc;
      }
      else {
        uVar5 = DAT_00582220;
      }
      iVar4 = 0x1fed;
      goto LAB_004baf87;
    }
  }
  FUN_0052f9b0(param_1,0x1fed,DAT_00582adc);
  FUN_0052f9b0(param_1,0x1fbc,DAT_00582adc);
  iVar4 = 0x1fef;
  uVar5 = DAT_00580b7c;
LAB_004baf87:
  FUN_0052f9b0(param_1,iVar4,uVar5);
  FUN_0052f080(param_1,0x1fd9,&DAT_005686f4,*(undefined4 *)((int)this + 0xd58));
  FUN_0052f080(param_1,0x1fda,&DAT_005686f4,*(undefined4 *)((int)this + 0xd5c));
  FUN_0052f080(param_1,0x1fdc,&DAT_005686f4,*(undefined4 *)((int)this + 0xd60));
  FUN_0052f080(param_1,0x1fdd,&DAT_005686f4,*(undefined4 *)((int)this + 0xd64));
  FUN_0052f080(param_1,0x1fdf,&DAT_005686f4,*(undefined4 *)((int)this + 0xd68));
  FUN_0052f080(param_1,0x1fe0,&DAT_005686f4,*(undefined4 *)((int)this + 0xd6c));
  FUN_0052f080(param_1,0x1fe2,&DAT_005686f4,*(undefined4 *)((int)this + 0xd70));
  FUN_0052f080(param_1,0x1fe3,&DAT_005686f4,*(undefined4 *)((int)this + 0xd74));
  FUN_0052f080(param_1,0x1fe5,&DAT_005686f4,*(undefined4 *)((int)this + 0xd78));
  FUN_0052f080(param_1,0x1fe6,&DAT_005686f4,*(undefined4 *)((int)this + 0xd7c));
  FUN_0052f080(param_1,0x1fe8,&DAT_005686f4,*(undefined4 *)((int)this + 0xd80));
  FUN_0052f080(param_1,0x1fe9,&DAT_005686f4,*(undefined4 *)((int)this + 0xd84));
  return;
}

