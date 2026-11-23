// Game_EnterBranchInterior: ported from Pizza Connection 2 at 0x488de0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x488de0
#include "pc2_port.h"

void __thiscall Game_EnterBranchInterior(void *self,int arg1)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(arg1 + 0x14e0);
  if (*(int *)(arg1 + 0x16f0) != 0) {
    Game_CenterViewOnObject(*(int *)(arg1 + 0x16f0));
    Map_DrawMinimap(self);
  }
  Game_ShowBranchScene(self,pvVar1,1);
  Sound_SetVolumePreset(self,0);
  return;
}
