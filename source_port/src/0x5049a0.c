// Person_ConstructFromSave: ported from Pizza Connection 2 at 0x5049a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5049a0
#include "pc2_port.h"


uint32_t * __thiscall Person_ConstructFromSave(void *self,void *arg1)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Constructs a person record from a save stream. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a24c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((intptr_t)self + 0x114),0);
  local_4 = 0;
  List_Construct((void *)((intptr_t)self + 0x130),0);
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  *(uint8_t ***)self = &PTR_LAB_0055c668;
  *(uint32_t *)((intptr_t)self + 0x168) = 0;
  PersonAction_LoadState(self,arg1);
  ExceptionList = local_c;
  return self;
}
