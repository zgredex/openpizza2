// rea decompile_all
// name: FUN_00552921
// address: 0x552921
// body: available
// range: 0x552921-0x552a60 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00552921(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 1) {
    if ((param_3 & 3) == 0) {
      iVar1 = *(int *)(&DAT_0057719c + param_4 * 4);
    }
    else {
      iVar1 = *(int *)(&DAT_005771d0 + param_4 * 4);
    }
    iVar2 = (int)(param_3 * 0x16d + -0x63db + iVar1 + 1 + ((int)(param_3 - 1) >> 2)) % 7;
    if (param_6 < iVar2) {
      iVar1 = iVar1 + 1 + (param_5 * 7 - iVar2) + param_6;
    }
    else {
      iVar1 = iVar1 + -6 + (param_5 * 7 - iVar2) + param_6;
    }
    if (param_5 == 5) {
      if ((param_3 & 3) == 0) {
        iVar2 = *(int *)(&DAT_005771a0 + param_4 * 4);
      }
      else {
        iVar2 = *(int *)(&DAT_005771d4 + param_4 * 4);
      }
      if (iVar2 < iVar1) {
        iVar1 = iVar1 + -7;
      }
    }
  }
  else {
    if ((param_3 & 3) == 0) {
      iVar1 = *(int *)(&DAT_0057719c + param_4 * 4);
    }
    else {
      iVar1 = *(int *)(&DAT_005771d0 + param_4 * 4);
    }
    iVar1 = iVar1 + param_7;
  }
  if (param_1 == 1) {
    DAT_00576ac8 = param_3;
    DAT_00576acc = iVar1;
    DAT_00576ad0 = ((param_8 * 0x3c + param_9) * 0x3c + param_10) * 1000 + param_11;
    return;
  }
  DAT_00576ae0 = ((param_8 * 0x3c + param_9) * 0x3c + _DAT_00576a38 + param_10) * 1000 + param_11;
  if (DAT_00576ae0 < 0) {
    DAT_00576ae0 = DAT_00576ae0 + 86400000;
    DAT_00576adc = iVar1 + -1;
  }
  else {
    if (DAT_00576ae0 < 86400000) {
      DAT_00576ad8 = param_3;
      DAT_00576adc = iVar1;
      return;
    }
    DAT_00576ae0 = DAT_00576ae0 + -86400000;
    DAT_00576adc = iVar1 + 1;
  }
  DAT_00576ad8 = param_3;
  return;
}

