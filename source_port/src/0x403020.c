// IDMap_GetRandomName: ported from Pizza Connection 2 at 0x403020.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403020
#include "pc2_port.h"

void __thiscall IDMap_GetRandomName(void *self,int arg1,char *arg2)

{
  char cVar1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  int value4;
  char *cptr5;
  char *cptr6;
  char *cptr7;
  
  if (arg1 == 0) {
    uvalue2 = Random_Mod((intptr_t)*(short *)((intptr_t)self + 0x10));
    value4 = *(int *)((intptr_t)self + 4);
  }
  else {
    uvalue2 = Random_Mod((intptr_t)*(short *)((intptr_t)self + 0x12));
    value4 = *(int *)((intptr_t)self + 8);
  }
  uvalue3 = 0xffffffff;
  cptr5 = (char *)(uvalue2 * 0x10 + value4);
  do {
    cptr6 = cptr5;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cptr6 = cptr5 + 1;
    cVar1 = *cptr5;
    cptr5 = cptr6;
  } while (cVar1 != '\0');
  uvalue3 = ~uvalue3;
  cptr5 = cptr6 + -uvalue3;
  cptr6 = arg2;
  for (uvalue2 = uvalue3 >> 2; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
    *(uint32_t *)cptr6 = *(uint32_t *)cptr5;
    cptr5 = cptr5 + 4;
    cptr6 = cptr6 + 4;
  }
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *cptr6 = *cptr5;
    cptr5 = cptr5 + 1;
    cptr6 = cptr6 + 1;
  }
  uvalue2 = 0xffffffff;
  cptr5 = DAT_00582e4c;
  do {
    cptr6 = cptr5;
    if (uvalue2 == 0) break;
    uvalue2 = uvalue2 - 1;
    cptr6 = cptr5 + 1;
    cVar1 = *cptr5;
    cptr5 = cptr6;
  } while (cVar1 != '\0');
  uvalue2 = ~uvalue2;
  value4 = -1;
  cptr5 = arg2;
  do {
    cptr7 = cptr5;
    if (value4 == 0) break;
    value4 = value4 + -1;
    cptr7 = cptr5 + 1;
    cVar1 = *cptr5;
    cptr5 = cptr7;
  } while (cVar1 != '\0');
  cptr5 = cptr6 + -uvalue2;
  cptr6 = cptr7 + -1;
  for (uvalue3 = uvalue2 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *(uint32_t *)cptr6 = *(uint32_t *)cptr5;
    cptr5 = cptr5 + 4;
    cptr6 = cptr6 + 4;
  }
  for (uvalue2 = uvalue2 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
    *cptr6 = *cptr5;
    cptr5 = cptr5 + 1;
    cptr6 = cptr6 + 1;
  }
  uvalue2 = Random_Mod((intptr_t)*(short *)((intptr_t)self + 0x14));
  uvalue3 = 0xffffffff;
  cptr5 = (char *)(uvalue2 * 0x10 + *(int *)((intptr_t)self + 0xc));
  do {
    cptr6 = cptr5;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cptr6 = cptr5 + 1;
    cVar1 = *cptr5;
    cptr5 = cptr6;
  } while (cVar1 != '\0');
  uvalue3 = ~uvalue3;
  value4 = -1;
  do {
    cptr5 = arg2;
    if (value4 == 0) break;
    value4 = value4 + -1;
    cptr5 = arg2 + 1;
    cVar1 = *arg2;
    arg2 = cptr5;
  } while (cVar1 != '\0');
  cptr6 = cptr6 + -uvalue3;
  cptr5 = cptr5 + -1;
  for (uvalue2 = uvalue3 >> 2; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
    *(uint32_t *)cptr5 = *(uint32_t *)cptr6;
    cptr6 = cptr6 + 4;
    cptr5 = cptr5 + 4;
  }
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *cptr5 = *cptr6;
    cptr6 = cptr6 + 1;
    cptr5 = cptr5 + 1;
  }
  return;
}
