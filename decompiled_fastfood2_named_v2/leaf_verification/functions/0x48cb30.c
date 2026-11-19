// rea decompile_all
// name: FUN_0048cb30
// address: 0x48cb30
// body: available
// range: 0x48cb30-0x48cbaa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0048cb30(int param_1)

{
  int iVar1;
  void *this;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = IDMap_Lookup((void *)(param_1 + 4),*(int *)(param_1 + 0x2f4),(int *)0x0);
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,*(int *)(param_1 + 0x2dac),(int *)0x0);
  if (this != (void *)0x0) {
    iVar2 = Get_FieldF0((int)this);
    while (iVar2 = iVar2 + -1, -1 < iVar2) {
      FUN_005311a0(this,iVar2);
    }
    iVar2 = *(int *)(iVar1 + 0xfc0);
    iVar4 = 0;
    if (0 < iVar2) {
      do {
        iVar3 = IDMap_Lookup((void *)(iVar1 + 0xfac),iVar4,(int *)0x0);
        if (iVar3 != 0) {
          FUN_004d2600(iVar3);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
  }
  return;
}

