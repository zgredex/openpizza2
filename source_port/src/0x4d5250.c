// Branch_HireExterminator: ported from Pizza Connection 2 at 0x4d5250.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d5250
#include "pc2_port.h"


bool __thiscall Branch_HireExterminator(void *self,int arg1,void *arg2)

{
  char cVar1;
  void *this_00;
  char *this_01;
  uint32_t uvalue2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  char *cptr5;
  char *cptr6;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Creates and charges an exterminator service object. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558f5b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0x16c);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    this_01 = (char *)0x0;
  }
  else {
    this_01 = (char *)Object_Construct(this_00,0x20,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
  }
  uvalue3 = 0xffffffff;
  cptr6 = DAT_00580af8;
  do {
    cptr5 = cptr6;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cptr5 = cptr6 + 1;
    cVar1 = *cptr6;
    cptr6 = cptr5;
  } while (cVar1 != '\0');
  uvalue3 = ~uvalue3;
  local_4 = 0xffffffff;
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
  Object_SetDestinationAndTarget(this_01,1,*(int *)((intptr_t)arg2 + 0x16f0));
  Object_SetFieldA4Locked(this_01,arg1);
  if (arg1 == 1) {
    Game_CanAfford(arg2,5,1000.0,'\0',-1);
    ExceptionList = local_c;
    return true;
  }
  uvalue2 = Game_CanAfford(arg2,5,10000.0,'\x01',-1);
  ExceptionList = local_c;
  return (char)uvalue2 != '\0';
}
