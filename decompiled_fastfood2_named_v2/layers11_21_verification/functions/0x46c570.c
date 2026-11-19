// rea decompile_all
// name: FUN_0046c570
// address: 0x46c570
// body: available
// range: 0x46c570-0x46c68a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0046c570(int *param_1)

{
  int iVar1;
  void *this;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0xbb,0xf8,s_PE_RQ_LOADING_spr_00566d34,&LAB_004c6390);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x3e9,0xe,0x1b,s_VERDANA16_fnt_00565788,DAT_0058203c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x3e9,0);
    Window_GadgetNotify_Text_SetLayout(this,0x3e9,2,400,0,0);
  }
  iVar1 = FUN_0052f690(this,0x3f8,0xac,0x44,s_VERDANA8_fnt_00563e98,DAT_005827ac,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x3f8,0,0,0);
    Gadget_SetButtonTextLayout(this,0x3f8,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x3f9,0x10,0xd,s_VERDANA10_fnt_00563e64,DAT_00582140);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x3f9,0);
    Window_GadgetNotify_Text_SetLayout(this,0x3f9,2,400,0x36,2);
  }
  return this;
}

