// Pak_DecodeIndex: ported from Pizza Connection 2 at 0x401f30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401f30
#include "pc2_port.h"

void Pak_DecodeIndex(int arg1,int arg2)

{
  int value1;
  
  value1 = 0;
  if (0 < arg2) {
    do {
      *(uint8_t *)(value1 + arg1) = *(char *)(value1 + arg1) - (char)value1 ^ 0xaa;
      value1 = value1 + 1;
    } while (value1 < arg2);
  }
  return;
}
