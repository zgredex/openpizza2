// FUN_00555afd: ported from Pizza Connection 2 at 0x555afd.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555afd
#include "pc2_port.h"

void __thiscall FUN_00555afd(void *self,uint32_t *arg1,uint8_t *arg2)

{
  uint16_t local_10 [6];
  
  FUN_0055606a(self,local_10,(int *)&arg2,arg2,0,0,0,0);
  FUN_00555ad1(local_10,arg1);
  return;
}
