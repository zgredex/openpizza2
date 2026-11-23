// Game_GetPlayerSatisfactionBand: ported from Pizza Connection 2 at 0x502120.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502120
#include "pc2_port.h"

char Game_GetPlayerSatisfactionBand(void)

{
  int value1;
  
  value1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value1 = (*(int *)(value1 + 0xf8) + *(int *)(value1 + 0xf4) + *(int *)(value1 + 0xf0)) / 3;
  if (0x5a < value1) {
    return '\0';
  }
  if (value1 < 0x47) {
    return (value1 < 0x33) + '\x02';
  }
  return '\x01';
}
