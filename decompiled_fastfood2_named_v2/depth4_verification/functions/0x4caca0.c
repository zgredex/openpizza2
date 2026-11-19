// rea decompile_all
// name: UI_ShowPanel
// address: 0x4caca0
// body: available
// range: 0x4caca0-0x4cad75 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl UI_ShowPanel(void *param_1)

{
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Builds/shows a UI panel. */
  local_4c = DAT_005812b8;
  local_44 = DAT_0058167c;
  local_54 = DAT_005812cc;
  local_34 = DAT_00581688;
  local_2c = DAT_00581684;
  local_3c = DAT_00581674;
  local_1c = DAT_00581690;
  local_14 = DAT_005816ac;
  local_24 = DAT_005816a0;
  local_58 = 0x5a5;
  local_50 = 0x4ac;
  local_48 = 0x5a7;
  local_40 = 0x4ae;
  local_38 = 0x4ab;
  local_30 = 0x4b0;
  local_28 = 0x4b1;
  local_20 = 0x4af;
  local_18 = 0x4aa;
  local_10 = 0x4d0;
  local_c = DAT_005821f0;
  local_8 = 0xffffffff;
  local_4 = 0;
  FUN_004c70b0(param_1,&local_58);
  return;
}

