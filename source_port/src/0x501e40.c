// Game_GetActivityVolumeBand: ported from Pizza Connection 2 at 0x501e40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x501e40
#include "pc2_port.h"

uint8_t Game_GetActivityVolumeBand(void)

{
  void *self;
  int value1;
  int value2;
  int value3;
  
  self = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value1 = Game_CountActiveObjectsByType(self,0x1f);
  value2 = Game_CountActiveObjectsByType(self,0x1e);
  value3 = Game_CountActiveObjectsByType(self,0x1d);
  value3 = value1 + value2 + value3;
  if (0x14 < value3) {
    return 3;
  }
  if (value3 < 0xb) {
    return 4 < value3;
  }
  return 2;
}
