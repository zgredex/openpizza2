// rea decompile_all
// name: HeadquartersExpansionPage_Create
// address: 0x427bb0
// body: available
// range: 0x427bb0-0x4281de inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl HeadquartersExpansionPage_Create(int *param_1)

{
  int iVar1;
  void *this;
  
                    /* Creates the headquarters expansion page. */
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004a3060);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(this,0x43c,0x32,0x4b,s_NEWAERGERN_spr_0056500c);
  UI_AddSprite(this,0x43d,0x32,0x6c,s_NEWANGREIFEN_spr_00564ff8);
  UI_AddSprite(this,0x43e,0x32,0x8d,s_NEWBILANZ_spr_00564fe8);
  UI_AddSprite(this,0x43f,0x32,0xae,s_NEWGANGSTER_spr_00564fd8);
  UI_AddSprite(this,0x440,0x32,0xcf,s_NEWINNENARCHI_spr_00564fc4);
  UI_AddSprite(this,0x441,0x32,0x4b,s_NEWKONKURENT_spr_00564fb0);
  UI_AddSprite(this,0x442,0x32,0xae,s_NEWMANAGER_spr_00564fa0);
  UI_AddSprite(this,0x443,0x32,0x6c,s_NEWPOLIZEI_spr_00564f90);
  UI_AddSprite(this,0x444,0x32,0xcf,s_NEWREZEPTAUTO_spr_00564f7c);
  UI_AddSprite(this,0x445,0x32,0x8d,s_NEWSCHUTZ_spr_00564f6c);
  UI_AddSprite(this,0x446,0x32,0x6c,s_NEWWERBUNG_spr_00564f5c);
  UI_AddSprite(this,0x447,0x32,0x4b,s_NEWWETTBEWERB_spr_00564f48);
  UI_AddSprite(this,0x43b,0x2c,0x12a,s_TABHQ_spr_00564f3c);
  UI_AddSprite(this,0x408,0x27,0x129,s_TRENNZEILE_spr_00563eb8);
  UI_AddSprite(this,0x409,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x448,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582be0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x448,0);
    Window_GadgetNotify_Text_SetLayout(this,0x448,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x449,0x2f,0xfe,s_VERDANA8_fnt_00563e98,DAT_00581fc0);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x449,0);
    Window_GadgetNotify_Text_SetLayout(this,0x449,0,0x3c,0,0);
  }
  iVar1 = UI_AddText(this,0x44a,0x2f,0x116,s_VERDANA8_fnt_00563e98,DAT_0058176c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x44a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x44a,0,0x37,0,0);
  }
  iVar1 = UI_AddText(this,1099,0x2f,0x23,s_VERDANA10_fnt_00563e64,DAT_00582e6c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,1099,0);
    Window_GadgetNotify_Text_SetLayout(this,1099,2,0xb4,0x23,0);
  }
  iVar1 = UI_AddTextButton(this,0x44d,0x8e,0x112,s_VERDANA8_fnt_00563e98,DAT_00582d84,0,
                           s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    Gadget_SetButtonColors(this,0x44d,0,0,0);
    Gadget_SetButtonTextLayout(this,0x44d,2,0x54,0,0,0xfffe);
  }
  iVar1 = UI_AddText(this,0x44f,0x61,0xfe,s_VERDANA8_fnt_00563e98,s__3424__00564f34);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x44f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x44f,1,0x50,0,0);
  }
  iVar1 = UI_AddText(this,0x450,0x5d,0x116,s_VERDANA8_fnt_00563e98,s__3Tage_00563e7c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x450,0);
    Window_GadgetNotify_Text_SetLayout(this,0x450,1,0x32,0,0);
  }
  iVar1 = UI_AddText(this,0x451,0x55,0x4b,s_VERDANA8_fnt_00563e98,&DAT_00564f30);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x451,0);
    Window_GadgetNotify_Text_SetLayout(this,0x451,0,0x91,0x21,0);
  }
  iVar1 = UI_AddText(this,0x456,0x55,0x6d,s_VERDANA8_fnt_00563e98,&DAT_00564f30);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x456,0);
    Window_GadgetNotify_Text_SetLayout(this,0x456,0,0x91,0x21,0);
  }
  iVar1 = UI_AddText(this,0x457,0x55,0xae,s_VERDANA8_fnt_00563e98,&DAT_00564f30);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x457,0);
    Window_GadgetNotify_Text_SetLayout(this,0x457,0,0x91,0x21,0);
  }
  iVar1 = UI_AddText(this,0x458,0x55,0x8c,s_VERDANA8_fnt_00563e98,&DAT_00564f30);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x458,0);
    Window_GadgetNotify_Text_SetLayout(this,0x458,0,0x91,0x21,0);
  }
  iVar1 = UI_AddText(this,0x459,0x54,0xcf,s_VERDANA8_fnt_00563e98,&DAT_00564f30);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x459,0);
    Window_GadgetNotify_Text_SetLayout(this,0x459,0,0x91,0x21,0);
  }
  UI_CreateBitmapGadget(this,0x45a,0x50,0x130,0xf,0x37,0x10);
  UI_CreateBitmapGadget(this,0x45b,0x6a,0x130,0xf,0x37,0x10);
  UI_CreateBitmapGadget(this,0x45c,0x83,0x130,0xf,0x37,0x10);
  UI_CreateBitmapGadget(this,0x45d,0x9d,0x130,0xf,0x37,0x10);
  UI_CreateBitmapGadget(this,0x45e,0xb8,0x130,0xf,0x37,0x10);
  UI_CreateBitmapGadget(this,0x45f,0xd3,0x130,0xf,0x37,0x10);
  UI_AddImage(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  UI_AddSprite(this,0x1f41,0x48,0x15d,s_LOGOS__07_spr_00564f20);
  UI_AddSprite(this,0x1f42,0x62,0x15e,s_LOGOS__01_spr_00564f10);
  UI_AddSprite(this,0x1f43,0x7d,0x15d,s_LOGOS__02_spr_00564f00);
  UI_AddSprite(this,0x1f44,0xcc,0x15d,s_LOGOS__05_spr_00564ef0);
  UI_AddSprite(this,0x1f45,0x95,0x15e,s_LOGOS__06_spr_00564ee0);
  UI_AddSprite(this,0x1f46,0xb1,0x15e,s_LOGOS__08_spr_00564ed0);
  return this;
}

