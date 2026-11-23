// Game_CountNearbyTypesAroundRect: ported from Pizza Connection 2 at 0x48d2b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48d2b0
#include "pc2_port.h"

void __thiscall
Game_CountNearbyTypesAroundRect(void *self,int arg1,int arg2,uint32_t *arg3)

{
  void *this_00;
  int value1;
  int value2;
  int value3;
  uint32_t *uptr4;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  uptr4 = arg3;
  for (value2 = 8; value2 != 0; value2 = value2 + -1) {
    *uptr4 = 0;
    uptr4 = uptr4 + 1;
  }
  value2 = IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
  UI_GetRecordCenteredRect(*(void **)(value2 + 0xfa8),*(int *)(arg1 + 0x24),&local_8,&local_4);
  value2 = *(int *)((intptr_t)self + 0x50);
  value3 = 0;
  if (0 < value2) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x3c),value3,(int *)0x0);
      if ((*(int *)((intptr_t)this_00 + 0x30) < 8) && (*(int *)((intptr_t)this_00 + 0x74) == 0)) {
        value1 = State_Is2DOr2E((intptr_t)this_00);
        if (value1 == 0) {
          MapObject_GetScreenPosition(this_00,0,&local_10,&local_c);
          local_10 = local_8 - local_10;
          local_c = local_4 - local_c;
          if (local_10 * local_10 + local_c * local_c * 4 < arg2 * arg2 * 4) {
            arg3[*(int *)((intptr_t)this_00 + 0x30)] = arg3[*(int *)((intptr_t)this_00 + 0x30)] + 1;
          }
        }
      }
      value3 = value3 + 1;
    } while (value3 < value2);
  }
  return;
}
