// AttackMenu_InitCompetitorRows: ported from Pizza Connection 2 at 0x4a28f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a28f0
#include "pc2_port.h"

void __cdecl AttackMenu_InitCompetitorRows(void *arg1)

{
  int value1;
  int value2;
  void *self;
  int local_110;
  int *local_10c;
  int local_108;
  int local_104;
  char local_100 [256];
  
                    /* Fills the attack menu's competitor logos and bars. */
  local_110 = 0;
  local_10c = &DAT_00568e14;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,local_110);
    if (value1 == 0) {
      UI_RemoveObjectByKey(arg1,*local_10c);
    }
    else {
      value2 = Game_GetPlayerFieldC20(value1);
      UI_ShowChildByID(arg1,*local_10c);
      String_Format(local_100,(uint8_t *)s_LOGOS__0_d_spr_00568eb8,*(int *)(value1 + 0x1e0) + 1);
      UI_SetButtonSpriteByName(arg1,*local_10c,local_100);
      if (0 < value2) {
        self = (void *)UI_GetWindowObject(arg1,local_110 + 0x45a);
        UI_RealizeSprite((intptr_t)self);
        UI_GetChildSize(self,&local_104,&local_108);
        Sprite_FillRectColor
                  (self,0,(local_108 - (local_108 * value2) / 6) + -1,local_104,local_108,
                   *(uint32_t *)(value1 + 0x1dc));
        UI_ClipChildRect((intptr_t)self);
      }
    }
    local_10c = local_10c + 1;
    local_110 = local_110 + 1;
  } while ((intptr_t)local_10c < 0x568e2c);
  return;
}
