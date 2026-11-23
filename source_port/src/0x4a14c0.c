// SaveGame_CompareTime: ported from Pizza Connection 2 at 0x4a14c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a14c0
#include "pc2_port.h"

int __cdecl SaveGame_CompareTime(uint16_t *arg1,uint16_t *arg2)

{
  if (*arg2 < *arg1) {
    return 1;
  }
  if (*arg1 < *arg2) {
    return -1;
  }
  if (arg2[1] < arg1[1]) {
    return 1;
  }
  if (arg1[1] < arg2[1]) {
    return -1;
  }
  if (arg2[3] < arg1[3]) {
    return 1;
  }
  if (arg1[3] < arg2[3]) {
    return -1;
  }
  if (arg2[4] < arg1[4]) {
    return 1;
  }
  if (arg1[4] < arg2[4]) {
    return -1;
  }
  if (arg2[5] < arg1[5]) {
    return 1;
  }
  if (arg1[5] < arg2[5]) {
    return -1;
  }
  if (arg2[6] < arg1[6]) {
    return 1;
  }
  return -(uint32_t)(arg1[6] < arg2[6]);
}
