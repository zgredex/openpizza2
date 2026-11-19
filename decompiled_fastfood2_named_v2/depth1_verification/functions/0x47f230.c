// rea decompile_all
// name: FUN_0047f230
// address: 0x47f230
// body: available
// range: 0x47f230-0x47f2df inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __thiscall FUN_0047f230(int param_1,int param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float10 extraout_ST0;
  longlong lVar5;
  
  iVar2 = FUN_00488be0(DAT_0057c670,*(int *)(param_1 + 0x30));
  iVar2 = FUN_004ddcc0(iVar2);
  iVar3 = FUN_004017f0((void *)((int)DAT_0057c670 + 0x74),*(int *)(param_2 + 4),(int *)0x0);
  fVar4 = Game_ComputePrice(iVar3,iVar2);
  fVar1 = (float)fVar4;
  if (param_3 != (float *)0x0) {
    *param_3 = fVar1;
  }
  iVar2 = *(int *)(param_2 + 0xc);
  if (iVar2 == 100) {
    return (float10)0.0;
  }
  if (iVar2 < 1) {
    if (param_3 != (float *)0x0) {
      *param_3 = 0.0;
    }
    return (float10)fVar1;
  }
  fVar4 = ((float10)fVar1 - (float10)iVar2 * (float10)0.01 * (float10)fVar1) * (float10)0.25;
  if (param_3 != (float *)0x0) {
    lVar5 = __ftol();
    *param_3 = (float)((float10)(int)lVar5 - extraout_ST0);
    fVar4 = extraout_ST0;
  }
  return fVar4;
}

