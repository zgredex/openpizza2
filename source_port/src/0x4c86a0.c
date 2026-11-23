// EndResultGraph_SelectCategory: ported from Pizza Connection 2 at 0x4c86a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c86a0
#include "pc2_port.h"

void __cdecl EndResultGraph_SelectCategory(void *arg1)

{
  if (DAT_0056b270 == -1) {
    Gadget_SetButtonState(arg1,0x4d0,1);
    EndResultGraph_DrawChart(arg1);
    return;
  }
  Window_GadgetNotify_Button_SetState(arg1,(&DAT_0056b230)[DAT_0056b270],1);
  EndResultGraph_DrawChart(arg1);
  return;
}
