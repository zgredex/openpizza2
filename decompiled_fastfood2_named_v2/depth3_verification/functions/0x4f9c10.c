// rea decompile_all
// name: FUN_004f9c10
// address: 0x4f9c10
// body: available
// range: 0x4f9c10-0x4f9c8f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_004f9c10(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = -1;
  iVar4 = 0;
  iVar1 = *(int *)(*param_1 + 0x24);
  if (0 < *(int *)(DAT_0057c670 + 0x88)) {
    do {
      iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 0x74),iVar4,(int *)0x0);
      if ((((*(int *)(iVar2 + 0xc) == 5) && ((param_1[7] == 0 || (*(char *)(iVar2 + 0x14) == '\0')))
           ) && ((iVar1 == 4 || (*(int *)(iVar2 + 0x10) == iVar1)))) &&
         ((iVar3 = iVar4, param_1[5] != -1 && ((uint)*(byte *)(iVar2 + 0x14) == param_1[6])))) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(DAT_0057c670 + 0x88));
  }
  return iVar3;
}

