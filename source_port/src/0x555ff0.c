// FUN_00555ff0: ported from Pizza Connection 2 at 0x555ff0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555ff0
#include "pc2_port.h"

int __cdecl FUN_00555ff0(uint8_t *arg1,uint8_t *arg2)

{
  uint8_t flag1;
  int value2;
  uint8_t abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    flag1 = *arg2;
    if (flag1 == 0) break;
    arg2 = arg2 + 1;
    abStack_28[(intptr_t)(uint32_t)flag1 >> 3] = abStack_28[(intptr_t)(uint32_t)flag1 >> 3] | '\x01' << (flag1 & 7);
  }
  value2 = -1;
  do {
    value2 = value2 + 1;
    flag1 = *arg1;
    if (flag1 == 0) {
      return value2;
    }
    arg1 = arg1 + 1;
  } while ((abStack_28[(intptr_t)(uint32_t)flag1 >> 3] >> (flag1 & 7) & 1) == 0);
  return value2;
}
