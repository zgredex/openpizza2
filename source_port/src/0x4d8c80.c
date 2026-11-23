// City_CreateObjectsOfType: ported from Pizza Connection 2 at 0x4d8c80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d8c80
#include "pc2_port.h"


uint32_t * __thiscall
City_CreateObjectsOfType(void *self,uint32_t *arg1,uint32_t arg2,int arg3)

{
  void *this_00;
  uint32_t *uptr1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055918b;
  local_c = ExceptionList;
  if (0 < (intptr_t)arg1) {
    ExceptionList = &local_c;
    do {
      this_00 = operator_new(0x16c);
      uptr1 = (uint32_t *)0x0;
      local_4 = 0;
      if (this_00 != (void *)0x0) {
        uptr1 = Object_Construct(this_00,arg2,*(int *)((intptr_t)self + 0xc1c),arg3,0,-1);
      }
      local_4 = 0xffffffff;
      IDMap_GetRandomName(DAT_0057ba10,arg3,(char *)(uptr1 + 1));
      Game_AddObjectToRegistry(DAT_0057c670,uptr1);
      arg1 = (uint32_t *)((intptr_t)arg1 + -1);
    } while (arg1 != (uint32_t *)0x0);
    arg1 = uptr1;
  }
  ExceptionList = local_c;
  return arg1;
}
