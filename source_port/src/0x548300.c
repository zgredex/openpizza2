// Sound_PlayTrackIfSelected: ported from Pizza Connection 2 at 0x548300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548300
#include "pc2_port.h"

void __thiscall Sound_PlayTrackIfSelected(void *self,int arg1)

{
  int value1;
  int value2;
  
  if (*(char *)((intptr_t)self + 0xfc) != '\0') {
    value1 = *(int *)(DAT_0057c670 + 0x2fc);
    value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
    if (value1 == *(int *)(value2 + 0xfa8)) {
      Sound_SetParam(self,*(uint32_t *)((intptr_t)self + arg1 * 4 + 0x24));
    }
  }
  return;
}
