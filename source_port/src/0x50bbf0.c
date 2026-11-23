// Object_ClearAssignedRecord: ported from Pizza Connection 2 at 0x50bbf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50bbf0
#include "pc2_port.h"

uint32_t __thiscall Object_ClearAssignedRecord(void *self,void *arg1)

{
  int *ptr1;
  
  if (*(int *)((intptr_t)self + 0xa4) == 4) {
    ptr1 = (int *)RecordMap_Lookup1998(arg1,*(int *)((intptr_t)self + 0x88));
    if ((ptr1 != (int *)0x0) && (0 < *ptr1)) {
      Object_SetFieldA4Locked(self,0xffffffff);
      *ptr1 = 0;
      return 1;
    }
  }
  return 0;
}
