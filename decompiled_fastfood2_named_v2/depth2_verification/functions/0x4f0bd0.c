// rea decompile_all
// name: Object_FindRecordAtOffset
// address: 0x4f0bd0
// body: available
// range: 0x4f0bd0-0x4f0c52 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Object_FindRecordAtOffset(void *this,int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *local_8 [2];
  
                    /* Depth-2 proposal batch 2/4. */
  FUN_004f0850(this,(int)param_1,(int *)local_8,(int *)&param_1,(undefined4 *)0x0,(undefined4 *)0x0)
  ;
  iVar2 = 0;
  if (0 < *param_1) {
    piVar1 = (int *)(*local_8[0] + 0x10);
    do {
      if ((piVar1[-1] - *(int *)((int)this + 0x24) == param_2) &&
         (*piVar1 - *(int *)((int)this + 0x28) == param_3)) {
        return *local_8[0] + iVar2 * 0x28;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 10;
    } while (iVar2 < *param_1);
  }
  return 0;
}

