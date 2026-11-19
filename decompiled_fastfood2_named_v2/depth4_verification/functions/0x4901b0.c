// rea decompile_all
// name: FUN_004901b0
// address: 0x4901b0
// body: available
// range: 0x4901b0-0x490295 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004901b0(void *param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte *pbVar1;
  char *local_128 [4];
  char *local_118;
  char *local_114;
  char *local_110;
  char *local_10c;
  char *local_108;
  char *local_104;
  char local_100 [256];
  
  local_110 = s_Moebel_MENU_BODENEINF0_d_spr_005685d4;
  local_10c = s_Moebel_MENU_BODENRUST0_d_spr_005685b4;
  local_108 = s_Moebel_MENU_BODENMODE0_d_spr_00568594;
  local_104 = s_Moebel_MENU_BODENEDEL0_d_spr_00568574;
  local_128[2] = s_Moebel_MENU_TRENNWAND_EINF01_spr_005684e0;
  local_128[3] = s_Moebel_MENU_TRENNWAND_RUST01_spr_005684bc;
  local_118 = s_Moebel_MENU_TRENNWAND_MODE01_spr_00568498;
  local_114 = s_Moebel_MENU_TRENNWAND_EDEL01_spr_00568474;
  if (param_3 == 6) {
    pbVar1 = (byte *)local_128[param_4 + 2];
  }
  else {
    if (param_3 != 8) {
      if (param_3 == 10) {
        FUN_0054dd83(local_100,(byte *)local_128[param_4 + 6],param_5 + 1);
      }
      goto LAB_00490276;
    }
    pbVar1 = (byte *)local_128[param_4 + -2];
  }
  FUN_0054dd83(local_100,pbVar1,s_Moebel_MENU_WAND_EINF_spr_00568558);
LAB_00490276:
  FUN_00531910(param_1,param_2,local_100);
  return;
}

