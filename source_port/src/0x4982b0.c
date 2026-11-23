// BranchList_UpdateSummary: ported from Pizza Connection 2 at 0x4982b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4982b0
#include "pc2_port.h"

void __cdecl BranchList_UpdateSummary(void *arg1)

{
  void *self;
  int value1;
  double fVar2;
  int64_t lvalue3;
  uint8_t local_80 [128];
  
  self = *(void **)(DAT_0057c670 + 0x98);
  if (self != (void *)0x0) {
    fVar2 = Game_GetPlayerWeightedStat((intptr_t)self);
    String_Format(local_80,(uint8_t *)s__0_2f__005688b8,SUB84((double)fVar2,0));
    Window_GadgetNotify_Text_SetText(arg1,0x4f9,local_80);
    Stats_GetMaxCategoryValue((intptr_t)self,-1);
    lvalue3 = __ftol();
    String_Format(local_80,&DAT_005683a4,(intptr_t)lvalue3);
    Window_GadgetNotify_Text_SetText(arg1,0x4fa,local_80);
    value1 = AI_CountPlanSteps(self,-1,0,-1);
    String_Format(local_80,&DAT_005686f4,value1);
    Window_GadgetNotify_Text_SetText(arg1,0x4fb,local_80);
  }
  return;
}
