// UI_Group_Create: ported from Pizza Connection 2 at 0x532330.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532330
#include "pc2_port.h"


int __cdecl UI_Group_Create(void *arg1,int arg2,int arg3,uint32_t arg4)

{
  int *ptr1;
  int *ptr2;
  int value3;
  uint32_t *uptr4;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Creates and applies a UI child selection group. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ac2b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  ptr2 = operator_new(0x18);
  local_4 = 0;
  if (ptr2 == (int *)0x0) {
    ptr2 = (int *)0x0;
  }
  else {
    Array_Construct(ptr2 + 1,0);
  }
  value3 = -1;
  local_4 = 0xffffffff;
  if (0 < arg3) {
    Array_InsertGrow(ptr2 + 1,arg4);
    value3 = 1;
    if (1 < arg3) {
      uptr4 = &arg4;
      do {
        ptr1 = uptr4 + 1;
        uptr4 = uptr4 + 1;
        if (*ptr1 == -1) break;
        Array_InsertGrow(ptr2 + 1,*ptr1);
        value3 = value3 + 1;
      } while (value3 < arg3);
    }
    *ptr2 = arg2;
    value3 = Array_InsertGrow((void *)((intptr_t)arg1 + 0x148),ptr2);
    UI_Group_ApplyMemberSelection(arg1,ptr2,-1);
  }
  ExceptionList = local_c;
  return value3;
}
