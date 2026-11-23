// UI_ClearChildExtent: ported from Pizza Connection 2 at 0x51eae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51eae0
#include "pc2_port.h"

void __fastcall UI_ClearChildExtent(uint32_t *arg1)

{
  int local_8;
  int local_4;
  
  CS_Enter(*(int *)(arg1[2] + 0x1c8));
  if ((arg1[6] != 0) && ((void *)arg1[1] != (void *)0x0)) {
    Sprite_GetSize((void *)arg1[1],&local_4,&local_8);
    Rect_Union((void *)arg1[2],arg1[3],arg1[4],local_4 + arg1[3],local_8 + arg1[4]);
  }
  arg1[5] = 0;
  *arg1 = 0;
  CS_Leave(*(int *)(arg1[2] + 0x1c8));
  return;
}
