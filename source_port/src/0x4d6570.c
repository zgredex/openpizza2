// Map_CollectCompanyObjectsAtPoint: ported from Pizza Connection 2 at 0x4d6570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d6570
#include "pc2_port.h"

void __thiscall Map_CollectCompanyObjectsAtPoint(void *self,void *arg1,int arg2,int arg3)

{
  int *ptr1;
  int value2;
  int value3;
  uint8_t *uptr4;
  int value5;
  int value6;
  void *this_00;
  uint32_t local_1c;
  int local_18;
  uint32_t local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  CS_Enter(*(int *)(DAT_0057c670 + 0x244));
  value6 = arg2 << ((uint8_t)DAT_00580a50 & 0x1f);
  value5 = arg3 << ((uint8_t)DAT_00580a50 & 0x1f);
  local_c = 0;
  if (0 < *(int *)(DAT_0057c670 + 0x50)) {
    do {
      value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),local_c,(int *)0x0);
      if (((((*(int *)(value2 + 0x28) == *(int *)((intptr_t)self + 0xc1c)) && (*(int *)(value2 + 200) != 0)
            ) && ((*(uint8_t *)(*(int *)(value2 + 200) + 0x10) & 1) == 0)) &&
          (((value3 = *(int *)(value2 + 0x30), value3 != 0xd && (value3 != 0x20)) &&
           ((value3 != 0x22 && ((value3 != 0xe && (value3 != 0x2e)))))))) &&
         (((value3 != 0x11 && (((value3 != 0x13 && (value3 != 0x14)) && (value3 != 0x12)))) ||
          (value3 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)(value2 + 0x50),(int *)0x0),
          *(int *)(value3 + 0x81c) != -1)))) {
        ptr1 = *(int **)(value2 + 200);
        if (ptr1 == (int *)0x0) {
          this_00 = (void *)0x0;
          value3 = -1;
        }
        else {
          this_00 = (void *)ptr1[0x16];
          value3 = *ptr1;
        }
        if (this_00 == (void *)0x0) {
          Debug_WarningMessageBox();
        }
        Record_GetTwoFloats48(this_00,value3,&local_18,&local_10);
        Record_GetBounds48(this_00,value3,&local_8,&local_4,&local_1c,&local_14);
        Record_GetScreenRect48(this_00,value3,(int *)&local_1c,(int *)&local_14);
        local_18 = local_18 + (local_1c - *(int *)(*(int *)((intptr_t)self + 0xfa8) + 0x24));
        local_10 = local_10 + (local_14 - *(int *)(*(int *)((intptr_t)self + 0xfa8) + 0x28));
        local_8 = 0x14;
        if (((local_18 <= value6) && (value6 <= local_18 + 0x14)) &&
           ((local_10 <= value5 && (value5 <= local_4 + local_10)))) {
          uptr4 = operator_new(8);
          *uptr4 = 1;
          *(int *)(uptr4 + 4) = value2;
          List_Add(arg1,uptr4);
        }
      }
      local_c = local_c + 1;
    } while (local_c < *(int *)(DAT_0057c670 + 0x50));
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x244));
  return;
}
