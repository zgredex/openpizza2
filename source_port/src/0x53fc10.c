// DirectSoundBuffer_Delete: ported from Pizza Connection 2 at 0x53fc10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53fc10
#include "pc2_port.h"

uint32_t * __thiscall DirectSoundBuffer_Delete(void *self,uint8_t arg1)

{
  int *ptr1;
  
  ptr1 = *(int **)((intptr_t)self + 4);
  *(uint8_t ***)self = &PTR_DirectSoundBuffer_Delete_0055c860;
  if (ptr1 != (int *)0x0) {
    (**(code **)(*ptr1 + 8))(ptr1);
  }
  if ((arg1 & 1) != 0) {
    Mem_Free(self);
  }
  return self;
}
