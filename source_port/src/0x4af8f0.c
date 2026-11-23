// GlossaryWeapons_FillWeaponPage: ported from Pizza Connection 2 at 0x4af8f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4af8f0
#include "pc2_port.h"

void __cdecl GlossaryWeapons_FillWeaponPage(void *arg1)

{
  int value1;
  uint8_t *uptr2;
  int *ptr3;
  int value4;
  int value5;
  char *cptr6;
  uint32_t uvalue7;
  int local_274;
  int *local_270;
  int local_26c;
  int local_268;
  int local_264;
  int local_260 [8];
  char local_240 [256];
  int local_140 [16];
  int local_100 [64];
  
  value4 = 0x3e9;
  ptr3 = local_260;
                    /* Fills the glossary weapons page and preview. */
  for (value1 = 8; value1 != 0; value1 = value1 + -1) {
    *ptr3 = -1;
    ptr3 = ptr3 + 1;
  }
  do {
    Window_GadgetNotify_Button_SetState
              (arg1,value4,(uint32_t)(value4 + -0x3e9 == DAT_0057d664 - DAT_0057d668));
    value4 = value4 + 1;
  } while (value4 < 0x3f6);
  Window_GadgetNotify_Text_SetText(arg1,0x3fd,*(uint32_t *)(&DAT_00583434 + DAT_0057d664 * 4));
  Window_GadgetNotify_Text_SetText(arg1,0x3fe,*(uint32_t *)(&DAT_00583888 + DAT_0057d664 * 4));
  DAT_0057d660 = Random_RangeFast(0,*(uint32_t *)(&DAT_0056a560 + DAT_0057d664 * 4));
  value1 = *(int *)(&DAT_0056a560 + DAT_0057d664 * 4);
  if (value1 == 0) {
    cptr6 = s__s_bik_00569bfc;
LAB_004afa35:
    uptr2 = &DAT_0056a1a0 + DAT_0057d664 * 0x20;
  }
  else if (value1 == 1) {
    if (DAT_0057d660 == 0) {
      uptr2 = &DAT_0056a1a0 + DAT_0057d664 * 0x20;
      cptr6 = s__sm_bik_0056a5f8;
    }
    else {
      uptr2 = &DAT_0056a1a0 + DAT_0057d664 * 0x20;
      cptr6 = s__sw_bik_0056a5f0;
    }
  }
  else {
    if (value1 != 2) goto LAB_004afa42;
    if (DAT_0057d660 == 0) {
      uptr2 = &DAT_0056a1a0 + DAT_0057d664 * 0x20;
      cptr6 = s__smg_bik_0056a620;
    }
    else {
      if (DAT_0057d660 != 1) {
        cptr6 = s__ssniper_bik_0056a600;
        goto LAB_004afa35;
      }
      uptr2 = &DAT_0056a1a0 + DAT_0057d664 * 0x20;
      cptr6 = s__spistole_bik_0056a610;
    }
  }
  String_Format(local_240,(uint8_t *)cptr6,uptr2);
LAB_004afa42:
  Array_GetPairByKey(arg1,0x881,&local_268,&local_26c);
  UI_RemoveObject(arg1,0x881);
  Movie_CreatePlayer(arg1,0x881,local_268,local_26c,local_240,(uint32_t *)0x0);
  UI_StartButtonMovie(arg1,0x881,1);
  Sound_PlayWeaponPageEvent(DAT_0057ba0c,DAT_0057d664,DAT_0057d660);
  value1 = 0x9b4;
  do {
    UI_SetChildVisibleByID(arg1,value1,(uint32_t)(DAT_0057d664 < 8));
    value1 = value1 + 1;
  } while (value1 < 0x9c6);
  value1 = 50000;
  do {
    UI_RemoveObject(arg1,value1);
    value1 = value1 + 1;
  } while (value1 < 0xc3aa);
  if (7 < DAT_0057d664) {
    value1 = 0x86f;
    do {
      Window_GadgetNotify_Text_SetText(arg1,value1,DAT_00582e4c);
      value1 = value1 + 1;
    } while (value1 < 0x877);
    DAT_0057d660 = 0;
    return;
  }
  local_264 = 0;
  Array_GetPairByKey(arg1,0x42e,&local_268,&local_26c);
  Stats_BuildCategoryMatrix(local_100,local_260);
  local_270 = local_260;
  local_274 = 0;
  ptr3 = local_100;
  do {
    if (*local_270 == -1) {
      uvalue7 = DAT_00582e4c;
    }
    else {
      uvalue7 = *(uint32_t *)(&DAT_005840d4 + *local_270 * 4);
    }
    Window_GadgetNotify_Text_SetText(arg1,local_274 + 0x86f,uvalue7);
    value4 = 0;
    value1 = local_264 + 50000;
    local_264 = local_264 + 8;
    do {
      String_Format(local_240,(uint8_t *)s_BEWERTUNG___02d_spr_00569f68,(*ptr3 * 0x10 + 0x32) / 100);
      UI_AddSprite(arg1,value1,DAT_0057d658 * value4 + local_268,
                   DAT_0057d65c * local_274 + local_26c,local_240);
      value1 = value1 + 1;
      value4 = value4 + 1;
      ptr3 = ptr3 + 1;
    } while (value4 < 8);
    local_274 = local_274 + 1;
    local_270 = local_270 + 1;
  } while (local_274 < 8);
  Array_GetPairByKey(arg1,0x1f5d,&local_268,&local_26c);
  Character_ComputeRatingArray(local_140);
  local_274 = 0;
  ptr3 = local_140;
  value1 = local_264 + 50000;
  while( true ) {
    value5 = 0;
    value4 = value1 + 2;
    do {
      String_Format(local_240,(uint8_t *)s_BEWERTUNG2___02d_spr_0056a5d8,(*ptr3 * 0x10 + 0x32) / 100)
      ;
      UI_AddSprite(arg1,value1,DAT_0057d658 * value5 + local_268,
                   DAT_0057d65c * local_274 + local_26c,local_240);
      value1 = value1 + 1;
      value5 = value5 + 1;
      ptr3 = ptr3 + 1;
    } while (value5 < 2);
    local_274 = local_274 + 1;
    if (8 < local_274) break;
    value1 = value4;
  }
  DAT_0057d660 = 0;
  return;
}
