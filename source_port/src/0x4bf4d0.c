// SchoolMenu_UpdatePage: ported from Pizza Connection 2 at 0x4bf4d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bf4d0
#include "pc2_port.h"

void __cdecl SchoolMenu_UpdatePage(void *arg1)

{
  int *ptr1;
  int value2;
  int *ptr3;
  int value4;
  int local_120 [8];
  int local_100 [64];
  
  value4 = *(int *)(DAT_0057c670 + 0x218);
  ptr3 = local_120;
                    /* Refreshes the school page and competitor matrix. */
  for (value2 = 8; value2 != 0; value2 = value2 + -1) {
    *ptr3 = 0;
    ptr3 = ptr3 + 1;
  }
  Window_GadgetNotify_Text_SetText
            (arg1,0x43b,*(uint32_t *)(&DAT_005840d4 + *(int *)(value4 + 4) * 4));
  value2 = Game_CanShowObject(value4);
  if (value2 == 0) {
    UI_RemoveObjectByKey(arg1,0x1f42);
    UI_RemoveObjectByKey(arg1,0x1f43);
  }
  Submenu_SetObjectPicture(arg1,*(int *)(value4 + 0x20),1,0x1f4c,-1,value4);
  SchoolMenu_FillLocalStructure(arg1);
  Stats_BuildCompetitorMatrix(local_100);
  ptr3 = local_120;
  ptr1 = local_100;
  value4 = 8;
  do {
    value2 = 8;
    do {
      if (*ptr3 < *ptr1) {
        *ptr3 = *ptr1;
      }
      ptr1 = ptr1 + 1;
      value2 = value2 + -1;
    } while (value2 != 0);
    ptr3 = ptr3 + 1;
    value4 = value4 + -1;
  } while (value4 != 0);
  value4 = 0;
  ptr3 = local_120;
  do {
    Rating_UpdateBarByKey(arg1,0x1fd4,value4,*ptr3,DAT_005822d4);
    value4 = value4 + 1;
    ptr3 = ptr3 + 1;
  } while (value4 < 8);
  return;
}
