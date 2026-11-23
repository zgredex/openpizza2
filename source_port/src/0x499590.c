// IngredientPanel_Save: ported from Pizza Connection 2 at 0x499590.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x499590
#include "pc2_port.h"

void __cdecl IngredientPanel_Save(void *arg1)

{
  CRT_Ostream_Write(arg1,&DAT_00568910,4);
  return;
}
