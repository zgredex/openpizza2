// Game_BlitScaledObjectSprite: ported from Pizza Connection 2 at 0x4ea400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ea400
#include "pc2_port.h"

void __fastcall Game_BlitScaledObjectSprite(int arg1)

{
  uint32_t *uptr1;
  int value2;
  int value3;
  int value4;
  
  value3 = *(int *)(arg1 + 0x2f88c);
  value2 = *(int *)(arg1 + 0x2f888);
  value4 = DAT_00580a50;
  uptr1 = (uint32_t *)Sprite_GetPixelBuffer(*(void **)(arg1 + 0x2f884));
  Gfx_BlitRLEScaled(*(void **)(arg1 + 0x2f884),*(int *)(arg1 + 0x2f880),DAT_0058072c,uptr1,
                    value2,value3,value4);
  return;
}
