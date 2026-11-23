// FurnitureMenu_RefreshSlots: ported from Pizza Connection 2 at 0x4902a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4902a0
#include "pc2_port.h"

void __cdecl FurnitureMenu_RefreshSlots(void *arg1)

{
  int *ptr1;
  int value2;
  
  switch(DAT_0057c6a8) {
  case 0:
    FurnitureMenu_SetItemSprite(arg1,0x1f59,1,0,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f5a,1,0,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f5b,1,0,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f5c,1,1,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f5d,1,1,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f5e,1,1,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f64,1,2,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f63,1,2,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f62,1,2,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f5f,1,3,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f60,1,3,1);
    value2 = 1;
    break;
  case 1:
    FurnitureMenu_SetItemSprite(arg1,0x1f59,2,0,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f5a,2,0,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f5b,2,0,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f5c,2,1,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f5d,2,1,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f5e,2,1,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f64,2,2,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f63,2,2,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f62,2,2,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f5f,2,3,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f60,2,3,1);
    value2 = 2;
    break;
  case 2:
    FurnitureMenu_SetItemSprite(arg1,0x1f59,3,0,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f5a,3,0,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f5b,3,0,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f5c,3,1,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f5d,3,1,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f5e,3,1,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f64,3,2,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f63,3,2,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f62,3,2,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f5f,3,3,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f60,3,3,1);
    value2 = 3;
    break;
  case 3:
    FurnitureMenu_SetItemSprite(arg1,0x1f59,4,0,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f5a,4,0,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f5b,4,0,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f5c,4,1,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f5d,4,1,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f5e,4,1,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f64,4,2,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f63,4,2,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f62,4,2,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f5f,4,3,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f60,4,3,1);
    value2 = 4;
    break;
  case 4:
    FurnitureMenu_SetWallFloorSprite(arg1,0x1f59,10,0,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(arg1,0x1f5c,10,1,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(arg1,0x1f64,10,2,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(arg1,0x1f5f,10,3,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(arg1,0x1f5a,8,0,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(arg1,0x1f5d,8,1,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(arg1,0x1f63,8,2,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(arg1,0x1f60,8,3,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(arg1,0x1f5b,6,0,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(arg1,0x1f5e,6,1,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(arg1,0x1f62,6,2,DAT_0057c6ac);
    FurnitureMenu_SetWallFloorSprite(arg1,0x1f61,6,3,DAT_0057c6ac);
    goto switchD_004902b4_default;
  case 5:
    FurnitureMenu_SetItemSprite(arg1,0x1f59,5,0,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f5a,5,0,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f5b,5,0,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f5c,5,1,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f5d,5,1,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f5e,5,1,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f64,5,2,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f63,5,2,1);
    FurnitureMenu_SetItemSprite(arg1,0x1f62,5,2,2);
    FurnitureMenu_SetItemSprite(arg1,0x1f5f,5,3,0);
    FurnitureMenu_SetItemSprite(arg1,0x1f60,5,3,1);
    value2 = 5;
    break;
  default:
    goto switchD_004902b4_default;
  }
  FurnitureMenu_SetItemSprite(arg1,0x1f61,value2,3,2);
switchD_004902b4_default:
  ptr1 = &DAT_00568420;
  do {
    Window_GadgetNotify_Button_SetState(arg1,*ptr1,0);
    ptr1 = ptr1 + 1;
  } while ((intptr_t)ptr1 < 0x568450);
  return;
}
