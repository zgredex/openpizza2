// Sound_ClampGlobalLimits: ported from Pizza Connection 2 at 0x547230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547230
#include "pc2_port.h"

void Sound_ClampGlobalLimits(void)

{
  if (10000 < DAT_00575094) {
    DAT_00575094 = 10000;
  }
  if (10000 < DAT_00575098) {
    DAT_00575098 = 5000;
  }
  if (10000 < DAT_0057509c) {
    DAT_0057509c = 5000;
  }
  return;
}
