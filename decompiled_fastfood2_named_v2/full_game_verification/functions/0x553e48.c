// rea decompile_all
// name: CRT_SetArgv
// address: 0x553e48
// body: available
// range: 0x553e48-0x553ee0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_SetArgv(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_00586d2c == 0) {
    FUN_00556979();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_005857e4,0x104);
  _DAT_00585640 = &DAT_005857e4;
  pbVar2 = &DAT_005857e4;
  if (*DAT_00586d24 != 0) {
    pbVar2 = DAT_00586d24;
  }
  ParseCommandLine(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  ParseCommandLine(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_00585628 = puVar1;
  _DAT_00585624 = local_8 + -1;
  return;
}

