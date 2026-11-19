// rea decompile_all
// name: FUN_0050bba0
// address: 0x50bba0
// body: available
// range: 0x50bba0-0x50bbef inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall FUN_0050bba0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x164);
  iVar2 = FUN_00486910(DAT_0057c670,-1);
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = FUN_004017f0((void *)((int)DAT_0057c670 + 0x3c),iVar4,(int *)0x0);
      if ((*(int *)(iVar3 + 0x30) == 0x1d) && (*(int *)(iVar3 + 0x10c) == iVar1)) {
        return 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  return 0;
}

