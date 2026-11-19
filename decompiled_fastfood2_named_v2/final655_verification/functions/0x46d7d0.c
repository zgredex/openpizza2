// rea decompile_all
// name: UI_CreateMessageBoxSubmenu
// address: 0x46d7d0
// body: available
// range: 0x46d7d0-0x46d906 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl UI_CreateMessageBoxSubmenu(int *param_1)

{
  int iVar1;
  void *this;
  
                    /* Creates the small submenu message window and reply list. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c6dd0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x42b,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581644);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x42b,0);
    FUN_0052f9d0(this,0x42b,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x42c,0x32,0x26,s_VEDANA11_fnt_00564090,s__Selbst_Schuld__00567104);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x42c,0);
    FUN_0052f9d0(this,0x42c,2,0xb4,0x122,2);
  }
  iVar1 = UI_AddTextButton(this,0x42e,0x8e,0x15b,s_VERDANA8_fnt_00563e98,DAT_00580b3c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x42e,0,0,0);
    FUN_0052f7a0(this,0x42e,2,0x54,0,0,0xfffe);
  }
  return this;
}

