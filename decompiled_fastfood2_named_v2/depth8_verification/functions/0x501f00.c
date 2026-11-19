// rea decompile_all
// name: FUN_00501f00
// address: 0x501f00
// body: available
// range: 0x501f00-0x501f81 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00501f00(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    iVar1 = FUN_00488be0(DAT_0057c670,iVar3);
    if (iVar1 != 0) {
      iVar1 = FUN_004ddcc0(iVar1);
      iVar2 = iVar2 + *(int *)(iVar1 + 0xa0);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 6);
  iVar3 = FUN_004ddcc0(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200)
                      );
  if (0 < iVar2) {
    iVar2 = *(int *)(iVar3 + 0xa0) * (int)(100 / (longlong)iVar2);
    if (0x3c < iVar2) {
      return 3;
    }
    if (0x30 < iVar2) {
      return 2;
    }
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}

