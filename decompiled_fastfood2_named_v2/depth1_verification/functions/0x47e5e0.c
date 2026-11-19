// rea decompile_all
// name: FUN_0047e5e0
// address: 0x47e5e0
// body: available
// range: 0x47e5e0-0x47e697 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0047e5e0(void *this,int param_1)

{
  char *local_a0 [4];
  undefined *local_90;
  undefined *local_8c;
  undefined *local_88;
  undefined *local_84;
  CHAR local_80 [128];
  
  local_a0[0] = s_KLEIN_00567cd4;
  local_a0[1] = s_MITTEL_00567ccc;
  local_a0[2] = s_GROSS_00567cc4;
  local_a0[3] = &DAT_00567cbc;
  local_90 = &DAT_00567cb4;
  local_8c = &DAT_00567cac;
  local_88 = &DAT_00567ca4;
  local_84 = &DAT_00567ca0;
  if (param_1 == 4) {
    FUN_0054dd83(local_80,(byte *)s_FILIALE__s_BODENROH00_spr_00567c68,
                 local_a0[*(int *)((int)this + 0x38)]);
  }
  else {
    FUN_0054dd83(local_80,(byte *)s_FILIALE__s_BODEN_s_02d_spr_00567c84,
                 local_a0[*(int *)((int)this + 0x38)]);
  }
  Sprite_LoadIntoSlot78(*(void **)((int)this + 0x14e0),local_80);
  return;
}

