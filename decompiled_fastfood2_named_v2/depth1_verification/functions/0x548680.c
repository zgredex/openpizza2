// rea decompile_all
// name: Sound_SetMusicTrack
// address: 0x548680
// body: available
// range: 0x548680-0x548762 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Sound_SetMusicTrack(void *this,undefined4 param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined1 local_104 [260];
  
                    /* Depth-1 proposal batch 1. */
  if (*(char *)((int)this + 0xfc) == '\0') {
    return;
  }
  iVar1 = (int)this + 0x178;
  FUN_00401320(iVar1);
  FUN_00547fd0((int)this);
  *(undefined4 *)((int)this + 0x108) = param_1;
  switch(param_1) {
  case 1000:
    if (*(int *)((int)this + 0xc) != 0) {
      (**(code **)(**(int **)((int)this + 8) + 0x54))
                (*(int **)((int)this + 8),*(int *)((int)this + 0xc));
      *(undefined4 *)((int)this + 0xc) = 0;
      FUN_00401340(iVar1);
      return;
    }
    goto switchD_005486c7_default;
  case 0x3e9:
    pcVar2 = s_Music_Mus_City__s_0_wav_00576150;
    break;
  case 0x3ea:
    pcVar2 = s_Music_Mus_City__s_1_wav_00576138;
    break;
  case 0x3eb:
    pcVar2 = s_Music_Mus_City__s_2_wav_00576120;
    break;
  case 0x3ec:
    goto LAB_00548747;
  default:
    goto switchD_005486c7_default;
  }
  FUN_0054dd83(local_104,(byte *)pcVar2,(int)this + 0x174);
LAB_00548747:
  iVar3 = FUN_005474b0(this,local_104,2);
  *(int *)((int)this + 0xc) = iVar3;
switchD_005486c7_default:
  FUN_00401340(iVar1);
  return;
}

