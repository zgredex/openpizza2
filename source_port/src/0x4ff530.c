// AI_SendGangsterForProtection: ported from Pizza Connection 2 at 0x4ff530.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ff530
#include "pc2_port.h"

uint32_t AI_SendGangsterForProtection(void *arg1,int arg2)

{
  int value1;
  int *ptr2;
  void *self;
  uint32_t uvalue3;
  int value4;
  
                    /* Sends a gangster to collect protection money. */
  ptr2 = Game_FindFreeStaffRecord(arg1,0x1d);
  if (ptr2 == (int *)0x0) {
    return 0;
  }
  self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr2,(int *)0x0);
  if (self == (void *)0x0) {
    return 0;
  }
  uvalue3 = Game_CanAffordWithCurrency(arg1,0x17,5000.0,'\x01',0xffffffff);
  if ((char)uvalue3 == '\0') {
    return 0;
  }
  Object_SetFieldA4Locked(self,6);
  Object_SetDestinationAndTarget(self,0xc,arg2);
  value1 = *(int *)(arg2 + 8);
  value4 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
  if (value1 == value4) {
    Sound_SetTimeout(DAT_0057ba0c);
  }
  return 1;
}
