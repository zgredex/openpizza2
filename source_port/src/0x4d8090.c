// Game_GetMostAdvancedCompany: ported from Pizza Connection 2 at 0x4d8090.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d8090
#include "pc2_port.h"

int __fastcall Game_GetMostAdvancedCompany(int arg1)

{
  int value1;
  int value2;
  uint32_t *uptr3;
  uint32_t uvalue4;
  
  if (*(int *)(*(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8) + 0xf8) != 0) {
    value1 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
    return value1;
  }
  uvalue4 = 0;
  value1 = -1;
  value2 = 0;
  uptr3 = (uint32_t *)(arg1 + 0xdac);
  do {
    if (uvalue4 < *uptr3) {
      value1 = value2;
      uvalue4 = *uptr3;
    }
    value2 = value2 + 1;
    uptr3 = uptr3 + 1;
  } while (value2 < 6);
  return value1;
}
