// Sprite_ClearBuffers: ported from Pizza Connection 2 at 0x53a060.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53a060
#include "pc2_port.h"

void Sprite_ClearBuffers(int *arg1)

{
  int value1;
  uint32_t *uptr2;
  uint8_t auStack_de [14];
  uint32_t local_d0 [25];
  uint32_t auStack_6c [27];
  
  uptr2 = local_d0;
  for (value1 = 0x1b; value1 != 0; value1 = value1 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  local_d0[0] = 0x6c;
  local_d0[1] = 6;
  (**(code **)(*arg1 + 0x58))(arg1,local_d0);
  uptr2 = auStack_6c;
  for (value1 = 0x19; value1 != 0; value1 = value1 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  auStack_6c[0] = 100;
  (**(code **)(*arg1 + 0x14))(arg1,auStack_de + -10,0,auStack_de + -10,0x1000400,auStack_6c);
  return;
}
