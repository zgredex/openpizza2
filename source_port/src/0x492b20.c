// ManagerPage_Update: ported from Pizza Connection 2 at 0x492b20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x492b20
#include "pc2_port.h"

void __cdecl ManagerPage_Update(void *arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  int value3;
  int64_t lvalue4;
  uint8_t local_20 [32];
  
                    /* Refreshes the branch manager page. */
  DAT_0057c6cc = *(int *)(DAT_0057c670 + 0x9c);
  Window_GadgetNotify_Slider_SetRange(arg1,0x43a,0,100,0);
  if (*(int *)(DAT_0057c6cc + 0x14c4) == 0) {
    uvalue2 = 0xffffffff;
  }
  else {
    uvalue2 = *(uint32_t *)(DAT_0057c6cc + 0x14c8);
  }
  Window_GadgetNotify_Slider_SetValue(arg1,0x43a,uvalue2,0);
  Window_GadgetNotify_Slider_SetRange(arg1,3000,0,100,0);
  if (*(int *)(DAT_0057c6cc + 0x14c4) == 0) {
    uvalue2 = 0xffffffff;
  }
  else {
    uvalue2 = *(uint32_t *)(DAT_0057c6cc + 0x14cc);
  }
  Window_GadgetNotify_Slider_SetValue(arg1,3000,uvalue2,0);
  Window_GadgetNotify_Slider_SetRange(arg1,0x43b,-0x32,0x32,0);
  if (*(int *)(DAT_0057c6cc + 0x14c4) == 0) {
    uvalue2 = 0;
  }
  else {
    uvalue2 = *(uint32_t *)(DAT_0057c6cc + 0x14d0);
  }
  Window_GadgetNotify_Slider_SetValue(arg1,0x43b,uvalue2,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x43b,1);
  Window_GadgetNotify_Slider_SetRange(arg1,0x43c,0,0x32,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x43c,*(uint32_t *)(DAT_0057c6cc + 0x14d4),0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x43c,1);
  Window_GadgetNotify_Slider_SetRange(arg1,0x43d,-0x32,0x32,0);
  if (*(int *)(DAT_0057c6cc + 0x14c4) == 0) {
    uvalue2 = 0;
  }
  else {
    uvalue2 = *(uint32_t *)(DAT_0057c6cc + 0x14c0);
  }
  Window_GadgetNotify_Slider_SetValue(arg1,0x43d,uvalue2,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x43d,1);
  Game_GetRatingMultiplier(DAT_0057c6cc);
  lvalue4 = __ftol();
  String_Format(local_20,&DAT_005686f8,(intptr_t)lvalue4);
  Window_GadgetNotify_Text_SetText(arg1,0x4f9,local_20);
  value3 = Rating_ComputePenalty(DAT_0057c6cc);
  String_Format(local_20,&DAT_005686f4,value3);
  Window_GadgetNotify_Text_SetText(arg1,0x4fa,local_20);
  Game_GetMarketBonusFactor(DAT_0057c6cc);
  lvalue4 = __ftol();
  String_Format(local_20,&DAT_005686f8,(intptr_t)lvalue4);
  Window_GadgetNotify_Text_SetText(arg1,0x1f43,local_20);
  value3 = Game_GetMarketBonus(DAT_0057c6cc);
  String_Format(local_20,(uint8_t *)s___02d_005686ec,value3);
  Window_GadgetNotify_Text_SetText(arg1,0x4f8,local_20);
  uvalue1 = *(uint32_t *)(DAT_0057c6cc + 0x1894);
  Window_GadgetNotify_Button_SetState(arg1,0x436,uvalue1 & 2);
  Window_GadgetNotify_Button_SetState(arg1,0x438,uvalue1 & 0x20);
  TakeoverScreen_UpdateRatingBars(arg1);
  return;
}
