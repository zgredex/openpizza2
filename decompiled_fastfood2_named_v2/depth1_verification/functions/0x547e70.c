// rea decompile_all
// name: Sound_SelectCurrentTrack
// address: 0x547e70
// body: available
// range: 0x547e70-0x547fa2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Sound_SelectCurrentTrack(void *param_1)

{
  int iVar1;
  undefined1 local_104 [260];
  
                    /* Selects the current sound track from game state. */
  FUN_00401320((int)param_1 + 0x178);
  iVar1 = -1;
  if (DAT_0057c670 == 0) {
    iVar1 = 0;
  }
  else {
    switch(*(undefined4 *)(DAT_0057c670 + 0x290)) {
    case 4:
      if (*(int *)(DAT_0057c670 + 0x9c) == 0) {
        iVar1 = -1;
      }
      else {
        iVar1 = *(int *)(*(int *)(DAT_0057c670 + 0x9c) + 0x14d8);
        if (iVar1 != -1) {
          iVar1 = iVar1 + 3;
          break;
        }
      }
      FUN_00547fd0((int)param_1);
      break;
    case 5:
      iVar1 = 2;
      break;
    case 6:
    case 7:
      iVar1 = 1;
      break;
    case 9:
    case 10:
    case 0xb:
    case 0xc:
      if (*(int *)((int)param_1 + 0x10) != 0) {
        (**(code **)(**(int **)((int)param_1 + 8) + 0x54))
                  (*(int **)((int)param_1 + 8),*(int *)((int)param_1 + 0x10));
        *(undefined4 *)((int)param_1 + 0x10) = 0;
        *(undefined4 *)((int)param_1 + 0x14) = 0;
      }
    case 0x16:
      iVar1 = 0;
    }
  }
  if (((*(int *)((int)param_1 + 0x108) < 1000) || (iVar1 != -1)) &&
     ((iVar1 != *(int *)((int)param_1 + 0x108) || (*(int *)((int)param_1 + 0xc) == 0)))) {
    FUN_00547fd0((int)param_1);
    *(int *)((int)param_1 + 0x108) = iVar1;
    if (((iVar1 != -1) && (*(char *)((int)param_1 + 0xfc) != '\0')) &&
       (*(int *)((int)param_1 + 0x1d4) != 0)) {
      FUN_0054dd83(local_104,(byte *)s_Music__s_005760e0,
                   (&PTR_s_Mus_Menue_Start_wav_00575220)[iVar1]);
      iVar1 = FUN_005474b0(param_1,local_104,2);
      *(int *)((int)param_1 + 0xc) = iVar1;
    }
  }
  FUN_00401340((int)param_1 + 0x178);
  return;
}

