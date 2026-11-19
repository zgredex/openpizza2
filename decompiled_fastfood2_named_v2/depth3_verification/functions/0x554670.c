// rea decompile_all
// name: FUN_00554670
// address: 0x554670
// body: available
// range: 0x554670-0x554702 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl FUN_00554670(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (DAT_00586d20 <= param_1) {
LAB_005546f1:
    pDVar3 = FUN_00553606();
    *pDVar3 = 9;
    return 0xffffffff;
  }
  iVar4 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)((&DAT_00586c20)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) goto LAB_005546f1;
  FUN_005545ef(param_1);
  if ((*(byte *)((&DAT_00586c20)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
    hFile = (HANDLE)FUN_005545ad(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    uVar5 = 0;
    if (DVar2 == 0) goto LAB_005546e6;
    pDVar3 = FUN_0055360f();
    *pDVar3 = DVar2;
  }
  pDVar3 = FUN_00553606();
  *pDVar3 = 9;
  uVar5 = 0xffffffff;
LAB_005546e6:
  FUN_0055464e(param_1);
  return uVar5;
}

