// rea decompile_all
// name: Sound_PlaySfxByIndex
// address: 0x5480c0
// body: available
// range: 0x5480c0-0x5481f5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Sound_PlaySfxByIndex(void *this,int param_1,int param_2)

{
  undefined *puVar1;
  undefined1 local_104 [260];
  
                    /* Depth-2 proposal batch 3. */
  if (((*(char *)((int)this + 0xfc) != '\0') && (param_1 < 0x25)) &&
     (puVar1 = (&PTR_s_Sfx_City_Building_Living_wav_00575190)[param_1], puVar1 != (undefined *)0x0))
  {
    if (param_1 == 0xb) {
      FUN_0054dd83(local_104,(byte *)s_Sfx__s_s_wav_00576110,puVar1);
    }
    else {
      FUN_0054dd83(local_104,(byte *)s_Sfx__s_00576108,puVar1);
    }
    if (((0 < param_2) && (param_1 != 0xf)) && ((param_1 != 0x10 && (param_1 == 0x1c)))) {
      switch(param_2) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
      }
    }
    FUN_00547340(this,local_104,1);
  }
  return;
}

