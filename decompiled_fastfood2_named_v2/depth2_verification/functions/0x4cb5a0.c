// rea decompile_all
// name: FUN_004cb5a0
// address: 0x4cb5a0
// body: available
// range: 0x4cb5a0-0x4cb6d2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004cb5a0(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  DAT_0057de30 = FUN_00476100(&local_4);
  DAT_0057de5c = param_1;
  DAT_0057de68 = param_3;
  DAT_0057de54 = param_4;
  DAT_0057de58 = 0;
  FUN_0052f9b0(DAT_0057de30,0x441,param_2);
  iVar1 = *(int *)(param_3 + 0x14);
  if (iVar1 < 0x14) {
    UI_RemoveObjectByKey(DAT_0057de30,0x462);
    iVar2 = 0x7e2;
    iVar1 = 0x7e2 - (0x13 - iVar1);
    if (iVar1 < 0x7e2) {
      do {
        UI_RemoveObjectByKey(DAT_0057de30,iVar2);
        UI_RemoveObjectByKey(DAT_0057de30,iVar2 + 1000);
        iVar2 = iVar2 + -1;
      } while (iVar1 < iVar2);
    }
  }
  else {
    DAT_0057de58 = param_4;
    if (*(int *)(param_3 + 0x14) < param_4 + 0x13) {
      DAT_0057de58 = iVar1 + -0x13;
    }
    FUN_0052fd00(DAT_0057de30,0x462,0,(iVar1 + -0x13) * 100,1);
    FUN_0052fd70(DAT_0057de30,0x462,DAT_0057de58 * 100,0);
    FUN_0052fce0(DAT_0057de30,0x462,1);
  }
  FUN_004cb520(DAT_0057de58);
  FUN_00523d60(DAT_0057c5e0,local_4);
  DAT_0057de6c = 1;
  return;
}

