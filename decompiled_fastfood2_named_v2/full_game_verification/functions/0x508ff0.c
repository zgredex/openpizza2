// rea decompile_all
// name: Map_DetachObjectFromTile
// address: 0x508ff0
// body: available
// range: 0x508ff0-0x509053 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Map_DetachObjectFromTile(int param_1)

{
  void *this;
  int iVar1;
  
  this = (void *)Game_GetPlayerSubmapValue
                           (DAT_0057c670,*(int *)(*(int *)(param_1 + 0xf4) + 8),
                            *(int *)(*(int *)(param_1 + 0xf4) + 0x2c));
  if (this != (void *)0x0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0xc4) + 0x1c);
    iVar1 = Game_FindRecordByPair
                      (this,*(int *)(param_1 + 0x88) % iVar1,*(int *)(param_1 + 0x88) / iVar1);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x10) == *(int *)(param_1 + 0x164))) {
      *(undefined4 *)(iVar1 + 0x10) = 0;
    }
  }
  return;
}

