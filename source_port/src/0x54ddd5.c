// CRT_InitFpEnvironment: ported from Pizza Connection 2 at 0x54ddd5.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ddd5
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_InitFpEnvironment(void)

{
  void *extraout_ECX;
  
                    /* Initializes the CRT floating-point conversion table and default precision. */
  CRT_InitFloatCvtTable();
  _DAT_005855d8 = CRT_QueryProcessorFeature();
  CRT_SetDefaultPrecision(extraout_ECX);
  return;
}
