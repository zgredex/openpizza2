// AnimSwapCritical_Init: ported from Pizza Connection 2 at 0x532bb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532bb0
#include "pc2_port.h"

void AnimSwapCritical_Init(void)

{
                    /* Constructs the global AnimSwapCritical named lock. */
  NamedLockable_Construct(&DAT_00584248,s_AnimSwapCritical_005744cc);
  return;
}
