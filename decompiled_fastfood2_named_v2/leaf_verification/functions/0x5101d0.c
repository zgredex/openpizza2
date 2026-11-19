// rea decompile_all
// name: FUN_005101d0
// address: 0x5101d0
// body: available
// range: 0x5101d0-0x5102eb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_005101d0(void *this,int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_2c;
  int local_20 [8];
  
  iVar6 = 0;
  local_2c = 0;
  if (*(int *)((int)this + 0x304) == 0) {
    return 0;
  }
  iVar1 = *(int *)(*(int *)((int)this + 0x304) + 0x14);
  if (param_2 == 0) {
    iVar6 = 0;
    if (0 < iVar1) {
      do {
        piVar2 = (int *)IDMap_Lookup(*(void **)((int)this + 0x304),iVar6,(int *)0x0);
        if (((piVar2[4] == param_1) || (param_1 == -1)) &&
           ((param_3 == -1 || (piVar2[5] == param_3)))) {
          local_2c = local_2c + *piVar2;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar1);
      return local_2c;
    }
  }
  else {
    iVar5 = 0;
    iVar3 = 0;
    piVar2 = local_20;
    do {
      if (*(char *)(iVar3 + param_2) == '\x01') {
        *piVar2 = iVar3;
        iVar5 = iVar5 + 1;
        piVar2 = piVar2 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    if (0 < iVar1) {
      do {
        piVar2 = (int *)IDMap_Lookup(*(void **)((int)this + 0x304),iVar6,(int *)0x0);
        if (((piVar2[4] == param_1) || (param_1 == -1)) && (0 < iVar5)) {
          piVar4 = local_20;
          iVar3 = iVar5;
          do {
            if ((*piVar4 == piVar2[6]) && ((param_3 == -1 || (piVar2[5] == param_3)))) {
              local_2c = local_2c + *piVar2;
            }
            piVar4 = piVar4 + 1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar1);
    }
  }
  return local_2c;
}

