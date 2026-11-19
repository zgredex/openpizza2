// rea decompile_all
// name: SaveGame_Scan
// address: 0x4a1940
// body: available
// range: 0x4a1940-0x4a19d9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl SaveGame_Scan(void *param_1,int param_2)

{
  void *this;
  char *pcVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Adds the autosave entry and scans manual save files into the save list. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055887b;
  local_c = ExceptionList;
  if (param_2 == 0) {
    pcVar1 = s_save_games_auto___piz_00568d04;
    ExceptionList = &local_c;
  }
  else {
    ExceptionList = &local_c;
    this = operator_new(0x58);
    local_4 = 0;
    if (this == (void *)0x0) {
      pcVar1 = (char *)0x0;
    }
    else {
      pcVar1 = FUN_00403370(this,DAT_00582894,0xffffffff);
    }
    local_4 = 0xffffffff;
    FUN_004033c0(pcVar1,DAT_00580ea0);
    FUN_004014b0(param_1,pcVar1);
    pcVar1 = (char *)0x0;
  }
  SaveGame_ReadHeaderEntry(param_1,pcVar1,s_save_games_save___piz_00568d1c);
  ExceptionList = local_c;
  return;
}

