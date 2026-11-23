// Person_WanderToRandomTile: ported from Pizza Connection 2 at 0x507b40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x507b40
#include "pc2_port.h"

void __fastcall Person_WanderToRandomTile(void *arg1)

{
  int value1;
  int value2;
  
                    /* Sends a person to a random tile in the city. */
  if (*(int *)((intptr_t)arg1 + 0xd0) == 0) {
    NoOp_Stub();
  }
  if (*(int *)((intptr_t)arg1 + 200) == 0) {
    value2 = 0;
  }
  else {
    value2 = *(int *)(*(int *)((intptr_t)arg1 + 200) + 0x20);
  }
  value1 = Map_ApplyRandomTileVariant(*(int *)((intptr_t)arg1 + 0xd0));
  Person_PathToTileAndStep(arg1,value2,value1);
  return;
}
