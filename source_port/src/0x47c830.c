// City_ComputeServiceLevel: ported from Pizza Connection 2 at 0x47c830.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47c830
#include "pc2_port.h"

int __fastcall City_ComputeServiceLevel(int arg1)

{
  char cVar1;
  int value2;
  int value3;
  int value4;
  char *cptr5;
  
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(arg1 + 0x34),(int *)0x0);
  value4 = 0x18;
  value3 = 0;
  cptr5 = (char *)(value2 + 0xa4);
  do {
    if ((value3 < 0) || (3 < value3)) {
      cVar1 = '\0';
    }
    else {
      cVar1 = *cptr5;
    }
    if (cVar1 + -6 < value4) {
      value4 = cVar1 + -6;
    }
    value3 = value3 + 1;
    cptr5 = cptr5 + 4;
  } while (value3 < 4);
  if (value4 < 0x19) {
    return (0x18 - value4) / *(int *)(&DAT_005675ac + *(int *)(arg1 + 0x38) * 4) + 1;
  }
  return 0;
}
