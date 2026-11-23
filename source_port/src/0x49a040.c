// Game_IsCompanyNameTaken: ported from Pizza Connection 2 at 0x49a040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49a040
#include "pc2_port.h"

uint32_t __cdecl Game_IsCompanyNameTaken(uint8_t *arg1)

{
  uint8_t flag1;
  int value2;
  int value3;
  uint8_t *bptr4;
  uint8_t *bptr5;
  int value6;
  bool flag7;
  
  value6 = 0;
  value2 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  if ((intptr_t)*(uint32_t *)(value2 + 0x124) < 1) {
    return *(uint32_t *)(value2 + 0x124) & 0xffffff00;
  }
  do {
    value3 = IDMap_Lookup((void *)(value2 + 0x110),value6,(int *)0x0);
    if (value3 != *(int *)(DAT_0057c670 + 0x98)) {
      bptr4 = (uint8_t *)(value3 + 4);
      bptr5 = arg1;
      do {
        flag1 = *bptr4;
        flag7 = flag1 < *bptr5;
        if (flag1 != *bptr5) {
LAB_0049a0ad:
          value3 = (1 - (uint32_t)flag7) - (uint32_t)(flag7 != 0);
          goto LAB_0049a0b2;
        }
        if (flag1 == 0) break;
        flag1 = bptr4[1];
        flag7 = flag1 < bptr5[1];
        if (flag1 != bptr5[1]) goto LAB_0049a0ad;
        bptr4 = bptr4 + 2;
        bptr5 = bptr5 + 2;
      } while (flag1 != 0);
      value3 = 0;
LAB_0049a0b2:
      if (value3 == 0) {
        return 1;
      }
    }
    value6 = value6 + 1;
    if ((intptr_t)*(uint32_t *)(value2 + 0x124) <= value6) {
      return *(uint32_t *)(value2 + 0x124) & 0xffffff00;
    }
  } while( true );
}
