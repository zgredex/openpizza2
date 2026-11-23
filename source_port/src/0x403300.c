// UI_ListEntry_ConstructWithValue: ported from Pizza Connection 2 at 0x403300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403300
#include "pc2_port.h"

char * __thiscall
UI_ListEntry_ConstructWithValue(void *self,char *arg1,uint32_t arg2,uint32_t arg3)

{
  char cVar1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  char *cptr4;
  char *cptr5;
  
                    /* Constructs a dialog list entry with a label, id, and extra value. */
  *(uint32_t *)((intptr_t)self + 0x4c) = arg2;
  *(uint32_t *)((intptr_t)self + 0x54) = arg3;
  uvalue2 = 0xffffffff;
  *(uint8_t ***)self = &PTR_UI_ListEntry_Delete_0055c2f8;
  *(uint32_t *)((intptr_t)self + 0x44) = 0;
  *(uint32_t *)((intptr_t)self + 0x48) = 0;
  do {
    cptr5 = arg1;
    if (uvalue2 == 0) break;
    uvalue2 = uvalue2 - 1;
    cptr5 = arg1 + 1;
    cVar1 = *arg1;
    arg1 = cptr5;
  } while (cVar1 != '\0');
  uvalue2 = ~uvalue2;
  cptr4 = cptr5 + -uvalue2;
  cptr5 = self;
  for (uvalue3 = uvalue2 >> 2; cptr5 = cptr5 + 4, uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *(uint32_t *)cptr5 = *(uint32_t *)cptr4;
    cptr4 = cptr4 + 4;
  }
  for (uvalue2 = uvalue2 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
    *cptr5 = *cptr4;
    cptr4 = cptr4 + 1;
    cptr5 = cptr5 + 1;
  }
  return self;
}
