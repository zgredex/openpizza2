// CRT_Istream_Prefix: ported from Pizza Connection 2 at 0x54d493.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d493
#include "pc2_port.h"

uint32_t __thiscall CRT_Istream_Prefix(void *self,int arg1)

{
  uint32_t uvalue1;
  int value2;
  uint32_t uvalue3;
  
  if (*(int *)((intptr_t)self + *(int *)(*(int *)self + 4) + 0x34) < 0) {
    CS_EnterRaw((LPCRITICAL_SECTION)((intptr_t)self + *(int *)(*(int *)self + 4) + 0x38));
  }
  if (arg1 != 0) {
    *(uint32_t *)((intptr_t)self + 8) = 0;
  }
  value2 = *(int *)(*(int *)self + 4);
  uvalue1 = *(uint32_t *)(value2 + 8 + (intptr_t)self);
  if (uvalue1 == 0) {
    if (*(int *)((intptr_t)self + value2 + 0x20) != 0) {
      if (arg1 != 0) {
        value2 = Stream_GetAvailable(*(int *)((intptr_t)self + value2 + 4));
        if (arg1 <= value2) goto LAB_0054d4f5;
      }
      Stream_AdvanceIterator(*(int **)(*(int *)(*(int *)self + 4) + 0x20 + (intptr_t)self));
    }
LAB_0054d4f5:
    value2 = *(int *)(*(int *)(*(int *)self + 4) + 4 + (intptr_t)self);
    if (*(int *)(value2 + 0x30) < 0) {
      CS_EnterRaw((LPCRITICAL_SECTION)(value2 + 0x34));
    }
    if ((arg1 == 0) && ((*(uint8_t *)(*(int *)(*(int *)self + 4) + 0x24 + (intptr_t)self) & 1) != 0)) {
      CRT_Istream_SkipWhitespace(self);
      uvalue1 = *(uint32_t *)(*(int *)(*(int *)self + 4) + 8 + (intptr_t)self);
      if (uvalue1 != 0) {
        *(uint32_t *)(*(int *)(*(int *)self + 4) + 8 + (intptr_t)self) = uvalue1 | 2;
        value2 = *(int *)(*(int *)(*(int *)self + 4) + 4 + (intptr_t)self);
        if (*(int *)(value2 + 0x30) < 0) {
          CS_LeaveRaw((LPCRITICAL_SECTION)(value2 + 0x34));
        }
        goto LAB_0054d551;
      }
    }
    uvalue3 = 1;
  }
  else {
    *(uint32_t *)((intptr_t)self + value2 + 8) = uvalue1 | 2;
LAB_0054d551:
    if (*(int *)((intptr_t)self + *(int *)(*(int *)self + 4) + 0x34) < 0) {
      CS_LeaveRaw((LPCRITICAL_SECTION)((intptr_t)self + *(int *)(*(int *)self + 4) + 0x38));
    }
    uvalue3 = 0;
  }
  return uvalue3;
}
