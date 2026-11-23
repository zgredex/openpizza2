// Game_FindNearestTransportBuilding: ported from Pizza Connection 2 at 0x4d8be0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d8be0
#include "pc2_port.h"

int __thiscall Game_FindNearestTransportBuilding(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  Array_GetRecord28(*(void **)((intptr_t)self + 0xfa8),1,*(int *)(arg1 + 0x54));
  value4 = 0;
  arg1 = 0;
  value3 = 10000000;
  value1 = 0;
  if (0 < *(int *)((intptr_t)self + 0xfc0)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),value4,(int *)0x0);
      if ((*(int *)(value1 + 4) == 2) && (*(int *)(value1 + 0x54) != -1)) {
        Array_GetRecord28(*(void **)((intptr_t)self + 0xfa8),1,*(int *)(value1 + 0x54));
        value2 = Map_FindShortestPath();
        if (value2 < value3) {
          value3 = value2;
          arg1 = value1;
        }
      }
      value4 = value4 + 1;
    } while (value4 < *(int *)((intptr_t)self + 0xfc0));
    value1 = arg1;
  }
  return value1;
}
