// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x4cbcd0.c:132:114: error: expected expression
// FreePlaySetup_InitWindow: ported from Pizza Connection 2 at 0x4cbcd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cbcd0
#include "pc2_port.h"

void __cdecl FreePlaySetup_InitWindow(void *arg1)

{
  void *self;
  int value1;
  uint32_t uvalue2;
  int *ptr3;
  uint8_t *uptr4;
  void *this_00;
  uint32_t *uptr5;
  uint32_t *uptr6;
  int value7;
  uint32_t *uptr8;
  uint32_t auStack_f8 [42];
  uint32_t uStack_50;
  uint32_t uvalue9;
  int local_24;
  uint8_t local_20 [32];
  
                    /* Initializes the free-play setup screen. */
  self = arg1;
  UI_ShowDialogTemplate(arg1);
  Window_GadgetNotify_Text_SetText(arg1,0x429,DAT_00582e4c);
  DAT_0057de60 = arg1;
  UI_RemoveObjectByKey(arg1,0x44d);
  UI_RemoveObjectByKey(arg1,0x451);
  UI_RemoveObjectByKey(arg1,0x450);
  UI_RemoveObjectByKey(arg1,0x452);
  value7 = 0x44f;
  do {
    UI_DisableButton(arg1,value7 + -1);
    UI_DisableButton(arg1,value7);
    value7 = value7 + 8;
  } while (value7 < 0x47f);
  Window_GadgetNotify_Text_SetText(arg1,0x43f,&DAT_0057bc58);
  Window_GadgetNotify_Text_SetText(arg1,0x440,&DAT_0057bc98);
  uptr6 = (uint32_t *)&DAT_0057bc58;
  uptr5 = auStack_f8;
  for (value7 = 0x30; value7 != 0; value7 = value7 + -1) {
    *uptr5 = *uptr6;
    uptr6 = uptr6 + 1;
    uptr5 = uptr5 + 1;
  }
  UI_SetImageFromTemplate(arg1);
  UI_SetPlayerLogoSprite(arg1,DAT_0057bd0c,DAT_0057bd10,0x4e6);
  MapList_LoadAllMapDefinitions(&DAT_0057de38);
  DAT_0057bb3c = (DAT_0057bb3c & ~(0xffffu << 8)) | (((DAT_0057b964 == 1) & 0xffffu) << 8);
  DAT_0057bb3c = (DAT_0057bb3c & ~(0xffu << 8)) | (((DAT_0057b968 == 1) & 0xffu) << 8);
  DAT_0057bb34 = (DAT_0057bb34 & ~(0x0u << 8)) | (((DAT_0057b96c == 1) & 0x0u) << 8);
  DAT_0057bb3c = (DAT_0057bb3c & ~(0x0u << 8)) | (((DAT_0057b970 == 1) & 0x0u) << 8);
  DAT_0057bb30 = DAT_0057b974;
  DAT_0057bb38 = DAT_0057b978;
  DAT_0057bb2c = DAT_0057b9cc;
  DAT_0057bb24 = DAT_0057b8b4;
  DAT_0057bb4c = DAT_0057b9d4;
  DAT_0057bb50 = DAT_0057b9d8;
  DAT_0057bb28 = DAT_0057b9c8;
  value7 = 0;
  DAT_0057bb48 = DAT_0057b9d0;
  DAT_0057bb40 = 0;
  if (0 < DAT_0057de4c) {
    do {
      value1 = IDMap_Lookup(&DAT_0057de38,value7,(int *)0x0);
      uvalue2 = FUN_005570c0(this_00,(uint8_t *)(value1 + 0x40),(uint8_t *)&DAT_0057b9c4);
      if (uvalue2 == 0) {
        DAT_0057bb40 = value7;
        break;
      }
      value7 = value7 + 1;
    } while (value7 < DAT_0057de4c);
  }
  FreePlaySetup_FillHighScoreTable(arg1);
  uptr5 = &DAT_0057bcdc;
  uptr6 = &DAT_0057b994;
  do {
    uptr8 = uptr6 + 1;
    uptr5[-1] = uptr6[-6];
    *uptr5 = *uptr6;
    uptr5[0xe] = uptr6[6];
    uptr5 = uptr5 + 0x30;
    uptr6 = uptr8;
  } while ((intptr_t)uptr8 < 0x57b9ac);
  DAT_0057bcdc = 0;
  ptr3 = &DAT_0057b94c;
  do {
    value7 = *ptr3;
    ptr3 = ptr3 + 1;
    DAT_0057bcdc = DAT_0057bcdc - value7;
  } while ((intptr_t)ptr3 < 0x57b964);
  ptr3 = &DAT_0057bdcc;
  do {
    if (ptr3[1] == DAT_0057bd10) {
      ptr3[1] = DAT_0057c270;
    }
    if (*ptr3 == DAT_0057bd0c) {
      *ptr3 = DAT_0057b780;
    }
    ptr3 = ptr3 + 0x30;
  } while ((intptr_t)ptr3 < 0x57c18c);
  uptr6 = &DAT_0057bd18;
  arg1 = (void *)0x442;
  local_24 = 0;
  do {
    Window_GadgetNotify_Text_SetText(self,(intptr_t)arg1 + -1,uptr6);
    Window_GadgetNotify_Text_SetText(self,(intptr_t)arg1,uptr6 + 0x10);
    uptr5 = uptr6;
    uptr8 = auStack_f8;
    for (value7 = 0x30; value7 != 0; value7 = value7 + -1) {
      *uptr8 = *uptr5;
      uptr5 = uptr5 + 1;
      uptr8 = uptr8 + 1;
    }
    UI_SetImageFromTemplate(self);
    UI_SetPlayerLogoSprite(self,uptr6[0x2d],uptr6[0x2e],*(int *)(&DAT_0056b2c8 + local_24));
    arg1 = (void *)((intptr_t)arg1 + 2);
    local_24 = local_24 + 4;
    uptr6 = uptr6 + 0x30;
  } while ((intptr_t)arg1 < 0x44c);
  value7 = 0x49e;
  ptr3 = &DAT_0057bdd4;
  do {
    Window_GadgetNotify_Button_SetState(self,value7,*ptr3);
    ptr3 = ptr3 + 0x30;
    value7 = value7 + 1;
  } while ((intptr_t)ptr3 < 0x57c194);
  FreePlaySetup_RefreshPlayerProfiles(self);
  Window_GadgetNotify_Button_SetState(self,0x4a3,(uint32_t)(DAT_0057bb3c = (DAT_0057bb3c & ~(0xffffu << 8)) | (((= '\x01'))) & 0xffffu) << 8);
  Window_GadgetNotify_Button_SetState(self,0x4a4,(uint32_t)(DAT_0057bb3c = (DAT_0057bb3c & ~(0xffu << 8)) | (((= '\x01'))) & 0xffu) << 8);
  Window_GadgetNotify_Button_SetState(self,0x4a5,(uint32_t)((char)DAT_0057bb34 == '\x01'));
  Window_GadgetNotify_Button_SetState(self,0x4a6,(uint32_t)((char)DAT_0057bb3c == '\x01'));
  String_Format(local_20,&DAT_005686f4,DAT_0057bb30);
  Window_GadgetNotify_Text_SetText(self,0x43e,local_20);
  String_Format(local_20,&DAT_005686f4,DAT_0057bb38);
  Window_GadgetNotify_Text_SetText(self,0x43d,local_20);
  Window_GadgetNotify_Slider_SetRange(self,0x437,100,500,0);
  Window_GadgetNotify_Slider_SetValue(self,0x437,DAT_0057bb28,0);
  Window_GadgetNotify_Slider_SetChangeNotify(self,0x437,1);
  Window_GadgetNotify_Slider_SetRange(self,0x434,10,0x6e,0);
  Window_GadgetNotify_Slider_SetValue(self,0x434,DAT_0057bb2c * 10,0);
  Window_GadgetNotify_Slider_SetChangeNotify(self,0x434,1);
  Window_GadgetNotify_Slider_SetRange(self,0x407,0,10,0);
  Window_GadgetNotify_Slider_SetValue(self,0x407,DAT_0057bb24,0);
  Window_GadgetNotify_Slider_SetChangeNotify(self,0x407,1);
  uptr4 = NameMap_GetString(&DAT_0057de38,DAT_0057bb40);
  Gadget_SetText(self,0x480,uptr4);
  if (DAT_0057bb48 < 0) {
    uvalue9 = DAT_00582a98;
  }
  else {
    uvalue9 = (&DAT_0058369c)[DAT_0057bb48];
  }
  Gadget_SetText(self,0x483,uvalue9);
  if (DAT_0057bb4c < 0) {
    uvalue9 = DAT_00582a98;
  }
  else {
    uvalue9 = (&DAT_0058369c)[DAT_0057bb4c];
  }
  Gadget_SetText(self,0x486,uvalue9);
  if (DAT_0057bb50 < 0) {
    uvalue9 = DAT_00582a98;
  }
  else {
    uvalue9 = (&DAT_0058369c)[DAT_0057bb50];
  }
  Gadget_SetText(self,0x489,uvalue9);
  FreePlaySetup_FillCityTable(self);
  FreePlaySetup_FillStartCapitalText(self);
  FreePlaySetup_FillGameLengthText(self);
  FreePlaySetup_SetDifficultyText(self,DAT_0057bb24);
  uStack_50 = 0x4cc217;
  FreePlaySetup_ShowMapPreview(self);
  return;
}
