// NamePool_AddName: ported from Pizza Connection 2 at 0x402f10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x402f10
#include "pc2_port.h"

void __thiscall NamePool_AddName(void *self,char *arg1,int arg2)

{
  char cVar1;
  uint32_t *uptr2;
  uint32_t uvalue3;
  int value4;
  uint32_t uvalue5;
  uint16_t *uptr6;
  int *ptr7;
  uint32_t *uptr8;
  char *cptr9;
  uint32_t *uptr10;
  char *cptr11;
  
  if (arg2 == 0) {
    ptr7 = (int *)((intptr_t)self + 8);
    uptr6 = (uint16_t *)((intptr_t)self + 0x12);
  }
  else if (arg2 == 1) {
    ptr7 = (int *)((intptr_t)self + 4);
    uptr6 = (uint16_t *)((intptr_t)self + 0x10);
  }
  else {
    if (arg2 != 2) {
      return;
    }
    ptr7 = (int *)((intptr_t)self + 0xc);
    uptr6 = (uint16_t *)((intptr_t)self + 0x14);
  }
  uvalue3 = 0xffffffff;
  cptr9 = arg1;
  do {
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cVar1 = *cptr9;
    cptr9 = cptr9 + 1;
  } while (cVar1 != '\0');
  if (0xf < ~uvalue3 - 1) {
    arg1[0xf] = '\0';
  }
  if ((*uptr6 & 0x3f) == 0) {
    uptr2 = operator_new(((short)*uptr6 + 0x40) * 0x10);
    if ((uint32_t *)*ptr7 != (uint32_t *)0x0) {
      uptr8 = (uint32_t *)*ptr7;
      uptr10 = uptr2;
      for (value4 = ((intptr_t)(short)*uptr6 & 0xfffffffU) << 2; value4 != 0; value4 = value4 + -1) {
        *uptr10 = *uptr8;
        uptr8 = uptr8 + 1;
        uptr10 = uptr10 + 1;
      }
      for (value4 = 0; value4 != 0; value4 = value4 + -1) {
        *(uint8_t *)uptr10 = *(uint8_t *)uptr8;
        uptr8 = (uint32_t *)((intptr_t)uptr8 + 1);
        uptr10 = (uint32_t *)((intptr_t)uptr10 + 1);
      }
      Mem_Free((LPVOID)*ptr7);
    }
    *ptr7 = (intptr_t)uptr2;
  }
  uvalue3 = 0xffffffff;
  do {
    cptr9 = arg1;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cptr9 = arg1 + 1;
    cVar1 = *arg1;
    arg1 = cptr9;
  } while (cVar1 != '\0');
  uvalue3 = ~uvalue3;
  cptr9 = cptr9 + -uvalue3;
  cptr11 = (char *)((short)*uptr6 * 0x10 + *ptr7);
  for (uvalue5 = uvalue3 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *(uint32_t *)cptr11 = *(uint32_t *)cptr9;
    cptr9 = cptr9 + 4;
    cptr11 = cptr11 + 4;
  }
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *cptr11 = *cptr9;
    cptr9 = cptr9 + 1;
    cptr11 = cptr11 + 1;
  }
  *uptr6 = *uptr6 + 1;
  return;
}
