// BuildingInfo_Fill: ported from Pizza Connection 2 at 0x4bb760.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4bb760
#include "pc2_port.h"

void __cdecl BuildingInfo_Fill(void *arg1)

{
  char cVar1;
  void *self;
  int value2;
  uint8_t *uptr3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  void *this_00;
  int value6;
  char *cptr7;
  uint32_t unaff_EDI;
  char *cptr8;
  int value9;
  uint8_t *bptr10;
  uint32_t uvalue11;
  int *local_88;
  int *local_84;
  char local_80 [128];
  
                    /* Fills the selected construction/building info page. */
  value6 = *(int *)((intptr_t)DAT_0057c670 + 0x21c);
  this_00 = (void *)0x0;
  local_84 = (int *)0x0;
  if (*(int *)(value6 + 0x30) == 0x16) {
    local_88 = operator_new(8);
    local_88[1] = 0x16;
    value9 = 0x16;
    local_84 = local_88;
  }
  else {
    this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value6 + 0x110));
    local_88 = Game_FindSubrecordByObject(this_00,value6);
    value9 = *(int *)(value6 + 0x30);
  }
  Sound_ProcessEvent(DAT_0057ba0c,value9,0,'\x01');
  UI_SetChildVisibleByID(arg1,0x1f6f,(uint32_t)(local_88[1] == 0x16));
  UI_SetChildVisibleByID(arg1,0x1f66,(uint32_t)(local_88[1] == 0x1e));
  UI_SetChildVisibleByID(arg1,0x1f67,(uint32_t)(local_88[1] == 0x1f));
  UI_SetChildVisibleByID(arg1,0x1f65,(uint32_t)(local_88[1] == 0x1d));
  Window_GadgetNotify_Slider_SetValue(arg1,0x1f41,*(uint32_t *)(value6 + 0xa8),0);
  if (*(int *)(value6 + 0xa4) != -1) {
    if (*(int *)(value6 + 0x74) == 0) {
      value9 = 0x1f68;
      do {
        UI_RemoveObjectByKey(arg1,value9);
        value9 = value9 + 1;
      } while (value9 < 0x1f6e);
    }
    else {
      Gadget_SetTextf(arg1,0x1f6a,&DAT_005683a4,1000);
      self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                  *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
      value9 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      value9 = Game_ComputeRatingShare(self,value9);
      Gadget_SetTextf(arg1,0x1f6b,(uint8_t *)s__d____00568834,value9);
    }
    value9 = *(int *)(value6 + 0xfc);
    switch(local_88[1]) {
    case 0x16:
      value9 = Game_GetPlayerSubmapValue(DAT_0057c670,*(int *)(value9 + 8),*(int *)(value9 + 0x2c));
      if (*(int *)(value6 + 0xa4) == 2) {
        bptr10 = DAT_00582b3c;
      }
      else {
        bptr10 = DAT_00582b34;
      }
      String_Format(local_80,bptr10,value9 + 4);
      Window_GadgetNotify_Text_SetText(arg1,0x1f44,local_80);
      uvalue11 = DAT_00581ad4;
      break;
    default:
      goto switchD_004bb89c_caseD_17;
    case 0x1d:
      if (*(int *)(value9 + 4) == 0xf) {
        value9 = Game_GetPlayerSubmapValue(DAT_0057c670,*(int *)(value9 + 8),*(int *)(value9 + 0x2c));
        if (*(int *)(value6 + 0xa4) != 0x10) {
          bptr10 = DAT_00580b50;
          goto LAB_004bba80;
        }
        String_Format(local_80,DAT_00582f30,value9 + 4);
      }
      else {
        bptr10 = DAT_005810b0;
LAB_004bba80:
        String_Format(local_80,bptr10,unaff_EDI);
      }
      Window_GadgetNotify_Text_SetText(arg1,0x1f44,local_80);
      uvalue11 = DAT_00582eec;
      break;
    case 0x1e:
      value9 = Game_GetPlayerSubmapValue(DAT_0057c670,*(int *)(value9 + 8),*(int *)(value9 + 0x2c));
      if (*(int *)(value6 + 0xa4) == 0xf) {
        String_Format(local_80,DAT_00581ffc,value9 + 4);
      }
      else {
        String_Format(local_80,DAT_00580f50,unaff_EDI);
      }
      Window_GadgetNotify_Text_SetText(arg1,0x1f44,local_80);
      goto switchD_004bb89c_caseD_1e;
    case 0x1f:
      value2 = Game_GetPlayerSubmapValue(DAT_0057c670,*(int *)(value9 + 8),*(int *)(value9 + 0x2c));
      value6 = *(int *)(value6 + 0xa4);
      if (value6 == 5) {
        String_Format(local_80,DAT_00581bb8,unaff_EDI);
      }
      else {
        if (value6 == 0x11) {
          if (value2 == 0) {
LAB_004bbaf5:
            uvalue4 = 0xffffffff;
            cptr7 = &DAT_00579aec;
            do {
              cptr8 = cptr7;
              if (uvalue4 == 0) break;
              uvalue4 = uvalue4 - 1;
              cptr8 = cptr7 + 1;
              cVar1 = *cptr7;
              cptr7 = cptr8;
            } while (cVar1 != '\0');
            uvalue4 = ~uvalue4;
            cptr7 = cptr8 + -uvalue4;
            cptr8 = local_80;
            for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
              *(uint32_t *)cptr8 = *(uint32_t *)cptr7;
              cptr7 = cptr7 + 4;
              cptr8 = cptr8 + 4;
            }
            for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
              *cptr8 = *cptr7;
              cptr7 = cptr7 + 1;
              cptr8 = cptr8 + 1;
            }
            goto LAB_004bbb61;
          }
          value2 = value2 + 4;
          bptr10 = DAT_00581bc4;
        }
        else if (value6 == 0x1d) {
          value6 = Game_GetPlayerMapValue(DAT_0057c670,*(int *)(value9 + 8),*(int *)(value9 + 0x2c));
          if (value6 == 0) goto LAB_004bbaf5;
          value2 = Get_Subobject4(value6);
          bptr10 = DAT_00581b98;
        }
        else {
          value2 = value2 + 4;
          bptr10 = DAT_00581b90;
        }
        String_Format(local_80,bptr10,value2);
      }
LAB_004bbb61:
      Window_GadgetNotify_Text_SetText(arg1,0x1f44,local_80);
      uvalue11 = DAT_00582418;
    }
    goto LAB_004bbb79;
  }
  Window_GadgetNotify_Text_SetText(arg1,0x1f44,DAT_00580b7c);
  value6 = 0x1f68;
  do {
    UI_RemoveObjectByKey(arg1,value6);
    value6 = value6 + 1;
  } while (value6 < 0x1f6e);
  switch(local_88[1]) {
  case 0x16:
    uvalue11 = DAT_00581ad4;
    break;
  default:
    goto switchD_004bb89c_caseD_17;
  case 0x1d:
    uvalue11 = DAT_00582eec;
    break;
  case 0x1e:
switchD_004bb89c_caseD_1e:
    uvalue11 = DAT_00582dd0;
    break;
  case 0x1f:
    uvalue11 = DAT_00582418;
  }
LAB_004bbb79:
  Window_GadgetNotify_Text_SetText(arg1,0x48f,uvalue11);
switchD_004bb89c_caseD_17:
  if (this_00 == (void *)0x0) {
    Window_GadgetNotify_Text_SetText(arg1,0x1f5b,DAT_00582e4c);
    UI_RemoveObjectByKey(arg1,0x1f6e);
    UI_RemoveObjectByKey(arg1,0x1f5c);
    UI_RemoveObjectByKey(arg1,0x1f5a);
  }
  else {
    Window_GadgetNotify_Text_SetText(arg1,0x1f5b,(intptr_t)this_00 + 8);
    Personnel_SetEmployeePhotoByKey(arg1,0x1f6e,(intptr_t)this_00);
  }
  switch(local_88[1]) {
  case 0x16:
  case 0x1f:
    Gadget_SetTextf(arg1,0x1f61,&DAT_005686f4,1);
    Gadget_SetTextf(arg1,0x1f47,&DAT_005686f4,0);
    Gadget_SetTextf(arg1,0x1f46,&DAT_005686f4,0);
    Gadget_SetTextf(arg1,0x1f48,&DAT_005686f4,0);
  default:
    goto switchD_004bbbfb_caseD_17;
  case 0x1d:
    Gadget_SetTextf(arg1,0x1f61,(uint8_t *)s__s__d_00568964,DAT_00581044);
    uptr3 = Economy_GetModifier(this_00,0x1d,0);
    Gadget_SetTextf(arg1,0x1f47,&DAT_005686f4,uptr3);
    uptr3 = Economy_GetModifier(this_00,0x1d,1);
    Gadget_SetTextf(arg1,0x1f46,&DAT_005686f4,uptr3);
    value6 = 0x1d;
    break;
  case 0x1e:
    Gadget_SetTextf(arg1,0x1f61,(uint8_t *)s__s__d_00568964,DAT_00581044);
    uptr3 = Economy_GetModifier(this_00,0x1e,0);
    Gadget_SetTextf(arg1,0x1f47,&DAT_005686f4,uptr3);
    uptr3 = Economy_GetModifier(this_00,0x1e,1);
    Gadget_SetTextf(arg1,0x1f46,&DAT_005686f4,uptr3);
    value6 = 0x1e;
  }
  uptr3 = Economy_GetModifier(this_00,value6,2);
  Gadget_SetTextf(arg1,0x1f48,&DAT_005686f4,uptr3);
switchD_004bbbfb_caseD_17:
  if (local_84 != (int *)0x0) {
    Mem_Free(local_84);
  }
  return;
}
