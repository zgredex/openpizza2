// Game_BuildCompetitorBuildingList: ported from Pizza Connection 2 at 0x489880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x489880
#include "pc2_port.h"


uint32_t * __fastcall Game_BuildCompetitorBuildingList(void *arg1)

{
  int value1;
  void *self;
  uint32_t *this_00;
  int value2;
  int value3;
  uint32_t uvalue4;
  int local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055834b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  self = operator_new(0x1c);
  local_4 = 0;
  if (self == (void *)0x0) {
    this_00 = (uint32_t *)0x0;
  }
  else {
    this_00 = List_Construct(self,0);
  }
  local_4 = 0xffffffff;
  local_14 = 0;
  do {
    value2 = Game_GetPlayerBySlot(arg1,local_14);
    if ((((value2 != 0) &&
         (value1 = *(int *)(value2 + 0x48), value3 = Game_GetCurrentPlayerCompanyName((intptr_t)arg1),
         value1 != value3)) && (value1 = *(int *)(value2 + 0x15c), value1 != 0)) &&
       (value3 = 0, 0 < value1)) {
      do {
        uvalue4 = IDMap_Lookup((void *)(value2 + 0x148),value3,(int *)0x0);
        List_Add(this_00,uvalue4);
        value3 = value3 + 1;
      } while (value3 < value1);
    }
    local_14 = local_14 + 1;
  } while (local_14 < 6);
  ExceptionList = local_c;
  return this_00;
}
