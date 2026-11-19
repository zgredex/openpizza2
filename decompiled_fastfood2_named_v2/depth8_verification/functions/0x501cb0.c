// rea decompile_all
// name: FUN_00501cb0
// address: 0x501cb0
// body: available
// range: 0x501cb0-0x501de6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00501cb0(void *this,void *param_1)

{
  void *this_00;
  int iVar1;
  void *local_4;
  
  this_00 = param_1;
  local_4 = this;
  CRT_Ostream_Write(param_1,(int)this + 4,1);
  CRT_Ostream_Write(this_00,(int)this + 0xc,0x34);
  CRT_Ostream_Write(this_00,(int)this + 0x44,4);
  CRT_Ostream_Write(this_00,(int)this + 0x40,4);
  CRT_Ostream_Write(this_00,(int)this + 0x48,4);
  CRT_Ostream_Write(this_00,(int)this + 0x4c,4);
  CRT_Ostream_Write(this_00,(int)this + 0x50,4);
  CRT_Ostream_Write(this_00,(int)this + 0x54,4);
  CRT_Ostream_Write(this_00,(int)this + 0x58,4);
  CRT_Ostream_Write(this_00,(int)this + 0x5c,4);
  CRT_Ostream_Write(this_00,(int)this + 0x60,1);
  CRT_Ostream_Write(this_00,(int)this + 100,4);
  CRT_Ostream_Write(this_00,(int)this + 0x84,4);
  CRT_Ostream_Write(this_00,(int)this + 8,4);
  CRT_Ostream_Write(this_00,(int)this + 0x88,0xe4);
  CRT_Ostream_Write(this_00,(int)this + 0x16c,0xe4);
  param_1 = *(void **)((int)this + 0x7c);
  CRT_Ostream_Write(this_00,&param_1,4);
  iVar1 = 0;
  if (0 < (int)param_1) {
    do {
      local_4 = (void *)FUN_004017f0((void *)((int)this + 0x68),iVar1,(int *)0x0);
      CRT_Ostream_Write(this_00,&local_4,4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)param_1);
  }
  return;
}

