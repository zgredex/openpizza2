// SoundFormat_Init: ported from Pizza Connection 2 at 0x53f840.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53f840
#include "pc2_port.h"

void SoundFormat_Init(uint16_t *arg1)

{
  arg1[8] = 0;
  *(uint32_t *)(arg1 + 4) = *(int *)(arg1 + 2) * (uint32_t)(uint16_t)arg1[1] * 2;
  *arg1 = 1;
  arg1[7] = 0x10;
  arg1[6] = arg1[1] * 2;
  return;
}
