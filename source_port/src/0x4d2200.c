// MapObject_Destroy: ported from Pizza Connection 2 at 0x4d2200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2200
#include "pc2_port.h"


void __fastcall MapObject_Destroy(uint32_t *arg1)

{
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_00558d56;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_MapObject_Delete_0055c4ec;
  local_4 = 1;
  if ((arg1[1] == 0x1b) && ((uint32_t *)arg1[0x1d] != (uint32_t *)0x0)) {
    (*(code *)**(uint32_t **)arg1[0x1d])(1);
    arg1[0x1d] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  List_Node_Destroy(arg1 + 0x1e);
  local_4 = 0xffffffff;
  List_Node_Destroy(arg1 + 0x16);
  ExceptionList = pvStack_c;
  return;
}
