// UI_ShowRecipeChoiceList: ported from Pizza Connection 2 at 0x49fad0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49fad0
#include "pc2_port.h"


void __cdecl UI_ShowRecipeChoiceList(void *arg1)

{
  void *pvVar1;
  uint32_t *self;
  int value2;
  char *cptr3;
  int value4;
  int value5;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Shows the current player's recipe choice list. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005587b6;
  local_c = ExceptionList;
  value4 = 0;
  if (0 < *(int *)(DAT_0057cd98 + 0x124)) {
    ExceptionList = &local_c;
    Window_GadgetNotify_Button_SetState(arg1,0x3fc,1);
    pvVar1 = operator_new(0x1c);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      self = (uint32_t *)0x0;
    }
    else {
      self = List_Construct(pvVar1,0);
    }
    local_4 = 0xffffffff;
    if (0 < *(int *)(DAT_0057cd98 + 0x124)) {
      do {
        pvVar1 = operator_new(0x58);
        local_4 = 1;
        if (pvVar1 == (void *)0x0) {
          cptr3 = (char *)0x0;
        }
        else {
          value5 = value4;
          value2 = IDMap_Lookup((void *)(DAT_0057cd98 + 0x110),value4,(int *)0x0);
          cptr3 = UI_ListEntry_Construct(pvVar1,(char *)(value2 + 4),value5);
        }
        local_4 = 0xffffffff;
        List_Add(self,cptr3);
        value4 = value4 + 1;
      } while (value4 < *(int *)(DAT_0057cd98 + 0x124));
    }
    CityOverviewDialog_Show
              (DAT_0057c670,0xfffe798e,DAT_00582c34,DAT_00582c40,self,DAT_0057cd9c,arg1);
  }
  ExceptionList = local_c;
  return;
}
