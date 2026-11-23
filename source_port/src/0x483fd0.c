// SubMenu_SetSelection: ported from Pizza Connection 2 at 0x483fd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x483fd0
#include "pc2_port.h"

uint32_t __thiscall
SubMenu_SetSelection(void *self,int arg1,int arg2,int arg3,int arg4)

{
  int value1;
  int value2;
  int value3;
  void *pvVar4;
  
  value2 = arg2;
                    /* Switches the active submenu selection and rebuilds the matching page. */
  value1 = arg1;
  if ((arg1 == 0) || (arg1 != *(int *)((intptr_t)self + 0x218))) {
    if (((arg4 != 0) || ((arg2 == 0 || (arg2 != *(int *)((intptr_t)self + 0x21c))))) &&
       ((arg3 == 0 || (arg3 != *(int *)((intptr_t)self + 0x220))))) {
      UI_DestroyWindowAt((uint32_t *)((intptr_t)self + 0x264));
      if (value1 == 0) {
        value3 = arg3;
      }
      else {
        value3 = UI_GetActionDuration(self,value1);
        *(int *)((intptr_t)self + 0x218) = value1;
        *(uint32_t *)((intptr_t)self + 0x21c) = 0;
        *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
        *(uint32_t *)((intptr_t)self + 0x220) = 0;
      }
      if (value2 != 0) {
        value3 = Game_GetRecordActionState(self,value2);
        *(int *)((intptr_t)self + 0x21c) = value2;
        *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
        *(uint32_t *)((intptr_t)self + 0x218) = 0;
        *(uint32_t *)((intptr_t)self + 0x220) = 0;
      }
      switch(*(uint32_t *)((intptr_t)self + 0x290)) {
      case 1:
        *(uint32_t *)((intptr_t)self + 700) = *(uint32_t *)((intptr_t)self + 0x29c);
        *(uint32_t *)((intptr_t)self + 0x29c) = 10;
        SubMenu_UpdateButtonStatesVariant1(*(void **)((intptr_t)self + 0x260));
        break;
      case 2:
      case 3:
        UI_DestroyWindowAt((uint32_t *)((intptr_t)self + 0x260));
        *(uint32_t *)((intptr_t)self + 700) = *(uint32_t *)((intptr_t)self + 0x29c);
        *(uint32_t *)((intptr_t)self + 0x29c) = 10;
        pvVar4 = UI_CreateInfoPanel(&arg1);
        *(uint32_t *)((intptr_t)self + 0x260) = pvVar4;
        SubMenu_UpdateButtonStatesVariant1(pvVar4);
        break;
      case 4:
        *(uint32_t *)((intptr_t)self + 0x2c8) = *(uint32_t *)((intptr_t)self + 0x2a8);
        *(uint32_t *)((intptr_t)self + 0x2a8) = 10;
      }
      value1 = arg3;
      if (arg3 != 0) {
        value3 = Game_MapPlayerStatusToAnimation(arg3);
        *(int *)((intptr_t)self + 0x220) = value1;
        *(uint32_t *)((intptr_t)self + 0x21c) = 0;
        *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
        *(uint32_t *)((intptr_t)self + 0x218) = 0;
      }
      pvVar4 = *(void **)((intptr_t)self + 0x260);
      Window_GadgetNotify_Button_SetState(pvVar4,0x3fd,1);
      Array_ToggleObjectActive(pvVar4,0x3fd,1);
      UI_SetChildVisibleByID(pvVar4,0x3fd,1);
      *(int *)((intptr_t)self + 0x2e4) = value3;
      switch(*(uint32_t *)((intptr_t)self + 0x290)) {
      case 1:
        pvVar4 = SubMenu_BuildSelectedPage(self,(int *)0x0);
        Window_ShowWindowById(DAT_0057c5e0,(intptr_t)pvVar4);
        return 0;
      case 2:
        *(uint32_t *)((intptr_t)self + 0x290) = 1;
        pvVar4 = SubMenu_BuildSelectedPage(self,(int *)0x0);
        Window_ShowWindowById(DAT_0057c5e0,(intptr_t)pvVar4);
        Window_ShowWindowById(DAT_0057c5e0,arg1);
        return 0;
      case 3:
        *(uint32_t *)((intptr_t)self + 0x290) = 1;
        pvVar4 = SubMenu_BuildSelectedPage(self,(int *)0x0);
        Window_ShowWindowById(DAT_0057c5e0,(intptr_t)pvVar4);
        Window_ShowWindowById(DAT_0057c5e0,arg1);
        break;
      case 4:
        pvVar4 = SubMenu_CreateBuildingPage(self);
        Window_ShowWindowById(DAT_0057c5e0,(intptr_t)pvVar4);
        return 0;
      }
    }
  }
  else if (*(int *)(arg1 + 4) == 0xf) {
    return 0xf;
  }
  return 0;
}
