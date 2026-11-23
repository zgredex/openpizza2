// Pak_SortEntries: ported from Pizza Connection 2 at 0x402240.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x402240
#include "pc2_port.h"


void Pak_SortEntries(int *arg1,uint32_t *arg2)

{
  CRT_QSort(arg1,arg2,0x14,&LAB_004021f0);
  return;
}
