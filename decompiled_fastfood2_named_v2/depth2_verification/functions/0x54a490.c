// rea decompile_all
// name: FUN_0054a490
// address: 0x54a490
// body: available
// range: 0x54a490-0x54a594 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0054a490(void *this,undefined4 param_1)

{
  if (*(char *)((int)this + 0xfc) != '\0') {
    switch(param_1) {
    case 0:
      Sound_PlaySfxByIndex(this,0x14,0);
      return;
    case 1:
      Sound_PlaySfxByIndex(this,0x15,0);
      return;
    case 2:
      Sound_PlaySfxByIndex(this,0x16,0);
      return;
    case 3:
      Sound_PlaySfxByIndex(this,0x1d,0);
      return;
    case 4:
      Sound_PlaySfxByIndex(this,0x1e,0);
      return;
    case 5:
      Sound_PlaySfxByIndex(this,0x1f,0);
      return;
    case 6:
      Sound_PlaySfxByIndex(this,0x1c,1);
      return;
    case 7:
      Sound_PlaySfxByIndex(this,0x1c,2);
      return;
    case 8:
      Sound_PlaySfxByIndex(this,0x1c,3);
      return;
    case 9:
      Sound_PlaySfxByIndex(this,0x1c,4);
      return;
    case 10:
      Sound_PlaySfxByIndex(this,0x1c,5);
      return;
    case 0xb:
      Sound_PlaySfxByIndex(this,0x1c,6);
      return;
    case 0xc:
      Sound_PlaySfxByIndex(this,0x11,0);
    }
  }
  return;
}

