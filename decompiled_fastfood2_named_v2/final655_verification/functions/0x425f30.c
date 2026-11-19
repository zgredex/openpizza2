// rea decompile_all
// name: GraphicsOptionsPage_Create
// address: 0x425f30
// body: available
// range: 0x425f30-0x4261f4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl GraphicsOptionsPage_Create(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Creates the graphics settings page. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a0840);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = FUN_0052f850(this,0x44f,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00581c1c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x44f,0);
    FUN_0052f9d0(this,0x44f,2,0xbe,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  FUN_00531850(this,0x1f50,0x27,0x10a,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddTextButton(this,0x1f51,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582748,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x1f51,0,0,0);
    FUN_0052f7a0(this,0x1f51,2,0xb4,0,0,0xfffe);
  }
  UI_CreateBitmapGadget(this,0x1f52,0x39,0x3a,0xaa,0xaa,0x10);
  iVar1 = UI_CreateSlider(this,0x1f53,0x51,0xf3,0x8c,s_SL02_00_spr_005642d0,0,0);
  if (iVar1 != 0) {
    local_10 = 0xffff;
    local_c = 0xf300;
    local_8 = 0xff;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f53,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x1f54,0x33,0x2a,s_VERDANA8_fnt_00563e98,DAT_00582ac4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f54,0);
    FUN_0052f9d0(this,0x1f54,2,0xb4,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f5d,0x44,0x118,s_VERDANA8_fnt_00563e98,DAT_00581028);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f5d,0);
    FUN_0052f9d0(this,0x1f5d,2,0x96,0,0);
  }
  FUN_00531850(this,0x1f5f,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x1f60,0x45,0x137,s_VERDANA8_fnt_00563e98,s_vordammt_hoch_00564d38);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x1f60,0);
    FUN_0052f9d0(this,0x1f60,2,0x96,0,0);
  }
  iVar1 = UI_CreateSlider(this,0x1f5e,0x4b,0x12f,0x8c,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xf300;
    local_c = 0xffff;
    local_8 = 0xff;
    local_4 = 0;
    FUN_0052fcc0(this,0x1f5e,&local_10);
  }
  return this;
}

