// RenovationScreen_UpdateCost: ported from Pizza Connection 2 at 0x4922d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4922d0
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl RenovationScreen_UpdateCost(void *arg1)

{
  int value1;
  
  value1 = DAT_0057c6c4 + 5 + DAT_0057c6c0 * 4;
  _DAT_0057c6c8 = value1 * 0xfa;
  if (DAT_0057c6b8 == 0) {
    _DAT_0057c6c8 = (value1 * 2000) / 10;
  }
  else if (DAT_0057c6b8 == 2) {
    _DAT_0057c6c8 = (intptr_t)(value1 * 0x9c4 + (value1 * 0x9c4 >> 0x1f & 7U)) >> 3;
  }
  value1 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value1 + 0xd4) == 0) {
    if (*(int *)(value1 + 0x1b8) != 0) {
      _DAT_0057c6c8 = (_DAT_0057c6c8 * 0xf) / 10;
    }
  }
  else {
    _DAT_0057c6c8 = 0;
  }
  Gadget_SetTextf(arg1,0x1f50,&DAT_005683a4,_DAT_0057c6c8);
  return;
}
