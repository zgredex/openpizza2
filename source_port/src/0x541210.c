// SoundBuffer_Configure: ported from Pizza Connection 2 at 0x541210.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541210
#include "pc2_port.h"

uint32_t SoundBuffer_Configure(int *arg1,char arg2)

{
  uint32_t local_14 [5];
  
  local_14[0] = 0x14;
  (**(code **)(*arg1 + 0xc))(arg1,local_14);
  (**(code **)(*arg1 + 0x30))(arg1,0,0,arg2 != '\0');
  return 0;
}
