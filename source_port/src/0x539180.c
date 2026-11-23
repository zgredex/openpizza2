// Surface_IsReady: ported from Pizza Connection 2 at 0x539180.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539180
#include "pc2_port.h"

bool Surface_IsReady(int *arg1)

{
  int value1;
  
  value1 = (**(code **)(*arg1 + 0x80))(arg1,0);
  return (bool)('\x01' - (value1 != 0));
}
