// UI_RemoveWindowForObject: ported from Pizza Connection 2 at 0x482f10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482f10
#include "pc2_port.h"

void __fastcall UI_RemoveWindowForObject(int arg1)

{
  int value1;
  
  if (*(int *)(arg1 + 0x26c) != 0) {
    value1 = Object_GetId(*(int *)(arg1 + 0x26c));
    UI_RemoveWindowByID(DAT_0057c5e0,value1);
  }
  return;
}
