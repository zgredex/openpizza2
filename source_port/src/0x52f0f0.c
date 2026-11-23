// Dialog_Destructor: ported from Pizza Connection 2 at 0x52f0f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f0f0
#include "pc2_port.h"


void __fastcall Dialog_Destructor(uint32_t *arg1)

{
  int value1;
  uint32_t *uptr2;
  int value3;
  int value4;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055aa6c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_Dialog_Delete_0055c808;
  local_4 = 1;
  if ((code *)arg1[0xa3] != (code *)0x0) {
    (*(code *)arg1[0xa3])(arg1[0xa4]);
  }
  UI_FreeObjectPairs((intptr_t)arg1);
  UI_Group_ClearAll((intptr_t)arg1);
  value3 = 0;
  if (0 < (intptr_t)arg1[0x3c]) {
    do {
      uptr2 = *(uint32_t **)(arg1[0x3a] + value3 * 8);
      if (uptr2 != (uint32_t *)0x0) {
        (**(code **)*uptr2)(1);
      }
      value3 = value3 + 1;
    } while (value3 < (intptr_t)arg1[0x3c]);
  }
  if ((LPVOID)arg1[0x3a] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x3a]);
  }
  if ((LPVOID)arg1[0x3b] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x3b]);
  }
  if (arg1[0x58] != 0) {
    value3 = 0;
    if (0 < (intptr_t)arg1[0x5d]) {
      value4 = 0;
      do {
        value1 = arg1[0x58] + value4;
        if (*(char *)(value1 + 0x108) == '\0') {
          if (*(uint32_t **)(value1 + 0x148) != (uint32_t *)0x0) {
            (**(code **)**(uint32_t **)(value1 + 0x148))(1);
          }
        }
        else {
          UI_DecrementRowCounter((void *)arg1[0x4d],(uint8_t *)(value1 + 0x108));
        }
        value3 = value3 + 1;
        value4 = value4 + 0x14c;
      } while (value3 < (intptr_t)arg1[0x5d]);
    }
    Mem_Free((LPVOID)arg1[0x58]);
  }
  if ((LPVOID)arg1[0x57] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x57]);
  }
  uptr2 = (uint32_t *)arg1[0x25];
  if (uptr2 != (uint32_t *)0x0) {
    if (*(char *)(arg1 + 0x15) == '\0') {
      if (uptr2 != (uint32_t *)0x0) {
        (**(code **)*uptr2)(1);
      }
    }
    else {
      UI_DecrementRowCounter((void *)arg1[0x4d],(uint8_t *)(arg1 + 0x15));
    }
  }
  if ((uint32_t *)arg1[0x4e] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x4e])(1);
  }
  if ((uint32_t *)arg1[0x14] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x14])(1);
  }
  if ((uint32_t *)arg1[0x37] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x37])(1);
  }
  if ((LPVOID)arg1[0x3e] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x3e]);
  }
  if (arg1[0x36] != 0) {
    UI_DecrementRowCounter((void *)arg1[0x4d],(uint8_t *)(arg1 + 0x26));
  }
  local_4 = local_4 & 0xffffff00;
  Array_Destroy(arg1 + 0xaa);
  local_4 = 0xffffffff;
  Array_Destroy(arg1 + 0x52);
  ExceptionList = pvStack_c;
  return;
}
