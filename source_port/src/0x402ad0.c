// ResourceManager_FindExtensionAlias: ported from Pizza Connection 2 at 0x402ad0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x402ad0
#include "pc2_port.h"

int __thiscall ResourceManager_FindExtensionAlias(void *self,char *arg1)

{
  char cVar1;
  uint8_t flag2;
  int value3;
  uint8_t *bptr4;
  int value5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  char *cptr8;
  uint8_t *bptr9;
  char *cptr10;
  bool flag11;
  uint32_t local_104;
  
  value3 = *(int *)((intptr_t)self + 0x1ab4);
  uvalue6 = 0xffffffff;
  do {
    cptr8 = arg1;
    if (uvalue6 == 0) break;
    uvalue6 = uvalue6 - 1;
    cptr8 = arg1 + 1;
    cVar1 = *arg1;
    arg1 = cptr8;
  } while (cVar1 != '\0');
  uvalue6 = ~uvalue6;
  cptr8 = cptr8 + -uvalue6;
  cptr10 = (char *)&local_104;
  for (uvalue7 = uvalue6 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
    *(uint32_t *)cptr10 = *(uint32_t *)cptr8;
    cptr8 = cptr8 + 4;
    cptr10 = cptr10 + 4;
  }
  for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *cptr10 = *cptr8;
    cptr8 = cptr8 + 1;
    cptr10 = cptr10 + 1;
  }
  CRT_Strlwr(&local_104);
  do {
    if (value3 == 0) {
      return 0;
    }
    bptr9 = (uint8_t *)&local_104;
    bptr4 = (uint8_t *)(value3 + 0x40);
    do {
      flag2 = *bptr4;
      flag11 = flag2 < *bptr9;
      if (flag2 != *bptr9) {
LAB_00402b48:
        value5 = (1 - (uint32_t)flag11) - (uint32_t)(flag11 != 0);
        goto LAB_00402b4d;
      }
      if (flag2 == 0) break;
      flag2 = bptr4[1];
      flag11 = flag2 < bptr9[1];
      if (flag2 != bptr9[1]) goto LAB_00402b48;
      bptr4 = bptr4 + 2;
      bptr9 = bptr9 + 2;
    } while (flag2 != 0);
    value5 = 0;
LAB_00402b4d:
    if (value5 == 0) {
      return value3;
    }
    value3 = *(int *)(value3 + 0x50);
  } while( true );
}
