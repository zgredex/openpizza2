// City_SpawnFlyerBoy: ported from Pizza Connection 2 at 0x4d54a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d54a0
#include "pc2_port.h"


void __thiscall City_SpawnFlyerBoy(void *self,int arg1)

{
  char cVar1;
  void *this_00;
  char *this_01;
  uint32_t uvalue2;
  uint32_t uvalue3;
  char *cptr4;
  char *cptr5;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Spawns a flyer-boy agent on the city map. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558f9b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0x16c);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    this_01 = (char *)0x0;
  }
  else {
    this_01 = (char *)Object_Construct(this_00,0x22,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
  }
  uvalue2 = 0xffffffff;
  cptr5 = DAT_00580b40;
  do {
    cptr4 = cptr5;
    if (uvalue2 == 0) break;
    uvalue2 = uvalue2 - 1;
    cptr4 = cptr5 + 1;
    cVar1 = *cptr5;
    cptr5 = cptr4;
  } while (cVar1 != '\0');
  uvalue2 = ~uvalue2;
  local_4 = 0xffffffff;
  cptr4 = cptr4 + -uvalue2;
  cptr5 = this_01;
  for (uvalue3 = uvalue2 >> 2; cptr5 = cptr5 + 4, uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *(uint32_t *)cptr5 = *(uint32_t *)cptr4;
    cptr4 = cptr4 + 4;
  }
  for (uvalue2 = uvalue2 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
    *cptr5 = *cptr4;
    cptr4 = cptr4 + 1;
    cptr5 = cptr5 + 1;
  }
  Game_AddObjectToRegistry(DAT_0057c670,this_01);
  Object_AttachToParent(this_01,*(void **)(arg1 + 0x16f0),0);
  *(uint32_t *)(this_01 + 0xcc) = *(uint32_t *)(arg1 + 0x16f0);
  Object_SetState(this_01,8);
  Person_WanderToLinkedCell(this_01);
  ExceptionList = local_c;
  return;
}
