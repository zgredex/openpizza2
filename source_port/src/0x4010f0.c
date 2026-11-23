// Stats_Report_ConstructEmpty: ported from Pizza Connection 2 at 0x4010f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4010f0
#include "pc2_port.h"

uint32_t * __thiscall
Stats_Report_ConstructEmpty(void *self,uint32_t arg1,uint32_t arg2)

{
  int value1;
  uint32_t unaff_EDI;
  uint32_t *uptr2;
  uint8_t *uptr3;
  
  *(uint8_t ***)self = &PTR_StatsPeriodReport_Delete_0055c2e0;
  uptr2 = (uint32_t *)((intptr_t)self + 0x78);
  for (value1 = 0x19; value1 != 0; value1 = value1 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x10);
  for (value1 = 0x1a; value1 != 0; value1 = value1 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr3 = (uint8_t *)((intptr_t)self + 0xdc);
  value1 = 0x14;
  do {
    String_Format(uptr3,DAT_00582e4c,unaff_EDI);
    uptr3 = uptr3 + 0x20;
    value1 = value1 + -1;
  } while (value1 != 0);
  *(uint32_t *)((intptr_t)self + 0xc) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 4) = arg1;
  *(uint32_t *)((intptr_t)self + 8) = arg2;
  return self;
}
