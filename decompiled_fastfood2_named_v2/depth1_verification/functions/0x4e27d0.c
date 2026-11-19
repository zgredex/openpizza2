// rea decompile_all
// name: Game_CountPlayerObjectsByType
// address: 0x4e27d0
// body: available
// range: 0x4e27d0-0x4e285b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Game_CountPlayerObjectsByType(void *this,int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_4;
  
                    /* Depth-1 proposal batch 2. */
  iVar3 = 0;
  local_4 = 0;
  iVar2 = 0;
  if (0 < *(int *)((int)this + 0x1cc)) {
    do {
      piVar1 = (int *)FUN_004017f0((void *)((int)this + 0x1b8),iVar3,(int *)0x0);
      if (piVar1[1] == param_2) {
        iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 0x3c),*piVar1,(int *)0x0);
        if (((*(int *)(iVar2 + 0x74) != 0) && (*(int *)(iVar2 + 0xf4) == *(int *)(param_1 + 0x16f0))
            ) && ((*(int *)(iVar2 + 0xa4) == param_3 || (param_3 == -1)))) {
          local_4 = local_4 + 1;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)((int)this + 0x1cc));
    iVar2 = local_4;
  }
  return iVar2;
}

