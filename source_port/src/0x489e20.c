// Game_AnyBuildingReachesCellList: ported from Pizza Connection 2 at 0x489e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x489e20
#include "pc2_port.h"

uint32_t __thiscall Game_AnyBuildingReachesCellList(void *self,void *arg1)

{
  void *this_00;
  bool flag1;
  void *this_01;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  int value2;
  
                    /* Tests whether any player building reaches a candidate cell. */
  if (*(int *)((intptr_t)self + 0x9c) == 0) {
    return 1;
  }
  this_00 = *(void **)(*(int *)((intptr_t)self + 0x9c) + 0x16f0);
  if (this_00 == (void *)0x0) {
    return 1;
  }
  value2 = 0;
  if (0 < *(int *)((intptr_t)this_00 + 0x8c)) {
    do {
      this_01 = (void *)Game_MapRecordToGlobal(this_00,value2);
      if (this_01 != (void *)0x0) {
        flag1 = Person_BlocksFootprintCells(this_01,arg1);
        if (CONCAT31(extraout_var,flag1) != 0) {
          return 1;
        }
        flag1 = Person_BlocksFootprintPath(this_01,arg1);
        if (CONCAT31(extraout_var_00,flag1) != 0) {
          return 1;
        }
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)this_00 + 0x8c));
  }
  return 0;
}
