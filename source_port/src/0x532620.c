// UI_Group_ApplyMemberSelection: ported from Pizza Connection 2 at 0x532620.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532620
#include "pc2_port.h"

void __thiscall UI_Group_ApplyMemberSelection(void *self,int *arg1,int arg2)

{
  int value1;
  int value2;
  int *ptr3;
  int value4;
  int value5;
  int unaff_ESI;
  int iStack_4;
  
  value1 = arg2;
joined_r0x0053263c:
  do {
    while( true ) {
      if (value1 != -1) {
        value4 = *arg1;
        if ((value4 == 0) || (value4 == 1)) {
          ptr3 = (int *)Window_GetGadgetChecked(self,value1);
          value4 = (**(code **)(*ptr3 + 0xc))(2,0,0);
          if (value4 == 0) {
            UI_ClearPendingCommand(ptr3);
            return;
          }
          value4 = arg1[5];
          iStack_4 = 0;
          if (0 < value4) {
            do {
              value5 = Array_GetPtr(arg1 + 1,iStack_4);
              ptr3 = (int *)Window_GetGadgetChecked(self,value5);
              if (value5 == value1) {
                if (unaff_ESI != 0) {
                  Object_EnsureInit(ptr3);
                }
              }
              else {
                (**(code **)(*ptr3 + 0xc))(2,0,0);
                (**(code **)(*ptr3 + 0xc))(0,0,0);
                if (unaff_ESI != 0) {
                  UI_ClearPendingCommand(ptr3);
                }
              }
              iStack_4 = iStack_4 + 1;
            } while (iStack_4 < value4);
          }
        }
        else {
          if (value4 != 2) {
            return;
          }
          value4 = arg1[5];
          arg2 = 0;
          if (0 < value4) {
            do {
              value5 = Array_GetPtr(arg1 + 1,arg2);
              value2 = Window_GetGadgetChecked(self,value5);
              if (value5 != value1) {
                UI_ClearPendingClipFlag(value2);
              }
              arg2 = arg2 + 1;
            } while (arg2 < value4);
          }
        }
        *(uint32_t *)(*(int *)((intptr_t)self + 0x134) + 0x1b8) = 1;
        return;
      }
      if (*arg1 == 0) break;
      if (*arg1 != 2) {
        return;
      }
      value4 = arg1[5];
      value5 = 0;
      while( true ) {
        if (value4 <= value5) {
          value1 = Array_GetPtr(arg1 + 1,0);
          value1 = Window_GetGadgetChecked(self,value1);
          UI_Child_Activate(value1);
          return;
        }
        value1 = Array_GetPtr(arg1 + 1,value5);
        value2 = Window_GetGadgetChecked(self,value1);
        if (*(int *)(value2 + 0x20) != 0) break;
        value5 = value5 + 1;
      }
    }
    value4 = arg1[5];
    value5 = 0;
    if (0 < value4) {
      do {
        value1 = Array_GetPtr(arg1 + 1,value5);
        ptr3 = (int *)Window_GetGadgetChecked(self,value1);
        value2 = (**(code **)(*ptr3 + 0xc))(2,0,0);
        if (value2 == 1) goto joined_r0x0053263c;
        value5 = value5 + 1;
      } while (value5 < value4);
    }
    value1 = Array_GetPtr(arg1 + 1,0);
    ptr3 = (int *)Window_GetGadgetChecked(self,value1);
    (**(code **)(*ptr3 + 0xc))(0,1,0);
  } while( true );
}
