// MapObject_StepToRandomCell: ported from Pizza Connection 2 at 0x507d30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x507d30
#include "pc2_port.h"

void __fastcall MapObject_StepToRandomCell(void *arg1)

{
  uint8_t uvalue1;
  int value2;
  uint32_t extraout_var;
  int value3;
  
                    /* Steps a map object to a random active cell or rebuilds its route. */
  if (*(int *)((intptr_t)arg1 + 200) == 0) {
    value3 = 0;
  }
  else {
    value3 = *(int *)(*(int *)((intptr_t)arg1 + 200) + 0x20);
  }
  value2 = Array_PickRandomActiveRecord28(*(void **)((intptr_t)arg1 + 0xc4),(int *)0x1);
  uvalue1 = Object_IsVisibleThisFrame((intptr_t)arg1);
  if (CONCAT31(extraout_var,uvalue1) == 0) {
    Person_PathToTileAndStep(arg1,value3,value2);
    return;
  }
  Person_RecomputePathStep((intptr_t)arg1);
  return;
}
