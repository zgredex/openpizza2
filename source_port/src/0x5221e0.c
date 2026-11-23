// UI_LabelElement_Destroy: ported from Pizza Connection 2 at 0x5221e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5221e0
#include "pc2_port.h"


void __fastcall UI_LabelElement_Destroy(uint32_t *arg1)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055a628;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *arg1 = &PTR_UI_LabelElement_Delete_0055c758;
  local_4 = 0;
  UI_ClearField230(*(void **)(arg1[2] + 0x134),(intptr_t)arg1);
  Mem_Free((LPVOID)arg1[0x1b]);
  Mem_Free((LPVOID)arg1[0x1c]);
  local_4 = 0xffffffff;
  UI_Child_Destroy(arg1);
  ExceptionList = local_c;
  return;
}
