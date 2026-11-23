// CompanyMenu_InitPolicePage: ported from Pizza Connection 2 at 0x4aa690.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4aa690
#include "pc2_port.h"

void __cdecl CompanyMenu_InitPolicePage(void *arg1)

{
                    /* Initializes the police/bodyguard company page. */
  Window_UpdatePolicePage(arg1);
  return;
}
