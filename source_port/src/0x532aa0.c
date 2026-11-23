// UI_FreeObjectPairs: ported from Pizza Connection 2 at 0x532aa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532aa0
#include "pc2_port.h"

void __fastcall UI_FreeObjectPairs(int arg1)

{
  int value1;
  LPVOID pvVar2;
  int value3;
  
  value3 = 0;
  value1 = *(int *)(arg1 + 0x2b8);
  if (0 < value1) {
    do {
      pvVar2 = (LPVOID)Array_GetPtr((void *)(arg1 + 0x2a8),value3);
      if (pvVar2 != (LPVOID)0x0) {
        Mem_Free(pvVar2);
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  Array_Clear(arg1 + 0x2a8);
  return;
}
