// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x482d70.c:21:25: error: use of undeclared identifier '_local_res0'
// UI_ShowHelpTopicDialog: ported from Pizza Connection 2 at 0x482d70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482d70
#include "pc2_port.h"

void UI_ShowHelpTopicDialog(char arg1)

{
  int *ptr1;
  uint32_t uvalue2;
  void *self;
  int value3;
  int value4;
  int extraout_ECX;
  uint8_t local_res0;
  uint32_t in_stack_00002008;
  char *in_stack_0000200c;
  uint32_t in_stack_00002010;
  uint32_t in_stack_00002014;
  
  local_res0 = (uint8_t)_local_res0;
                    /* Shows a help-topic text dialog. */
  __chkstk(local_res0);
  if (*(int *)(extraout_ECX + 0x268) == 0) {
    ptr1 = Resource_Open(DAT_0057c5d8,in_stack_0000200c,1);
    uvalue2 = Resource_Read(DAT_0057c5d8,&arg1,0x2000,(intptr_t)ptr1);
    (&arg1)[uvalue2] = '\0';
    Resource_Close(DAT_0057c5d8,(intptr_t)ptr1);
    self = HelpTopicDialog_Create((int *)&local_res0);
    *(void **)(extraout_ECX + 0x268) = self;
    Window_GadgetNotify_Text_SetText(self,0x42b,in_stack_00002010);
    Window_GadgetNotify_Text_SetText(*(void **)(extraout_ECX + 0x268),0x42c,&arg1);
    value3 = Window_GadgetNotify_Text_GetLineCount(*(void **)(extraout_ECX + 0x268),0x42c);
    value4 = Window_GadgetNotify_Text_GetHeight(*(void **)(extraout_ECX + 0x268),0x42c);
    if (value4 < value3) {
      UI_ShowChildByID(*(void **)(extraout_ECX + 0x268),0x1f42);
      Window_GadgetNotify_Slider_SetRange(*(void **)(extraout_ECX + 0x268),0x1f42,0,value3 - value4,1)
      ;
      Window_GadgetNotify_Slider_SetValue(*(void **)(extraout_ECX + 0x268),0x1f42,0,0);
      Window_GadgetNotify_Slider_SetChangeNotify(*(void **)(extraout_ECX + 0x268),0x1f42,1);
    }
    else {
      UI_RemoveObjectByKey(*(void **)(extraout_ECX + 0x268),0x1f42);
      Window_GadgetNotify_Text_ResetScroll(*(void **)(extraout_ECX + 0x268),0x42c,0);
    }
    *(uint32_t *)(extraout_ECX + 0x270) = in_stack_00002014;
    *(uint32_t *)(extraout_ECX + 0x274) = in_stack_00002008;
    *(uint32_t *)(extraout_ECX + 0x278) = 0xffffffff;
    *(uint32_t *)(extraout_ECX + 0x27c) = 0;
    *(uint32_t *)(extraout_ECX + 0x280) = 0;
    UI_AddUniquePair(*(void **)(extraout_ECX + 0x268),0x42e,0xd);
    UI_AddUniquePair(*(void **)(extraout_ECX + 0x268),0x42e,0x1b);
    Window_ShowWindowById(DAT_0057c5e0,_local_res0);
  }
  return;
}
