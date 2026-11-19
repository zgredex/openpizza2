// rea decompile_all
// name: FUN_00479a40
// address: 0x479a40
// body: available
// range: 0x479a40-0x479aac inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00479a40(void *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = FUN_0047cc10(param_1,1);
  iVar3 = FUN_0047cc10(param_1,2);
  iVar4 = FUN_0047cc10(param_1,4);
  iVar5 = FUN_0047cc10(param_1,3);
  iVar6 = FUN_0047ccd0(param_1,3);
  iVar2 = iVar2 + iVar3 + iVar4 + iVar5 + iVar6;
  piVar1 = (int *)((int)param_1 + 0x1868);
  if (iVar2 < 1) {
    *piVar1 = 0;
    FUN_00477100(piVar1);
    return;
  }
  *piVar1 = (iVar6 * 100) / iVar2;
  FUN_00477100(piVar1);
  return;
}

