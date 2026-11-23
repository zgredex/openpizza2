// CriminalsPage_FillUnitDetails: ported from Pizza Connection 2 at 0x4be9e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4be9e0
#include "pc2_port.h"

void __cdecl CriminalsPage_FillUnitDetails(void *arg1)

{
  char cVar1;
  void *self;
  int *ptr2;
  int value3;
  int value4;
  int value5;
  uint8_t *uptr6;
  uint32_t uvalue7;
  uint32_t uvalue8;
  uint8_t *bptr9;
  uint32_t uvalue10;
  char *cptr11;
  uint32_t unaff_EDI;
  char *cptr12;
  char local_80 [128];
  
                    /* Fills the criminal unit detail page. */
  value4 = *(int *)((intptr_t)DAT_0057c670 + 0x21c);
  self = *(void **)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  ptr2 = Game_FindSubrecordByObject(self,value4);
  UI_SetChildVisibleByID(arg1,0x1f5e,(uint32_t)(ptr2[1] == 0x16));
  UI_SetChildVisibleByID(arg1,0x470,(uint32_t)(ptr2[1] == 0x1e));
  UI_SetChildVisibleByID(arg1,0x1f5a,(uint32_t)(ptr2[1] == 0x1f));
  UI_SetChildVisibleByID(arg1,0x46d,(uint32_t)(ptr2[1] == 0x1d));
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f41,*(uint32_t *)(value4 + 0xa8),0);
  if (*(int *)(value4 + 0xa4) == -1) {
    Gadget_SetTextf(arg1,0x1f44,&DAT_005630d0,DAT_00580b7c);
    UI_RemoveObjectByKey(arg1,0x483);
    UI_RemoveObjectByKey(arg1,0x484);
    UI_RemoveObjectByKey(arg1,0x477);
    Gadget_SetTextf(arg1,0x1f57,&DAT_005686f4,0);
    Gadget_SetTextf(arg1,0x1f50,&DAT_005686f4,0);
    Gadget_SetTextf(arg1,0x1f58,&DAT_005686f4,0);
    Gadget_SetTextf(arg1,0x1f52,&DAT_005686f4,0);
    Gadget_SetTextf(arg1,0x1f59,&DAT_005686f4,0);
    Gadget_SetTextf(arg1,0x1f54,&DAT_005686f4,0);
    goto LAB_004bee3d;
  }
  UI_ShowChildByID(arg1,0x483);
  UI_ShowChildByID(arg1,0x484);
  UI_ShowChildByID(arg1,0x477);
  value5 = *(int *)(value4 + 0xfc);
  value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value3 = Game_CountFilteredObjects(DAT_0057c670,-1,0x1f,value5,value3);
  Gadget_SetTextf(arg1,0x1f57,&DAT_005686f4,value3);
  value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value3 = Game_CountFilteredObjects2(DAT_0057c670,-1,0x1f,value5,value3);
  Gadget_SetTextf(arg1,0x1f50,&DAT_005686f4,value3);
  value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value3 = Game_CountFilteredObjects(DAT_0057c670,-1,0x1e,value5,value3);
  Gadget_SetTextf(arg1,0x1f58,&DAT_005686f4,value3);
  value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value3 = Game_CountFilteredObjects2(DAT_0057c670,-1,0x1e,value5,value3);
  Gadget_SetTextf(arg1,0x1f52,&DAT_005686f4,value3);
  value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value3 = Game_CountFilteredObjects(DAT_0057c670,-1,0x1d,value5,value3);
  Gadget_SetTextf(arg1,0x1f59,&DAT_005686f4,value3);
  value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
  value3 = Game_CountFilteredObjects2(DAT_0057c670,-1,0x1d,value5,value3);
  Gadget_SetTextf(arg1,0x1f54,&DAT_005686f4,value3);
  value3 = ptr2[1];
  if (value3 == 0x1d) {
    if (*(int *)(value5 + 4) == 0xf) {
      value5 = Game_GetPlayerSubmapValue(DAT_0057c670,*(int *)(value5 + 8),*(int *)(value5 + 0x2c));
      if (*(int *)(value4 + 0xa4) == 0x10) {
        String_Format(local_80,DAT_00582f30,value5 + 4);
        goto LAB_004bee2d;
      }
      bptr9 = DAT_00580b50;
    }
    else {
      bptr9 = DAT_005810b0;
    }
LAB_004bee20:
    String_Format(local_80,bptr9,unaff_EDI);
  }
  else if (value3 == 0x1e) {
    value5 = Game_GetPlayerSubmapValue(DAT_0057c670,*(int *)(value5 + 8),*(int *)(value5 + 0x2c));
    if (*(int *)(value4 + 0xa4) == 0xf) {
      String_Format(local_80,DAT_00581ffc,value5 + 4);
    }
    else {
      String_Format(local_80,DAT_00580f50,unaff_EDI);
    }
  }
  else {
    if (value3 != 0x1f) goto LAB_004bee3d;
    value3 = Game_GetPlayerSubmapValue(DAT_0057c670,*(int *)(value5 + 8),*(int *)(value5 + 0x2c));
    value4 = *(int *)(value4 + 0xa4);
    if (value4 == 5) {
      bptr9 = DAT_00581bb8;
      goto LAB_004bee20;
    }
    if (value4 == 0x11) {
      bptr9 = DAT_00581bc4;
    }
    else {
      if (value4 == 0x1d) {
        value4 = Game_GetPlayerMapValue(DAT_0057c670,*(int *)(value5 + 8),*(int *)(value5 + 0x2c));
        if (value4 == 0) {
          uvalue7 = 0xffffffff;
          cptr11 = &DAT_00579aec;
          do {
            cptr12 = cptr11;
            if (uvalue7 == 0) break;
            uvalue7 = uvalue7 - 1;
            cptr12 = cptr11 + 1;
            cVar1 = *cptr11;
            cptr11 = cptr12;
          } while (cVar1 != '\0');
          uvalue7 = ~uvalue7;
          cptr11 = cptr12 + -uvalue7;
          cptr12 = local_80;
          for (uvalue8 = uvalue7 >> 2; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
            *(uint32_t *)cptr12 = *(uint32_t *)cptr11;
            cptr11 = cptr11 + 4;
            cptr12 = cptr12 + 4;
          }
          for (uvalue7 = uvalue7 & 3; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
            *cptr12 = *cptr11;
            cptr11 = cptr11 + 1;
            cptr12 = cptr12 + 1;
          }
        }
        else {
          value4 = Get_Subobject4(value4);
          String_Format(local_80,DAT_00581b98,value4);
        }
        goto LAB_004bee2d;
      }
      bptr9 = DAT_00581b90;
    }
    String_Format(local_80,bptr9,value3 + 4);
  }
LAB_004bee2d:
  Window_GadgetNotify_Text_SetText(arg1,0x1f44,local_80);
LAB_004bee3d:
  value4 = ptr2[1];
  if (value4 == 0x1d) {
    Gadget_SetTextf(arg1,0x1f4d,(uint8_t *)s__s__d_00568964,DAT_00581044);
    uptr6 = Economy_GetModifier(self,0x1d,0);
    Gadget_SetTextf(arg1,0x1f47,&DAT_005686f4,uptr6);
    uptr6 = Economy_GetModifier(self,0x1d,1);
    Gadget_SetTextf(arg1,0x1f46,&DAT_005686f4,uptr6);
    uptr6 = Economy_GetModifier(self,0x1d,2);
    Gadget_SetTextf(arg1,0x1f48,&DAT_005686f4,uptr6);
    uvalue10 = DAT_00582eec;
  }
  else if (value4 == 0x1e) {
    Gadget_SetTextf(arg1,0x1f4d,(uint8_t *)s__s__d_00568964,DAT_00581044);
    uptr6 = Economy_GetModifier(self,0x1e,0);
    Gadget_SetTextf(arg1,0x1f47,&DAT_005686f4,uptr6);
    uptr6 = Economy_GetModifier(self,0x1e,1);
    Gadget_SetTextf(arg1,0x1f46,&DAT_005686f4,uptr6);
    uptr6 = Economy_GetModifier(self,0x1e,2);
    Gadget_SetTextf(arg1,0x1f48,&DAT_005686f4,uptr6);
    uvalue10 = DAT_00582dd0;
  }
  else {
    if (value4 != 0x1f) {
      return;
    }
    Gadget_SetTextf(arg1,0x1f4d,&DAT_005686f4,1);
    Gadget_SetTextf(arg1,0x1f47,&DAT_005686f4,0);
    Gadget_SetTextf(arg1,0x1f46,&DAT_005686f4,0);
    Gadget_SetTextf(arg1,0x1f48,&DAT_005686f4,0);
    uvalue10 = DAT_00582418;
  }
  Window_GadgetNotify_Text_SetText(arg1,0x48f,uvalue10);
  return;
}
