// Object_PickByCursorDirection: ported from Pizza Connection 2 at 0x50b200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50b200
#include "pc2_port.h"

int __thiscall
Object_PickByCursorDirection(void *self,uint32_t arg1,uint32_t *arg2,void *arg3)

{
  void *this_00;
  int *ptr1;
  int value2;
  int value3;
  uint32_t uvalue4;
  void *this_01;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (*(int *)((intptr_t)self + 200) != 0) {
    if (arg3 != (void *)0x0) {
      List_Node_Reset((intptr_t)arg3);
    }
    this_00 = *(void **)((intptr_t)self + 0xf4);
    Record_GetTwoFloats48
              ((void *)(*(int **)((intptr_t)self + 200))[0x16],**(int **)((intptr_t)self + 200),&local_c,
               &local_4);
    local_18 = 0;
    if (0 < *(int *)((intptr_t)this_00 + 0x8c)) {
      do {
        value2 = Game_MapRecordToGlobal(this_00,local_18);
        value3 = State_Is1A1B1C(value2);
        if ((value3 != 0) && (*(int *)(value2 + 0x38) != 0x1f)) {
          ptr1 = *(int **)(value2 + 200);
          if (ptr1 == (int *)0x0) {
            value3 = -1;
            this_01 = (void *)0x0;
          }
          else {
            value3 = *ptr1;
            this_01 = (void *)ptr1[0x16];
          }
          Record_GetTwoFloats48(this_01,value3,&local_10,&local_8);
          if ((local_10 - local_c) * (local_10 - local_c) +
              (local_8 - local_4) * (local_8 - local_4) * 4 < 0xe10) {
            uvalue4 = UI_ComputeObjectDirection
                              (self,(float)(*(int *)(*(int *)((intptr_t)self + 0xc4) + 0xf8) + local_10),
                               *(int *)(*(int *)((intptr_t)self + 0xc4) + 0xfc) + local_8);
            *arg2 = uvalue4;
            if (arg3 == (void *)0x0) {
              return value2;
            }
            List_Add(arg3,value2);
          }
        }
        local_18 = local_18 + 1;
      } while (local_18 < *(int *)((intptr_t)this_00 + 0x8c));
    }
    if (arg3 != (void *)0x0) {
      value2 = IDMap_Lookup(arg3,0,(int *)0x0);
      return value2;
    }
  }
  return 0;
}
