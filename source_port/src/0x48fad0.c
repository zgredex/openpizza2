// FinanceScreen_UpdateStatement: ported from Pizza Connection 2 at 0x48fad0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48fad0
#include "pc2_port.h"

void __cdecl FinanceScreen_UpdateStatement(void *arg1)

{
  float fVar1;
  float fVar2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  double fVar5;
  double fVar6;
  uint32_t uvalue7;
  float local_38;
  int local_34;
  uint8_t local_28 [36];
  
  DAT_0057c69c = *(int *)(DAT_0057c670 + 0x9c);
  uvalue4 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  uvalue3 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4);
  fVar5 = Stats_SumFilteredFloats2(DAT_0057c69c,-1,uvalue3,uvalue4);
  fVar1 = (float)fVar5;
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(arg1,0x471,local_28);
  fVar5 = Stats_SumFilteredFloats2(DAT_0057c69c,0xc,uvalue3,uvalue4);
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(arg1,0x47e,local_28);
  fVar5 = Stats_SumFilteredFloats2(DAT_0057c69c,0xe,uvalue3,uvalue4);
  fVar6 = Stats_SumFilteredFloats2(DAT_0057c69c,0,uvalue3,uvalue4);
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)(fVar6 + (double)(float)fVar5),0))
  ;
  Window_GadgetNotify_Text_SetText(arg1,0x473,local_28);
  fVar5 = Stats_SumFilteredFloats2(DAT_0057c69c,1,uvalue3,uvalue4);
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(arg1,0x472,local_28);
  fVar5 = Stats_SumFilteredFloats2(DAT_0057c69c,2,uvalue3,uvalue4);
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(arg1,0x47b,local_28);
  fVar5 = Stats_SumFilteredFloats2(DAT_0057c69c,4,uvalue3,uvalue4);
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(arg1,0x47a,local_28);
  fVar5 = Stats_GetGroupScore(DAT_0057c69c,1,uvalue4);
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(arg1,0x47f,local_28);
  fVar5 = Stats_GetGroupScore(DAT_0057c69c,3,uvalue4);
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(arg1,0x487,local_28);
  fVar5 = Stats_SumFilteredFloats2(DAT_0057c69c,0xb,uvalue3,uvalue4);
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(arg1,0x1f42,local_28);
  fVar5 = Stats_SumFilteredFloats2(DAT_0057c69c,5,uvalue3,uvalue4);
  fVar6 = Stats_SumFilteredFloats2(DAT_0057c69c,9,uvalue3,uvalue4);
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)(fVar6 + (double)(float)fVar5),0))
  ;
  Window_GadgetNotify_Text_SetText(arg1,0x483,local_28);
  fVar5 = Stats_SumFilteredFloats2(DAT_0057c69c,0x13,uvalue3,uvalue4);
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(arg1,0x482,local_28);
  UI_RemoveObjectByKey(arg1,0x485);
  UI_RemoveObjectByKey(arg1,0x486);
  fVar5 = Stats_SumFilteredFloats(DAT_0057c69c,-1,uvalue3,uvalue4);
  fVar2 = (float)fVar5;
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(arg1,0x474,local_28);
  local_38 = 0.0;
  local_34 = 0;
  do {
    fVar5 = Stats_SumFilteredFloats(DAT_0057c69c,local_34,uvalue3,uvalue4);
    local_34 = local_34 + 1;
    local_38 = (float)(fVar5 + (double)local_38);
  } while (local_34 < 8);
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)local_38,0));
  Window_GadgetNotify_Text_SetText(arg1,0x475,local_28);
  fVar5 = Stats_SumFilteredFloats(DAT_0057c69c,0x16,uvalue3,uvalue4);
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(arg1,0x476,local_28);
  fVar5 = Stats_SumFilteredFloats(DAT_0057c69c,0x17,uvalue3,uvalue4);
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(arg1,0x489,local_28);
  fVar5 = Stats_SumFilteredFloats(DAT_0057c69c,0x15,uvalue3,uvalue4);
  String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)fVar5,0));
  Window_GadgetNotify_Text_SetText(arg1,0x477,local_28);
  if (fVar2 < fVar1) {
    Window_GadgetNotify_Text_SetTextColor(arg1,0x43c,0xff);
    Window_GadgetNotify_Text_SetText(arg1,0x43c,DAT_00582554);
    String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)(fVar1 - fVar2),0));
    uvalue7 = 0xff;
  }
  else {
    Window_GadgetNotify_Text_SetTextColor(arg1,0x43c,0xa000);
    Window_GadgetNotify_Text_SetText(arg1,0x43c,DAT_00582d8c);
    String_Format(local_28,(uint8_t *)s___2f___005683d4,SUB84((double)(fVar2 - fVar1),0));
    uvalue7 = 0xa000;
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x466,uvalue7);
  Window_GadgetNotify_Text_SetText(arg1,0x466,local_28);
  return;
}
