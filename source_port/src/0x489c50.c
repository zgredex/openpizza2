// MapCell_CheckSpriteOverlap: ported from Pizza Connection 2 at 0x489c50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x489c50
#include "pc2_port.h"

uint32_t __thiscall MapCell_CheckSpriteOverlap(void *self,void *arg1)

{
  void *this_00;
  void *this_01;
  uint8_t uvalue1;
  int value2;
  uint32_t extraout_var;
  int value3;
  int value4;
  int value5;
  int value6;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
                    /* Checks whether a drawn sprite already occupies a candidate cell. */
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if (*(int *)((intptr_t)self + 0x9c) == 0) {
    return 1;
  }
  this_01 = *(void **)(*(int *)((intptr_t)self + 0x9c) + 0x16f0);
  if (this_01 == (void *)0x0) {
    return 1;
  }
  local_10 = 0;
  if (0 < *(int *)((intptr_t)this_01 + 0x8c)) {
    do {
      value2 = Game_MapRecordToGlobal(this_01,local_10);
      if ((value2 != 0) &&
         (uvalue1 = Object_IsVisibleThisFrame(value2), CONCAT31(extraout_var,uvalue1) != 0)) {
        value3 = MapObject_ComputeBlitRect(value2);
        value6 = *(int *)(value2 + 200);
        if (*(short *)(value6 + 0x28) == -1) {
          local_1c = 0;
          local_18 = 0;
          local_14 = 0;
        }
        else {
          this_00 = (void *)(value6 + 0x14);
          value4 = Array_GetPtr4(this_00,(intptr_t)*(short *)(value6 + 0x28));
          value5 = Array_GetPtr4(this_00,*(short *)(value6 + 0x28) + 1);
          value6 = Array_GetPtr4(this_00,*(short *)(value6 + 0x28) + 2);
          if (value4 != 0) {
            local_1c = *(int *)(*(int *)(value2 + 0xc4) + 0x4c) + *(int *)(value4 + 8) * 0xc;
          }
          if (value5 != 0) {
            local_18 = *(int *)(*(int *)(value2 + 0xc4) + 0x4c) + *(int *)(value5 + 8) * 0xc;
          }
          if (value6 != 0) {
            local_14 = *(int *)(*(int *)(value2 + 0xc4) + 0x4c) + *(int *)(value6 + 8) * 0xc;
          }
        }
        value2 = 0;
        if (0 < *(int *)((intptr_t)arg1 + 0x14)) {
          do {
            value6 = IDMap_Lookup(arg1,value2,(int *)0x0);
            if (value3 == value6) {
              return 1;
            }
            if ((local_1c != 0) &&
               (value6 = IDMap_Lookup(arg1,value2,(int *)0x0), local_1c == value6)) {
              return 1;
            }
            if ((local_18 != 0) &&
               (value6 = IDMap_Lookup(arg1,value2,(int *)0x0), local_18 == value6)) {
              return 1;
            }
            if ((local_14 != 0) &&
               (value6 = IDMap_Lookup(arg1,value2,(int *)0x0), local_14 == value6)) {
              return 1;
            }
            value2 = value2 + 1;
          } while (value2 < *(int *)((intptr_t)arg1 + 0x14));
        }
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)((intptr_t)this_01 + 0x8c));
  }
  return 0;
}
