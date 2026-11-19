// rea decompile_all
// name: FUN_004de030
// address: 0x4de030
// body: available
// range: 0x4de030-0x4de0c0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_004de030(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float local_8;
  int local_4;
  
  local_8 = 0.0;
  local_4 = 0;
  iVar1 = Game_CountActiveCompanies((int)this);
  iVar3 = 0;
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = Game_GetActiveCompanyById(this,iVar3);
      fVar4 = FUN_00510460(iVar2,param_1);
      if ((float10)local_8 < fVar4) {
        local_8 = (float)fVar4;
        local_4 = iVar2;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
    iVar2 = local_4;
  }
  if (((param_2 == 0) || (iVar1 = *(int *)(param_2 + 0x14dc), iVar1 == 0)) ||
     (fVar4 = FUN_00510460(iVar1,param_1), fVar4 <= (float10)local_8)) {
    iVar1 = iVar2;
  }
  return iVar1;
}

