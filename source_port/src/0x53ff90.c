// Pak_SortEmbeddedEntries: ported from Pizza Connection 2 at 0x53ff90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53ff90
#include "pc2_port.h"


void Pak_SortEmbeddedEntries(int *arg1,uint32_t *arg2)

{
  CRT_QSort(arg1,arg2,0x14,&LAB_0053ffb0);
  return;
}
