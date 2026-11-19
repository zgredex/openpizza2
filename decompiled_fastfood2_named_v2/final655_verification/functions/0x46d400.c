// rea decompile_all
// name: MissionOfferDialog_Create
// address: 0x46d400
// body: available
// range: 0x46d400-0x46d7c9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl MissionOfferDialog_Create(int *param_1)

{
  int iVar1;
  void *this;
  
                    /* Creates the mission-offer dialog. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c6cf0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x42d,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582d44);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x42d,0);
    FUN_0052f9d0(this,0x42d,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x42f,0x32,0x26,s_VERDANA7_fnt_00563ec8,&DAT_00566fe4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x42f,0);
    FUN_0052f9d0(this,0x42f,0,0xb4,100,3);
  }
  iVar1 = UI_AddTextButton(this,0x430,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_005821a0,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x430,0,0,0);
    FUN_0052f7a0(this,0x430,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddTextButton(this,0x431,0x8e,0x15b,s_VERDANA8_fnt_00563e98,DAT_00580b3c,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x431,0,0,0);
    FUN_0052f7a0(this,0x431,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f850(this,0x432,0x32,0x8d,s_VERDANA7_fnt_00563ec8,DAT_00580ae4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x432,0xce0000);
    FUN_0052f9d0(this,0x432,0,0xb4,0xffff,3);
  }
  iVar1 = FUN_0052f850(this,0x433,0x32,0xcd,s_VERDANA7_fnt_00563ec8,DAT_00581b94);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x433,0xce0000);
    FUN_0052f9d0(this,0x433,0,0xb4,0xffff,3);
  }
  iVar1 = FUN_0052f850(this,0x434,0x32,0x10d,s_VERDANA7_fnt_00563ec8,DAT_00581508);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x434,0xce0000);
    FUN_0052f9d0(this,0x434,0,0xb4,0xffff,3);
  }
  iVar1 = FUN_0052f850(this,0x435,0x32,0x13a,s_VERDANA7_fnt_00563ec8,DAT_0058189c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x435,0);
    FUN_0052f9d0(this,0x435,0,0xb4,0xffff,3);
  }
  iVar1 = FUN_0052f850(this,0x436,0x3e,0x9a,s_VERDANA7_fnt_00563ec8,&DAT_00566f64);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x436,0);
    FUN_0052f9d0(this,0x436,0,0xaa,0x32,3);
  }
  iVar1 = FUN_0052f850(this,0x437,0x3e,0xda,s_VERDANA7_fnt_00563ec8,&DAT_00566ef8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x437,0);
    FUN_0052f9d0(this,0x437,0,0xaa,0x32,3);
  }
  iVar1 = FUN_0052f850(this,0x438,0x3e,0x119,s_VERDANA7_fnt_00563ec8,DAT_00582aa0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x438,0);
    FUN_0052f9d0(this,0x438,0,0xaa,0xffff,3);
  }
  iVar1 = FUN_0052f850(this,0x439,0x3d,0x126,s_VERDANA7_fnt_00563ec8,
                       s__1__Quartal_2001_16_00_Uhr_00566edc);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x439,0xff);
    FUN_0052f9d0(this,0x439,1,0xaa,0xffff,3);
  }
  return this;
}

