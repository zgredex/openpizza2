// rea decompile_all
// name: FUN_004f7320
// address: 0x4f7320
// body: available
// range: 0x4f7320-0x4f741b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_004f7320(int param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *local_124;
  int *local_120;
  int local_11c;
  int local_110 [68];
  
  this = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(param_1 + 0x34),(int *)0x0);
  FUN_004f7a00(param_1,local_110 + 4);
  local_120 = local_110 + 4;
  local_110[0] = 0;
  local_110[1] = 0;
  local_11c = 8;
  local_110[2] = 0;
  local_110[3] = 0;
  do {
    iVar3 = 0;
    local_124 = local_120;
    do {
      iVar2 = *local_124;
      iVar4 = 0;
      piVar5 = local_110;
      do {
        iVar1 = Game_GetPlayerQuarterStat(this,iVar3,iVar4);
        iVar4 = iVar4 + 1;
        *piVar5 = *piVar5 + iVar1 * iVar2;
        piVar5 = piVar5 + 1;
      } while (iVar4 < 4);
      iVar3 = iVar3 + 1;
      local_124 = local_124 + 8;
    } while (iVar3 < 8);
    local_120 = local_120 + 1;
    local_11c = local_11c + -1;
  } while (local_11c != 0);
  iVar3 = 0;
  iVar2 = 1;
  piVar5 = local_110;
  do {
    piVar5 = piVar5 + 1;
    if (local_110[0] < *piVar5) {
      local_110[0] = *piVar5;
      iVar3 = iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  *(int *)(param_1 + 0x24) = iVar3;
  return;
}

