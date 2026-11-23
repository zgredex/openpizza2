// UI_ImageElement_Destroy: ported from Pizza Connection 2 at 0x51f230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51f230
#include "pc2_port.h"


void __fastcall UI_ImageElement_Destroy(uint32_t *arg1)

{
  void *self;
  int value1;
  uint8_t *bptr2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055a558;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *arg1 = &PTR_UI_ImageElement_Delete_0055c704;
  local_4 = 0;
  bptr2 = (uint8_t *)(arg1 + 0x15);
  value1 = 4;
  self = *(void **)(arg1[2] + 0x134);
  do {
    if (*(int *)(bptr2 + 0x40) != 0) {
      UI_DecrementRowCounter(self,bptr2);
    }
    bptr2 = bptr2 + 0x44;
    value1 = value1 + -1;
  } while (value1 != 0);
  local_4 = 0xffffffff;
  UI_Child_Destroy(arg1);
  ExceptionList = local_c;
  return;
}
