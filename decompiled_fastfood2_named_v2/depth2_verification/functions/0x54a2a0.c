// rea decompile_all
// name: FUN_0054a2a0
// address: 0x54a2a0
// body: available
// range: 0x54a2a0-0x54a433 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0054a2a0(void *this,undefined4 param_1)

{
  if (*(char *)((int)this + 0xfc) != '\0') {
    switch(param_1) {
    case 0:
      Sound_PlaySfxByIndex(this,0,0);
      return;
    case 1:
      Sound_PlaySfxByIndex(this,1,0);
      return;
    case 2:
      Sound_PlaySfxByIndex(this,2,0);
      return;
    case 3:
      Sound_PlaySfxByIndex(this,0x12,0);
      return;
    case 4:
      Sound_PlaySfxByIndex(this,4,0);
      return;
    case 5:
      Sound_PlaySfxByIndex(this,5,0);
      return;
    case 6:
      Sound_PlaySfxByIndex(this,6,0);
      return;
    case 7:
      Sound_PlaySfxByIndex(this,7,0);
      return;
    case 8:
      Sound_PlaySfxByIndex(this,8,0);
      return;
    case 9:
      Sound_PlaySfxByIndex(this,9,0);
      return;
    case 10:
      Sound_PlaySfxByIndex(this,10,0);
      return;
    case 0xb:
      FUN_00547340(this,s_Sfx_Sfx_City_Building_Manufaktur_00576330,1);
      return;
    case 0xc:
      Sound_PlaySfxByIndex(this,0xd,0);
      return;
    case 0xd:
      Sound_PlaySfxByIndex(this,0xe,0);
      return;
    case 0xe:
      Sound_PlaySfxByIndex(this,0x18,0);
      return;
    case 0xf:
      Sound_PlaySfxByIndex(this,0xb,0);
      return;
    case 0x10:
      Sound_PlaySfxByIndex(this,0x21,0);
      return;
    case 0x11:
      Sound_PlaySfxByIndex(this,0x19,0);
      return;
    case 0x12:
      Sound_PlaySfxByIndex(this,0x17,0);
      return;
    case 0x13:
      Sound_PlaySfxByIndex(this,0x13,0);
      return;
    case 0x14:
      Sound_PlaySfxByIndex(this,0x16,0);
      return;
    case 0x15:
      Sound_PlaySfxByIndex(this,0x1a,0);
      return;
    case 0x16:
      Sound_PlaySfxByIndex(this,0x23,0);
    }
  }
  return;
}

