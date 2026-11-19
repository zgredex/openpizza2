// rea decompile_all
// name: FUN_0048b9b0
// address: 0x48b9b0
// body: available
// range: 0x48b9b0-0x48bad1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0048b9b0(void *this,int param_1,int param_2)

{
  void *this_00;
  int iVar1;
  int iVar2;
  
  iVar1 = param_2;
  if (param_1 == 1) {
    this_00 = (void *)((int)this + 0x304);
    iVar2 = FUN_0054b110(this_00,param_2,&param_1);
    if (*(int *)(iVar2 + 4) == 1) {
      if (*(int *)((int)this + 0x268) != 0) {
        if (*(int *)((int)this + 0x278) == 0x11d7) {
          return;
        }
        Game_CloseSelectionDialog((int)this);
      }
      FUN_00482930(this,param_1);
      FUN_00548040(DAT_0057ba0c,0x14);
      FUN_0054ae60(this_00,param_1);
      return;
    }
    if ((DAT_00567da0 != iVar1) && (*(int *)((int)this + 0x268) != 0)) {
      Game_CloseSelectionDialog((int)this);
    }
    FUN_00482c40(this,0xffffffff,DAT_00582408,iVar2 + 0x78,1,0,iVar1,'\0');
    FUN_00548040(DAT_0057ba0c,0x14);
    FUN_0054ae60(this_00,param_1);
  }
  else if (param_1 == 0x15) {
    if ((*(int *)((int)this + 0x278) == 1) && (*(int *)((int)this + 0x268) != 0)) {
      Game_CloseSelectionDialog((int)this);
    }
    FUN_0054b110((void *)((int)this + 0x304),param_2,&param_1);
    FUN_0054acc0((void *)((int)this + 0x304),param_1,0);
    FUN_00548040(DAT_0057ba0c,0x13);
    return;
  }
  return;
}

