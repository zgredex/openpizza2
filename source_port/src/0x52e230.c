// UI_ComputeElementRowExtent: ported from Pizza Connection 2 at 0x52e230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52e230
#include "pc2_port.h"

void __fastcall UI_ComputeElementRowExtent(void *arg1)

{
  void *self;
  int value1;
  int value2;
  int value3;
  int value4;
  int local_30;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  value2 = 4 - (uint32_t)(*(int *)((intptr_t)arg1 + 0x3a8) != 1);
  local_30 = 0;
  value3 = local_4;
  value4 = local_8;
  if (0 < value2) {
    do {
      self = *(void **)((intptr_t)arg1 + local_30 * 0xcc + 0x9c);
      if (self != (void *)0x0) {
        Sprite_GetSize(self,&local_1c,&local_18);
        Sprite_GetSize(*(void **)((intptr_t)arg1 + local_30 * 0xcc + 0x124),&local_20,&local_14);
        Sprite_GetHotspot(*(void **)((intptr_t)arg1 + local_30 * 0xcc + 0x9c),&local_28,&local_24);
        if (local_30 == 0) {
          local_10 = local_28;
          local_c = local_24;
          if (0 < *(short *)((intptr_t)arg1 + 0x3b0)) {
            *(int *)((intptr_t)arg1 + 0x3a4) =
                 (*(short *)((intptr_t)arg1 + 0x3b0) - local_20) - local_1c;
          }
          value4 = *(int *)((intptr_t)arg1 + 0x3a4) + local_28 + local_20 + local_1c;
          value3 = local_24 + local_18;
        }
        else {
          if (local_28 < local_10) {
            local_10 = local_28;
          }
          if (local_24 < local_c) {
            local_c = local_24;
          }
          value1 = local_1c + *(int *)((intptr_t)arg1 + 0x3a4) + local_28 + local_20;
          if (value4 < value1) {
            value4 = value1;
          }
          if (value3 < local_24 + local_18) {
            value3 = local_24 + local_18;
          }
        }
      }
      local_30 = local_30 + 1;
    } while (local_30 < value2);
  }
  *(int *)((intptr_t)arg1 + 0x28) = *(int *)((intptr_t)arg1 + 0x38) + local_10;
  *(int *)((intptr_t)arg1 + 0x2c) = *(int *)((intptr_t)arg1 + 0x3c) + local_c;
  UI_SetAbsolutePosition(arg1,value4 - local_10,value3 - local_c);
  return;
}
