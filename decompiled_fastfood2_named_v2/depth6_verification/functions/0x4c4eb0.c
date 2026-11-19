// rea decompile_all
// name: FUN_004c4eb0
// address: 0x4c4eb0
// body: available
// range: 0x4c4eb0-0x4c4f96 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c4eb0(void *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 1) {
    if (param_2 == 8000) {
      FUN_00482d70(-0x51);
    }
    else if (param_2 == 0x1fee) {
      iVar1 = *(int *)((int)DAT_0057dcf4 + *(int *)((int)DAT_0057dcf8 + 0x48) * 4 + 0xcb0);
      if (999 < iVar1) {
        FUN_004db010(DAT_0057dcf4,*(int *)((int)DAT_0057dcf8 + 0x48),iVar1 + -1000);
        FUN_004c4bd0(param_1);
        return;
      }
    }
    else if (param_2 == 0x1fef) {
      Game_CanAffordWithCurrency(DAT_0057dcf8,0x15,1000.0,'\0',0xffffffff);
      FUN_004db010(DAT_0057dcf4,*(int *)((int)DAT_0057dcf8 + 0x48),
                   *(int *)((int)DAT_0057dcf4 + *(int *)((int)DAT_0057dcf8 + 0x48) * 4 + 0xcb0) +
                   1000);
      FUN_004c4bd0(param_1);
      return;
    }
  }
  else if ((param_3 == 0x23) && (param_2 == -0x1863b)) {
    FUN_004c4bd0(param_1);
    return;
  }
  return;
}

