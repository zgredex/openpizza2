// rea decompile_all
// name: FUN_0047e6e0
// address: 0x47e6e0
// body: available
// range: 0x47e6e0-0x47e74d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0047e6e0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_280 [160];
  
  iVar1 = FUN_004f55e0(*(void **)(param_1 + 0x14e0),(int)local_280);
  if (0 < iVar1) {
    puVar4 = local_280 + 1;
    do {
      puVar2 = operator_new(0x20);
      puVar5 = puVar2;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      puVar2[5] = puVar4[-1];
      puVar2[6] = *puVar4;
      puVar2[7] = 0;
      List_Add((void *)(param_1 + 0x1998),puVar2);
      puVar4 = puVar4 + 2;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

