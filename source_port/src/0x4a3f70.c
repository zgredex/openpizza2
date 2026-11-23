// HeadquartersCompanyPage_Update: ported from Pizza Connection 2 at 0x4a3f70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a3f70
#include "pc2_port.h"

void __cdecl HeadquartersCompanyPage_Update(void *arg1)

{
  void *self;
  int value1;
  int value2;
  int value3;
  int *ptr4;
  
                    /* Refreshes the headquarters company-overview page. */
  self = arg1;
  value1 = *(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  value3 = *(int *)(value1 + 0x1d8);
  value1 = Game_GetPlayerFieldC20(value1);
  Sound_PlaySfxByIndex(DAT_0057ba0c,0x1c,value1);
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value3 + 8));
  value3 = 0;
  do {
    value2 = Game_GetPlayerBySlot(DAT_0057c670,value3);
    if (value2 == 0) {
      (&DAT_0057d240)[value3] = 0;
    }
    else {
      (&DAT_0057d240)[value3] = *(uint8_t *)(*(int *)(value1 + 0x48) + 0xac + value2);
    }
    value3 = value3 + 1;
  } while (value3 < 6);
  Window_GadgetNotify_Text_SetText(arg1,0x51b,value1 + 8);
  Personnel_SetEmployeePhotoByKey(arg1,0x23f0,value1);
  CompanyProfile_UpdateStatistics(arg1);
  value1 = 0x23c8;
  do {
    UI_RemoveObjectByKey(arg1,value1);
    value1 = value1 + 1;
  } while (value1 < 0x23e0);
  value1 = 0x23f1;
  do {
    UI_RemoveObjectByKey(arg1,value1);
    value1 = value1 + 1;
  } while (value1 < 0x23f5);
  ptr4 = &DAT_00568f2c;
  do {
    value1 = 4;
    do {
      UI_RemoveObjectByKey(arg1,*ptr4);
      ptr4 = ptr4 + 1;
      value1 = value1 + -1;
    } while (value1 != 0);
  } while ((intptr_t)ptr4 < 0x568f6c);
  UI_RemoveObjectByKey(arg1,0x23b4);
  DAT_0057d248 = 0;
  arg1 = (void *)0x0;
  value1 = 0;
  ptr4 = &DAT_0057d24c;
  do {
    value3 = Game_GetPlayerBySlot(DAT_0057c670,value1);
    if (value3 == 0) {
      *ptr4 = 0;
    }
    else {
      value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      value3 = *(int *)(value3 + 0x94 + value2 * 4);
      *ptr4 = value3;
      if (0 < value3) {
        arg1 = (void *)((intptr_t)arg1 + 1);
      }
    }
    ptr4 = ptr4 + 1;
    value1 = value1 + 1;
  } while ((intptr_t)ptr4 < 0x57d264);
  if ((intptr_t)arg1 < 5) {
    value1 = 0;
    if (0 < (intptr_t)arg1) {
      ptr4 = &DAT_00568f2c;
      do {
        UI_ShowChildByID(self,value1 + 0x23f1);
        value3 = 4;
        do {
          UI_ShowChildByID(self,*ptr4);
          ptr4 = ptr4 + 1;
          value3 = value3 + -1;
        } while (value3 != 0);
        value1 = value1 + 1;
      } while (value1 < (intptr_t)arg1);
    }
  }
  else {
    value1 = 0;
    ptr4 = &DAT_00568f2c;
    do {
      UI_ShowChildByID(self,value1 + 0x23f1);
      value3 = 4;
      do {
        UI_ShowChildByID(self,*ptr4);
        ptr4 = ptr4 + 1;
        value3 = value3 + -1;
      } while (value3 != 0);
      value1 = value1 + 1;
    } while ((intptr_t)ptr4 < 0x568f6c);
    UI_ShowChildByID(self,0x23b4);
    Window_GadgetNotify_Slider_SetRange(self,0x23b4,0,200,0);
    Window_GadgetNotify_Slider_SetValue(self,0x23b4,DAT_0057d248,0);
    Window_GadgetNotify_Slider_SetChangeNotify(self,0x23b4,1);
  }
  HeadquartersPage_FillCompetitorRows(self,DAT_0057d248,(intptr_t)arg1);
  return;
}
