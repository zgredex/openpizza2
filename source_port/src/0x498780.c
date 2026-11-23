// Menu_DeleteRecipeByIndex: ported from Pizza Connection 2 at 0x498780.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x498780
#include "pc2_port.h"

uint32_t Menu_DeleteRecipeByIndex(void)

{
  void *self;
  int value1;
  int value2;
  uint32_t uvalue3;
  DWORD DVar4;
  int value5;
  int value6;
  char cVar7;
  uint8_t local_200 [512];
  
                    /* Deletes a recipe by menu index. */
  self = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  value2 = IDMap_Lookup((void *)((intptr_t)self + 0x110),DAT_0057c9fc,(int *)0x0);
  cVar7 = *(char *)(value2 + 0x1dc) == '\x01';
  uvalue3 = Game_HasRecordField14DC(self,value2);
  if ((char)uvalue3 == '\x01') {
    cVar7 = '\x02';
  }
  DAT_0057c9f4 = 0;
  if (cVar7 != '\0') {
    String_Format(local_200,DAT_00582890,value2 + 4);
    Game_ShowQuestionDialog(DAT_0057c670,0xfffe798c,DAT_00581e34,local_200,0xfffe798d,0,-1,'\x01');
    DVar4 = WaitForSingleObject(DAT_0057c0d8,0);
    while (((DVar4 != 0 && (DAT_0057c9f4 == 0)) && (*(int *)((intptr_t)DAT_0057c670 + 0x280) == 1))) {
      Window_ProcessMessageQueue(DAT_0057c5e0,0);
      Sleep(10);
      DVar4 = WaitForSingleObject(DAT_0057c0d8,0);
    }
  }
  if (*(uint32_t *)((intptr_t)DAT_0057c670 + 0x280) == 0) {
    return 0;
  }
  if (DAT_0057c9f4 == 2) {
    return *(uint32_t *)((intptr_t)DAT_0057c670 + 0x280) & 0xffffff00;
  }
  IDMap_RemoveRecursive((void *)((intptr_t)self + 0x110),DAT_0057c9fc);
  if (cVar7 == '\x02') {
    value1 = *(int *)((intptr_t)self + 0x15c);
    value6 = 0;
    if (0 < value1) {
      do {
        value5 = IDMap_Lookup((void *)((intptr_t)self + 0x148),value6,(int *)0x0);
        if (((value5 != 0) && (*(int *)(value5 + 0x14dc) != 0)) && (*(int *)(value5 + 0x14dc) == value2)
           ) {
          Branch_ClearAssignedEmployee(value5);
        }
        value6 = value6 + 1;
      } while (value6 < value1);
    }
  }
  value2 = DAT_0057c9fc + -1;
  DAT_0057c9fc = value2;
  if (value2 < 0) {
    DAT_0057c9fc = 0;
  }
  return CONCAT31((int3)((uint32_t)value2 >> 8),1);
}
