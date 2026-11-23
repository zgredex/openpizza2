// Game_FindBestRatedBuilding: ported from Pizza Connection 2 at 0x4e3e80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3e80
#include "pc2_port.h"

void * __thiscall Game_FindBestRatedBuilding(void *self,int arg1)

{
  int value1;
  void *this_00;
  int value2;
  int value3;
  void *pvVar4;
  int value5;
  
  value1 = *(int *)((intptr_t)self + 0x124);
  value5 = 0;
  pvVar4 = (void *)0x0;
  value3 = 0;
  if (value1 < 1) {
    return (void *)0x0;
  }
  do {
    this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x110),value3,(int *)0x0);
    if (*(char *)((intptr_t)this_00 + 0x1dc) == '\0') {
      value2 = Index_Map8To5(this_00,arg1);
      if (value5 < value2) {
        pvVar4 = this_00;
        value5 = value2;
      }
    }
    value3 = value3 + 1;
  } while (value3 < value1);
  return pvVar4;
}
