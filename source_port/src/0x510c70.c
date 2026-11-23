// Output_StorePair: ported from Pizza Connection 2 at 0x510c70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x510c70
#include "pc2_port.h"

void Output_StorePair(uint32_t *arg1,uint32_t *arg2,uint32_t arg3,uint32_t arg4)

{
  *arg1 = arg3;
  *arg2 = arg4;
  return;
}
