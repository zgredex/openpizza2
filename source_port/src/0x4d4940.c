// City_SpawnPerson: ported from Pizza Connection 2 at 0x4d4940.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d4940
#include "pc2_port.h"


uint32_t * __thiscall City_SpawnPerson(void *self,uint32_t arg1)

{
  void *this_00;
  uint32_t uvalue1;
  uint32_t *uptr2;
  int value3;
  uint32_t *this_01;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558e6b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (arg1 == 0xffffffff) {
    ExceptionList = &local_c;
    arg1 = Random_RangeFast(0,3);
  }
  this_00 = operator_new(0x828);
  this_01 = (uint32_t *)0x0;
  local_4 = 0;
  if (this_00 != (void *)0x0) {
    this_01 = Character_Construct(this_00,*(int *)((intptr_t)self + 0xc1c),arg1);
  }
  local_4 = 0xffffffff;
  if ((DAT_0057bb20 == '\0') && (*(int *)((intptr_t)self + 0x340) == 7)) {
    uvalue1 = Random_RangeFast(5,0x14);
    Person_SetMotivation(this_01,uvalue1);
  }
  uptr2 = operator_new(8);
  if (uptr2 == (uint32_t *)0x0) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    uptr2[1] = 0xffffffff;
    *uptr2 = this_01;
  }
  value3 = Game_GetRecordByField814((intptr_t)this_01);
  UI_SetChildIconAndRatingHeight(value3);
  List_Add((void *)((intptr_t)self + 0xfc8),uptr2);
  ExceptionList = local_c;
  return uptr2;
}
