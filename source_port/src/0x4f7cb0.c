// Game_BuildTopRatedObjectList: ported from Pizza Connection 2 at 0x4f7cb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7cb0
#include "pc2_port.h"

void Game_BuildTopRatedObjectList(int arg1,uint32_t *arg2,uint32_t arg3)

{
  int value1;
  uint32_t *uptr2;
  void *self;
  int *ptr3;
  int value4;
  int value5;
  int value6;
  int local_8;
  int local_4;
  
  uptr2 = arg2;
  for (value6 = 0x1e; value6 != 0; value6 = value6 + -1) {
    *arg2 = 0;
    arg2 = arg2 + 1;
  }
  value6 = *(int *)(arg1 + 0x30);
  value1 = *(int *)(arg1 + 0x34);
  self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),value1,(int *)0x0);
  if ((value6 != -1) && (self != (void *)0x0)) {
    local_4 = Game_CountObjectsByType2(self,0xffffffff);
    arg2 = (uint32_t *)0x0;
    if (0 < local_4) {
      do {
        ptr3 = (int *)Game_GetOwnedObjectByIndex(self,(intptr_t)arg2,&local_8);
        value6 = *ptr3;
        if ((((value6 != 0) && (*(uint8_t *)(value6 + 0x824) == arg3)) &&
            (value4 = Game_GetRecordByField814(value6), *(int *)(value4 + 0x108) != 0xc)) &&
           (value4 = Game_GetRecordByField814(value6), *(int *)(value4 + 0x74) == 0)) {
          value6 = Rating_GetComposite(value6);
          value4 = 9;
          if ((intptr_t)uptr2[0x1d] < value6) {
            ptr3 = uptr2 + 0x1d;
            do {
              if (value6 <= *ptr3) break;
              value4 = value4 + -1;
              ptr3 = ptr3 + -3;
            } while (-1 < value4);
            value5 = value4 + 1;
            ptr3 = uptr2 + value5 * 3;
            _memmove(uptr2 + value4 + 4 + value5 * 2,ptr3,value5 * -0xc + 0x6c);
            ptr3[2] = value6;
            ptr3[1] = local_8;
            *ptr3 = value1;
          }
        }
        arg2 = (uint32_t *)((intptr_t)arg2 + 1);
      } while ((intptr_t)arg2 < local_4);
    }
  }
  return;
}
