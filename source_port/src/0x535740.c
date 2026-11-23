// Font_DrawTextLine: ported from Pizza Connection 2 at 0x535740.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535740
#include "pc2_port.h"

void __thiscall Font_DrawTextLine(void *self,void *arg1,int arg2)

{
  uint8_t flag1;
  int value2;
  int value3;
  int value4;
  
  value4 = 0;
  while( true ) {
    flag1 = *(uint8_t *)(value4 + arg2);
    value3 = value4;
    while (0x1f < flag1) {
      value2 = value3 + 1;
      value3 = value3 + 1;
      flag1 = *(uint8_t *)(value2 + arg2);
    }
    if (*(int *)((intptr_t)self + 0x9c4) != 0) {
      if (*(int *)((intptr_t)self + 0x9c4) == 2) {
        value2 = Font_MeasureRange(self,arg2,value4,value3);
        value2 = value2 >> 1;
      }
      else {
        value2 = Font_MeasureRange(self,arg2,value4,value3);
      }
      *(int *)((intptr_t)self + 0x9a0) = *(int *)((intptr_t)self + 0x9a0) - value2;
    }
    *(uint32_t *)((intptr_t)self + 0x9bc) = *(uint32_t *)((intptr_t)self + 0x9a0);
    *(uint32_t *)((intptr_t)self + 0x9c0) = *(uint32_t *)((intptr_t)self + 0x9a4);
    for (value2 = value4; value2 < value3; value2 = value2 + 1) {
      Text_DrawCharAdvance(self,arg1,*(char *)(value2 + arg2));
    }
    if (*(char *)(value2 + arg2) == '\0') break;
    value3 = *(int *)((intptr_t)self + 0x9ac) + *(int *)((intptr_t)self + 0x9b0);
    *(uint32_t *)((intptr_t)self + 0x9a0) = *(uint32_t *)((intptr_t)self + 0x9a8);
    value4 = value2 + 1;
    *(int *)((intptr_t)self + 0x9ac) = value3;
    *(int *)((intptr_t)self + 0x9a4) = value3;
    if (*(char *)(value4 + arg2) == '\n') {
      value4 = value2 + 2;
    }
    if (*(char *)(value4 + arg2) == '\0') {
      return;
    }
  }
  return;
}
