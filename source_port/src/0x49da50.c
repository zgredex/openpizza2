// RecipeEdit_PlaceIngredient: ported from Pizza Connection 2 at 0x49da50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49da50
#include "pc2_port.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl RecipeEdit_PlaceIngredient(int arg1,int arg2)

{
  uint8_t uvalue1;
  uint32_t *uptr2;
  int value3;
  void *pvVar4;
  uint32_t uvalue5;
  int value6;
  double fVar7;
  char acStack_10c [256];
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
                    /* Adds a positioned ingredient to the recipe being edited. */
  pvStack_c = ExceptionList;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055876e;
  ExceptionList = &pvStack_c;
  *(uint8_t *)(DAT_0057cac4 + 0x1dd) = 1;
  value3 = *(int *)(DAT_0057cac4 + 0x5c);
  while (value6 = value3, value3 = value6 + -1, -1 < value3) {
    uptr2 = (uint32_t *)IDMap_Lookup((void *)(DAT_0057cac4 + 0x48),value3,(int *)0x0);
    if (*(char *)((intptr_t)uptr2 + 0x11) == '\x01') {
      UI_RemoveObject(*(void **)(DAT_0057c670 + 0x25c),value6 + 99999);
      if (uptr2 != (uint32_t *)0x0) {
        (**(code **)*uptr2)(1);
      }
      IDMap_RemoveRecursive((void *)(DAT_0057cac4 + 0x48),value3);
    }
  }
  value3 = IDMap_Lookup(DAT_0057cac8,DAT_00568af4,(int *)0x0);
  String_Format(acStack_10c,(uint8_t *)s_zutaten_ZA_02dA__02d_spr_00568948,
                *(uint32_t *)(value3 + 0xd0));
  value6 = *(int *)(DAT_0057cac4 + 0x5c) + 100000;
  pvVar4 = operator_new(0x1c);
  uStack_4 = 0;
  if (pvVar4 == (void *)0x0) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    uptr2 = RecipeTopping_StreamConstruct(pvVar4,(void *)0x0);
  }
  uptr2[2] = DAT_0057cabc + arg1;
  uStack_4 = 0xffffffff;
  uptr2[3] = DAT_0057cac0 + arg2;
  *(uint8_t *)((intptr_t)uptr2 + 6) = DAT_0057cacc;
  *(char *)(uptr2 + 1) = (char)*(uint32_t *)(value3 + 0xd0) + -1;
  *(uint8_t *)((intptr_t)uptr2 + 5) = DAT_00568af8;
  uvalue1 = UI_ResetInputHelper(DAT_0057c5e0);
  *(uint8_t *)(uptr2 + 4) = uvalue1;
  value3 = DAT_0057cac4;
  List_Add((void *)(DAT_0057cac4 + 0x48),uptr2);
  PlayerStats_Reset(value3);
  fVar7 = Game_GetPlayerWeightedStat(value3);
  *(float *)(value3 + 0x44) = (float)fVar7;
  DAT_0057cab8 = *(int *)(DAT_0057cac4 + 0x5c);
  pvVar4 = *(void **)(DAT_0057c670 + 0x25c);
  UI_AddSprite(pvVar4,value6,DAT_0057cabc + arg1,DAT_0057cac0 + arg2,acStack_10c);
  uvalue5 = UI_ResetInputHelper(DAT_0057c5e0);
  UI_SetButtonColorVariant(pvVar4,value6,uvalue5);
  Array_SetField14ByKey(pvVar4,value6,0);
  RecipeKitchen_ShowPlacedIngredient(*(void **)(DAT_0057c670 + 0x25c),DAT_0057cab8);
  *(uint32_t *)((intptr_t)pvVar4 + 0xe0) = 1;
  ExceptionList = pvStack_c;
  return;
}
