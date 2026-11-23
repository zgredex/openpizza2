// CRT_FlushStream: ported from Pizza Connection 2 at 0x5506b2.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5506b2
#include "pc2_port.h"

uint32_t __cdecl CRT_FlushStream(int *arg1)

{
  DWORD DVar1;
  uint32_t uvalue2;
  DWORD DVar3;
  
  uvalue2 = 0;
  if ((((uint8_t)arg1[3] & 3) == 2) && ((arg1[3] & 0x108U) != 0)) {
    DVar3 = *arg1 - arg1[2];
    if (0 < (intptr_t)DVar3) {
      DVar1 = CRT_Write(arg1[4],(char *)arg1[2],DVar3);
      if (DVar1 == DVar3) {
        if ((arg1[3] & 0x80U) != 0) {
          arg1[3] = arg1[3] & 0xfffffffd;
        }
      }
      else {
        arg1[3] = arg1[3] | 0x20;
        uvalue2 = 0xffffffff;
      }
    }
  }
  arg1[1] = 0;
  *arg1 = arg1[2];
  return uvalue2;
}
