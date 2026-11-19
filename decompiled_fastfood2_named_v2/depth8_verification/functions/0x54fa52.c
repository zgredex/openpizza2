// rea decompile_all
// name: FUN_0054fa52
// address: 0x54fa52
// body: available
// range: 0x54fa52-0x54fb1d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __thiscall FUN_0054fa52(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;
  
  uVar1 = param_1;
  if (DAT_005857cc == 0) {
    if ((int)param_1 < 0x61) {
      return param_1;
    }
    if ((int)param_1 < 0x7b) {
      return param_1 - 0x20;
    }
    return param_1;
  }
  local_8 = this;
  if ((int)param_1 < 0x100) {
    if (DAT_00576cf0 < 2) {
      uVar2 = (byte)PTR_DAT_00576ae4[param_1 * 2] & 2;
    }
    else {
      uVar2 = CRT_Mbtowc(this,param_1,2);
    }
    if (uVar2 == 0) {
      return uVar1;
    }
  }
  if ((PTR_DAT_00576ae4[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
    param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
    iVar3 = 1;
  }
  else {
    uVar2 = param_1 >> 0x10;
    param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
    param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
    iVar3 = 2;
  }
  iVar3 = FUN_00553710(DAT_005857cc,0x200,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
  if (iVar3 == 0) {
    return uVar1;
  }
  if (iVar3 == 1) {
    return (uint)local_8 & 0xff;
  }
  return (uint)local_8 & 0xffff;
}

