// AI_Action_BuyOrRentBranch: ported from Pizza Connection 2 at 0x4f7ed0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f7ed0
#include "pc2_port.h"

uint32_t __thiscall AI_Action_BuyOrRentBranch(void *self,int arg1)

{
  int value1;
  bool flag2;
  int value3;
  void *pvVar4;
  int value5;
  int value6;
  int *ptr7;
  int64_t lvalue8;
  char *cptr9;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  void *local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38 [4];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Buys or rents a new branch for an AI company. */
  local_58 = 0;
  value5 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x70);
  local_44 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x134);
  pvVar4 = (void *)((intptr_t)self + arg1 * 0x168);
  value1 = *(int *)(value5 + 0x15c);
  if (0x13 < value1) {
    return 1;
  }
  local_48 = pvVar4;
  local_3c = value5;
  if (value1 < 1) {
    value6 = arg1;
LAB_004f7fcc:
    if (0 < local_50) {
      return 1;
    }
    if ((0 < value1) && (value6 < 0)) {
      return 1;
    }
  }
  else {
    Game_GetPlayerCity(value5);
    local_40 = Game_SumPlayerAssetValue(*(int *)((intptr_t)pvVar4 + 0x40));
    value6 = *(int *)((intptr_t)pvVar4 + 0x134) - local_40;
    local_50 = 0;
    local_40 = local_40 / value1;
    local_54 = 0;
    if (0 < value1) {
      do {
        value3 = IDMap_Lookup((void *)(value5 + 0x148),local_54,(int *)0x0);
        if (value3 != 0) {
          if (*(int *)(*(int *)(value3 + 0x16f0) + 0x38) != 0) {
            local_50 = local_50 + 1;
          }
          value6 = value6 + (-1 - *(int *)(value3 + 0x38)) * 20000;
          AI_ComputePlanScores(value3,&local_4c,local_38,4);
          local_4c = local_4c - local_40;
          if (local_4c < 0) {
            local_58 = local_58 + 1;
          }
        }
        local_54 = local_54 + 1;
      } while (local_54 < value1);
      goto LAB_004f7fcc;
    }
  }
  if ((1 < value1) && (((value1 < 4 && (0 < local_58)) || (1 < local_58)))) {
    return 1;
  }
  if (9 < value1) {
    Map_PickObject(self,arg1);
  }
  pvVar4 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0
                               );
  local_14 = AI_FindBestBranchSite(self,arg1,pvVar4,0,&local_10);
  if (local_14 != 0) {
    local_4 = Game_ComputeTradeOffers
                        (pvVar4,local_14,1,&local_c,&local_8,*(int *)((intptr_t)local_48 + 0x40),
                         (int *)0x0);
  }
  local_28 = AI_FindBestBranchSite(self,arg1,pvVar4,1,&local_24);
  if ((local_28 != 0) &&
     (local_18 = Game_ComputeTradeOffers
                           (pvVar4,local_28,1,&local_20,&local_1c,*(int *)((intptr_t)local_48 + 0x40),
                            (int *)0x0), local_44 < local_1c)) {
    local_28 = 0;
  }
  if (local_14 == 0) {
    if (local_28 == 0) {
      return 3;
    }
  }
  else {
    ptr7 = &local_14;
    flag2 = false;
    if (((local_28 == 0) || (local_24 <= local_10 * 2)) || (local_44 <= local_20 * 2))
    goto LAB_004f8113;
  }
  ptr7 = &local_28;
  flag2 = true;
LAB_004f8113:
  Game_UpdateCompanyAdvancementScore(self,arg1);
  value5 = IsSpecialIdRange(*ptr7);
  if (value5 == 0) {
    value5 = 0;
  }
  else {
    value5 = *(int *)(*ptr7 + 0x20) + -0x84c >> 2;
  }
  value5 = Player_CreateBranch(self,*(int *)((intptr_t)pvVar4 + 0xc1c),(void *)*ptr7,arg1,value5,
                              (uint32_t)!flag2);
  pvVar4 = (void *)IDMap_Lookup((void *)(local_3c + 0x148),value5,(int *)0x0);
  if (flag2) {
    *(uint8_t *)((intptr_t)pvVar4 + 0x16f4) = 1;
    lvalue8 = __ftol();
    *(int *)((intptr_t)pvVar4 + 0x14b0) = (intptr_t)lvalue8;
    *(int *)(*ptr7 + 0x3c) = ptr7[3];
    Game_CanAfford(pvVar4,2,(float)ptr7[3],'\0',-1);
    cptr9 = s_Filiale___s__gekauft__00571ed4;
  }
  else {
    *(uint8_t *)((intptr_t)pvVar4 + 0x16f4) = 0;
    *(int *)((intptr_t)pvVar4 + 0x14b0) = ptr7[2];
    Game_CanAfford(pvVar4,1,(float)ptr7[2],'\0',-1);
    cptr9 = s_Filiale___s__gemietet__00571eec;
  }
  DebugConsole_Printf(DAT_0057c1e0,0xff,(uint8_t *)cptr9,(intptr_t)pvVar4 + 4);
  return 1;
}
