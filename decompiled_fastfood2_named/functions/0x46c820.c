// rea decompile_all
// name: FUN_0046c820
// address: 0x46c820
// body: available
// range: 0x46c820-0x46cac2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl FUN_0046c820(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = UI_CreateWindow(DAT_0057c5e0,0x231,0xda,s_SUBMENUE_spr_0056402c,&LAB_004c6640);
  *param_1 = iVar1;
  this = (void *)UI_FindWindowByID(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddSprite(this,0x42d,0x39,0xde,s_RAHMEN01_spr_00566790);
  UI_AddSprite(this,0x429,0x27,0x14c,s_TRENNZEILE_spr_00563eb8);
  iVar1 = UI_AddText(this,0x42f,0x2c,5,s_TIMESFONT_fnt_00563ea8,DAT_0058159c);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x42f,0);
    FUN_0052f9d0(this,0x42f,2,0xbe,0,0);
  }
  iVar1 = UI_AddText(this,0x431,0x32,0x26,s_VERDANA10_fnt_00563e64,
                     s__Geben_Sie_den_Betrag_ein__00566da8);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x431,0);
    FUN_0052f9d0(this,0x431,2,0xb4,0x7d,2);
  }
  iVar1 = FUN_0052fc00(this,0x42e,0x42,0xbf,0x96,s_SLHOR01_00_spr_00564660,0,0);
  if (iVar1 != 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_0052fcc0(this,0x42e,&local_10);
  }
  iVar1 = FUN_0052f690(this,0x434,0x30,0x15b,s_VERDANA8_fnt_00563e98,DAT_00582ae4,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x434,0,0,0);
    FUN_0052f7a0(this,0x434,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052f690(this,0x435,0x8e,0x15b,s_VERDANA8_fnt_00563e98,DAT_00580b3c,0,
                       s_TEXTPB01__00_spr_00563e84);
  if (iVar1 != 0) {
    FUN_0052f750(this,0x435,0,0,0);
    FUN_0052f7a0(this,0x435,2,0x54,0,0,0xfffe);
  }
  iVar1 = FUN_0052fa40(this,0x436,0x3d,0xe8,s_VERDANA10_fnt_00563e64,s__hgjghjghjghjghj_00566d94,
                       0xa0);
  if (iVar1 != 0) {
    FUN_0052fb40(this,0x436,0);
    FUN_0052fb60(this,0x436,0);
    FUN_0052fb80(this,0x436,0x868686);
    FUN_0052fba0(this,0x436,0xff);
  }
  iVar1 = FUN_0052fa40(this,0x437,0x5b,0xe9,s_VERDANA10_fnt_00563e64,s__hgjghjghjghjghj_00566d94,100
                      );
  if (iVar1 != 0) {
    FUN_0052fb40(this,0x437,0);
    FUN_0052fb60(this,0x437,0);
    FUN_0052fb80(this,0x437,0x868686);
    FUN_0052fba0(this,0x437,0xff);
  }
  return this;
}

