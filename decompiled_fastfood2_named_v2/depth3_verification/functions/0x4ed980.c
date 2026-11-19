// rea decompile_all
// name: Map_ComputeVisibleTileRange
// address: 0x4ed980
// body: available
// range: 0x4ed980-0x4eda52 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
Map_ComputeVisibleTileRange
          (void *this,int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,
          undefined4 *param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
                    /* Depth-3 proposal batch 4. */
  *param_6 = 0;
  FUN_004eda60(this,param_1,param_2,param_3);
  FUN_004edaf0(this,(int)param_1,param_4,param_5);
  piVar1 = (int *)FUN_004ef4b0(this,*param_2 + 1,*param_3);
  if ((piVar1 != (int *)0x0) && (*param_1 < *piVar1)) {
    *param_2 = *param_2 + -1;
  }
  iVar2 = FUN_004ef4b0(this,*param_2 + 1,*param_3);
  if ((iVar2 != 0) && (param_1[1] <= *(int *)(iVar2 + 4) + *(int *)((int)this + 0x10))) {
    *param_2 = *param_2 + -1;
    *param_5 = *param_5 + -1;
    *param_6 = 1;
  }
  while( true ) {
    iVar2 = FUN_004ef4b0(this,*param_2,*param_3);
    iVar3 = FUN_004ef4b0(this,*param_4,*param_5);
    if (((iVar2 == 0) || (iVar3 == 0)) || (*(int *)(iVar3 + 4) <= *(int *)(iVar2 + 4))) break;
    *param_5 = *param_5 + -1;
  }
  return;
}

