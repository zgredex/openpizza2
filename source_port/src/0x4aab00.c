// StatisticsBalance_UpdateReport: ported from Pizza Connection 2 at 0x4aab00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4aab00
#include "pc2_port.h"

void __cdecl StatisticsBalance_UpdateReport(void *arg1)

{
  char cVar1;
  char *self;
  uint32_t uvalue2;
  int value3;
  int value4;
  float *fptr5;
  int value6;
  int value7;
  int *ptr8;
  char *cptr9;
  double fVar10;
  double fVar11;
  double fVar12;
  double fVar13;
  float local_1f8;
  int local_1f4;
  float local_1ec;
  float *local_1e8;
  int local_1e0;
  float local_1dc;
  int local_1d8;
  float local_1d4 [20];
  float local_184 [6];
  char local_16c [256];
  float local_6c [26];
  
                    /* Recomputes the balance sheet for the selected period. */
  if (DAT_0057d5c8 == 0) {
    local_1f4 = -1;
  }
  else {
    local_1f4 = DAT_0057d5c8 + -1 + (DAT_00569354 - DAT_0057dfbc) * 4;
  }
  self = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  fptr5 = local_6c;
  for (value4 = 0x19; value4 != 0; value4 = value4 + -1) {
    *fptr5 = 0.0;
    fptr5 = fptr5 + 1;
  }
  fptr5 = local_1d4;
  for (value4 = 0x1a; value4 != 0; value4 = value4 + -1) {
    *fptr5 = 0.0;
    fptr5 = fptr5 + 1;
  }
  fVar10 = Stats_GetFilteredFloatDelta((intptr_t)self,DAT_00569354,local_1f4);
  DAT_0057d574 = (float)(intptr_t)(fVar10);
  value4 = *(int *)((intptr_t)self + 0x15c);
  value6 = 0;
  if (0 < value4) {
    local_1e8 = (float *)&DAT_0057d578;
    do {
      local_1d8 = IDMap_Lookup((void *)((intptr_t)self + 0x148),value6,(int *)0x0);
      fVar10 = Stats_SumFilteredFloats(local_1d8,-1,DAT_00569354,local_1f4);
      fVar11 = Stats_SumFilteredFloats2(local_1d8,-1,DAT_00569354,local_1f4);
      uvalue2 = Calendar_IsSelectedDate();
      if ((char)uvalue2 != '\0') {
        fVar12 = Stats_SumFilteredFloats
                           (local_1d8,-1,DAT_00569354,
                            (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10));
        fVar13 = Stats_SumFilteredFloats2
                           (local_1d8,-1,DAT_00569354,
                            (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10));
        DAT_0057d574 = (float)((double)DAT_0057d574 + ((double)(float)(intptr_t)(fVar12) - fVar13));
      }
      value6 = value6 + 1;
      *local_1e8 = (float)(intptr_t)(fVar10) - (float)(intptr_t)(fVar11);
      local_1e8 = local_1e8 + 1;
    } while (value6 < value4);
  }
  local_1f8 = 0.0;
  local_1ec = 0.0;
  if ((DAT_00569358 < 0) ||
     (local_1d8 = IDMap_Lookup((void *)((intptr_t)self + 0x148),DAT_00569358,(int *)0x0), local_1d8 != 0)
     ) {
    value4 = 0;
    do {
      UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_00569420 + value4));
      UI_ShowChildByID(arg1,*(int *)((intptr_t)&DAT_00569488 + value4));
      value4 = value4 + 4;
    } while (value4 < 0x54);
    if (DAT_00569358 == -1) {
      local_1e8 = (float *)0x0;
      local_1dc = 0.0;
      value6 = 0;
      value4 = *(int *)((intptr_t)self + 0x15c);
      do {
        fVar10 = Stats_SumFilteredFloats4((intptr_t)self,value6,DAT_00569354,local_1f4);
        local_6c[value6] = (float)(intptr_t)(fVar10);
        uvalue2 = Calendar_IsSelectedDate();
        if (((char)uvalue2 != '\0') && (value7 = 0, 0 < value4)) {
          do {
            value3 = IDMap_Lookup((void *)((intptr_t)self + 0x148),value7,(int *)0x0);
            fVar10 = Stats_SumFilteredFloats2
                               (value3,value6,DAT_00569354,
                                (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10));
            value7 = value7 + 1;
            local_6c[value6] = (float)(fVar10 + (double)local_6c[value6]);
          } while (value7 < value4);
        }
        local_1ec = local_1ec + local_6c[value6];
        String_Format(local_16c,(uint8_t *)s___2f___005683d4,SUB84((double)local_6c[value6],0));
        Window_GadgetNotify_Text_SetText(arg1,(&DAT_005693bc)[value6],local_16c);
        value6 = value6 + 1;
      } while (value6 < 0x19);
      ptr8 = &DAT_0056940c;
      do {
        UI_ShowChildByID(arg1,*ptr8);
        ptr8 = ptr8 + 1;
      } while ((intptr_t)ptr8 < 0x569420);
      UI_ShowChildByID(arg1,DAT_005693c8);
      UI_ShowChildByID(arg1,0x418);
      UI_ShowChildByID(arg1,0x43a);
      UI_ShowChildByID(arg1,0x43d);
      UI_ShowChildByID(arg1,0x1f44);
      UI_ShowChildByID(arg1,0x1f42);
      UI_ShowChildByID(arg1,0x43e);
      uvalue2 = Calendar_IsSelectedDate();
      if ((char)uvalue2 == '\0') {
        if (local_1f4 == -1) {
          local_1f4 = -2;
        }
        value4 = 0;
        do {
          value6 = Game_FindDailyStatRecord(self,value4,DAT_00569354,local_1f4);
          String_Format(local_16c,&DAT_005630d0,value6);
          Window_GadgetNotify_Text_SetText(arg1,(&DAT_00569488)[value4],local_16c);
          fVar10 = Stats_SumFilteredFloats3((intptr_t)self,value4,DAT_00569354,local_1f4);
          local_1d4[value4] = (float)(intptr_t)(fVar10);
          value6 = -1;
          cptr9 = local_16c;
          do {
            if (value6 == 0) break;
            value6 = value6 + -1;
            cVar1 = *cptr9;
            cptr9 = cptr9 + 1;
          } while (cVar1 != '\0');
          local_1f8 = (float)(fVar10 + (double)local_1f8);
          if (value6 != -3) {
            String_Format(local_16c,(uint8_t *)s___2f___005683d4,SUB84((double)fVar10,0));
          }
          Window_GadgetNotify_Text_SetText(arg1,(&DAT_00569420)[value4],local_16c);
          value4 = value4 + 1;
        } while (value4 < 0x14);
        value4 = 0x14;
        fptr5 = local_184;
        do {
          fVar10 = Stats_SumFilteredFloats3((intptr_t)self,value4,DAT_00569354,local_1f4);
          *fptr5 = (float)(intptr_t)(fVar10);
          value4 = value4 + 1;
          fptr5 = fptr5 + 1;
          local_1f8 = (float)(fVar10 + (double)local_1f8);
        } while (value4 < 0x1a);
      }
      else {
        value6 = 0;
        if (0 < value4) {
          do {
            value7 = IDMap_Lookup((void *)((intptr_t)self + 0x148),value6,(int *)0x0);
            fVar10 = Stats_SumFilteredFloats(value7,-1,DAT_00569354,local_1f4);
            local_1d4[value6] = (float)(intptr_t)(fVar10);
            fVar11 = Stats_SumFilteredRecordFloats20(value7,DAT_00569354,local_1f4);
            local_1e8 = (float *)pc2_bits((double)((float)(intptr_t)(fVar10) + (float)(intptr_t)(local_1e8)));
            local_1f8 = (float)(intptr_t)(fVar10) + local_1f8;
            fVar10 = Stats_SumFilteredFloats
                               (value7,-1,DAT_00569354,
                                (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10));
            local_1dc = (float)(fVar10 + (double)local_1dc);
            String_Format(local_16c,(uint8_t *)s___2f___005683d4,SUB84((double)(float)(intptr_t)(fVar11),0));
            Window_GadgetNotify_Text_SetText(arg1,(&DAT_00569420)[value6],local_16c);
            Window_GadgetNotify_Text_SetText(arg1,(&DAT_00569488)[value6],value7 + 4);
            value6 = value6 + 1;
          } while (value6 < value4);
        }
        if (value4 < 0x14) {
          value6 = value4 * 4;
          do {
            UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00569420 + value6));
            UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00569488 + value6));
            value6 = value6 + 4;
          } while (value6 < 0x50);
        }
        value6 = 0;
        do {
          fVar10 = Stats_SumFilteredFloats3((intptr_t)self,value6,DAT_00569354,local_1f4);
          value6 = value6 + 1;
          local_1dc = (float)(fVar10 + (double)local_1dc);
        } while (value6 < 0x14);
        value6 = 0x14;
        local_1e0 = 0;
        do {
          fVar10 = Stats_SumFilteredFloats3((intptr_t)self,value6,DAT_00569354,local_1f4);
          value7 = 0;
          *(float *)((intptr_t)local_184 + local_1e0) = (float)(intptr_t)(fVar10);
          if (0 < value4) {
            do {
              value3 = IDMap_Lookup((void *)((intptr_t)self + 0x148),value7,(int *)0x0);
              fVar10 = Stats_SumFilteredFloats
                                 (value3,value6,DAT_00569354,
                                  (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10));
              value7 = value7 + 1;
              *(float *)((intptr_t)local_184 + local_1e0) =
                   (float)(fVar10 + (double)*(float *)((intptr_t)local_184 + local_1e0));
            } while (value7 < value4);
          }
          local_1f8 = local_1f8 + *(float *)((intptr_t)local_184 + local_1e0);
          String_Format(local_16c,(uint8_t *)s___2f___005683d4,
                        SUB84((double)*(float *)((intptr_t)local_184 + local_1e0),0));
          Window_GadgetNotify_Text_SetText
                    (arg1,*(int *)((intptr_t)&DAT_00569470 + local_1e0),local_16c);
          local_1e0 = local_1e0 + 4;
          value6 = value6 + 1;
        } while (local_1e0 < 0x18);
        if (0.0 < local_1dc - (float)(intptr_t)(local_1e8)) {
          local_184[0] = local_184[0] + (local_1dc - (float)(intptr_t)(local_1e8));
        }
      }
      String_Format(local_16c,(uint8_t *)s___2f___005683d4,SUB84((double)local_184[0],0));
      Window_GadgetNotify_Text_SetText(arg1,DAT_00569470,local_16c);
      UI_ShowChildByID(arg1,DAT_00569484);
      UI_ShowChildByID(arg1,DAT_00569480);
      UI_ShowChildByID(arg1,0x4a4);
      UI_ShowChildByID(arg1,0x4a7);
      value4 = 0;
      do {
        String_Format(local_16c,(uint8_t *)s___2f___005683d4,
                      SUB84((double)*(float *)((intptr_t)local_184 + value4 + 4),0));
        Window_GadgetNotify_Text_SetText(arg1,*(int *)((intptr_t)&DAT_00569474 + value4),local_16c);
        value4 = value4 + 4;
      } while (value4 < 0x14);
    }
    else {
      value4 = 0;
      do {
        fVar10 = Stats_SumFilteredFloats2(local_1d8,value4,DAT_00569354,local_1f4);
        local_6c[value4] = (float)(intptr_t)(fVar10);
        local_1ec = (float)(fVar10 + (double)local_1ec);
        String_Format(local_16c,(uint8_t *)s___2f___005683d4,SUB84((double)fVar10,0));
        Window_GadgetNotify_Text_SetText(arg1,(&DAT_005693bc)[value4],local_16c);
        value4 = value4 + 1;
      } while (value4 < 0x14);
      UI_RemoveObjectByKey(arg1,DAT_005693c8);
      ptr8 = &DAT_0056940c;
      do {
        UI_RemoveObjectByKey(arg1,*ptr8);
        ptr8 = ptr8 + 1;
      } while ((intptr_t)ptr8 < 0x569420);
      UI_RemoveObjectByKey(arg1,0x418);
      UI_RemoveObjectByKey(arg1,0x43a);
      UI_RemoveObjectByKey(arg1,0x43d);
      UI_RemoveObjectByKey(arg1,0x1f44);
      UI_RemoveObjectByKey(arg1,0x1f42);
      UI_RemoveObjectByKey(arg1,0x43e);
      value4 = 0;
      do {
        fVar10 = Stats_SumFilteredFloats(local_1d8,value4,DAT_00569354,local_1f4);
        local_1f8 = (float)(fVar10 + (double)local_1f8);
        String_Format(local_16c,(uint8_t *)s___2f___005683d4,SUB84((double)fVar10,0));
        Window_GadgetNotify_Text_SetText(arg1,(&DAT_00569420)[value4],local_16c);
        Window_GadgetNotify_Text_SetText(arg1,(&DAT_00569488)[value4],(&DAT_005834d4)[value4]);
        value4 = value4 + 1;
      } while (value4 < 9);
      value4 = 0;
      do {
        UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_00569444 + value4));
        UI_RemoveObjectByKey(arg1,*(int *)((intptr_t)&DAT_005694ac + value4));
        value4 = value4 + 4;
      } while (value4 < 0x30);
      local_1e8 = (float *)0x15;
      value4 = 0;
      do {
        fVar10 = Stats_SumFilteredFloats(local_1d8,(intptr_t)local_1e8,DAT_00569354,local_1f4);
        *(float *)((intptr_t)local_184 + value4 + 4) = (float)(intptr_t)(fVar10);
        local_1f8 = (float)(fVar10 + (double)local_1f8);
        String_Format(local_16c,(uint8_t *)s___2f___005683d4,SUB84((double)fVar10,0));
        Window_GadgetNotify_Text_SetText(arg1,*(int *)((intptr_t)&DAT_00569474 + value4),local_16c);
        value4 = value4 + 4;
        local_1e8 = (float *)((intptr_t)local_1e8 + 1);
      } while (value4 < 0x14);
      UI_RemoveObjectByKey(arg1,0x4a4);
      UI_RemoveObjectByKey(arg1,0x4a7);
      UI_RemoveObjectByKey(arg1,DAT_00569484);
      UI_RemoveObjectByKey(arg1,DAT_00569480);
    }
    if (local_1ec <= local_1f8) {
      String_Format(local_16c,(uint8_t *)s___2f___005683d4,SUB84((double)(local_1f8 - local_1ec),0));
      Window_GadgetNotify_Text_SetText(arg1,0x441,local_16c);
      Window_GadgetNotify_Text_SetText(arg1,0x440,DAT_00582d8c);
      Window_GadgetNotify_Text_SetTextColor(arg1,0x441,0xa000);
      Window_GadgetNotify_Text_SetTextColor(arg1,0x440,0xa000);
      Window_GadgetNotify_Text_SetText(arg1,0x4ab,DAT_00582e4c);
      Window_GadgetNotify_Text_SetText(arg1,0x4aa,DAT_00582e4c);
      local_1ec = local_1f8;
    }
    else {
      String_Format(local_16c,(uint8_t *)s___2f___005683d4,SUB84((double)(local_1ec - local_1f8),0));
      Window_GadgetNotify_Text_SetTextColor(arg1,0x4ab,0xff);
      Window_GadgetNotify_Text_SetTextColor(arg1,0x4aa,0xff);
      Window_GadgetNotify_Text_SetText(arg1,0x4ab,local_16c);
      Window_GadgetNotify_Text_SetText(arg1,0x4aa,DAT_00582554);
      Window_GadgetNotify_Text_SetText(arg1,0x440,DAT_00582e4c);
      Window_GadgetNotify_Text_SetText(arg1,0x441,DAT_00582e4c);
    }
    String_Format(local_16c,(uint8_t *)s___2f___005683d4,SUB84((double)local_1ec,0));
    Window_GadgetNotify_Text_SetText(arg1,0x4b1,local_16c);
    Window_GadgetNotify_Text_SetText(arg1,0x4af,local_16c);
    StatisticsBalance_UpdateBranchProfitColumn(arg1,DAT_0057d5d4);
  }
  return;
}
