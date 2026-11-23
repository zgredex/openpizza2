// Company_DispatchWorkerToBranch: ported from Pizza Connection 2 at 0x4fe300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fe300
#include "pc2_port.h"

uint32_t Company_DispatchWorkerToBranch(int arg1,int arg2)

{
  void *self;
  int value1;
  void *this_00;
  int value2;
  
                    /* Sends an idle HQ worker to a branch. */
  self = *(void **)(arg1 + 0x1d8);
  value2 = 0;
  value1 = *(int *)((intptr_t)self + 0x8c);
  if (0 < value1) {
    do {
      this_00 = (void *)Game_MapRecordToGlobal(self,value2);
      if (*(int *)((intptr_t)this_00 + 0x30) == 0x17) {
        Object_SetFieldA4Locked(this_00,0x12);
        Object_SetDestinationAndTarget(this_00,1,*(int *)(arg2 + 0x16f0));
        *(uint32_t *)((intptr_t)this_00 + 0x10c) = *(uint32_t *)(arg2 + 0x3c);
        return 1;
      }
      value2 = value2 + 1;
    } while (value2 < value1);
  }
  return 0;
}
