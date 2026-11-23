// FreePlaySubmenu_InitSaveGamePage: ported from Pizza Connection 2 at 0x4ce450.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ce450
#include "pc2_port.h"


void __cdecl FreePlaySubmenu_InitSaveGamePage(void *arg1)

{
  int value1;
  void *pvVar2;
  char *cptr3;
  int value4;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Initializes the free-play load-game page and save rows. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558cd6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  UI_SetPosition(arg1,&LAB_004ce3b0,0);
  Window_GadgetNotify_Text_SetText(arg1,0x440,DAT_00582464);
  Window_GadgetNotify_Text_SetText(arg1,0x441,DAT_00581ac0);
  pvVar2 = operator_new(0x1c);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    DAT_0057df88 = (uint32_t *)0x0;
  }
  else {
    DAT_0057df88 = List_Construct(pvVar2,0);
  }
  local_4 = 0xffffffff;
  DAT_0057df8c = 0;
  SaveGame_Scan(DAT_0057df88,0);
  value1 = DAT_0057df88[5];
  value4 = value1 + -1;
  if (value4 < 1) {
    value4 = 0x7e2;
    do {
      UI_RemoveObjectByKey(arg1,value4);
      UI_RemoveObjectByKey(arg1,value4 + 100);
      value4 = value4 + -1;
    } while (2000 < value4);
    UI_RemoveObjectByKey(arg1,0x462);
    pvVar2 = operator_new(0x58);
    local_4 = 1;
    if (pvVar2 == (void *)0x0) {
      cptr3 = (char *)0x0;
    }
    else {
      cptr3 = UI_ListEntry_Construct(pvVar2,DAT_00581ab4,0xffffffff);
    }
    local_4 = 0xffffffff;
    List_Add(DAT_0057df88,cptr3);
  }
  else if (value4 < 0x13) {
    UI_RemoveObjectByKey(arg1,0x462);
    value4 = 0x7e2;
    if (value1 + 1999 < 0x7e2) {
      do {
        UI_RemoveObjectByKey(arg1,value4);
        UI_RemoveObjectByKey(arg1,value4 + 100);
        value4 = value4 + -1;
      } while (value1 + 1999 < value4);
    }
  }
  else {
    Window_GadgetNotify_Slider_SetRange(arg1,0x462,0,(value1 + -0x5b + value4 * 4) * 0x14,1);
    Window_GadgetNotify_Slider_SetValue(arg1,0x462,0,0);
    Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x462,1);
  }
  FreePlaySubmenu_FillSaveGameRows(arg1,DAT_0057df8c);
  ExceptionList = local_c;
  return;
}
