// String_SetField48: ported from Pizza Connection 2 at 0x403420.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403420
#include "pc2_port.h"

void __thiscall String_SetField48(void *self,char *arg1)

{
  char cVar1;
  char *cptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  char *cptr5;
  
  if (*(LPVOID *)((intptr_t)self + 0x48) != (LPVOID)0x0) {
    Mem_Free(*(LPVOID *)((intptr_t)self + 0x48));
  }
  uvalue3 = 0xffffffff;
  cptr2 = arg1;
  do {
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cVar1 = *cptr2;
    cptr2 = cptr2 + 1;
  } while (cVar1 != '\0');
  cptr2 = operator_new(~uvalue3);
  uvalue3 = 0xffffffff;
  *(char **)((intptr_t)self + 0x48) = cptr2;
  do {
    cptr5 = arg1;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cptr5 = arg1 + 1;
    cVar1 = *arg1;
    arg1 = cptr5;
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
