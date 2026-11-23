// Game_GetRecordActionState: ported from Pizza Connection 2 at 0x483d10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x483d10
#include "pc2_port.h"

int __thiscall Game_GetRecordActionState(void *self,int arg1)

{
  int value1;
  int value2;
  void *this_00;
  int *ptr3;
  int value4;
  
  switch(*(uint32_t *)(arg1 + 0x30)) {
  default:
    return 0xf;
  case 10:
    return 0x10;
  case 0x10:
    break;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
    value1 = IDMap_Lookup((void *)((intptr_t)self + 0x20),*(int *)(arg1 + 0x50),(int *)0x0);
    value1 = *(int *)(value1 + 0x81c);
    if (value1 == -1) {
      return 0xe;
    }
    value2 = Game_GetCurrentPlayerCompanyName((intptr_t)self);
    return (-(uint32_t)(value1 != value2) & 0xfffffffa) + 0x1d;
  case 0x16:
    return 2;
  case 0x17:
    value1 = *(int *)(arg1 + 0x110);
    if (value1 == -1) {
      return 0xc;
    }
    value2 = Game_GetCurrentPlayerCompanyName((intptr_t)self);
    return (-(uint32_t)(value1 != value2) & 0xfffffffa) + 0x13;
  case 0x18:
    return 6;
  case 0x1a:
  case 0x1b:
  case 0x1c:
    return 0x18;
  case 0x1d:
  case 0x1e:
  case 0x1f:
    value1 = *(int *)(arg1 + 0x110);
    value2 = Game_GetCurrentPlayerCompanyName((intptr_t)self);
    return (-(uint32_t)(value1 != value2) & 0xfffffff1) + 0x11;
  }
  value1 = IDMap_Lookup((void *)((intptr_t)self + 0x20),*(int *)(arg1 + 0x50),(int *)0x0);
  this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
  ptr3 = Map_FindRecordByFirstField(this_00,value1);
  if (ptr3 != (int *)0x0) {
    return 0xe;
  }
  value2 = *(int *)(value1 + 0x81c);
  value4 = Game_GetCurrentPlayerCompanyName((intptr_t)self);
  if (value2 == value4) {
    return 0x1d;
  }
  return (-(uint32_t)(*(int *)(value1 + 0x81c) != -1) & 9) + 0xe;
}
