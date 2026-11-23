// Record_DoublePositionValue: ported from Pizza Connection 2 at 0x509170.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509170
#include "pc2_port.h"

void __fastcall Record_DoublePositionValue(int arg1)

{
  double dVar1;
  int *ptr2;
  int value3;
  int value4;
  
  ptr2 = *(int **)(arg1 + 200);
  if ((ptr2 != (int *)0x0) && (value3 = ptr2[0x16], value3 != 0)) {
    value4 = *ptr2;
    if ((-1 < value4) && (value4 < *(int *)(value3 + 0x48))) {
      dVar1 = *(double *)(*(int *)(value3 + 0x4c) + 0x28 + value4 * 0x48);
      UI_SetListEntryPosition(value3,value4,dVar1 + dVar1);
      return;
    }
    UI_SetListEntryPosition(value3,value4,0);
  }
  return;
}
