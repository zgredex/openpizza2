// Recipe_RecomputeLayoutQuality: ported from Pizza Connection 2 at 0x512f10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x512f10
#include "pc2_port.h"

void __fastcall Recipe_RecomputeLayoutQuality(void *arg1)

{
  uint32_t *self;
  char *cptr1;
  int value2;
  int value3;
  int value4;
  float fVar5;
  int value6;
  int64_t lvalue7;
  int *local_14;
  int local_10;
  int local_c;
  int local_8;
  float local_4;
  
  local_c = 0;
  local_14 = (int *)((intptr_t)arg1 + 100);
  *(uint32_t *)((intptr_t)arg1 + 0x25c) = 0;
  *(uint32_t *)((intptr_t)arg1 + 0x260) = 0;
  *(uint32_t *)((intptr_t)arg1 + 600) = 0;
  *(uint32_t *)((intptr_t)arg1 + 0x248) = 0;
  local_4 = 0.0;
  do {
    fVar5 = local_4;
    if (*local_14 != 0) {
      local_8 = 0;
      do {
        value2 = local_8;
        self = Recipe_FindIngredientsByCategory(arg1,SUB41(fVar5,0),(char)local_8,&local_10);
        if ((local_10 < 0x14) && (local_10 != 0)) {
          local_c = local_c + (intptr_t)self[5] / 2;
          if (0 < (intptr_t)self[5]) {
            do {
              cptr1 = (char *)IDMap_Lookup(self,0,(int *)0x0);
              value2 = Map_FindObjectOnApproachLine(self,(intptr_t)cptr1);
              if (value2 != 0) {
                *(int *)((intptr_t)arg1 + 0x25c) = *(int *)((intptr_t)arg1 + 0x25c) + 1;
                Recipe_AccumulateQualityDelta(arg1,cptr1,value2);
                value2 = IDMap_FindIndexByPointer(self,value2);
                IDMap_RemoveRecursive(self,value2);
              }
              IDMap_RemoveRecursive(self,0);
            } while (0 < (intptr_t)self[5]);
            value2 = local_8;
            fVar5 = local_4;
          }
          if (self != (uint32_t *)0x0) {
            (**(code **)*self)(1);
          }
        }
        else if (self != (uint32_t *)0x0) {
          (**(code **)*self)(1);
        }
        local_8 = value2 + 1;
      } while (local_8 < 4);
    }
    local_4 = (float)((intptr_t)fVar5 + 1);
    local_14 = local_14 + 1;
  } while ((intptr_t)local_4 < 0x56);
  value2 = *(int *)((intptr_t)arg1 + 0x25c);
  value3 = 5;
  local_10 = 0;
  if (0 < value2) {
    value4 = value2;
    do {
      value6 = *(int *)((intptr_t)arg1 + 0x248) + value3;
      value3 = value3 + 5;
      *(int *)((intptr_t)arg1 + 0x248) = value6;
      if (0x14 < value3) {
        value3 = 0x14;
      }
      value4 = value4 + -1;
      local_10 = value2;
    } while (value4 != 0);
  }
  value2 = *(int *)((intptr_t)arg1 + 0x248) + (value2 - local_c) * 10;
  *(int *)((intptr_t)arg1 + 0x248) = value2;
  if (100 < value2) {
    *(uint32_t *)((intptr_t)arg1 + 0x248) = 100;
  }
  if (*(int *)((intptr_t)arg1 + 0x248) < 0) {
    *(uint32_t *)((intptr_t)arg1 + 0x248) = 0;
  }
  if (*(int *)((intptr_t)arg1 + 0x260) < 1) {
    local_4 = 0.0;
  }
  else {
    local_4 = (float)*(int *)((intptr_t)arg1 + 600) / (float)*(int *)((intptr_t)arg1 + 0x260);
  }
  lvalue7 = Math_RoundFloat(local_4);
  value2 = (intptr_t)lvalue7 * 100;
  *(int *)((intptr_t)arg1 + 600) = value2;
  if (100 < value2) {
    *(uint32_t *)((intptr_t)arg1 + 600) = 100;
  }
  if (*(int *)((intptr_t)arg1 + 600) < 0) {
    *(uint32_t *)((intptr_t)arg1 + 600) = 0;
  }
  return;
}
