// Menu_DeleteRecipeFromCompanyMenu: ported from Pizza Connection 2 at 0x49ed90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49ed90
#include "pc2_port.h"

int Menu_DeleteRecipeFromCompanyMenu(void)

{
  void *self;
  uint32_t *uptr1;
  int value2;
  uint32_t uvalue3;
  DWORD DVar4;
  uint3 uvalue6;
  int value5;
  int value7;
  char cVar8;
  uint8_t local_200 [512];
  
                    /* Deletes the selected recipe from the company menu. */
  self = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  cVar8 = *(char *)(DAT_0057cda0 + 0x1dc) == '\x01';
  uvalue3 = Game_HasRecordField14DC(self,DAT_0057cda0);
  if ((char)uvalue3 == '\x01') {
    cVar8 = '\x02';
  }
  DAT_0057cc38 = 0;
  if (cVar8 != '\0') {
    String_Format(local_200,DAT_00582890,DAT_0057cda0 + 4);
    Game_ShowQuestionDialog(DAT_0057c670,0xfffe798c,DAT_00581e34,local_200,0xfffe798d,0,-1,'\x01');
    DVar4 = WaitForSingleObject(DAT_0057c0d8,0);
    while (((DVar4 != 0 && (DAT_0057cc38 == 0)) && (*(int *)((intptr_t)DAT_0057c670 + 0x280) == 1))) {
      Window_ProcessMessageQueue(DAT_0057c5e0,0);
      Sleep(10);
      DVar4 = WaitForSingleObject(DAT_0057c0d8,0);
    }
  }
  uvalue6 = (uint3)((uint32_t)DAT_0057c670 >> 8);
  if (*(int *)((intptr_t)DAT_0057c670 + 0x280) == 0) {
    return (uint32_t)uvalue6 << 8;
  }
  if (DAT_0057cc38 == 2) {
    return (uint32_t)uvalue6 << 8;
  }
  uptr1 = *(uint32_t **)((intptr_t)DAT_0057c670 + 0x98);
  Game_FindCompanyIndex(self,(intptr_t)uptr1);
  value5 = Company_RemoveRecipe(self,uptr1);
  if (cVar8 == '\x02') {
    value2 = *(int *)((intptr_t)self + 0x15c);
    value7 = 0;
    if (0 < value2) {
      do {
        value5 = IDMap_Lookup((void *)((intptr_t)self + 0x148),value7,(int *)0x0);
        if (((value5 != 0) && (*(uint32_t **)(value5 + 0x14dc) != (uint32_t *)0x0)) &&
           (*(uint32_t **)(value5 + 0x14dc) == uptr1)) {
          value5 = Branch_ClearAssignedEmployee(value5);
        }
        value7 = value7 + 1;
      } while (value7 < value2);
    }
  }
  return CONCAT31((int3)((uint32_t)value5 >> 8),1);
}
