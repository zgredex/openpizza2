// Object_SetBuildingRecordForAllCompanies: ported from Pizza Connection 2 at 0x50a0b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50a0b0
#include "pc2_port.h"

void __thiscall Object_SetBuildingRecordForAllCompanies(void *self,int arg1,int arg2)

{
  void *this_00;
  uint32_t *uptr1;
  int value2;
  
  if (arg2 == 0) {
    this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                   (int *)0x0);
    arg2 = Map_GetRandomBuildingOfType(this_00,arg1,0,'\0');
  }
  *(int *)((intptr_t)self + 0xcc) = arg2;
  uptr1 = (uint32_t *)((intptr_t)self + 0xd4);
  value2 = 8;
  do {
    *uptr1 = *(uint32_t *)((intptr_t)self + 0xcc);
    uptr1 = uptr1 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  return;
}
