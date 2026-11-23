// MovieWindow_Destroy: ported from Pizza Connection 2 at 0x52b230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52b230
#include "pc2_port.h"


void __fastcall MovieWindow_Destroy(uint32_t *arg1)

{
  void *self;
  int *ptr1;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055a8a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_MovieWindow_Delete_0055c7b0;
  local_4 = 0;
  self = *(void **)(arg1[2] + 0x134);
  if ((arg1[0x29] == 1) || (arg1[0x29] == 3)) {
    UI_RemoveEffectObject(self,(intptr_t)arg1);
  }
  if (arg1[0x2b] != 0) {
    switch(arg1[0x29]) {
    case 0:
      if (*(char *)(arg1 + 0x15) == '\0') {
        if ((uint32_t *)arg1[0x25] != (uint32_t *)0x0) {
          (*(code *)**(uint32_t **)arg1[0x25])(1);
        }
      }
      else {
        UI_DecrementRowCounter(self,(uint8_t *)(arg1 + 0x15));
      }
      break;
    case 1:
      Record_Clear48((void *)arg1[0x15],arg1[0x26]);
      if ((arg1[0x2b] != 0) && ((uint32_t *)arg1[0x15] != (uint32_t *)0x0)) {
        (*(code *)**(uint32_t **)arg1[0x15])(1);
      }
      break;
    case 2:
      if ((uint32_t *)arg1[0x15] != (uint32_t *)0x0) {
        (*(code *)**(uint32_t **)arg1[0x15])(1);
      }
      break;
    case 3:
      if (*(int *)arg1[0x2e] != 0) {
        _BinkClose_4(*(int *)arg1[0x2e]);
        *(uint32_t *)arg1[0x2e] = 0;
      }
    }
  }
  if ((LPVOID)arg1[0x28] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x28]);
  }
  if (arg1[0x2e] != 0) {
    ptr1 = *(int **)(arg1[0x2e] + 4);
    if (ptr1 != (int *)0x0) {
      (**(code **)(*ptr1 + 8))(ptr1);
    }
    Mem_Free((LPVOID)arg1[0x2e]);
  }
  local_4 = 0xffffffff;
  UI_Child_Destroy(arg1);
  ExceptionList = pvStack_c;
  return;
}
