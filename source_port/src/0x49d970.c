// RecipeEditor_ShowIngredientCursorSprite: ported from Pizza Connection 2 at 0x49d970.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49d970
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl RecipeEditor_ShowIngredientCursorSprite(uint32_t arg1)

{
  int value1;
  uint32_t *self;
  uint16_t *uptr2;
  uint32_t local_44;
  CHAR local_40 [64];
  
  if ((intptr_t)arg1 < 0) {
    UI_ReleasePendingSprite((intptr_t)DAT_0057c5e0);
    DAT_0057ca2c = 0;
    return;
  }
  value1 = IDMap_Lookup(DAT_0057cac8,arg1,(int *)0x0);
  String_Format(local_40,(uint8_t *)s_zutaten_ZA_02dA__02d_spr_00568948,*(uint32_t *)(value1 + 0xd0));
  self = UI_LoadChildSprite(DAT_0057c5e0,local_40);
  Game_SetObjectInfoWindowVisible(DAT_0057c670,0);
  if (self != (uint32_t *)0x0) {
    Sprite_GetRenderSize(self,&arg1,&local_44);
    DAT_0057cac0 = -((intptr_t)local_44 / 2);
    DAT_0057cabc = -((intptr_t)arg1 / 2);
    UI_RefreshChildSprite(DAT_0057c5e0,1,DAT_0057cabc,DAT_0057cac0);
    DAT_0057ca2c = 1;
    uptr2 = (uint16_t *)UI_ResetInputHelper((intptr_t)DAT_0057c5e0);
    UI_ApplyChildSpriteTint(DAT_0057c5e0,uptr2,1);
  }
  return;
}
