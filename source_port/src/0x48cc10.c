// Game_CountAssignedAssetSlots: ported from Pizza Connection 2 at 0x48cc10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48cc10
#include "pc2_port.h"

int __thiscall Game_CountAssignedAssetSlots(void *self,int *arg1,int *arg2)

{
  void *this_00;
  void *pvVar1;
  int value2;
  int value3;
  uint32_t uvalue4;
  int value5;
  int *ptr6;
  int local_8;
  int local_4;
  
  this_00 = *(void **)((intptr_t)self + *(int *)((intptr_t)self + 0x2ec) * 4 + 0x200);
  local_8 = 0;
  local_4 = 0;
  ptr6 = (int *)((intptr_t)self + 0x200);
  do {
    pvVar1 = (void *)*ptr6;
    if ((pvVar1 != (void *)0x0) && (pvVar1 != this_00)) {
      value2 = *(int *)((intptr_t)pvVar1 + 0x15c);
      value5 = 0;
      if (0 < value2) {
        do {
          value3 = IDMap_Lookup((void *)(*ptr6 + 0x148),value5,(int *)0x0);
          uvalue4 = Game_IsValueAssignedToCompany(this_00,*(int *)(value3 + 0x16f0));
          if ((char)uvalue4 != '\0') {
            if (local_8 == 0) {
              *arg1 = value5;
              *arg2 = local_4;
            }
            local_8 = local_8 + 1;
          }
          value5 = value5 + 1;
        } while (value5 < value2);
      }
      value5 = 0;
      value2 = *(int *)(*ptr6 + 0x194);
      if (0 < value2) {
        do {
          value3 = IDMap_Lookup((void *)(*ptr6 + 0x180),value5,(int *)0x0);
          uvalue4 = Game_IsValueAssignedToCompany(this_00,*(int *)(value3 + 0x34));
          if ((char)uvalue4 != '\0') {
            if (local_8 == 0) {
              *arg1 = value5 + 0x14;
              *arg2 = local_4;
            }
            local_8 = local_8 + 1;
          }
          value5 = value5 + 1;
        } while (value5 < value2);
      }
      uvalue4 = Game_IsValueAssignedToCompany(this_00,*(int *)(*ptr6 + 0x1d8));
      if ((char)uvalue4 != '\0') {
        if (local_8 == 0) {
          *arg1 = 0x28;
          *arg2 = local_4;
        }
        local_8 = local_8 + 1;
      }
    }
    ptr6 = ptr6 + 1;
    local_4 = local_4 + 1;
  } while (local_4 < 6);
  return local_8;
}
