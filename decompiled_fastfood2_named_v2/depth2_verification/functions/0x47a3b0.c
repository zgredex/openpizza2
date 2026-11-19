// rea decompile_all
// name: FUN_0047a3b0
// address: 0x47a3b0
// body: available
// range: 0x47a3b0-0x47a429 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0047a3b0(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_EDX;
  int iVar5;
  
  iVar4 = param_1;
  iVar5 = 3;
  iVar1 = FUN_004787f0(this,param_1);
  iVar2 = FUN_00478be0(this,extraout_EDX,iVar4);
  iVar3 = FUN_00478320(this,iVar4);
  iVar3 = iVar1 + iVar2 + iVar3;
  if (param_2 != 0) {
    iVar1 = FUN_00478420(this,iVar4,&param_1);
    if (param_1 != 0) {
      iVar3 = iVar3 + iVar1;
      iVar5 = 4;
    }
  }
  iVar4 = Rating_ComputeBuildingScore(this,iVar4);
  iVar4 = iVar4 + iVar3 / iVar5;
  if (iVar4 < 0) {
    return 0;
  }
  iVar1 = 100;
  if (iVar4 < 0x65) {
    iVar1 = iVar4;
  }
  return iVar1;
}

