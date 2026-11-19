// rea decompile_all
// name: Game_GetDataByIndex
// address: 0x48d110
// body: available
// range: 0x48d110-0x48d21b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined * Game_GetDataByIndex(undefined4 param_1)

{
                    /* Switch 0..4 returning global data pointers. */
  switch(param_1) {
  case 0:
    return DAT_005822c8;
  case 1:
    return DAT_0058235c;
  case 2:
    return DAT_00582344;
  case 3:
    return DAT_00582334;
  case 4:
    return DAT_00582318;
  case 5:
    return DAT_00582488;
  case 6:
    return DAT_00582480;
  case 7:
    return DAT_00582478;
  default:
    return &DAT_00568310;
  case 10:
    return DAT_00582314;
  case 0xb:
    return DAT_00582484;
  case 0xc:
    return DAT_00582124;
  case 0xd:
    return DAT_005820fc;
  case 0xe:
    return DAT_00582148;
  case 0xf:
  case 0x21:
    return DAT_005820e8;
  case 0x10:
    return DAT_005812bc;
  case 0x11:
    return DAT_00582174;
  case 0x12:
    return DAT_0058214c;
  case 0x13:
    return DAT_00582114;
  case 0x14:
    return DAT_00580e4c;
  case 0x16:
    return DAT_00582214;
  case 0x17:
    return DAT_00582234;
  case 0x18:
    return DAT_00580df8;
  case 0x1a:
    return DAT_00582208;
  case 0x1b:
    return DAT_005820e4;
  case 0x1c:
    return DAT_005821bc;
  case 0x1d:
    return DAT_00582110;
  case 0x1e:
    return DAT_00582100;
  case 0x1f:
    return DAT_00581290;
  case 0x20:
    return DAT_005821f8;
  case 0x22:
    return DAT_005820cc;
  }
}

