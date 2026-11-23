// UI_BriefingList_Destroy: ported from Pizza Connection 2 at 0x54a8e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54a8e0
#include "pc2_port.h"


void __fastcall UI_BriefingList_Destroy(uint32_t *arg1)

{
  int value1;
  LPVOID pvVar2;
  int value3;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055b8bb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *arg1 = &PTR_UI_BriefingList_Delete_0055cb40;
  value1 = arg1[6];
  value3 = 0;
  local_4 = 0;
  if (0 < value1) {
    do {
      pvVar2 = (LPVOID)IDMap_Lookup(arg1 + 1,value3,(int *)0x0);
      Mem_Free(pvVar2);
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  List_Node_Reset((intptr_t)(arg1 + 1));
  local_4 = 0xffffffff;
  List_Node_Destroy(arg1 + 1);
  ExceptionList = local_c;
  return;
}
