// UI_TextElement_Destroy: ported from Pizza Connection 2 at 0x52bd70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52bd70
#include "pc2_port.h"


void __fastcall UI_TextElement_Destroy(uint32_t *arg1)

{
  void *self;
  int value1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055a8e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *arg1 = &PTR_UI_TextElement_Delete_0055c7cc;
  local_4 = 0;
  self = *(void **)(arg1[2] + 0x134);
  if (arg1[0x22] != 0) {
    value1 = 0x10;
    do {
      if (self != (void *)0x0) {
        UI_ReleaseRefCount(self,*(int *)(arg1[0x22] + value1));
      }
      value1 = value1 + 4;
      *(uint32_t *)(arg1[0x22] + -4 + value1) = 0;
    } while (value1 < 0x34);
  }
  if ((LPVOID)arg1[0x1d] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x1d]);
  }
  UI_ReleaseRefCount(self,arg1[0x15]);
  local_4 = 0xffffffff;
  UI_Child_Destroy(arg1);
  ExceptionList = local_c;
  return;
}
