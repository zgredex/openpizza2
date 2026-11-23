// Map_PickRandomLinkedCellInSteps: ported from Pizza Connection 2 at 0x507b90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x507b90
#include "pc2_port.h"


int Map_PickRandomLinkedCellInSteps(int arg1,int arg2)

{
  void *self;
  int value1;
  int value2;
  uint32_t uvalue3;
  int value4;
  int value5;
  short *psVar6;
  int *ptr7;
  uint32_t local_28 [5];
  int local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a2d8;
  local_c = ExceptionList;
  value5 = 0;
  ExceptionList = &local_c;
  List_Construct(local_28,0);
  local_4 = 0;
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  self = *(void **)(value1 + 0xfa8);
  value1 = arg1;
  if (0 < arg2) {
    do {
      value4 = arg1;
      List_Node_Reset((intptr_t)local_28);
      psVar6 = (short *)(value4 + 0x14);
      arg1 = 8;
      do {
        if (*psVar6 != -1) {
          value2 = Array_GetRecord28(self,1,(intptr_t)*psVar6);
          if (value2 != value1) {
            List_Add(local_28,value2);
          }
        }
        psVar6 = psVar6 + 1;
        arg1 = arg1 + -1;
      } while (arg1 != 0);
      arg1 = value4;
      if (local_14 < 1) break;
      ptr7 = (int *)0x0;
      uvalue3 = Random_RangeFast(0,local_14 - 1);
      arg1 = IDMap_Lookup(local_28,uvalue3,ptr7);
      value5 = value5 + 1;
      value1 = value4;
    } while (value5 < arg2);
  }
  local_4 = 0xffffffff;
  List_Node_Destroy(local_28);
  ExceptionList = local_c;
  return arg1;
}
