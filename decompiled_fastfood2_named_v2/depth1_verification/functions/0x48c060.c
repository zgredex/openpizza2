// rea decompile_all
// name: FUN_0048c060
// address: 0x48c060
// body: available
// range: 0x48c060-0x48c151 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __thiscall FUN_0048c060(int param_1,int *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  float local_8;
  
  iVar7 = 0;
  if (param_2[7] == 0) {
    *param_2 = 0;
    return (float10)0.0;
  }
  if (*param_2 == 0) {
    param_2[7] = 0;
    return (float10)0.0;
  }
  iVar8 = 0;
  local_8 = 0.0;
  iVar3 = Game_CountActiveCompanies((int)param_3);
  if (0 < iVar3) {
    do {
      iVar4 = Game_GetActiveCompanyById(param_3,iVar7);
      if (iVar4 == 0) {
        fVar9 = (float10)local_8;
      }
      else {
        fVar9 = (float10)local_8;
        piVar6 = (int *)(param_1 + 0xa8);
        piVar5 = (int *)(iVar4 + 100);
        iVar4 = 0x56;
        do {
          iVar1 = *piVar5;
          piVar5 = piVar5 + 1;
          iVar8 = iVar8 + iVar1;
          iVar2 = *piVar6;
          piVar6 = piVar6 + 1;
          iVar4 = iVar4 + -1;
          fVar9 = (float10)*(double *)(iVar2 + 0xc0) * (float10)iVar1 * (float10)0.001 + fVar9;
        } while (iVar4 != 0);
        local_8 = (float)fVar9;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar3);
    local_8 = (float)iVar8;
    if (iVar8 != 0) goto LAB_0048c128;
  }
  fVar9 = (float10)100.0;
  local_8 = 2.8026e-40;
LAB_0048c128:
  param_2[7] = 0;
  iVar7 = *param_2;
  *param_2 = 0;
  return (fVar9 / (float10)(int)local_8) * (float10)(float)param_2[4] * (float10)iVar7;
}

