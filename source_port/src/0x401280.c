// NamedLockable_Construct: ported from Pizza Connection 2 at 0x401280.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401280
#include "pc2_port.h"

uint32_t * __thiscall NamedLockable_Construct(void *self,char *arg1)

{
  char cVar1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  char *cptr4;
  char *cptr5;
  
                    /* Constructs a named critical-section wrapper and copies its name. */
  *(uint8_t ***)self = &PTR_NamedLockable_Delete_0055c2e8;
  InitializeCriticalSection((LPCRITICAL_SECTION)((intptr_t)self + 4));
  if (arg1 == (char *)0x0) {
    arg1 = s____no_name____005630ec;
  }
  uvalue2 = 0xffffffff;
  do {
    cptr4 = arg1;
    if (uvalue2 == 0) break;
    uvalue2 = uvalue2 - 1;
    cptr4 = arg1 + 1;
    cVar1 = *arg1;
    arg1 = cptr4;
  } while (cVar1 != '\0');
  uvalue2 = ~uvalue2;
  cptr4 = cptr4 + -uvalue2;
  cptr5 = (char *)((intptr_t)self + 0x1c);
  for (uvalue3 = uvalue2 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *(uint32_t *)cptr5 = *(uint32_t *)cptr4;
    cptr4 = cptr4 + 4;
    cptr5 = cptr5 + 4;
  }
  for (uvalue2 = uvalue2 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
    *cptr5 = *cptr4;
    cptr4 = cptr4 + 1;
    cptr5 = cptr5 + 1;
  }
  *(uint32_t *)((intptr_t)self + 0x54) = 0;
  *(uint32_t *)((intptr_t)self + 0x50) = 0;
  return self;
}
