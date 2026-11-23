// Branch_InitCityObjects: ported from Pizza Connection 2 at 0x480200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480200
#include "pc2_port.h"

void __thiscall Branch_InitCityObjects(void *self,uint16_t arg1)

{
  int value1;
  uint16_t uvalue2;
  int value3;
  int value4;
  void *this_00;
  int *ptr5;
  uint32_t unaff_EDI;
  int local_8;
  
  uvalue2 = 0;
  value4 = *(int *)((intptr_t)self + 0x30);
  value1 = *(int *)(*(int *)((intptr_t)self + 0x16f0) + 0x8c);
  value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  if (value3 == value4) {
    value4 = Game_HasKeyedRecordEntry(DAT_0057c670,7,*(int *)((intptr_t)self + 0x16f0));
    if (value4 == 0) {
      value4 = UI_Briefing_Printf((intptr_t)DAT_0057c670,3,4,4,1,*(int *)((intptr_t)self + 0x16f0),DAT_005828a8
                                 ,DAT_005819e8,unaff_EDI);
      Game_SetMessageField34(DAT_0057c670,value4,7);
    }
  }
  if (0 < value1) {
    local_8 = 0;
    do {
      this_00 = (void *)Game_MapRecordToGlobal(*(void **)((intptr_t)self + 0x16f0),local_8);
      value4 = State_Is2DOr2E((intptr_t)this_00);
      if (((((value4 == 0) && (*(int *)((intptr_t)this_00 + 0x74) != 0)) &&
           (value4 = *(int *)((intptr_t)this_00 + 0x30), value4 != 0x1d)) &&
          (((value4 != 0x1e && (value4 != 0x1f)) &&
           ((value4 != 0x17 && ((value4 != 0x16 && (value4 != 0xd)))))))) &&
         ((value4 != 0x2b &&
          (((((value4 != 0x2c && (value4 != 0x2d)) && (value4 != 0x2f)) &&
            ((value4 != 0x1a && (value4 != 0x1b)))) &&
           ((value4 != 0x1c && (*(char *)((intptr_t)this_00 + 0x81) == '\0')))))))) {
        *(uint8_t *)((intptr_t)this_00 + 0x81) = 1;
        if (*(short *)((intptr_t)this_00 + 0x40) == 9) {
          ptr5 = (int *)Game_ApplyObjectEvent((intptr_t)this_00);
          if (ptr5 != (int *)0x0) {
            UI_DrawCenteredSelectionRect(*(void **)((intptr_t)self + 0x14e0),ptr5);
          }
        }
        UI_SetChildState(this_00,arg1);
        Object_SyncChildState(this_00,(intptr_t)self,0);
        uvalue2 = 1;
        *(uint32_t *)((intptr_t)this_00 + *(int *)((intptr_t)self + 0x30) * 4 + 0xac) = 0;
      }
      local_8 = local_8 + 1;
    } while (local_8 < value1);
    if (uvalue2 != 0) {
      Sound_HandleEvent(DAT_0057ba0c,(intptr_t)self,0x25);
      if (9 < uvalue2) {
        uvalue2 = 10;
      }
      Game_AdjustPlayerObjectPercent
                (*(void **)((intptr_t)DAT_0057c670 + 0x90),*(int *)((intptr_t)self + 0x30),uvalue2);
    }
  }
  return;
}
