// CharacterSelect_UpdateScreen: ported from Pizza Connection 2 at 0x4c7110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c7110
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CharacterSelect_UpdateScreen(void *arg1)

{
  int *ptr1;
  char cVar2;
  uint32_t uvalue3;
  int value4;
  uint32_t uvalue5;
  char *cptr6;
  char *cptr7;
  uint32_t uvalue8;
  
                    /* Refreshes the character-select screen. */
  UI_ShowMessageTemplate(arg1);
  Window_GadgetNotify_Text_SetText(arg1,0x429,DAT_00582e4c);
  DAT_0057dda0 = DAT_0057b93c;
  DAT_0057ddfc = DAT_0057b940;
  DAT_0057ddb8 = DAT_0057b944;
  DAT_0057dda4 = DAT_0057b948;
  DAT_0057ddb0 = DAT_0057b8b0;
  DAT_0057ddac = DAT_0057b938;
  DAT_0057dd44 = _DAT_0057b8ac;
  if ((char)DAT_0057b8f8 == '\0') {
    IDMap_GetRandomName(DAT_0057ba10,DAT_0057b938,(char *)&DAT_0057dd60);
  }
  else {
    uvalue3 = 0xffffffff;
    cptr6 = (char *)&DAT_0057b8f8;
    do {
      cptr7 = cptr6;
      if (uvalue3 == 0) break;
      uvalue3 = uvalue3 - 1;
      cptr7 = cptr6 + 1;
      cVar2 = *cptr6;
      cptr6 = cptr7;
    } while (cVar2 != '\0');
    uvalue3 = ~uvalue3;
    cptr6 = cptr7 + -uvalue3;
    cptr7 = (char *)&DAT_0057dd60;
    for (uvalue5 = uvalue3 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *(uint32_t *)cptr7 = *(uint32_t *)cptr6;
      cptr6 = cptr6 + 4;
      cptr7 = cptr7 + 4;
    }
    for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
      *cptr7 = *cptr6;
      cptr6 = cptr6 + 1;
      cptr7 = cptr7 + 1;
    }
  }
  Window_GadgetNotify_Input_SetText(arg1,0x40c,&DAT_0057dd60);
  if ((char)DAT_0057b8b8 == '\0') {
    uvalue8 = 0;
    uvalue3 = Random_RangeFast(0,0x29);
    String_Format((uint8_t *)&DAT_0057ddbc,*(uint8_t **)(&DAT_00583bb0 + uvalue3 * 4),uvalue8);
  }
  else {
    uvalue3 = 0xffffffff;
    cptr6 = (char *)&DAT_0057b8b8;
    do {
      cptr7 = cptr6;
      if (uvalue3 == 0) break;
      uvalue3 = uvalue3 - 1;
      cptr7 = cptr6 + 1;
      cVar2 = *cptr6;
      cptr6 = cptr7;
    } while (cVar2 != '\0');
    uvalue3 = ~uvalue3;
    cptr6 = cptr7 + -uvalue3;
    cptr7 = (char *)&DAT_0057ddbc;
    for (uvalue5 = uvalue3 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *(uint32_t *)cptr7 = *(uint32_t *)cptr6;
      cptr6 = cptr6 + 4;
      cptr7 = cptr7 + 4;
    }
    for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
      *cptr7 = *cptr6;
      cptr6 = cptr6 + 1;
      cptr7 = cptr7 + 1;
    }
  }
  Window_GadgetNotify_Input_SetText(arg1,0x40a,&DAT_0057ddbc);
  UI_Group_Create(arg1,0,2,0x43a);
  Window_GadgetNotify_Button_SetState(arg1,0x43b - DAT_0057ddac,1);
  Window_GadgetNotify_Text_SetText(arg1,0x423,DAT_00582280);
  DAT_0057ddb4 = 0;
  value4 = 0;
  do {
    ptr1 = (int *)((intptr_t)&DAT_0057b94c + value4);
    *(int *)((intptr_t)&DAT_0057dd48 + value4) = *ptr1;
    value4 = value4 + 4;
    DAT_0057ddb4 = DAT_0057ddb4 - *ptr1;
  } while (value4 < 0x18);
  DAT_0057dda8 = DAT_0057b8b4;
  Window_GadgetNotify_Slider_SetRange(arg1,0x407,0,10,0);
  Window_GadgetNotify_Slider_SetValue(arg1,0x407,DAT_0057dda8,0);
  Window_GadgetNotify_Slider_SetChangeNotify(arg1,0x407,1);
  CharacterSelect_DrawPortrait(arg1);
  CharacterSelect_FillAttributes(arg1);
  CharacterSelect_SetPhotoSprite(arg1);
  UI_RemoveObjectByKey(arg1,0x406);
  UI_RemoveObjectByKey(arg1,0x407);
  UI_RemoveObjectByKey(arg1,0x408);
  return;
}
