// Map_UpdateObjectState: ported from Pizza Connection 2 at 0x4ee6d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ee6d0
#include "pc2_port.h"

void __thiscall Map_UpdateObjectState(void *self,int *arg1)

{
  uint8_t flag1;
  void *this_00;
  int value2;
  int value3;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint32_t local_10;
  uint32_t local_c [2];
  
  this_00 = *(void **)(*(int *)((intptr_t)self + 4) + 0x2c3b8);
  local_24 = *(int *)(*(int *)((intptr_t)self + 4) + 0x2c414);
  local_20 = 0;
  do {
    flag1 = *(uint8_t *)(arg1[2] + 0x2c + local_20);
    if (flag1 < 0x28) {
      if (0x1d < flag1) {
        value3 = -0x10;
        value2 = flag1 - 0x1e;
        goto LAB_004ee75e;
      }
      if (0x13 < flag1) {
        value3 = -8;
        value2 = flag1 - 0x14;
        goto LAB_004ee75e;
      }
      if (9 < flag1) {
        value3 = 0;
        value2 = flag1 - 10;
        goto LAB_004ee75e;
      }
    }
    else {
      value3 = -8;
      value2 = flag1 - 0x28;
LAB_004ee75e:
      if (value2 != -1) {
        Record_SetIndex48(this_00,local_24,value2);
        Sprite_DrawMasked(this_00,&local_1c,&local_18,local_c,&local_10);
        UI_ComputeCenteredRect(self,arg1,&local_2c,&local_28);
        local_2c = local_2c - ((local_1c >> 1) + *(int *)((intptr_t)self + 0x24));
        local_28 = local_28 - ((local_18 >> 1) + *(int *)((intptr_t)self + 0x28));
        local_14 = local_2c + value3 + 2;
        Record_DrawSprite48(this_00,*(uint32_t **)((intptr_t)self + 8),DAT_0058072c,local_24);
      }
    }
    local_20 = local_20 + 1;
    if (3 < local_20) {
      return;
    }
  } while( true );
}
