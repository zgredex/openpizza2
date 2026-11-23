// CRT_LocalUnwind2: ported from Pizza Connection 2 at 0x553c9d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553c9d
#include "pc2_port.h"

void CRT_LocalUnwind2(int arg1)

{
  __local_unwind2(*(int *)(arg1 + 0x18),*(int *)(arg1 + 0x1c));
  return;
}
