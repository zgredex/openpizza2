// AnimCritical_Init: ported from Pizza Connection 2 at 0x532bf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532bf0
#include "pc2_port.h"

void AnimCritical_Init(void)

{
                    /* Constructs the global AnimCritical named lock. */
  NamedLockable_Construct(&DAT_005842a0,s_AnimCritical_005744e0);
  return;
}
