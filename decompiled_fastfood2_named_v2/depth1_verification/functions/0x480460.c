// rea decompile_all
// name: FUN_00480460
// address: 0x480460
// body: available
// range: 0x480460-0x4805c7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_00480460(void *this,int param_1,int *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  float local_32c;
  int local_328;
  
  iVar5 = 0;
  local_328 = 0;
  local_32c = 0.0;
  iVar1 = FUN_00480050((int)this);
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = FUN_004017f0((void *)((int)this + 0x19e0),iVar5,(int *)0x0);
      iVar2 = *(int *)(iVar2 + 0x20);
      iVar3 = FUN_004f0cc0(*(void **)((int)this + 0x14e0),1,
                           (int)*(short *)(*(int *)(*(int *)((int)*(void **)((int)this + 0x14e0) +
                                                            0x4c) + iVar2 * 0xc + 8) + 0x24));
      iVar4 = Map_FindShortestPath();
      if ((iVar5 == 0) || (iVar4 < (int)local_32c)) {
        *param_2 = iVar2;
        local_32c = (float)iVar4;
        local_328 = iVar3;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
    iVar2 = local_328;
    if (local_328 != 0) {
      local_32c = (float)(*(int *)(local_328 + 0x10) - *(int *)(param_1 + 0x10));
      if (local_32c == 0.0) {
        local_32c = 1.0;
      }
      fpatan((float10)(*(int *)(local_328 + 0xc) - *(int *)(param_1 + 0xc)) / (float10)local_32c,
             (float10)1);
      lVar6 = __ftol();
      *param_3 = -(-(int)lVar6 - 1U & 7) & 7;
    }
  }
  return iVar2;
}

