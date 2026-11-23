// Building_GetLevelFromType: ported from Pizza Connection 2 at 0x4f9d50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f9d50
#include "pc2_port.h"

uint32_t Building_GetLevelFromType(int arg1)

{
  char cVar1;
  
  switch(*(uint32_t *)(arg1 + 0x10)) {
  case 0:
    if (*(uint8_t *)(arg1 + 0x14) < 2) {
      return 1;
    }
    if (*(uint8_t *)(arg1 + 0x14) == 2) {
      return 2;
    }
    break;
  case 1:
    cVar1 = *(char *)(arg1 + 0x14);
    if (cVar1 == '\0') {
      return 1;
    }
    if (cVar1 == '\x01') {
      return 2;
    }
    if (cVar1 == '\x02') {
      return 3;
    }
    break;
  case 2:
    cVar1 = *(char *)(arg1 + 0x14);
    if (cVar1 == '\0') {
      return 2;
    }
    if (cVar1 == '\x01') {
      return 3;
    }
    if (cVar1 == '\x02') {
      return 4;
    }
    break;
  case 3:
    cVar1 = *(char *)(arg1 + 0x14);
    if (cVar1 == '\0') {
      return 3;
    }
    if (cVar1 == '\x01') {
      return 4;
    }
    if (cVar1 == '\x02') {
      return 5;
    }
  }
  return 0xffffffff;
}
