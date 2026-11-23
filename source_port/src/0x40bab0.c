// Game_UpdateIdleCars: ported from Pizza Connection 2 at 0x40bab0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x40bab0
#include "pc2_port.h"

void __fastcall Game_UpdateIdleCars(int arg1)

{
  uint8_t uvalue1;
  void *pvVar2;
  uint32_t extraout_var;
  int value3;
  
                    /* Gives idle cars random road destinations. */
  value3 = 0;
  if (0 < *(int *)(arg1 + 0x6c)) {
    do {
      pvVar2 = (void *)IDMap_Lookup((void *)(arg1 + 0x58),value3,(int *)0x0);
      uvalue1 = Record_GetFlag3E48((intptr_t)pvVar2);
      if ((CONCAT31(extraout_var,uvalue1) == 0) &&
         (*(short *)(*(int *)((intptr_t)pvVar2 + 8) + 0x28) == -1)) {
        Car_PickRandomRoadStep(pvVar2);
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)(arg1 + 0x6c));
  }
  return;
}
