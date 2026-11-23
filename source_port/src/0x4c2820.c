// ExclusiveImport_UpdatePage: ported from Pizza Connection 2 at 0x4c2820.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c2820
#include "pc2_port.h"

void __cdecl ExclusiveImport_UpdatePage(int *arg1)

{
  void *pvVar1;
  int *ptr2;
  int value3;
  int value4;
  int64_t lvalue5;
  uint32_t uvalue6;
  
                    /* Refreshes the exclusive-import supplier page. */
  pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                                (int *)0x0);
  ptr2 = (int *)Array_GetStride60(pvVar1,DAT_0057d730);
  Gadget_SetText(arg1,0x23b3,ptr2 + 0x11);
  Window_GadgetNotify_Slider_SetValue(arg1,0x549,*ptr2 / 10,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x54b,ptr2[1],0);
  uvalue6 = 0;
  lvalue5 = __ftol();
  Window_GadgetNotify_Slider_SetValue(arg1,0x54d,(intptr_t)lvalue5,uvalue6);
  uvalue6 = 0;
  lvalue5 = __ftol();
  Window_GadgetNotify_Slider_SetValue(arg1,0x54f,(intptr_t)lvalue5,uvalue6);
  SupplierMenu_FillClientRows(arg1);
  pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                                (int *)0x0);
  value3 = Game_FindRecordByField24(pvVar1,ptr2[4]);
  Game_CenterViewOnObject(value3);
  value3 = 0;
  do {
    value4 = Game_GetRatingPercent(DAT_0057c670,value3,*ptr2 / 10);
    Rating_UpdateBarByKey(arg1,0x23af,value3,value4,DAT_00581048);
    value3 = value3 + 1;
  } while (value3 < 8);
  return;
}
