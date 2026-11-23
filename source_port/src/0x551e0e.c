// CRT_Realloc: ported from Pizza Connection 2 at 0x551e0e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551e0e
#include "pc2_port.h"

int * __cdecl CRT_Realloc(int *arg1,uint32_t *arg2)

{
  int *ptr1;
  uint32_t *uptr2;
  int value3;
  uint32_t *uptr4;
  
  if (arg1 == (int *)0x0) {
    ptr1 = _malloc((size_t)arg2);
  }
  else {
    if (arg2 == (uint32_t *)0x0) {
      CRT_FreeInternal(arg1);
    }
    else {
      do {
        if (arg2 < (uint32_t *)0xffffffe1) {
          CRT_Lock(9);
          uptr2 = (uint32_t *)Heap_FindBlock((intptr_t)arg1);
          if (uptr2 == (uint32_t *)0x0) {
            CS_LeaveIndexed(9);
            if (arg2 == (uint32_t *)0x0) {
              arg2 = (uint32_t *)0x1;
            }
            arg2 = (uint32_t *)((intptr_t)arg2 + 0xfU & 0xfffffff0);
            ptr1 = HeapReAlloc(DAT_00585be0,0,arg1,(SIZE_T)arg2);
          }
          else {
            if (DAT_00577168 < arg2) {
LAB_00551ead:
              if (arg2 == (uint32_t *)0x0) {
                arg2 = (uint32_t *)0x1;
              }
              arg2 = (uint32_t *)((intptr_t)arg2 + 0xfU & 0xfffffff0);
              ptr1 = HeapAlloc(DAT_00585be0,0,(SIZE_T)arg2);
              if (ptr1 != (int *)0x0) {
                uptr4 = (uint32_t *)(arg1[-1] - 1U);
                if (arg2 <= (uint32_t *)(arg1[-1] - 1U)) {
                  uptr4 = arg2;
                }
                _memmove_2(ptr1,arg1,(uint32_t)uptr4);
                CRT_Free(uptr2,(uint32_t)arg1);
              }
            }
            else {
              value3 = CRT_HeapFreeBlock(uptr2,(intptr_t)arg1,(intptr_t)arg2);
              if (value3 == 0) {
                ptr1 = CRT_Malloc(arg2);
                if (ptr1 == (int *)0x0) goto LAB_00551ead;
                uptr4 = (uint32_t *)(arg1[-1] - 1U);
                if (arg2 <= (uint32_t *)(arg1[-1] - 1U)) {
                  uptr4 = arg2;
                }
                _memmove_2(ptr1,arg1,(uint32_t)uptr4);
                CRT_Free(uptr2,(uint32_t)arg1);
              }
              else {
                ptr1 = arg1;
              }
              if (ptr1 == (int *)0x0) goto LAB_00551ead;
            }
            CS_LeaveIndexed(9);
          }
          if (ptr1 != (int *)0x0) {
            return ptr1;
          }
        }
        if (DAT_005858f8 == 0) {
          return (int *)0x0;
        }
        value3 = FUN_00555d41(arg2);
      } while (value3 != 0);
    }
    ptr1 = (int *)0x0;
  }
  return ptr1;
}
