// UI_FindObjectByField20: ported from Pizza Connection 2 at 0x47e1d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47e1d0
#include "pc2_port.h"

int __thiscall UI_FindObjectByField20(void *self,int arg1)

{
  int value1;
  int value2;
  
  value2 = 0;
  value1 = Get_Field19F4((intptr_t)self);
  if (0 < value1) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x19e0),value2,(int *)0x0);
      if ((value1 != 0) && (*(int *)(value1 + 0x20) == arg1)) {
        return value1;
      }
      value2 = value2 + 1;
      value1 = Get_Field19F4((intptr_t)self);
    } while (value2 < value1);
  }
  return 0;
}
