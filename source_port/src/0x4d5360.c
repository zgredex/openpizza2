// City_SpawnPersonAtRandomCell: ported from Pizza Connection 2 at 0x4d5360.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d5360
#include "pc2_port.h"


void __thiscall City_SpawnPersonAtRandomCell(void *self,int arg1)

{
  char cVar1;
  void *this_00;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  char *this_01;
  char *cptr5;
  char *cptr6;
  char local_4c [64];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Creates and places a person object on a random city cell. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558f7b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CS_Enter(*(int *)((intptr_t)DAT_0057c670 + 0x240));
  CS_Enter(*(int *)((intptr_t)DAT_0057c670 + 0x244));
  this_00 = operator_new(0x16c);
  this_01 = (char *)0x0;
  local_4 = 0;
  if (this_00 != (void *)0x0) {
    this_01 = (char *)Object_Construct(this_00,0xe,*(int *)((intptr_t)self + 0xc1c),0,arg1,-1);
  }
  local_4 = 0xffffffff;
  String_Format(local_4c,(uint8_t *)s__s__s_00563314,DAT_00580dfc);
  uvalue3 = 0xffffffff;
  cptr6 = local_4c;
  do {
    cptr5 = cptr6;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cptr5 = cptr6 + 1;
    cVar1 = *cptr6;
    cptr6 = cptr5;
  } while (cVar1 != '\0');
  uvalue3 = ~uvalue3;
  cptr5 = cptr5 + -uvalue3;
  cptr6 = this_01;
  for (uvalue4 = uvalue3 >> 2; cptr6 = cptr6 + 4, uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *(uint32_t *)cptr6 = *(uint32_t *)cptr5;
    cptr5 = cptr5 + 4;
  }
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *cptr6 = *cptr5;
    cptr5 = cptr5 + 1;
    cptr6 = cptr6 + 1;
  }
  Game_AddObjectToRegistry(DAT_0057c670,this_01);
  Game_AddObjectToList(*(void **)(arg1 + 0x16f0),this_01);
  value2 = Grid_GetRandomRecord28(*(int *)(arg1 + 0x14e0));
  UI_SetChildTracking(this_01,1,value2);
  Object_SetState(this_01,5);
  UI_SetChildRecordVariant(this_01,0xc);
  UI_DetachChildRecord((intptr_t)this_01);
  CS_Leave(*(int *)((intptr_t)DAT_0057c670 + 0x244));
  CS_Leave(*(int *)((intptr_t)DAT_0057c670 + 0x240));
  ExceptionList = local_c;
  return;
}
