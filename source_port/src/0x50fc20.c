// Recipe_Construct: ported from Pizza Connection 2 at 0x50fc20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50fc20
#include "pc2_port.h"

uint32_t * __thiscall Recipe_Construct(void *self,int *arg1,char arg2)

{
  uint32_t uvalue1;
  void *this_00;
  uint32_t *uptr2;
  uint32_t uvalue3;
  int value4;
  double fVar5;
  void *local_c;
  uint8_t *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a406;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((intptr_t)self + 0x48),0);
  local_4 = 0;
  *(uint8_t ***)self = &PTR_Recipe_Delete_0055c698;
  if (arg1 != (int *)0x0) {
    Recipe_LoadFromStream(self,arg1);
    ExceptionList = local_c;
    return self;
  }
  *(uint32_t *)((intptr_t)self + 0x304) = 0;
  *(uint8_t *)((intptr_t)self + 0x1dc) = 0;
  *(uint8_t *)((intptr_t)self + 0x1dd) = 0;
  *(uint32_t *)((intptr_t)self + 0x308) = 5;
  *(uint32_t *)((intptr_t)self + 0x30c) = 0;
  String_Format((uint8_t *)((intptr_t)self + 4),&DAT_005630d0,DAT_00582c6c);
  uptr2 = (uint32_t *)((intptr_t)self + 100);
  for (value4 = 0x56; value4 != 0; value4 = value4 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x1e0);
  for (value4 = 0x18; value4 != 0; value4 = value4 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x1bc);
  for (value4 = 7; value4 != 0; value4 = value4 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  Game_ResetStats((intptr_t)self);
  uvalue1 = Random_RangeFast(7,7);
  if (arg2 == '\0') {
    uvalue1 = 0xffffffff;
  }
  if (0 < (intptr_t)uvalue1) {
    do {
      this_00 = operator_new(0x1c);
      local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
      if (this_00 == (void *)0x0) {
        uptr2 = (uint32_t *)0x0;
      }
      else {
        uptr2 = RecipeTopping_StreamConstruct(this_00,(void *)0x0);
      }
      local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
      uvalue3 = Random_RangeFast(0,0x55);
      *(char *)(uptr2 + 1) = (char)uvalue3;
      *(uint8_t *)((intptr_t)uptr2 + 5) =
           *(uint8_t *)(*(int *)(DAT_0057c670 + 0xa8 + uvalue3 * 4) + 0xa8);
      uvalue3 = Random_RangeFast(0,3);
      *(char *)((intptr_t)uptr2 + 6) = (char)uvalue3;
      uvalue3 = Random_RangeFast(0x2d,400);
      uptr2[2] = uvalue3 - 0x23;
      uvalue3 = Random_RangeFast(0x35,400);
      uptr2[3] = uvalue3 - 0x23;
      List_Add((void *)((intptr_t)self + 0x48),uptr2);
      PlayerStats_Reset((intptr_t)self);
      fVar5 = Game_GetPlayerWeightedStat((intptr_t)self);
      *(float *)((intptr_t)self + 0x44) = (float)fVar5;
      uvalue1 = uvalue1 - 1;
    } while (uvalue1 != 0);
  }
  PlayerStats_Reset((intptr_t)self);
  fVar5 = Game_GetPlayerWeightedStat((intptr_t)self);
  *(float *)((intptr_t)self + 0x44) = (float)fVar5;
  ExceptionList = local_c;
  return self;
}
