// rea decompile_all
// name: Map_CountBuildableNeighbors
// address: 0x479750
// body: available
// range: 0x479750-0x479955 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int Map_CountBuildableNeighbors(int param_1,int param_2,int param_3)

{
  int iVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  
                    /* Leaf reversal proposal batch 1. */
  iVar4 = 0;
  iVar1 = param_3 + (param_1 * 0x50 + param_2) * 8;
  if (((((*(short *)(iVar1 + 0x14) == 0) || (*(short *)(iVar1 + 0x14) == 2)) &&
       ((*(short *)(iVar1 + 0x1c) == 0 || (*(short *)(iVar1 + 0x1c) == 2)))) &&
      ((*(short *)(iVar1 + 0x294) == 0 || (*(short *)(iVar1 + 0x294) == 2)))) &&
     ((*(short *)(iVar1 + 0x29c) == 0 || (*(short *)(iVar1 + 0x29c) == 2)))) {
    iVar4 = 1;
  }
  if ((((*(short *)(iVar1 + -4) == 0) || (*(short *)(iVar1 + -4) == 2)) &&
      ((*(short *)(iVar1 + -0xc) == 0 || (*(short *)(iVar1 + -0xc) == 2)))) &&
     (((*(short *)(iVar1 + 0x27c) == 0 || (*(short *)(iVar1 + 0x27c) == 2)) &&
      ((*(short *)(iVar1 + 0x274) == 0 || (*(short *)(iVar1 + 0x274) == 2)))))) {
    iVar4 = iVar4 + 1;
  }
  if (((((*(short *)(iVar1 + 0x504) == 0) || (*(short *)(iVar1 + 0x504) == 2)) &&
       ((*(short *)(iVar1 + 0x50c) == 0 || (*(short *)(iVar1 + 0x50c) == 2)))) &&
      ((*(short *)(iVar1 + 0x784) == 0 || (*(short *)(iVar1 + 0x784) == 2)))) &&
     ((*(short *)(iVar1 + 0x78c) == 0 || (*(short *)(iVar1 + 0x78c) == 2)))) {
    iVar4 = iVar4 + 1;
  }
  if (((((*(short *)(iVar1 + -0x27c) == 0) || (*(short *)(iVar1 + -0x27c) == 2)) &&
       ((*(short *)(iVar1 + -0x274) == 0 || (*(short *)(iVar1 + -0x274) == 2)))) &&
      ((*(short *)(iVar1 + -0x4fc) == 0 || (*(short *)(iVar1 + -0x4fc) == 2)))) &&
     ((*(short *)(iVar1 + -0x4f4) == 0 || (*(short *)(iVar1 + -0x4f4) == 2)))) {
    iVar4 = iVar4 + 1;
  }
  if ((((*(short *)(iVar1 + -0x26c) == 0) || (*(short *)(iVar1 + -0x26c) == 2)) &&
      ((*(short *)(iVar1 + -0x4ec) == 0 || (*(short *)(iVar1 + -0x4ec) == 2)))) &&
     (((*(short *)(iVar1 + -0x264) == 0 || (*(short *)(iVar1 + -0x264) == 2)) &&
      ((*(short *)(iVar1 + -0x4e4) == 0 || (*(short *)(iVar1 + -0x4e4) == 2)))))) {
    iVar4 = iVar4 + 1;
  }
  if ((((*(short *)(iVar1 + 0x514) == 0) || (*(short *)(iVar1 + 0x514) == 2)) &&
      ((*(short *)(iVar1 + 0x51c) == 0 || (*(short *)(iVar1 + 0x51c) == 2)))) &&
     (((*(short *)(iVar1 + 0x794) == 0 || (*(short *)(iVar1 + 0x794) == 2)) &&
      ((*(short *)(iVar1 + 0x79c) == 0 || (*(short *)(iVar1 + 0x79c) == 2)))))) {
    iVar4 = iVar4 + 1;
  }
  sVar2 = *(short *)(iVar1 + 0x4fc);
  sVar3 = *(short *)(iVar1 + 0x774);
  if (((((sVar2 == 0) || (sVar2 == 2)) && ((sVar3 == 0 || (sVar3 == 2)))) &&
      ((sVar2 == 0 || (sVar2 == 2)))) && ((sVar3 == 0 || (sVar3 == 2)))) {
    iVar4 = iVar4 + 1;
  }
  sVar2 = *(short *)(iVar1 + -0x284);
  sVar3 = *(short *)(iVar1 + -0x50c);
  if ((((sVar2 == 0) || (sVar2 == 2)) && ((sVar3 == 0 || (sVar3 == 2)))) &&
     (((sVar2 == 0 || (sVar2 == 2)) && ((sVar3 == 0 || (sVar3 == 2)))))) {
    iVar4 = iVar4 + 1;
  }
  return iVar4;
}

