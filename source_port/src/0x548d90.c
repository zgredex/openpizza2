// Sound_PlayPoliceSfx: ported from Pizza Connection 2 at 0x548d90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548d90
#include "pc2_port.h"

void __fastcall Sound_PlayPoliceSfx(void *arg1)

{
  if (*(char *)((intptr_t)arg1 + 0xfc) != '\0') {
    Sound_PlayChannel(arg1,s_Sfx_Sfx_City_Police_wav_00576168,1);
  }
  return;
}
