// StatisticsBranchBalance_InitBranchTabs: ported from Pizza Connection 2 at 0x4ac460.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ac460
#include "pc2_port.h"

void __cdecl StatisticsBranchBalance_InitBranchTabs(void *arg1,int arg2)

{
  int value1;
  int value2;
  int value3;
  float *local_34;
  int local_30;
  uint8_t local_28 [36];
  
                    /* Fills branch tabs with names, profits, and the selected branch. */
  value1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_30 = *(int *)(value1 + 0x15c);
  if (local_30 < 6) {
    arg2 = 0;
  }
  else {
    local_30 = 5;
  }
  Window_GadgetNotify_Button_SetState(arg1,0x3e9,(uint32_t)(DAT_0056951c == -1));
  Window_GadgetNotify_Text_SetText(arg1,0x3f8,DAT_005819f8);
  String_Format(local_28,(uint8_t *)s__0_2f___005688b0,SUB84((double)DAT_0057d5d8,0));
  Window_GadgetNotify_Text_SetText(arg1,0x3fb,local_28);
  UI_SetChildVisibleByID(arg1,0x4b2,(uint32_t)(DAT_0056951c != -1));
  value3 = 0;
  if (0 < local_30) {
    local_34 = (float *)(&DAT_0057d5dc + arg2);
    do {
      if (arg2 != DAT_0056951c) {
        value2 = (&DAT_00569570)[value3];
      }
      else {
        value2 = (&DAT_00569570)[value3];
      }
      Window_GadgetNotify_Button_SetState(arg1,value2,(uint32_t)(arg2 == DAT_0056951c));
      value2 = IDMap_Lookup((void *)(value1 + 0x148),arg2,(int *)0x0);
      Window_GadgetNotify_Text_SetText(arg1,(&DAT_00569584)[value3],value2 + 4);
      String_Format(local_28,(uint8_t *)s__0_2f___005688b0,SUB84((double)*local_34,0));
      Window_GadgetNotify_Text_SetText(arg1,(&DAT_00569598)[value3],local_28);
      value3 = value3 + 1;
      arg2 = arg2 + 1;
      local_34 = local_34 + 1;
    } while (value3 < local_30);
  }
  return;
}
