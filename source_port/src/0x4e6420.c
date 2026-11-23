// Filename_ToUpperStripExt: ported from Pizza Connection 2 at 0x4e6420.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e6420
#include "pc2_port.h"

void __cdecl Filename_ToUpperStripExt(char *arg1)

{
  char cVar1;
  char *cptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  char *cptr5;
  char *cptr6;
  uint32_t *uptr7;
  uint32_t *uptr8;
  uint32_t local_64 [25];
  
  uvalue3 = 0xffffffff;
  cptr2 = arg1;
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
  uptr7 = local_64;
  for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *uptr7 = *(uint32_t *)cptr2;
    cptr2 = cptr2 + 4;
    uptr7 = (uint32_t *)((intptr_t)uptr7 + 4);
  }
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *(char *)uptr7 = *cptr2;
    cptr2 = cptr2 + 1;
    uptr7 = (uint32_t *)((intptr_t)uptr7 + 1);
  }
  CRT_Strupr(local_64);
  cptr2 = _strchr((char *)local_64,0x2e);
  if (cptr2 != (char *)0x0) {
    uvalue3 = 0xffffffff;
    cptr5 = &DAT_0057ca0c;
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
  }
  uvalue3 = 0xffffffff;
  uptr7 = local_64;
  do {
    uptr8 = uptr7;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    uptr8 = (uint32_t *)((intptr_t)uptr7 + 1);
    uvalue4 = *uptr7;
    uptr7 = uptr8;
  } while ((char)uvalue4 != '\0');
  uvalue3 = ~uvalue3;
  cptr2 = (char *)((intptr_t)uptr8 - uvalue3);
  for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *(uint32_t *)arg1 = *(uint32_t *)cptr2;
    cptr2 = cptr2 + 4;
    arg1 = arg1 + 4;
  }
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *arg1 = *cptr2;
    cptr2 = cptr2 + 1;
    arg1 = arg1 + 1;
  }
  return;
}
