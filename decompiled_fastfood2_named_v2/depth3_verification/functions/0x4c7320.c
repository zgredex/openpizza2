// rea decompile_all
// name: FUN_004c7320
// address: 0x4c7320
// body: available
// range: 0x4c7320-0x4c759c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c7320(void *param_1)

{
  int local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
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
  
  local_10c = DAT_0058265c;
  local_fc = DAT_005826ac;
  local_f4 = DAT_005826ac;
  local_ec = DAT_005826ac;
  local_e4 = DAT_005826ac;
  local_dc = DAT_005826ac;
  local_d4 = DAT_005826ac;
  local_cc = DAT_005826ac;
  local_c4 = DAT_005826ac;
  local_104 = DAT_005826bc;
  local_bc = DAT_005826a0;
  local_b4 = DAT_005826a0;
  local_ac = DAT_0058268c;
  local_a4 = DAT_0058268c;
  local_9c = DAT_005826fc;
  local_94 = DAT_005826fc;
  local_54 = DAT_00580fcc;
  local_8c = DAT_005826f0;
  local_84 = DAT_005826f0;
  local_4c = DAT_00580fcc;
  local_7c = DAT_005826dc;
  local_74 = DAT_005826dc;
  local_6c = DAT_005826c8;
  local_64 = DAT_005826c8;
  local_44 = DAT_00580f48;
  local_3c = DAT_00580f48;
  local_5c = DAT_00580fc8;
  local_24 = DAT_00580fc8;
  local_34 = DAT_00580f58;
  local_2c = DAT_00580f58;
  local_110 = 0x43a;
  local_108 = 0x43b;
  local_100 = 0x3ee;
  local_f8 = 0x3ef;
  local_f0 = 0x3f0;
  local_e8 = 0x3f1;
  local_e0 = 0x3f2;
  local_d8 = 0x3f3;
  local_d0 = 0x3f4;
  local_c8 = 0x3f5;
  local_c0 = 0x3fa;
  local_b8 = 0x3fb;
  local_b0 = 0x3fc;
  local_a8 = 0x3fd;
  local_a0 = 0x3fe;
  local_98 = 0x3ff;
  local_90 = 0x400;
  local_88 = 0x401;
  local_80 = 0x402;
  local_78 = 0x403;
  local_70 = 0x404;
  local_68 = 0x405;
  local_60 = 0x40c;
  local_58 = 0x3f8;
  local_50 = 0x3f9;
  local_48 = 0x3f6;
  local_40 = 0x3f7;
  local_38 = 0x40a;
  local_30 = 0x440;
  local_28 = 0x43f;
  local_20 = 0x407;
  local_1c = DAT_00580f5c;
  local_18 = 0x434;
  local_14 = DAT_00580f64;
  local_10 = 0x435;
  local_c = DAT_00580f70;
  local_8 = 0xffffffff;
  local_4 = 0;
  UI_SetMultipleLabels(param_1,&local_110);
  return;
}

