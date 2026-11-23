// MapObject_RestoreSignLogoAnimations: ported from Pizza Connection 2 at 0x480e30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480e30
#include "pc2_port.h"

void __fastcall MapObject_RestoreSignLogoAnimations(int arg1)

{
  int value1;
  int value2;
  void *self;
  
                    /* Rebinds sign/logo animations on building objects after a load. */
  value1 = *(int *)(arg1 + 0x16f0);
  if ((value1 != 0) && (*(int *)(value1 + 4) == 0xf)) {
    value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg1 + 0x30));
    if (value2 != 0) {
      self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                  *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
      Object_SetSignAndLogoVariant(self,1,value1,value2);
    }
  }
  return;
}
