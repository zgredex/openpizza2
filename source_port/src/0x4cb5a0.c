// ListDialog_Open: ported from Pizza Connection 2 at 0x4cb5a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cb5a0
#include "pc2_port.h"

void __cdecl ListDialog_Open(uint32_t arg1,uint32_t arg2,int arg3,int arg4)

{
  int value1;
  int value2;
  int local_4;
  
                    /* Opens the generic scrolled list dialog. */
  DAT_0057de30 = HighScore_BuildCityListWindow(&local_4);
  DAT_0057de5c = arg1;
  DAT_0057de68 = arg3;
  DAT_0057de54 = arg4;
  DAT_0057de58 = 0;
  Window_GadgetNotify_Text_SetText(DAT_0057de30,0x441,arg2);
  value1 = *(int *)(arg3 + 0x14);
  if (value1 < 0x14) {
    UI_RemoveObjectByKey(DAT_0057de30,0x462);
    value2 = 0x7e2;
    value1 = 0x7e2 - (0x13 - value1);
    if (value1 < 0x7e2) {
      do {
        UI_RemoveObjectByKey(DAT_0057de30,value2);
        UI_RemoveObjectByKey(DAT_0057de30,value2 + 1000);
        value2 = value2 + -1;
      } while (value1 < value2);
    }
  }
  else {
    DAT_0057de58 = arg4;
    if (*(int *)(arg3 + 0x14) < arg4 + 0x13) {
      DAT_0057de58 = value1 + -0x13;
    }
    Window_GadgetNotify_Slider_SetRange(DAT_0057de30,0x462,0,(value1 + -0x13) * 100,1);
    Window_GadgetNotify_Slider_SetValue(DAT_0057de30,0x462,DAT_0057de58 * 100,0);
    Window_GadgetNotify_Slider_SetChangeNotify(DAT_0057de30,0x462,1);
  }
  ListDialog_FillRows(DAT_0057de58);
  Window_ShowWindowById(DAT_0057c5e0,local_4);
  DAT_0057de6c = 1;
  return;
}
