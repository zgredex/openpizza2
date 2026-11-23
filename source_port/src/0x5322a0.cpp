// UI_GetWindowRect: ported from Pizza Connection 2 at 0x5322a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5322a0
#include "pc2_port.h"

void __thiscall UI_GetWindowRect(void *self,LPRECT arg1)

{
  if (*(int *)((intptr_t)self + 0xe0) != 0) {
    arg1->left = *(LONG *)((intptr_t)self + 8);
    arg1->top = *(LONG *)((intptr_t)self + 0xc);
    arg1->right = *(LONG *)((intptr_t)self + 0x10);
    arg1->bottom = *(LONG *)((intptr_t)self + 0x14);
    return;
  }
  if (*(int *)((intptr_t)self + 0x38) == -999) {
    SetRect(arg1,0,0,0,0);
    return;
  }
  arg1->left = *(int *)((intptr_t)self + 0x38);
  arg1->top = *(LONG *)((intptr_t)self + 0x3c);
  arg1->right = *(LONG *)((intptr_t)self + 0x40);
  arg1->bottom = *(LONG *)((intptr_t)self + 0x44);
  return;
}
