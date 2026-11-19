// rea decompile_all
// name: Sprite_InitFormat
// address: 0x53a220
// body: available
// range: 0x53a220-0x53a26c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
Sprite_InitFormat(void *this,short param_1,undefined2 param_2,undefined4 param_3,int param_4,
                 undefined1 param_5,undefined2 param_6,undefined2 param_7)

{
  short sVar1;
  
  *(undefined2 *)((int)this + 10) = param_6;
  *(char *)((int)this + 5) = (char)param_4;
  *(undefined2 *)((int)this + 0xc) = param_7;
  *(undefined4 *)((int)this + 0x18) = 0;
  sVar1 = (short)(param_4 >> 3) * param_1;
  *(undefined1 *)((int)this + 4) = param_5;
  *(undefined4 *)((int)this + 0x1c) = param_3;
  *(undefined2 *)((int)this + 8) = param_2;
  *(undefined2 *)((int)this + 0x14) = param_2;
  *(short *)((int)this + 6) = sVar1;
  *(short *)((int)this + 0x12) = sVar1;
  return;
}

