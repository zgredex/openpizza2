// FurnitureMenu_SetWallFloorSprite: ported from Pizza Connection 2 at 0x4901b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4901b0
#include "pc2_port.h"

void __cdecl
FurnitureMenu_SetWallFloorSprite(void *arg1,int arg2,int arg3,int arg4,int arg5)

{
  uint8_t *bptr1;
  char *local_128 [4];
  char *local_118;
  char *local_114;
  char *local_110;
  char *local_10c;
  char *local_108;
  char *local_104;
  char local_100 [256];
  
  local_110 = s_Moebel_MENU_BODENEINF0_d_spr_005685d4;
  local_10c = s_Moebel_MENU_BODENRUST0_d_spr_005685b4;
  local_108 = s_Moebel_MENU_BODENMODE0_d_spr_00568594;
  local_104 = s_Moebel_MENU_BODENEDEL0_d_spr_00568574;
  local_128[2] = s_Moebel_MENU_TRENNWAND_EINF01_spr_005684e0;
  local_128[3] = s_Moebel_MENU_TRENNWAND_RUST01_spr_005684bc;
  local_118 = s_Moebel_MENU_TRENNWAND_MODE01_spr_00568498;
  local_114 = s_Moebel_MENU_TRENNWAND_EDEL01_spr_00568474;
  if (arg3 == 6) {
    bptr1 = (uint8_t *)local_128[arg4 + 2];
  }
  else {
    if (arg3 != 8) {
      if (arg3 == 10) {
        String_Format(local_100,(uint8_t *)local_128[arg4 + 6],arg5 + 1);
      }
      goto LAB_00490276;
    }
    bptr1 = (uint8_t *)local_128[arg4 + -2];
  }
  String_Format(local_100,bptr1,s_Moebel_MENU_WAND_EINF_spr_00568558);
LAB_00490276:
  UI_SetButtonSpriteByName(arg1,arg2,local_100);
  return;
}
