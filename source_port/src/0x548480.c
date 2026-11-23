// Sound_CheckSpeechState: ported from Pizza Connection 2 at 0x548480.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548480
#include "pc2_port.h"

void __thiscall Sound_CheckSpeechState(void *self,int arg1)

{
  if (((*(char *)((intptr_t)self + 0xfc) != '\0') && (*(char *)((intptr_t)self + 0x16a) != '\0')) &&
     (*(int *)(DAT_0057c670 + 0x290) == 4)) {
    Sound_UpdateVolumeByCitySize(self,arg1);
  }
  return;
}
