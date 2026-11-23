// Sound_GetStreamRefillSize: ported from Pizza Connection 2 at 0x541fc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541fc0
#include "pc2_port.h"

uint8_t __thiscall Sound_GetStreamRefillSize(void *self,uint32_t *arg1)

{
  int *ptr1;
  int value2;
  uint8_t uvalue3;
  bool flag4;
  int64_t lvalue5;
  uint32_t local_c;
  int local_8 [2];
  
  *arg1 = 0;
  if (*(char *)((intptr_t)self + 0x54) == '\0') {
    return 0;
  }
  if (*(char *)((intptr_t)self + 0x53) == '\0') {
    return 0;
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)self + 0x38));
  ptr1 = *(int **)(*(int *)((intptr_t)self + 0x28) + 0x48);
  if (ptr1 == (int *)0x0) {
    local_c = 0;
  }
  else {
    value2 = (**(code **)(*ptr1 + 0x10))(ptr1,&local_c,local_8);
    local_c = (value2 < 0) - 1 & local_c;
  }
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)((intptr_t)self + 0x38));
  value2 = *(int *)((intptr_t)self + 0x28);
  uvalue3 = 1;
  flag4 = local_c < *(uint32_t *)(value2 + 0x10) >> 1;
  if (*(char *)((intptr_t)self + 0x55) == '\0') {
    if (!flag4) {
      uvalue3 = 0;
      goto LAB_0054209f;
    }
  }
  else if (flag4) {
    uvalue3 = 0;
    goto LAB_0054209f;
  }
  local_8[0] = (uint32_t)*(uint16_t *)(value2 + 0x24) * *(int *)(value2 + 0x14);
  local_8[1] = 0;
  lvalue5 = __ftol();
  *arg1 = (uint32_t)lvalue5;
LAB_0054209f:
  if ((*(int *)((intptr_t)self + 0x8c) != 0) && (*(uint32_t *)((intptr_t)self + 0x98) < *arg1)) {
    *arg1 = *(uint32_t *)((intptr_t)self + 0x98);
  }
  return uvalue3;
}
