// String_RegisterSlot: ported from Pizza Connection 2 at 0x403750.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403750
#include "pc2_port.h"

int __cdecl String_RegisterSlot(uint32_t arg1)

{
  int value1;
  int *ptr2;
  
  if (DAT_0057b558 != 0) {
    value1 = 0;
    ptr2 = &DAT_00579ffc;
    do {
      if ((uint8_t *)*ptr2 == PTR_s_unknown_0056376b_1_00563364) {
        (&DAT_00579ffc)[value1] = arg1;
        return value1;
      }
      ptr2 = ptr2 + 1;
      value1 = value1 + 1;
    } while ((intptr_t)ptr2 < 0x57a18c);
  }
  return 99;
}
