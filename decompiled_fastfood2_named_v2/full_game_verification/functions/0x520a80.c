// rea decompile_all
// name: UI_Child_Construct
// address: 0x520a80
// body: available
// range: 0x520a80-0x520ae2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
UI_Child_Construct(void *this,undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
                    /* Constructs the base UI child element. */
  *(int *)((int)this + 0x38) = param_2;
  *(int *)((int)this + 0x28) = param_2;
  *(int *)((int)this + 0x3c) = param_3;
  *(int *)((int)this + 0x2c) = param_3;
  *(undefined4 *)((int)this + 8) = param_4;
  *(int *)((int)this + 0x30) = param_2 + 100;
  *(int *)((int)this + 0x34) = param_3 + 0x14;
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined ***)this = &PTR_UI_Child_Delete_0055c720;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x14) = 1;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x20) = 1;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  return;
}

