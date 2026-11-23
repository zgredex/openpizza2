// Window_UpdateBranchInfoPage: ported from Pizza Connection 2 at 0x4b83f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b83f0
#include "pc2_port.h"

void __cdecl Window_UpdateBranchInfoPage(void *arg1,char arg2)

{
  void *self;
  int value1;
  int value2;
  uint8_t *bptr3;
  uint32_t unaff_EBP;
  uint32_t uvalue4;
  uint32_t unaff_EDI;
  bool flag5;
  uint8_t *uptr6;
  uint8_t *uptr7;
  int value8;
  uint8_t local_340 [64];
  uint8_t local_300 [64];
  uint8_t local_2c0 [64];
  uint8_t local_280 [64];
  uint8_t local_240 [64];
  uint8_t local_200 [256];
  uint8_t local_100 [256];
  
                    /* Updates the branch info page's type, flags, owner, and ratings. */
  uptr6 = local_340;
  String_Format(local_340,DAT_00582e4c,unaff_EDI);
  uptr7 = local_300;
  String_Format(uptr7,DAT_00582e4c,uptr6);
  uptr6 = local_2c0;
  String_Format(uptr6,DAT_00582e4c,uptr7);
  String_Format(local_280,DAT_00582e4c,uptr6);
  if (arg2 == '\0') {
    self = *(void **)((intptr_t)DAT_0057c670 + 0x9c);
    DAT_0057d6b8 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x30));
  }
  else {
    value1 = *(int *)((intptr_t)DAT_0057c670 + 0x218);
    DAT_0057d6b8 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value1 + 8));
    self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057d6b8 + 0x148),*(int *)(value1 + 0x2c),
                                (int *)0x0);
    Window_GadgetNotify_Text_SetText(arg1,0x483,(intptr_t)self + 4);
  }
  value1 = Player_FindRecordType2ByKey(DAT_0057d6b8,*(int *)((intptr_t)self + 0x3c));
  if ((value1 == 0) || (*(int *)(value1 + 0x20) < 1)) {
    Window_GadgetNotify_Text_SetText(arg1,0x495,DAT_005829f0);
    Window_GadgetNotify_Text_SetText(arg1,0x496,DAT_005829f0);
    bptr3 = DAT_00582e4c;
  }
  else {
    String_Format(local_240,&DAT_005630d0,
                  *(uint32_t *)(&DAT_00583504 + *(int *)(value1 + 0x10) * 4));
    Window_GadgetNotify_Text_SetText(arg1,0x495,local_240);
    flag5 = (*(uint8_t *)(value1 + 0x14) & 8) != 0;
    if (flag5) {
      String_Format(local_340,&DAT_005630d0,DAT_00582654);
    }
    uvalue4 = (uint32_t)flag5;
    if ((*(uint8_t *)(value1 + 0x14) & 4) != 0) {
      String_Format(local_340 + uvalue4 * 0x40,&DAT_005630d0,DAT_00582910);
      uvalue4 = uvalue4 + 1;
    }
    if ((*(uint8_t *)(value1 + 0x14) & 2) != 0) {
      String_Format(local_340 + uvalue4 * 0x40,&DAT_005630d0,DAT_00581af0);
      uvalue4 = uvalue4 + 1;
    }
    if ((*(uint8_t *)(value1 + 0x14) & 1) != 0) {
      String_Format(local_340 + uvalue4 * 0x40,&DAT_005630d0,DAT_00581b80);
      uvalue4 = uvalue4 + 1;
    }
    if (uvalue4 < 3) {
      if (uvalue4 == 2) {
        String_Format(local_200,(uint8_t *)s__s__s_0056a8a8,local_340);
      }
      else {
        String_Format(local_200,&DAT_005630d0,local_340);
      }
      String_Format(local_100,DAT_00582e4c,unaff_EBP);
    }
    else if (uvalue4 == 3) {
      String_Format(local_200,(uint8_t *)s__s__s_0056a8a8,local_340);
      String_Format(local_100,&DAT_005630d0,local_2c0);
    }
    else {
      String_Format(local_200,(uint8_t *)s__s__s_0056a8a8,local_340);
      String_Format(local_100,(uint8_t *)s__s__s_0056a8a8,local_2c0);
    }
    if (*(int *)(value1 + 0x14) == 0) {
      uptr7 = local_200;
      String_Format(uptr7,&DAT_005630d0,DAT_005826e4);
      String_Format(local_100,DAT_00582e4c,uptr7);
    }
    Window_GadgetNotify_Text_SetText(arg1,0x496,local_200);
    bptr3 = local_100;
  }
  Window_GadgetNotify_Text_SetText(arg1,0x4aa,bptr3);
  Window_GadgetNotify_Text_SetText(arg1,0x488,(intptr_t)DAT_0057d6b8 + 8);
  if (arg2 == '\0') {
    value1 = 0x1f51;
  }
  else {
    value1 = 0x1f53;
  }
  Personnel_SetEmployeePhotoByKey(arg1,value1,(intptr_t)DAT_0057d6b8);
  Chart_DrawGroupMatrix(arg1,0x4a0,*(int *)((intptr_t)DAT_0057d6b8 + 0x48),(intptr_t)self);
  value1 = 0;
  do {
    value8 = DAT_00582998;
    value2 = Branch_GetCustomerGroupRating(self,value1,1);
    Rating_UpdateBarByKey(arg1,0x46f,value1,value2,value8);
    value1 = value1 + 1;
  } while (value1 < 8);
  return;
}
