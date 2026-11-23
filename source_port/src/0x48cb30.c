// Map_RefreshObjectSprites: ported from Pizza Connection 2 at 0x48cb30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48cb30
#include "pc2_port.h"

void __fastcall Map_RefreshObjectSprites(int arg1)

{
  int value1;
  void *self;
  int value2;
  int value3;
  int value4;
  
  value1 = IDMap_Lookup((void *)(arg1 + 4),*(int *)(arg1 + 0x2f4),(int *)0x0);
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,*(int *)(arg1 + 0x2dac),(int *)0x0);
  if (self != (void *)0x0) {
    value2 = Get_FieldF0((intptr_t)self);
    while (value2 = value2 + -1, -1 < value2) {
      UI_RemoveObject(self,value2);
    }
    value2 = *(int *)(value1 + 0xfc0);
    value4 = 0;
    if (0 < value2) {
      do {
        value3 = IDMap_Lookup((void *)(value1 + 0xfac),value4,(int *)0x0);
        if (value3 != 0) {
          Game_UpdateObjectMapMarker(value3);
        }
        value4 = value4 + 1;
      } while (value4 < value2);
    }
  }
  return;
}
