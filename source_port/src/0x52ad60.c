// UI_BuildListItem: ported from Pizza Connection 2 at 0x52ad60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52ad60
#include "pc2_port.h"

void __thiscall UI_BuildListItem(void *self,int arg1)

{
  char cVar1;
  void *this_00;
  char *cptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  char *cptr5;
  
  this_00 = *(void **)(*(int *)((intptr_t)self + 8) + 0x134);
  if (*(int *)((intptr_t)self + 0x54) == 0) {
    if (*(int *)((intptr_t)self + 0xc0) == 0) {
      *(uint32_t *)(arg1 + 8) = 0x6e;
    }
    else {
      *(uint32_t *)(arg1 + 8) = 0x70;
    }
  }
  else if (*(int *)((intptr_t)self + 0xc0) == 0) {
    *(uint32_t *)(arg1 + 8) = 0x6d;
  }
  else {
    *(uint32_t *)(arg1 + 8) = 0x6f;
  }
  *(uint32_t *)(arg1 + 0x14) = *(uint32_t *)((intptr_t)self + 0xb4);
  *(uint32_t *)(arg1 + 0x20) = 3;
  cptr2 = (char *)UI_FindStringRecord(this_00,(uint8_t *)((intptr_t)self + 0x1ac));
  uvalue3 = 0xffffffff;
  do {
    cptr5 = cptr2;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cptr5 = cptr2 + 1;
    cVar1 = *cptr2;
    cptr2 = cptr5;
  } while (cVar1 != '\0');
  uvalue3 = ~uvalue3;
  cptr2 = cptr5 + -uvalue3;
  cptr5 = (char *)(arg1 + 0x24);
  for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *(uint32_t *)cptr5 = *(uint32_t *)cptr2;
    cptr2 = cptr2 + 4;
    cptr5 = cptr5 + 4;
  }
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *cptr5 = *cptr2;
    cptr2 = cptr2 + 1;
    cptr5 = cptr5 + 1;
  }
  *(uint32_t *)(arg1 + 0x430) = *(uint32_t *)((intptr_t)self + 0xd4);
  *(uint32_t *)(arg1 + 0x434) = *(uint32_t *)((intptr_t)self + 0xd8);
  *(uint32_t *)(arg1 + 0x438) = *(uint32_t *)((intptr_t)self + 0xdc);
  return;
}
