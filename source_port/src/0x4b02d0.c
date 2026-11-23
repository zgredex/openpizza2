// StatisticsBackdrop_RestoreCategorySelection: ported from Pizza Connection 2 at 0x4b02d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b02d0
#include "pc2_port.h"

void __cdecl StatisticsBackdrop_RestoreCategorySelection(void *arg1)

{
  if (DAT_0056a68c == -1) {
    Gadget_SetButtonState(arg1,0x1f41,1);
    return;
  }
  Window_GadgetNotify_Button_SetState(arg1,(&DAT_0056a66c)[DAT_0056a68c],1);
  return;
}
