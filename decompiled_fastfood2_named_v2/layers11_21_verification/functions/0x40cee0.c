// rea decompile_all
// name: SubMenu_BuildBranchBalance
// address: 0x40cee0
// body: available
// range: 0x40cee0-0x40da92 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl SubMenu_BuildBranchBalance(int *param_1)

{
  int iVar1;
  void *this;
  
                    /* Builds the branch-balance submenu page. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_0048ffd0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_00531850(this,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x42b,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_005823d8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x42b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x42b,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x43c,0x2f,0x15c,s_VEDANA11_fnt_00564090,DAT_00582bd8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x43c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x43c,0,0x6e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x466,0x87,0x15e,s_VERDANA10_fnt_00563e64,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x466,0);
    Window_GadgetNotify_Text_SetLayout(this,0x466,1,0x61,0,0);
  }
  FUN_00531850(this,0x467,0x27,0xf2,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x468,0x2f,0x24,s_VEDANA11_fnt_00564090,DAT_00582cf8);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x468,0);
    Window_GadgetNotify_Text_SetLayout(this,0x468,0,0x6e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x469,0x32,0x3a,s_VERDANA8_fnt_00563e98,DAT_0058106c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x469,0);
    Window_GadgetNotify_Text_SetLayout(this,0x469,0,0x76,0,0);
  }
  iVar1 = FUN_0052f850(this,0x46a,0x32,0x48,s_VERDANA8_fnt_00563e98,DAT_0058177c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x46a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x46a,0,0x76,0,0);
  }
  iVar1 = FUN_0052f850(this,0x46b,0x32,0x13a,s_VERDANA8_fnt_00563e98,DAT_00582b1c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x46b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x46b,0,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x46c,0x2f,0xfc,s_VEDANA11_fnt_00564090,DAT_00580d4c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x46c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x46c,0,0x6e,0,0);
  }
  iVar1 = FUN_0052f850(this,0x46d,0x32,0x120,s_VERDANA8_fnt_00563e98,DAT_00581d68);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x46d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x46d,0,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x46e,0x32,0x113,s_VERDANA8_fnt_00563e98,DAT_00582d6c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x46e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x46e,0,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x46f,0x2b,0x103,s_VERDANA8_fnt_00563e98,
                       s_________________________00564070);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x46f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x46f,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x470,0x2b,0x2b,s_VERDANA8_fnt_00563e98,
                       s_________________________00564070);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x470,0);
    Window_GadgetNotify_Text_SetLayout(this,0x470,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x471,0x88,0x26,s_VERDANA10_fnt_00563e64,s__12323742__00564064);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x471,0);
    Window_GadgetNotify_Text_SetLayout(this,0x471,1,0x61,0,0);
  }
  iVar1 = FUN_0052f850(this,0x472,0x98,0x48,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x472,0);
    Window_GadgetNotify_Text_SetLayout(this,0x472,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x473,0x98,0x3a,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x473,0);
    Window_GadgetNotify_Text_SetLayout(this,0x473,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x474,0x88,0xfe,s_VERDANA10_fnt_00563e64,s__12323742__00564064);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x474,0);
    Window_GadgetNotify_Text_SetLayout(this,0x474,1,0x61,0,0);
  }
  iVar1 = FUN_0052f850(this,0x475,0x98,0x113,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x475,0);
    Window_GadgetNotify_Text_SetLayout(this,0x475,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x476,0x98,0x120,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x476,0);
    Window_GadgetNotify_Text_SetLayout(this,0x476,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x477,0x98,0x13a,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x477,0);
    Window_GadgetNotify_Text_SetLayout(this,0x477,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x478,0x32,0x55,s_VERDANA8_fnt_00563e98,DAT_00580b64);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x478,0);
    Window_GadgetNotify_Text_SetLayout(this,0x478,0,0x76,0,0);
  }
  iVar1 = FUN_0052f850(this,0x479,0x32,99,s_VERDANA8_fnt_00563e98,DAT_00582a10);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x479,0);
    Window_GadgetNotify_Text_SetLayout(this,0x479,0,0x76,0,0);
  }
  iVar1 = FUN_0052f850(this,0x47a,0x98,99,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47a,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x47b,0x98,0x55,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47b,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x47c,0x32,0x7e,s_VERDANA8_fnt_00563e98,DAT_00582a9c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47c,0,0x76,0,0);
  }
  iVar1 = FUN_0052f850(this,0x47d,0x32,0xa2,s_VERDANA8_fnt_00563e98,DAT_00582df4);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47d,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47d,0,0x76,0,0);
  }
  iVar1 = FUN_0052f850(this,0x47e,0x98,0xa2,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47e,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47e,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x47f,0x98,0x7e,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x47f,0);
    Window_GadgetNotify_Text_SetLayout(this,0x47f,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x480,0x32,0xe1,s_VERDANA8_fnt_00563e98,DAT_00582b1c);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x480,0);
    Window_GadgetNotify_Text_SetLayout(this,0x480,0,0x76,0,0);
  }
  iVar1 = FUN_0052f850(this,0x481,0x32,0xb0,s_VERDANA8_fnt_00563e98,DAT_00581d30);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x481,0);
    Window_GadgetNotify_Text_SetLayout(this,0x481,0,0x76,0,0);
  }
  iVar1 = FUN_0052f850(this,0x482,0x98,0xb0,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x482,0);
    Window_GadgetNotify_Text_SetLayout(this,0x482,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x483,0x98,0xe1,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x483,0);
    Window_GadgetNotify_Text_SetLayout(this,0x483,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x484,0x32,0xc5,s_VERDANA8_fnt_00563e98,DAT_00580f18);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x484,0);
    Window_GadgetNotify_Text_SetLayout(this,0x484,0,0x76,0,0);
  }
  iVar1 = FUN_0052f850(this,0x485,0x32,0xd3,s_VERDANA8_fnt_00563e98,DAT_00581944);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x485,0);
    Window_GadgetNotify_Text_SetLayout(this,0x485,0,0x76,0,0);
  }
  iVar1 = FUN_0052f850(this,0x486,0x98,0xd3,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x486,0);
    Window_GadgetNotify_Text_SetLayout(this,0x486,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x487,0x98,0xc5,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x487,0);
    Window_GadgetNotify_Text_SetLayout(this,0x487,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x488,0x32,0x12d,s_VERDANA8_fnt_00563e98,DAT_00581d30);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x488,0);
    Window_GadgetNotify_Text_SetLayout(this,0x488,0,100,0,0);
  }
  iVar1 = FUN_0052f850(this,0x489,0x98,0x12d,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x489,0);
    Window_GadgetNotify_Text_SetLayout(this,0x489,1,0x50,0,0);
  }
  iVar1 = FUN_0052f850(this,0x48a,0x2b,0x6d,s_VERDANA8_fnt_00563e98,s________________00564054);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x48a,0);
    Window_GadgetNotify_Text_SetLayout(this,0x48a,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x48b,0x2b,0x93,s_VERDANA8_fnt_00563e98,s________________00564054);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x48b,0);
    Window_GadgetNotify_Text_SetLayout(this,0x48b,0,0,0,0);
  }
  iVar1 = FUN_0052f850(this,0x48c,0x2b,0xb6,s_VERDANA8_fnt_00563e98,s________________00564054);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x48c,0);
    Window_GadgetNotify_Text_SetLayout(this,0x48c,0,0,0,0);
  }
  FUN_0052f5b0(this,8000,0xb,-1,s_HILFEBUTTONSNIP_00_spr_00563e4c,1,0);
  iVar1 = FUN_0052f850(this,0x1f41,0x32,0x8c,s_VERDANA8_fnt_00563e98,DAT_00582b94);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f41,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f41,0,0x76,0,0);
  }
  iVar1 = FUN_0052f850(this,0x1f42,0x98,0x8c,s_VERDANA8_fnt_00563e98,s__23742__00564088);
  if (iVar1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(this,0x1f42,0);
    Window_GadgetNotify_Text_SetLayout(this,0x1f42,1,0x50,0,0);
  }
  return this;
}

