// Glossary_ShowCityBuildingDetail: ported from Pizza Connection 2 at 0x4aeda0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4aeda0
#include "pc2_port.h"

void __cdecl Glossary_ShowCityBuildingDetail(void *arg1)

{
  int value1;
  int value2;
  int *ptr3;
  int local_210;
  int local_20c;
  int local_208;
  int local_204;
  char local_200 [256];
  int local_100 [64];
  
  value1 = 0x3e9;
  do {
    Window_GadgetNotify_Button_SetState
              (arg1,value1,(uint32_t)(value1 + -0x3e9 == DAT_0057d64c - DAT_0057d648));
    value1 = value1 + 1;
  } while (value1 < 0x3f6);
  Window_GadgetNotify_Text_SetText(arg1,0x3fd,*(uint32_t *)(&DAT_0058404c + DAT_0057d64c * 4));
  Window_GadgetNotify_Text_SetText(arg1,0x3fe,*(uint32_t *)(&DAT_00583db8 + DAT_0057d64c * 4));
  Array_GetPairByKey(arg1,0x42c,&local_20c,&local_208);
  UI_RemoveObject(arg1,0x42c);
  String_Format(local_200,(uint8_t *)s__s_bik_00569bfc,s_stat_wohnhaus_b_00569c2c + DAT_0057d64c * 0x20
               );
  Movie_CreatePlayer(arg1,0x42c,local_20c,local_208,local_200,(uint32_t *)0x0);
  UI_StartButtonMovie(arg1,0x42c,1);
  Sound_PlayMenuSfxByIndex(DAT_0057ba0c,DAT_0057d64c);
  value1 = 50000;
  do {
    UI_RemoveObject(arg1,value1);
    value1 = value1 + 1;
  } while (value1 < 0xc390);
  if (DAT_0057d64c < 0x11) {
    Array_GetPairByKey(arg1,0x42e,&local_20c,&local_208);
    Stats_BuildObjectProductMatrix(local_100);
    local_210 = 0;
    local_204 = 50000;
    ptr3 = local_100;
    do {
      value2 = 0;
      value1 = local_204;
      local_204 = local_204 + 8;
      do {
        String_Format(local_200,(uint8_t *)s_BEWERTUNG___02d_spr_00569f68,(*ptr3 * 0x10 + 0x32) / 100
                     );
        UI_AddSprite(arg1,value1,DAT_0057d640 * value2 + local_20c,
                     DAT_0057d644 * local_210 + local_208,local_200);
        value1 = value1 + 1;
        value2 = value2 + 1;
        ptr3 = ptr3 + 1;
      } while (value2 < 8);
      local_210 = local_210 + 1;
    } while (local_210 < 8);
  }
  return;
}
