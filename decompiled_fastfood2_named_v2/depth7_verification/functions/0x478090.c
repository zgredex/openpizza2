// rea decompile_all
// name: FUN_00478090
// address: 0x478090
// body: available
// range: 0x478090-0x478135 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __thiscall FUN_00478090(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  float10 fVar5;
  float local_8;
  
  iVar1 = *(int *)(param_1 + 0x14f8);
  iVar4 = 0;
  local_8 = 0.0;
  if (iVar1 < 1) {
    return (float10)0.0;
  }
  do {
    iVar2 = FUN_004017f0((void *)(param_1 + 0x14e4),iVar4,(int *)0x0);
    if (((*(int *)(iVar2 + 8) == param_3) || (param_3 == -1)) &&
       ((param_4 == -1 || (param_4 == *(int *)(iVar2 + 4))))) {
      if (param_2 == -1) {
        fVar5 = (float10)local_8;
        pfVar3 = (float *)(iVar2 + 0x78);
        iVar2 = 0x19;
        do {
          fVar5 = fVar5 + (float10)*pfVar3;
          pfVar3 = pfVar3 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        local_8 = (float)fVar5;
      }
      else {
        fVar5 = (float10)*(float *)(iVar2 + 0x78 + param_2 * 4) + (float10)local_8;
        local_8 = (float)fVar5;
      }
    }
    else {
      fVar5 = (float10)local_8;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < iVar1);
  return fVar5;
}

