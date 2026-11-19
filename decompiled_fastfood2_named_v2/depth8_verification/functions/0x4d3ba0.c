// rea decompile_all
// name: FUN_004d3ba0
// address: 0x4d3ba0
// body: available
// range: 0x4d3ba0-0x4d3cec inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004d3ba0(void *this,void *param_1)

{
  CRT_Ostream_Write(param_1,(int)this + 4,4);
  CRT_Ostream_Write(param_1,(int)this + 8,4);
  CRT_Ostream_Write(param_1,(int)this + 0xc,4);
  CRT_Ostream_Write(param_1,(int)this + 0x10,4);
  CRT_Ostream_Write(param_1,(int)this + 0x24,4);
  CRT_Ostream_Write(param_1,(int)this + 0x28,4);
  CRT_Ostream_Write(param_1,(int)this + 0x2c,4);
  CRT_Ostream_Write(param_1,(int)this + 0x30,4);
  CRT_Ostream_Write(param_1,(int)this + 0x34,4);
  CRT_Ostream_Write(param_1,(int)this + 0x38,4);
  CRT_Ostream_Write(param_1,(int)this + 0x3c,4);
  CRT_Ostream_Write(param_1,(int)this + 0x44,2000);
  CRT_Ostream_Write(param_1,(int)this + 0x814,4);
  CRT_Ostream_Write(param_1,(int)this + 0x818,4);
  CRT_Ostream_Write(param_1,(int)this + 0x81c,4);
  CRT_Ostream_Write(param_1,(int)this + 0x820,4);
  CRT_Ostream_Write(param_1,(int)this + 0x824,1);
  CRT_Ostream_Write(param_1,(int)this + 0x40,4);
  CRT_Ostream_Write(param_1,(int)this + 0x825,1);
  CRT_Ostream_Write(param_1,(int)this + 0x14,4);
  CRT_Ostream_Write(param_1,(int)this + 0x18,4);
  CRT_Ostream_Write(param_1,(int)this + 0x1c,4);
  CRT_Ostream_Write(param_1,(int)this + 0x20,4);
  return;
}

