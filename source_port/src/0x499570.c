// IngredientPanel_Load: ported from Pizza Connection 2 at 0x499570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x499570
#include "pc2_port.h"

void __cdecl IngredientPanel_Load(void *arg1)

{
  CRT_Istream_Read(arg1,&DAT_00568910,4);
  return;
}
