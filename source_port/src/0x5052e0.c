// Person_Save: ported from Pizza Connection 2 at 0x5052e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5052e0
#include "pc2_port.h"

void __thiscall Person_Save(void *self,void *arg1)

{
  uint32_t local_4;
  
  if (*(int *)((intptr_t)self + 200) == 0) {
    local_4 = 0;
    CRT_Ostream_Write(arg1,&local_4,4);
    return;
  }
  local_4 = 1;
  CRT_Ostream_Write(arg1,&local_4,4);
  MapSprite_Save(arg1,*(int **)((intptr_t)self + 200));
  return;
}
