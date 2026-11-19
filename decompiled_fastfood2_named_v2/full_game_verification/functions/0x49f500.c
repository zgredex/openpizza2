// rea decompile_all
// name: RecipeMenu_ShowSelectedRecipe
// address: 0x49f500
// body: available
// range: 0x49f500-0x49f573 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl RecipeMenu_ShowSelectedRecipe(void *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)IDMap_Lookup((void *)(DAT_0057cd98 + 0x110),DAT_0057cd9c,(int *)0x0);
  RecipeMenu_SetCurrentRecipe(param_1,puVar1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar2 = DAT_00581ad0;
  }
  else {
    puVar2 = puVar1 + 1;
  }
  Window_GadgetNotify_Text_SetText(param_1,0x40f,puVar2);
  *(undefined4 **)(DAT_0057c670 + 0x98) = puVar1;
  if (*(void **)(DAT_0057c670 + 0x264) != (void *)0x0) {
    UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x264),-0x18671,0x23,1);
  }
  return;
}

