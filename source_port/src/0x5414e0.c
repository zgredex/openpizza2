// Input_GetDeviceObjectInfo: ported from Pizza Connection 2 at 0x5414e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5414e0
#include "pc2_port.h"

uint32_t __cdecl Input_GetDeviceObjectInfo(int *arg1,uint32_t arg2)

{
  int value1;
  uint32_t uvalue2;
  uint32_t local_4;
  
  local_4 = 0;
  value1 = (**(code **)(*arg1 + 0x14))(arg1,&DAT_0055cbe8,arg2,&local_4);
  if ((value1 < 0) || (uvalue2 = 1, ((uint32_t)arg1 & 1) == 0)) {
    uvalue2 = 0;
  }
  return uvalue2;
}
