// rea decompile_all
// name: IngredientPanel_UpdatePage
// address: 0x499890
// body: available
// range: 0x499890-0x4999eb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl IngredientPanel_UpdatePage(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* Refreshes the ingredient-panel slots and details. */
  if (DAT_0057ca20 != (undefined4 *)0x0) {
    (**(code **)*DAT_0057ca20)(1);
    DAT_0057ca20 = (undefined4 *)0x0;
  }
  DAT_0057ca20 = FUN_00488b30(DAT_0057c670,DAT_00568910);
  iVar2 = DAT_0057ca20[5];
  DAT_0057ca24 = 0;
  iVar3 = 0x4ed;
  do {
    UI_ShowChildByID(param_1,iVar3 + 0x1c);
    UI_ShowChildByID(param_1,iVar3);
    iVar1 = iVar3 + -0x4ec;
    iVar3 = iVar3 + 1;
  } while (iVar1 < 0xc);
  if (iVar2 < 0xd) {
    FUN_00531740(param_1,0x428);
    iVar2 = 0xc - iVar2;
    if (0 < iVar2) {
      iVar3 = 0x4f8;
      do {
        FUN_00531740(param_1,iVar3 + 0x1c);
        FUN_00531740(param_1,iVar3);
        iVar3 = iVar3 + -1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  else {
    UI_ShowChildByID(param_1,0x428);
    iVar3 = DAT_00568914;
    if (iVar2 < DAT_00568914 + 0xc) {
      iVar3 = iVar2 + -9;
    }
    DAT_0057ca24 = iVar3 / 3;
    FUN_0052fd00(param_1,0x428,0,((iVar2 + -0xc) / 3 + 1) * 100,0);
    FUN_0052fd70(param_1,0x428,DAT_0057ca24 * 100,0);
    FUN_0052fce0(param_1,0x428,1);
  }
  CreateRecipePage_FillIngredientDetails(param_1,-1);
  RecipeEditor_InitRecipeRows(param_1,DAT_0057ca24);
  return;
}

