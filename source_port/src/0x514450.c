// Storage_SetSupplierBuilding: ported from Pizza Connection 2 at 0x514450.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x514450
#include "pc2_port.h"

void __thiscall Storage_SetSupplierBuilding(void *self,int arg1)

{
  void *this_00;
  
  *(int *)((intptr_t)self + 0x30) = arg1;
  this_00 = *(void **)(DAT_0057c670 + 0x264);
  if (this_00 != (void *)0x0) {
    UI_QueueControlCommand(this_00,-0x1861c,0x23,0);
    UI_QueueControlCommand(this_00,-0x18659,0x23,0);
  }
  if (arg1 != -1) {
    Storage_OrderDelivery((intptr_t)self);
  }
  return;
}
