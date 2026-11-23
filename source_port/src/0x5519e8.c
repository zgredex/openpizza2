// CRT_ForceDecimalPoint: ported from Pizza Connection 2 at 0x5519e8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5519e8
#include "pc2_port.h"

void __cdecl CRT_ForceDecimalPoint(char *arg1)

{
  char cVar1;
  char cVar2;
  uint8_t *self;
  uint32_t uvalue3;
  uint8_t *uptr4;
  
  self = (uint8_t *)(intptr_t)*arg1;
  uvalue3 = CRT_Tolower((uint32_t)self);
  if (uvalue3 != 0x65) {
    do {
      arg1 = arg1 + 1;
      if (DAT_00576cf0 < 2) {
        uvalue3 = (uint8_t)PTR_DAT_00576ae4[*arg1 * 2] & 4;
        self = PTR_DAT_00576ae4;
      }
      else {
        uptr4 = (uint8_t *)0x4;
        uvalue3 = CRT_Mbtowc(self,(intptr_t)*arg1,4);
        self = uptr4;
      }
    } while (uvalue3 != 0);
  }
  cVar2 = *arg1;
  *arg1 = DAT_00576cf4;
  do {
    arg1 = arg1 + 1;
    cVar1 = *arg1;
    *arg1 = cVar2;
    cVar2 = cVar1;
  } while (*arg1 != '\0');
  return;
}
