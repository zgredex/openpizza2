// Glossary_BuildingsPage_Init: ported from Pizza Connection 2 at 0x4aeac0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4aeac0
#include "pc2_port.h"

void __cdecl Glossary_BuildingsPage_Init(void *arg1)

{
  int value1;
  uint32_t *uptr2;
  
                    /* Initializes the glossary building page and its tabs. */
  UI_Group_Create(arg1,0,4,0x3f9);
  Window_GadgetNotify_Button_SetState(arg1,0x3f7,1);
  UI_RemoveObjectByKey(arg1,0x3f6);
  value1 = 0x41f;
  uptr2 = &DAT_00583fd4;
  do {
    Window_GadgetNotify_Text_SetText(arg1,value1,*uptr2);
    uptr2 = uptr2 + 1;
    value1 = value1 + 1;
  } while ((intptr_t)uptr2 < 0x584008);
  Glossary_ShowCompanyBuildingDetail(arg1);
  return;
}
