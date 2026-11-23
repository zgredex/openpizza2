// UI_AddSelectionGroup: ported from Pizza Connection 2 at 0x532400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532400
#include "pc2_port.h"


int __thiscall UI_AddSelectionGroup(void *self,int arg1,int arg2,int *arg3)

{
  int *ptr1;
  int value2;
  int value3;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Creates and registers a UI selection group. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ac4b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  ptr1 = operator_new(0x18);
  value3 = 0;
  local_4 = 0;
  if (ptr1 == (int *)0x0) {
    ptr1 = (int *)0x0;
  }
  else {
    Array_Construct(ptr1 + 1,0);
  }
  value2 = -1;
  local_4 = 0xffffffff;
  if (0 < arg2) {
    if (0 < arg2) {
      do {
        if (*arg3 == -1) break;
        Array_InsertGrow(ptr1 + 1,*arg3);
        value3 = value3 + 1;
        arg3 = arg3 + 1;
      } while (value3 < arg2);
    }
    *ptr1 = arg1;
    value2 = Array_InsertGrow((void *)((intptr_t)self + 0x148),ptr1);
    UI_Group_ApplyMemberSelection(self,ptr1,-1);
  }
  ExceptionList = local_c;
  return value2;
}
