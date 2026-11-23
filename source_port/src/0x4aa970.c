// StatisticsBalance_UpdateBranchProfitColumn: ported from Pizza Connection 2 at 0x4aa970.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4aa970
#include "pc2_port.h"

void __cdecl StatisticsBalance_UpdateBranchProfitColumn(void *arg1,int arg2)

{
  float fVar1;
  int value2;
  int value3;
  int value4;
  uint32_t uvalue5;
  float *local_2c;
  uint8_t local_28 [36];
  
  fVar1 = DAT_0057d574;
  value3 = *(int *)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x15c);
  if (value3 < 9) {
    arg2 = 0;
  }
  else {
    value3 = 8;
  }
  String_Format(local_28,(uint8_t *)s__0_2f___005688b0,SUB84((double)DAT_0057d574,0));
  if (0.0 <= fVar1) {
    uvalue5 = 0;
  }
  else {
    uvalue5 = 0xff;
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x3fb,uvalue5);
  Window_GadgetNotify_Text_SetText(arg1,0x3fb,local_28);
  value4 = 0;
  if (0 < value3) {
    local_2c = (float *)(&DAT_0057d578 + arg2);
    do {
      fVar1 = *local_2c;
      String_Format(local_28,(uint8_t *)s__0_2f___005688b0,SUB84((double)fVar1,0));
      if (0.0 <= fVar1) {
        value2 = (&DAT_0056939c)[value4];
        uvalue5 = 0;
      }
      else {
        value2 = (&DAT_0056939c)[value4];
        uvalue5 = 0xff;
      }
      Window_GadgetNotify_Text_SetTextColor(arg1,value2,uvalue5);
      value2 = Array_GetField20ByKey(arg1,(&DAT_0056935c)[value4]);
      if (value2 != 0) {
        Window_GadgetNotify_Text_SetText(arg1,(&DAT_0056939c)[value4],local_28);
      }
      value4 = value4 + 1;
      local_2c = local_2c + 1;
    } while (value4 < value3);
  }
  return;
}
