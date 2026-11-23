// StreamBuffer_Reset: ported from Pizza Connection 2 at 0x53f820.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53f820
#include "pc2_port.h"

uint32_t StreamBuffer_Reset(uint32_t *arg1)

{
  *arg1 = 0;
  arg1[1] = 0;
  arg1[2] = 0;
  arg1[3] = 0;
  *arg1 = 0;
  return 1;
}
