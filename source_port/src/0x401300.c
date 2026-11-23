// NamedLockable_Destroy: ported from Pizza Connection 2 at 0x401300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401300
#include "pc2_port.h"

void __fastcall NamedLockable_Destroy(uint32_t *arg1)

{
                    /* Destroys a named critical-section wrapper. */
  *arg1 = &PTR_NamedLockable_Delete_0055c2e8;
  DeleteCriticalSection((LPCRITICAL_SECTION)(arg1 + 1));
  return;
}
