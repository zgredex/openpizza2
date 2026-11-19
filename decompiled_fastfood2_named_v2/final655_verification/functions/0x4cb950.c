// rea decompile_all
// name: FUN_004cb950
// address: 0x4cb950
// body: available
// range: 0x4cb950-0x4cba50 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl FUN_004cb950(LPCSTR param_1,BYTE *param_2)

{
  HKEY pHVar1;
  LPBYTE pBVar2;
  uint uVar3;
  LPBYTE pBVar4;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558bb8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00403190(&local_14);
  local_4 = 0;
  pHVar1 = FUN_004031b0(&local_14,(HKEY)0x80000002,s_SOFTWARE_Software2000_Pizza_Conn_00563c5c);
  if (pHVar1 == (HKEY)0x0) {
    local_4 = 0xffffffff;
    thunk_FUN_004032e0(&local_14);
    ExceptionList = local_c;
    return 0;
  }
  pBVar2 = FUN_00403200(&local_14,param_1,&local_10);
  FUN_004032e0(&local_14);
  if (pBVar2 == (LPBYTE)0x0) {
    local_4 = 0xffffffff;
    thunk_FUN_004032e0(&local_14);
    ExceptionList = local_c;
    return 0;
  }
  if (0xcb < local_10) {
    local_10 = 0xcc;
  }
  pBVar4 = pBVar2;
  for (uVar3 = local_10 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)param_2 = *(undefined4 *)pBVar4;
    pBVar4 = pBVar4 + 4;
    param_2 = param_2 + 4;
  }
  for (local_10 = local_10 & 3; local_10 != 0; local_10 = local_10 - 1) {
    *param_2 = *pBVar4;
    pBVar4 = pBVar4 + 1;
    param_2 = param_2 + 1;
  }
  FUN_0054dd78(pBVar2);
  local_4 = 0xffffffff;
  thunk_FUN_004032e0(&local_14);
  ExceptionList = local_c;
  return 1;
}

