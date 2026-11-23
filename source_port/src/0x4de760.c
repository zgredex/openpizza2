// Company_ProcessDailyAccounting: ported from Pizza Connection 2 at 0x4de760.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4de760
#include "pc2_port.h"


void __thiscall Company_ProcessDailyAccounting(void *self,char *arg1)

{
  char cVar1;
  int value2;
  int value3;
  int value4;
  int value5;
  int *ptr6;
  int value7;
  void *pvVar8;
  uint32_t uvalue9;
  uint32_t uvalue10;
  char *cptr11;
  float *fptr12;
  int value13;
  char *cptr14;
  char *cptr15;
  double fVar16;
  uint32_t local_30;
  float local_20;
  float local_1c;
  char *local_18;
  float *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005593db;
  local_c = ExceptionList;
  local_30 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 4);
  if (arg1 != (char *)0x0) {
    local_30 = local_30 - 1;
  }
  value2 = *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10) - 1;
  ExceptionList = &local_c;
  value3 = Game_FindRecordByField4(self,value2);
  value4 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  if (*(int *)((intptr_t)self + 0x48) == value4) {
    Object_ClearField28(*(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xac));
  }
  value4 = Game_GetPlayerFieldC20((intptr_t)self);
  value5 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  Game_CanAffordWithCurrency
            (self,3,(float)(value4 * value4 * 0xbc) * *(float *)(value5 + 0x94),'\0',0xffffffff);
  value5 = Game_GetPlayerCity((intptr_t)self);
  value4 = *(int *)((intptr_t)self + 0x1cc);
  value13 = 0;
  value5 = (((*(int *)(value5 + 0x68) + *(int *)(value5 + 0x50)) * -0x1e + 100) * 500) / 100;
  if (0 < value4) {
    do {
      ptr6 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value13,(int *)0x0);
      if (ptr6[1] == 0x17) {
        value7 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr6,(int *)0x0);
        if ((*(int *)(value7 + 0x10c) == -1) ||
           (pvVar8 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x148),*(int *)(value7 + 0x10c),
                                          (int *)0x0), pvVar8 == (void *)0x0)) {
          Game_CanAffordWithCurrency(self,10,(float)value5,'\0',0xffffffff);
        }
        else {
          Game_CanAfford(pvVar8,10,(float)value5,'\0',-1);
        }
      }
      value13 = value13 + 1;
    } while (value13 < value4);
  }
  value4 = 0;
  if (0 < *(int *)((intptr_t)self + 0x194)) {
    do {
      pvVar8 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x180),value4,(int *)0x0);
      Storage_ChargePurchaseCost(pvVar8);
      value4 = value4 + 1;
    } while (value4 < *(int *)((intptr_t)self + 0x194));
  }
  value4 = *(int *)((intptr_t)self + 0x15c);
  if (value3 != 0) {
    local_1c = 0.0;
    if (0 < value4) {
      local_18 = (char *)(value3 + 0xdc);
      local_10 = (float *)(value3 + 0x10);
      do {
        value5 = IDMap_Lookup((void *)((intptr_t)self + 0x148),(intptr_t)local_1c,(int *)0x0);
        uvalue9 = 0xffffffff;
        cptr11 = (char *)(value5 + 4);
        do {
          cptr14 = cptr11;
          if (uvalue9 == 0) break;
          uvalue9 = uvalue9 - 1;
          cptr14 = cptr11 + 1;
          cVar1 = *cptr11;
          cptr11 = cptr14;
        } while (cVar1 != '\0');
        uvalue9 = ~uvalue9;
        cptr11 = cptr14 + -uvalue9;
        cptr14 = local_18;
        for (uvalue10 = uvalue9 >> 2; uvalue10 != 0; uvalue10 = uvalue10 - 1) {
          *(uint32_t *)cptr14 = *(uint32_t *)cptr11;
          cptr11 = cptr11 + 4;
          cptr14 = cptr14 + 4;
        }
        for (uvalue9 = uvalue9 & 3; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
          *cptr14 = *cptr11;
          cptr11 = cptr11 + 1;
          cptr14 = cptr14 + 1;
        }
        value13 = 0;
        fptr12 = (float *)(value3 + 0x78);
        do {
          fVar16 = Stats_SumFilteredFloats2(value5,value13,local_30,value2);
          value13 = value13 + 1;
          *fptr12 = (float)(fVar16 + (double)*fptr12);
          fptr12 = fptr12 + 1;
        } while (value13 < 0x19);
        local_20 = 0.0;
        value13 = 0;
        fptr12 = (float *)(value3 + 0x10);
        do {
          if (value13 < 0x14) {
            fVar16 = Stats_SumFilteredFloats(value5,value13,local_30,value2);
            local_20 = (float)(fVar16 + (double)local_20);
          }
          else {
            fVar16 = Stats_SumFilteredFloats(value5,value13,local_30,value2);
            *fptr12 = (float)(fVar16 + (double)*fptr12);
          }
          value13 = value13 + 1;
          fptr12 = fptr12 + 1;
        } while (value13 < 0x1a);
        local_1c = (float)((intptr_t)local_1c + 1);
        local_18 = local_18 + 0x20;
        *local_10 = local_20 + *local_10;
        local_10 = local_10 + 1;
      } while ((intptr_t)local_1c < value4);
    }
    if (value4 < 0x14) {
      local_10 = (float *)(0x14 - value4);
      cptr11 = (char *)(value4 * 0x20 + 0xdc + value3);
      do {
        uvalue9 = 0xffffffff;
        cptr14 = DAT_00582e4c;
        do {
          cptr15 = cptr14;
          if (uvalue9 == 0) break;
          uvalue9 = uvalue9 - 1;
          cptr15 = cptr14 + 1;
          cVar1 = *cptr14;
          cptr14 = cptr15;
        } while (cVar1 != '\0');
        uvalue9 = ~uvalue9;
        cptr14 = cptr15 + -uvalue9;
        cptr15 = cptr11;
        for (uvalue10 = uvalue9 >> 2; uvalue10 != 0; uvalue10 = uvalue10 - 1) {
          *(uint32_t *)cptr15 = *(uint32_t *)cptr14;
          cptr14 = cptr14 + 4;
          cptr15 = cptr15 + 4;
        }
        local_10 = (float *)((intptr_t)local_10 + -1);
        for (uvalue9 = uvalue9 & 3; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
          *cptr15 = *cptr14;
          cptr14 = cptr14 + 1;
          cptr15 = cptr15 + 1;
        }
        cptr11 = cptr11 + 0x20;
      } while (local_10 != (float *)0x0);
    }
  }
  value2 = 0;
  if (0 < value4) {
    do {
      pvVar8 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x148),value2,(int *)0x0);
      Branch_CloseMonth(pvVar8,(intptr_t)arg1);
      value2 = value2 + 1;
    } while (value2 < value4);
  }
  if (arg1 != (char *)0x0) {
    local_1c = 0.0;
    local_20 = 0.0;
    pvVar8 = operator_new(0x35c);
    local_4 = 0;
    if (pvVar8 == (void *)0x0) {
      local_18 = (char *)0x0;
    }
    else {
      local_18 = (char *)Stats_Report_Construct(pvVar8,0xfffffffe,local_30,(intptr_t)self);
    }
    value2 = 0;
    local_4 = 0xffffffff;
    if (0 < value4) {
      arg1 = (char *)((intptr_t)local_18 + 0xdc);
      fptr12 = (float *)((intptr_t)local_18 + 0x10);
      do {
        value3 = IDMap_Lookup((void *)((intptr_t)self + 0x148),value2,(int *)0x0);
        uvalue9 = 0xffffffff;
        cptr11 = (char *)(value3 + 4);
        do {
          cptr14 = cptr11;
          if (uvalue9 == 0) break;
          uvalue9 = uvalue9 - 1;
          cptr14 = cptr11 + 1;
          cVar1 = *cptr11;
          cptr11 = cptr14;
        } while (cVar1 != '\0');
        uvalue9 = ~uvalue9;
        cptr11 = cptr14 + -uvalue9;
        cptr14 = arg1;
        for (uvalue10 = uvalue9 >> 2; uvalue10 != 0; uvalue10 = uvalue10 - 1) {
          *(uint32_t *)cptr14 = *(uint32_t *)cptr11;
          cptr11 = cptr11 + 4;
          cptr14 = cptr14 + 4;
        }
        for (uvalue9 = uvalue9 & 3; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
          *cptr14 = *cptr11;
          cptr11 = cptr11 + 1;
          cptr14 = cptr14 + 1;
        }
        fVar16 = Stats_SumFilteredFloats(value3,-1,local_30,-1);
        value2 = value2 + 1;
        arg1 = arg1 + 0x20;
        local_20 = (float)((double)local_20 + fVar16);
        *fptr12 = (float)(fVar16 + (double)*fptr12);
        fptr12 = fptr12 + 1;
      } while (value2 < value4);
    }
    value2 = 0;
    do {
      fVar16 = Stats_SumFilteredFloats3((intptr_t)self,value2,local_30,-1);
      value2 = value2 + 1;
      local_1c = (float)(fVar16 + (double)local_1c);
    } while (value2 < 0x1a);
    if (0.0 < local_1c - local_20) {
      *(float *)((intptr_t)local_18 + 0x60) = (local_1c - local_20) + *(float *)((intptr_t)local_18 + 0x60);
    }
    List_Add((void *)((intptr_t)self + 0x164),local_18);
  }
  ExceptionList = local_c;
  return;
}
