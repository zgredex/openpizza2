// Thread_InitLocks: ported from Pizza Connection 2 at 0x553934.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553934
#include "pc2_port.h"

void Thread_InitLocks(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_00576eb4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_00576ea4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_00576e94);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_00576e74);
  return;
}
