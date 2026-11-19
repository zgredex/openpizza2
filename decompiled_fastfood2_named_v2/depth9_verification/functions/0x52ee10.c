// rea decompile_all
// name: Dialog_InitBase
// address: 0x52ee10
// body: available
// range: 0x52ee10-0x52ef1b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Dialog_InitBase(void *this,void *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
                    /* Initializes fields shared by all dialog/window variants. */
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x2c0) = 0;
  *(undefined4 *)((int)this + 0x29c) = 0;
  *(undefined4 *)((int)this + 0xd8) = 0;
  *(undefined4 *)((int)this + 700) = 0;
  *(undefined4 *)((int)this + 0x13c) = 0;
  *(undefined4 *)((int)this + 0xf8) = 0;
  *(undefined4 *)((int)this + 0x16c) = 0;
  *(undefined4 *)((int)this + 0x48) = param_3;
  *(undefined4 *)((int)this + 0xe4) = 1;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x15c) = 0;
  *(undefined4 *)((int)this + 0x10c) = 0;
  *(undefined4 *)((int)this + 0x164) = 1;
  *(undefined1 *)((int)this + 0x178) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x94) = 0;
  *(undefined1 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x160) = 0;
  *(undefined4 *)((int)this + 0xe0) = 1;
  *(undefined4 *)((int)this + 0xec) = 0;
  *(undefined4 *)((int)this + 0x170) = 0;
  *(undefined4 *)((int)this + 0x134) = param_2;
  *(undefined4 *)((int)this + 0x114) = 0;
  *(undefined4 *)((int)this + 0xf0) = 0;
  *(undefined4 *)((int)this + 0xf4) = 0;
  *(undefined4 *)((int)this + 0xe8) = 0;
  *(undefined4 *)((int)this + 0x27c) = 0;
  *(undefined4 *)((int)this + 0x284) = 0;
  *(undefined4 *)((int)this + 0x28c) = 0;
  *(undefined4 *)((int)this + 0x168) = 0;
  *(undefined4 *)((int)this + 0x174) = 0;
  puVar1 = FUN_00539ea0(param_1);
  *(undefined4 **)((int)this + 0xdc) = puVar1;
  *(undefined4 *)((int)this + 0x138) = 0;
  *(undefined4 *)((int)this + 0x298) = 0;
  SetRect((LPRECT)((int)this + 0x38),-999,0,0,0);
  *(undefined4 *)((int)this + 0xfc) = 0xff000000;
  *(undefined4 *)((int)this + 0x100) = 0xff000000;
  *(undefined4 *)((int)this + 0x104) = 0xff000000;
  *(undefined4 *)((int)this + 0x108) = 0xff000000;
  return;
}

