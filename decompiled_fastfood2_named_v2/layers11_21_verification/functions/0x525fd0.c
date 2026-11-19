// rea decompile_all
// name: Window_DispatchWindowMessage
// address: 0x525fd0
// body: available
// range: 0x525fd0-0x5260bc inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Window_DispatchWindowMessage(void *this,uint param_1,void *param_2,uint param_3)

{
                    /* Dispatches one Windows message to key, mouse, or hover handlers. */
  if (param_1 < 0x1f5) {
    if (param_1 == 500) {
      FUN_005311a0(param_2,param_3);
      return;
    }
    if (param_1 == 0x100) {
      FUN_005247f0(this,(int)param_2);
      return;
    }
    if (param_1 == 0x102) {
      FUN_005247f0(this,(int)param_2);
      return;
    }
    if (param_1 == 0x104) {
      if ((param_2 == (void *)0x58) || (param_2 == (void *)0x73)) {
        if (*(int *)((int)this + 0x8304) == 0) {
          SetEvent(DAT_0057c0d8);
          return;
        }
        FUN_00525bc0(this,*(int *)((int)this + 0x8304),0,(int)this,0x17,(int)param_2);
        return;
      }
      if (param_2 == (void *)0x79) {
        FUN_00526200(this);
        return;
      }
    }
  }
  else {
    switch(param_1) {
    case 0x200:
    case 0x201:
    case 0x202:
    case 0x204:
    case 0x205:
      Window_DispatchMouseEvent(this,param_1,param_3 & 0xffff,param_3 >> 0x10,(uint)param_2);
      return;
    case 0x20a:
      FUN_00524860(this,param_1,(int)param_2,param_3);
    }
  }
  return;
}

