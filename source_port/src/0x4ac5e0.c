// StatisticsBranchBalance_UpdateBranchProfits: ported from Pizza Connection 2 at 0x4ac5e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ac5e0
#include "pc2_port.h"

void __cdecl StatisticsBranchBalance_UpdateBranchProfits(void *arg1,int arg2)

{
  float fVar1;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int *ptr5;
  uint32_t *uptr6;
  int value7;
  double fVar8;
  double fVar9;
  double fVar10;
  double fVar11;
  int value12;
  uint32_t uvalue13;
  float *local_3c;
  float *local_38;
  uint8_t local_28 [36];
  
  value12 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value7 = *(int *)(value12 + 0x15c);
  uvalue4 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4);
  uvalue3 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  uptr6 = &DAT_0057d5d8;
  for (value2 = 0x15; value2 != 0; value2 = value2 + -1) {
    *uptr6 = 0;
    uptr6 = uptr6 + 1;
  }
  fVar8 = Stats_GetFilteredFloatDelta(value12,uvalue4,uvalue3);
  local_3c = (float *)0x0;
  DAT_0057d5d8 = (float)fVar8;
  if (0 < value7) {
    local_38 = (float *)&DAT_0057d5dc;
    do {
      value2 = IDMap_Lookup((void *)(value12 + 0x148),(intptr_t)local_3c,(int *)0x0);
      fVar8 = Stats_SumFilteredFloats(value2,-1,uvalue4,uvalue3);
      fVar9 = Stats_SumFilteredFloats2(value2,-1,uvalue4,uvalue3);
      fVar10 = Stats_SumFilteredFloats(value2,-1,uvalue4,uvalue3);
      fVar11 = Stats_SumFilteredFloats2(value2,-1,uvalue4,uvalue3);
      local_3c = (float *)((intptr_t)local_3c + 1);
      DAT_0057d5d8 = (float)((double)DAT_0057d5d8 + ((double)(float)fVar10 - fVar11));
      *local_38 = (float)fVar8 - (float)fVar9;
      local_38 = local_38 + 1;
    } while ((intptr_t)local_3c < value7);
  }
  fVar1 = DAT_0057d5d8;
  if (value7 < 6) {
    arg2 = 0;
  }
  else {
    value7 = 5;
  }
  String_Format(local_28,(uint8_t *)s__0_2f___005688b0,SUB84((double)DAT_0057d5d8,0));
  if (0.0 <= fVar1) {
    uvalue13 = 0;
  }
  else {
    uvalue13 = 0xff;
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x3fb,uvalue13);
  Window_GadgetNotify_Text_SetText(arg1,0x3fb,local_28);
  if (0 < value7) {
    ptr5 = &DAT_00569598;
    local_3c = (float *)(&DAT_0057d5dc + arg2);
    do {
      fVar1 = *local_3c;
      String_Format(local_28,(uint8_t *)s__0_2f___005688b0,SUB84((double)fVar1,0));
      if (0.0 <= fVar1) {
        value12 = *ptr5;
        uvalue13 = 0;
      }
      else {
        value12 = *ptr5;
        uvalue13 = 0xff;
      }
      Window_GadgetNotify_Text_SetTextColor(arg1,value12,uvalue13);
      Window_GadgetNotify_Text_SetText(arg1,*ptr5,local_28);
      ptr5 = ptr5 + 1;
      local_3c = local_3c + 1;
      value7 = value7 + -1;
    } while (value7 != 0);
  }
  return;
}
