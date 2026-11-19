// rea decompile_all
// name: FUN_004bf730
// address: 0x4bf730
// body: available
// range: 0x4bf730-0x4bf97a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004bf730(void *param_1)

{
  void *this;
  void *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  this = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  FUN_0052f080(param_1,0x1f93,(byte *)s__s__d_00568964,DAT_00580d98);
  this_00 = *(void **)((int)this + 0x1d8);
  iVar1 = FUN_004d2ae0(this_00,0x1f);
  FUN_0052f080(param_1,0x1f59,&DAT_005686f4,iVar1);
  iVar2 = FUN_004e1db0(this,0x1f);
  FUN_0052f080(param_1,0x1f58,&DAT_005686f4,iVar2);
  iVar3 = FUN_004e1d40(this,0x1f);
  iVar4 = FUN_004e3730(this,0x1f);
  if (iVar3 < iVar4) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0xff;
  }
  FUN_0052f910(param_1,0x1f95,uVar5);
  FUN_0052f080(param_1,0x1f95,&DAT_005686f4,iVar4);
  FUN_0052f080(param_1,0x1f57,&DAT_005686f4,(iVar3 - iVar2) - iVar1);
  iVar1 = FUN_004d2ae0(this_00,0x1e);
  FUN_0052f080(param_1,0x1f54,&DAT_005686f4,iVar1);
  iVar2 = FUN_004e1db0(this,0x1e);
  FUN_0052f080(param_1,0x1f52,&DAT_005686f4,iVar2);
  iVar3 = FUN_004e1d40(this,0x1e);
  iVar4 = FUN_004e3730(this,0x1e);
  if (iVar3 < iVar4) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0xff;
  }
  FUN_0052f910(param_1,0x1f94,uVar5);
  FUN_0052f080(param_1,0x1f94,&DAT_005686f4,iVar4);
  FUN_0052f080(param_1,0x1f50,&DAT_005686f4,(iVar3 - iVar2) - iVar1);
  iVar1 = FUN_004d2ae0(this_00,0x1d);
  FUN_0052f080(param_1,0x1f8e,&DAT_005686f4,iVar1);
  iVar2 = FUN_004e1db0(this,0x1d);
  FUN_0052f080(param_1,0x1f8d,&DAT_005686f4,iVar2);
  iVar3 = FUN_004e1d40(this,0x1d);
  iVar4 = FUN_004e3730(this,0x1d);
  if (iVar3 < iVar4) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0xff;
  }
  FUN_0052f910(param_1,0x1f96,uVar5);
  FUN_0052f080(param_1,0x1f96,&DAT_005686f4,iVar4);
  FUN_0052f080(param_1,0x1f8c,&DAT_005686f4,(iVar3 - iVar2) - iVar1);
  return;
}

