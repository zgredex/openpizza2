// Person_TryDeliverCustomerOrder: ported from Pizza Connection 2 at 0x50b9c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50b9c0
#include "pc2_port.h"

uint32_t __thiscall Person_TryDeliverCustomerOrder(void *self,void *arg1)

{
  void *this_00;
  int *ptr1;
  int *this_01;
  void *pvVar2;
  int value3;
  int value4;
  uint32_t uvalue5;
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
  
                    /* Checks and books a courier delivery to a customer. */
  if (*(int *)((intptr_t)self + 200) != 0) {
    local_14 = *(int *)((intptr_t)self + 0x10c);
    this_00 = *(void **)((intptr_t)arg1 + 0x16f0);
    local_18 = 0;
    if (0 < *(int *)((intptr_t)this_00 + 0x8c)) {
      do {
        value4 = local_18;
        this_01 = (int *)Game_MapRecordToGlobal(this_00,local_18);
        if (this_01[0x59] == local_14) {
          Record_GetTwoFloats48
                    ((void *)(*(int **)((intptr_t)self + 200))[0x16],**(int **)((intptr_t)self + 200),
                     &local_24,&local_28);
          local_24 = local_24 + *(int *)(*(int *)((intptr_t)self + 0xc4) + 0xf8);
          local_28 = local_28 + *(int *)(*(int *)((intptr_t)self + 0xc4) + 0xfc);
          ptr1 = (int *)this_01[0x32];
          if (ptr1 == (int *)0x0) {
            value4 = -1;
            pvVar2 = (void *)0x0;
          }
          else {
            value4 = *ptr1;
            pvVar2 = (void *)ptr1[0x16];
          }
          Record_GetTwoFloats48(pvVar2,value4,&local_20,&local_1c);
          pvVar2 = *(void **)((intptr_t)self + 0xc4);
          local_20 = local_20 + *(int *)((intptr_t)pvVar2 + 0xf8);
          local_1c = local_1c + *(int *)((intptr_t)pvVar2 + 0xfc);
          Map_ScreenToGridCell(pvVar2,local_20,local_1c,&local_8,&local_10,(int *)0x1);
          Map_ScreenToGridCell
                    (*(void **)((intptr_t)self + 0xc4),local_24,local_28,&local_4,&local_c,(int *)0x1);
          uvalue5 = local_10 - local_c >> 0x1f;
          if ((intptr_t)((local_10 - local_c ^ uvalue5) - uvalue5) < 5) {
            value4 = *(int *)((intptr_t)self + 0x110);
            value3 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
            if (value4 == value3) {
              MissionGoal_HandleEvent
                        (*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),10,this_01[0x59],-1);
            }
            Object_SetState(this_01,0x25);
            this_01[0x42] = 1;
            Staff_HandleKidnapping(*(void **)(DAT_0057c670 + 0x90),arg1,this_01);
            this_01[0x43] = *(int *)((intptr_t)self + 0x164);
            return 1;
          }
          value4 = local_18;
        }
        local_18 = value4 + 1;
      } while (local_18 < *(int *)((intptr_t)this_00 + 0x8c));
    }
  }
  return 0;
}
