// UI_IsSpriteVisibleInView: ported from Pizza Connection 2 at 0x4d3080.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3080
#include "pc2_port.h"

bool __fastcall UI_IsSpriteVisibleInView(int arg1)

{
  void *self;
  int value1;
  int value2;
  void *this_00;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_4;
  
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  self = *(void **)(value2 + 0xfa8);
  if (self == (void *)0x0) {
    return false;
  }
  value2 = *(int *)(arg1 + 0x24);
  value1 = *(int *)((intptr_t)self + 0x4c);
  this_00 = (void *)SparseMap_Lookup48(DAT_0057c5cc,*(int *)(arg1 + 0x20));
  if (this_00 == (void *)0x0) {
    return false;
  }
  UI_AlignSpriteToRect(self,(int *)(value1 + value2 * 0xc),this_00,&local_38,&local_34);
  Sprite_GetHotspot(this_00,&local_30,&local_2c);
  Sprite_GetSize(this_00,&local_28,&local_24);
  local_38 = local_38 + *(int *)((intptr_t)self + 0x24);
  local_34 = local_34 + *(int *)((intptr_t)self + 0x28);
  value2 = local_30 + local_38;
  value1 = local_2c + local_34;
  local_4 = value1 + local_24;
  UI_GetViewRect(self,&local_20);
  if (value2 < local_20 + -0x23) {
    return false;
  }
  if (local_18 + 0x23 < value2 + local_28) {
    return false;
  }
  if (value1 < local_1c + -0x23) {
    return false;
  }
  return local_4 <= local_14 + 0x23;
}
