// Map_GetFirstLinkedCell: ported from Pizza Connection 2 at 0x4f5c80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5c80
#include "pc2_port.h"

int __thiscall Map_GetFirstLinkedCell(void *self,int arg1)

{
  int value1;
  short *psVar2;
  
  value1 = Array_CountValid8(arg1);
  if (1 < value1) {
    NoOp_Stub();
  }
  value1 = 0;
  psVar2 = (short *)(arg1 + 0x14);
  do {
    if (*psVar2 != -1) {
      value1 = Array_GetRecord28(self,0,(intptr_t)*(short *)(arg1 + 0x14 + value1 * 2));
      return value1;
    }
    value1 = value1 + 1;
    psVar2 = psVar2 + 1;
  } while (value1 < 8);
  return 0;
}
