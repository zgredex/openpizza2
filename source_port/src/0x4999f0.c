// RecipeEditorPage_Update: ported from Pizza Connection 2 at 0x4999f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4999f0
#include "pc2_port.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl RecipeEditorPage_Update(void *arg1,char arg2)

{
  void *self;
  int value1;
  int value2;
  
                    /* Fills the create-recipe editor page. */
  DAT_00568914 = 0xffffffff;
  DAT_0057ca1c = 0;
  DAT_0057ca2c = 0;
  UI_SetPosition(arg1,&LAB_004995b0,0);
  *(uint32_t *)(DAT_0057c5e0 + 0x831c) = 1;
  if (arg2 != '\0') {
    UI_Group_Create(arg1,0,6,0x4eb);
  }
  Window_GadgetNotify_Button_SetState(arg1,(&DAT_00568914)[_DAT_00568910],1);
  if (arg2 != '\0') {
    UI_Group_Create(arg1,1,0xc,0x4ed);
  }
  value2 = 0x509;
  do {
    Array_SetField14ByKey(arg1,value2,0);
    value2 = value2 + 1;
  } while (value2 < 0x515);
  value2 = 0;
  do {
    UI_SetChildLabelText(arg1,value2 + 0x4ed,1,(char *)0x0);
    value2 = value2 + 1;
  } while (value2 < 0xc);
  UI_RemoveObjectByKey(arg1,0x507);
  if (DAT_0057cda0 == 0) {
    Window_GadgetNotify_Text_SetText(arg1,0x448,DAT_00582d50);
    DAT_0057ca10 = 0;
  }
  else {
    Window_GadgetNotify_Text_SetText(arg1,0x448,DAT_0057cda0 + 4);
    DAT_0057ca10 = Game_CountRecordsWithoutFlag(DAT_0057cda0);
    if (*(char *)(DAT_0057cda0 + 0x1dd) == '\x01') {
      UI_ShowChildByID(arg1,0x507);
    }
  }
  IngredientPanel_UpdatePage(arg1);
  Gadget_SetText(arg1,0x4e8,DAT_00582cc4);
  self = *(void **)(DAT_0057c670 + 0x98);
  if (self == (void *)0x0) {
    value2 = 0;
    do {
      Rating_UpdateBarByKey(arg1,0x4df,value2,0,0);
      value2 = value2 + 1;
    } while (value2 < 8);
    return;
  }
  value2 = 0;
  do {
    value1 = Game_MapInputIndex(self,value2);
    Rating_UpdateBarByKey(arg1,0x4df,value2,value1,DAT_0058155c);
    value2 = value2 + 1;
  } while (value2 < 8);
  return;
}
