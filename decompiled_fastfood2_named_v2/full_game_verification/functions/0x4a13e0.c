// rea decompile_all
// name: SaveGame_NextFreeSlot
// address: 0x4a13e0
// body: available
// range: 0x4a13e0-0x4a1445 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int SaveGame_NextFreeSlot(void)

{
  FILE *pFVar1;
  int iVar2;
  CHAR local_104 [260];
  
  iVar2 = 0;
  String_Format(local_104,(byte *)s_save_games_save__03d_piz_00568198,0);
  pFVar1 = (FILE *)CRT_Fopen(local_104,&DAT_00563184);
  while (pFVar1 != (FILE *)0x0) {
    CRT_Fclose(pFVar1);
    iVar2 = iVar2 + 1;
    String_Format(local_104,(byte *)s_save_games_save__03d_piz_00568198,iVar2);
    pFVar1 = (FILE *)CRT_Fopen(local_104,&DAT_00563184);
  }
  return iVar2;
}

