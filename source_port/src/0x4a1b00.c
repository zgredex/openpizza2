// LoadGameMenu_InitSlotList: ported from Pizza Connection 2 at 0x4a1b00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a1b00
#include "pc2_port.h"

void __cdecl LoadGameMenu_InitSlotList(void *arg1)

{
  int value1;
  void *self;
  int value2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Initializes the load-game slot list and rows. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055889b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  UI_SetPosition(arg1,SaveGameList_Destroy,0);
  self = operator_new(0x1c);
  local_4 = 0;
  if (self == (void *)0x0) {
    DAT_0057cfc8 = (uint32_t *)0x0;
  }
  else {
    DAT_0057cfc8 = List_Construct(self,0);
  }
  local_4 = 0xffffffff;
  SaveGame_Scan(DAT_0057cfc8,1);
  value1 = DAT_0057cfc8[5];
  DAT_0057cfcc = 0;
  value2 = 0x1f69;
  do {
    UI_ShowChildByID(arg1,value2);
    UI_ShowChildByID(arg1,value2 + 0xd);
    Array_SetField14ByKey(arg1,value2 + 0xd,0);
    value2 = value2 + -1;
  } while (0x1f5d < value2);
  UI_ShowChildByID(arg1,0x462);
  if (value1 + -1 < 0xd) {
    UI_RemoveObjectByKey(arg1,0x462);
    value2 = 0x1f69;
    if (value1 + 0x1f5c < 0x1f69) {
      do {
        UI_RemoveObjectByKey(arg1,value2);
        UI_RemoveObjectByKey(arg1,value2 + 0xd);
        value2 = value2 + -1;
      } while (value1 + 0x1f5c < value2);
    }
  }
  else {
    Window_GadgetNotify_Slider_SetRange(arg1,0x462,0,(value1 + -0x3d + (value1 + -1) * 4) * 0x14,1)
    ;
    Window_GadgetNotify_Slider_SetValue(arg1,0x462,0,0);
    Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x462,1);
  }
  LoadGameMenu_UpdateSlotRows(arg1,DAT_0057cfcc);
  ExceptionList = local_c;
  return;
}
