// UI_Manager_Destroy: ported from Pizza Connection 2 at 0x5235b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5235b0
#include "pc2_port.h"


void __fastcall UI_Manager_Destroy(uint32_t *arg1)

{
  LPVOID pvVar1;
  int value2;
  int value3;
  int *ptr4;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Destroys the global UI manager and its tables, sprites, and locks. */
  puStack_8 = &LAB_0055a6bc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_UI_Manager_ScalarDeletingDestructor_0055c778;
  local_4 = 1;
  if (arg1[0x20e7] != 0) {
    UI_DecrementRowCounter(arg1,(uint8_t *)(arg1 + 0x20d7));
  }
  UI_SetBackgroundSurfaceEnabled(arg1,0);
  if ((HWND)arg1[0x20c8] != (HWND)0x0) {
    SetWindowLongA((HWND)arg1[0x20c8],-0x15,0);
  }
  UI_ReleasePendingSprite((intptr_t)arg1);
  value2 = 0;
  if (0 < (intptr_t)arg1[0x8f]) {
    ptr4 = arg1 + 5;
    do {
      if ((uint32_t *)*ptr4 != (uint32_t *)0x0) {
        (*(code *)**(uint32_t **)*ptr4)(1);
      }
      *ptr4 = 0;
      value2 = value2 + 1;
      ptr4 = ptr4 + 1;
    } while (value2 < (intptr_t)arg1[0x8f]);
  }
  RecordArray_CompactEmpty48((intptr_t)arg1);
  value2 = 0;
  if (0 < (intptr_t)arg1[0x20bf]) {
    value3 = 0;
    do {
      if (*(int *)(arg1[0x20be] + value3 + 0x44) != 0) {
        NoOp_Stub();
      }
      value2 = value2 + 1;
      value3 = value3 + 0x48;
    } while (value2 < (intptr_t)arg1[0x20bf]);
  }
  if (arg1[0x9e] != 0) {
    arg1[0xa0] = 1;
    value2 = arg1[0x9e];
    while (value2 != 0) {
      Sleep(0x14);
      value2 = arg1[0x9e];
    }
  }
  Movie_ReleasePlayer((intptr_t)arg1);
  pvVar1 = (LPVOID)arg1[0x20c4];
  if (pvVar1 != (LPVOID)0x0) {
    RefPtr_Release((intptr_t)pvVar1);
    Mem_Free(pvVar1);
  }
  if ((uint32_t *)arg1[0x20eb] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x20eb])(1);
  }
  if ((uint32_t *)arg1[0x6f] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x6f])(1);
  }
  if ((arg1[0x70] != 0) && (value2 = Object_GetRootType(DAT_0057c5c8), value2 != 2)) {
    (**(code **)(*(int *)arg1[0x70] + 8))((int *)arg1[0x70]);
  }
  if ((uint32_t *)arg1[0x72] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x72])(1);
  }
  if ((uint32_t *)arg1[0x91] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x91])(1);
  }
  ptr4 = arg1 + 0x94;
  value2 = 8;
  do {
    if ((uint32_t *)*ptr4 != (uint32_t *)0x0) {
      (*(code *)**(uint32_t **)*ptr4)(1);
    }
    ptr4 = ptr4 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  if ((LPVOID)arg1[0x20be] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x20be]);
  }
  if ((uint32_t *)arg1[3] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[3])(1);
  }
  if ((uint32_t *)arg1[0x90] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x90])(1);
  }
  ImageCache_Clear((intptr_t)arg1);
  CloseHandle((HANDLE)arg1[0x20d5]);
  local_4 = local_4 & 0xffffff00;
  Array_Destroy(arg1 + 0x20c9);
  local_4 = 0xffffffff;
  NamedLockable_Destroy(arg1 + 0x73);
  ExceptionList = pvStack_c;
  return;
}
