// StatisticsBalance_Load: ported from Pizza Connection 2 at 0x4aa6c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4aa6c0
#include "pc2_port.h"

void __cdecl StatisticsBalance_Load(void *arg1)

{
  CRT_Istream_Read(arg1,&DAT_00569354,4);
  CRT_Istream_Read(arg1,&DAT_0057d5c8,4);
  CRT_Istream_Read(arg1,&DAT_0057d5d0,4);
  CRT_Istream_Read(arg1,&DAT_00569358,4);
  return;
}
