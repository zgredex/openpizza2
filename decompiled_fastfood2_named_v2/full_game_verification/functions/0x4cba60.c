// rea decompile_all
// name: Config_WriteRegistryBlock
// address: 0x4cba60
// body: available
// range: 0x4cba60-0x4cbb05 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl Config_WriteRegistryBlock(LPCSTR param_1,BYTE *param_2)

{
  HKEY pHVar1;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558bd8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  Clear_Ptr(&local_10);
  local_4 = 0;
  pHVar1 = RegistryKey_OpenOrCreate
                     (&local_10,(HKEY)0x80000002,s_SOFTWARE_Software2000_Pizza_Conn_00563c5c);
  if (pHVar1 == (HKEY)0x0) {
    local_4 = 0xffffffff;
    RegistryKey_CloseThunk(&local_10);
    ExceptionList = local_c;
    return 0;
  }
  RegistryKey_WriteValue(&local_10,param_1,param_2,0xcc);
  RegistryKey_Close(&local_10);
  local_4 = 0xffffffff;
  RegistryKey_CloseThunk(&local_10);
  ExceptionList = local_c;
  return 1;
}

