// IngredientMenu_HandleInput: ported from Pizza Connection 2 at 0x4c67f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c67f0
#include "pc2_port.h"

void __cdecl IngredientMenu_HandleInput(void *arg1,int arg2,int arg3,uint32_t *arg4)

{
  int value1;
  void *self;
  int value2;
  uint32_t *uptr3;
  
  if (arg3 < 0x19) {
    if (arg3 != 0x18) {
      if (arg3 == -0x18657) {
        if (arg2 < 0x131) {
          if (arg2 == 0x130) {
LAB_004c69a5:
            value2 = Array_GetField20ByKey(arg1,0x42d);
            if (value2 != 0) {
              value2 = Window_GadgetNotify_Slider_GetValue(arg1,0x42d,0);
              if (arg2 == 0x136) {
                value2 = value2 + 0x514;
              }
              else {
                value2 = value2 + -0x514;
              }
              Window_GadgetNotify_Slider_SetValue(arg1,0x42d,value2,0);
              uptr3 = (uint32_t *)Window_GadgetNotify_Slider_GetValue(arg1,0x42d,0);
              IngredientMenu_HandleInput(arg1,0x42d,0x19,uptr3);
            }
            *arg4 = 1;
            return;
          }
          if (arg2 == 0xd) {
            IngredientMenu_HandleInput(arg1,DAT_0056b154 + 0x444,1,(uint32_t *)0x0);
            *arg4 = 1;
            return;
          }
          if (arg2 == 0x12f) {
            if (DAT_0056b154 < 0) {
              DAT_0056b154 = 0xc;
            }
            else {
              DAT_0056b154 = DAT_0056b154 + -1;
              if (-1 < DAT_0056b154) goto joined_r0x004c692c;
              DAT_0056b154 = 0xc;
            }
            do {
              value2 = Array_GetField20ByKey(arg1,DAT_0056b154 + 0x451);
              if (value2 != 0) break;
              DAT_0056b154 = DAT_0056b154 + -1;
joined_r0x004c692c:
            } while (0 < DAT_0056b154);
            goto LAB_004c6954;
          }
        }
        else {
          if (arg2 == 0x135) {
            if ((DAT_0056b154 < 0) || (DAT_0056b154 = DAT_0056b154 + 1, DAT_0056b154 == 0xd)) {
              DAT_0056b154 = 0;
            }
            value2 = Array_GetField20ByKey(arg1,DAT_0056b154 + 0x451);
            if (value2 == 0) {
              DAT_0056b154 = 0;
            }
LAB_004c6954:
            UI_WarpCursorToControl(arg1,DAT_0056b154 + 0x451);
            *arg4 = 1;
            return;
          }
          if (arg2 == 0x136) goto LAB_004c69a5;
        }
      }
      else if (arg3 == 1) {
        if (arg2 == 0x443) {
          Game_CloseSelectionDialog((intptr_t)DAT_0057c670);
          return;
        }
        if ((0x443 < arg2) && (arg2 < 0x451)) {
          value1 = *(int *)((intptr_t)DAT_0057c670 + 0x274);
          value2 = *(int *)((intptr_t)DAT_0057c670 + 0x280) + -0x444 + arg2;
          Object_SetField280(DAT_0057c670,value2);
          UI_SyncSelectedChild((intptr_t)DAT_0057c670);
          if (*(int *)((intptr_t)DAT_0057c670 + 0x278) == 0) {
            UI_QueueChildCommand(DAT_0057c5e0,value1,1);
            Game_CloseSelectionDialog((intptr_t)DAT_0057c670);
            Object_SetField280(DAT_0057c670,value2);
            return;
          }
          self = (void *)Game_GetActiveScreenOrFallback((intptr_t)DAT_0057c670);
          UI_QueueControlCommand(self,value1,0x23,1);
          Game_CloseSelectionDialog((intptr_t)DAT_0057c670);
          Object_SetField280(DAT_0057c670,value2);
          return;
        }
      }
    }
  }
  else if (arg3 == 0x19) {
    if (arg2 == 0x42d) {
      IngredientDialog_FillRows(DAT_0057c670,(intptr_t)arg4 / 100);
      Object_SetField280(DAT_0057c670,(intptr_t)arg4 / 100);
    }
  }
  else if (arg3 == 0x1f) {
    DAT_0056b154 = 0xffffffff;
    return;
  }
  return;
}
