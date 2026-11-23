// __allmul: ported from Pizza Connection 2 at 0x54fca0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54fca0
#include "pc2_port.h"

/* Library Function - Single Match
    __allmul
   
   Library: Visual Studio */

int64_t __allmul(uint32_t arg1,int arg2,uint32_t arg3,int arg4)

{
  if (arg4 == 0 && arg2 == 0) {
    return (uint64_t)arg1 * (uint64_t)arg3;
  }
  return CONCAT44((intptr_t)((uint64_t)arg1 * (uint64_t)arg3 >> 0x20) +
                  arg2 * arg3 + arg1 * arg4,
                  (intptr_t)((uint64_t)arg1 * (uint64_t)arg3));
}
