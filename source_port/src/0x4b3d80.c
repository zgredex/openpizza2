// CompanyOverview_UpdateCompanyRows: ported from Pizza Connection 2 at 0x4b3d80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b3d80
#include "pc2_port.h"

void __cdecl CompanyOverview_UpdateCompanyRows(void *arg1,int arg2)

{
  void *self;
  void *this_00;
  int value1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  int value4;
  double fVar5;
  uint8_t *uptr6;
  int *local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint8_t local_28 [36];
  
  local_34 = 0;
  uvalue3 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  local_38 = *(int *)((intptr_t)DAT_0057d6a4 + 0x14);
  self = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  if (DAT_0056a7d4 != -1) {
    local_34 = IDMap_Lookup((void *)((intptr_t)self + 0x148),DAT_0056a7d4,(int *)0x0);
  }
  if (local_38 < 9) {
    arg2 = 0;
  }
  else {
    local_38 = 8;
  }
  if (0 < local_38) {
    local_3c = arg2 << 2;
    local_40 = &DAT_0056a740;
    value4 = 0x40d;
    do {
      value1 = *(int *)(local_3c + DAT_0057d6a0);
      Window_GadgetNotify_Button_SetState
                (arg1,value4 + 0x1b34,(uint32_t)(*(int *)(&DAT_0056a760 + value1 * 4) != 0));
      this_00 = (void *)IDMap_Lookup(DAT_0057d6a4,value1,(int *)0x0);
      Window_GadgetNotify_Text_SetText(arg1,value4,(intptr_t)this_00 + 4);
      if (((DAT_0056a7d4 == -1) || (local_34 == 0)) || (*(void **)(local_34 + 0x14dc) != this_00)) {
        value1 = Game_GetActiveCompanyOrdinal(self,(intptr_t)this_00);
      }
      else {
        value1 = 0x14;
      }
      uvalue2 = Game_GetGlobalTableValue(value1);
      Window_GadgetNotify_Text_SetTextColor(arg1,value4,uvalue2);
      if (uvalue3 == 0) {
        value1 = *local_40;
        uptr6 = DAT_00582e4c;
      }
      else {
        if (DAT_0057d69c == 0) {
          value1 = AI_CountPlanSteps(this_00,uvalue3 - 1,0x56a734,DAT_0056a7d4);
          String_Format(local_28,&DAT_005686f4,value1);
        }
        else if (DAT_0057d69c == 1) {
          fVar5 = Stats_SumMaskedMapFloats((intptr_t)this_00,uvalue3 - 1,0x56a734,DAT_0056a7d4);
          String_Format(local_28,(uint8_t *)s__0_2f__005688b8,SUB84((double)fVar5,0));
        }
        else if (DAT_0057d69c == 2) {
          fVar5 = Stats_AverageActiveCategories(this_00,0x56a734);
          String_Format(local_28,(uint8_t *)s__0_2f_005685f4,SUB84((double)fVar5,0));
        }
        Window_GadgetNotify_Text_SetTextColor(arg1,*local_40,0);
        value1 = *local_40;
        uptr6 = local_28;
      }
      Window_GadgetNotify_Text_SetText(arg1,value1,uptr6);
      local_3c = local_3c + 4;
      local_40 = local_40 + 1;
      value1 = value4 + -0x40c;
      value4 = value4 + 1;
    } while (value1 < local_38);
  }
  return;
}
