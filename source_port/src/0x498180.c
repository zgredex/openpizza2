// BranchList_UpdateRows: ported from Pizza Connection 2 at 0x498180.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x498180
#include "pc2_port.h"

void __cdecl BranchList_UpdateRows(void *arg1,int arg2)

{
  int value1;
  int value2;
  int value3;
  double fVar4;
  int local_38;
  int *local_34;
  int local_30;
  uint8_t local_28 [36];
  
  value1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_30 = *(int *)(value1 + 0x124);
  if (local_30 < 9) {
    arg2 = 0;
  }
  else {
    local_30 = 8;
  }
  if (0 < local_30) {
    local_38 = arg2 * 4;
    local_34 = &DAT_00568890;
    value3 = 0x461;
    while( true ) {
      Window_GadgetNotify_Button_SetState
                (arg1,value3,(uint32_t)(*(int *)(local_38 + DAT_0057ca08) == DAT_0057c9fc));
      value2 = IDMap_Lookup((void *)(value1 + 0x110),*(int *)(local_38 + DAT_0057ca08),(int *)0x0);
      Window_GadgetNotify_Text_SetText(arg1,*local_34,value2 + 4);
      fVar4 = Get_Float44(value2);
      String_Format(local_28,(uint8_t *)s__0_2f___005688b0,SUB84((double)fVar4,0));
      Window_GadgetNotify_Text_SetText(arg1,value3 + 0xa4,local_28);
      local_38 = local_38 + 4;
      local_34 = local_34 + 1;
      if (local_30 <= value3 + -0x460) break;
      value3 = value3 + 1;
    }
  }
  return;
}
