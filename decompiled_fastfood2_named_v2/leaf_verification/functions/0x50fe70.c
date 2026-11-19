// rea decompile_all
// name: Game_GetPlayerWeightedStat
// address: 0x50fe70
// body: available
// range: 0x50fe70-0x50feb5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __fastcall Game_GetPlayerWeightedStat(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  float10 fVar4;
  
                    /* Pass 1/2 leaf name re-applied. */
  fVar4 = (float10)0.0;
  piVar1 = (int *)(param_1 + 100);
  iVar3 = 0x56;
  piVar2 = (int *)(DAT_0057c670 + 0xa8);
  do {
    if (0 < *piVar1) {
      fVar4 = (float10)*(double *)(*piVar2 + 0xc0) * (float10)0.001 * (float10)*piVar1 + fVar4;
    }
    piVar2 = piVar2 + 1;
    piVar1 = piVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return fVar4;
}

