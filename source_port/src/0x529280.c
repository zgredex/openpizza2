// UI_Slider_Destroy: ported from Pizza Connection 2 at 0x529280.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x529280
#include "pc2_port.h"


void __fastcall UI_Slider_Destroy(uint32_t *arg1)

{
  void *self;
  uint8_t *bptr1;
  int value2;
  int local_14;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055a868;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_UI_Slider_Delete_0055c78c;
  local_4 = 0;
  bptr1 = (uint8_t *)(arg1 + 0x6b);
  value2 = 3;
  self = *(void **)(arg1[2] + 0x134);
  do {
    if (*(int *)(bptr1 + 0x40) != 0) {
      UI_DecrementRowCounter(self,bptr1);
    }
    if (*(int *)(bptr1 + -0x8c) != 0) {
      UI_DecrementRowCounter(self,bptr1 + -0xcc);
    }
    bptr1 = bptr1 + 0x44;
    value2 = value2 + -1;
  } while (value2 != 0);
  bptr1 = (uint8_t *)(arg1 + 0xd2);
  local_14 = 2;
  do {
    value2 = 3;
    do {
      if (*(int *)(bptr1 + 0x40) != 0) {
        UI_DecrementRowCounter(self,bptr1);
      }
      bptr1 = bptr1 + 0x44;
      value2 = value2 + -1;
    } while (value2 != 0);
    local_14 = local_14 + -1;
  } while (local_14 != 0);
  if ((uint32_t *)arg1[0xd1] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xd1])(1);
  }
  if ((LPVOID)arg1[0x2f] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x2f]);
  }
  local_4 = 0xffffffff;
  UI_Child_Destroy(arg1);
  ExceptionList = pvStack_c;
  return;
}
