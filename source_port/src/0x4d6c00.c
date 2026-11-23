// City_RemovePersonEntry: ported from Pizza Connection 2 at 0x4d6c00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d6c00
#include "pc2_port.h"

void __thiscall City_RemovePersonEntry(void *self,int *arg1)

{
  City_RemovePersonAndMaintainPopulation(self,*arg1);
  return;
}
