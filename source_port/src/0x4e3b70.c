// Player_RestorePlanTargetAnimations: ported from Pizza Connection 2 at 0x4e3b70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3b70
#include "pc2_port.h"

void __fastcall Player_RestorePlanTargetAnimations(int arg1)

{
  int value1;
  void *self;
  int value2;
  int value3;
  
                    /* Rebinds plan target color animations after a load. */
  value1 = *(int *)(arg1 + 0x140);
  self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value3 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)(arg1 + 300),value3,(int *)0x0);
      if ((*(int *)(value2 + 4) != 0) && (*(int *)(value2 + 8) == 3)) {
        value2 = Game_FindRecordByField24(self,*(int *)(value2 + 0x2c));
        if (value2 != 0) {
          Object_SetFacadeAndLogoVariant(self,1,value2,arg1);
        }
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return;
}
