// UI_RenderDrawCommand: ported from Pizza Connection 2 at 0x521dd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521dd0
#include "pc2_port.h"

void __thiscall UI_RenderDrawCommand(void *self,uint32_t *arg1,int arg2,int *arg3)

{
  uint32_t *uptr1;
  int value2;
  int *ptr3;
  
  ptr3 = arg3;
  value2 = arg2;
  uptr1 = arg1;
  if (*arg3 == 0) {
    if ((-1 < (intptr_t)arg1) && (-1 < arg2)) {
      Sprite_GetSize(*(void **)((intptr_t)self + 0x60),(int *)&arg1,&arg2);
      if (((intptr_t)uptr1 < (intptr_t)arg1) && (value2 < arg2)) {
        *(short *)(*(int *)(*(int *)((intptr_t)self + 0x68) + 0x28) +
                  (intptr_t)(*(int *)(*(int *)((intptr_t)self + 0x68) + 0x20) * value2 + (intptr_t)uptr1) * 2) =
             (short)ptr3[2];
      }
    }
  }
  else if (*arg3 == 1) {
    Sprite_Draw((void *)arg3[1],*(int *)((intptr_t)self + 0x68),arg1,arg2);
    return;
  }
  return;
}
