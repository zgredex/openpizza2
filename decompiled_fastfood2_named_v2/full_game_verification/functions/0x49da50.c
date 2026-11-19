// rea decompile_all
// name: RecipeEdit_PlaceIngredient
// address: 0x49da50
// body: available
// range: 0x49da50-0x49dc58 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl RecipeEdit_PlaceIngredient(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  float10 fVar7;
  char acStack_10c [256];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
                    /* Adds a positioned ingredient to the recipe being edited. */
  pvStack_c = ExceptionList;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055876e;
  ExceptionList = &pvStack_c;
  *(undefined1 *)(DAT_0057cac4 + 0x1dd) = 1;
  iVar3 = *(int *)(DAT_0057cac4 + 0x5c);
  while (iVar6 = iVar3, iVar3 = iVar6 + -1, -1 < iVar3) {
    puVar2 = (undefined4 *)IDMap_Lookup((void *)(DAT_0057cac4 + 0x48),iVar3,(int *)0x0);
    if (*(char *)((int)puVar2 + 0x11) == '\x01') {
      UI_RemoveObject(*(void **)(DAT_0057c670 + 0x25c),iVar6 + 99999);
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(1);
      }
      IDMap_RemoveRecursive((void *)(DAT_0057cac4 + 0x48),iVar3);
    }
  }
  iVar3 = IDMap_Lookup(DAT_0057cac8,DAT_00568af4,(int *)0x0);
  String_Format(acStack_10c,(byte *)s_zutaten_ZA_02dA__02d_spr_00568948,
                *(undefined4 *)(iVar3 + 0xd0));
  iVar6 = *(int *)(DAT_0057cac4 + 0x5c) + 100000;
  pvVar4 = operator_new(0x1c);
  uStack_4 = 0;
  if (pvVar4 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = RecipeTopping_StreamConstruct(pvVar4,(void *)0x0);
  }
  puVar2[2] = DAT_0057cabc + param_1;
  uStack_4 = 0xffffffff;
  puVar2[3] = DAT_0057cac0 + param_2;
  *(undefined1 *)((int)puVar2 + 6) = DAT_0057cacc;
  *(char *)(puVar2 + 1) = (char)*(undefined4 *)(iVar3 + 0xd0) + -1;
  *(undefined1 *)((int)puVar2 + 5) = DAT_00568af8;
  uVar1 = UI_ResetInputHelper(DAT_0057c5e0);
  *(undefined1 *)(puVar2 + 4) = uVar1;
  iVar3 = DAT_0057cac4;
  List_Add((void *)(DAT_0057cac4 + 0x48),puVar2);
  PlayerStats_Reset(iVar3);
  fVar7 = Game_GetPlayerWeightedStat(iVar3);
  *(float *)(iVar3 + 0x44) = (float)fVar7;
  DAT_0057cab8 = *(int *)(DAT_0057cac4 + 0x5c);
  pvVar4 = *(void **)(DAT_0057c670 + 0x25c);
  UI_AddSprite(pvVar4,iVar6,DAT_0057cabc + param_1,DAT_0057cac0 + param_2,acStack_10c);
  uVar5 = UI_ResetInputHelper(DAT_0057c5e0);
  UI_SetButtonColorVariant(pvVar4,iVar6,uVar5);
  Array_SetField14ByKey(pvVar4,iVar6,0);
  RecipeKitchen_ShowPlacedIngredient(*(void **)(DAT_0057c670 + 0x25c),DAT_0057cab8);
  *(undefined4 *)((int)pvVar4 + 0xe0) = 1;
  ExceptionList = pvStack_c;
  return;
}

