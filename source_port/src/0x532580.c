// UI_Group_SelectMemberByKey: ported from Pizza Connection 2 at 0x532580.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532580
#include "pc2_port.h"

void __thiscall UI_Group_SelectMemberByKey(void *self,int arg1)

{
  int *ptr1;
  int value2;
  int value3;
  int value4;
  
                    /* Selects the option group member corresponding to a control id. */
  value3 = *(int *)((intptr_t)self + 0x158);
  value4 = 0;
  if (0 < value3) {
    while( true ) {
      ptr1 = (int *)Array_GetPtr((void *)((intptr_t)self + 0x148),value4);
      value2 = Array_IndexOfInt(ptr1 + 1,arg1);
      if (value2 != -1) break;
      value4 = value4 + 1;
      if (value3 <= value4) {
        return;
      }
    }
    if (*ptr1 == 3) {
      value2 = value2 + 1;
      if (ptr1[5] <= value2) {
        value2 = 0;
      }
      value3 = Array_GetPtr(ptr1 + 1,value2);
      ptr1 = (int *)Array_GetRecordByKeyPtr(self,value3);
      UI_SetActiveChild(*(void **)((intptr_t)self + 0x134),ptr1);
      UI_SelectObjectRecord(*(void **)((intptr_t)self + 0x134),self,value3);
      return;
    }
    UI_Group_ApplyMemberSelection(self,ptr1,arg1);
  }
  return;
}
