// Map_CountNearbyObjects: ported from Pizza Connection 2 at 0x4d5cf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d5cf0
#include "pc2_port.h"

void __thiscall
Map_CountNearbyObjects(void *self,int arg1,int *arg2,int *arg3,uint32_t *arg4)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int *ptr7;
  int value8;
  
  value1 = *(int *)((intptr_t)self + 0xfc0);
  *arg3 = 0;
  *arg2 = 0;
  *arg4 = 0;
  value2 = Game_GetObjectCenterY(arg1);
  value3 = Game_GetObjectBottom(arg1);
  value8 = 0;
  if (0 < value1) {
    do {
      value4 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),value8,(int *)0x0);
      value5 = Game_GetObjectCenterY(value4);
      value6 = Game_GetObjectBottom(value4);
      if ((value2 - value5) * (value2 - value5) + (value3 - value6) * (value3 - value6) * 4 < 360000) {
        if (*(int *)(value4 + 4) == 0) {
          ptr7 = arg2;
LAB_004d5db0:
          *ptr7 = *ptr7 + 1;
        }
        else if (*(int *)(value4 + 4) == 0x20) {
          *arg4 = 1;
        }
        else if (*(int *)(value4 + 0x48) != -1) {
          ptr7 = arg3;
          goto LAB_004d5db0;
        }
      }
      value8 = value8 + 1;
    } while (value8 < value1);
  }
  return;
}
