// Player_AddRecipeToMenu: ported from Pizza Connection 2 at 0x49bd50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49bd50
#include "pc2_port.h"

void __cdecl Player_AddRecipeToMenu(int arg1)

{
  void *self;
  int value1;
  
  self = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  value1 = IDMap_Lookup((void *)((intptr_t)self + 0x110),arg1,(int *)0x0);
  Recipe_SetOnMenu(self,value1,1);
  return;
}
