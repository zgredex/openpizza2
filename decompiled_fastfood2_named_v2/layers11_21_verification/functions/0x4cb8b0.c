// rea decompile_all
// name: UI_SetPlayerLogoSprite
// address: 0x4cb8b0
// body: available
// range: 0x4cb8b0-0x4cb8f3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl UI_SetPlayerLogoSprite(void *param_1,int param_2,undefined4 param_3,int param_4)

{
  char local_100 [256];
  
                    /* Sets a player's logo/portrait sprite from its index and rank. */
  FUN_0054dd83(local_100,(byte *)s_PLAYLOG__d_0_d_01_spr_0056b318,param_2 + 1);
  UI_SetButtonSpriteByName(param_1,param_4,local_100);
  return;
}

