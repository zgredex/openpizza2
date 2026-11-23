// EmployeeAvatar_Delete: ported from Pizza Connection 2 at 0x54b620.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b620
#include "pc2_port.h"

uint32_t * __thiscall EmployeeAvatar_Delete(void *self,uint8_t arg1)

{
  EmployeeAvatar_Destroy(self);
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
