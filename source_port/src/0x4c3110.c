// FurnitureMenu_WindowProc: ported from Pizza Connection 2 at 0x4c3110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c3110
#include "pc2_port.h"

void __cdecl FurnitureMenu_WindowProc(void *arg1,int arg2,int arg3)

{
  void *pvVar1;
  char *self;
  int value2;
  int value3;
  char *pvVar4;
  int value5;
  int value6;
  int value7;
  int local_4;
  
                    /* Handles furniture/renovation submenu input. */
  if (arg3 == 1) {
    pvVar1 = *(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x9c) + 0x14e0);
    if (*(int *)((intptr_t)DAT_0057c670 + 0x220) != 0) {
      IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x74),
                   *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x220) + 4),(int *)0x0);
      if (arg2 < 0x1f41) {
        if (arg2 == 8000) {
          UI_ShowHelpTopicDialog(-0x51);
          return;
        }
        if (arg2 == 0x5bd) {
          self = *(void **)((intptr_t)DAT_0057c670 + 0x9c);
          value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x30));
          value3 = Game_GetPlayerCity(value2);
          value2 = *(int *)((intptr_t)self + 0x170c);
          value6 = 0;
          value7 = 0;
          arg2 = 0;
          if (0 < value2) {
            do {
              pvVar4 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x16f8),value7,(int *)0x0);
              value5 = Game_ComputeEventValue(pvVar4,value3,&local_4);
              value6 = value6 + value5;
              value7 = value7 + 1;
            } while (value7 < value2);
            arg2 = value6;
          }
          Game_CanAfford(self,5,(float)(intptr_t)(arg2),'\0',-1);
          value2 = *(int *)((intptr_t)self + 0x170c);
          value3 = 0;
          if (0 < value2) {
            do {
              pvVar4 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x16f8),value3,(int *)0x0);
              if (*(int *)((intptr_t)pvVar4 + 0xc) < 1) {
                Game_UpdateObject2(pvVar4,pvVar1);
              }
              else {
                Game_SetModeByte(pvVar4,100);
              }
              value3 = value3 + 1;
            } while (value3 < value2);
            return;
          }
        }
        else if (arg2 == 0x5be) {
          Game_ShowQuestionDialog
                    (DAT_0057c670,0xfffe796e,DAT_005827a4,DAT_00580f60,0xffffffff,0,-1,'\0');
          return;
        }
      }
      else if ((0x1f62 < arg2) && (arg2 < 0x1f66)) {
        DAT_0056adec = arg2 + -0x1f63;
        Window_UpdateFurniturePage(arg1);
      }
    }
  }
  else if (arg3 == 0x23) {
    if (arg2 == -0x18692) {
      Game_MarkAllObjectsDirty(*(void **)((intptr_t)DAT_0057c670 + 0x9c),1);
      return;
    }
    if ((arg2 == -0x1863b) || (arg2 == -0x1861b)) {
      Window_UpdateFurniturePage(arg1);
      return;
    }
  }
  return;
}
