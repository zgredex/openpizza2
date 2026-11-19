// rea decompile_all
// name: Glossary_FillCityBuildingList
// address: 0x4aec60
// body: available
// range: 0x4aec60-0x4aecb8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Glossary_FillCityBuildingList(void *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(&DAT_0058404c + param_2 * 4);
  iVar3 = 0x3e9;
  do {
    Window_GadgetNotify_Button_SetState
              (param_1,iVar3,(uint)(iVar3 + -0x3e9 + param_2 == DAT_0057d64c));
    Window_GadgetNotify_Text_SetText(param_1,iVar3 + 0x36,*puVar2);
    puVar2 = puVar2 + 1;
    iVar1 = iVar3 + -1000;
    iVar3 = iVar3 + 1;
  } while (iVar1 < 0xd);
  return;
}

