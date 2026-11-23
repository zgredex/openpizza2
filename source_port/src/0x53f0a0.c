// Sound_SetLastError: ported from Pizza Connection 2 at 0x53f0a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53f0a0
#include "pc2_port.h"

void __cdecl Sound_SetLastError(uint32_t *arg1,char *arg2,int arg3,uint32_t arg4)

{
  char cVar1;
  uint8_t flag2;
  char *cptr3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  int value6;
  uint8_t *bptr7;
  char *cptr8;
  uint8_t *bptr9;
  char *cptr10;
  uint8_t local_800 [1024];
  char local_400 [1024];
  
  cptr3 = Sound_FormatErrorString(arg3);
  uvalue4 = 0xffffffff;
  do {
    cptr8 = cptr3;
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    cptr8 = cptr3 + 1;
    cVar1 = *cptr3;
    cptr3 = cptr8;
  } while (cVar1 != '\0');
  uvalue4 = ~uvalue4;
  bptr7 = (uint8_t *)(cptr8 + -uvalue4);
  bptr9 = local_800;
  for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *(uint32_t *)bptr9 = *(uint32_t *)bptr7;
    bptr7 = bptr7 + 4;
    bptr9 = bptr9 + 4;
  }
  for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *bptr9 = *bptr7;
    bptr7 = bptr7 + 1;
    bptr9 = bptr9 + 1;
  }
  uvalue4 = 0xffffffff;
  cptr3 = &DAT_00574c10;
  do {
    cptr8 = cptr3;
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    cptr8 = cptr3 + 1;
    cVar1 = *cptr3;
    cptr3 = cptr8;
  } while (cVar1 != '\0');
  uvalue4 = ~uvalue4;
  value6 = -1;
  bptr7 = local_800;
  do {
    bptr9 = bptr7;
    if (value6 == 0) break;
    value6 = value6 + -1;
    bptr9 = bptr7 + 1;
    flag2 = *bptr7;
    bptr7 = bptr9;
  } while (flag2 != 0);
  bptr7 = (uint8_t *)(cptr8 + -uvalue4);
  bptr9 = bptr9 + -1;
  for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *(uint32_t *)bptr9 = *(uint32_t *)bptr7;
    bptr7 = bptr7 + 4;
    bptr9 = bptr9 + 4;
  }
  for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *bptr9 = *bptr7;
    bptr7 = bptr7 + 1;
    bptr9 = bptr9 + 1;
  }
  uvalue4 = 0xffffffff;
  do {
    cptr3 = arg2;
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    cptr3 = arg2 + 1;
    cVar1 = *arg2;
    arg2 = cptr3;
  } while (cVar1 != '\0');
  uvalue4 = ~uvalue4;
  value6 = -1;
  bptr7 = local_800;
  do {
    bptr9 = bptr7;
    if (value6 == 0) break;
    value6 = value6 + -1;
    bptr9 = bptr7 + 1;
    flag2 = *bptr7;
    bptr7 = bptr9;
  } while (flag2 != 0);
  bptr7 = (uint8_t *)(cptr3 + -uvalue4);
  bptr9 = bptr9 + -1;
  for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *(uint32_t *)bptr9 = *(uint32_t *)bptr7;
    bptr7 = bptr7 + 4;
    bptr9 = bptr9 + 4;
  }
  for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *bptr9 = *bptr7;
    bptr7 = bptr7 + 1;
    bptr9 = bptr9 + 1;
  }
  CRT_Vsprintf(local_400,local_800,&arg4);
  if ((LPVOID)*arg1 != (LPVOID)0x0) {
    Mem_Free((LPVOID)*arg1);
  }
  uvalue4 = 0xffffffff;
  cptr3 = local_400;
  do {
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    cVar1 = *cptr3;
    cptr3 = cptr3 + 1;
  } while (cVar1 != '\0');
  cptr3 = operator_new(~uvalue4);
  *arg1 = cptr3;
  if (cptr3 != (char *)0x0) {
    uvalue4 = 0xffffffff;
    cptr8 = local_400;
    do {
      cptr10 = cptr8;
      if (uvalue4 == 0) break;
      uvalue4 = uvalue4 - 1;
      cptr10 = cptr8 + 1;
      cVar1 = *cptr8;
      cptr8 = cptr10;
    } while (cVar1 != '\0');
    uvalue4 = ~uvalue4;
    cptr8 = cptr10 + -uvalue4;
    for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *(uint32_t *)cptr3 = *(uint32_t *)cptr8;
      cptr8 = cptr8 + 4;
      cptr3 = cptr3 + 4;
    }
    for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
      *cptr3 = *cptr8;
      cptr8 = cptr8 + 1;
      cptr3 = cptr3 + 1;
    }
  }
  return;
}
