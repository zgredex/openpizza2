// rea decompile_all
// name: FUN_004e3660
// address: 0x4e3660
// body: available
// range: 0x4e3660-0x4e36c9 inclusive
// range: 0x4e371b-0x4e3723 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall FUN_004e3660(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  int local_4;
  
  bVar4 = param_1 == *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_4 = FUN_004e3610(param_1);
  if (local_4 != 0) {
    if ((bVar4) && (*(int *)(*(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8) + 0x180) != 0)) {
      local_4 = (local_4 * 0xf) / 10;
    }
    uVar3 = Game_CanAffordWithCurrency((void *)param_1,10,(float)local_4,'\x01',0xffffffff);
    if ((char)uVar3 == '\0') {
      return 0;
    }
    if (bVar4) {
      iVar1 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
      iVar2 = *(int *)(iVar1 + 0x180);
      if (iVar2 != 0) {
        *(int *)(iVar1 + 0x180) = iVar2 + -1;
      }
    }
    FUN_004e29b0(param_1);
  }
  return 1;
}

