// Game_ShowBranchInteriorDefaultZoom: ported from Pizza Connection 2 at 0x488db0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x488db0
#include "pc2_port.h"

void __thiscall Game_ShowBranchInteriorDefaultZoom(void *self,void *arg1)

{
  Sound_SetVolumePreset(self,*(int *)((intptr_t)self + 900));
  Game_ShowBranchScene(self,arg1,0);
  return;
}
