// Game_GetPlayerSlotByOrdinal: ported from Pizza Connection 2 at 0x4a4190.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a4190
#include "pc2_port.h"

int __cdecl Game_GetPlayerSlotByOrdinal(int arg1)

{
  int value1;
  int value2;
  int *ptr3;
  int value4;
  
  value2 = 0;
  if (DAT_0057d248 < 6) {
    ptr3 = &DAT_0057d24c + DAT_0057d248;
    value4 = DAT_0057d248;
    do {
      value1 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
      if ((value4 != value1) && (*ptr3 != 0)) {
        if (arg1 == value2) {
          return value4;
        }
        value2 = value2 + 1;
      }
      ptr3 = ptr3 + 1;
      value4 = value4 + 1;
    } while ((intptr_t)ptr3 < 0x57d264);
  }
  return value2;
}
