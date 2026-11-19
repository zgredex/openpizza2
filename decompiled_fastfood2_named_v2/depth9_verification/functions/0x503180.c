// rea decompile_all
// name: FUN_00503180
// address: 0x503180
// body: available
// range: 0x503180-0x503243 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00503180(void *this,int param_1,int param_2)

{
  void *this_00;
  uint uVar1;
  
  if (((*(char *)((int)this + 0x60) != '\0') && (param_1 == *(int *)((int)this + 0x48))) &&
     (param_2 < *(int *)((int)this + 0x7c))) {
    this_00 = (void *)(DAT_0057c670 + 0x304);
    FUN_0054acc0(this_00,*(int *)((int)this + 100),1);
    uVar1 = FUN_004034d0(0x13,0x1d);
    *(uint *)((int)this + 0x5c) = uVar1;
    *(undefined1 *)((int)this + 4) = 0;
    if ((*(int *)(DAT_0057c670 + 0x268) != 0) && (*(int *)(DAT_0057c670 + 0x278) == 0x11d7)) {
      FUN_00482890(DAT_0057c670);
    }
    if (*(char *)((int)this + 0x60) != '\0') {
      FUN_00503b20((int)this);
      UI_Briefing_AddMessage
                (this_00,0x24,0,-1,-1,0,DAT_00581c14,(byte *)s__s__s_005729bc,DAT_00582968);
      FUN_00503280((int)this);
    }
  }
  return;
}

