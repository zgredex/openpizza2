// Game_SearchObjectsByName: ported from Pizza Connection 2 at 0x48bb70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48bb70
#include "pc2_port.h"


void __thiscall Game_SearchObjectsByName(void *self,uint32_t *arg1)

{
  char cVar1;
  int value2;
  void *pvVar3;
  char *cptr4;
  void *this_00;
  uint32_t uvalue5;
  uint32_t uvalue6;
  uint32_t *uptr7;
  char *cptr8;
  uint32_t *uptr9;
  uint32_t *local_68;
  int local_64;
  int local_5c;
  char *local_54;
  void *local_50;
  uint32_t local_4c [15];
  void *pvStack_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Searches global object names and opens the result. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005583d6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_50 = operator_new(0x1c);
  local_4 = 0;
  if (local_50 == (void *)0x0) {
    local_68 = (uint32_t *)0x0;
  }
  else {
    local_68 = List_Construct(local_50,0);
  }
  local_4 = 0xffffffff;
  CRT_Strupr(arg1);
  local_5c = 0;
  value2 = Game_CountObjectsByState(self,-1);
  local_64 = 0;
  if (0 < value2) {
    do {
      pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x3c),local_64,(int *)0x0);
      uvalue5 = 0xffffffff;
      cptr4 = (char *)((intptr_t)pvVar3 + 4);
      do {
        cptr8 = cptr4;
        if (uvalue5 == 0) break;
        uvalue5 = uvalue5 - 1;
        cptr8 = cptr4 + 1;
        cVar1 = *cptr4;
        cptr4 = cptr8;
      } while (cVar1 != '\0');
      uvalue5 = ~uvalue5;
      uptr7 = (uint32_t *)(cptr8 + -uvalue5);
      uptr9 = local_4c;
      for (uvalue6 = uvalue5 >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
        *uptr9 = *uptr7;
        uptr7 = uptr7 + 1;
        uptr9 = uptr9 + 1;
      }
      for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
        *(char *)uptr9 = (char)*uptr7;
        uptr7 = (uint32_t *)((intptr_t)uptr7 + 1);
        uptr9 = (uint32_t *)((intptr_t)uptr9 + 1);
      }
      CRT_Strupr(local_4c);
      cptr4 = _strstr((char *)local_4c,(char *)arg1);
      if (cptr4 != (char *)0x0) {
        local_5c = local_5c + 1;
        this_00 = operator_new(0x58);
        local_4 = 1;
        if (this_00 == (void *)0x0) {
          local_54 = (char *)0x0;
        }
        else {
          local_54 = UI_ListEntry_Construct(this_00,(char *)((intptr_t)pvVar3 + 4),local_64);
        }
        local_4 = 0xffffffff;
        List_Add(local_68,local_54);
        local_50 = pvVar3;
      }
      local_64 = local_64 + 1;
    } while (local_64 < value2);
    if (local_5c != 0) {
      if (local_5c != 1) {
        CRT_QSort((int *)local_68[1],(uint32_t *)local_68[5],4,&LAB_0048bb20);
        UI_ShowScrollingListDialog(self,0xfffe79e7,DAT_00582ab4,DAT_00582420,(intptr_t)local_68,0,0);
        *(uint32_t *)((intptr_t)self + 0x278) = 0;
        ExceptionList = local_c;
        return;
      }
      if (local_54 != (char *)0x0) {
        (*(code *)**(uint32_t **)local_54)(1);
      }
      if (local_68 != (uint32_t *)0x0) {
        (**(code **)*local_68)(1);
      }
      Game_OpenObjectView(self,(intptr_t)local_50);
      ExceptionList = local_c;
      return;
    }
  }
  Game_ShowConfirmationDialog(self,0xffffffff,DAT_00582ab4,DAT_005828dc,0);
  if (local_68 == (uint32_t *)0x0) {
    ExceptionList = local_c;
    return;
  }
  (**(code **)*local_68)(1);
  ExceptionList = pvStack_10;
  return;
}
