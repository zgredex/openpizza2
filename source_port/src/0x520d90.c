// UI_SetLabelIdText: ported from Pizza Connection 2 at 0x520d90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520d90
#include "pc2_port.h"

void __thiscall UI_SetLabelIdText(void *self,uint32_t arg1,char *arg2)

{
  char cVar1;
  char *cptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  char *cptr5;
  
  *(uint32_t *)((intptr_t)self + 0x24) = arg1;
  if (*(LPVOID *)((intptr_t)self + 0x10) != (LPVOID)0x0) {
    Mem_Free(*(LPVOID *)((intptr_t)self + 0x10));
  }
  if (arg2 == (char *)0x0) {
    *(uint32_t *)((intptr_t)self + 0x10) = 0;
    return;
  }
  uvalue3 = 0xffffffff;
  cptr2 = arg2;
  do {
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cVar1 = *cptr2;
    cptr2 = cptr2 + 1;
  } while (cVar1 != '\0');
  cptr2 = operator_new(~uvalue3);
  uvalue3 = 0xffffffff;
  *(char **)((intptr_t)self + 0x10) = cptr2;
  do {
    cptr5 = arg2;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cptr5 = arg2 + 1;
    cVar1 = *arg2;
    arg2 = cptr5;
  } while (cVar1 != '\0');
  uvalue3 = ~uvalue3;
  cptr5 = cptr5 + -uvalue3;
  for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *(uint32_t *)cptr2 = *(uint32_t *)cptr5;
    cptr5 = cptr5 + 4;
    cptr2 = cptr2 + 4;
  }
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *cptr2 = *cptr5;
    cptr5 = cptr5 + 1;
    cptr2 = cptr2 + 1;
  }
  return;
}
