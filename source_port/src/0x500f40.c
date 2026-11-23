// Company_PushRecentEntry: ported from Pizza Connection 2 at 0x500f40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x500f40
#include "pc2_port.h"

void __thiscall Company_PushRecentEntry(void *self,int arg1,int arg2,int arg3,int arg4)

{
  int *ptr1;
  int *ptr2;
  int value3;
  
  if (arg4 == -1) {
    arg4 = 5;
  }
  value3 = 0;
  ptr1 = (int *)((intptr_t)self + arg1 * 0x168 + 0x74);
  ptr2 = ptr1;
  while ((ptr2[3] != arg2 || (*ptr2 != arg3))) {
    value3 = value3 + 1;
    ptr2 = ptr2 + 4;
    if (9 < value3) {
LAB_00500f95:
      _memmove((uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x84),ptr1,0x90);
      *(int *)((intptr_t)self + arg1 * 0x168 + 0x80) = arg2;
      *ptr1 = arg3;
      *(uint16_t *)((intptr_t)self + arg1 * 0x168 + 0x7e) = (uint16_t)arg4;
      return;
    }
  }
  UI_RemoveListEntryAt(self,arg1,value3);
  goto LAB_00500f95;
}
