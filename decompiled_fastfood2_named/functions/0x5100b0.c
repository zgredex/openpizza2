// rea decompile_all
// name: FUN_005100b0
// address: 0x5100b0
// body: available
// range: 0x5100b0-0x5101ca inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __thiscall FUN_005100b0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  float local_2c;
  int local_20 [8];
  
  local_2c = 0.0;
  if (*(int *)(param_1 + 0x304) == 0) {
    return (float10)0.0;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x304) + 0x14);
  if (param_3 == 0) {
    iVar6 = 0;
    if (0 < iVar1) {
      do {
        iVar2 = IDMap_Lookup(*(void **)(param_1 + 0x304),iVar6,(int *)0x0);
        if (((*(int *)(iVar2 + 0x10) == param_2) || (param_2 == -1)) &&
           ((param_4 == -1 || (*(int *)(iVar2 + 0x14) == param_4)))) {
          local_2c = local_2c + *(float *)(iVar2 + 4);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar1);
      return (float10)local_2c;
    }
  }
  else {
    iVar2 = 0;
    iVar6 = 0;
    piVar4 = local_20;
    do {
      if (*(char *)(iVar6 + param_3) == '\x01') {
        *piVar4 = iVar6;
        iVar2 = iVar2 + 1;
        piVar4 = piVar4 + 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 8);
    iVar6 = 0;
    if (0 < iVar1) {
      do {
        iVar3 = IDMap_Lookup(*(void **)(param_1 + 0x304),iVar6,(int *)0x0);
        if (((*(int *)(iVar3 + 0x10) == param_2) || (param_2 == -1)) && (0 < iVar2)) {
          piVar4 = local_20;
          iVar5 = iVar2;
          do {
            if ((*piVar4 == *(int *)(iVar3 + 0x18)) &&
               ((param_4 == -1 || (*(int *)(iVar3 + 0x14) == param_4)))) {
              local_2c = local_2c + *(float *)(iVar3 + 4);
            }
            piVar4 = piVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar1);
    }
  }
  return (float10)local_2c;
}

