// ResourceIterator_Init: ported from Pizza Connection 2 at 0x401f60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401f60
#include "pc2_port.h"

void __thiscall ResourceIterator_Init(void *self,char *arg1)

{
  arg1[0x114] = '\0';
  arg1[0x115] = '\0';
  arg1[0x116] = '\0';
  arg1[0x117] = '\0';
  arg1[0x118] = -1;
  arg1[0x119] = -1;
  arg1[0x11a] = -1;
  arg1[0x11b] = -1;
  ResourceIterator_Next(self,arg1);
  return;
}
