// City_CreateExplosionEffect: ported from Pizza Connection 2 at 0x4d5160.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d5160
#include "pc2_port.h"


char * __thiscall
City_CreateExplosionEffect(void *self,uint32_t arg1,uint32_t arg2,void *arg3)

{
  char cVar1;
  char *this_00;
  uint32_t uvalue2;
  uint32_t uvalue3;
  char *cptr4;
  char *cptr5;
  int local_18;
  int local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558f3b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = operator_new(0x16c);
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    this_00 = (char *)0x0;
  }
  else {
    this_00 = (char *)Object_Construct(local_10,0x2e,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
  }
  uvalue2 = 0xffffffff;
  cptr5 = &DAT_0056cd20;
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
  cptr5 = this_00;
  for (uvalue3 = uvalue2 >> 2; cptr5 = cptr5 + 4, uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *(uint32_t *)cptr5 = *(uint32_t *)cptr4;
    cptr4 = cptr4 + 4;
  }
  for (uvalue2 = uvalue2 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
    *cptr5 = *cptr4;
    cptr4 = cptr4 + 1;
    cptr5 = cptr5 + 1;
  }
  Game_AddObjectToRegistry(DAT_0057c670,this_00);
  UI_GetCenteredRectForRecord(arg3,&local_14,&local_18);
  Object_PlaceSpriteAtCenter(this_00,0,local_14,local_18);
  Object_SetState(this_00,0x18);
  *(void **)(this_00 + 0xcc) = arg3;
  this_00[0x98] = '\x06';
  this_00[0x99] = '\0';
  this_00[0x9a] = '\0';
  this_00[0x9b] = '\0';
  *(uint32_t *)(this_00 + 0x8c) = arg1;
  ExceptionList = local_c;
  return this_00;
}
