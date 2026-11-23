// Map_PickRandomSpawnCell: ported from Pizza Connection 2 at 0x4f4f20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f4f20
#include "pc2_port.h"

int __thiscall Map_PickRandomSpawnCell(void *self,int arg1)

{
  int value1;
  uint32_t uvalue2;
  int *ptr3;
  int *ptr4;
  int value5;
  int value6;
  int value7;
  int local_7dc;
  int local_7d8;
  int *local_7d4;
  int local_7d0 [500];
  
  value6 = 0;
  value7 = 0;
  local_7d8 = 0;
  if (arg1 == 1) {
    local_7dc = *(int *)((intptr_t)self + 0x20);
    if (0 < local_7dc) {
      do {
        value5 = *(int *)((intptr_t)self + 0x1c);
        value1 = value7;
        if (0 < value5) {
          ptr3 = local_7d0 + value6;
          value1 = value7 + value5;
          ptr4 = (int *)(*(int *)((intptr_t)self + 0x4c) + 8 + value7 * 0xc);
          do {
            value7 = *ptr4;
            if (((value7 != 0) && (*(int *)(value7 + 4) == 0x354)) && (*(short *)(value7 + 0x24) != -1)
               ) {
              value6 = local_7d8 + 1;
              *ptr3 = *(int *)((intptr_t)self + 0x9c) + *(short *)(value7 + 0x24) * 0x28;
              ptr3 = ptr3 + 1;
              local_7d8 = value6;
            }
            ptr4 = ptr4 + 3;
            value5 = value5 + -1;
          } while (value5 != 0);
        }
        local_7dc = local_7dc + -1;
        value7 = value1;
      } while (local_7dc != 0);
      if (0 < value6) {
        uvalue2 = Random_RangeFast(0,value6 - 1);
        return local_7d0[uvalue2];
      }
    }
  }
  else if ((arg1 == 2) && (local_7d8 = 0, 0 < *(int *)((intptr_t)self + 0x20))) {
    do {
      local_7dc = 0;
      if (0 < *(int *)((intptr_t)self + 0x1c)) {
        local_7d4 = local_7d0 + value6;
        value5 = value7 * 0xc;
        do {
          value1 = *(int *)(value5 + 8 + *(int *)((intptr_t)self + 0x4c));
          if (value1 != 0) {
            value1 = IsMenuId34EOr350(*(int *)(value1 + 4));
            if (value1 != 0) {
              value1 = *(int *)((intptr_t)self + 0x4c);
              if (((*(int *)(*(int *)(value1 + 8 + (value7 - *(int *)((intptr_t)self + 0x1c)) * 0xc) + 4)
                    == -1) && (*(int *)(*(int *)(value5 + 8 + value1) + 0x10) == -1)) &&
                 (value1 = *(int *)(value1 + 8 + (*(int *)((intptr_t)self + 0x1c) + value7) * 0xc),
                 *(int *)(value1 + 0x10) == -1)) {
                value6 = value6 + 1;
                *local_7d4 = *(int *)((intptr_t)self + 0x9c) + *(short *)(value1 + 0x24) * 0x28;
                local_7d4 = local_7d4 + 1;
              }
            }
          }
          value7 = value7 + 1;
          value5 = value5 + 0xc;
          local_7dc = local_7dc + 1;
        } while (local_7dc < *(int *)((intptr_t)self + 0x1c));
      }
      local_7d8 = local_7d8 + 1;
    } while (local_7d8 < *(int *)((intptr_t)self + 0x20));
    if (0 < value6) {
      uvalue2 = Random_RangeFast(0,value6 - 1);
      return local_7d0[uvalue2];
    }
  }
  return 0;
}
