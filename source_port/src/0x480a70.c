// Game_SetObjectValue100: ported from Pizza Connection 2 at 0x480a70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480a70
#include "pc2_port.h"

uint32_t __thiscall Game_SetObjectValue100(void *self,void *arg1)

{
  uint32_t uvalue1;
  double fVar2;
  
  fVar2 = Game_ComputeCityPriceShare((intptr_t)self,(intptr_t)arg1,(float *)0x0);
  Game_CanAfford(self,5,(float)fVar2,'\0',-1);
  uvalue1 = Game_SetModeByte(arg1,100);
  return CONCAT31((int3)((uint32_t)uvalue1 >> 8),1);
}
