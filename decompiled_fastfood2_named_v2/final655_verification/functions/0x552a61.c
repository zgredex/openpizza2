// rea decompile_all
// name: FUN_00552a61
// address: 0x552a61
// body: available
// range: 0x552a61-0x552b22 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl
FUN_00552a61(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_28 [2];
  int local_20;
  int local_18;
  uint local_14;
  int local_c;
  
  uVar3 = param_1 - 0x76c;
  if (((int)uVar3 < 0x46) || (0x8a < (int)uVar3)) {
    return -1;
  }
  iVar4 = *(int *)(&DAT_005771d0 + param_2 * 4) + param_3;
  if (((uVar3 & 3) == 0) && (2 < param_2)) {
    iVar4 = iVar4 + 1;
  }
  FUN_0055249f();
  local_20 = param_4;
  local_18 = param_2 + -1;
  iVar2 = ((param_4 + (uVar3 * 0x16d + iVar4 + (param_1 + -0x76d >> 2)) * 0x18) * 0x3c + param_5) *
          0x3c + DAT_00576a30 + 0x7c558180 + param_6;
  if ((param_7 == 1) ||
     (((param_7 == -1 && (DAT_00576a34 != 0)) &&
      (local_14 = uVar3, local_c = iVar4, bVar1 = FUN_00552754(local_28),
      CONCAT31(extraout_var,bVar1) != 0)))) {
    iVar2 = iVar2 + _DAT_00576a38;
  }
  return iVar2;
}

