// AnnoyancesPage_FillCosts: ported from Pizza Connection 2 at 0x4b5ac0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b5ac0
#include "pc2_port.h"

void __cdecl AnnoyancesPage_FillCosts(void *arg1)

{
  void *self;
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  uint32_t uvalue6;
  
                    /* Fills the annoyances tab's costs and unit counts. */
  value4 = *(int *)((intptr_t)DAT_0057c670 + 0x9c);
  self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)(value4 + 0x34),(int *)0x0);
  value1 = Game_GetPlayerCity(*(int *)((intptr_t)DAT_0057c670 +
                                     *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  value1 = (((*(int *)(value1 + 0x60) + *(int *)(value1 + 0x48)) * -3 + 100) * 1000) / 100;
  value2 = value1;
  if (*(int *)(*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8) + 0x148) != 0) {
    value2 = 0;
  }
  Gadget_SetTextf(arg1,0x1f45,&DAT_005683a4,value2);
  value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  Gadget_SetTextf(arg1,0x1f47,(uint8_t *)s__d____00568834,
                  *(uint32_t *)(value2 * 0x10 + 0xc3c + (intptr_t)self));
  value2 = value1;
  if (*(int *)(*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8) + 0x148) != 0) {
    value2 = 0;
  }
  Gadget_SetTextf(arg1,0x1f4d,&DAT_005683a4,value2);
  value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  Gadget_SetTextf(arg1,0x1f4f,(uint8_t *)s__d____00568834,
                  *(uint32_t *)(value2 * 0x10 + 0xc38 + (intptr_t)self));
  value2 = value1;
  if (*(int *)(*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8) + 0x148) != 0) {
    value2 = 0;
  }
  Gadget_SetTextf(arg1,0x1f5b,&DAT_005683a4,value2);
  value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  Gadget_SetTextf(arg1,0x1f5d,(uint8_t *)s__d____00568834,
                  *(uint32_t *)((value2 + 0xc4) * 0x10 + (intptr_t)self));
  if (*(int *)(*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8) + 0x148) != 0) {
    value1 = 0;
  }
  Gadget_SetTextf(arg1,0x1f5f,&DAT_005683a4,value1);
  value1 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value1 = Game_ComputeRatingShare(self,value1);
  Gadget_SetTextf(arg1,0x1f61,(uint8_t *)s__d____00568834,value1);
  value1 = Game_GetPlayerCity(*(int *)((intptr_t)DAT_0057c670 +
                                     *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  value5 = (10 - *(int *)(value1 + 0x58)) - *(int *)(value1 + 0x40);
  value2 = (value5 * 10000) / 100;
  value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value1 + 0x148) == 0) {
    if (*(int *)(value1 + 0x9c) != 0) {
      value2 = value2 / 2;
    }
  }
  else {
    value2 = 0;
  }
  Gadget_SetTextf(arg1,0x1f6a,&DAT_005683a4,value2);
  value1 = *(int *)(value4 + 0x16f0);
  value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value1 = Game_CountFilteredObjects(DAT_0057c670,1,0x16,value1,value2);
  Gadget_SetTextf(arg1,0x1f6c,&DAT_005686f4,value1);
  value1 = *(int *)(value4 + 0x16f0);
  value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value1 = Game_CountFilteredObjects2(DAT_0057c670,1,0x16,value1,value2);
  Gadget_SetTextf(arg1,0x1f72,&DAT_005686f4,value1);
  value2 = (value5 * 50000) / 100;
  value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value1 + 0x148) == 0) {
    if (*(int *)(value1 + 0x9c) != 0) {
      value2 = value2 / 2;
    }
  }
  else {
    value2 = 0;
  }
  Gadget_SetTextf(arg1,0x1f6e,&DAT_005683a4,value2);
  value1 = *(int *)(value4 + 0x16f0);
  value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value1 = Game_CountFilteredObjects(DAT_0057c670,2,0x16,value1,value2);
  Gadget_SetTextf(arg1,0x1f76,&DAT_005686f4,value1);
  value1 = *(int *)(value4 + 0x16f0);
  value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value1 = Game_CountFilteredObjects2(DAT_0057c670,2,0x16,value1,value2);
  Gadget_SetTextf(arg1,0x1f78,&DAT_005686f4,value1);
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value4 + 0x30));
  value1 = Game_GetPlayerCity(value1);
  value1 = (*(int *)(value1 + 0x68) + *(int *)(value1 + 0x50)) * 0x1e + 100;
  value5 = (value1 * 5000) / 100;
  value2 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value2 + 0x148) == 0) {
    if (*(int *)(value2 + 0x13c) == 0) {
      if (*(int *)(value2 + 0x9c) == 0) {
        if ((*(int *)(value2 + 0x22c) != 0) || (value3 = value5, *(int *)(value2 + 0x220) != 0)) {
          value3 = (value5 * 0xf) / 10;
        }
      }
      else {
        value3 = value5 / 2;
      }
    }
    else {
      value3 = 0;
    }
  }
  else {
    value3 = 0;
  }
  Gadget_SetTextf(arg1,0x1f7f,&DAT_005683a4,value3);
  value2 = *(int *)(value4 + 0x16f0);
  value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value2 = Game_CountFilteredObjects(DAT_0057c670,0xd,0x1f,value2,value3);
  Gadget_SetTextf(arg1,0x1f81,&DAT_005686f4,value2);
  value2 = *(int *)(value4 + 0x16f0);
  value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value2 = Game_CountFilteredObjects2(DAT_0057c670,0xd,0x1f,value2,value3);
  Gadget_SetTextf(arg1,0x1f85,&DAT_005686f4,value2);
  value2 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value2 + 0x148) == 0) {
    if (*(int *)(value2 + 300) == 0) {
      if (*(int *)(value2 + 0x9c) == 0) {
        if ((*(int *)(value2 + 0x22c) != 0) || (*(int *)(value2 + 0x210) != 0)) {
          value5 = (value5 * 0xf) / 10;
        }
      }
      else {
        value5 = value5 / 2;
      }
    }
    else {
      value5 = 0;
    }
  }
  else {
    value5 = 0;
  }
  Gadget_SetTextf(arg1,0x1f83,&DAT_005683a4,value5);
  value2 = *(int *)(value4 + 0x16f0);
  value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value2 = Game_CountFilteredObjects(DAT_0057c670,3,0x1f,value2,value5);
  Gadget_SetTextf(arg1,0x1f87,&DAT_005686f4,value2);
  value2 = *(int *)(value4 + 0x16f0);
  value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value2 = Game_CountFilteredObjects2(DAT_0057c670,3,0x1f,value2,value5);
  Gadget_SetTextf(arg1,0x1f89,&DAT_005686f4,value2);
  value2 = (value1 * 10000) / 100;
  value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value1 + 0x148) == 0) {
    if (*(int *)(value1 + 0x9c) == 0) {
      value5 = value2;
      if (*(int *)(value1 + 0x22c) != 0) {
        value5 = (value2 * 0xf) / 10;
      }
    }
    else {
      value5 = value2 / 2;
    }
  }
  else {
    value5 = 0;
  }
  Gadget_SetTextf(arg1,0x1f9d,&DAT_005683a4,value5);
  value1 = *(int *)(value4 + 0x16f0);
  value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value1 = Game_CountFilteredObjects(DAT_0057c670,9,0x1f,value1,value5);
  Gadget_SetTextf(arg1,0x1f9f,&DAT_005686f4,value1);
  value1 = *(int *)(value4 + 0x16f0);
  value5 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value1 = Game_CountFilteredObjects2(DAT_0057c670,9,0x1f,value1,value5);
  Gadget_SetTextf(arg1,0x1fa3,&DAT_005686f4,value1);
  value1 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value1 + 0x148) == 0) {
    if (*(int *)(value1 + 0x140) == 0) {
      if (*(int *)(value1 + 0x9c) == 0) {
        if ((*(int *)(value1 + 0x22c) != 0) || (*(int *)(value1 + 0x224) != 0)) {
          value2 = (value2 * 0xf) / 10;
        }
      }
      else {
        value2 = value2 / 2;
      }
    }
    else {
      value2 = 0;
    }
  }
  else {
    value2 = 0;
  }
  Gadget_SetTextf(arg1,0x1fa1,&DAT_005683a4,value2);
  value1 = *(int *)(value4 + 0x16f0);
  value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value1 = Game_CountFilteredObjects(DAT_0057c670,7,0x1f,value1,value2);
  Gadget_SetTextf(arg1,0x1fa5,&DAT_005686f4,value1);
  value4 = *(int *)(value4 + 0x16f0);
  value1 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value4 = Game_CountFilteredObjects2(DAT_0057c670,7,0x1f,value4,value1);
  Gadget_SetTextf(arg1,0x1fa7,&DAT_005686f4,value4);
  value4 = Game_CountFreeSlots(DAT_0057c670,0x16);
  if (value4 == 0) {
    uvalue6 = 0xff;
  }
  else {
    uvalue6 = 0;
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x1f7a,uvalue6);
  Gadget_SetTextf(arg1,0x1f7a,&DAT_005686f4,value4);
  value4 = Game_CountFreeBuildingsByType
                    (*(void **)(*(int *)((intptr_t)DAT_0057c670 +
                                        *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) + 0x1d8),
                     0x1f);
  if (value4 == 0) {
    uvalue6 = 0xff;
  }
  else {
    uvalue6 = 0;
  }
  Window_GadgetNotify_Text_SetTextColor(arg1,0x1f8b,uvalue6);
  Gadget_SetTextf(arg1,0x1f8b,&DAT_005686f4,value4);
  value4 = Game_GetPlayerFieldC20
                    (*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
  value1 = 0x1f9a;
  if (value4 < 4) {
    do {
      UI_RemoveObjectByKey(arg1,value1);
      value1 = value1 + 1;
    } while (value1 < 0x1fa8);
  }
  else {
    do {
      UI_ShowChildByID(arg1,value1);
      value1 = value1 + 1;
    } while (value1 < 0x1fa8);
  }
  value1 = 0x1f7b;
  if (value4 < 3) {
    do {
      UI_RemoveObjectByKey(arg1,value1);
      value1 = value1 + 1;
    } while (value1 < 0x1f8c);
    UI_RemoveObjectByKey(arg1,0x1fa8);
    return;
  }
  do {
    UI_ShowChildByID(arg1,value1);
    value1 = value1 + 1;
  } while (value1 < 0x1f8c);
  UI_ShowChildByID(arg1,0x1fa8);
  return;
}
