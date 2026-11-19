// rea decompile_all
// name: FUN_004a1b00
// address: 0x4a1b00
// body: available
// range: 0x4a1b00-0x4a1c40 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a1b00(void *param_1)

{
  int iVar1;
  void *this;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055889b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00532310(param_1,FUN_004a1af0,0);
  this = operator_new(0x1c);
  local_4 = 0;
  if (this == (void *)0x0) {
    DAT_0057cfc8 = (undefined4 *)0x0;
  }
  else {
    DAT_0057cfc8 = FUN_004013a0(this,0);
  }
  local_4 = 0xffffffff;
  FUN_004a1940(DAT_0057cfc8,1);
  iVar1 = DAT_0057cfc8[5];
  DAT_0057cfcc = 0;
  iVar2 = 0x1f69;
  do {
    FUN_005316b0(param_1,iVar2);
    FUN_005316b0(param_1,iVar2 + 0xd);
    Array_SetField14ByKey(param_1,iVar2 + 0xd,0);
    iVar2 = iVar2 + -1;
  } while (0x1f5d < iVar2);
  FUN_005316b0(param_1,0x462);
  if (iVar1 + -1 < 0xd) {
    FUN_00531740(param_1,0x462);
    iVar2 = 0x1f69;
    if (iVar1 + 0x1f5c < 0x1f69) {
      do {
        FUN_00531740(param_1,iVar2);
        FUN_00531740(param_1,iVar2 + 0xd);
        iVar2 = iVar2 + -1;
      } while (iVar1 + 0x1f5c < iVar2);
    }
  }
  else {
    FUN_0052fd00(param_1,0x462,0,(iVar1 + -0x3d + (iVar1 + -1) * 4) * 0x14,1);
    FUN_0052fd70(param_1,0x462,0,0);
    FUN_0052fce0(param_1,0x462,1);
  }
  FUN_004a1a10(param_1,DAT_0057cfcc);
  ExceptionList = local_c;
  return;
}

