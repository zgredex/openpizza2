// Distance_Manhattan3: ported from Pizza Connection 2 at 0x4ed570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed570
#include "pc2_port.h"

int Distance_Manhattan3(int arg1,int arg2,int arg3,int arg4)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  
  uvalue1 = arg1 - arg3 >> 0x1f;
  uvalue2 = arg2 - arg4 >> 0x1f;
  return ((arg1 - arg3 ^ uvalue1) - uvalue1) * 3 + ((arg2 - arg4 ^ uvalue2) - uvalue2) * 4;
}
