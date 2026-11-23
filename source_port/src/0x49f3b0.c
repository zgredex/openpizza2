// RecipeMenu_RefreshPortionPreview: ported from Pizza Connection 2 at 0x49f3b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49f3b0
#include "pc2_port.h"

int __cdecl RecipeMenu_RefreshPortionPreview(void *arg1,int arg2)

{
  uint8_t flag1;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  char local_100 [256];
  
  value4 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  if (*(int *)(value4 + 0x1154) == 0) {
    value4 = 100;
  }
  else {
    value4 = 100 - (*(int *)(value4 + 0x114c) * 100) / *(int *)(value4 + 0x1154);
  }
  if (*(int *)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x1d4) ==
      arg2) {
    value4 = 100;
  }
  UI_RemoveAllObjects(arg1);
  value4 = *(int *)(arg2 + 0x5c) * value4;
  value5 = value4 * 0x51eb851f;
  value4 = value4 / 100;
  value6 = 0;
  if (0 < value4) {
    do {
      value5 = IDMap_Lookup((void *)(arg2 + 0x48),value6,(int *)0x0);
      if (*(char *)(value5 + 0x11) == '\0') {
        flag1 = *(uint8_t *)(value5 + 0x10);
        value2 = *(int *)(value5 + 0xc);
        value3 = *(int *)(value5 + 8);
        String_Format(local_100,(uint8_t *)s_zutaten_ZA_02dA__02d_spr_00568948,*(uint8_t *)(value5 + 4) + 1
                     );
        UI_AddSprite(arg1,value6 + 100000,value3,value2,local_100);
        value5 = UI_SetButtonColorVariant(arg1,value6 + 100000,(uint32_t)flag1);
        *(uint32_t *)((intptr_t)arg1 + 0xe0) = 1;
      }
      value6 = value6 + 1;
    } while (value6 < value4);
  }
  *(uint32_t *)((intptr_t)arg1 + 0xe0) = 1;
  return value5;
}
