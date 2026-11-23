// Game_HideAllLinkedElements: ported from Pizza Connection 2 at 0x4ead50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ead50
#include "pc2_port.h"

void __fastcall Game_HideAllLinkedElements(int arg1)

{
  int value1;
  int value2;
  
  value2 = 0;
  if (0 < *(int *)(arg1 + 0x2c40c)) {
    do {
      value1 = IDMap_Lookup((void *)(arg1 + 0x2c3f8),value2,(int *)0x0);
      Object_HideLinkedElements(value1);
      value2 = value2 + 1;
    } while (value2 < *(int *)(arg1 + 0x2c40c));
  }
  return;
}
