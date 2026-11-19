// rea decompile_all
// name: Screen_BeginTileWipeTransition
// address: 0x51fb00
// body: available
// range: 0x51fb00-0x51fb42 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Screen_BeginTileWipeTransition(void *this,uint param_1,undefined4 param_2)

{
  DWORD DVar1;
  
                    /* Depth-3 proposal batch 1. */
  if (*(int *)((int)this + 0x34) != 0) {
    if (*(int *)((int)this + 8) != 0) {
      *(undefined4 *)((int)this + 0xc) = 0;
      FUN_0051fda0(this,param_1);
    }
    *(undefined4 *)((int)this + 8) = *(undefined4 *)((int)this + 0x34);
    DVar1 = timeGetTime();
    *(DWORD *)((int)this + 0xc) = DVar1;
    *(undefined4 *)((int)this + 0x10) = param_2;
    *(undefined4 *)((int)this + 0x14) = 1;
  }
  return;
}

