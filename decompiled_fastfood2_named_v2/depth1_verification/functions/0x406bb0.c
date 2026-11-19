// rea decompile_all
// name: Settings_LoadFromRegistry
// address: 0x406bb0
// body: available
// range: 0x406bb0-0x406cc9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool Settings_LoadFromRegistry(void)

{
  HKEY pHVar1;
  LPBYTE pBVar2;
  LPBYTE pBVar3;
  uint uVar4;
  BYTE *pBVar5;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Depth-1 proposal batch 1. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557d58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00403190(&local_14);
  local_4 = 0;
  pHVar1 = FUN_004031b0(&local_14,(HKEY)0x80000002,s_SOFTWARE_Software2000_Pizza_Conn_00563c5c);
  if (pHVar1 == (HKEY)0x0) {
    local_4 = 0xffffffff;
    thunk_FUN_004032e0(&local_14);
    ExceptionList = local_c;
    return false;
  }
  pBVar2 = FUN_00403200(&local_14,s_Options_00563c54,&local_10);
  if (0x163 < local_10) {
    local_10 = 0x164;
  }
  pBVar3 = pBVar2;
  pBVar5 = (BYTE *)&DAT_0057b8a8;
  for (uVar4 = local_10 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pBVar5 = *(undefined4 *)pBVar3;
    pBVar3 = pBVar3 + 4;
    pBVar5 = pBVar5 + 4;
  }
  for (local_10 = local_10 & 3; local_10 != 0; local_10 = local_10 - 1) {
    *pBVar5 = *pBVar3;
    pBVar3 = pBVar3 + 1;
    pBVar5 = pBVar5 + 1;
  }
  if (pBVar2 == (LPBYTE)0x0) {
    FUN_0054dd78((LPVOID)0x0);
  }
  pBVar3 = FUN_00403200(&local_14,s_Sound_00563c4c,&local_10);
  if (pBVar3 != (LPBYTE)0x0) {
    DAT_00575090 = *(undefined4 *)pBVar3;
    DAT_00575094 = *(undefined4 *)(pBVar3 + 4);
    DAT_00575098 = *(undefined4 *)(pBVar3 + 8);
    DAT_0057509c = *(undefined4 *)(pBVar3 + 0xc);
  }
  FUN_004032e0(&local_14);
  local_4 = 0xffffffff;
  thunk_FUN_004032e0(&local_14);
  ExceptionList = local_c;
  return pBVar2 != (LPBYTE)0x0;
}

