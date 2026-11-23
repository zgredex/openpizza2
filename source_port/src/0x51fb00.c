// Screen_BeginTileWipeTransition: ported from Pizza Connection 2 at 0x51fb00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51fb00
#include "pc2_port.h"

void __thiscall Screen_BeginTileWipeTransition(void *self,uint32_t arg1,uint32_t arg2)

{
  DWORD DVar1;
  
  if (*(int *)((intptr_t)self + 0x34) != 0) {
    if (*(int *)((intptr_t)self + 8) != 0) {
      *(uint32_t *)((intptr_t)self + 0xc) = 0;
      Screen_AnimateTileWipe(self,arg1);
    }
    *(uint32_t *)((intptr_t)self + 8) = *(uint32_t *)((intptr_t)self + 0x34);
    DVar1 = timeGetTime();
    *(DWORD *)((intptr_t)self + 0xc) = DVar1;
    *(uint32_t *)((intptr_t)self + 0x10) = arg2;
    *(uint32_t *)((intptr_t)self + 0x14) = 1;
  }
  return;
}
