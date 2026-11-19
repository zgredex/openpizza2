// rea decompile_all
// name: Company_OpenBranchInHomeCity
// address: 0x4fc290
// body: available
// range: 0x4fc290-0x4fc3ae inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Company_OpenBranchInHomeCity(void *this,int param_1)

{
  void *this_00;
  uint uVar1;
  int iVar2;
  void *this_01;
  byte *this_02;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Opens a player branch in the home city and charges its fee. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a18b;
  local_c = ExceptionList;
  this_00 = *(void **)((int)this + param_1 * 0x168 + 0x70);
  ExceptionList = &local_c;
  uVar1 = FUN_004e0e90(this_00,2);
  if (uVar1 == 0xffffffff) {
    ExceptionList = local_c;
    return 1;
  }
  iVar3 = *(int *)((int)this_00 + 0x15c) + 0x10;
  if (0x14 < iVar3) {
    iVar3 = 0x14;
  }
  iVar2 = FUN_004ddde0((int)this_00);
  if (iVar3 <= iVar2) {
    ExceptionList = local_c;
    return 1;
  }
  this_01 = operator_new(0x330);
  local_4 = 0;
  if (this_01 == (void *)0x0) {
    this_02 = (byte *)0x0;
  }
  else {
    this_02 = Recipe_CreateGenerated
                        (this_01,*(int *)((int)this_00 + 0x48),uVar1,2,
                         *(float *)((int)DAT_0057c670 + 0x2f4),-1);
  }
  local_4 = 0xffffffff;
  iVar3 = FUN_00488bc0(DAT_0057c670,(int)this_00);
  FUN_00513a90(this_02,iVar3);
  *(uint *)(this_02 + 0x308) = uVar1;
  FUN_004014b0((void *)((int)this_00 + 0x110),this_02);
  FUN_004e0b60(this_00,9,500.0,'\0',0xffffffff);
  ExceptionList = local_c;
  return 4;
}

