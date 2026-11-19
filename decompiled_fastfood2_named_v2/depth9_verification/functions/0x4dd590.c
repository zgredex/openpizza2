// rea decompile_all
// name: GameCalendar_Load
// address: 0x4dd590
// body: available
// range: 0x4dd590-0x4dd64d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall GameCalendar_Load(void *this,void *param_1)

{
                    /* Loads the game clock fields and applies save-version defaults. */
  FUN_0054cbc1(param_1,(int)this + 7,1);
  FUN_0054cbc1(param_1,(int)this + 6,1);
  FUN_0054cbc1(param_1,(int)this + 8,1);
  FUN_0054cbc1(param_1,(int)this + 4,2);
  FUN_0054cbc1(param_1,(int)this + 10,2);
  FUN_0054cbc1(param_1,(int)this + 0xc,4);
  FUN_0054cbc1(param_1,(int)this + 0x19,1);
  FUN_0054cbc1(param_1,(int)this + 0x18,1);
  FUN_0054cbc1(param_1,(undefined4 *)((int)this + 0x14),4);
  *(undefined4 *)((int)this + 0x14) = 0xc35;
  FUN_0054cbc1(param_1,(int)this + 0x10,4);
  if (DAT_0057c668 < 0x2e) {
    DAT_0057dfbc = 2000;
    return;
  }
  FUN_0054cbc1(param_1,&DAT_0057dfbc,4);
  return;
}

