// City_CreateBranchObject: ported from Pizza Connection 2 at 0x4d50a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d50a0
#include "pc2_port.h"


char * __thiscall City_CreateBranchObject(void *self,uint32_t arg1,int arg2)

{
  char cVar1;
  void *this_00;
  char *cptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  char *cptr5;
  char *cptr6;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558f1b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0x16c);
  cptr5 = (char *)0x0;
  local_4 = 0;
  if (this_00 != (void *)0x0) {
    cptr5 = (char *)Object_Construct(this_00,arg1,*(int *)((intptr_t)self + 0xc1c),0,arg2,-1);
  }
  local_4 = 0xffffffff;
  cptr2 = Game_GetDataByIndex(arg1);
  uvalue3 = 0xffffffff;
  do {
    cptr6 = cptr2;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cptr6 = cptr2 + 1;
    cVar1 = *cptr2;
    cptr2 = cptr6;
  } while (cVar1 != '\0');
  uvalue3 = ~uvalue3;
  cptr6 = cptr6 + -uvalue3;
  cptr2 = cptr5;
  for (uvalue4 = uvalue3 >> 2; cptr2 = cptr2 + 4, uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *(uint32_t *)cptr2 = *(uint32_t *)cptr6;
    cptr6 = cptr6 + 4;
  }
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *cptr2 = *cptr6;
    cptr6 = cptr6 + 1;
    cptr2 = cptr2 + 1;
  }
  Game_AddObjectToRegistry(DAT_0057c670,cptr5);
  Game_AddObjectToList(*(void **)(arg2 + 0x16f0),cptr5);
  ExceptionList = local_c;
  return cptr5;
}
