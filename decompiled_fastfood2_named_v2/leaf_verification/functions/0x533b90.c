// rea decompile_all
// name: FUN_00533b90
// address: 0x533b90
// body: available
// range: 0x533b90-0x533c50 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00533b90(void *this,int param_1,int param_2)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  
  iVar3 = param_1 * 0x48;
  puVar1 = (ushort *)
           (*(int *)((int)this + 0x50) + *(int *)(*(int *)((int)this + 0x4c) + iVar3) * 0x98 +
           param_2 * 6);
  if ((char)puVar1[2] == -1) {
    Record_ClearFlags48(this,param_1);
    return;
  }
  *(ushort *)(*(int *)((int)this + 0x4c) + iVar3 + 0x32) = *puVar1;
  *(undefined2 *)(*(int *)((int)this + 0x4c) + 0x36 + iVar3) = 0;
  *(short *)(*(int *)((int)this + 0x4c) + 0x34 + iVar3) = (short)param_2;
  iVar2 = *(int *)((int)this + 0x4c);
  lVar4 = __ftol();
  *(short *)(iVar2 + iVar3 + 0x3a) = (short)lVar4;
  if (puVar1[1] < *puVar1) {
    *(undefined1 *)(*(int *)((int)this + 0x4c) + 0x38 + iVar3) = 0xff;
    return;
  }
  *(undefined1 *)(*(int *)((int)this + 0x4c) + 0x38 + iVar3) = 1;
  return;
}

