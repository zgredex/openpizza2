// Player_Destroy: ported from Pizza Connection 2 at 0x50e9e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e9e0
#include "pc2_port.h"


void __fastcall Player_Destroy(uint32_t *arg1)

{
  int value1;
  uint32_t *uptr2;
  int value3;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055a37e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_Player_Delete_0055c684;
  value1 = arg1[0x28];
  value3 = 0;
  local_4 = 0;
  if (0 < value1) {
    do {
      uptr2 = (uint32_t *)IDMap_Lookup(arg1 + 0x23,value3,(int *)0x0);
      if (uptr2 != (uint32_t *)0x0) {
        (**(code **)*uptr2)(1);
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  if ((uint32_t *)arg1[0x2a] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x2a])(1);
  }
  if ((uint32_t *)arg1[0x2b] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x2b])(1);
  }
  if ((uint32_t *)arg1[1] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[1])(1);
  }
  local_4 = 0xffffffff;
  List_Node_Destroy(arg1 + 0x23);
  ExceptionList = pvStack_c;
  return;
}
