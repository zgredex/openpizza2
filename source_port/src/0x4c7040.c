// CharacterSelect_SetPhotoSprite: ported from Pizza Connection 2 at 0x4c7040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c7040
#include "pc2_port.h"

void __cdecl CharacterSelect_SetPhotoSprite(void *arg1)

{
  char local_100 [256];
  
  String_Format(local_100,(uint8_t *)s_PLAYLOG__d_0_d_00_spr_0056b1d0,DAT_0057ddb0 + 1);
  UI_SetButtonSpriteByName(arg1,0x43c,local_100);
  return;
}
