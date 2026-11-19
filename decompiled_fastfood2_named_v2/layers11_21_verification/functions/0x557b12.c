// rea decompile_all
// name: FUN_00557b12
// address: 0x557b12
// body: available
// range: 0x557b12-0x557b97 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl FUN_00557b12(LPCSTR param_1)

{
  undefined1 uVar1;
  BOOL BVar2;
  DWORD DVar3;
  uint uVar4;
  byte local_10c;
  byte local_10b;
  
  BVar2 = SetCurrentDirectoryA(param_1);
  if (BVar2 != 0) {
    DVar3 = GetCurrentDirectoryA(0x105,(LPSTR)&local_10c);
    if (DVar3 != 0) {
      if (((local_10c != 0x5c) && (local_10c != 0x2f)) || (local_10c != local_10b)) {
        param_1 = (LPCSTR)CONCAT31(param_1._1_3_,0x3d);
        uVar4 = FUN_00557b98((uint)local_10c);
        uVar1 = SUB41(param_1,0);
        param_1 = (LPCSTR)(uint)CONCAT12(0x3a,CONCAT11((char)uVar4,uVar1));
        BVar2 = SetEnvironmentVariableA((LPCSTR)&param_1,(LPCSTR)&local_10c);
        if (BVar2 == 0) goto LAB_00557b86;
      }
      return 0;
    }
  }
LAB_00557b86:
  DVar3 = GetLastError();
  FUN_00553593(DVar3);
  return 0xffffffff;
}

