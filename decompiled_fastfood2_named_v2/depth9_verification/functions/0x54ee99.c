// rea decompile_all
// name: CRT_Strlwr
// address: 0x54ee99
// body: available
// range: 0x54ee99-0x54efcc inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Variable defined which should be unmapped: param_1 */

uint * __cdecl CRT_Strlwr(uint *param_1)

{
  char cVar1;
  size_t _Size;
  int iVar2;
  uint *puVar3;
  bool bVar4;
  LPWSTR local_c;
  
                    /* Lowercases an ANSI string in place, using the CRT locale. */
  local_c = (LPWSTR)0x0;
  if (DAT_005857cc == 0) {
    cVar1 = (char)*param_1;
    puVar3 = param_1;
    while (cVar1 != '\0') {
      cVar1 = (char)*puVar3;
      if (('@' < cVar1) && (cVar1 < '[')) {
        *(char *)puVar3 = cVar1 + ' ';
      }
      puVar3 = (uint *)((int)puVar3 + 1);
      cVar1 = *(char *)puVar3;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_00585be8);
    bVar4 = DAT_00585be4 == 0;
    if (!bVar4) {
      InterlockedDecrement((LONG *)&DAT_00585be8);
      FUN_0055395d(0x13);
    }
    if (DAT_005857cc == 0) {
      if (bVar4) {
        InterlockedDecrement((LONG *)&DAT_00585be8);
      }
      else {
        FUN_005539be(0x13);
      }
      cVar1 = (char)*param_1;
      puVar3 = param_1;
      while (cVar1 != '\0') {
        cVar1 = (char)*puVar3;
        if (('@' < cVar1) && (cVar1 < '[')) {
          *(char *)puVar3 = cVar1 + ' ';
        }
        puVar3 = (uint *)((int)puVar3 + 1);
        cVar1 = *(char *)puVar3;
      }
    }
    else {
      _Size = FUN_00553710(DAT_005857cc,0x100,(char *)param_1,-1,(LPWSTR)0x0,0,0,1);
      if (((_Size != 0) && (local_c = _malloc(_Size), local_c != (LPWSTR)0x0)) &&
         (iVar2 = FUN_00553710(DAT_005857cc,0x100,(char *)param_1,-1,local_c,_Size,0,1), iVar2 != 0)
         ) {
        FUN_00553620(param_1,(uint *)local_c);
      }
      if (bVar4) {
        InterlockedDecrement((LONG *)&DAT_00585be8);
      }
      else {
        FUN_005539be(0x13);
      }
      FUN_00551005(local_c);
    }
  }
  return param_1;
}

