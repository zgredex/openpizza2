// MapActor_UpdateLinkedOverlays: ported from Pizza Connection 2 at 0x4f1b60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f1b60
#include "pc2_port.h"

int __thiscall MapActor_UpdateLinkedOverlays(void *self,int *arg1)

{
  int *ptr1;
  int value2;
  int value3;
  int value4;
  int local_8;
  int local_4;
  
                    /* Maintains a map actor's linked overlay slots and idle release. */
  ptr1 = arg1;
  value2 = 0;
  value3 = 0;
  value4 = 0;
  local_8 = 0;
  local_4 = 0;
  if (arg1[1] == -1) {
    arg1[0x15] = arg1[0x15] + 1;
    if (-1 < arg1[0xe]) {
      value3 = *(int *)((intptr_t)self + 0x4c) + arg1[0xe] * 0xc;
    }
    if (-1 < arg1[0xf]) {
      value4 = *(int *)((intptr_t)self + 0x4c) + arg1[0xf] * 0xc;
    }
    if (-1 < arg1[0x13]) {
      local_8 = *(int *)((intptr_t)self + 0x4c) + arg1[0x13] * 0xc;
    }
    if (-1 < arg1[0x14]) {
      local_4 = *(int *)((intptr_t)self + 0x4c) + arg1[0x14] * 0xc;
    }
    if (value3 != 0) {
      if (*(int *)(*(int *)(value3 + 8) + 0x34) == 0) {
        arg1[0xe] = -1;
        Record_SelectVariant((void *)arg1[0x16],*arg1,arg1[3]);
        ptr1[0x10] = -1;
        value2 = 0;
      }
      else {
        value2 = 1;
      }
    }
    if (value4 != 0) {
      if (*(int *)(*(int *)(value4 + 8) + 0x34) == 0) {
        ptr1[0xf] = -1;
        Record_SelectVariant((void *)ptr1[0x16],*ptr1,ptr1[3]);
        ptr1[0x10] = -1;
        value2 = 0;
      }
      else {
        value2 = 1;
      }
    }
    if (local_8 != 0) {
      value3 = Object_CanAssignSlot(local_8,(intptr_t)ptr1,ptr1 + 0x13,&arg1);
      if (value3 == 0) {
        if (arg1 == (int *)0x0) {
          Record_SelectVariant((void *)ptr1[0x16],*ptr1,ptr1[3]);
        }
        ptr1[0x10] = -1;
        value2 = 0;
      }
      else {
        value2 = 1;
      }
    }
    if (local_4 == 0) {
      if (value2 != 0) {
        return value2;
      }
    }
    else {
      value3 = Object_CanAssignSlot(local_4,(intptr_t)ptr1,ptr1 + 0x14,&arg1);
      if (value3 != 0) {
        return 1;
      }
      if (arg1 == (int *)0x0) {
        Record_SelectVariant((void *)ptr1[0x16],*ptr1,ptr1[3]);
      }
      ptr1[0x10] = -1;
    }
    value3 = ptr1[0x15];
    ptr1[0x15] = -1;
    if (200 < value3) {
      Object_ClearSlotRefs(self,(intptr_t)ptr1);
      MapActor_RelocateToRandomTile((void *)ptr1[0x1e]);
      return 1;
    }
  }
  else {
    if (-1 < arg1[0xe]) {
      value3 = *(int *)((intptr_t)self + 0x4c) + arg1[0xe] * 0xc;
    }
    if (-1 < arg1[0xf]) {
      value4 = *(int *)((intptr_t)self + 0x4c) + arg1[0xf] * 0xc;
    }
    if ((value3 != 0) && (*(int *)(*(int *)(value3 + 8) + 0x30) == 0)) {
      arg1[0xe] = -1;
      Record_SelectVariant((void *)arg1[0x16],*arg1,arg1[3]);
      ptr1[0x10] = -1;
    }
    if ((value4 != 0) && (*(int *)(*(int *)(value4 + 8) + 0x30) == 0)) {
      ptr1[0xf] = -1;
      Record_SelectVariant((void *)ptr1[0x16],*ptr1,ptr1[3]);
      ptr1[0x10] = -1;
    }
  }
  return 0;
}
