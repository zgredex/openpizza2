// rea decompile_all
// name: RecipeList_SelectRecipe
// address: 0x498e20
// body: available
// range: 0x498e20-0x498ee7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl RecipeList_SelectRecipe(void *param_1,int param_2)

{
  void *this;
  int iVar1;
  int iVar2;
  
                    /* Selects a recipe and refreshes its summary and rating bars. */
  iVar2 = 0;
  do {
    Window_GadgetNotify_Button_SetState(param_1,iVar2 + 0x461,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  Window_GadgetNotify_Button_SetState(param_1,param_2,1);
  DAT_0057c9fc = *(int *)(DAT_0057ca08 + -0x1184 + (DAT_0057ca00 + param_2) * 4);
  this = (void *)IDMap_Lookup((void *)(*(int *)(DAT_0057c670 + 0x200 +
                                               *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x110),
                              DAT_0057c9fc,(int *)0x0);
  *(void **)(DAT_0057c670 + 0x98) = this;
  UI_QueueControlCommand(*(void **)(DAT_0057c670 + 0x25c),-0x18671,0x23,DAT_0057c9fc);
  BranchList_UpdateSummary(param_1);
  iVar2 = 0;
  do {
    iVar1 = Game_MapInputIndex(this,iVar2);
    Rating_UpdateBarByKey(param_1,0x4f0,iVar2,iVar1,DAT_0058155c);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  return;
}

