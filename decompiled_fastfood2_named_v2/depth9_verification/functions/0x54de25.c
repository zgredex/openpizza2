// rea decompile_all
// name: FUN_0054de25
// address: 0x54de25
// body: available
// range: 0x54de25-0x54dea2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __cdecl FUN_0054de25(int param_1)

{
  SIZE_T SVar1;
  int *piVar2;
  
  CRT_LockExit();
  SVar1 = CRT_Msize(DAT_00586d34);
  if (SVar1 < (uint)((int)DAT_00586d30 + (4 - (int)DAT_00586d34))) {
    SVar1 = CRT_Msize(DAT_00586d34);
    piVar2 = CRT_Realloc(DAT_00586d34,(uint *)(SVar1 + 0x10));
    if (piVar2 == (int *)0x0) {
      param_1 = 0;
      goto LAB_0054de9a;
    }
    DAT_00586d30 = piVar2 + ((int)DAT_00586d30 - (int)DAT_00586d34 >> 2);
    DAT_00586d34 = piVar2;
  }
  *DAT_00586d30 = param_1;
  DAT_00586d30 = DAT_00586d30 + 1;
LAB_0054de9a:
  FUN_0054f3ad();
  return param_1;
}

