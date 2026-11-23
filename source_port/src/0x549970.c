// Sound_ProcessEventForSelectedObject: ported from Pizza Connection 2 at 0x549970.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x549970
#include "pc2_port.h"

void __thiscall
Sound_ProcessEventForSelectedObject
          (void *self,int arg1,int arg2,uint32_t arg3,char arg4)

{
  if ((*(char *)((intptr_t)self + 0xfc) != '\0') && (arg1 == *(int *)(DAT_0057c670 + 0x9c))) {
    Sound_ProcessEvent(self,arg2,arg3,arg4);
  }
  return;
}
