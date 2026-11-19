// rea decompile_all
// name: FUN_00480d80
// address: 0x480d80
// body: available
// range: 0x480d80-0x480e21 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00480d80(void *this,int param_1)

{
  void *this_00;
  void *this_01;
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  this_00 = *(void **)((int)this + 0x16f0);
  if (0 < *(int *)((int)this_00 + 0x8c)) {
    do {
      this_01 = (void *)FUN_004d2a60(this_00,iVar2);
      if (((-1 < *(int *)((int)this_01 + 0x30)) && (*(int *)((int)this_01 + 0x30) < 8)) &&
         (*(int *)((int)this_01 + 0x88) == *(int *)(param_1 + 0x20))) {
        if ((*(short *)((int)this_01 + 0x40) == 9) &&
           (piVar1 = (int *)FUN_0050ad00((int)this_01), piVar1 != (int *)0x0)) {
          FUN_004f5bb0(*(void **)((int)this + 0x14e0),piVar1);
        }
        *(undefined1 *)((int)this_01 + 0x81) = 1;
        FUN_00507550(this_01,0x14);
        FUN_00504a90(this_01,7);
        Object_SyncChildState(this_01,(int)this,0);
        *(undefined4 *)((int)this_01 + *(int *)((int)this + 0x30) * 4 + 0xac) = 0x14;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this_00 + 0x8c));
  }
  return;
}

