// Stats_Report_FillCompanyOverview: ported from Pizza Connection 2 at 0x4decf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4decf0
#include "pc2_port.h"

void __thiscall Stats_Report_FillCompanyOverview(void *self,int *arg1)

{
  int *ptr1;
  int *ptr2;
  int value3;
  void *pvVar4;
  uint32_t *this_00;
  int value5;
  uint32_t uvalue6;
  int value7;
  int local_c;
  int local_4;
  
  ptr2 = arg1;
  value7 = 0;
  *(uint32_t *)*arg1 = 0;
  *(uint32_t *)(*arg1 + 4) = 0;
  *(uint32_t *)(*arg1 + 0x120) = 0;
  if (0 < *(int *)((intptr_t)self + 0x15c)) {
    do {
      value3 = IDMap_Lookup((void *)((intptr_t)self + 0x148),value7,(int *)0x0);
      ptr1 = (int *)*arg1;
      if (*(char *)(value3 + 0x16f4) == '\0') {
        ptr1[1] = ptr1[1] + 1;
        *(int *)(*arg1 + 0x120) = *(int *)(*arg1 + 0x120) + (*(int *)(value3 + 0x38) + 1) * 600
        ;
      }
      else {
        *ptr1 = *ptr1 + 1;
        *(int *)(*arg1 + 0x120) =
             *(int *)(*arg1 + 0x120) + (*(int *)(value3 + 0x38) + 1) * 0x5dc;
      }
      value7 = value7 + 1;
    } while (value7 < *(int *)((intptr_t)self + 0x15c));
  }
  value7 = 0;
  *(uint32_t *)(*arg1 + 8) = 0;
  *(uint32_t *)(*arg1 + 0xc) = 0;
  *(uint32_t *)(*arg1 + 0x124) = 0;
  if (0 < *(int *)((intptr_t)self + 0x194)) {
    do {
      value3 = IDMap_Lookup((void *)((intptr_t)self + 0x180),value7,(int *)0x0);
      if (*(char *)(value3 + 0x3c) == '\0') {
        *(int *)(*arg1 + 0xc) = *(int *)(*arg1 + 0xc) + 1;
        value5 = *arg1;
        value3 = Get_Field2C(value3);
        *(int *)(value5 + 0x124) = *(int *)(value5 + 0x124) + (value3 + 1) * 600;
      }
      else {
        *(int *)(*arg1 + 8) = *(int *)(*arg1 + 8) + 1;
        value5 = *arg1;
        value3 = Get_Field2C(value3);
        *(int *)(value5 + 0x124) = *(int *)(value5 + 0x124) + (value3 + 1) * 0x5dc;
      }
      value7 = value7 + 1;
    } while (value7 < *(int *)((intptr_t)self + 0x194));
  }
  *(uint32_t *)(*arg1 + 0x10) = 0;
  pvVar4 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                                (int *)0x0);
  this_00 = City_CollectBuildingsByType(pvVar4,0x11,0,'\0');
  value7 = 0;
  if (0 < (intptr_t)this_00[5]) {
    do {
      value3 = IDMap_Lookup(this_00,value7,(int *)0x0);
      if (*(int *)(value3 + 8) == *(int *)((intptr_t)self + 0x48)) {
        *(int *)(*arg1 + 0x10) = *(int *)(*arg1 + 0x10) + 1;
      }
      value7 = value7 + 1;
    } while (value7 < (intptr_t)this_00[5]);
  }
  value7 = 0;
  arg1 = (int *)0x6;
  local_c = 0;
  do {
    pvVar4 = (void *)Game_GetPlayerBySlot(DAT_0057c670,local_c);
    if (pvVar4 != (void *)0x0) {
      value3 = *(int *)((intptr_t)pvVar4 + 0x48);
      value5 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      value7 = value7 + *(int *)(value5 + 0xcb0 + value3 * 4);
      if (pvVar4 == self) {
        value3 = *(int *)((intptr_t)pvVar4 + 0x48);
        value5 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                             (int *)0x0);
        local_4 = *(int *)(value5 + 0xcb0 + value3 * 4);
      }
      else {
        value3 = Game_GetPlayerFieldC20((intptr_t)pvVar4);
        value5 = Game_GetPlayerFieldC20((intptr_t)self);
        if (value5 < value3) {
          arg1 = (int *)((intptr_t)arg1 + -1);
        }
        value3 = Game_GetPlayerFieldC20((intptr_t)pvVar4);
        value5 = Game_GetPlayerFieldC20((intptr_t)self);
        if ((value3 == value5) && (*(int *)((intptr_t)pvVar4 + 0x60) < *(int *)((intptr_t)self + 0x60))) {
          arg1 = (int *)((intptr_t)arg1 + -1);
        }
      }
    }
    local_c = local_c + 1;
  } while (local_c < 6);
  *(int *)(*ptr2 + 0x14) = local_4;
  if (value7 < 1) {
    *(uint32_t *)(*ptr2 + 0x128) = 0;
  }
  else {
    *(int *)(*ptr2 + 0x128) = ((local_4 * 100) / value7) * 100;
  }
  uvalue6 = Game_GetPlayerFieldC20((intptr_t)self);
  *(uint32_t *)(*ptr2 + 0x18) = uvalue6;
  *(uint32_t *)(*ptr2 + 0x1c) = *(uint32_t *)((intptr_t)self + 0x60);
  value7 = Game_GetPlayerFieldC20((intptr_t)self);
  *(int *)(*ptr2 + 300) = ((intptr_t)arg1 + value7 * 2) * 1000;
  return;
}
