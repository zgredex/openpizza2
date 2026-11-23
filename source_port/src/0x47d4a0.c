// Branch_ProcessCustomerOrder: ported from Pizza Connection 2 at 0x47d4a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47d4a0
#include "pc2_port.h"

int __thiscall Branch_ProcessCustomerOrder(void *self,int *arg1,int arg2)

{
  uint16_t uvalue1;
  int value2;
  void *this_00;
  int value3;
  double dVar4;
  float fVar5;
  int value6;
  int value7;
  int *ptr8;
  int value9;
  int *ptr10;
  int *ptr11;
  int value12;
  int value13;
  double fVar14;
  int64_t lvalue15;
  int local_1a8;
  int local_1a4;
  uint32_t local_190;
  int local_17c;
  uint32_t local_178;
  uint32_t local_16c;
  int local_164;
  int local_160 [87];
  
                    /* Processes a customer order, consumes ingredients, and books sales. */
  value13 = 0;
  value9 = 0;
  if (arg1 == (int *)0x0) {
    return 0;
  }
  value6 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),arg1[4],(int *)0x0);
  value12 = 100;
  local_1a8 = 100;
  if (*(int *)(value6 + 0x30) == 0xb) {
    local_1a8 = 200;
    value12 = 200;
  }
  value2 = *(int *)(value6 + 0x2c);
  value7 = Branch_GetCustomerGroupRating(self,*(int *)(value6 + 0x34),1);
  local_17c = value7 - value2 >> 1;
  if (local_17c < 0) {
    local_17c = 0;
  }
  this_00 = (void *)*arg1;
  value2 = arg1[2];
  ptr8 = (int *)((intptr_t)this_00 + 100);
  value7 = 0x56;
  do {
    value3 = *ptr8;
    ptr8 = ptr8 + 1;
    value13 = value13 + value3;
    value7 = value7 + -1;
  } while (value7 != 0);
  local_1a4 = value12 * value13;
  value7 = 0;
  if (0 < *(int *)((intptr_t)self + 0x19ac)) {
    do {
      ptr8 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1998),value7,(int *)0x0);
      if (ptr8[7] != 0) {
        value9 = value9 + *ptr8;
      }
      value7 = value7 + 1;
    } while (value7 < *(int *)((intptr_t)self + 0x19ac));
    value12 = local_1a8;
  }
  if (value9 < local_1a4) {
    local_1a4 = value13 * (value9 / value13);
    local_1a8 = value9 / value13;
  }
  else {
    local_1a8 = value12;
  }
  uvalue1 = *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  local_16c = (uint32_t)uvalue1;
  if (99 < uvalue1) {
    local_16c = 99;
  }
  if ((arg2 != 0) && (value12 != 0)) {
    local_164 = value12;
  }
  dVar4 = 0.0;
  if (local_1a8 == 0) {
    return 0;
  }
  ptr11 = (int *)(DAT_0057c670 + 0xa8);
  ptr8 = local_160;
  ptr10 = (int *)((intptr_t)this_00 + 100);
  value9 = 0x56;
  do {
    value12 = *ptr10;
    ptr10 = ptr10 + 1;
    *ptr8 = value12;
    value7 = *ptr11;
    ptr8 = ptr8 + 1;
    ptr11 = ptr11 + 1;
    value9 = value9 + -1;
    dVar4 = *(double *)(value7 + 0xc0) * (double)value12 * 0.001 + dVar4;
  } while (value9 != 0);
  value9 = *(int *)((intptr_t)self + 0x19ac);
  fVar5 = 0.0;
  for (; 0 < local_1a4; local_1a4 = local_1a4 - value12) {
    ptr8 = (int *)0x0;
    value12 = 0;
    if (value9 < 1) break;
    do {
      ptr10 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1998),value12,(int *)0x0);
      if (((ptr10[7] != 0) && (*ptr10 != 0)) &&
         ((ptr8 == (int *)0x0 || (ptr10[1] < ptr8[1])))) {
        ptr8 = ptr10;
      }
      value12 = value12 + 1;
    } while (value12 < value9);
    if (ptr8 == (int *)0x0) break;
    value12 = *ptr8;
    if (local_1a4 <= *ptr8) {
      value12 = local_1a4;
    }
    *ptr8 = *ptr8 - value12;
    fVar5 = (float)ptr8[4] * (float)value12 * (float)(dVar4 / (double)value13) + fVar5;
  }
  fVar14 = Game_GetMarketBonusFactor((intptr_t)self);
  fVar14 = fVar14 * (double)fVar5;
  lvalue15 = __ftol();
  value9 = (intptr_t)lvalue15;
  if (value9 < 1) {
    Stats_AddRecordValue(self,0x17,(float)-value9,-1);
  }
  else {
    Game_CanAfford(self,0x13,(float)value9,'\0',-1);
  }
  if (*(int *)(value6 + 0x38) == 0x1a) {
    value9 = 0x12;
  }
  else {
    value9 = 0xc;
  }
  Game_CanAfford(self,value9,
                 (float)((double)(double)fVar14 - (double)(double)(fVar14 - (double)fVar5)),'\0',
                 -1);
  fVar5 = ((float)local_17c + 100.0) * (float)local_1a8 * (float)arg1[1] * 0.01;
  if (*(void **)(DAT_0057c670 + 0x9c) == self) {
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(uint8_t *)s_Order_in__s_00567c50,(intptr_t)self + 4);
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(uint8_t *)s_Gast__s_00567c48,
                        (&DAT_005834d4)[*(int *)(value6 + 0x34)]);
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(uint8_t *)s_Trinkgeld__d_00567c38,local_17c);
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(uint8_t *)s_Pizza____s_00567c28,*arg1 + 4);
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(uint8_t *)s_Anzahl____d_00567c18,local_1a8);
    local_190 = SUB84((double)fVar14,0);
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(uint8_t *)s_Ausgaben_____2f_00567c08,local_190);
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(uint8_t *)s_MenuPreis____2f_00567bf8,
                        SUB84((double)(float)arg1[1],0));
    local_178 = SUB84((double)fVar5,0);
    DebugConsole_Printf(DAT_0057c1e0,0x888800,(uint8_t *)s_Einnahmen____2f_00567be8,local_178);
  }
  arg1[7] = (intptr_t)(fVar5 + 0.5);
  arg1[5] = local_1a8;
  arg1[8] = local_164;
  arg1[6] = (intptr_t)((fVar5 - (float)fVar14) + 0.5);
  arg1[9] = local_16c;
  arg1[0xb] = value2;
  arg1[10] = *(int *)((intptr_t)self + 0x3c);
  Branch_UpdateConstructionQueue(self);
  Recipe_AppendSalesRecord(this_00,(intptr_t)arg1);
  return local_1a8;
}
