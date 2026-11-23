// FUN_005558bd: ported from Pizza Connection 2 at 0x5558bd.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5558bd
#include "pc2_port.h"

uint32_t __cdecl FUN_005558bd(int *arg1)

{
  int value1;
  
  value1 = 0;
  do {
    if (*arg1 != 0) {
      return 0;
    }
    value1 = value1 + 1;
    arg1 = arg1 + 1;
  } while (value1 < 3);
  return 1;
}
