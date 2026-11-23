// UI_TrimTextToWidth: ported from Pizza Connection 2 at 0x522dc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x522dc0
#include "pc2_port.h"

void __thiscall UI_TrimTextToWidth(void *self,int arg1,int arg2)

{
  char cVar1;
  char *cptr2;
  uint8_t uvalue3;
  uint32_t extraout_var;
  int value4;
  
  UI_SubtractOrigin(*(void **)((intptr_t)self + 8),&arg1,&arg2);
  cptr2 = *(char **)((intptr_t)self + 0x6c);
  arg1 = arg1 - *(int *)((intptr_t)self + 0x38);
  value4 = 0;
  cVar1 = *cptr2;
  while (cVar1 != '\0') {
    uvalue3 = Font_GetCharWidth(*(void **)((intptr_t)self + 0x54),
                              CONCAT31((int3)((uint32_t)cptr2 >> 8),cptr2[value4]));
    arg1 = arg1 - CONCAT31(extraout_var,uvalue3);
    if (arg1 < 0) break;
    cptr2 = *(char **)((intptr_t)self + 0x6c);
    value4 = value4 + 1;
    cVar1 = cptr2[value4];
  }
  *(int *)((intptr_t)self + 0x80) = value4;
  *(uint32_t *)((intptr_t)self + 0x88) = 0xfffffc19;
  UI_ClipRect(*(void **)((intptr_t)self + 8),(int *)((intptr_t)self + 0x28),1);
  return;
}
