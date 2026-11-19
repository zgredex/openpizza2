// rea decompile_all
// name: FUN_0048cbb0
// address: 0x48cbb0
// body: available
// range: 0x48cbb0-0x48cc09 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0048cbb0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_1 + 0x200 + *(int *)(param_1 + 0x2ec) * 4);
  if ((iVar1 != 0) && (0 < *(int *)(iVar1 + 0x15c))) {
    if ((*(int *)(param_1 + 0x9c) != 0) &&
       (iVar2 = *(int *)(*(int *)(param_1 + 0x9c) + 0x30), iVar3 = FUN_00482820(param_1),
       iVar2 == iVar3)) {
      return;
    }
    uVar4 = FUN_004017f0((void *)(iVar1 + 0x148),0,(int *)0x0);
    *(undefined4 *)(param_1 + 0x9c) = uVar4;
    Sound_SelectCurrentTrack(DAT_0057ba0c);
  }
  return;
}

