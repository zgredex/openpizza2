// rea decompile_all
// name: FUN_00526640
// address: 0x526640
// body: available
// range: 0x526640-0x5266fc inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00526640(void *this,int param_1)

{
  int iVar1;
  
  if ((*(int *)((int)this + 0x230) != 0) && (*(int *)(*(int *)((int)this + 0x230) + 8) == param_1))
  {
    *(undefined4 *)((int)this + 0x230) = 0;
  }
  if (param_1 == *(int *)((int)this + 0x82c8)) {
    *(undefined4 *)((int)this + 0x82c8) = 0;
    *(undefined4 *)((int)this + 0x82d4) = 0;
  }
  if (param_1 == *(int *)((int)this + 0x224)) {
    *(undefined4 *)((int)this + 0x224) = 0;
    *(undefined4 *)((int)this + 0x22c) = 0;
  }
  if (param_1 == *(int *)((int)this + 0x82d0)) {
    if ((*(int *)((int)this + 0x82d0) != 0) && (*(int *)((int)this + 0x82dc) != 0)) {
      iVar1 = FUN_00520e00(*(int *)((int)this + 0x82dc));
      if (iVar1 != 0) {
        FUN_005301c0(*(void **)((int)this + 0x82d0),*(int *)(*(int *)((int)this + 0x82dc) + 4),0xd,0
                    );
      }
    }
    UI_RefreshChildRect(this);
    *(undefined4 *)((int)this + 0x82dc) = 0;
    *(undefined4 *)((int)this + 0x82d0) = 0;
  }
  if (param_1 == *(int *)((int)this + 0x8338)) {
    *(undefined4 *)((int)this + 0x833c) = 0;
    *(undefined4 *)((int)this + 0x8348) = 0;
  }
  if (param_1 == *(int *)((int)this + 0x228)) {
    FUN_00526d00((int)this);
  }
  return;
}

