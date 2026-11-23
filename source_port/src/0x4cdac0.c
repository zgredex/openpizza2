// Screen_MissionBriefing_Populate: ported from Pizza Connection 2 at 0x4cdac0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cdac0
#include "pc2_port.h"

void __cdecl
Screen_MissionBriefing_Populate
          (char *arg1,uint32_t arg2,int arg3,uint32_t arg4,char *arg5,
          uint32_t arg6,int arg7,uint32_t arg8,char *arg9,uint32_t arg10,
          int arg11,uint32_t arg12,char *arg13,uint32_t arg14,int arg15,
          uint32_t arg16,char *arg17,uint32_t arg18,int arg19,uint32_t arg20,
          char *arg21,uint32_t arg22,int arg23,uint32_t arg24,char *arg25,
          uint32_t arg26,int arg27,uint32_t arg28,char *arg29,uint32_t arg30,
          int arg31,uint32_t arg32,uint8_t *arg33,uint32_t arg34,int arg35,
          uint32_t arg36,char *arg37,uint32_t arg38,int arg39,uint32_t arg40,
          uint8_t *arg41,uint32_t arg42,int arg43,uint32_t arg44,char *arg45,
          uint32_t arg46,int arg47,uint32_t arg48,char *arg49,uint32_t arg50,
          int arg51,uint32_t arg52,char *arg53,uint32_t arg54,int arg55,
          uint32_t arg56,char *arg57,uint32_t arg58,int arg59,uint32_t arg60,
          char *arg61,uint32_t arg62,int arg63,uint32_t arg64,char *arg65,
          uint32_t arg66,int arg67,uint32_t arg68,char *arg69,uint32_t arg70,
          int arg71,uint32_t arg72,char *arg73,uint32_t arg74,int arg75,
          uint32_t arg76,char *arg77,uint32_t arg78,int arg79,uint32_t arg80,
          char *arg81,uint32_t arg82,int arg83,uint32_t arg84,char *arg85,
          uint32_t arg86,int arg87,uint32_t arg88,char *arg89,uint32_t arg90,
          int arg91,uint32_t arg92,char *arg93,uint32_t arg94,int arg95,
          uint32_t arg96,char *arg97,uint32_t arg98,int arg99)

{
  char *self;
  int value1;
  uint32_t *uptr2;
  int value3;
  int value4;
  uint32_t unaff_EBX;
  uint8_t *unaff_ESI;
  uint32_t unaff_EDI;
  uint32_t unaff_retaddr;
  uint32_t auStack_264 [128];
  char *cptr5;
  int in_stack_ffffffbc;
  uint32_t in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  uint32_t in_stack_ffffffc8;
  int in_stack_ffffffcc;
  uint32_t in_stack_ffffffd0;
  char *in_stack_ffffffd4;
  uint32_t in_stack_ffffffd8;
  int in_stack_ffffffdc;
  uint32_t in_stack_ffffffe0;
  char *in_stack_ffffffe4;
  uint32_t in_stack_ffffffe8;
  int in_stack_ffffffec;
  uint32_t in_stack_fffffff0;
  char *in_stack_fffffff4;
  uint32_t in_stack_fffffff8;
  int in_stack_fffffffc;
  
                    /* Populates the mission briefing screen from its ini. */
  self = arg1;
  if (DAT_0057c5c0 != 0) {
    Gadget_SetText(arg1,0x433,DAT_0058280c);
  }
  if (DAT_0057c5c0 == 7) {
    Gadget_SetText(self,0x433,DAT_00581bfc);
  }
  value1 = IDMap_Lookup(&DAT_0057c590,DAT_0057bb40,(int *)0x0);
  uptr2 = auStack_264 + 0x89;
  cptr5 = s__s_ini_0056b380;
  String_Format((uint8_t *)uptr2,(uint8_t *)s__s_ini_0056b380,value1);
  uptr2 = CityDefinition_ParseIni
                     (DAT_0057c5d8,auStack_264 + 0x89,(uint8_t *)uptr2,cptr5,value1,unaff_EDI,
                      unaff_ESI,unaff_EBX,in_stack_ffffffbc,in_stack_ffffffc0,in_stack_ffffffc4,
                      in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0,in_stack_ffffffd4,
                      in_stack_ffffffd8,in_stack_ffffffdc,in_stack_ffffffe0,in_stack_ffffffe4,
                      in_stack_ffffffe8,in_stack_ffffffec,in_stack_fffffff0,in_stack_fffffff4,
                      in_stack_fffffff8,in_stack_fffffffc,unaff_retaddr,arg1,arg2,arg3,
                      arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,
                      arg13,arg14,arg15,arg16,arg17,arg18,arg19,arg20,
                      arg21,arg22,arg23,arg24,arg25,arg26,arg27,arg28,
                      arg29,arg30,arg31,arg32,arg33,arg34,arg35,arg36,
                      arg37,arg38,arg39,arg40,arg41,arg42,arg43,arg44,
                      arg45,arg46,arg47,arg48,arg49,arg50,arg51,arg52,
                      arg53,arg54,arg55,arg56,arg57,arg58,arg59,arg60,
                      arg61,arg62,arg63,arg64,arg65,arg66,arg67,arg68,
                      arg69,arg70,arg71,arg72,arg73,arg74,arg75,arg76,
                      arg77,arg78,arg79,arg80,arg81,arg82,arg83,arg84,
                      arg85,arg86,arg87,arg88,arg89,arg90,arg91,arg92,
                      arg93,arg94,arg95,arg96,arg97,arg98,arg99);
  Window_GadgetNotify_Text_SetText(self,0x42c,uptr2 + 0x106);
  Window_GadgetNotify_Text_SetText(self,0x42d,uptr2);
  String_Format((uint8_t *)(auStack_264 + 0x89),(uint8_t *)s_maps__s_spr_0056b330,uptr2 + 0x10);
  Array_GetPairByKey(self,0x435,auStack_264 + 0x88,&arg1);
  UI_AddSprite(self,200000,in_stack_ffffffbc,(intptr_t)arg1,(char *)(auStack_264 + 0x89));
  value1 = Window_GadgetNotify_Text_GetLineCount(self,0x42c);
  value3 = Window_GadgetNotify_Text_GetHeight(self,0x42c);
  value4 = Window_GadgetNotify_Text_GetFont(self,0x42c);
  value3 = value3 / *(int *)(value4 + 0x9b0);
  if (value3 < value1) {
    UI_ShowChildByID(self,0x42e);
    Window_GadgetNotify_Slider_SetRange(self,0x42e,0,(value1 - value3) * 100,1);
    Window_GadgetNotify_Slider_SetValue(self,0x42e,0,0);
    Window_GadgetNotify_Slider_SetChangeNotify(self,0x42e,1);
  }
  else {
    UI_RemoveObjectByKey(self,0x42e);
    Window_GadgetNotify_Text_ResetScroll(self,0x42c,0);
  }
  UI_SetChildLabelText(self,200000,1,(char *)0x0);
  UI_SetChildLabelText(self,0x42e,1,(char *)0x0);
  UI_SetChildLabelText(self,0x433,1,(char *)0x0);
  UI_SetChildLabelText(self,0x434,1,(char *)0x0);
  Window_GadgetNotify_Text_SetText(self,0x429,DAT_00582e4c);
  Sound_PlayMissionSpeech(DAT_0057ba0c,DAT_0057bb40,'\0');
  return;
}
