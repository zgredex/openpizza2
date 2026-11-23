// COM_QueryInterfaceGuid: ported from Pizza Connection 2 at 0x53ef90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53ef90
#include "pc2_port.h"

uint32_t __thiscall COM_QueryInterfaceGuid(void *self,int *arg1,uint32_t *arg2)

{
  int value1;
  int *ptr2;
  bool flag3;
  
  value1 = 4;
  flag3 = true;
  ptr2 = &DAT_0055cb68;
  do {
    if (value1 == 0) break;
    value1 = value1 + -1;
    flag3 = *arg1 == *ptr2;
    arg1 = arg1 + 1;
    ptr2 = ptr2 + 1;
  } while (flag3);
  if (flag3) {
    *arg2 = self;
    return 0;
  }
  *arg2 = 0;
  return 0x80004002;
}
