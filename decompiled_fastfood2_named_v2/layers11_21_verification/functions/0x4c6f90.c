// rea decompile_all
// name: CharacterSelect_FillAttributes
// address: 0x4c6f90
// body: available
// range: 0x4c6f90-0x4c703f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl CharacterSelect_FillAttributes(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_20 [32];
  
                    /* Fills the character-selection attribute values and colors. */
  iVar2 = 0x418;
  piVar1 = &DAT_0057dd48;
  do {
    FUN_0054dd83(local_20,&DAT_005686f4,*piVar1);
    if (*piVar1 < 0) {
      uVar3 = 0xff;
    }
    else if (*piVar1 < 1) {
      uVar3 = 0;
    }
    else {
      uVar3 = 0xa000;
    }
    Window_GadgetNotify_Text_SetTextColor(param_1,iVar2,uVar3);
    Window_GadgetNotify_Text_SetText(param_1,iVar2,local_20);
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x57dd60);
  FUN_0054dd83(local_20,&DAT_005686f4,DAT_0057ddb4);
  if (DAT_0057ddb4 < 1) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xa000;
  }
  Window_GadgetNotify_Text_SetTextColor(param_1,0x41e,uVar3);
  Window_GadgetNotify_Text_SetText(param_1,0x41e,local_20);
  return;
}

