// rea decompile_all
// name: FUN_0046cc70
// address: 0x46cc70
// body: available
// range: 0x46cc70-0x46d289 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0046cc70(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,FUN_004c67f0);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  FUN_0052f5b0(this,0x444,0x2f,0x38,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x445,0x2f,0x4d,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x446,0x2f,0x62,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x447,0x2f,0x77,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x448,0x2f,0x8c,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x449,0x2f,0xa1,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x44a,0x2f,0xb6,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,1099,0x2f,0xcb,s_TABPB01__00_spr_00564670,1,0);
  FUN_00531850(this,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  iVar1 = FUN_0052f850(this,0x440,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_00582f58);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x440,0);
    FUN_0052f9d0(this,0x440,2,0xbe,0,0);
  }
  iVar1 = FUN_0052f850(this,0x441,0x32,0x26,s_VERDANA10_fnt_00563e64,s__Zutaten_aussuchen__00566e48)
  ;
  if (iVar1 != 0) {
    FUN_0052f910(this,0x441,0);
    FUN_0052f9d0(this,0x441,0,0xb4,0,0);
  }
  iVar1 = FUN_0052fc00(this,0x42d,0xdc,0x40,0x109,s_SL01_00_spr_0056448c,0,1);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_0052fcc0(this,0x42d,&local_10);
  }
  iVar1 = FUN_0052f690(this,0x443,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582ae4,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x443,0,0,0);
    FUN_0052f7a0(this,0x443,2,0x54,0,0,0xfffe);
  }
  FUN_0052f5b0(this,0x44c,0x2f,0xe0,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x44d,0x2f,0xf5,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x44e,0x2f,0x10a,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x44f,0x2f,0x11f,s_TABPB01__00_spr_00564670,1,0);
  FUN_0052f5b0(this,0x450,0x2f,0x134,s_TABPB01__00_spr_00564670,1,0);
  iVar1 = FUN_0052f850(this,0x451,0x32,0x3b,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x451,0);
    FUN_0052f9d0(this,0x451,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x452,0x32,0x50,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x452,0);
    FUN_0052f9d0(this,0x452,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x453,0x32,0x65,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x453,0);
    FUN_0052f9d0(this,0x453,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x454,0x32,0x7a,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x454,0);
    FUN_0052f9d0(this,0x454,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x455,0x32,0x8f,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x455,0);
    FUN_0052f9d0(this,0x455,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x456,0x32,0xa4,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x456,0);
    FUN_0052f9d0(this,0x456,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x457,0x32,0xb9,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x457,0);
    FUN_0052f9d0(this,0x457,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x458,0x32,0xce,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x458,0);
    FUN_0052f9d0(this,0x458,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x459,0x32,0xe3,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x459,0);
    FUN_0052f9d0(this,0x459,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x45a,0x32,0xf8,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x45a,0);
    FUN_0052f9d0(this,0x45a,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x45b,0x32,0x10d,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x45b,0);
    FUN_0052f9d0(this,0x45b,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x45c,0x32,0x122,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x45c,0);
    FUN_0052f9d0(this,0x45c,0,0x9b,0,0);
  }
  iVar1 = FUN_0052f850(this,0x45d,0x32,0x137,s_VERDANA10_fnt_00563e64,s__Tomaten_00564be4);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x45d,0);
    FUN_0052f9d0(this,0x45d,0,0x9b,0,0);
  }
  return this;
}

