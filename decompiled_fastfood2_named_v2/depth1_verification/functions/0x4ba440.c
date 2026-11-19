// rea decompile_all
// name: FUN_004ba440
// address: 0x4ba440
// body: available
// range: 0x4ba440-0x4ba57c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004ba440(void *param_1)

{
  void *pvVar1;
  int iVar2;
  
  FUN_0052f9b0(param_1,0x40f,(int)DAT_0057d6e8 + 4);
  *(void **)((int)DAT_0057c670 + 0x9c) = DAT_0057d6e8;
  Sound_SelectCurrentTrack(DAT_0057ba0c);
  FUN_00488de0(DAT_0057c670,(int)DAT_0057d6e8);
  FUN_00548430(DAT_0057ba0c,(int)DAT_0057d6e8);
  pvVar1 = DAT_0057c670;
  if (*(int *)((int)DAT_0057c670 + 0x21c) != 0) {
    *(undefined4 *)((int)DAT_0057c670 + 0x21c) = 0;
    *(undefined4 *)((int)pvVar1 + 0x2da8) = 1;
    *(undefined4 *)((int)DAT_0057c670 + 0x2e4) = 0;
    FUN_00482880((int)DAT_0057c670);
    pvVar1 = DAT_0057c670;
    *(undefined4 *)((int)DAT_0057c670 + 0x2c8) = *(undefined4 *)((int)DAT_0057c670 + 0x2a8);
    *(undefined4 *)((int)pvVar1 + 0x2a8) = 1;
    iVar2 = FUN_004844c0((int)DAT_0057c670);
    FUN_00523d60(DAT_0057c5e0,iVar2);
  }
  iVar2 = Game_CountObjectsByType(DAT_0057d6e8,1);
  if ((iVar2 == 0) &&
     (*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x290) * 4 + 0x298) == 8)) {
    FUN_005301c0(param_1,-0x18697,0x23,0);
  }
  else {
    FUN_004cfa20(*(void **)((int)DAT_0057c670 + 0x260));
  }
  FUN_0048e6d0(param_1);
  FUN_005301c0(*(void **)((int)DAT_0057c670 + 0x264),-0x18642,0x23,
               *(int *)((int)DAT_0057d6e8 + 0x3c));
  return;
}

