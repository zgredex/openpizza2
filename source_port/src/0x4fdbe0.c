// Game_PickRandomIdleObject: ported from Pizza Connection 2 at 0x4fdbe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fdbe0
#include "pc2_port.h"

int __thiscall Game_PickRandomIdleObject(void *self,int arg1)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  int *ptr4;
  int value5;
  int value6;
  int value7;
  int local_c8 [50];
  
  value7 = 0;
  value1 = Game_GetPlayerCount((intptr_t)DAT_0057c670);
  value6 = 0;
  value5 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x70);
  if (0 < value1) {
    do {
      if (0x31 < value7) break;
      if ((((value6 != *(int *)((intptr_t)self + arg1 * 0x168 + 0x40)) &&
           (*(char *)(value6 + 0xac + value5) == '\0')) &&
          (value2 = Game_GetPlayerBySlot(DAT_0057c670,value6),
          *(int *)((intptr_t)self + *(int *)(value2 + 0x4c) * 0x168 + 300) != 0x18)) &&
         (value2 = *(int *)(value2 + 0x15c) + 2, 0 < value2)) {
        ptr4 = local_c8 + value7;
        do {
          if (0x31 < value7) break;
          *ptr4 = value6;
          value7 = value7 + 1;
          ptr4 = ptr4 + 1;
          value2 = value2 + -1;
        } while (0 < value2);
      }
      value6 = value6 + 1;
    } while (value6 < value1);
    if (value7 != 0) {
      value5 = 0;
      do {
        uvalue3 = Random_RangeFast(0,value7 - 1);
        value1 = local_c8[uvalue3];
        uvalue3 = Random_Mod(*(uint32_t *)(*(int *)((intptr_t)self + value1 * 0x168 + 0x70) + 0x15c));
        value1 = Game_GetPlayerSubrecord(self,value1,uvalue3,1);
        if (((value1 != 0) && (*(int *)(*(int *)(value1 + 0x16f0) + 0x38) == 0)) &&
           (*(int *)(value1 + 0x2c) == 0)) {
          return value1;
        }
        value5 = value5 + 1;
      } while (value5 < 10);
    }
  }
  return 0;
}
