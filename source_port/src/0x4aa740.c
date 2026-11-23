// StatisticsBalance_UpdateBranchList: ported from Pizza Connection 2 at 0x4aa740.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4aa740
#include "pc2_port.h"

void __cdecl StatisticsBalance_UpdateBranchList(void *arg1,int arg2)

{
  int value1;
  int value2;
  int value3;
  int local_3c;
  int local_38;
  float *local_34;
  int local_30;
  uint8_t local_28 [36];
  
                    /* Fills the balance screen's branch rows and selected period data. */
  value1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_30 = *(int *)(value1 + 0x15c);
  if (local_30 < 9) {
    arg2 = 0;
  }
  else {
    local_30 = 8;
  }
  if (DAT_0057d5c8 == 0) {
    local_3c = (DAT_00569354 - DAT_0057dfbc) * 4 + 4;
  }
  else {
    local_3c = DAT_0057d5c8 + -1 + (DAT_00569354 - DAT_0057dfbc) * 4;
  }
  if ((-1 < DAT_00569358) &&
     (value2 = IDMap_Lookup((void *)(value1 + 0x148),DAT_00569358,(int *)0x0),
     local_3c < *(int *)(value2 + 0x40))) {
    DAT_00569358 = -1;
  }
  Window_GadgetNotify_Button_SetState(arg1,0x3e9,(uint32_t)(DAT_00569358 == -1));
  Window_GadgetNotify_Text_SetText(arg1,0x3f8,DAT_005819f8);
  String_Format(local_28,(uint8_t *)s__0_2f___005688b0,SUB84((double)DAT_0057d574,0));
  Window_GadgetNotify_Text_SetText(arg1,0x3fb,local_28);
  UI_SetChildVisibleByID(arg1,0x4b2,(uint32_t)(DAT_00569358 != -1));
  value2 = 0;
  if (0 < local_30) {
    local_38 = arg2;
    local_34 = (float *)(&DAT_0057d578 + arg2);
    do {
      if (local_38 != DAT_00569358) {
        value3 = (&DAT_0056935c)[value2];
      }
      else {
        value3 = (&DAT_0056935c)[value2];
      }
      Window_GadgetNotify_Button_SetState(arg1,value3,(uint32_t)(local_38 == DAT_00569358));
      value3 = IDMap_Lookup((void *)(value1 + 0x148),local_38,(int *)0x0);
      Window_GadgetNotify_Text_SetText(arg1,(&DAT_0056937c)[value2],value3 + 4);
      String_Format(local_28,(uint8_t *)s__0_2f___005688b0,SUB84((double)*local_34,0));
      Window_GadgetNotify_Text_SetText(arg1,(&DAT_0056939c)[value2],local_28);
      if (local_3c < *(int *)(value3 + 0x40)) {
        UI_RemoveObjectByKey(arg1,(&DAT_0056935c)[value2]);
        Window_GadgetNotify_Text_SetText(arg1,(&DAT_0056939c)[value2],DAT_00582e4c);
      }
      else {
        UI_ShowChildByID(arg1,(&DAT_0056935c)[value2]);
      }
      value2 = value2 + 1;
      local_38 = local_38 + 1;
      local_34 = local_34 + 1;
    } while (value2 < local_30);
  }
  return;
}
