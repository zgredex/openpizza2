// MapObject_InitRenderRecord: ported from Pizza Connection 2 at 0x504e90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x504e90
#include "pc2_port.h"


void __thiscall MapObject_InitRenderRecord(void *self,int arg1,int arg2,int arg3)

{
  void *pvVar1;
  void *pvVar2;
  uint32_t uvalue3;
  int value4;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a29b;
  local_c = ExceptionList;
  if (arg2 == -1) {
    arg2 = *(int *)((intptr_t)self + 0x30);
  }
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x7c);
  local_4 = 0;
  pvVar2 = (void *)0x0;
  if (pvVar1 != (void *)0x0) {
    MessageList_Construct((uint32_t *)((intptr_t)pvVar1 + 0x14));
    pvVar2 = pvVar1;
  }
  local_4 = 0xffffffff;
  *(void **)((intptr_t)self + 200) = pvVar2;
  if (arg2 == 0x14) {
    *(uint32_t *)((intptr_t)self + 0x24) = 0;
  }
  if (*(int *)((intptr_t)self + 0xc4) != 0) {
    switch(arg2) {
    case 0xd:
    case 0x17:
      value4 = State_Is2DOr2E((intptr_t)self);
      if (value4 != 0) {
        if (*(int *)((intptr_t)self + 0x74) == 0) {
          ExceptionList = local_c;
          return;
        }
        arg2 = 0x29;
      }
      break;
    case 0x1d:
    case 0x1e:
      value4 = State_Is2DOr2E((intptr_t)self);
      if (value4 != 0) {
        if (*(int *)((intptr_t)self + 0x74) == 0) {
          ExceptionList = local_c;
          return;
        }
        arg2 = 0x2a;
      }
    }
    switch(arg2) {
    case 0x23:
      uvalue3 = Map_Get2DTableValue(DAT_0057c5cc,arg1,0,0);
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x58) = uvalue3;
      break;
    default:
      if (*(int *)((intptr_t)self + 0x30) == 0x10) {
        if (arg3 == -1) {
          NoOp_Stub();
        }
        value4 = *(int *)((intptr_t)self + 0x24);
        arg2 = arg3 + 0x25;
      }
      else {
        value4 = *(int *)((intptr_t)self + 0x24);
      }
      uvalue3 = Map_Get2DTableValue(DAT_0057c5cc,arg1,value4,arg2);
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x58) = uvalue3;
      break;
    case 0x29:
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x58) =
           *(uint32_t *)((intptr_t)DAT_0057c5cc + 0x2c3bc);
      break;
    case 0x2a:
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x58) =
           *(uint32_t *)((intptr_t)DAT_0057c5cc + 0x2c3c0);
      break;
    case 0x2b:
    case 0x2c:
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x58) =
           *(uint32_t *)((intptr_t)DAT_0057c5cc + 0x2c3c8);
      break;
    case 0x2d:
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x58) =
           *(uint32_t *)((intptr_t)DAT_0057c5cc + 0x2c3c4);
      break;
    case 0x2e:
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x58) =
           *(uint32_t *)((intptr_t)DAT_0057c5cc + 0x2c3cc);
      break;
    case 0x2f:
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x58) =
           *(uint32_t *)((intptr_t)DAT_0057c5cc + 0x2c3d0);
    }
    CS_Enter(*(int *)(DAT_0057c670 + 0x240));
    pvVar2 = *(void **)(*(int *)((intptr_t)self + 200) + 0x58);
    if (pvVar2 == (void *)0x0) {
      *(uint32_t *)((intptr_t)self + 200) = 0;
      CS_Leave(*(int *)(DAT_0057c670 + 0x240));
    }
    else {
      value4 = RecordList_FindFreeSlot(pvVar2,-1);
      **(int **)((intptr_t)self + 200) = value4;
      value4 = RecordList_FindFreeSlot(*(void **)((intptr_t)DAT_0057c5cc + 0x2c3b4),-1);
      *(int *)(*(int *)((intptr_t)self + 200) + 4) = value4;
      CS_Leave(*(int *)(DAT_0057c670 + 0x240));
      *(uint16_t *)(*(int *)((intptr_t)self + 200) + 8) = 0xffff;
      *(uint16_t *)(*(int *)((intptr_t)self + 200) + 10) = 0xffff;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x6c) = 0;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x70) = 0;
      *(uint16_t *)(*(int *)((intptr_t)self + 200) + 0x28) = 0xffff;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0xc) = 0xffffffff;
      *(uint8_t *)(*(int *)((intptr_t)self + 200) + 0x10) = 0;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x20) = 0;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x24) = 0;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x30) = 0xffffffff;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x34) = 0xffffffff;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x38) = 0xffffffff;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x3c) = 0xffffffff;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x40) = 0xffffffff;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x44) = 0xffffffff;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x48) = 0xffffffff;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x4c) = 0xffffffff;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x50) = 0xffffffff;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x54) = 0xffffffff;
      if (((*(int *)((intptr_t)self + 0x30) == 0x11) || (*(int *)((intptr_t)self + 0x30) != 0x13)) ||
         (arg1 != 1)) {
        uvalue3 = 0;
      }
      else {
        uvalue3 = 0x10;
      }
      Object_SetChildField2C(self,uvalue3);
      List_AppendNode(*(void **)((intptr_t)self + 0xc4),*(int *)((intptr_t)self + 200));
      if (arg1 == 1) {
        Record_SetDoubles48((void *)(*(int **)((intptr_t)self + 200))[0x16],**(int **)((intptr_t)self + 200),
                            -1,-1);
      }
      SetRect((LPRECT)(*(int *)((intptr_t)self + 200) + 0x5c),0xffff,0xffff,-1,-1);
      *(void **)(*(int *)((intptr_t)self + 200) + 0x74) = self;
      *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0x78) = 0;
    }
  }
  ExceptionList = local_c;
  return;
}
