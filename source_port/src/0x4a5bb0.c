// FinancePage_UpdateBalanceSheet: ported from Pizza Connection 2 at 0x4a5bb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a5bb0
#include "pc2_port.h"

void __cdecl FinancePage_UpdateBalanceSheet(void *arg1)

{
  float fVar1;
  int value2;
  int value3;
  int value4;
  int value5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  float *fptr8;
  double fVar9;
  double fVar10;
  double fVar11;
  double fVar12;
  double fVar13;
  double fVar14;
  double fVar15;
  double fVar16;
  double fVar17;
  double fVar18;
  double fVar19;
  double fVar20;
  double fVar21;
  double fVar22;
  double fVar23;
  double fVar24;
  double fVar25;
  double fVar26;
  double fVar27;
  double fVar28;
  double fVar29;
  double fVar30;
  double fVar31;
  double fVar32;
  double fVar33;
  double fVar34;
  uint32_t uvalue35;
  float local_78;
  int local_74;
  int local_70;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  uint8_t local_50 [32];
  float local_30 [4];
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  uvalue6 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4);
  uvalue7 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  value2 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value4 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value3 = *(int *)(value2 + 0x15c);
  fptr8 = local_30;
  for (value5 = 0xc; value5 != 0; value5 = value5 + -1) {
    *fptr8 = 0.0;
    fptr8 = fptr8 + 1;
  }
  local_64 = 0.0;
  local_60 = 0.0;
  local_5c = 0.0;
  local_58 = 0.0;
  local_54 = 0.0;
  local_70 = 0;
  if (0 < value3) {
    do {
      value5 = IDMap_Lookup((void *)(value2 + 0x148),local_70,(int *)0x0);
      if (*(int *)(value5 + 0x34) == *(int *)(value4 + 0xc1c)) {
        fVar9 = Stats_SumFilteredFloats2(value5,-1,uvalue6,uvalue7);
        local_30[0] = (float)(fVar9 + (double)local_30[0]);
        fVar9 = Stats_SumFilteredFloats2(value5,0xc,uvalue6,uvalue7);
        local_18 = (float)(fVar9 + (double)local_18);
        fVar9 = Stats_SumFilteredFloats2(value5,0xe,uvalue6,uvalue7);
        fVar10 = Stats_SumFilteredFloats2(value5,0,uvalue6,uvalue7);
        local_30[1] = (float)(fVar10 + (double)(float)fVar9 + (double)local_30[1]);
        fVar9 = Stats_SumFilteredFloats2(value5,1,uvalue6,uvalue7);
        local_30[2] = (float)(fVar9 + (double)local_30[2]);
        fVar9 = Stats_SumFilteredFloats2(value5,2,uvalue6,uvalue7);
        local_30[3] = (float)(fVar9 + (double)local_30[3]);
        fVar9 = Stats_SumFilteredFloats2(value5,4,uvalue6,uvalue7);
        local_20 = (float)(fVar9 + (double)local_20);
        fVar9 = Stats_GetGroupScore(value5,1,uvalue7);
        local_1c = (float)(fVar9 + (double)local_1c);
        fVar9 = Stats_GetGroupScore(value5,3,uvalue7);
        local_c = (float)(fVar9 + (double)local_c);
        fVar9 = Stats_SumFilteredFloats2(value5,5,uvalue6,uvalue7);
        fVar10 = Stats_SumFilteredFloats2(value5,0x12,uvalue6,uvalue7);
        fVar11 = Stats_SumFilteredFloats2(value5,9,uvalue6,uvalue7);
        local_14 = (float)(fVar11 + (double)(float)(fVar10 + (double)(float)fVar9) +
                          (double)local_14);
        fVar9 = Stats_SumFilteredFloats2(value5,0x13,uvalue6,uvalue7);
        local_10 = (float)(fVar9 + (double)local_10);
        fVar9 = Stats_SumFilteredFloats2(value5,0xb,uvalue6,uvalue7);
        local_4 = (float)(fVar9 + (double)local_4);
        fVar9 = Stats_SumFilteredFloats(value5,-1,uvalue6,uvalue7);
        local_78 = 0.0;
        local_74 = 0;
        local_64 = (float)(fVar9 + (double)local_64);
        do {
          fVar9 = Stats_SumFilteredFloats(value5,local_74,uvalue6,uvalue7);
          local_74 = local_74 + 1;
          local_78 = (float)(fVar9 + (double)local_78);
        } while (local_74 < 8);
        local_60 = local_60 + local_78;
        fVar9 = Stats_SumFilteredFloats(value5,0x16,uvalue6,uvalue7);
        local_5c = (float)(fVar9 + (double)local_5c);
        fVar9 = Stats_SumFilteredFloats(value5,0x17,uvalue6,uvalue7);
        local_58 = (float)(fVar9 + (double)local_58);
        fVar9 = Stats_SumFilteredFloats(value5,0x15,uvalue6,uvalue7);
        local_54 = (float)(fVar9 + (double)local_54);
      }
      local_70 = local_70 + 1;
    } while (local_70 < value3);
  }
  fVar9 = Stats_SumFilteredFloats4(value2,0x14,uvalue6,uvalue7);
  fVar10 = Stats_SumFilteredFloats4(value2,0x14,uvalue6,uvalue7);
  local_8 = (float)fVar10;
  fVar10 = Stats_SumFilteredFloats4(value2,0x15,uvalue6,uvalue7);
  fVar11 = Stats_SumFilteredFloats4(value2,0x15,uvalue6,uvalue7);
  local_8 = (float)(fVar11 + (double)local_8);
  fVar11 = Stats_SumFilteredFloats4(value2,0xb,uvalue6,uvalue7);
  fVar12 = Stats_SumFilteredFloats4(value2,0xb,uvalue6,uvalue7);
  local_4 = (float)(fVar12 + (double)local_4);
  fVar12 = Stats_SumFilteredFloats4(value2,0xc,uvalue6,uvalue7);
  fVar13 = Stats_SumFilteredFloats4(value2,0xc,uvalue6,uvalue7);
  local_18 = (float)(fVar13 + (double)local_18);
  fVar13 = Stats_SumFilteredFloats4(value2,10,uvalue6,uvalue7);
  fVar14 = Stats_SumFilteredFloats4(value2,10,uvalue6,uvalue7);
  local_1c = (float)(fVar14 + (double)local_1c);
  fVar14 = Stats_SumFilteredFloats4(value2,6,uvalue6,uvalue7);
  fVar15 = Stats_SumFilteredFloats4(value2,6,uvalue6,uvalue7);
  local_1c = (float)(fVar15 + (double)local_1c);
  fVar15 = Stats_SumFilteredFloats4(value2,7,uvalue6,uvalue7);
  fVar16 = Stats_SumFilteredFloats4(value2,7,uvalue6,uvalue7);
  local_1c = (float)(fVar16 + (double)local_1c);
  fVar16 = Stats_SumFilteredFloats4(value2,8,uvalue6,uvalue7);
  fVar17 = Stats_SumFilteredFloats4(value2,8,uvalue6,uvalue7);
  local_1c = (float)(fVar17 + (double)local_1c);
  fVar17 = Stats_SumFilteredFloats4(value2,0xd,uvalue6,uvalue7);
  fVar18 = Stats_SumFilteredFloats4(value2,0xd,uvalue6,uvalue7);
  local_1c = (float)(fVar18 + (double)local_1c);
  fVar18 = Stats_SumFilteredFloats4(value2,3,uvalue6,uvalue7);
  fVar19 = Stats_SumFilteredFloats4(value2,3,uvalue6,uvalue7);
  local_30[2] = (float)(fVar19 + (double)local_30[2]);
  fVar19 = Stats_SumFilteredFloats4(value2,1,uvalue6,uvalue7);
  fVar20 = Stats_SumFilteredFloats4(value2,1,uvalue6,uvalue7);
  local_30[2] = (float)(fVar20 + (double)local_30[2]);
  fVar20 = Stats_SumFilteredFloats4(value2,2,uvalue6,uvalue7);
  fVar21 = Stats_SumFilteredFloats4(value2,2,uvalue6,uvalue7);
  local_30[3] = (float)(fVar21 + (double)local_30[3]);
  fVar21 = Stats_SumFilteredFloats4(value2,0,uvalue6,uvalue7);
  fVar22 = Stats_SumFilteredFloats4(value2,0,uvalue6,uvalue7);
  local_30[1] = (float)(fVar22 + (double)local_30[1]);
  fVar22 = Stats_SumFilteredFloats4(value2,0xe,uvalue6,uvalue7);
  fVar23 = Stats_SumFilteredFloats4(value2,0xe,uvalue6,uvalue7);
  local_30[1] = (float)(fVar23 + (double)local_30[1]);
  fVar23 = Stats_SumFilteredFloats4(value2,4,uvalue6,uvalue7);
  fVar24 = Stats_SumFilteredFloats4(value2,4,uvalue6,uvalue7);
  local_20 = (float)(fVar24 + (double)local_20);
  fVar24 = Stats_SumFilteredFloats4(value2,0x13,uvalue6,uvalue7);
  fVar25 = Stats_SumFilteredFloats4(value2,0x13,uvalue6,uvalue7);
  local_10 = (float)(fVar25 + (double)local_10);
  fVar25 = Stats_SumFilteredFloats4(value2,0xf,uvalue6,uvalue7);
  fVar26 = Stats_SumFilteredFloats4(value2,0xf,uvalue6,uvalue7);
  local_c = (float)(fVar26 + (double)local_c);
  fVar26 = Stats_SumFilteredFloats4(value2,0x11,uvalue6,uvalue7);
  fVar27 = Stats_SumFilteredFloats4(value2,0x11,uvalue6,uvalue7);
  local_c = (float)(fVar27 + (double)local_c);
  fVar27 = Stats_SumFilteredFloats4(value2,0x10,uvalue6,uvalue7);
  fVar28 = Stats_SumFilteredFloats4(value2,0x10,uvalue6,uvalue7);
  local_c = (float)(fVar28 + (double)local_c);
  fVar28 = Stats_SumFilteredFloats4(value2,9,uvalue6,uvalue7);
  fVar29 = Stats_SumFilteredFloats4(value2,9,uvalue6,uvalue7);
  local_14 = (float)(fVar29 + (double)local_14);
  fVar29 = Stats_SumFilteredFloats4(value2,5,uvalue6,uvalue7);
  fVar30 = Stats_SumFilteredFloats4(value2,9,uvalue6,uvalue7);
  local_14 = (float)(fVar30 + (double)local_14);
  fVar30 = Stats_SumFilteredFloats4(value2,0x18,uvalue6,uvalue7);
  fVar31 = Stats_SumFilteredFloats4(value2,0x18,uvalue6,uvalue7);
  local_14 = (float)(fVar31 + (double)local_14);
  fVar31 = Stats_SumFilteredFloats4(value2,0x12,uvalue6,uvalue7);
  fVar32 = Stats_SumFilteredFloats4(value2,0x12,uvalue6,uvalue7);
  local_14 = (float)(fVar32 + (double)local_14);
  fVar32 = Stats_SumFilteredFloats4(value2,0x17,uvalue6,uvalue7);
  fVar33 = Stats_SumFilteredFloats4(value2,0x17,uvalue6,uvalue7);
  local_14 = (float)(fVar33 + (double)local_14);
  fVar33 = Stats_SumFilteredFloats4(value2,0x16,uvalue6,uvalue7);
  fVar34 = Stats_SumFilteredFloats4(value2,0x16,uvalue6,uvalue7);
  local_14 = (float)(fVar34 + (double)local_14);
  local_30[0] = local_30[0] +
                (float)(fVar33 + (double)(float)(fVar32 + (double)(float)(fVar31 + (double)(float
                                                  )(fVar30 + (double)(float)(fVar29 + (double)(
                                                  float)(fVar28 + (double)(float)(fVar27 + (double
                                                  )(float)(fVar26 + (double)(float)(fVar25 + (
                                                  double)(float)(fVar24 + (double)(float)(fVar23 +
                                                                                           (double)
                                                  (float)(fVar22 + (double)(float)(fVar21 + (
                                                  double)(float)(fVar20 + (double)(float)(fVar19 +
                                                                                           (double)
                                                  (float)(fVar18 + (double)(float)(fVar17 + (
                                                  double)(float)(fVar16 + (double)(float)(fVar15 +
                                                                                           (double)
                                                  (float)(fVar14 + (double)(float)(fVar13 + (
                                                  double)(float)(fVar12 + (double)(float)(fVar11 +
                                                                                           (double)
                                                  (float)(fVar10 + (double)(float)fVar9))))))))))))
                                                  ))))))))))));
  fVar9 = Stats_SumFilteredFloats3(value2,0x15,uvalue6,uvalue7);
  fVar10 = Stats_SumFilteredFloats3(value2,0x18,uvalue6,uvalue7);
  fVar11 = Stats_SumFilteredFloats3(value2,0x19,uvalue6,uvalue7);
  fVar12 = Stats_SumFilteredFloats3(value2,0x14,uvalue6,uvalue7);
  fVar12 = fVar12 + (double)(float)(fVar11 + (double)(float)(fVar10 + (double)(float)fVar9));
  fVar1 = (float)((double)local_64 + fVar12);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_30[0],0));
  Window_GadgetNotify_Text_SetText(arg1,0x457,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_30[1],0));
  Window_GadgetNotify_Text_SetText(arg1,0x459,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_30[2],0));
  Window_GadgetNotify_Text_SetText(arg1,0x458,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_30[3],0));
  Window_GadgetNotify_Text_SetText(arg1,0x46a,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_20,0));
  Window_GadgetNotify_Text_SetText(arg1,0x469,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_1c,0));
  Window_GadgetNotify_Text_SetText(arg1,0x46e,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_18,0));
  Window_GadgetNotify_Text_SetText(arg1,0x46d,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_14,0));
  Window_GadgetNotify_Text_SetText(arg1,0x472,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_10,0));
  Window_GadgetNotify_Text_SetText(arg1,0x471,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_c,0));
  Window_GadgetNotify_Text_SetText(arg1,0x476,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_8,0));
  Window_GadgetNotify_Text_SetText(arg1,0x475,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_4,0));
  Window_GadgetNotify_Text_SetText(arg1,0x1f42,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)fVar1,0));
  Window_GadgetNotify_Text_SetText(arg1,0x462,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_60,0));
  Window_GadgetNotify_Text_SetText(arg1,0x463,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_5c,0));
  Window_GadgetNotify_Text_SetText(arg1,0x464,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)local_58,0));
  Window_GadgetNotify_Text_SetText(arg1,0x478,local_50);
  String_Format(local_50,(uint8_t *)s___2f___005683d4,
                SUB84((double)(float)((double)local_54 + fVar12),0));
  Window_GadgetNotify_Text_SetText(arg1,0x465,local_50);
  if (fVar1 < local_30[0]) {
    Window_GadgetNotify_Text_SetTextColor(arg1,0x43c,0xff);
    Window_GadgetNotify_Text_SetText(arg1,0x43c,DAT_00582554);
    String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)(local_30[0] - fVar1),0));
    uvalue35 = 0xff;
  }
  else {
    Window_GadgetNotify_Text_SetTextColor(arg1,0x43c,0xa000);
    Window_GadgetNotify_Text_SetText(arg1,0x43c,DAT_00582d8c);
    String_Format(local_50,(uint8_t *)s___2f___005683d4,SUB84((double)(fVar1 - local_30[0]),0));
    uvalue35 = 0xa000;
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x466,uvalue35);
  Window_GadgetNotify_Text_SetText(arg1,0x466,local_50);
  return;
}
