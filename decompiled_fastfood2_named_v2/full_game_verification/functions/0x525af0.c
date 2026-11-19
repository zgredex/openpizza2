// rea decompile_all
// name: UI_ProcessCommandQueue
// address: 0x525af0
// body: available
// range: 0x525af0-0x525b6f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall UI_ProcessCommandQueue(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0x82bc);
  if (iVar6 != *(int *)(param_1 + 0x82c0)) {
    do {
      iVar1 = *(int *)(param_1 + (iVar6 * 5 + 0xcb2) * 4);
      if (iVar1 == 0x22) {
        *(uint *)(param_1 + 0x82bc) = iVar6 + 1U & 0x3ff;
      }
      else {
        uVar2 = *(undefined4 *)(param_1 + 0x32c0 + iVar6 * 0x14);
        uVar3 = *(undefined4 *)(param_1 + 0x32c4 + iVar6 * 0x14);
        pcVar4 = *(code **)(param_1 + 0x32bc + iVar6 * 0x14);
        uVar5 = *(undefined4 *)(param_1 + iVar6 * 0x14 + 0x32cc);
        *(uint *)(param_1 + 0x82bc) = iVar6 + 1U & 0x3ff;
        (*pcVar4)(uVar2,uVar3,iVar1,uVar5);
      }
      iVar6 = *(int *)(param_1 + 0x82bc);
    } while (iVar6 != *(int *)(param_1 + 0x82c0));
  }
  return;
}

