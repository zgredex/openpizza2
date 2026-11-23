// FUN_00556cb7: ported from Pizza Connection 2 at 0x556cb7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x556cb7
#include "pc2_port.h"

void __cdecl FUN_00556cb7(char *arg1,int arg2,uint32_t *arg3)

{
  uint32_t *uptr1;
  uint32_t local_14;
  uint32_t local_10;
  uint32_t local_c;
  int local_8;
  
  uptr1 = arg3;
  local_8 = 0x404e;
  *arg3 = 0;
  arg3[1] = 0;
  arg3[2] = 0;
  if (arg2 != 0) {
    arg3 = (uint32_t *)arg2;
    do {
      local_14 = *uptr1;
      local_10 = uptr1[1];
      local_c = uptr1[2];
      FUN_00556c5c(uptr1);
      FUN_00556c5c(uptr1);
      ___add_12(uptr1,&local_14);
      FUN_00556c5c(uptr1);
      local_10 = 0;
      local_c = 0;
      local_14 = (uint32_t)*arg1;
      ___add_12(uptr1,&local_14);
      arg1 = arg1 + 1;
      arg3 = (uint32_t *)((intptr_t)arg3 + -1);
    } while (arg3 != (uint32_t *)0x0);
  }
  while (uptr1[2] == 0) {
    uptr1[2] = uptr1[1] >> 0x10;
    local_8 = local_8 + 0xfff0;
    uptr1[1] = *uptr1 >> 0x10 | uptr1[1] << 0x10;
    *uptr1 = *uptr1 << 0x10;
  }
  while ((uptr1[2] & 0x8000) == 0) {
    FUN_00556c5c(uptr1);
    local_8 = local_8 + 0xffff;
  }
  *(uint16_t *)((intptr_t)uptr1 + 10) = (uint16_t)local_8;
  return;
}
