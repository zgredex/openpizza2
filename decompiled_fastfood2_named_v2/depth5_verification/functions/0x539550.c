// rea decompile_all
// name: FUN_00539550
// address: 0x539550
// body: available
// range: 0x539550-0x539594 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00539550(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar5 = *(undefined4 **)(param_1 + 0x28);
  if ((puVar5 != (undefined4 *)0x0) && (iVar4 = 0, *(short *)(param_1 + 0x1c) != 0)) {
    do {
      uVar1 = *(ushort *)(param_1 + 0x1a);
      puVar6 = puVar5;
      for (uVar2 = (uint)(uVar1 >> 1); uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      iVar4 = iVar4 + 1;
      for (iVar3 = (uVar1 & 1) << 1; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)puVar6 = 0;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
      puVar5 = (undefined4 *)((int)puVar5 + *(int *)(param_1 + 0x20) * 2);
    } while (iVar4 < (int)(uint)*(ushort *)(param_1 + 0x1c));
  }
  return;
}

