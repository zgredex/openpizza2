// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x4a0a70.c:20:23: error: use of undeclared identifier 'SaveGameMenu_DestroyList'
// SaveGameMenu_Init: ported from Pizza Connection 2 at 0x4a0a70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a0a70
#include "pc2_port.h"

void __cdecl SaveGameMenu_Init(void *arg1)

{
  int value1;
  void *self;
  int value2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055880b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  UI_SetPosition(arg1,SaveGameMenu_DestroyList,0);
  self = operator_new(0x1c);
  local_4 = 0;
  if (self == (void *)0x0) {
    DAT_0057cdb4 = (uint32_t *)0x0;
  }
  else {
    DAT_0057cdb4 = List_Construct(self,0);
  }
  local_4 = 0xffffffff;
  SaveGame_Scan(DAT_0057cdb4,0);
  value1 = DAT_0057cdb4[5];
  DAT_0057cebc = 0;
  if (value1 + -1 < 0xd) {
    UI_RemoveObjectByKey(arg1,0x462);
    value2 = 0x450;
    if (value1 + 0x443 < 0x450) {
      do {
        UI_RemoveObjectByKey(arg1,value2);
        UI_RemoveObjectByKey(arg1,value2 + 0xf);
        value2 = value2 + -1;
      } while (value1 + 0x443 < value2);
    }
  }
  else {
    Window_GadgetNotify_Slider_SetRange(arg1,0x462,0,(value1 + -0x3d + (value1 + -1) * 4) * 0x14,1)
    ;
    Window_GadgetNotify_Slider_SetValue(arg1,0x462,0,0);
    Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x462,1);
  }
  SaveGameMenu_UpdateSlotRows(arg1,DAT_0057cebc);
  ExceptionList = local_c;
  return;
}
