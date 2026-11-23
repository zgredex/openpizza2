// Resource_Read: ported from Pizza Connection 2 at 0x402750.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x402750
#include "pc2_port.h"

uint32_t __thiscall Resource_Read(void *self,char *arg1,uint32_t arg2,int arg3)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  char *cptr4;
  
  value1 = (intptr_t)self + 0x1688;
  CS_Enter(value1);
  value2 = *(int *)(arg3 + 0x10);
  if (*(uint32_t *)(arg3 + 8) <= value2 + arg2) {
    arg2 = *(uint32_t *)(arg3 + 8) - value2;
  }
  if ((intptr_t)arg2 < 0) {
    CS_Leave(value1);
    return 0;
  }
  if (*(int *)(arg3 + 0x1c) == 2) {
    cptr4 = (char *)(*(int *)(arg3 + 0x20) + *(int *)(arg3 + 0xc) + value2);
    for (uvalue3 = arg2 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
      *(uint32_t *)arg1 = *(uint32_t *)cptr4;
      cptr4 = cptr4 + 4;
      arg1 = arg1 + 4;
    }
    for (uvalue3 = arg2 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
      *arg1 = *cptr4;
      cptr4 = cptr4 + 1;
      arg1 = arg1 + 1;
    }
  }
  else {
    if ((*(int **)((intptr_t)self + 0x1ac0) != *(int **)(arg3 + 0x18)) ||
       (*(int *)((intptr_t)self + 0x1abc) != *(int *)(arg3 + 0xc) + value2)) {
      CRT_Fseek(*(int **)(arg3 + 0x18),*(int *)(arg3 + 0xc) + value2,0);
    }
    arg2 = CRT_FreadLocked(arg1,1,arg2,*(int **)(arg3 + 0x18));
    *(uint32_t *)((intptr_t)self + 0x1abc) = *(int *)(arg3 + 0xc) + *(int *)(arg3 + 0x10) + arg2;
    *(uint32_t *)((intptr_t)self + 0x1ac0) = *(uint32_t *)(arg3 + 0x18);
  }
  *(uint32_t *)(arg3 + 0x10) = *(int *)(arg3 + 0x10) + arg2;
  CS_Leave(value1);
  return arg2;
}
