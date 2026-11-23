// CompanyOverview_UpdateBuildingRows: ported from Pizza Connection 2 at 0x4a47e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a47e0
#include "pc2_port.h"

void __cdecl CompanyOverview_UpdateBuildingRows(void *arg1,int arg2)

{
  void *self;
  int value1;
  int value2;
  int value3;
  uint32_t uvalue4;
  int local_4;
  
  self = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_4 = *(int *)((intptr_t)self + 0x15c);
  if (local_4 < 9) {
    arg2 = 0;
  }
  else {
    local_4 = 8;
  }
  value2 = 0;
  if (0 < local_4) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x148),value2 + arg2,(int *)0x0);
      Window_GadgetNotify_Text_SetText(arg1,(&DAT_00568f90)[value2],value1 + 4);
      value1 = Game_CountObjectsForOwner(self,value1,0x17);
      if (value1 == 0) {
        value3 = (&DAT_00568fb0)[value2];
        uvalue4 = 0xff;
      }
      else {
        value3 = (&DAT_00568fb0)[value2];
        uvalue4 = 0;
      }
      Window_GadgetNotify_Text_SetTextColor(arg1,value3,uvalue4);
      Gadget_SetTextf(arg1,(&DAT_00568fb0)[value2],&DAT_005686f4,value1);
      value2 = value2 + 1;
    } while (value2 < local_4);
  }
  return;
}
