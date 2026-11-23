// Game_SaveTileNameTable: ported from Pizza Connection 2 at 0x4eaaa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eaaa0
#include "pc2_port.h"

void __thiscall Game_SaveTileNameTable(void *self,void *arg1)

{
  char cVar1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  char *cptr4;
  int value5;
  char *cptr6;
  char *cptr7;
  char local_34 [52];
  
  cptr4 = (char *)((intptr_t)self + 0x25);
  value5 = 0x9c4;
  do {
    uvalue2 = 0xffffffff;
    cptr6 = cptr4;
    do {
      cptr7 = cptr6;
      if (uvalue2 == 0) break;
      uvalue2 = uvalue2 - 1;
      cptr7 = cptr6 + 1;
      cVar1 = *cptr6;
      cptr6 = cptr7;
    } while (cVar1 != '\0');
    uvalue2 = ~uvalue2;
    cptr6 = cptr7 + -uvalue2;
    cptr7 = local_34;
    for (uvalue3 = uvalue2 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
      *(uint32_t *)cptr7 = *(uint32_t *)cptr6;
      cptr6 = cptr6 + 4;
      cptr7 = cptr7 + 4;
    }
    for (uvalue2 = uvalue2 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
      *cptr7 = *cptr6;
      cptr6 = cptr6 + 1;
      cptr7 = cptr7 + 1;
    }
    CRT_Ostream_Write(arg1,local_34,0x32);
    cptr4 = cptr4 + 0x48;
    value5 = value5 + -1;
    if (value5 == 0) {
      return;
    }
  } while( true );
}
