// Branch_HandleBuildCommand: ported from Pizza Connection 2 at 0x47f470.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47f470
#include "pc2_port.h"

void __fastcall Branch_HandleBuildCommand(void *arg1)

{
  uint32_t uvalue1;
  int value2;
  int value3;
  int unaff_ESI;
  int unaff_EDI;
  int value4;
  void *pvVar5;
  int value6;
  uint32_t *uptr7;
  
                    /* Executes a branch construction menu command. */
  uvalue1 = *(uint32_t *)((intptr_t)arg1 + 0x2c);
  Game_SetStageIfHigher(arg1,0);
  switch(uvalue1) {
  case 1:
    Branch_ClearInteriorObjects(arg1,0);
    break;
  case 2:
    CityMap_TryPlaceBuilding();
    break;
  case 3:
    value4 = *(int *)((intptr_t)DAT_0057c670 + 0x90);
    value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x30));
    Thread_IsOwner(value4);
    Branch_ClearInteriorObjects(arg1,0);
    value3 = *(int *)(value2 + 0x4c);
    uptr7 = (uint32_t *)0xffffffff;
    value2 = -1;
    value6 = -1;
    pvVar5 = (void *)0xffffffff;
    goto LAB_0047f53f;
  case 4:
    value4 = *(int *)((intptr_t)DAT_0057c670 + 0x90);
    value3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x30));
    Thread_IsOwner(value4);
    Branch_ClearInteriorObjects(arg1,0);
    uptr7 = *(uint32_t **)((intptr_t)arg1 + 0x1a30);
    value2 = *(int *)((intptr_t)arg1 + 0x1a38);
    value6 = *(int *)((intptr_t)arg1 + 0x1a34);
    pvVar5 = *(void **)((intptr_t)arg1 + 0x1a2c);
    value3 = *(int *)(value3 + 0x4c);
LAB_0047f53f:
    Customer_VisitBranch(value3,(intptr_t)arg1,pvVar5,value6,value2,uptr7,unaff_EDI,unaff_ESI);
    Thread_Init(value4);
    break;
  case 5:
    Branch_UpgradeSize(arg1);
  }
  Game_SetChildField94(arg1,0);
  if (arg1 == *(void **)((intptr_t)DAT_0057c670 + 0x9c)) {
    if (*(void **)((intptr_t)DAT_0057c670 + 0x260) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x260),-0x1860b,0x23,0);
    }
    if (*(void **)((intptr_t)DAT_0057c670 + 0x264) != (void *)0x0) {
      UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x264),-0x18606,0x23,0);
    }
  }
  return;
}
