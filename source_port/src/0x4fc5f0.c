// Company_RefreshMenuSalesIfDue: ported from Pizza Connection 2 at 0x4fc5f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fc5f0
#include "pc2_port.h"

uint32_t __thiscall Company_RefreshMenuSalesIfDue(void *self,int arg1)

{
  int value1;
  
  value1 = Game_GetDateField0C(DAT_0057c670);
  if (*(int *)((intptr_t)self + arg1 * 0x168 + 0x44) <= value1) {
    *(int *)((intptr_t)self + arg1 * 0x168 + 0x44) = value1 + 0x18;
    Game_RecomputeCompanyMenuSales(self,arg1);
  }
  return 1;
}
