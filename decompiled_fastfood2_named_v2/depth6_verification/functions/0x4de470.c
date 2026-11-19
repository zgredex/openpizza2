// rea decompile_all
// name: FUN_004de470
// address: 0x4de470
// body: available
// range: 0x4de470-0x4de4ef inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __thiscall FUN_004de470(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float local_4;
  
  local_4 = 0.0;
  if (param_4 != 0) {
    fVar4 = FUN_00477fe0(param_4,param_2,-1,param_3);
    return fVar4;
  }
  iVar1 = *(int *)(param_1 + 0x15c);
  iVar3 = 0;
  if (iVar1 < 1) {
    return (float10)0.0;
  }
  do {
    iVar2 = FUN_004017f0((void *)(param_1 + 0x148),iVar3,(int *)0x0);
    fVar4 = FUN_00477fe0(iVar2,param_2,-1,param_3);
    iVar3 = iVar3 + 1;
    local_4 = (float)(fVar4 + (float10)local_4);
  } while (iVar3 < iVar1);
  return (float10)local_4;
}

