// Personnel_SetEmployeePhotoByKey: ported from Pizza Connection 2 at 0x4a66d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a66d0
#include "pc2_port.h"

void __cdecl Personnel_SetEmployeePhotoByKey(void *arg1,int arg2,int arg3)

{
  int value1;
  char local_100 [256];
  
                    /* Sets an employee photo sprite at a UI key. */
  if (arg3 == 0) {
    UI_RemoveObjectByKey(arg1,arg2);
    return;
  }
  value1 = *(int *)(arg3 + 0x1e0);
  Game_FindCityIndex(arg3);
  String_Format(local_100,(uint8_t *)s_PLAYLOG__d_0_d_02_spr_00569148,value1 + 1);
  UI_ShowChildByID(arg1,arg2);
  UI_SetButtonSpriteByName(arg1,arg2,local_100);
  return;
}
