// rea decompile_all
// name: UI_ShowDialog
// address: 0x4c89b0
// body: available
// range: 0x4c89b0-0x4c8aa7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl UI_ShowDialog(void *param_1)

{
  int local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
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
  
  local_7c = DAT_005810c4;
  local_74 = DAT_0058110c;
  local_6c = DAT_0058110c;
  local_64 = DAT_0058110c;
  local_5c = DAT_0058110c;
  local_54 = DAT_0058110c;
  local_4c = DAT_0058110c;
  local_44 = DAT_0058110c;
  local_3c = DAT_0058110c;
  local_80 = 0x59a;
  local_78 = 0x4ac;
  local_70 = 0x59b;
  local_68 = 0x4ae;
  local_60 = 0x4ab;
  local_58 = 0x4b0;
  local_50 = 0x4b1;
  local_48 = 0x4af;
  local_40 = 0x4aa;
  local_38 = 0x4b8;
  local_34 = DAT_005810f8;
  local_30 = 0x4b9;
  local_2c = DAT_005810f8;
  local_28 = 0x4ba;
  local_24 = DAT_005810f8;
  local_20 = 0x4bb;
  local_1c = DAT_005810f8;
  local_18 = 0x4bc;
  local_14 = DAT_005810f8;
  local_10 = 0x4bd;
  local_c = DAT_005810f8;
  local_8 = 0xffffffff;
  local_4 = 0;
  UI_SetMultipleLabels(param_1,&local_80);
  return;
}

