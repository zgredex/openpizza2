// AI_ComputePath: ported from Pizza Connection 2 at 0x4f50d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f50d0
#include "pc2_port.h"

uint32_t AI_ComputePath(int arg1,int arg2,int arg3,int arg4,uint8_t arg5)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  int extraout_ECX;
  int *ptr4;
  int *ptr5;
  int value6;
  bool flag7;
  uint8_t unaff_retaddr;
  int value8;
  int in_stack_00003e98;
  int in_stack_00003e9c;
  int in_stack_00003ea0;
  
  __chkstk(unaff_retaddr);
  value2 = 0;
  arg1 = 0;
  value8 = 0;
  if (in_stack_00003e98 == 0) {
    arg2 = 0;
  }
  arg4 = 0;
  if (0 < *(int *)(extraout_ECX + 0x20)) {
    do {
      arg3 = 0;
      if (0 < *(int *)(extraout_ECX + 0x1c)) {
        value6 = arg1 * 0xc;
        ptr4 = (int *)(&arg5 + value2 * 4);
        value2 = value8;
        do {
          value8 = *(int *)(*(int *)(extraout_ECX + 0x4c) + 8 + value6);
          ptr5 = ptr4;
          if (value8 != 0) {
            value1 = *(int *)(value8 + 4);
            flag7 = value1 == 0x34e;
            if ((in_stack_00003e9c != 0) && (value1 == 0x352)) {
              flag7 = true;
            }
            if (((in_stack_00003ea0 != 0) && (value1 == 0x355)) || (flag7)) {
              if ((in_stack_00003e98 != 0) &&
                 ((*(int *)(value8 + 0x10) < 0x19 || (arg2 = 1, 0x20 < *(int *)(value8 + 0x10)))))
              {
                arg2 = 0;
              }
              if (((*(short *)(value8 + 0x24) != -1) && (*(int *)(value8 + 0x28) != 0)) &&
                 (arg2 == 0)) {
                ptr5 = ptr4 + 1;
                *ptr4 = *(int *)(extraout_ECX + 0x9c) + *(short *)(value8 + 0x24) * 0x28;
                value2 = value2 + 1;
                if (3999 < value2) {
                  NoOp_Stub();
                }
              }
            }
          }
          arg1 = arg1 + 1;
          value6 = value6 + 0xc;
          arg3 = arg3 + 1;
          ptr4 = ptr5;
        } while (arg3 < *(int *)(extraout_ECX + 0x1c));
        value8 = value2;
      }
      arg4 = arg4 + 1;
    } while (arg4 < *(int *)(extraout_ECX + 0x20));
    if (0 < value2) {
      uvalue3 = Random_RangeFast(0,value2 - 1);
      return *(uint32_t *)(&arg5 + uvalue3 * 4);
    }
  }
  return 0;
}
