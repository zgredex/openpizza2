// rea decompile_all
// name: FUN_00557b98
// address: 0x557b98
// body: available
// range: 0x557b98-0x557c12 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __cdecl FUN_00557b98(uint param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  undefined1 uVar4;
  undefined2 local_8;
  
  uVar1 = param_1;
  if (param_1 < 0x100) {
    if ((*(byte *)((int)&DAT_00585ac0 + param_1 + 1) & 0x20) == 0x20) {
      return (uint)(byte)(&DAT_005859c0)[param_1];
    }
  }
  else {
    uVar4 = (undefined1)param_1;
    bVar2 = (byte)(param_1 >> 8);
    param_1 = CONCAT13(uVar4,CONCAT12(bVar2,(undefined2)param_1));
    if (((*(byte *)((int)&DAT_00585ac0 + bVar2 + 1) & 4) != 0) &&
       (iVar3 = CRT_LCMapStringA(DAT_00585bc4,0x200,(char *)((int)&param_1 + 2),2,&local_8,2,
                                 DAT_005859ac,1), iVar3 != 0)) {
      return (uint)CONCAT11((undefined1)local_8,local_8._1_1_);
    }
  }
  return uVar1;
}

