// Game_GetRecordField814Value: ported from Pizza Connection 2 at 0x4d3930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3930
#include "pc2_port.h"

int __fastcall Game_GetRecordField814Value(int arg1)

{
  int value1;
  
  value1 = Game_GetRecordByField814(arg1);
  return value1 + 4;
}
