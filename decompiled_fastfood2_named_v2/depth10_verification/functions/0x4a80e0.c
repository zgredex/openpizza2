// rea decompile_all
// name: FUN_004a80e0
// address: 0x4a80e0
// body: available
// range: 0x4a80e0-0x4a81e9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a80e0(void *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  char local_100 [256];
  
  local_100[0] = '\0';
  if (param_5 != 0) {
    if ((param_3 < 0) || (7 < param_3)) {
      FUN_0054dd83(local_100,DAT_00580f54,param_5);
    }
    else {
      FUN_0054dd83(local_100,DAT_00580f44,param_5);
    }
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  iVar2 = 0;
  iVar1 = (&DAT_00569288)[param_3] + -0x10 + param_2;
  do {
    FUN_00531740(param_1,iVar2 + iVar1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x11);
  if (param_4 < 0) {
    param_4 = 0;
  }
  else if (100 < param_4) {
    param_4 = 100;
  }
  iVar2 = (param_4 * 0x10 + 0x32) / 100;
  if (100 < iVar2) {
    iVar2 = 100;
  }
  iVar2 = iVar2 + iVar1;
  FUN_005316b0(param_1,iVar2);
  if (local_100[0] == '\0') {
    FUN_00531f80(param_1,iVar2);
    return;
  }
  FUN_00531f50(param_1,iVar2,local_100);
  return;
}

