// Object_Construct: ported from Pizza Connection 2 at 0x504610.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x504610
#include "pc2_port.h"


uint32_t * __thiscall
Object_Construct(void *self,uint32_t arg1,int arg2,uint32_t arg3,int arg4,
                int arg5)

{
  void *this_00;
  uint32_t uvalue1;
  int value2;
  uint32_t *uptr3;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a21c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((intptr_t)self + 0x114),0);
  local_4 = 0;
  List_Construct((void *)((intptr_t)self + 0x130),0);
  *(uint8_t ***)self = &PTR_LAB_0055c668;
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),arg2,(int *)0x0);
  if (this_00 == (void *)0x0) {
    NoOp_Stub();
  }
  *(uint8_t *)((intptr_t)self + 0x80) = 1;
  *(uint32_t *)((intptr_t)self + 0x30) = arg1;
  *(int *)((intptr_t)self + 0x28) = arg2;
  *(uint32_t *)((intptr_t)self + 0x24) = arg3;
  *(uint32_t *)((intptr_t)self + 0x50) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x7c) = 0xff;
  *(uint8_t *)((intptr_t)self + 0x81) = 0;
  *(uint32_t *)((intptr_t)self + 0x84) = 0;
  *(uint32_t *)((intptr_t)self + 0x88) = 0;
  *(uint32_t *)((intptr_t)self + 0x8c) = 0;
  *(uint32_t *)((intptr_t)self + 0x90) = 0;
  *(uint32_t *)((intptr_t)self + 0xa0) = 0;
  *(uint32_t *)((intptr_t)self + 0xa4) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0xa8) = 100;
  *(uint32_t *)((intptr_t)self + 0x110) = 0xffffffff;
  Object_SetFieldFC(self,0);
  *(uint8_t *)((intptr_t)self + 0x104) = 0;
  *(uint32_t *)((intptr_t)self + 0x100) = 0;
  *(uint32_t *)((intptr_t)self + 0x108) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x34) = 3;
  uvalue1 = Random_RangeFast(0x1e,0x32);
  *(uint32_t *)((intptr_t)self + 0x2c) = uvalue1;
  *(uint32_t *)((intptr_t)self + 0x164) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x74) = 0;
  *(uint32_t *)((intptr_t)self + 0x168) = 0;
  *(uint32_t *)((intptr_t)self + 0x38) = 2;
  if (arg4 != 0) {
    arg5 = -1;
    *(uint32_t *)((intptr_t)self + 0xc4) = *(uint32_t *)(arg4 + 0x14e0);
  }
  else {
    value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
    *(uint32_t *)((intptr_t)self + 0xc4) = *(uint32_t *)(value2 + 0xfa8);
  }
  MapObject_InitRenderRecord(self,(uint32_t)(arg4 != 0),-1,arg5);
  UI_SetChildState(self,0xffff);
  switch(arg1) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
    *(uint32_t *)((intptr_t)self + 0x34) = arg1;
    break;
  case 9:
  case 10:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x20:
    *(uint32_t *)((intptr_t)self + 0x34) = 3;
    break;
  case 0xb:
  case 0xf:
  case 0x21:
    *(uint32_t *)((intptr_t)self + 0x34) = 5;
    break;
  case 0x18:
    *(uint32_t *)((intptr_t)self + 0x34) = 3;
    UI_SetChildState(self,4);
  }
  value2 = *(int *)((intptr_t)self + 0x30);
  if ((((-1 < value2) && (value2 < 8)) || (value2 == 0xb)) || ((value2 == 0xf || (value2 == 0x21)))) {
    *(uint32_t *)((intptr_t)self + 0xa0) = 1;
  }
  value2 = Map_GetRandomBuildingOfType(this_00,0,0,'\0');
  *(int *)((intptr_t)self + 0xcc) = value2;
  *(int *)((intptr_t)self + 0xd0) = value2;
  *(uint32_t *)((intptr_t)self + 0xf4) = 0;
  *(uint32_t *)((intptr_t)self + 0xf8) = 0;
  Object_InitCompanyBuildingGraphics(self,-1);
  *(uint32_t *)((intptr_t)self + 0x3c) = 0xffffffff;
  Game_GetTimeByMode(self,0);
  *(uint16_t *)((intptr_t)self + 0x40) = 0xffff;
  *(uint32_t *)((intptr_t)self + 0x58) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x10c) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x94) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x9c) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x4c) = 0;
  *(uint32_t *)((intptr_t)self + 0x54) = 0;
  *(uint32_t *)((intptr_t)self + 0x74) = 0;
  *(uint32_t *)((intptr_t)self + 0x78) = 0;
  *(uint32_t *)((intptr_t)self + 0x98) = 0;
  uptr3 = (uint32_t *)((intptr_t)self + 0x14c);
  for (value2 = 6; value2 != 0; value2 = value2 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  uptr3 = (uint32_t *)((intptr_t)self + 0xac);
  for (value2 = 6; value2 != 0; value2 = value2 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  uptr3 = (uint32_t *)((intptr_t)self + 0x5c);
  for (value2 = 6; value2 != 0; value2 = value2 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  switch(*(uint32_t *)((intptr_t)self + 0x30)) {
  case 0xd:
    value2 = 0x11;
    break;
  default:
    goto switchD_00504872_caseD_e;
  case 0x10:
  case 0x20:
    value2 = 0x19;
    break;
  case 0x16:
  case 0x17:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    value2 = 0x17;
  }
  value2 = Map_GetRandomBuildingOfType(this_00,value2,0,'\0');
  *(int *)((intptr_t)self + 0xcc) = value2;
switchD_00504872_caseD_e:
  if (arg4 == 0) {
    value2 = Array_GetRecord28(*(void **)((intptr_t)self + 0xc4),1,
                              *(int *)(*(int *)((intptr_t)self + 0xcc) + 0x54));
    UI_SetChildTracking(self,0,value2);
    Object_SetFieldFC(self,*(uint32_t *)((intptr_t)self + 0xcc));
  }
  else {
    Object_SetFieldFC(self,*(uint32_t *)(arg4 + 0x16f0));
    *(uint32_t *)((intptr_t)self + 0x74) = 1;
    *(uint8_t *)((intptr_t)self + 0x104) = 1;
    *(uint32_t *)((intptr_t)self + 0xf4) = *(uint32_t *)(arg4 + 0x16f0);
  }
  if (*(int *)((intptr_t)self + 0x30) == 0x2e) {
    *(uint32_t *)((intptr_t)self + 0xcc) = 0;
    Object_SetFieldFC(self,0);
  }
  ExceptionList = local_c;
  return self;
}
