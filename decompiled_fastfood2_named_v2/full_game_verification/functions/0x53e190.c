// rea decompile_all
// name: Tilemap_GetCell
// address: 0x53e190
// body: available
// range: 0x53e190-0x53e1d1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __cdecl Tilemap_GetCell(uint param_1,int param_2,int param_3)

{
  uint in_EAX;
  
  if ((((param_2 < 0) || (in_EAX = param_1, (int)(uint)*(ushort *)(param_1 + 0x1a) <= param_2)) ||
      (param_3 < 0)) || ((int)(uint)*(ushort *)(param_1 + 0x1c) <= param_3)) {
    return in_EAX & 0xffff0000;
  }
  return CONCAT22((short)((uint)(param_2 * 3) >> 0x10),
                  *(undefined2 *)
                   (*(int *)(param_1 + 0x20) * param_3 + *(int *)(param_1 + 0x28) + param_2 * 3));
}

