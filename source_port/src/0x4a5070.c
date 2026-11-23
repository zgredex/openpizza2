// TradeOffer_UpdatePanel: ported from Pizza Connection 2 at 0x4a5070.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a5070
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl TradeOffer_UpdatePanel(void *arg1,int arg2)

{
  int value1;
  void *self;
  int value2;
  int *ptr3;
  int local_8;
  int local_4;
  
  value1 = *(int *)(DAT_0057c670 + 0x218);
  self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(value1 + 0x28),(int *)0x0);
  switch(arg2) {
  case 0:
    Window_GadgetNotify_Text_SetText(arg1,0x1f67,DAT_00581d5c);
    Window_GadgetNotify_Text_SetText(arg1,0x1f65,DAT_005824c0);
    Gadget_SetTextf(arg1,0x43a,(uint8_t *)s__d__s_00568324,2);
    ptr3 = (int *)0x0;
    value2 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
    arg2 = Game_ComputeTradeOffers(self,value1,1,&local_4,&local_8,value2,ptr3);
    break;
  case 1:
    Window_GadgetNotify_Text_SetText(arg1,0x1f67,DAT_00580bdc);
    Window_GadgetNotify_Text_SetText(arg1,0x1f65,DAT_00582e10);
    Gadget_SetTextf(arg1,0x43a,(uint8_t *)s__d__s_00568324,3);
    ptr3 = (int *)0x0;
    value2 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
    arg2 = Game_ComputeTradeOffers(self,value1,3,&local_4,&local_8,value2,ptr3);
    break;
  case 2:
    Window_GadgetNotify_Text_SetText(arg1,0x1f67,DAT_00581bc0);
    Window_GadgetNotify_Text_SetText(arg1,0x1f65,DAT_005827bc);
    Gadget_SetTextf(arg1,0x43a,(uint8_t *)s__d__s_00568324,4);
    ptr3 = (int *)0x0;
    value2 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
    arg2 = Game_ComputeTradeOffers(self,value1,4,&local_4,&local_8,value2,ptr3);
    break;
  case 3:
    Window_GadgetNotify_Text_SetText(arg1,0x1f67,DAT_00582954);
    Window_GadgetNotify_Text_SetText(arg1,0x1f65,DAT_00581e98);
    Gadget_SetTextf(arg1,0x43a,(uint8_t *)s__d__s_00568324,5);
    ptr3 = (int *)0x0;
    value2 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
    arg2 = Game_ComputeTradeOffers(self,value1,2,&local_4,&local_8,value2,ptr3);
    break;
  default:
  }
  _DAT_0057d268 = arg2 / 10;
  DAT_0057d26c = local_8;
  Gadget_SetTextf(arg1,0x439,&DAT_005686f4,local_8);
  Gadget_SetTextf(arg1,0x1f64,&DAT_005686f4,local_8 - arg2);
  Gadget_SetTextf(arg1,0x1f63,&DAT_005686f4,arg2);
  return;
}
