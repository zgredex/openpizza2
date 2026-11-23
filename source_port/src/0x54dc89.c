// Stream_GetStatus: ported from Pizza Connection 2 at 0x54dc89.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54dc89
#include "pc2_port.h"

int __fastcall Stream_GetStatus(int *arg1)

{
  int value1;
  
  if ((arg1[2] == 0) && (arg1[4] == 0)) {
    value1 = (**(code **)(*arg1 + 0x28))();
    return (-(uint32_t)(value1 != -1) & 2) - 1;
  }
  return 0;
}
