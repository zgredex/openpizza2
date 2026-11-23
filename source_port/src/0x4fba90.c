// Map_GridToScreenOffset: ported from Pizza Connection 2 at 0x4fba90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fba90
#include "pc2_port.h"

void Map_GridToScreenOffset(void *arg1,int arg2,int arg3,int *arg4,int *arg5)

{
  int local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  Object_GetRect100(arg1,&arg1,&local_4,&local_c,&local_8);
  *arg4 = (intptr_t)arg1 + arg2;
  *arg5 = local_c + arg3;
  return;
}
