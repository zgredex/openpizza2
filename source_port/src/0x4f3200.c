// Grid_RebuildStreetNodes: ported from Pizza Connection 2 at 0x4f3200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f3200
#include "pc2_port.h"

void __thiscall Grid_RebuildStreetNodes(void *self,int arg1)

{
  int value1;
  void *pvVar2;
  int *ptr3;
  int value4;
  int value5;
  int value6;
  int local_2c;
  int local_28;
  int local_24 [5];
  uint32_t local_10;
  int local_c;
  int local_8;
  int local_4;
  
  value5 = 0;
  local_24[3] = *(int *)((intptr_t)self + 0x1c);
  local_24[1] = 1;
  local_24[2] = local_24[3] + 1;
  local_24[4] = local_24[3] + -1;
  local_c = -1 - local_24[3];
  local_8 = -local_24[3];
  local_4 = 1 - local_24[3];
  local_10 = 0xffffffff;
  IsoMap_MarkPlayerFootprints(self,arg1);
  value4 = 0;
  if (0 < *(int *)((intptr_t)self + 0x20)) {
    do {
      value6 = 0;
      if (0 < *(int *)((intptr_t)self + 0x1c)) {
        do {
          value1 = Grid_GetCell(self,value6,value4);
          if (((value1 != 0) && (*(int *)(value1 + 8) != 0)) &&
             (value1 = IsMenuIdRange(*(int *)(*(int *)(value1 + 8) + 4)), value1 != 0)) {
            value5 = value5 + 1;
          }
          value6 = value6 + 1;
        } while (value6 < *(int *)((intptr_t)self + 0x1c));
      }
      value4 = value4 + 1;
    } while (value4 < *(int *)((intptr_t)self + 0x20));
  }
  if (*(LPVOID *)((intptr_t)self + 0x9c) != (LPVOID)0x0) {
    Mem_Free(*(LPVOID *)((intptr_t)self + 0x9c));
    *(uint32_t *)((intptr_t)self + 0xa4) = 0;
  }
  pvVar2 = operator_new(value5 * 0x28);
  *(void **)((intptr_t)self + 0x9c) = pvVar2;
  arg1 = 0;
  if (0 < *(int *)((intptr_t)self + 0x20)) {
    do {
      value4 = 0;
      if (0 < *(int *)((intptr_t)self + 0x1c)) {
        do {
          ptr3 = (int *)Grid_GetCell(self,value4,arg1);
          if ((ptr3 != (int *)0x0) && (value5 = ptr3[2], value5 != 0)) {
            value6 = *(int *)(value5 + 0x10);
            value5 = IsMenuIdRange(*(int *)(value5 + 4));
            if (value5 == 0) {
              *(uint16_t *)(ptr3[2] + 0x24) = 0xffff;
            }
            else {
              UI_ComputeCenteredRect(self,ptr3,local_24,&local_28);
              Object_UpdateBufferRecord
                        (self,(int *)0x1,local_24[0] - *(int *)((intptr_t)self + 0x24),
                         local_28 - *(int *)((intptr_t)self + 0x28));
              *(short *)(ptr3[2] + 0x24) = *(short *)((intptr_t)self + 0xa4) + -1;
              value5 = Object_IsKnownId(value6);
              if (value5 == 0) {
                *(uint32_t *)(ptr3[2] + 0x28) = 0;
              }
              else {
                *(uint32_t *)(ptr3[2] + 0x28) = 1;
              }
            }
          }
          value4 = value4 + 1;
        } while (value4 < *(int *)((intptr_t)self + 0x1c));
      }
      arg1 = arg1 + 1;
    } while (arg1 < *(int *)((intptr_t)self + 0x20));
  }
  arg1 = 0;
  if (0 < *(int *)((intptr_t)self + 0xa4)) {
    do {
      value4 = Array_GetRecord28(self,1,arg1);
      value4 = *(int *)(value4 + 8);
      value5 = *(int *)((intptr_t)self + 0x4c);
      if (*(int *)(*(int *)(value5 + 8 + value4 * 0xc) + 0x28) != 0) {
        ptr3 = local_24;
        local_2c = 8;
        do {
          ptr3 = ptr3 + 1;
          value6 = *(int *)((intptr_t)self + 0x4c) + (**(int **)(value5 + value4 * 0xc + 8) + *ptr3) * 0xc
          ;
          if (((value6 != 0) && (*(int *)(value6 + 8) != 0)) &&
             ((value1 = Array_GetRecord28(self,1,(intptr_t)*(short *)(*(int *)(value6 + 8) + 0x24)),
              value1 != 0 && (*(int *)(*(int *)(value6 + 8) + 0x28) != 0)))) {
            Map_LinkCells(self,1,arg1,(intptr_t)*(short *)(*(int *)(value6 + 8) + 0x24));
          }
          local_2c = local_2c + -1;
        } while (local_2c != 0);
      }
      arg1 = arg1 + 1;
    } while (arg1 < *(int *)((intptr_t)self + 0xa4));
  }
  NoOp_2();
  Map_CollectObjectIDsByType(self,1,(uint32_t)(*(int *)((intptr_t)self + 0x118) == 0),1);
  return;
}
