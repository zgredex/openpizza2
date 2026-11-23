// Recipe_Destroy: ported from Pizza Connection 2 at 0x510c10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x510c10
#include "pc2_port.h"


void __fastcall Recipe_Destroy(uint32_t *arg1)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055a45b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *arg1 = &PTR_Recipe_Delete_0055c698;
  local_4 = 0;
  Object_DeleteAllInMap((intptr_t)arg1);
  Stats_FreeRecordMap((intptr_t)arg1);
  local_4 = 0xffffffff;
  List_Node_Destroy(arg1 + 0x12);
  ExceptionList = local_c;
  return;
}
