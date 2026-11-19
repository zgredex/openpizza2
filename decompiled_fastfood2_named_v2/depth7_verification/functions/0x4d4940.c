// rea decompile_all
// name: FUN_004d4940
// address: 0x4d4940
// body: available
// range: 0x4d4940-0x4d4a17 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall FUN_004d4940(void *this,uint param_1)

{
  void *this_00;
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *this_01;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558e6b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 == 0xffffffff) {
    ExceptionList = &local_c;
    param_1 = FUN_004034d0(0,3);
  }
  this_00 = operator_new(0x828);
  this_01 = (undefined4 *)0x0;
  local_4 = 0;
  if (this_00 != (void *)0x0) {
    this_01 = FUN_004d3730(this_00,*(int *)((int)this + 0xc1c),param_1);
  }
  local_4 = 0xffffffff;
  if ((DAT_0057bb20 == '\0') && (*(int *)((int)this + 0x340) == 7)) {
    uVar1 = FUN_004034d0(5,0x14);
    Person_SetMotivation(this_01,uVar1);
  }
  puVar2 = operator_new(8);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[1] = 0xffffffff;
    *puVar2 = this_01;
  }
  iVar3 = FUN_004d3910((int)this_01);
  FUN_0050ac30(iVar3);
  FUN_004014b0((void *)((int)this + 0xfc8),puVar2);
  ExceptionList = local_c;
  return puVar2;
}

