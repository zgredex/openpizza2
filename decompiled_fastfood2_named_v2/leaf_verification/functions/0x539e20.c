// rea decompile_all
// name: FUN_00539e20
// address: 0x539e20
// body: available
// range: 0x539e20-0x539e6c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00539e20(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  piVar1 = *(int **)((int)this + 0x50);
  if (*(int **)((int)this + 0x50) != (int *)0x0) {
    while (piVar2 = piVar1, *piVar2 != param_1) {
      piVar1 = (int *)piVar2[1];
      piVar3 = piVar2;
      if ((int *)piVar2[1] == (int *)0x0) {
        return;
      }
    }
    if (piVar2 != (int *)0x0) {
      if (piVar3 == (int *)0x0) {
        *(int *)((int)this + 0x50) = piVar2[1];
        FUN_0054dd78(piVar2);
        return;
      }
      piVar3[1] = piVar2[1];
      FUN_0054dd78(piVar2);
    }
  }
  return;
}

