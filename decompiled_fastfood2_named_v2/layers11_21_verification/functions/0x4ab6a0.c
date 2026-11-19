// rea decompile_all
// name: FUN_004ab6a0
// address: 0x4ab6a0
// body: available
// range: 0x4ab6a0-0x4ab75d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004ab6a0(void *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  DAT_0057d5c8 = DAT_0057d5c8 + param_2;
  if (DAT_0057d5c8 < 0) {
    DAT_00569354 = DAT_00569354 - 1;
    DAT_0057d5c8 = 4;
    if ((int)DAT_00569354 < (int)DAT_0057dfbc) {
      DAT_00569354 = DAT_0057dfbc;
      DAT_0057d5c8 = 0;
    }
  }
  else {
    uVar1 = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 4);
    if (DAT_00569354 == uVar1) {
      iVar2 = *(byte *)(*(int *)(DAT_0057c670 + 0x94) + 8) + 1;
    }
    else {
      iVar2 = 4;
    }
    if (iVar2 < DAT_0057d5c8) {
      if (DAT_00569354 == uVar1) {
        DAT_0057d5c8 = iVar2;
      }
      else {
        DAT_00569354 = DAT_00569354 + 1;
        DAT_0057d5c8 = 0;
      }
    }
  }
  DAT_0057d5cc = 0xffffffff;
  StatisticsBalance_UpdateHeader(param_1);
  FUN_004aa740(param_1,DAT_0057d5d4);
  FUN_004aab00(param_1);
  return;
}

