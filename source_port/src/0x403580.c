// ResetScreenRegistry: ported from Pizza Connection 2 at 0x403580.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403580
#include "pc2_port.h"

void ResetScreenRegistry(void)

{
  uint8_t *uptr1;
  int value2;
  uint32_t *uptr3;
  
  uptr1 = PTR_s_unknown_0056376b_1_00563364;
  uptr3 = &DAT_00579ffc;
  for (value2 = 100; value2 != 0; value2 = value2 + -1) {
    *uptr3 = uptr1;
    uptr3 = uptr3 + 1;
  }
  uptr3 = &DAT_00579e68;
  for (value2 = 100; value2 != 0; value2 = value2 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  uptr3 = &DAT_0057b31c;
  for (value2 = 100; value2 != 0; value2 = value2 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  uptr3 = &DAT_0057a18c;
  for (value2 = 100; value2 != 0; value2 = value2 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  uptr3 = &DAT_00579b48;
  for (value2 = 100; value2 != 0; value2 = value2 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  return;
}
