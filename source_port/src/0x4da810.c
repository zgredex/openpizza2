// Player_TrackRecentEntry: ported from Pizza Connection 2 at 0x4da810.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da810
#include "pc2_port.h"

void __thiscall Player_TrackRecentEntry(void *self,int arg1,int arg2)

{
  int value1;
  bool flag2;
  int value3;
  int *ptr4;
  
  value3 = 0;
  flag2 = false;
  ptr4 = (int *)((intptr_t)self + arg1 * 0x18 + 0xfe4);
  do {
    if (*ptr4 == arg2) {
      flag2 = true;
      if (value3 == 0) {
        return;
      }
      value1 = value3 + arg1 * 6;
      *ptr4 = *(int *)((intptr_t)self + value1 * 4 + 0xfe0);
      *(int *)((intptr_t)self + value1 * 4 + 0xfe0) = arg2;
    }
    value3 = value3 + 1;
    ptr4 = ptr4 + 1;
  } while (value3 < 6);
  if (!flag2) {
    *(int *)((intptr_t)self + arg1 * 0x18 + 0xff8) = arg2;
  }
  return;
}
