// SoundBuffer_FillFromSample: ported from Pizza Connection 2 at 0x540a30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x540a30
#include "pc2_port.h"

int __thiscall SoundBuffer_FillFromSample(void *self,void *arg1)

{
  char *cptr1;
  int value2;
  
  cptr1 = (char *)SoundBuffer_LockSample(self,0,*(int *)((intptr_t)self + 0x10));
  if (cptr1 == (char *)0x0) {
    return -0x7fffbffb;
  }
  value2 = SoundSample_ReadPCM(arg1,cptr1,*(uint32_t *)((intptr_t)self + 0x10));
  if (value2 < 0) {
    SoundBuffer_UnlockSample((intptr_t)self);
    return value2;
  }
  value2 = SoundBuffer_UnlockSample((intptr_t)self);
  return value2;
}
