// Window_GetGadgetChecked: ported from Pizza Connection 2 at 0x52fef0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52fef0
#include "pc2_port.h"

int __thiscall Window_GetGadgetChecked(void *self,int arg1)

{
  int value1;
  
  value1 = Array_GetRecordByKey(self,arg1);
  if (value1 == 0) {
    DebugConsole_Errorf(*(uint32_t *)((intptr_t)self + 0x134),0,
                        (uint8_t *)s_Window__GadgetNotify__Gadget___d_0057447c,arg1);
    value1 = 0;
  }
  return value1;
}
