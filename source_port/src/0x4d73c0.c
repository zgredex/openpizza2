// City_Destroy: ported from Pizza Connection 2 at 0x4d73c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d73c0
#include "pc2_port.h"


void __fastcall City_Destroy(uint32_t *arg1)

{
  uint32_t *uptr1;
  LPVOID pvVar2;
  int value3;
  int value4;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_005590cc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_City_Delete_0055c500;
  local_4 = 1;
  if ((uint32_t *)arg1[0x3ea] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x3ea])(1);
  }
  value3 = 0;
  if (0 < (intptr_t)arg1[0x3f0]) {
    do {
      uptr1 = (uint32_t *)IDMap_Lookup(arg1 + 0x3eb,value3,(int *)0x0);
      if (uptr1 != (uint32_t *)0x0) {
        (**(code **)*uptr1)(1);
      }
      value3 = value3 + 1;
    } while (value3 < (intptr_t)arg1[0x3f0]);
  }
  List_Node_Reset((intptr_t)(arg1 + 0x3eb));
  value3 = arg1[0x3f7];
  value4 = 0;
  if (0 < value3) {
    do {
      pvVar2 = (LPVOID)IDMap_Lookup(arg1 + 0x3f2,value4,(int *)0x0);
      Mem_Free(pvVar2);
      value4 = value4 + 1;
    } while (value4 < value3);
  }
  List_Node_Reset((intptr_t)(arg1 + 0x3f2));
  if ((uint32_t *)arg1[0x42a] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x42a])(1);
  }
  local_4 = local_4 & 0xffffff00;
  List_Node_Destroy(arg1 + 0x3f2);
  local_4 = 0xffffffff;
  List_Node_Destroy(arg1 + 0x3eb);
  ExceptionList = pvStack_c;
  return;
}
