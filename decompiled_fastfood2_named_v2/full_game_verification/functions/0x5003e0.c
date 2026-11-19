// rea decompile_all
// name: Game_UpdateCompanyAccount
// address: 0x5003e0
// body: available
// range: 0x5003e0-0x500469 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Game_UpdateCompanyAccount(void *this,int param_1)

{
  int *piVar1;
  int iVar2;
  double dVar3;
  longlong lVar4;
  
  iVar2 = *(int *)(param_1 + 0x4c);
  if (iVar2 != 0) {
    piVar1 = (int *)((int)this + iVar2 * 0x168 + 0x19c);
    iVar2 = *(int *)((int)this + iVar2 * 0x168 + 0x19c);
    if (0 < iVar2) {
      if (*(double *)(param_1 + 0x108) < 0.0) {
        dVar3 = (double)iVar2;
        if (1000.0 < dVar3) {
          dVar3 = 1000.0;
        }
        *(double *)(param_1 + 0x108) = dVar3 + *(double *)(param_1 + 0x108);
        lVar4 = __ftol();
        *piVar1 = *piVar1 - (int)lVar4;
        return;
      }
      *piVar1 = iVar2 + -0xfa;
      if (iVar2 + -0xfa < 0) {
        *piVar1 = 0;
      }
    }
  }
  return;
}

