// Record_CopyTemplate98: ported from Pizza Connection 2 at 0x533310.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x533310
#include "pc2_port.h"

void Record_CopyTemplate98(char *arg1,int arg2)

{
  char cVar1;
  char *cptr2;
  uint8_t *uptr3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  int value6;
  int value7;
  char *cptr8;
  int64_t lvalue9;
  
  uvalue4 = 0xffffffff;
  cptr2 = arg1;
  do {
    cptr8 = cptr2;
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    cptr8 = cptr2 + 1;
    cVar1 = *cptr2;
    cptr2 = cptr8;
  } while (cVar1 != '\0');
  uvalue4 = ~uvalue4;
  cptr2 = cptr8 + -uvalue4;
  cptr8 = (char *)(arg2 + 0x80);
  for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *(uint32_t *)cptr8 = *(uint32_t *)cptr2;
    cptr2 = cptr2 + 4;
    cptr8 = cptr8 + 4;
  }
  for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *cptr8 = *cptr2;
    cptr2 = cptr2 + 1;
    cptr8 = cptr8 + 1;
  }
  *(uint32_t *)(arg2 + 0x60) = *(uint32_t *)(arg1 + 0x70);
  *(uint32_t *)(arg2 + 100) = *(uint32_t *)(arg1 + 0x74);
  *(uint32_t *)(arg2 + 0x68) = *(uint32_t *)(arg1 + 0x78);
  *(uint32_t *)(arg2 + 0x6c) = *(uint32_t *)(arg1 + 0x7c);
  lvalue9 = __ftol();
  *(char *)(arg2 + 0x90) = (char)lvalue9;
  *(uint32_t *)(arg2 + 0x70) = *(uint32_t *)(arg1 + 0x88);
  *(uint32_t *)(arg2 + 0x74) = *(uint32_t *)(arg1 + 0x8c);
  *(uint32_t *)(arg2 + 0x78) = *(uint32_t *)(arg1 + 0x90);
  *(uint32_t *)(arg2 + 0x7c) = *(uint32_t *)(arg1 + 0x94);
  value6 = arg2 + 5;
  cptr2 = arg1 + 0x14;
  value7 = 6;
  do {
    *(uint16_t *)(value6 + -5) = *(uint16_t *)(cptr2 + -4);
    *(uint16_t *)(value6 + -3) = *(uint16_t *)cptr2;
    *(bool *)value6 = *(int *)(cptr2 + 4) == 1;
    *(char *)(value6 + -1) = cptr2[8];
    cptr2 = cptr2 + 0x10;
    value6 = value6 + 6;
    value7 = value7 + -1;
  } while (value7 != 0);
  uptr3 = (uint8_t *)(arg2 + 0x28);
  value6 = 10;
  do {
    *(uint16_t *)(uptr3 + -4) = 0xffff;
    *(uint16_t *)(uptr3 + -2) = 0;
    *uptr3 = 0;
    uptr3[1] = 0;
    uptr3 = uptr3 + 6;
    value6 = value6 + -1;
  } while (value6 != 0);
  return;
}
