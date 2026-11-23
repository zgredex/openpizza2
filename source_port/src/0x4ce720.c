// Movie_PlayGameOverMovie: ported from Pizza Connection 2 at 0x4ce720.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ce720
#include "pc2_port.h"

void __cdecl Movie_PlayGameOverMovie(void *arg1)

{
  DAT_0056b40c = 1;
  SoundBuffer_Release(DAT_0057ba0c);
  Sound_StopCurrentBuffer(DAT_0057ba0c);
  Movie_CreatePlayer(arg1,100,0,100,s_lost_s_bik_0056b3d0,(uint32_t *)0x1);
  UI_StartButtonMovie(arg1,100,0);
  return;
}
