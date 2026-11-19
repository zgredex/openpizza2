// rea decompile_all
// name: FUN_00502eb0
// address: 0x502eb0
// body: available
// range: 0x502eb0-0x502f05 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall FUN_00502eb0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x48);
  if (*(int *)(param_1 + 0x48) == 0x16) {
    iVar3 = 0;
    iVar1 = DAT_0057c670;
    if (0 < *(int *)(DAT_0057c670 + 0x50)) {
      do {
        iVar1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),iVar3,(int *)0x0);
        if (*(int *)(iVar1 + 0x30) < 8) {
          uVar2 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
          if (*(int *)(iVar1 + 0x14c + uVar2 * 4) == 0) {
            return uVar2 & 0xffffff00;
          }
        }
        iVar3 = iVar3 + 1;
        iVar1 = DAT_0057c670;
      } while (iVar3 < *(int *)(DAT_0057c670 + 0x50));
    }
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}

