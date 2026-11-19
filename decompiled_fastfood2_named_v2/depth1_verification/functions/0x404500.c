// rea decompile_all
// name: FUN_00404500
// address: 0x404500
// body: available
// range: 0x404500-0x40475c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00404500(void)

{
  undefined4 *puVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557c56;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  puVar1 = operator_new(0x1ac4);
  local_4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_0057c5d8 = (undefined4 *)0x0;
  }
  else {
    DAT_0057c5d8 = FUN_00401970(puVar1);
  }
  DAT_0057c5d8[0x6ae] = 0;
  local_4 = 0xffffffff;
  FUN_004029e0(DAT_0057c5d8,s_sprites__00563b44,&DAT_00563b50);
  FUN_004029e0(DAT_0057c5d8,s_sprites__00563b44,&DAT_00563b40);
  FUN_004029e0(DAT_0057c5d8,s_fonts__00563b34,&DAT_00563b3c);
  FUN_004029e0(DAT_0057c5d8,s_pictures__00563b24,&DAT_00563b30);
  FUN_004029e0(DAT_0057c5d8,s_pictures__00563b24,&DAT_00563b20);
  FUN_004029e0(DAT_0057c5d8,s_daten__00563b14,&DAT_00563b1c);
  FUN_004029e0(DAT_0057c5d8,s_daten__00563b14,&DAT_00563b10);
  FUN_004029e0(DAT_0057c5d8,s_daten__00563b14,&DAT_00563b0c);
  FUN_004029e0(DAT_0057c5d8,s_movies__00563b00,&DAT_00563b08);
  FUN_004029e0(DAT_0057c5d8,s_update__00563af4,&DAT_00563afc);
  ResourceManager_OpenArchivePath(DAT_0057c5d8);
  ResourceManager_OpenArchivePath(DAT_0057c5d8);
  ResourceManager_OpenArchivePath(DAT_0057c5d8);
  FUN_00401cf0(DAT_0057c5d8,s_SpriteResource_00563ac0);
  puVar1 = operator_new(0x1ac4);
  local_4 = 1;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_0057c5dc = (undefined4 *)0x0;
  }
  else {
    DAT_0057c5dc = FUN_00401970(puVar1);
  }
  DAT_0057c5dc[0x6ae] = 0;
  local_4 = 0xffffffff;
  FUN_004029e0(DAT_0057c5dc,s_Isodaten_Sprites__00563aac,&DAT_00563b50);
  FUN_004029e0(DAT_0057c5dc,s_Isodaten_Anims__00563a9c,&DAT_00563b40);
  FUN_004029e0(DAT_0057c5dc,s_Backgrounds__00563a8c,&DAT_00563b20);
  FUN_004029e0(DAT_0057c5dc,s_Backgrounds__00563a8c,&DAT_00563b30);
  FUN_004029e0(DAT_0057c5dc,s_Isokarten__00563a7c,&DAT_00563a88);
  FUN_004029e0(DAT_0057c5dc,s_Isodaten__00563a6c,&DAT_00563a78);
  FUN_004029e0(DAT_0057c5dc,s_Isodaten__00563a6c,&DAT_00563a68);
  ResourceManager_OpenArchivePath(DAT_0057c5dc);
  ExceptionList = local_c;
  return;
}

