// rea decompile_all
// name: RenovationScreen_UpdateCost
// address: 0x4922d0
// body: available
// range: 0x4922d0-0x49238d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl RenovationScreen_UpdateCost(void *param_1)

{
  int iVar1;
  
                    /* Computes and displays the renovation price. */
  iVar1 = DAT_0057c6c4 + 5 + DAT_0057c6c0 * 4;
  _DAT_0057c6c8 = iVar1 * 0xfa;
  if (DAT_0057c6b8 == 0) {
    _DAT_0057c6c8 = (iVar1 * 2000) / 10;
  }
  else if (DAT_0057c6b8 == 2) {
    _DAT_0057c6c8 = (int)(iVar1 * 0x9c4 + (iVar1 * 0x9c4 >> 0x1f & 7U)) >> 3;
  }
  iVar1 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(iVar1 + 0xd4) == 0) {
    if (*(int *)(iVar1 + 0x1b8) != 0) {
      _DAT_0057c6c8 = (_DAT_0057c6c8 * 0xf) / 10;
    }
  }
  else {
    _DAT_0057c6c8 = 0;
  }
  Gadget_SetTextf(param_1,0x1f50,&DAT_005683a4,_DAT_0057c6c8);
  return;
}

