// UI_FindStringRecord: ported from Pizza Connection 2 at 0x527810.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527810
#include "pc2_port.h"

int __thiscall UI_FindStringRecord(void *self,uint8_t *arg1)

{
  int value1;
  
  value1 = StringList_Find(self,arg1,(int *)&arg1);
  if (value1 == 0) {
    return 0;
  }
  return *(int *)((intptr_t)self + 0x82f8) + (intptr_t)arg1 * 0x48;
}
