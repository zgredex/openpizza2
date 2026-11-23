// FurnitureType_Construct: ported from Pizza Connection 2 at 0x4e3fb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3fb0
#include "pc2_port.h"

uint32_t * __fastcall FurnitureType_Construct(uint32_t *arg1)

{
  char cVar1;
  uint32_t *uptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int value5;
  char *cptr6;
  char *cptr7;
  
                    /* Constructs a furniture-type record with defaults and tile ranges. */
  uvalue3 = 0xffffffff;
  *arg1 = &PTR_FurnitureType_Delete_0055c5a0;
  arg1[2] = 0xc;
  arg1[3] = 0xb;
  arg1[4] = 4;
  arg1[5] = 3;
  cptr6 = &DAT_00579aec;
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
  cptr7 = (char *)(arg1 + 6);
  for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *(uint32_t *)cptr7 = *(uint32_t *)cptr6;
    cptr6 = cptr6 + 4;
    cptr7 = cptr7 + 4;
  }
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *cptr7 = *cptr6;
    cptr6 = cptr6 + 1;
    cptr7 = cptr7 + 1;
  }
  arg1[0x1c] = 0;
  arg1[0x1d] = 0;
  value5 = 8;
  uptr2 = arg1 + 0x1e;
  do {
    value5 = value5 + -1;
    *uptr2 = 0xffffffff;
    uptr2[1] = 0xffffffff;
    uptr2 = uptr2 + 3;
  } while (value5 != 0);
  return arg1;
}
