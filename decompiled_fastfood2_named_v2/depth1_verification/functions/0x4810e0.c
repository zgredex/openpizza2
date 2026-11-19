// rea decompile_all
// name: Game_FreeSubmapObjects
// address: 0x4810e0
// body: available
// range: 0x4810e0-0x481131 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Game_FreeSubmapObjects(int param_1)

{
  int iVar1;
  LPVOID pvVar2;
  int iVar3;
  
                    /* Depth-1 proposal batch 2. */
  if (*(int *)(param_1 + 0x1a28) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x1a28) + 0x14);
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        pvVar2 = (LPVOID)FUN_004017f0(*(void **)(param_1 + 0x1a28),iVar3,(int *)0x0);
        FUN_0054dd78(pvVar2);
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
    if (*(undefined4 **)(param_1 + 0x1a28) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x1a28))(1);
    }
    *(undefined4 *)(param_1 + 0x1a28) = 0;
  }
  return;
}

