// rea decompile_all
// name: Record_GetScreenOffset
// address: 0x534790
// body: available
// range: 0x534790-0x53482e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Record_GetScreenOffset(void *this,int param_1,int *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  
                    /* Depth-1 proposal batch 1. */
  if ((-1 < param_1) && (param_1 < *(int *)((int)this + 0x48))) {
    iVar2 = param_1 * 0x48;
    if (*(int *)(*(int *)((int)this + 0x4c) + iVar2) != -1) {
      iVar3 = *(short *)(*(int *)((int)this + 0x4c) + iVar2 + 0x32) * 2;
      lVar4 = __ftol();
      *param_2 = (int)lVar4 + ((int)*(short *)(*(int *)((int)this + 0x20) + iVar3) >> 2) +
                 (uint)*(ushort *)(*(int *)((int)this + 0x28) + iVar3);
      uVar1 = *(ushort *)
               (*(int *)((int)this + 0x2c) +
               *(short *)(*(int *)((int)this + 0x4c) + iVar2 + 0x32) * 2);
      lVar4 = __ftol();
      *param_3 = (uint)uVar1 + (int)lVar4;
    }
  }
  return;
}

