// rea decompile_all
// name: FUN_004dd090
// address: 0x4dd090
// body: available
// range: 0x4dd090-0x4dd0ef inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004dd090(int param_1)

{
  int iVar1;
  int iVar2;
  void *this;
  void *this_00;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0xfc0);
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      this = (void *)IDMap_Lookup((void *)(param_1 + 0xfac),iVar3,(int *)0x0);
      iVar2 = *(int *)((int)this + 0x8c);
      while (iVar2 = iVar2 + -1, -1 < iVar2) {
        this_00 = (void *)FUN_004d2a60(this,iVar2);
        if (this_00 == (void *)0x0) {
          FUN_004d2a90(this,iVar2);
        }
        else {
          Set_Field168(this_00,this);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}

