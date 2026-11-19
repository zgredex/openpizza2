// rea decompile_all
// name: FUN_00523f10
// address: 0x523f10
// body: available
// range: 0x523f10-0x523fd7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00523f10(void *this,int param_1)

{
  void *this_00;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  this_00 = (void *)UI_FindWindowByID(this,param_1,(int *)0x0);
  if ((this_00 != (void *)0x0) && (*(int *)((int)this_00 + 0x4c) != 0)) {
    local_10 = *(int *)((int)this_00 + 8);
    local_c = *(undefined4 *)((int)this_00 + 0xc);
    local_8 = *(undefined4 *)((int)this_00 + 0x10);
    local_4 = *(undefined4 *)((int)this_00 + 0x14);
    Rect_Set1A4(this,&local_10);
    *(undefined4 *)((int)this + 0x83b8) = 1;
    FUN_00532890(this_00,0);
    if ((*(void **)((int)this + 0x82c8) == this_00) && (*(int **)((int)this + 0x82d4) != (int *)0x0)
       ) {
      (**(code **)(**(int **)((int)this + 0x82d4) + 0xc))(5,0,(int)this + 0x835c);
      *(undefined4 *)((int)this + 0x22c) = 0;
      *(undefined4 *)((int)this + 0x224) = 0;
    }
    FUN_00526640(this,(int)this_00);
    FUN_0054a660(DAT_0057c1e0,0xff0000,(byte *)s_hide_window__d_0057421c,param_1);
  }
  return;
}

