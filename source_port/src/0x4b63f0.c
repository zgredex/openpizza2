// StaffCosts_UpdatePage: ported from Pizza Connection 2 at 0x4b63f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b63f0
#include "pc2_port.h"

void __cdecl StaffCosts_UpdatePage(void *arg1)

{
                    /* Refreshes the staff-cost page labels. */
  AnnoyancesPage_FillCosts(arg1);
  return;
}
