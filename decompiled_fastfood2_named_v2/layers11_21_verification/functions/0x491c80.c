// rea decompile_all
// name: Chart_DrawGroupMatrix
// address: 0x491c80
// body: available
// range: 0x491c80-0x491d37 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Chart_DrawGroupMatrix(void *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *local_104;
  int local_100 [64];
  
                    /* Builds an 8x8 group matrix and hands it to the icon renderer. */
  if (param_4 != 0) {
    iVar3 = 0x636;
    piVar4 = local_100;
    for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar4 = 0;
      piVar4 = piVar4 + 1;
    }
    local_104 = local_100;
    piVar4 = (int *)(param_4 + 0x189c);
    piVar5 = local_100 + param_3;
    do {
      iVar1 = 0;
      *piVar5 = piVar4[-1] + *piVar4;
      piVar2 = local_104;
      do {
        if (iVar1 != param_3) {
          *piVar2 = *(int *)(param_4 + (iVar3 + iVar1) * 4);
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar1 < 6);
      iVar3 = iVar3 + 6;
      piVar5 = piVar5 + 8;
      piVar4 = piVar4 + 2;
      local_104 = local_104 + 8;
    } while (iVar3 < 0x666);
    Chart_DrawCustomerGroups(param_1,param_2,param_3,local_100);
  }
  return;
}

