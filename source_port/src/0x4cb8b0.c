// UI_SetPlayerLogoSprite: ported from Pizza Connection 2 at 0x4cb8b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cb8b0
#include "pc2_port.h"

void __cdecl UI_SetPlayerLogoSprite(void *arg1,int arg2,uint32_t arg3,int arg4)

{
  char local_100 [256];
  
  String_Format(local_100,(uint8_t *)s_PLAYLOG__d_0_d_01_spr_0056b318,arg2 + 1);
  UI_SetButtonSpriteByName(arg1,arg4,local_100);
  return;
}
