// GameState_Destruct: ported from Pizza Connection 2 at 0x488e20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x488e20
#include "pc2_port.h"

void __fastcall GameState_Destruct(uint32_t *arg1)

{
  uint32_t *uptr1;
  int value2;
  int *ptr3;
  int value4;
  void *pvStack_c;
  uint8_t *puStack_8;
  int local_4;
  
                    /* Destroys the global game-state object and its maps. */
  puStack_8 = &LAB_00558333;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_GameWorld_Delete_0055c44c;
  local_4 = 6;
  Game_SuspendSimulation(arg1);
  UI_ResetScrollPosition((intptr_t)DAT_0057c5e0);
  if ((uint32_t *)arg1[0x24] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x24])(1);
  }
  arg1[0x24] = 0;
  if ((uint32_t *)arg1[0x25] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x25])(1);
  }
  arg1[0x25] = 0;
  if ((uint32_t *)arg1[0x24] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x24])(1);
  }
  arg1[0x24] = 0;
  if (DAT_0058072c != (uint32_t *)0x0) {
    (**(code **)*DAT_0058072c)(1);
    DAT_0058072c = (uint32_t *)0x0;
  }
  uptr1 = (uint32_t *)UI_FindWindowByID(DAT_0057c5e0,arg1[0xb6b],(int *)0x0);
  Window_DestroyChild(DAT_0057c5e0,uptr1);
  if ((uint32_t *)arg1[0x29] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x29])(1);
  }
  if ((uint32_t *)arg1[0x28] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x28])(1);
  }
  uptr1 = (uint32_t *)arg1[0xb67];
  if (uptr1 != (uint32_t *)0x0) {
    UI_RemoveAllBriefings(uptr1);
    Mem_Free(uptr1);
  }
  Game_DestroyEventWindow((intptr_t)arg1);
  Game_ShutdownWorld((intptr_t)arg1);
  ptr3 = arg1 + 0x2a;
  value2 = 0x56;
  do {
    if ((uint32_t *)*ptr3 != (uint32_t *)0x0) {
      (*(code *)**(uint32_t **)*ptr3)(1);
      *ptr3 = 0;
    }
    ptr3 = ptr3 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  value2 = arg1[0x22];
  value4 = 0;
  if (0 < value2) {
    do {
      uptr1 = (uint32_t *)IDMap_Lookup(arg1 + 0x1d,value4,(int *)0x0);
      if (uptr1 != (uint32_t *)0x0) {
        (**(code **)*uptr1)(1);
      }
      value4 = value4 + 1;
    } while (value4 < value2);
  }
  List_Node_Reset((intptr_t)(arg1 + 0x1d));
  if ((uint32_t *)arg1[0x8f] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x8f])(1);
  }
  if ((uint32_t *)arg1[0x90] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x90])(1);
  }
  if ((uint32_t *)arg1[0x91] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x91])(1);
  }
  if ((uint32_t *)arg1[0x92] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x92])(1);
  }
  if (arg1[0xa4] != 0x1d) {
    DAT_0057bb54 = (DAT_0057bb54 & ~(0x0u << 8)) | (((0) & 0x0u) << 8);
  }
  local_4 = (local_4 & ~(0x0u << 8)) | (((5) & 0x0u) << 8);
  Timer_Destroy(arg1 + 0xb47);
  local_4 = (local_4 & ~(0x0u << 8)) | (((4) & 0x0u) << 8);
  UI_BriefingList_Destroy(arg1 + 0xc1);
  local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x1d);
  local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x16);
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0xf);
  local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
  List_Node_Destroy(arg1 + 8);
  local_4 = 0xffffffff;
  List_Node_Destroy(arg1 + 1);
  ExceptionList = pvStack_c;
  return;
}
