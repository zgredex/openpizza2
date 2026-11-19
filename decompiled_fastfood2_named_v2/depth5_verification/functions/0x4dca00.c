// rea decompile_all
// name: FUN_004dca00
// address: 0x4dca00
// body: available
// range: 0x4dca00-0x4dca66 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004dca00(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = *(uint *)(param_1 + 0x10bc);
  do {
    uVar3 = _rand();
    uVar3 = uVar3 & 7;
    *(uint *)(param_1 + 0x10bc) = uVar3;
  } while (uVar2 == uVar3);
  iVar4 = *(int *)(&DAT_0056ca28 + uVar3 * 0x24) -
          (uint)*(byte *)(*(int *)(DAT_0057c670 + 0x94) + 7);
  iVar1 = iVar4 + 0x30;
  *(int *)(param_1 + 0x10c0) = iVar1;
  if (iVar1 < 0x19) {
    *(int *)(param_1 + 0x10c0) = iVar4 + 0x48;
  }
  if (0x30 < *(int *)(param_1 + 0x10c0)) {
    *(int *)(param_1 + 0x10c0) = *(int *)(param_1 + 0x10c0) + -0x18;
  }
  return;
}

