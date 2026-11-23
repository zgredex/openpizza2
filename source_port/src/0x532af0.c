// UI_NotifyObjectsByKey: ported from Pizza Connection 2 at 0x532af0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532af0
#include "pc2_port.h"

uint32_t __thiscall UI_NotifyObjectsByKey(void *self,int arg1)

{
  int value1;
  int *ptr2;
  uint32_t uvalue3;
  int value4;
  
  uvalue3 = 0;
  value4 = 0;
  value1 = *(int *)((intptr_t)self + 0x2b8);
  if (value1 < 1) {
    return 0;
  }
  do {
    ptr2 = (int *)Array_GetPtr((void *)((intptr_t)self + 0x2a8),value4);
    if (((ptr2 != (int *)0x0) && (ptr2[1] == arg1)) &&
       (ptr2 = (int *)Array_GetRecordByKey(self,*ptr2), ptr2 != (int *)0x0)) {
      (**(code **)(*ptr2 + 0xc))(0x3b,arg1,0);
      uvalue3 = 1;
    }
    value4 = value4 + 1;
  } while (value4 < value1);
  return uvalue3;
}
