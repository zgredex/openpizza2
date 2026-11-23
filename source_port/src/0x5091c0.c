// UI_SetListEntryHalfScale: ported from Pizza Connection 2 at 0x5091c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5091c0
#include "pc2_port.h"

void __fastcall UI_SetListEntryHalfScale(int arg1)

{
  int *ptr1;
  int value2;
  int value3;
  
  ptr1 = *(int **)(arg1 + 200);
  if ((ptr1 != (int *)0x0) && (value2 = ptr1[0x16], value2 != 0)) {
    value3 = *ptr1;
    if ((-1 < value3) && (value3 < *(int *)(value2 + 0x48))) {
      UI_SetListEntryPosition
                (value2,value3,*(double *)(*(int *)(value2 + 0x4c) + 0x28 + value3 * 0x48) * 0.5);
      return;
    }
    UI_SetListEntryPosition(value2,value3,0);
  }
  return;
}
