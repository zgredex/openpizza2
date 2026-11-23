// Glossary_BranchesPage_Init: ported from Pizza Connection 2 at 0x4aef90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4aef90
#include "pc2_port.h"

void __cdecl Glossary_BranchesPage_Init(void *arg1)

{
  void *self;
  int value1;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Initializes the glossary branch page, scrollbar, and selected entry. */
  self = arg1;
  Array_GetPairByKey(arg1,0x42e,&local_8,&local_4);
  Array_GetPairByKey(self,0x43f,&arg1,&local_c);
  DAT_0057d640 = (intptr_t)arg1 - local_8;
  Array_GetPairByKey(self,0x4b6,&arg1,&local_c);
  DAT_0057d644 = local_c - local_4;
  UI_Group_Create(self,0,4,0x3f9);
  Window_GadgetNotify_Button_SetState(self,0x3f8,1);
  Window_GadgetNotify_Slider_SetRange(self,0x3f6,0,10,0);
  Window_GadgetNotify_Slider_SetValue(self,0x3f6,DAT_0057d648,0);
  Window_GadgetNotify_Slider_SetChangeNotify(self,0x3f6,1);
  value1 = 0x42f;
  do {
    UI_RemoveObjectByKey(self,value1);
    value1 = value1 + 1;
  } while (value1 < 0x43f);
  Glossary_FillCityBuildingList(self,DAT_0057d648);
  Glossary_ShowCityBuildingDetail(self);
  UI_RemoveObjectByKey(self,0x42e);
  UI_RemoveObjectByKey(self,0x43f);
  UI_RemoveObjectByKey(self,0x4b6);
  return;
}
