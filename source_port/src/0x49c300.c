// RankingScreen_UpdateRows: ported from Pizza Connection 2 at 0x49c300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49c300
#include "pc2_port.h"

void __cdecl RankingScreen_UpdateRows(void *arg1,int arg2)

{
  void *self;
  int value1;
  int value2;
  bool flag3;
  double fVar4;
  int local_38;
  int local_34;
  int local_30;
  uint8_t local_28 [36];
  
  self = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_30 = Game_CountActiveCompanies((intptr_t)self);
  if (local_30 < 9) {
    arg2 = 0;
  }
  else {
    local_30 = 8;
  }
  value2 = 0;
  if (0 < local_30) {
    local_34 = arg2 * 4;
    local_38 = 0x51b;
    do {
      flag3 = *(int *)(local_34 + DAT_0057ca94) != DAT_0057ca90;
      if (flag3) {
        value1 = (&DAT_00568a14)[value2];
      }
      else {
        value1 = (&DAT_00568a14)[value2];
      }
      Window_GadgetNotify_Button_SetState(arg1,value1,(uint32_t)!flag3);
      value1 = Game_GetActiveCompanyById(self,*(int *)(local_34 + DAT_0057ca94));
      Window_GadgetNotify_Text_SetText(arg1,local_38,value1 + 4);
      if (DAT_005689f0 == '\0') {
        fVar4 = Game_ComputeCompanySharePercent(self,value1,-1);
      }
      else {
        fVar4 = Game_GetPlayerWeightedStat(value1);
      }
      String_Format(local_28,(uint8_t *)s__0_2f_005685f4,SUB84((double)fVar4,0));
      Window_GadgetNotify_Text_SetText(arg1,(&DAT_005689f4)[value2],local_28);
      value2 = value2 + 1;
      local_38 = local_38 + -1;
      local_34 = local_34 + 4;
    } while (value2 < local_30);
  }
  return;
}
