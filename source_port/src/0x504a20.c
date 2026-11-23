// UI_DestroyPanel: ported from Pizza Connection 2 at 0x504a20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x504a20
#include "pc2_port.h"


void __fastcall UI_DestroyPanel(uint32_t *arg1)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055a27c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *arg1 = &PTR_LAB_0055c668;
  local_4 = 1;
  UI_DestroyChildObject((intptr_t)arg1);
  local_4 = local_4 & 0xffffff00;
  List_Node_Destroy(arg1 + 0x4c);
  local_4 = 0xffffffff;
  List_Node_Destroy(arg1 + 0x45);
  ExceptionList = local_c;
  return;
}
