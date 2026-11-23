// Game_FreeSubmapObjects: ported from Pizza Connection 2 at 0x4810e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4810e0
#include "pc2_port.h"

void __fastcall Game_FreeSubmapObjects(int arg1)

{
  int value1;
  LPVOID pvVar2;
  int value3;
  
  if (*(int *)(arg1 + 0x1a28) != 0) {
    value1 = *(int *)(*(int *)(arg1 + 0x1a28) + 0x14);
    value3 = 0;
    if (0 < value1) {
      do {
        pvVar2 = (LPVOID)IDMap_Lookup(*(void **)(arg1 + 0x1a28),value3,(int *)0x0);
        Mem_Free(pvVar2);
        value3 = value3 + 1;
      } while (value3 < value1);
    }
    if (*(uint32_t **)(arg1 + 0x1a28) != (uint32_t *)0x0) {
      (**(code **)**(uint32_t **)(arg1 + 0x1a28))(1);
    }
    *(uint32_t *)(arg1 + 0x1a28) = 0;
  }
  return;
}
