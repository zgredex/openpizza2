// rea decompile_all
// name: Building_GetLevelFromType
// address: 0x4f9d50
// body: available
// range: 0x4f9d50-0x4f9dd1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 Building_GetLevelFromType(int param_1)

{
  char cVar1;
  
                    /* Leaf reversal proposal batch 4. */
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0:
    if (*(byte *)(param_1 + 0x14) < 2) {
      return 1;
    }
    if (*(byte *)(param_1 + 0x14) == 2) {
      return 2;
    }
    break;
  case 1:
    cVar1 = *(char *)(param_1 + 0x14);
    if (cVar1 == '\0') {
      return 1;
    }
    if (cVar1 == '\x01') {
      return 2;
    }
    if (cVar1 == '\x02') {
      return 3;
    }
    break;
  case 2:
    cVar1 = *(char *)(param_1 + 0x14);
    if (cVar1 == '\0') {
      return 2;
    }
    if (cVar1 == '\x01') {
      return 3;
    }
    if (cVar1 == '\x02') {
      return 4;
    }
    break;
  case 3:
    cVar1 = *(char *)(param_1 + 0x14);
    if (cVar1 == '\0') {
      return 3;
    }
    if (cVar1 == '\x01') {
      return 4;
    }
    if (cVar1 == '\x02') {
      return 5;
    }
  }
  return 0xffffffff;
}

