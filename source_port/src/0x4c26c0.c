// SupplierMenu_FillClientRows: ported from Pizza Connection 2 at 0x4c26c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c26c0
#include "pc2_port.h"

void __cdecl SupplierMenu_FillClientRows(int *arg1)

{
  int value1;
  int *self;
  void *this_00;
  int value2;
  uint32_t uvalue3;
  int value4;
  int value5;
  int *ptr6;
  int local_20;
  uint8_t local_14 [20];
  
  self = arg1;
  this_00 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4)
                                 ,(int *)0x0);
  value2 = Array_GetStride60(this_00,DAT_0057d730);
  value5 = 0;
  IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x218) + 0x28),
               (int *)0x0);
  value4 = 6;
  ptr6 = (int *)(value2 + 0x2c);
  do {
    value1 = *ptr6;
    ptr6 = ptr6 + 1;
    value5 = value5 + value1;
    value4 = value4 + -1;
  } while (value4 != 0);
  ptr6 = &DAT_0056ada8;
  do {
    Window_GadgetNotify_Text_SetText(arg1,*ptr6,DAT_00582e4c);
    Window_GadgetNotify_Text_SetText(arg1,*ptr6 + 1,DAT_00582e4c);
    ptr6 = ptr6 + 1;
  } while ((intptr_t)ptr6 < 0x56adc0);
  ptr6 = &DAT_0056ada8;
  local_20 = 0;
  arg1 = (int *)(value2 + 0x2c);
  do {
    value2 = Game_GetPlayerBySlot(DAT_0057c670,local_20);
    if (value2 != 0) {
      uvalue3 = Player_HasRecordWithField30(DAT_0057d730,*(int *)(value2 + 0x48));
      if ((char)uvalue3 != '\0') {
        if (value5 < 1) {
          value4 = 0;
        }
        else {
          value4 = (*arg1 * 100) / value5;
        }
        Window_GadgetNotify_Text_SetTextColor(self,*ptr6,*(uint32_t *)(value2 + 0x1dc));
        Window_GadgetNotify_Text_SetText(self,*ptr6,value2 + 8);
        String_Format(local_14,(uint8_t *)s__d____00568834,value4);
        Window_GadgetNotify_Text_SetText(self,*ptr6 + 1,local_14);
        ptr6 = ptr6 + 1;
      }
    }
    local_20 = local_20 + 1;
    arg1 = arg1 + 1;
  } while (local_20 < 6);
  return;
}
