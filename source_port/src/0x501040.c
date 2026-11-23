// UI_RemoveListEntryByType: ported from Pizza Connection 2 at 0x501040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501040
#include "pc2_port.h"

void __thiscall UI_RemoveListEntryByType(void *self,int arg1,int arg2,int arg3)

{
  int value1;
  int *ptr2;
  
  if (arg2 == 2) {
    value1 = 0;
    ptr2 = (int *)((intptr_t)self + arg1 * 0x168 + 0x74);
    do {
      if (*ptr2 == arg3) {
        UI_RemoveListEntryAt(self,arg1,value1);
        return;
      }
      value1 = value1 + 1;
      ptr2 = ptr2 + 4;
    } while (value1 < 10);
  }
  value1 = 0;
  ptr2 = (int *)((intptr_t)self + arg1 * 0x168 + 0x74);
  while ((ptr2[3] != arg2 || (*ptr2 != arg3))) {
    value1 = value1 + 1;
    ptr2 = ptr2 + 4;
    if (9 < value1) {
      return;
    }
  }
  UI_RemoveListEntryAt(self,arg1,value1);
  return;
}
