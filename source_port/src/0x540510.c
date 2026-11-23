// SoundPakManager_FindExtensionEntry: ported from Pizza Connection 2 at 0x540510.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x540510
#include "pc2_port.h"

int __thiscall SoundPakManager_FindExtensionEntry(void *self,char *arg1)

{
  char cVar1;
  uint8_t flag2;
  int value3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  uint8_t *bptr6;
  int value7;
  char *cptr8;
  uint8_t *bptr9;
  char *cptr10;
  bool flag11;
  uint32_t local_10;
  
  uvalue4 = 0xffffffff;
  do {
    cptr8 = arg1;
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    cptr8 = arg1 + 1;
    cVar1 = *arg1;
    arg1 = cptr8;
  } while (cVar1 != '\0');
  uvalue4 = ~uvalue4;
  cptr8 = cptr8 + -uvalue4;
  cptr10 = (char *)&local_10;
  for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *(uint32_t *)cptr10 = *(uint32_t *)cptr8;
    cptr8 = cptr8 + 4;
    cptr10 = cptr10 + 4;
  }
  for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *cptr10 = *cptr8;
    cptr8 = cptr8 + 1;
    cptr10 = cptr10 + 1;
  }
  CRT_Strlwr(&local_10);
  value3 = *(int *)((intptr_t)self + 0x628);
  do {
    if (value3 == 0) {
      return 0;
    }
    bptr9 = (uint8_t *)&local_10;
    bptr6 = (uint8_t *)(value3 + 0x40);
    do {
      flag2 = *bptr6;
      flag11 = flag2 < *bptr9;
      if (flag2 != *bptr9) {
LAB_00540583:
        value7 = (1 - (uint32_t)flag11) - (uint32_t)(flag11 != 0);
        goto LAB_00540588;
      }
      if (flag2 == 0) break;
      flag2 = bptr6[1];
      flag11 = flag2 < bptr9[1];
      if (flag2 != bptr9[1]) goto LAB_00540583;
      bptr6 = bptr6 + 2;
      bptr9 = bptr9 + 2;
    } while (flag2 != 0);
    value7 = 0;
LAB_00540588:
    if (value7 == 0) {
      return value3;
    }
    value3 = *(int *)(value3 + 0x50);
  } while( true );
}
