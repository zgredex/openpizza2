// EmployeeAvatar_Construct: ported from Pizza Connection 2 at 0x54b460.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b460
#include "pc2_port.h"

uint32_t * __thiscall EmployeeAvatar_Construct(void *self,void *arg1,void *arg2)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b931;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((intptr_t)self + 4),0);
  local_4 = 0;
  List_Construct((void *)((intptr_t)self + 0x20),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x3c),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x58),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x74),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((4) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0x90),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((5) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 0xac),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  List_Construct((void *)((intptr_t)self + 200),0);
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),7);
  *(uint8_t ***)self = &PTR_EmployeeAvatar_Delete_0055cb44;
  Sprite_LoadSequence((uint8_t *)s_PizzaImages_HEAD_F__02d_spr_00576590,(void *)((intptr_t)self + 0x20),
                      arg1,arg2);
  Sprite_LoadSequence((uint8_t *)s_PizzaImages_HEAD_M__02d_spr_00576574,(void *)((intptr_t)self + 4),arg1
                      ,arg2);
  Sprite_LoadSequence((uint8_t *)s_PizzaImages_AUGEN_F__02d_spr_00576554,(void *)((intptr_t)self + 0x58),
                      arg1,arg2);
  Sprite_LoadSequence((uint8_t *)s_PizzaImages_AUGEN_M__02d_spr_00576534,(void *)((intptr_t)self + 0x3c),
                      arg1,arg2);
  Sprite_LoadSequence((uint8_t *)s_PizzaImages_HAARE_F__02d_spr_00576514,(void *)((intptr_t)self + 0x90),
                      arg1,arg2);
  Sprite_LoadSequence((uint8_t *)s_PizzaImages_HAARE_M__02d_spr_005764f4,(void *)((intptr_t)self + 0x74),
                      arg1,arg2);
  Sprite_LoadSequence((uint8_t *)s_PizzaImages_MUND_F__02d_spr_005764d8,(void *)((intptr_t)self + 200),
                      arg1,arg2);
  Sprite_LoadSequence((uint8_t *)s_PizzaImages_MUND_M__02d_spr_005764bc,(void *)((intptr_t)self + 0xac),
                      arg1,arg2);
  DAT_00585588 = *(int *)((intptr_t)self + 0x34);
  if (*(int *)((intptr_t)self + 0x18) <= *(int *)((intptr_t)self + 0x34)) {
    DAT_00585588 = *(int *)((intptr_t)self + 0x18);
  }
  DAT_00585580 = *(int *)((intptr_t)self + 0x6c);
  if (*(int *)((intptr_t)self + 0x50) <= *(int *)((intptr_t)self + 0x6c)) {
    DAT_00585580 = *(int *)((intptr_t)self + 0x50);
  }
  DAT_00585584 = *(int *)((intptr_t)self + 0xdc);
  if (*(int *)((intptr_t)self + 0xc0) <= *(int *)((intptr_t)self + 0xdc)) {
    DAT_00585584 = *(int *)((intptr_t)self + 0xc0);
  }
  DAT_0058557c = *(int *)((intptr_t)self + 0xa4);
  if (*(int *)((intptr_t)self + 0x88) <= *(int *)((intptr_t)self + 0xa4)) {
    DAT_0058557c = *(int *)((intptr_t)self + 0x88);
  }
  ExceptionList = local_c;
  return self;
}
