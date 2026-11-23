// DirectSoundBuffer_Destructor: ported from Pizza Connection 2 at 0x53fbf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53fbf0
#include "pc2_port.h"

void __fastcall DirectSoundBuffer_Destructor(uint32_t *arg1)

{
  int *ptr1;
  
                    /* Releases the embedded DirectSound buffer wrapper. */
  *arg1 = &PTR_DirectSoundBuffer_Delete_0055c860;
  ptr1 = (int *)arg1[1];
  if (ptr1 != (int *)0x0) {
    (**(code **)(*ptr1 + 8))(ptr1);
  }
  return;
}
