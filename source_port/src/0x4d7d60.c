// Game_CountNearbyObjectTypes: ported from Pizza Connection 2 at 0x4d7d60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d7d60
#include "pc2_port.h"

int __thiscall Game_CountNearbyObjectTypes(void *self,int arg1,uint32_t *arg2)

{
  void *this_00;
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int value7;
  int *ptr8;
  uint32_t *uptr9;
  int local_18;
  int local_14;
  
  uptr9 = arg2;
  for (value7 = 0x40; value1 = DAT_0057c670, value7 != 0; value7 = value7 + -1) {
    *uptr9 = 0;
    uptr9 = uptr9 + 1;
  }
  value7 = *(int *)((intptr_t)self + 0xfc0);
  this_00 = (void *)(DAT_0057c670 + 0x3c);
  local_14 = 0;
  local_18 = 0;
  value2 = 0;
  if (0 < value7) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),local_18,(int *)0x0);
      value3 = Game_GetObjectCenterY(value2);
      value4 = Game_GetObjectCenterY(arg1);
      value5 = Game_GetObjectBottom(value2);
      value6 = Game_GetObjectBottom(arg1);
      if (((value4 - value3) * (value4 - value3) + (value6 - value5) * (value6 - value5) * 4 < 160000) &&
         (value3 = 0, 0 < *(int *)(value1 + 0x50))) {
        do {
          value4 = IDMap_Lookup(this_00,value3,(int *)0x0);
          if ((*(int *)(value4 + 0x28) == *(int *)((intptr_t)self + 0xc1c)) &&
             (*(int *)(value4 + 0x30) < 8)) {
            value5 = 0;
            ptr8 = (int *)(value4 + 0xd4);
            do {
              if (value2 == *ptr8) {
                arg2[value5 + *(int *)(value4 + 0x34) * 8] =
                     arg2[value5 + *(int *)(value4 + 0x34) * 8] + 1;
                local_14 = local_14 + 1;
              }
              value5 = value5 + 1;
              ptr8 = ptr8 + 1;
            } while (value5 < 8);
          }
          value3 = value3 + 1;
        } while (value3 < *(int *)(value1 + 0x50));
      }
      local_18 = local_18 + 1;
    } while (local_18 < value7);
    value2 = local_14;
  }
  return value2;
}
