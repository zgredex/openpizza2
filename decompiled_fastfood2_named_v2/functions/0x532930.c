// rea decompile_all
// name: FUN_00532930
// address: 0x532930
// body: available
// range: 0x532930-0x532a24 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int * __thiscall FUN_00532930(void *this,int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_8;
  
  iVar1 = *(int *)((int)this + 0x1c);
  piVar5 = (int *)0x0;
  iVar6 = param_1 - *(int *)((int)this + 0x18);
  local_8 = *(int *)((int)this + 0xf0) + -1;
  if (-1 < local_8) {
    do {
      piVar2 = *(int **)(*(int *)((int)this + 0xec) + local_8 * 8);
      if ((((piVar2[0x10] == 5) && (piVar2[8] != 0)) &&
          (iVar3 = (**(code **)(*piVar2 + 0xc))(0x2e,0,0), iVar3 == 0)) &&
         ((iVar3 = (**(code **)(*piVar2 + 0xc))(0x30,0,0), iVar3 != 0 &&
          ((iVar4 = (iVar6 - (piVar2[0xc] - piVar2[10]) / 2) - piVar2[10],
           iVar3 = ((param_2 - iVar1) - (piVar2[0xd] - piVar2[0xb]) / 2) - piVar2[0xb],
           iVar3 = iVar3 * iVar3 + iVar4 * iVar4, piVar5 == (int *)0x0 || (iVar3 < param_1)))))) {
        piVar5 = piVar2;
        param_1 = iVar3;
      }
      local_8 = local_8 + -1;
    } while (-1 < local_8);
    if (piVar5 != (int *)0x0) {
      *param_3 = param_1;
      return piVar5;
    }
  }
  *param_3 = 0;
  return (int *)0x0;
}

