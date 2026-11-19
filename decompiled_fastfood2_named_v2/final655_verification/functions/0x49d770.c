// rea decompile_all
// name: PizzaContestRecipePage_Update
// address: 0x49d770
// body: available
// range: 0x49d770-0x49d90b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl PizzaContestRecipePage_Update(void *param_1)

{
  int iVar1;
  
                    /* Fills the pizza-contest recipe page. */
  DAT_00568af4 = 0xffffffff;
  DAT_0057ca2c = 0;
  *(undefined4 *)(DAT_0057c5e0 + 0x831c) = 1;
  FUN_00532520((int)param_1);
  UI_Group_Create(param_1,0,6,0x4eb);
  FUN_0052ff50(param_1,*(int *)(&DAT_00568af8 + _DAT_00568af8 * 4),1);
  UI_Group_Create(param_1,1,0xc,0x4ed);
  FUN_00532310(param_1,&LAB_0049d2b0,0);
  DAT_0057cac4 = *(int *)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) +
                         0x1d4);
  if (*(int *)(DAT_0057c670 + 0x98) != DAT_0057cac4) {
    FUN_005301c0(*(void **)(DAT_0057c670 + 0x25c),-0x18670,0x23,DAT_0057cac4);
  }
  iVar1 = 0x509;
  do {
    FUN_00531470(param_1,iVar1,0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x515);
  iVar1 = 0;
  do {
    FUN_00531fb0(param_1,iVar1 + 0x4ed,1,(char *)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xc);
  if (DAT_0057cac4 == 0) {
    FUN_0052f9b0(param_1,0x448,DAT_00582d50);
    DAT_0057cab8 = 0;
    WarehousePanel_UpdatePage(param_1);
    RecipeEdit_UpdateRatingBars(param_1);
    return;
  }
  FUN_0052f9b0(param_1,0x448,DAT_0057cac4 + 4);
  DAT_0057cab8 = FUN_00510580(DAT_0057cac4);
  WarehousePanel_UpdatePage(param_1);
  RecipeEdit_UpdateRatingBars(param_1);
  return;
}

