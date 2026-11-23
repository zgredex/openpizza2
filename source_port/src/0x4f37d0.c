// Map_CollectObjectIDsByType: ported from Pizza Connection 2 at 0x4f37d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f37d0
#include "pc2_port.h"

void __thiscall Map_CollectObjectIDsByType(void *self,int arg1,int arg2,int arg3)

{
  uint32_t *uptr1;
  int *ptr2;
  int *ptr3;
  int *ptr4;
  int value5;
  int value6;
  int value7;
  int value8;
  int local_b08;
  int *local_b04;
  int local_b00;
  int local_afc;
  uint32_t *local_af8;
  int local_af4 [100];
  int aiStack_964 [100];
  uint32_t auStack_7d4 [501];
  
  value6 = 0;
  value5 = 0;
  value8 = 0;
  local_b00 = 0;
  local_b08 = 0;
  local_afc = 0;
  if ((arg1 != 0) && (*(LPVOID *)((intptr_t)self + 0x110) != (LPVOID)0x0)) {
    Mem_Free(*(LPVOID *)((intptr_t)self + 0x110));
  }
  if ((arg3 != 0) && (*(LPVOID *)((intptr_t)self + 0x114) != (LPVOID)0x0)) {
    Mem_Free(*(LPVOID *)((intptr_t)self + 0x114));
  }
  if ((arg2 != 0) && (*(LPVOID *)((intptr_t)self + 0x118) != (LPVOID)0x0)) {
    Mem_Free(*(LPVOID *)((intptr_t)self + 0x118));
  }
  if (0 < *(int *)((intptr_t)self + 0x20)) {
    local_af4[0] = *(int *)((intptr_t)self + 0x20);
    do {
      value7 = *(int *)((intptr_t)self + 0x1c);
      if (0 < value7) {
        ptr2 = aiStack_964 + value8 + 1;
        local_af8 = auStack_7d4 + local_b08 + 1;
        local_b04 = (int *)(*(int *)((intptr_t)self + 0x4c) + 8 + value6 * 0xc);
        value6 = local_afc + value7;
        ptr3 = local_af4 + value5 + 1;
        do {
          uptr1 = (uint32_t *)*local_b04;
          ptr4 = ptr3;
          if (uptr1 != (uint32_t *)0x0) {
            value8 = uptr1[1];
            if (value8 == 0x34d) {
              if ((arg1 != 0) && (*(short *)(uptr1 + 9) != -1)) {
                value5 = value5 + 1;
                ptr4 = ptr3 + 1;
                *ptr3 = *(int *)((intptr_t)self + 0x9c) + *(short *)(uptr1 + 9) * 0x28;
              }
            }
            else if (value8 == 0x34f) {
              if ((arg3 != 0) && (*(short *)(uptr1 + 9) != -1)) {
                local_b00 = local_b00 + 1;
                *ptr2 = *(int *)((intptr_t)self + 0x9c) + *(short *)(uptr1 + 9) * 0x28;
                ptr2 = ptr2 + 1;
              }
            }
            else if ((value8 == 0x352) && (arg2 != 0)) {
              *local_af8 = *uptr1;
              local_b08 = local_b08 + 1;
              local_af8 = local_af8 + 1;
            }
          }
          local_b04 = local_b04 + 3;
          value7 = value7 + -1;
          ptr3 = ptr4;
        } while (value7 != 0);
        value8 = local_b00;
        local_afc = value6;
      }
      local_af4[0] = local_af4[0] + -1;
    } while (local_af4[0] != 0);
  }
  if (arg1 != 0) {
    if (value5 < 1) {
      *(uint32_t *)((intptr_t)self + 0x110) = 0;
    }
    else {
      ptr2 = operator_new(value5 * 4 + 4);
      *(int **)((intptr_t)self + 0x110) = ptr2;
      *ptr2 = value5;
      if (0 < value5) {
        value6 = 4;
        do {
          value5 = value5 + -1;
          *(uint32_t *)(value6 + *(int *)((intptr_t)self + 0x110)) =
               (uint32_t)*(uint16_t *)(*(int *)((intptr_t)local_af4 + value6) + 4);
          value6 = value6 + 4;
        } while (value5 != 0);
      }
    }
  }
  if (arg3 != 0) {
    if (value8 < 1) {
      *(uint32_t *)((intptr_t)self + 0x114) = 0;
    }
    else {
      ptr2 = operator_new(value8 * 4 + 4);
      *(int **)((intptr_t)self + 0x114) = ptr2;
      *ptr2 = value8;
      if (0 < value8) {
        value6 = 4;
        do {
          value8 = value8 + -1;
          *(uint32_t *)(value6 + *(int *)((intptr_t)self + 0x114)) =
               (uint32_t)*(uint16_t *)(*(int *)((intptr_t)aiStack_964 + value6) + 4);
          value6 = value6 + 4;
        } while (value8 != 0);
      }
    }
  }
  if ((arg2 != 0) && (0 < local_b08)) {
    ptr2 = operator_new(local_b08 * 4 + 4);
    *(int **)((intptr_t)self + 0x118) = ptr2;
    *ptr2 = local_b08;
    if (0 < local_b08) {
      value8 = 4;
      do {
        *(uint32_t *)(*(int *)((intptr_t)self + 0x118) + value8) =
             *(uint32_t *)((intptr_t)auStack_7d4 + value8);
        value8 = value8 + 4;
        local_b08 = local_b08 + -1;
      } while (local_b08 != 0);
    }
  }
  return;
}
