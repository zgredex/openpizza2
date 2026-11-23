// Game_AutoFillCompanyMenu: ported from Pizza Connection 2 at 0x4fc3b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fc3b0
#include "pc2_port.h"

uint32_t __thiscall Game_AutoFillCompanyMenu(void *self,int arg1)

{
  void *this_00;
  int value1;
  int value2;
  void *pvVar3;
  int value4;
  int value5;
  
  this_00 = *(void **)((intptr_t)self + arg1 * 0x168 + 0x70);
  value1 = *(int *)((intptr_t)this_00 + 0x124);
  if (value1 == 0) {
    return 1;
  }
  value5 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)this_00 + 0x110),value5,(int *)0x0);
      Recipe_SetOnMenu(this_00,value2,0);
      value5 = value5 + 1;
    } while (value5 < value1);
  }
  value5 = 0;
  do {
    pvVar3 = Game_FindBestRatedBuilding(this_00,value5);
    if (pvVar3 != (void *)0x0) {
      Recipe_SetOnMenu(this_00,(intptr_t)pvVar3,1);
    }
    value5 = value5 + 1;
  } while (value5 < 7);
  value5 = Game_CountActiveCompanies((intptr_t)this_00);
  value5 = 8 - value5;
  if ((0 < value5) && (value2 = 0, 0 < value1)) {
    do {
      value4 = IDMap_Lookup((void *)((intptr_t)this_00 + 0x110),value2,(int *)0x0);
      if (*(char *)(value4 + 0x1dc) == '\0') {
        Recipe_SetOnMenu(this_00,value4,1);
        value5 = value5 + -1;
        if (value5 == 0) {
          return 1;
        }
      }
      value2 = value2 + 1;
    } while (value2 < value1);
  }
  return 1;
}
