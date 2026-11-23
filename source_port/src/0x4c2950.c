// MarketShareMenu_Init: ported from Pizza Connection 2 at 0x4c2950.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c2950
#include "pc2_port.h"

void __cdecl MarketShareMenu_Init(int *arg1)

{
  int value1;
  void *self;
  int value2;
  int value3;
  
                    /* Initializes the market-share branch comparison page. */
  value3 = 0;
  value1 = *(int *)(DAT_0057c670 + 0x218);
  do {
    self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0
                               );
    value2 = Array_GetStride60(self,value3);
    if (*(int *)(value2 + 0x10) == *(int *)(value1 + 0x24)) break;
    value3 = value3 + 1;
  } while (value3 < 5);
  DAT_0057d730 = value3;
  ExclusiveImport_UpdatePage(arg1);
  return;
}
