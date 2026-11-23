// FurnitureMenu_SetItemSprite: ported from Pizza Connection 2 at 0x490100.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x490100
#include "pc2_port.h"

void __cdecl
FurnitureMenu_SetItemSprite(void *arg1,int arg2,int arg3,int arg4,uint32_t arg5)

{
  int value1;
  char local_100 [256];
  
  value1 = Game_FindRecordByTripleKey(DAT_0057c670,arg3,arg4,arg5,(int *)0x0);
  if (value1 != 0) {
    if ((arg3 < 1) || (2 < arg3)) {
      String_Format(local_100,(uint8_t *)s_Moebel__s_spr_00568450,value1 + 0x40);
    }
    else {
      String_Format(local_100,(uint8_t *)s_Moebel__s__c_spr_00568460,value1 + 0x40);
    }
    UI_SetButtonSpriteByName(arg1,arg2,local_100);
  }
  return;
}
