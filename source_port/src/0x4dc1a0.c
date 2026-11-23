// City_SpawnDeliveryVehicles: ported from Pizza Connection 2 at 0x4dc1a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dc1a0
#include "pc2_port.h"


void __thiscall City_SpawnDeliveryVehicles(void *self,int arg1,void *arg2)

{
  char cVar1;
  uint32_t uvalue2;
  int value3;
  void *this_00;
  int value4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  char *this_01;
  int value7;
  char *cptr8;
  char *cptr9;
  char local_4c [64];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055922b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  value3 = Get_Field2C(arg1);
  uvalue2 = *(uint32_t *)(arg1 + 0x34);
  CS_Enter(*(int *)((intptr_t)DAT_0057c670 + 0x240));
  CS_Enter(*(int *)((intptr_t)DAT_0057c670 + 0x244));
  value7 = 0;
  if (0 < value3 + 1) {
    do {
      this_00 = operator_new(0x16c);
      this_01 = (char *)0x0;
      local_4 = 0;
      if (this_00 != (void *)0x0) {
        this_01 = (char *)Object_Construct(this_00,0xc,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
      }
      local_4 = 0xffffffff;
      value4 = Get_Subobject4(arg1);
      String_Format(local_4c,(uint8_t *)s_Sup__s_0056d03c,value4);
      uvalue5 = 0xffffffff;
      cptr9 = local_4c;
      do {
        cptr8 = cptr9;
        if (uvalue5 == 0) break;
        uvalue5 = uvalue5 - 1;
        cptr8 = cptr9 + 1;
        cVar1 = *cptr9;
        cptr9 = cptr8;
      } while (cVar1 != '\0');
      uvalue5 = ~uvalue5;
      cptr8 = cptr8 + -uvalue5;
      cptr9 = this_01;
      for (uvalue6 = uvalue5 >> 2; cptr9 = cptr9 + 4, uvalue6 != 0; uvalue6 = uvalue6 - 1) {
        *(uint32_t *)cptr9 = *(uint32_t *)cptr8;
        cptr8 = cptr8 + 4;
      }
      for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
        *cptr9 = *cptr8;
        cptr8 = cptr8 + 1;
        cptr9 = cptr9 + 1;
      }
      Game_AddObjectToRegistry(DAT_0057c670,this_01);
      Object_AttachToParent(this_01,arg2,1);
      *(void **)(this_01 + 0xcc) = arg2;
      uvalue5 = Random_RangeFast(4,7);
      *(uint32_t *)(this_01 + 0x98) = uvalue5 * value7 + 1;
      Object_SetState(this_01,0x34);
      *(uint32_t *)(this_01 + 0x100) = uvalue2;
      Object_SetChildField2C(this_01,0x10);
      Object_SetFieldA4Locked(this_01,0x18);
      value7 = value7 + 1;
    } while (value7 < value3 + 1);
  }
  CS_Leave(*(int *)((intptr_t)DAT_0057c670 + 0x244));
  CS_Leave(*(int *)((intptr_t)DAT_0057c670 + 0x240));
  ExceptionList = local_c;
  return;
}
