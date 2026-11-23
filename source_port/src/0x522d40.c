// UI_SetTextFit: ported from Pizza Connection 2 at 0x522d40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x522d40
#include "pc2_port.h"

void __thiscall UI_SetTextFit(void *self,char *arg1)

{
  char cVar1;
  uint8_t uvalue2;
  int value3;
  uint32_t extraout_var;
  uint32_t uvalue4;
  int value5;
  int extraout_ECX;
  char *cptr6;
  int value7;
  
  _strncpy(*(char **)((intptr_t)self + 0x6c),arg1,*(size_t *)((intptr_t)self + 0x78));
  *(uint8_t *)(*(int *)((intptr_t)self + 0x6c) + *(int *)((intptr_t)self + 0x78)) = 0;
  value3 = Font_MeasureText(*(void **)((intptr_t)self + 0x54),*(char **)((intptr_t)self + 0x6c));
  uvalue4 = 0xffffffff;
  cptr6 = *(char **)((intptr_t)self + 0x6c);
  do {
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    cVar1 = *cptr6;
    cptr6 = cptr6 + 1;
  } while (cVar1 != '\0');
  value5 = ~uvalue4 - 1;
  value7 = ~uvalue4 - 2;
  for (; (-1 < value7 && (*(int *)((intptr_t)self + 0x84) <= value3));
      value3 = value3 - CONCAT31(extraout_var,uvalue2)) {
    uvalue2 = Font_GetCharWidth(*(void **)((intptr_t)self + 0x54),
                              CONCAT31((int3)((uint32_t)value5 >> 8),
                                       *(uint8_t *)(*(int *)((intptr_t)self + 0x6c) + value7)));
    *(uint8_t *)(*(int *)((intptr_t)self + 0x6c) + value7) = 0;
    value7 = value7 + -1;
    value5 = extraout_ECX;
  }
  UI_ClipRect(*(void **)((intptr_t)self + 8),(int *)((intptr_t)self + 0x28),1);
  return;
}
