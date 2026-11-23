// ResourceIterator_Next: ported from Pizza Connection 2 at 0x401f90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401f90
#include "pc2_port.h"

uint32_t __thiscall ResourceIterator_Next(void *self,char *arg1)

{
  uint32_t *uptr1;
  char cVar2;
  int value3;
  int value4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  char *cptr7;
  char *cptr8;
  
  value3 = *(int *)(arg1 + 0x114);
  if (*(int *)((intptr_t)self + 0x1684) <= value3) {
    return 0;
  }
  value4 = *(int *)(arg1 + 0x118);
  *(int *)(arg1 + 0x118) = value4 + 1;
  if (**(int **)(value3 * 0x120 + 0x110 + (intptr_t)self) <= value4 + 1) {
    arg1[0x118] = '\0';
    arg1[0x119] = '\0';
    arg1[0x11a] = '\0';
    arg1[0x11b] = '\0';
    *(int *)(arg1 + 0x114) = value3 + 1;
    if (*(int *)((intptr_t)self + 0x1684) <= value3 + 1) {
      return 0;
    }
  }
  value3 = *(int *)(*(int *)(arg1 + 0x114) * 0x120 + 0x114 + (intptr_t)self);
  uptr1 = (uint32_t *)(value3 + *(int *)(arg1 + 0x118) * 0x14);
  uvalue5 = 0xffffffff;
  cptr7 = *(char **)(value3 + 0x10 + *(int *)(arg1 + 0x118) * 0x14);
  do {
    cptr8 = cptr7;
    if (uvalue5 == 0) break;
    uvalue5 = uvalue5 - 1;
    cptr8 = cptr7 + 1;
    cVar2 = *cptr7;
    cptr7 = cptr8;
  } while (cVar2 != '\0');
  uvalue5 = ~uvalue5;
  cptr7 = cptr8 + -uvalue5;
  cptr8 = arg1;
  for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *(uint32_t *)cptr8 = *(uint32_t *)cptr7;
    cptr7 = cptr7 + 4;
    cptr8 = cptr8 + 4;
  }
  for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *cptr8 = *cptr7;
    cptr7 = cptr7 + 1;
    cptr8 = cptr8 + 1;
  }
  *(uint32_t *)(arg1 + 0x104) = *uptr1;
  *(uint32_t *)(arg1 + 0x108) = uptr1[1];
  *(uint32_t *)(arg1 + 0x10c) = uptr1[2];
  *(uint32_t *)(arg1 + 0x110) = uptr1[3];
  return 1;
}
