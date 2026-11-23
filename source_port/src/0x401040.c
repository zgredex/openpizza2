// Stats_Report_Construct: ported from Pizza Connection 2 at 0x401040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401040
#include "pc2_port.h"

uint32_t * __thiscall
Stats_Report_Construct(void *self,uint32_t arg1,uint32_t arg2,int arg3)

{
  int value1;
  int value2;
  uint8_t *uptr3;
  int value4;
  uint32_t unaff_EDI;
  uint32_t *uptr5;
  
  *(uint8_t ***)self = &PTR_StatsPeriodReport_Delete_0055c2e0;
  value4 = 0;
  uptr5 = (uint32_t *)((intptr_t)self + 0x78);
  for (value2 = 0x19; value2 != 0; value2 = value2 + -1) {
    *uptr5 = 0;
    uptr5 = uptr5 + 1;
  }
  uptr5 = (uint32_t *)((intptr_t)self + 0x10);
  for (value2 = 0x1a; value2 != 0; value2 = value2 + -1) {
    *uptr5 = 0;
    uptr5 = uptr5 + 1;
  }
  value2 = *(int *)(arg3 + 0x15c);
  if (0 < value2) {
    uptr3 = (uint8_t *)((intptr_t)self + 0xdc);
    do {
      value1 = IDMap_Lookup((void *)(arg3 + 0x148),value4,(int *)0x0);
      String_Format(uptr3,&DAT_005630d0,value1 + 4);
      value4 = value4 + 1;
      uptr3 = uptr3 + 0x20;
    } while (value4 < value2);
  }
  if (value2 < 0x14) {
    value4 = 0x14 - value2;
    uptr3 = (uint8_t *)(value2 * 0x20 + 0xdc + (intptr_t)self);
    do {
      String_Format(uptr3,DAT_00582e4c,unaff_EDI);
      uptr3 = uptr3 + 0x20;
      value4 = value4 + -1;
    } while (value4 != 0);
  }
  *(int *)((intptr_t)self + 0xc) = value2;
  *(uint32_t *)((intptr_t)self + 8) = arg2;
  *(uint32_t *)((intptr_t)self + 4) = arg1;
  return self;
}
