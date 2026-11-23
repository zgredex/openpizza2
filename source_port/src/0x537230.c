// Window_Construct: ported from Pizza Connection 2 at 0x537230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x537230
#include "pc2_port.h"


uint32_t * __thiscall Window_Construct(void *self,int arg1,int arg2,uint32_t arg3)

{
  int *ptr1;
  void *pvVar2;
  int value3;
  uint32_t *uptr4;
  uint32_t local_30c [192];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ad1e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(uint8_t ***)self = &PTR_Window_Delete_0055c814;
  *(uint32_t *)((intptr_t)self + 0x14) = 0;
  if ((intptr_t)arg3 < 8) {
    if (arg3 != 1) goto LAB_005372e8;
  }
  else {
    if (0x20 < (intptr_t)arg3) {
      arg3 = 4;
      goto LAB_005372e8;
    }
    if (0x18 < (intptr_t)arg3) {
      arg3 = 3;
      goto LAB_005372e8;
    }
    if (0xf < (intptr_t)arg3) {
      arg3 = 2;
      goto LAB_005372e8;
    }
    arg3 = 1;
  }
  uptr4 = local_30c;
  for (value3 = 0xc0; value3 != 0; value3 = value3 + -1) {
    *uptr4 = 0;
    uptr4 = uptr4 + 1;
  }
  pvVar2 = operator_new(0x20c);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    ptr1 = (int *)0x0;
  }
  else {
    ptr1 = Palette_Init(pvVar2,0,local_30c,0);
  }
  *(int **)((intptr_t)self + 0x14) = ptr1;
LAB_005372e8:
  local_4 = 0xffffffff;
  *(char *)((intptr_t)self + 0x11) = (char)arg3;
  *(int *)((intptr_t)self + 4) = arg1;
  value3 = (arg3 & 0xff) * arg1 * arg2;
  *(int *)((intptr_t)self + 0xc) = value3;
  *(uint32_t *)((intptr_t)self + 0x18) = 0;
  *(int *)((intptr_t)self + 8) = arg2;
  *(char *)((intptr_t)self + 0x10) = (char)arg3 << 3;
  pvVar2 = operator_new((value3 >> 1) * 2 + 2);
  *(void **)((intptr_t)self + 0x18) = pvVar2;
  ExceptionList = local_c;
  return self;
}
