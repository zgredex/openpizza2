// rea decompile_all
// name: Branch_GetBuildingValue
// address: 0x47fd90
// body: available
// range: 0x47fd90-0x47fe03 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __fastcall Branch_GetBuildingValue(int param_1)

{
  int iVar1;
  void *this;
  void *this_00;
  void *pvVar2;
  int iVar3;
  float10 fVar4;
  
                    /* Returns the branch building's stored or computed value. */
  iVar3 = 0;
  iVar1 = FUN_004017f0((void *)(param_1 + 0x1998),0,(int *)0x0);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x1c) != 0)) {
    return (float10)*(float *)(iVar1 + 0x10);
  }
  this = (void *)FUN_00488be0(DAT_0057c670,*(int *)(param_1 + 0x30));
  this_00 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)(param_1 + 0x34),(int *)0x0
                                );
  pvVar2 = FUN_004e23b0(this,param_1);
  if (pvVar2 != (void *)0x0) {
    iVar3 = FUN_004da630(this_00,*(int *)((int)pvVar2 + 0x30));
  }
  fVar4 = FUN_004e2410((int)this,this_00,iVar3);
  return fVar4;
}

