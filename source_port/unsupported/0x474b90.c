// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x474b90.c:17:80: error: use of undeclared identifier 'NoOp_Stub'
// LoadingWindow_Create: ported from Pizza Connection 2 at 0x474b90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x474b90
#include "pc2_port.h"

void * __cdecl LoadingWindow_Create(int *arg1)

{
  int value1;
  void *self;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
                    /* Creates the modal loading/progress window. */
  value1 = UI_CreateWindow(DAT_0057c5e0,0xbb,0xf8,s_PE_RQ_LOADING_spr_00566d34,NoOp_Stub);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  value1 = UI_CreateSlider(self,0x3f7,0x13,0x46,400,s_SC_00_spr_00564324,1,0);
  if (value1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    Window_GadgetNotify_Slider_SetGradientColors(self,0x3f7,&local_10);
  }
  value1 = UI_AddText(self,0x3e9,0x10,0x17,s_VERDANA16_fnt_00565788,DAT_005828f0);
  if (value1 != 0) {
    Window_GadgetNotify_Text_SetTextColor(self,0x3e9,0);
    Window_GadgetNotify_Text_SetLayout(self,0x3e9,2,400,0,0);
  }
  return self;
}
