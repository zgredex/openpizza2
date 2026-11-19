// rea decompile_all
// name: FUN_0054ac40
// address: 0x54ac40
// body: available
// range: 0x54ac40-0x54acb3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0054ac40(void *this,void *param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  if (*(float *)(param_3 + 0x20) != 0.0) {
    *(float *)(param_3 + 0x1c) =
         (float)param_2 * *(float *)(param_3 + 0x20) * 0.001 + *(float *)(param_3 + 0x1c);
    lVar3 = __ftol();
    iVar1 = *(int *)(param_3 + 0xc);
    iVar2 = (int)lVar3;
    if ((int)lVar3 < iVar1) {
      *(undefined4 *)(param_3 + 0x20) = 0;
      *(float *)(param_3 + 0x1c) = (float)iVar1;
      iVar2 = iVar1;
    }
    UI_MoveChildToPosition(param_1,iVar2,*(int *)((int)this + 0x24));
  }
  return;
}

