// Rect_Center: ported from Pizza Connection 2 at 0x4f3490.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f3490
#include "pc2_port.h"

void Rect_Center(int *arg1,int *arg2)

{
  int value1;
  
  value1 = DAT_00571954;
  *arg1 = *arg1 - (DAT_00571950 >> 1);
  *arg2 = *arg2 - (value1 >> 1);
  return;
}
