// Map_FindNearestCompanyBuilding: ported from Pizza Connection 2 at 0x47d150.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47d150
#include "pc2_port.h"

void * __thiscall Map_FindNearestCompanyBuilding(void *self,int arg1)

{
  void *this_00;
  int value1;
  void *pvVar2;
  void *pvVar3;
  int value4;
  int value5;
  int value6;
  int local_8;
  
  this_00 = *(void **)((intptr_t)self + 0x16f0);
  if (this_00 == (void *)0x0) {
    return (void *)0x0;
  }
  if (*(int *)(arg1 + 200) == 0) {
    value6 = 0;
  }
  else {
    value6 = *(int *)(*(int *)(arg1 + 200) + 0x20);
  }
  value1 = *(int *)((intptr_t)this_00 + 0x8c);
  local_8 = 0;
  pvVar2 = (void *)0x0;
  while (value1 = value1 + -1, -1 < value1) {
    pvVar3 = (void *)Game_MapRecordToGlobal(this_00,value1);
    if (*(int *)((intptr_t)pvVar3 + 0x38) == 0xd) {
      if (*(int *)((intptr_t)pvVar3 + 0xc4) == *(int *)(arg1 + 0xc4)) {
        if (*(int *)((intptr_t)pvVar3 + 200) == 0) {
          value4 = 0;
        }
        else {
          value4 = *(int *)(*(int *)((intptr_t)pvVar3 + 200) + 0x20);
        }
        value5 = *(int *)(value6 + 0xc) - *(int *)(value4 + 0xc);
        value4 = *(int *)(value6 + 0x10) - *(int *)(value4 + 0x10);
        value4 = value4 * value4 + value5 * value5;
        if ((pvVar2 == (void *)0x0) || (value4 < local_8)) {
          pvVar2 = pvVar3;
          local_8 = value4;
        }
      }
      else {
        Game_RemoveRecordFromLocalMap(this_00,pvVar3);
      }
    }
  }
  return pvVar2;
}
