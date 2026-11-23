// RefCount_Release: ported from Pizza Connection 2 at 0x53ef70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53ef70
#include "pc2_port.h"

int RefCount_Release(int *arg1)

{
  int value1;
  
  value1 = arg1[1] + -1;
  arg1[1] = value1;
  if (value1 == 0) {
    if (arg1 != (int *)0x0) {
      (**(code **)(*arg1 + 0xc))(1);
    }
    value1 = 0;
  }
  return value1;
}
