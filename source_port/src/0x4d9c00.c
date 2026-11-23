// City_SendPoliceUnits: ported from Pizza Connection 2 at 0x4d9c00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d9c00
#include "pc2_port.h"


void __thiscall
City_SendPoliceUnits
          (void *self,uint32_t arg1,void *arg2,uint32_t arg3,uint32_t arg4)

{
  char cVar1;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  char *this_00;
  int value5;
  char *cptr6;
  char *cptr7;
  int local_24;
  int local_20;
  int local_1c;
  void *local_18;
  int local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055920b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_18 = self;
  CS_Enter(*(int *)((intptr_t)DAT_0057c670 + 0x240));
  CS_Enter(*(int *)((intptr_t)DAT_0057c670 + 0x244));
  local_14 = Game_ComputeCompanyValue(self,&local_24,&local_20,&local_1c);
  value5 = 0;
  if (local_14 < 1) {
LAB_004d9d9d:
    CS_Leave(*(int *)((intptr_t)DAT_0057c670 + 0x244));
    CS_Leave(*(int *)((intptr_t)DAT_0057c670 + 0x240));
    ExceptionList = local_c;
    return;
  }
  do {
    local_10 = operator_new(0x16c);
    this_00 = (char *)0x0;
    local_4 = 0;
    if (local_10 != (void *)0x0) {
      this_00 = (char *)Object_Construct(local_10,0xd,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
    }
    uvalue3 = 0xffffffff;
    cptr7 = s_Police_0056ce08;
    do {
      cptr6 = cptr7;
      if (uvalue3 == 0) break;
      uvalue3 = uvalue3 - 1;
      cptr6 = cptr7 + 1;
      cVar1 = *cptr7;
      cptr7 = cptr6;
    } while (cVar1 != '\0');
    uvalue3 = ~uvalue3;
    cptr6 = cptr6 + -uvalue3;
    cptr7 = this_00;
    for (uvalue4 = uvalue3 >> 2; cptr7 = cptr7 + 4, uvalue4 != 0; uvalue4 = uvalue4 - 1) {
      *(uint32_t *)cptr7 = *(uint32_t *)cptr6;
      cptr6 = cptr6 + 4;
    }
    local_4 = 0xffffffff;
    for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
      *cptr7 = *cptr6;
      cptr6 = cptr6 + 1;
      cptr7 = cptr7 + 1;
    }
    *(uint32_t *)(this_00 + 0x100) = arg3;
    *(uint32_t *)(this_00 + 0x58) = arg4;
    Game_AddObjectToRegistry(DAT_0057c670,this_00);
    Object_AttachToParent(this_00,arg2,1);
    *(void **)(this_00 + 0xcc) = arg2;
    value5 = value5 + 1;
    *(int *)(this_00 + 0x98) = value5;
    Object_SetState(this_00,0x18);
    Object_SetFieldA4Locked(this_00,arg1);
    if (local_24 < 1) {
      if (local_20 < 1) {
        if (local_1c < 1) {
          NoOp_Stub();
        }
        else {
          this_00[0x10c] = '\x03';
          this_00[0x10d] = '\0';
          this_00[0x10e] = '\0';
          this_00[0x10f] = '\0';
          local_1c = local_1c + -1;
        }
      }
      else {
        this_00[0x10c] = '\x02';
        this_00[0x10d] = '\0';
        this_00[0x10e] = '\0';
        this_00[0x10f] = '\0';
        local_20 = local_20 + -1;
      }
    }
    else {
      this_00[0x10c] = '\x01';
      this_00[0x10d] = '\0';
      this_00[0x10e] = '\0';
      this_00[0x10f] = '\0';
      local_24 = local_24 + -1;
    }
    value2 = Object_GetClampedLevel((intptr_t)this_00);
    Object_GetPlayerValue(this_00,value2);
    if (local_14 <= value5) goto LAB_004d9d9d;
    self = local_18;
  } while( true );
}
