// Map_UpdateVisibleObjects: ported from Pizza Connection 2 at 0x4ef1c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ef1c0
#include "pc2_port.h"

void __thiscall Map_UpdateVisibleObjects(void *self,int arg1)

{
  int *ptr1;
  void *this_00;
  int value2;
  int value3;
  int value4;
  uint32_t local_48;
  uint32_t local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  uint32_t local_28;
  uint32_t local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_8;
  int local_4;
  
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x13c)) {
    value4 = 0;
    do {
      value2 = value2 + 1;
      *(uint32_t *)(value4 + 0x20 + *(int *)((intptr_t)self + 0x138)) = 0;
      value4 = value4 + 0x3c;
    } while (value2 < *(int *)((intptr_t)self + 0x13c));
  }
  for (ptr1 = *(int **)((intptr_t)self + 0xbc); ptr1 != (int *)0x0; ptr1 = (int *)ptr1[0x1c]) {
    Record_GetTwoFloats48((void *)ptr1[0x16],*ptr1,&local_34,&local_40);
    if (arg1 == 0) {
      Record_GetBounds48((void *)ptr1[0x16],*ptr1,&local_3c,&local_38,&local_48,&local_44);
      Record_GetScreenRect48((void *)ptr1[0x16],*ptr1,(int *)&local_48,(int *)&local_44);
      local_20 = local_48 + local_34;
      local_18 = local_3c + local_20;
      local_1c = local_44 + local_40;
      local_14 = local_1c + local_38;
      if ((ptr1[0x1d] == 0) &&
         (this_00 = *(void **)(*(int *)((intptr_t)self + 4) + 0x2c180 + *(int *)(ptr1[0x1e] + 0xc) * 4)
         , this_00 != (void *)0x0)) {
        value2 = Record_GetValue48((void *)ptr1[0x16],*ptr1);
        Record_SetIndex48(this_00,*(int *)(ptr1[0x1e] + 0x10),value2);
        Record_GetBounds48(this_00,*(int *)(ptr1[0x1e] + 0x10),&local_3c,&local_38,&local_48,
                           &local_44);
        Record_GetScreenRect48
                  (this_00,*(int *)(ptr1[0x1e] + 0x10),(int *)&local_48,(int *)&local_44);
        value2 = local_48 + local_34;
        value4 = local_44 + local_40;
        local_8 = local_3c + value2;
        local_4 = local_38 + value4;
        if (value2 < local_20) {
          local_20 = value2;
        }
        if (local_18 < local_8) {
          local_18 = local_8;
        }
        if (value4 < local_1c) {
          local_1c = value4;
        }
        if (local_14 < local_4) {
          local_14 = local_4;
        }
      }
      value2 = local_20;
      if (((short)ptr1[2] != -1) && ((*(uint8_t *)(ptr1 + 4) & 1) == 0)) {
        local_30 = local_34 - *(int *)((intptr_t)self + 0x24);
        local_2c = local_40 - *(int *)((intptr_t)self + 0x28);
        Record_GetScreenOffset((void *)ptr1[0x16],*ptr1,&local_30,&local_2c);
        Get_WidthHeight(*(void **)(*(int *)((intptr_t)self + 4) + 0x2c3b4),&local_24,&local_28);
        value3 = (local_30 - ((intptr_t)local_24 >> 2)) + *(int *)((intptr_t)self + 0x24);
        value4 = (local_2c - local_28) + -3 + *(int *)((intptr_t)self + 0x28);
        if (value3 < value2) {
          value2 = value3;
        }
        if (local_18 < (intptr_t)(local_24 + value3)) {
          local_18 = local_24 + value3;
        }
        if (value4 < local_1c) {
          local_1c = value4;
        }
        if (local_14 < (intptr_t)(local_28 + value4)) {
          local_14 = local_28 + value4;
        }
      }
      ptr1[0x17] = value2;
      ptr1[0x18] = local_1c;
      ptr1[0x19] = local_18;
      ptr1[0x1a] = local_14;
    }
    if (local_34 != -1) {
      if (ptr1[0x16] == *(int *)(*(int *)((intptr_t)self + 4) + 0x2c3bc)) {
        local_40 = *(int *)(ptr1[0x1d] + 0x98);
      }
      if (ptr1[1] == -1) {
        value2 = local_40 + 0xd0;
        value4 = local_34 + 0xa0;
      }
      else {
        value2 = *(int *)((intptr_t)self + 0xfc) + local_40;
        value4 = *(int *)((intptr_t)self + 0xf8) + local_34;
      }
      value2 = Map_ComputeBlitRect(self,value4,value2,(int *)0x1,0);
      if ((value2 != 0) && (*(int *)(value2 + 8) != 0)) {
        Object_InsertSortedByScreenY(self,value2,ptr1);
      }
    }
  }
  return;
}
