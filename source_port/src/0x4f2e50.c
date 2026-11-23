// IsoMap_MarkPlayerFootprints: ported from Pizza Connection 2 at 0x4f2e50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f2e50
#include "pc2_port.h"

void __thiscall IsoMap_MarkPlayerFootprints(void *self,int arg1)

{
  short svalue1;
  char cVar2;
  void *this_00;
  int value3;
  uint32_t *this_01;
  int value4;
  int value5;
  int local_4;
  
  value5 = 0;
  if (0 < *(int *)((intptr_t)self + 0x1c) * *(int *)((intptr_t)self + 0x20)) {
    value4 = 0;
    do {
      value3 = *(int *)(value4 + 8 + *(int *)((intptr_t)self + 0x4c));
      if ((value3 != 0) && (*(int *)(value3 + 0x10) == -2)) {
        *(uint32_t *)(value3 + 0x10) = 0xffffffff;
      }
      value5 = value5 + 1;
      value4 = value4 + 0xc;
    } while (value5 < *(int *)((intptr_t)self + 0x1c) * *(int *)((intptr_t)self + 0x20));
  }
  local_4 = 0;
  if (0 < *(int *)(arg1 + 0x170c)) {
    do {
      value5 = IDMap_Lookup((void *)(arg1 + 0x16f8),local_4,(int *)0x0);
      if (((value5 != 0) &&
          (this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(value5 + 4),
                                          (int *)0x0), this_00 != (void *)0x0)) &&
         (value4 = Grid_GetCell(self,*(int *)(value5 + 0x18),*(int *)(value5 + 0x1c)), value4 != 0)) {
        cVar2 = Game_GetPlayerByte8(value5);
        if (cVar2 == '\x01') {
          value3 = Game_FindGroupSlot(this_00,*(int *)(*(int *)(value4 + 8) + 0x10),
                                     *(int *)(value5 + 8));
          if (value3 == 2) {
            svalue1 = *(short *)((intptr_t)this_00 + *(int *)(value5 + 8) * 0xc + 0x80);
          }
          else {
            if (value3 != 3) {
              *(uint32_t *)(*(int *)(value4 + 8) + 0x1c) = 0xffffffff;
              goto LAB_004f2f49;
            }
            svalue1 = *(short *)((intptr_t)this_00 + *(int *)(value5 + 8) * 0xc + 0x82);
          }
          *(int *)(*(int *)(value4 + 8) + 0x1c) = (intptr_t)svalue1;
        }
LAB_004f2f49:
        this_01 = Grid_CollectFootprintCells(self,value5);
        value5 = 0;
        if (0 < (intptr_t)this_01[5]) {
          do {
            value4 = IDMap_Lookup(this_01,value5,(int *)0x0);
            if (*(int *)(*(int *)(value4 + 8) + 0x10) == -1) {
              *(uint32_t *)(*(int *)(value4 + 8) + 0x10) = 0xfffffffe;
            }
            value5 = value5 + 1;
          } while (value5 < (intptr_t)this_01[5]);
        }
        List_Node_Reset((intptr_t)this_01);
        if (this_01 != (uint32_t *)0x0) {
          (**(code **)*this_01)(1);
        }
      }
      local_4 = local_4 + 1;
    } while (local_4 < *(int *)(arg1 + 0x170c));
  }
  return;
}
