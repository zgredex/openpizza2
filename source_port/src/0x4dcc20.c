// Game_ShuffleProductMarketValues: ported from Pizza Connection 2 at 0x4dcc20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dcc20
#include "pc2_port.h"

void __fastcall Game_ShuffleProductMarketValues(void *arg1)

{
  void *pvVar1;
  uint32_t uvalue2;
  void *pvVar3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  
  uvalue2 = Random_RangeFast(0,7);
  pvVar3 = *(void **)((intptr_t)arg1 + uvalue2 * 4 + 0x200);
  if ((intptr_t)pvVar3 < 1) {
    pvVar3 = arg1;
  }
  pvVar1 = *(void **)((intptr_t)arg1 + uvalue2 * 4 + 0x240);
  if (0 < (intptr_t)pvVar1) {
    pvVar3 = pvVar1;
  }
  uvalue5 = (uint32_t)(0 < (intptr_t)pvVar1);
  pvVar1 = *(void **)((intptr_t)arg1 + uvalue2 * 4 + 0x220);
  if ((intptr_t)uvalue5 < (intptr_t)pvVar1) {
    uvalue5 = 2;
    pvVar3 = pvVar1;
  }
  pvVar1 = *(void **)((intptr_t)arg1 + uvalue2 * 4 + 0x260);
  if ((intptr_t)uvalue5 < (intptr_t)pvVar1) {
    uvalue5 = 3;
    pvVar3 = pvVar1;
  }
  else if (3 < uvalue5) {
    return;
  }
  switch(uvalue5) {
  case 0:
    uvalue4 = Random_SwapOneOfFour(arg1,uvalue2,0,pvVar3);
    *(uint32_t *)((intptr_t)arg1 + uvalue2 * 4 + 0x200) = uvalue4;
    return;
  case 1:
    uvalue4 = Random_SwapOneOfFour(arg1,uvalue2,1,pvVar3);
    *(uint32_t *)((intptr_t)arg1 + uvalue2 * 4 + 0x240) = uvalue4;
    return;
  case 2:
    uvalue4 = Random_SwapOneOfFour(arg1,uvalue2,2,pvVar3);
    *(uint32_t *)((intptr_t)arg1 + uvalue2 * 4 + 0x220) = uvalue4;
    return;
  case 3:
    uvalue4 = Random_SwapOneOfFour(arg1,uvalue2,3,pvVar3);
    *(uint32_t *)((intptr_t)arg1 + uvalue2 * 4 + 0x260) = uvalue4;
    return;
  }
}
