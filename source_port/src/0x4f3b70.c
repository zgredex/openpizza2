// Map_ComputeSpecialTileBounds: ported from Pizza Connection 2 at 0x4f3b70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f3b70
#include "pc2_port.h"

void __fastcall Map_ComputeSpecialTileBounds(void *arg1)

{
  bool flag1;
  bool flag2;
  bool flag3;
  bool flag4;
  int value5;
  int value6;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  int value7;
  int value8;
  int value9;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  value9 = 0;
  flag1 = false;
  flag2 = false;
  flag3 = false;
  if (*(int *)((intptr_t)arg1 + 0xc) != 0x10) {
    NoOp_Stub();
  }
  if (0 < *(int *)((intptr_t)arg1 + 0x20)) {
    do {
      value8 = 0;
      if (0 < *(int *)((intptr_t)arg1 + 0x1c)) {
        do {
          value5 = Grid_GetCell(arg1,value8,value9);
          if (*(int *)(value5 + 8) != 0) {
            if ((!flag1) &&
               (value6 = IsMenuId351Or355(*(int *)(*(int *)(value5 + 8) + 4)), value6 != 0)) {
              local_10 = value8 + -5;
              local_c = value9 + -5;
              flag1 = true;
            }
            if (!flag2) {
              value5 = IsMenuId34EOr350(*(int *)(*(int *)(value5 + 8) + 4));
              if (value5 != 0) {
                flag2 = true;
                value5 = value8;
                do {
                  value7 = value5;
                  value5 = Grid_GetCell(arg1,value7,value9);
                  value6 = IsMenuId34EOr350(*(int *)(*(int *)(value5 + 8) + 4));
                  value5 = value7 + 1;
                } while (value6 != 0);
                local_8 = value7 + 5;
              }
              value5 = Grid_GetCell(arg1,value8,value9);
            }
            if (((!flag3) &&
                (flag4 = IsMenuId352(*(int *)(*(int *)(value5 + 8) + 4)),
                CONCAT31(extraout_var,flag4) != 0)) &&
               (flag4 = IsMenuId352(*(int *)(*(int *)(*(int *)((intptr_t)arg1 + 0x4c) + 8 +
                                                     (**(int **)(value5 + 8) +
                                                     *(int *)((intptr_t)arg1 + 0x1c)) * 0xc) + 4)),
               CONCAT31(extraout_var_00,flag4) == 0)) {
              local_4 = value9 + 5;
              flag3 = true;
            }
          }
          value8 = value8 + 1;
        } while (value8 < *(int *)((intptr_t)arg1 + 0x1c));
      }
      value9 = value9 + 1;
    } while (value9 < *(int *)((intptr_t)arg1 + 0x20));
  }
  *(int *)((intptr_t)arg1 + 0x100) = local_10;
  *(int *)((intptr_t)arg1 + 0x104) = local_c;
  *(int *)((intptr_t)arg1 + 0x108) = local_8;
  *(int *)((intptr_t)arg1 + 0x10c) = local_4;
  return;
}
