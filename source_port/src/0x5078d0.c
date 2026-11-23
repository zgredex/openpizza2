// Person_PathToTileAndStep: ported from Pizza Connection 2 at 0x5078d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5078d0
#include "pc2_port.h"

uint32_t __thiscall Person_PathToTileAndStep(void *self,int arg1,int arg2)

{
  uint32_t uvalue1;
  DWORD DVar2;
  
                    /* Starts a path to a tile and advances one step. */
  uvalue1 = 0;
  if (*(void **)((intptr_t)self + 200) != (void *)0x0) {
    uvalue1 = Object_TryStepToTile
                      (*(void **)((intptr_t)self + 0xc4),1,*(void **)((intptr_t)self + 200),arg1,arg2);
    DVar2 = timeGetTime();
    Object_UpdateWalkStep(*(void **)((intptr_t)self + 0xc4),*(uint32_t **)((intptr_t)self + 200),DVar2);
  }
  return uvalue1;
}
