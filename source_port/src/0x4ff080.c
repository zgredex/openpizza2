// AI_AssignBuilderToConstructionSite: ported from Pizza Connection 2 at 0x4ff080.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ff080
#include "pc2_port.h"

uint32_t AI_AssignBuilderToConstructionSite(void *arg1,void *arg2)

{
  uint8_t flag1;
  int value2;
  bool flag3;
  uint32_t extraout_var;
  int value4;
  int *ptr5;
  uint32_t uvalue6;
  int value7;
  void *self;
  uint32_t uvalue8;
  int value9;
  int value10;
  int local_8;
  
                    /* Assigns a builder to a construction site and charges the cost. */
  flag3 = Math_CompareRounded();
  if (CONCAT31(extraout_var,flag3) == 0) {
    return 2;
  }
  value9 = 0;
  value10 = 0;
  local_8 = 0;
  flag1 = *(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 7);
  value4 = Game_CountObjectsByType(arg2,0xffffffff);
  if (0 < value4) {
    do {
      ptr5 = (int *)IDMap_Lookup((void *)((intptr_t)arg2 + 0x1500),value9,(int *)0x0);
      value2 = *ptr5;
      if ((*(char *)(value2 + 0x824) == '\0') || (*(char *)(value2 + 0x824) == '\x02')) {
        uvalue6 = (ptr5[1] + 3) * 3 - (flag1 + 4);
        if (0x17 < (intptr_t)uvalue6) {
          uvalue6 = uvalue6 - 0x18;
        }
        if ((intptr_t)uvalue6 < -0x17) {
          uvalue6 = uvalue6 + 0x18;
        }
        if ((intptr_t)((uvalue6 ^ (intptr_t)uvalue6 >> 0x1f) - ((intptr_t)uvalue6 >> 0x1f)) < 3) {
          value7 = Rating_ClampAdjusted(value2);
          if ((value10 == 0) || (local_8 < value7)) {
            value10 = value2;
            local_8 = value7;
          }
        }
      }
      value9 = value9 + 1;
    } while (value9 < value4);
    if (value10 != 0) {
      value10 = Game_GetRecordByField814(value10);
      value4 = Game_HasObjectWithSourceId(value10);
      if (value4 != 0) {
        return 3;
      }
      ptr5 = AI_FindTargetWithMinA8(arg1,0x1d);
      if (ptr5 == (int *)0x0) {
        return 3;
      }
      self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr5,(int *)0x0);
      if (self == (void *)0x0) {
        return 3;
      }
      uvalue8 = Game_CanAffordWithCurrency(arg1,0x17,10000.0,'\x01',0xffffffff);
      if ((char)uvalue8 != '\0') {
        Person_SendToBranchForAction(self,(intptr_t)arg2,0xe);
        *(uint32_t *)((intptr_t)self + 0x10c) = *(uint32_t *)(value10 + 0x164);
      }
      return 1;
    }
  }
  return 3;
}
