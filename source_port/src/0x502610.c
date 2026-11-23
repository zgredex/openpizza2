// AI_SelectExpansionAction: ported from Pizza Connection 2 at 0x502610.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502610
#include "pc2_port.h"

uint32_t __fastcall AI_SelectExpansionAction(int arg1)

{
  bool flag1;
  int value2;
  int value3;
  uint32_t uvalue4;
  int value5;
  int value6;
  int value7;
  int value8;
  uint32_t local_10;
  int local_8;
  
  value7 = 0;
  value5 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  local_8 = 0;
  local_10 = 2;
  if (((*(int *)(arg1 + 0x44) == 0) && (*(int *)(value5 + 0x15c) == 0)) &&
     (local_8 = 1, *(int *)(value5 + 0x194) == 0)) {
    local_8 = 2;
  }
  if ((*(int *)(arg1 + 0x44) == 1) && (*(int *)(value5 + 0x15c) == 0x14)) {
    value6 = 0;
    local_10 = 1;
    do {
      value2 = IDMap_Lookup((void *)(value5 + 0x148),value7,(int *)0x0);
      if (*(int *)(value2 + 0x38) == 2) {
        value6 = value6 + 1;
      }
      value7 = value7 + 1;
    } while (value7 < 0x14);
    if (value6 == 0x14) {
      local_10 = 0;
    }
  }
  if (*(int *)(arg1 + 0x44) == 2) {
    flag1 = false;
    value7 = 0;
    do {
      value6 = Game_GetPlayerBySlot(DAT_0057c670,value7);
      if (value6 != 0) {
        value2 = *(int *)(value6 + 0x15c);
        value8 = 0;
        if (0 < value2) {
          do {
            value3 = IDMap_Lookup((void *)(value6 + 0x148),value8,(int *)0x0);
            value3 = Game_CountFreeBuildingsByType(*(void **)(value3 + 0x16f0),0x17);
            if (value3 != 0) {
              flag1 = true;
              break;
            }
            value8 = value8 + 1;
          } while (value8 < value2);
        }
      }
      value7 = value7 + 1;
    } while (value7 < 6);
    if (!flag1) {
      local_10 = 1;
    }
  }
  uvalue4 = Random_RangeFast(local_8,local_10);
  if (uvalue4 == 1) {
    if (*(int *)(arg1 + 0x44) == 1) {
      value6 = 0;
      local_8 = 0;
      value7 = *(int *)(value5 + 0x15c);
      if (0 < value7) {
        do {
          value2 = IDMap_Lookup((void *)(value5 + 0x148),value6,(int *)0x0);
          if (*(int *)(value2 + 0x38) == 2) {
            local_8 = local_8 + 1;
          }
          value6 = value6 + 1;
        } while (value6 < value7);
      }
      if (local_8 != value7) goto LAB_0050277f;
      if (value7 != 0x14) {
LAB_005027a4:
        uvalue4 = 2;
        goto LAB_005027b4;
      }
    }
    else {
LAB_0050277f:
      if ((*(int *)(arg1 + 0x44) != 0) || (*(int *)(value5 + 0x194) != 0)) goto LAB_005027d5;
      uvalue4 = Random_RangeFast(0,1);
      if (uvalue4 == 0) goto LAB_005027a4;
    }
    uvalue4 = 0;
  }
  else {
    if (uvalue4 != 2) goto LAB_005027d5;
LAB_005027b4:
    if (*(int *)(arg1 + 0x44) == 2) {
      *(uint32_t *)(arg1 + 0x84) = 200000;
    }
    if (*(int *)(arg1 + 0x44) == 3) {
      *(uint32_t *)(arg1 + 0x84) = 300000;
    }
  }
LAB_005027d5:
  if ((*(int *)(arg1 + 0x44) == 3) && (uvalue4 == 0)) {
    *(uint32_t *)(arg1 + 0x84) = 0x14;
  }
  value5 = (*(int *)(arg1 + 0x44) + uvalue4 * 4) * 4;
  *(uint32_t *)(arg1 + 0x4c) = *(uint32_t *)(&DAT_0057276c + value5);
  return *(uint32_t *)(&DAT_0057273c + value5);
}
