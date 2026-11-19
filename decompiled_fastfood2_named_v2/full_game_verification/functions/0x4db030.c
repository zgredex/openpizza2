// rea decompile_all
// name: Game_ComputeCompanyValue
// address: 0x4db030
// body: available
// range: 0x4db030-0x4db16f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Game_ComputeCompanyValue(void *this,int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = 0;
  piVar1 = (int *)((int)this + 0xcb0);
  iVar6 = 6;
  do {
    iVar2 = *piVar1;
    piVar1 = piVar1 + 1;
    iVar3 = iVar3 + iVar2;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = *(int *)((int)this + 0x10c4);
  iVar3 = iVar3 + iVar6 * -1000;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (iVar6 == 0) {
    return 0;
  }
  iVar4 = 0;
  iVar5 = 0;
  iVar2 = Game_GetPlayerCount((int)DAT_0057c670);
  if (0 < iVar2) {
    do {
      iVar2 = Game_GetPlayerBySlot(DAT_0057c670,iVar5);
      iVar4 = iVar4 + *(int *)(iVar2 + 0xf0);
      iVar5 = iVar5 + 1;
      iVar2 = Game_GetPlayerCount((int)DAT_0057c670);
    } while (iVar5 < iVar2);
  }
  iVar2 = Game_GetPlayerCount((int)DAT_0057c670);
  iVar2 = 100 - iVar4 / iVar2;
  iVar4 = (iVar3 / iVar6) / 1000 + 1 + iVar2 / 10;
  iVar3 = iVar3 / iVar6 + (iVar2 * 10000) / 0x14;
  if (10 < iVar4) {
    iVar4 = 10;
  }
  iVar6 = iVar3 / 10000;
  iVar3 = iVar3 / 15000;
  iVar2 = iVar4 - iVar3;
  *param_3 = iVar3;
  if (iVar2 < 1) {
    iVar2 = 0;
    *param_3 = iVar4;
  }
  iVar2 = iVar2 - iVar6;
  *param_2 = iVar6;
  if (iVar2 < 0) {
    iVar6 = iVar6 + iVar2;
    iVar2 = 0;
    *param_2 = iVar6;
  }
  *param_1 = iVar2;
  return iVar4;
}

