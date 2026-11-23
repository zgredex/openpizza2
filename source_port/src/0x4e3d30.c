// Advertising_StartCampaignAgainstPlayer: ported from Pizza Connection 2 at 0x4e3d30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3d30
#include "pc2_port.h"

void __thiscall
Advertising_StartCampaignAgainstPlayer(void *self,int arg1,uint32_t arg2,int *arg3)

{
  int value1;
  void *this_00;
  
                    /* Starts an advertising campaign against a rival player. */
  value1 = *(int *)(arg1 + 0x30);
  *(uint32_t *)((intptr_t)self + value1 * 4 + 0x94) = arg2;
  *(uint32_t *)((intptr_t)self + value1 * 4 + 0xcc) = 0;
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*arg3,(int *)0x0);
  Gangster_StartProtectionCollection(this_00,arg1);
  return;
}
