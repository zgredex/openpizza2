// Game_RemoveMapObjectAtPoint: ported from Pizza Connection 2 at 0x4803c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4803c0
#include "pc2_port.h"

void __thiscall Game_RemoveMapObjectAtPoint(void *self,int arg1)

{
  int *ptr1;
  int value2;
  int local_14;
  uint32_t local_10;
  int local_c;
  int local_8;
  int local_4;
  
  value2 = arg1;
  IDMap_RemoveByKey((void *)((intptr_t)self + 0x19e0),arg1);
  ptr1 = (int *)(*(int *)((intptr_t)*(void **)((intptr_t)self + 0x14e0) + 0x4c) +
                  *(int *)(value2 + 0x20) * 0xc);
  Map_SetTileFieldWithDefault(*(void **)((intptr_t)self + 0x14e0),(intptr_t)ptr1,-1,1);
  UI_ComputeCenteredRect(*(void **)((intptr_t)self + 0x14e0),ptr1,&arg1,&local_14);
  arg1 = arg1 - *(int *)(*(int *)((intptr_t)self + 0x14e0) + 0x24);
  local_14 = local_14 - *(int *)(*(int *)((intptr_t)self + 0x14e0) + 0x28);
  local_10 = arg1 - 0x10;
  local_c = local_14 + -8;
  local_4 = local_14 + 8;
  local_8 = arg1 + 0x10;
  Gfx_BlitRectList(DAT_0058072c,&local_10);
  return;
}
