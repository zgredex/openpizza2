// UI_RemoveLastChild: ported from Pizza Connection 2 at 0x509bf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509bf0
#include "pc2_port.h"

void __fastcall UI_RemoveLastChild(int arg1)

{
  int value1;
  
  value1 = *(int *)(arg1 + 200);
  if (value1 == 0) {
    return;
  }
  Array_GetPtr4((void *)(value1 + 0x14),*(int *)(value1 + 0x18) + -1);
  return;
}
