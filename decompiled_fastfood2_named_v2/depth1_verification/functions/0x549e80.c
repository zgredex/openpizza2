// rea decompile_all
// name: FUN_00549e80
// address: 0x549e80
// body: available
// range: 0x549e80-0x549f1b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00549e80(void *this,undefined4 param_1)

{
  undefined *puVar1;
  undefined1 local_104 [260];
  
  if (*(char *)((int)this + 0xfc) != '\0') {
    switch(param_1) {
    case 0:
      puVar1 = &DAT_0057632c;
      break;
    case 1:
      puVar1 = &DAT_00576328;
      break;
    case 2:
      puVar1 = &DAT_00576324;
      break;
    case 3:
      puVar1 = &DAT_00576320;
      break;
    case 4:
      puVar1 = &DAT_0057631c;
      break;
    case 5:
      puVar1 = &DAT_00576318;
      break;
    case 6:
      puVar1 = &DAT_00576314;
      break;
    case 7:
      puVar1 = &DAT_00576310;
      break;
    case 8:
      puVar1 = &DAT_0057630c;
      break;
    case 9:
      puVar1 = &DAT_00576308;
      break;
    default:
      goto switchD_00549e9f_default;
    }
    FUN_0054dd83(local_104,(byte *)s_Sfx_Sfx_City_Building_Special__s_005762e0,puVar1);
    Sound_PlayChannel(this,local_104,1);
  }
switchD_00549e9f_default:
  return;
}

