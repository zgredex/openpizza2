// rea decompile_all
// name: FUN_0050b370
// address: 0x50b370
// body: available
// range: 0x50b370-0x50b456 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall FUN_0050b370(int param_1)

{
  int *piVar1;
  void *this;
  int iVar2;
  int iVar3;
  void *this_00;
  int iVar4;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_1 + 200);
  if (piVar1 != (int *)0x0) {
    this = *(void **)(param_1 + 0xf4);
    Record_GetTwoFloats48((void *)piVar1[0x16],*piVar1,&local_c,&local_4);
    iVar4 = 0;
    if (0 < *(int *)((int)this + 0x8c)) {
      do {
        iVar2 = Game_MapRecordToGlobal(this,iVar4);
        if ((*(int *)(iVar2 + 0x30) == 0x20) && (*(int *)(iVar2 + 0x38) == 0x20)) {
          piVar1 = *(int **)(iVar2 + 200);
          if (piVar1 == (int *)0x0) {
            iVar3 = -1;
            this_00 = (void *)0x0;
          }
          else {
            iVar3 = *piVar1;
            this_00 = (void *)piVar1[0x16];
          }
          Record_GetTwoFloats48(this_00,iVar3,&local_10,&local_8);
          if ((local_10 - local_c) * (local_10 - local_c) +
              (local_8 - local_4) * (local_8 - local_4) * 4 <
              (int)((-(uint)(*(int *)(iVar2 + 0xa4) != 2) & 0xfffff510) + 0x1900)) {
            return 1;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)((int)this + 0x8c));
    }
  }
  return 0;
}

