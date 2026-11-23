// Stream_PeekChar: ported from Pizza Connection 2 at 0x54d3be.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d3be
#include "pc2_port.h"

int __fastcall Stream_PeekChar(int *arg1)

{
  int value1;
  
  if (arg1[2] == 0) {
    value1 = (**(code **)(*arg1 + 0x20))();
    return value1;
  }
  if (arg1[3] == -1) {
    value1 = (**(code **)(*arg1 + 0x20))();
    arg1[3] = value1;
  }
  return arg1[3];
}
