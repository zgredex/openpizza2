// rea decompile_all
// name: FUN_004c3070
// address: 0x4c3070
// body: available
// range: 0x4c3070-0x4c310e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c3070(void *param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 uVar3;
  undefined4 extraout_EDX_00;
  int iVar4;
  
  *(undefined4 *)(DAT_0057c5e0 + 0x831c) = 1;
  FUN_00532520((int)param_1);
  FUN_00532330(param_1,0,3,0x1f63);
  DAT_0056adec = 2;
  FUN_0052ff50(param_1,0x1f65,1);
  FUN_00532310(param_1,&LAB_004c2ba0,0);
  pvVar1 = *(void **)(DAT_0057c670 + 0x9c);
  FUN_004c2be0(param_1);
  iVar4 = 0;
  uVar3 = extraout_EDX;
  do {
    iVar2 = Branch_ComputeBuildingRating(pvVar1,uVar3,iVar4);
    FUN_004a80e0(param_1,0x559,iVar4,iVar2,DAT_00582320);
    iVar4 = iVar4 + 1;
    uVar3 = extraout_EDX_00;
  } while (iVar4 < 8);
  return;
}

