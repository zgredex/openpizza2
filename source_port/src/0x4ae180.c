// Glossary_ShowCompanyBuildingDetail: ported from Pizza Connection 2 at 0x4ae180.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ae180
#include "pc2_port.h"

void __cdecl Glossary_ShowCompanyBuildingDetail(void *arg1)

{
  int value1;
  int64_t lvalue2;
  int local_88;
  int local_84;
  char local_80 [128];
  
  value1 = 0x3e9;
  do {
    Window_GadgetNotify_Button_SetState(arg1,value1,(uint32_t)(value1 + -0x3e9 == DAT_0057d63c));
    value1 = value1 + 1;
  } while (value1 < 0x3f6);
  Array_GetPairByKey(arg1,0x3fb,&local_84,&local_88);
  String_Format(local_80,(uint8_t *)s__s_bik_00569bfc,s_stat_pizz_a_00569680 + DAT_0057d63c * 0x6c);
  UI_RemoveObject(arg1,0x3fb);
  Movie_CreatePlayer(arg1,0x3fb,local_84,local_88,local_80,(uint32_t *)0x0);
  UI_StartButtonMovie(arg1,0x3fb,1);
  Sound_PlayStatisticPageSfx(DAT_0057ba0c,DAT_0057d63c);
  Window_GadgetNotify_Text_SetText
            (arg1,0x3fd,(&DAT_00583fd4)[*(int *)(&DAT_005696c0 + DAT_0057d63c * 0x6c)]);
  Window_GadgetNotify_Text_SetText
            (arg1,0x3fe,
             *(uint32_t *)(&DAT_00584008 + *(int *)(&DAT_005696c4 + DAT_0057d63c * 0x6c) * 4));
  Window_GadgetNotify_Text_SetText
            (arg1,0x1f44,
             *(uint32_t *)(&DAT_00584018 + *(int *)(&DAT_005696e8 + DAT_0057d63c * 0x6c) * 4));
  IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  switch(DAT_0057d63c) {
  case 0:
    lvalue2 = __ftol();
    Gadget_SetTextf(arg1,0x40a,&DAT_005683a4,(intptr_t)lvalue2);
    lvalue2 = __ftol();
    Gadget_SetTextf(arg1,0x40b,&DAT_005683a4,(intptr_t)lvalue2);
    Gadget_SetTextf(arg1,0x40c,(uint8_t *)s__d__s_00568324,
                    *(uint32_t *)(&DAT_005696d0 + DAT_0057d63c * 0x6c));
    lvalue2 = __ftol();
    Gadget_SetTextf(arg1,0x40d,&DAT_005683a4,(intptr_t)lvalue2);
    Window_GadgetNotify_Text_SetText(arg1,0x40e,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(arg1,0x40f,DAT_00582adc);
    Gadget_SetTextf(arg1,0x410,(uint8_t *)s__d__s_00568324,
                    *(uint32_t *)(&DAT_005696e0 + DAT_0057d63c * 0x6c));
    Gadget_SetTextf(arg1,0x411,(uint8_t *)s__d__s_00568324,
                    (*(int *)(&DAT_005696e4 + DAT_0057d63c * 0x6c) * 200000) / 1000);
    return;
  case 1:
  case 2:
    lvalue2 = __ftol();
    Gadget_SetTextf(arg1,0x40a,&DAT_005683a4,(intptr_t)lvalue2);
    Window_GadgetNotify_Text_SetText(arg1,0x40b,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(arg1,0x40c,DAT_00582adc);
    lvalue2 = __ftol();
    Gadget_SetTextf(arg1,0x40d,&DAT_005683a4,(intptr_t)lvalue2);
    Gadget_SetTextf(arg1,0x40e,&DAT_005683a4,*(uint32_t *)(&DAT_005696d8 + DAT_0057d63c * 0x6c)
                   );
    Gadget_SetTextf(arg1,0x40f,(uint8_t *)s__d__s_00568324,
                    *(uint32_t *)(&DAT_005696dc + DAT_0057d63c * 0x6c));
    Gadget_SetTextf(arg1,0x410,(uint8_t *)s__d__s_00568324,
                    *(uint32_t *)(&DAT_005696e0 + DAT_0057d63c * 0x6c));
    value1 = *(int *)(&DAT_005696e4 + DAT_0057d63c * 0x6c);
    goto LAB_004ae66b;
  case 3:
    lvalue2 = __ftol();
    Gadget_SetTextf(arg1,0x40a,&DAT_005683a4,(intptr_t)lvalue2);
    lvalue2 = __ftol();
    Gadget_SetTextf(arg1,0x40b,&DAT_005683a4,(intptr_t)lvalue2);
    Gadget_SetTextf(arg1,0x40c,(uint8_t *)s__d__s_00568324,
                    *(uint32_t *)(&DAT_005696d0 + DAT_0057d63c * 0x6c));
    lvalue2 = __ftol();
    Gadget_SetTextf(arg1,0x40d,&DAT_005683a4,(intptr_t)lvalue2);
    Window_GadgetNotify_Text_SetText(arg1,0x40e,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(arg1,0x40f,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(arg1,0x410,DAT_00582720);
    value1 = *(int *)(&DAT_005696e4 + DAT_0057d63c * 0x6c);
LAB_004ae66b:
    Gadget_SetTextf(arg1,0x411,(uint8_t *)s__d__s_00568324,(value1 * 200000) / 1000);
    return;
  case 4:
  case 5:
    lvalue2 = __ftol();
    Gadget_SetTextf(arg1,0x40a,&DAT_005683a4,(intptr_t)lvalue2);
    Window_GadgetNotify_Text_SetText(arg1,0x40b,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(arg1,0x40c,DAT_00582adc);
    lvalue2 = __ftol();
    Gadget_SetTextf(arg1,0x40d,&DAT_005683a4,(intptr_t)lvalue2);
    Gadget_SetTextf(arg1,0x40e,&DAT_005683a4,*(uint32_t *)(&DAT_005696d8 + DAT_0057d63c * 0x6c)
                   );
    Gadget_SetTextf(arg1,0x40f,(uint8_t *)s__d__s_00568324,
                    *(uint32_t *)(&DAT_005696dc + DAT_0057d63c * 0x6c));
    Window_GadgetNotify_Text_SetText(arg1,0x410,DAT_00582720);
    Gadget_SetTextf(arg1,0x411,(uint8_t *)s__d__s_00568324,
                    (*(int *)(&DAT_005696e4 + DAT_0057d63c * 0x6c) * 200000) / 1000);
    return;
  case 6:
    Window_GadgetNotify_Text_SetText(arg1,0x40a,DAT_00582adc);
    lvalue2 = __ftol();
    Gadget_SetTextf(arg1,0x40b,&DAT_005683a4,(intptr_t)lvalue2);
    Gadget_SetTextf(arg1,0x40c,(uint8_t *)s__d__s_00568324,
                    *(uint32_t *)(&DAT_005696d0 + DAT_0057d63c * 0x6c));
    lvalue2 = __ftol();
    Gadget_SetTextf(arg1,0x40d,&DAT_005683a4,(intptr_t)lvalue2);
    Window_GadgetNotify_Text_SetText(arg1,0x40e,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(arg1,0x40f,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(arg1,0x410,DAT_00582720);
    break;
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
    Window_GadgetNotify_Text_SetText(arg1,0x40a,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(arg1,0x40b,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(arg1,0x40c,DAT_00582adc);
    lvalue2 = __ftol();
    Gadget_SetTextf(arg1,0x40d,&DAT_005683a4,(intptr_t)lvalue2);
    Gadget_SetTextf(arg1,0x40e,&DAT_005683a4,*(uint32_t *)(&DAT_005696d8 + DAT_0057d63c * 0x6c)
                   );
    Gadget_SetTextf(arg1,0x40f,(uint8_t *)s__d__s_00568324,
                    *(uint32_t *)(&DAT_005696dc + DAT_0057d63c * 0x6c));
    Window_GadgetNotify_Text_SetText(arg1,0x410,DAT_00582720);
    break;
  case 0xc:
    Window_GadgetNotify_Text_SetText(arg1,0x40a,DAT_00582adc);
    lvalue2 = __ftol();
    Gadget_SetTextf(arg1,0x40b,&DAT_005683a4,(intptr_t)lvalue2);
    Gadget_SetTextf(arg1,0x40c,(uint8_t *)s__d__s_00568324,
                    *(uint32_t *)(&DAT_005696d0 + DAT_0057d63c * 0x6c));
    Gadget_SetTextf(arg1,0x40d,&DAT_005683a4,*(uint32_t *)(&DAT_005696d4 + DAT_0057d63c * 0x6c)
                   );
    Window_GadgetNotify_Text_SetText(arg1,0x40e,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(arg1,0x40f,DAT_00582adc);
    Window_GadgetNotify_Text_SetText(arg1,0x410,DAT_00582720);
    break;
  default:
    goto switchD_004ae2fd_default;
  }
  Window_GadgetNotify_Text_SetText(arg1,0x411,DAT_00582720);
switchD_004ae2fd_default:
  return;
}
