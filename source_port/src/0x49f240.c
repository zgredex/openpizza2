// RecipeMenu_SetCurrentRecipe: ported from Pizza Connection 2 at 0x49f240.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49f240
#include "pc2_port.h"


void __cdecl RecipeMenu_SetCurrentRecipe(void *arg1,uint32_t *arg2)

{
  uint8_t flag1;
  int value2;
  int value3;
  int value4;
  void *self;
  int value5;
  int local_114;
  char local_10c [256];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055878e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (DAT_0057cda0 != (void *)0x0) {
    ExceptionList = &local_c;
    PlayerStats_Reset((intptr_t)DAT_0057cda0);
    value4 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
    Recipe_RecomputeAllStats(DAT_0057cda0,value4);
    UI_RemoveAllObjects(arg1);
  }
  if (arg2 == (uint32_t *)0x0) {
    self = operator_new(0x330);
    local_4 = 0;
    if (self == (void *)0x0) {
      arg2 = (uint32_t *)0x0;
    }
    else {
      arg2 = Recipe_Construct(self,(int *)0x0,'\0');
    }
    local_4 = 0xffffffff;
  }
  value4 = arg2[0x17];
  local_114 = 0;
  DAT_0057cda0 = arg2;
  if (0 < value4) {
    do {
      value5 = IDMap_Lookup(DAT_0057cda0 + 0x12,local_114,(int *)0x0);
      if (*(char *)(value5 + 0x11) == '\0') {
        flag1 = *(uint8_t *)(value5 + 0x10);
        value2 = *(int *)(value5 + 8);
        value3 = *(int *)(value5 + 0xc);
        String_Format(local_10c,(uint8_t *)s_zutaten_ZA_02dA__02d_spr_00568948,*(uint8_t *)(value5 + 4) + 1
                     );
        UI_AddSprite(arg1,local_114 + 100000,value2,value3,local_10c);
        UI_SetButtonColorVariant(arg1,local_114 + 100000,(uint32_t)flag1);
        *(uint32_t *)((intptr_t)arg1 + 0xe0) = 1;
      }
      local_114 = local_114 + 1;
    } while (local_114 < value4);
    if (0 < value4) {
      *(uint32_t *)((intptr_t)arg1 + 0xe0) = 1;
    }
  }
  ExceptionList = local_c;
  return;
}
