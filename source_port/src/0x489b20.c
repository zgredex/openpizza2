// City_IndexOfListValue: ported from Pizza Connection 2 at 0x489b20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x489b20
#include "pc2_port.h"

int __thiscall City_IndexOfListValue(void *self,int arg1,int arg2,int arg3)

{
  void *this_00;
  int value1;
  
  this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x74),arg2,(int *)0x0);
  if (this_00 == (void *)0x0) {
    return -1;
  }
  value1 = Game_FindGroupSlot(this_00,arg1,arg3);
  return value1;
}
