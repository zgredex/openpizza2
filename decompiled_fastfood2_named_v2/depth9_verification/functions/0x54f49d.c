// rea decompile_all
// name: CRT_FindNext
// address: 0x54f49d
// body: available
// range: 0x54f49d-0x54f564 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl CRT_FindNext(HANDLE param_1,uint *param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  uint uVar4;
  _WIN32_FIND_DATAA local_144;
  
                    /* Wraps FindNextFileA and refills a CRT find-data record. */
  BVar1 = FindNextFileA(param_1,&local_144);
  if (BVar1 != 0) {
    *param_2 = -(uint)(local_144.dwFileAttributes != 0x80) & local_144.dwFileAttributes;
    uVar4 = ___timet_from_ft(&local_144.ftCreationTime);
    param_2[1] = uVar4;
    uVar4 = ___timet_from_ft(&local_144.ftLastAccessTime);
    param_2[2] = uVar4;
    uVar4 = ___timet_from_ft(&local_144.ftLastWriteTime);
    param_2[3] = uVar4;
    param_2[4] = local_144.nFileSizeLow;
    FUN_00553620(param_2 + 5,(uint *)local_144.cFileName);
    return 0;
  }
  DVar2 = GetLastError();
  if (DVar2 < 2) {
LAB_0054f4d7:
    pDVar3 = FUN_00553606();
    *pDVar3 = 0x16;
  }
  else {
    if (3 < DVar2) {
      if (DVar2 == 8) {
        pDVar3 = FUN_00553606();
        *pDVar3 = 0xc;
        return 0xffffffff;
      }
      if (DVar2 != 0x12) goto LAB_0054f4d7;
    }
    pDVar3 = FUN_00553606();
    *pDVar3 = 2;
  }
  return 0xffffffff;
}

