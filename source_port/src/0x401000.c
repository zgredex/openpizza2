// StatsPeriodReport_StreamConstruct: ported from Pizza Connection 2 at 0x401000.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401000
#include "pc2_port.h"

uint32_t * __thiscall StatsPeriodReport_StreamConstruct(void *self,void *arg1)

{
  *(uint8_t ***)self = &PTR_StatsPeriodReport_Delete_0055c2e0;
  if (arg1 != (void *)0x0) {
    StatsPeriodReport_Load(self,arg1);
  }
  return self;
}
