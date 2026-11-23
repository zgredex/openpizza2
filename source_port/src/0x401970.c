// ResourceManager_Construct: ported from Pizza Connection 2 at 0x401970.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401970
#include "pc2_port.h"

uint32_t * __fastcall ResourceManager_Construct(uint32_t *arg1)

{
  char cVar1;
  uint32_t *uptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int value5;
  char *cptr6;
  char *cptr7;
  
                    /* Constructs a resource manager and its named lock. */
  NamedLockable_Construct(arg1 + 0x5a2,(char *)0x0);
  uvalue3 = 0xffffffff;
  *arg1 = &PTR_ResourceManager_ScalarDeletingDestructor_0055c2f0;
  arg1[0x6af] = 0xffffffff;
  arg1[0x6b0] = 0;
  arg1[0x5a1] = 0;
  arg1[0x6ae] = 1;
  *(uint8_t *)(arg1 + 0x66c) = 0;
  cptr6 = s_loadclass_crit_0056315c;
  do {
    cptr7 = cptr6;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cptr7 = cptr6 + 1;
    cVar1 = *cptr6;
    cptr6 = cptr7;
  } while (cVar1 != '\0');
  uvalue3 = ~uvalue3;
  cptr6 = cptr7 + -uvalue3;
  cptr7 = (char *)(arg1 + 0x5a9);
  for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *(uint32_t *)cptr7 = *(uint32_t *)cptr6;
    cptr6 = cptr6 + 4;
    cptr7 = cptr7 + 4;
  }
  uptr2 = arg1 + 0x5bd;
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *cptr7 = *cptr6;
    cptr6 = cptr6 + 1;
    cptr7 = cptr7 + 1;
  }
  value5 = 0x14;
  do {
    *uptr2 = 0;
    uptr2 = uptr2 + 9;
    value5 = value5 + -1;
  } while (value5 != 0);
  arg1[0x6ad] = 0;
  return arg1;
}
