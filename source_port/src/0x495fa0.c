// Menu_OpenRecipePicker: ported from Pizza Connection 2 at 0x495fa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x495fa0
#include "pc2_port.h"


void Menu_OpenRecipePicker(void)

{
  int value1;
  void *pvVar2;
  char *cptr3;
  int value4;
  int value5;
  int value6;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Opens the recipe picker or its error message. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558541;
  local_c = ExceptionList;
  value1 = *(int *)(DAT_0057c700 + 0x124);
  value5 = 0;
  value6 = *(int *)((intptr_t)DAT_0057c670 + 0x9c);
  if (value1 == 0) {
    ExceptionList = &local_c;
    Game_ShowConfirmationDialog(DAT_0057c670,0xfffe79af,DAT_0058282c,DAT_00581698,0);
    ExceptionList = local_c;
    return;
  }
  ExceptionList = &local_c;
  pvVar2 = operator_new(0x1c);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    DAT_0057c710 = (uint32_t *)0x0;
  }
  else {
    DAT_0057c710 = List_Construct(pvVar2,0);
  }
  local_4 = 0xffffffff;
  if (*(int *)(value6 + 0x14dc) != 0) {
    pvVar2 = operator_new(0x58);
    value5 = 1;
    local_4 = 1;
    if (pvVar2 == (void *)0x0) {
      cptr3 = (char *)0x0;
    }
    else {
      cptr3 = UI_ListEntry_Construct(pvVar2,DAT_00582aa4,0);
    }
    local_4 = 0xffffffff;
    List_Add(DAT_0057c710,cptr3);
  }
  value6 = 0;
  if (0 < value1) {
    do {
      value4 = IDMap_Lookup((void *)(DAT_0057c700 + 0x110),value6,(int *)0x0);
      if (*(char *)(value4 + 0x1dc) == '\0') {
        pvVar2 = operator_new(0x58);
        local_4 = 2;
        if (pvVar2 == (void *)0x0) {
          cptr3 = (char *)0x0;
        }
        else {
          cptr3 = UI_ListEntry_Construct(pvVar2,(char *)(value4 + 4),value6 + 1);
        }
        local_4 = 0xffffffff;
        List_Add(DAT_0057c710,cptr3);
        value5 = value5 + 1;
      }
      value6 = value6 + 1;
    } while (value6 < value1);
  }
  if (value5 == 0) {
    Game_ShowConfirmationDialog(DAT_0057c670,0xfffe79af,DAT_0058282c,DAT_00581a00,0);
    ExceptionList = local_c;
    return;
  }
  UI_ShowScrollingListDialog
            (DAT_0057c670,0xfffe7986,DAT_0058282c,DAT_00581208,(intptr_t)DAT_0057c710,0,0);
  ExceptionList = local_c;
  return;
}
