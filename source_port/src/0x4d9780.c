// City_GenerateRatingNews: ported from Pizza Connection 2 at 0x4d9780.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d9780
#include "pc2_port.h"


void __fastcall City_GenerateRatingNews(int arg1)

{
  int value1;
  void *pvVar2;
  int value3;
  int value4;
  void *pvVar5;
  uint32_t *uptr6;
  int value7;
  uint32_t uvalue8;
  uint32_t unaff_EDI;
  uint32_t *local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Posts news when the city's best branch or building beats a threshold. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005591f6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = Game_FindBestCompositeRatedBranch(-1);
  if (pvVar2 != (void *)0x0) {
    value3 = 0x3c - *(int *)(arg1 + 0xcc8 + *(int *)((intptr_t)pvVar2 + 0x30) * 4);
    value4 = Branch_GetCustomerGroupRating(pvVar2,-1,1);
    if (((intptr_t)(value3 + (value3 >> 0x1f & 7U)) >> 3) + 0x32 < value4) {
      value4 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)pvVar2 + 0x30));
      value3 = *(int *)((intptr_t)DAT_0057c670 + *(int *)(value4 + 0x4c) * 4 + 0x224);
      pvVar5 = operator_new(0xc);
      local_4 = 0;
      if (pvVar5 == (void *)0x0) {
        uptr6 = (uint32_t *)0x0;
      }
      else {
        uptr6 = Player_Event_StreamConstruct(pvVar5,(void *)0x0);
      }
      local_4 = 0xffffffff;
      uptr6[1] = 1;
      List_Add((void *)(value3 + 0x8c),uptr6);
      value1 = *(int *)((intptr_t)pvVar2 + 0x30);
      value7 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      if (value1 == value7) {
        MissionGoal_HandleEvent(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x13,-1,-1);
      }
      *(int *)(arg1 + 0xcf8 + *(int *)(value4 + 0x48) * 4) =
           *(int *)(arg1 + 0xcf8 + *(int *)(value4 + 0x48) * 4) + 1;
      if (*(int *)(value3 + 0x88) != 0) {
        UI_Briefing_AddMessage
                  ((void *)((intptr_t)DAT_0057c670 + 0x304),0x11,0,4,1,*(int *)((intptr_t)pvVar2 + 0x16f0),
                   DAT_00581128,DAT_005824e8,unaff_EDI);
      }
    }
  }
  pvVar2 = Game_FindBestQualityBuilding();
  if (pvVar2 != (void *)0x0) {
    value3 = 0x3c - *(int *)(arg1 + 0xcc8 + *(int *)((intptr_t)pvVar2 + 0x30) * 4);
    uvalue8 = value3 >> 0x1f & 7;
    value4 = Branch_ComputeBuildingRating(pvVar2,uvalue8,-1);
    if (((intptr_t)(value3 + uvalue8) >> 3) + 0x32 < value4) {
      value4 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)pvVar2 + 0x30));
      value3 = *(int *)((intptr_t)DAT_0057c670 + *(int *)(value4 + 0x4c) * 4 + 0x224);
      pvVar5 = operator_new(0xc);
      local_4 = 1;
      if (pvVar5 == (void *)0x0) {
        local_14 = (uint32_t *)0x0;
      }
      else {
        local_14 = Player_Event_StreamConstruct(pvVar5,(void *)0x0);
      }
      value1 = *(int *)((intptr_t)pvVar2 + 0x30);
      local_4 = 0xffffffff;
      value7 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      if (value1 == value7) {
        MissionGoal_HandleEvent(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),0x13,-1,-1);
      }
      local_14[1] = 2;
      List_Add((void *)(value3 + 0x8c),local_14);
      *(int *)(arg1 + 0xd10 + *(int *)(value4 + 0x48) * 4) =
           *(int *)(arg1 + 0xd10 + *(int *)(value4 + 0x48) * 4) + 1;
      if (*(int *)(value3 + 0x88) != 0) {
        UI_Briefing_AddMessage
                  ((void *)((intptr_t)DAT_0057c670 + 0x304),0x12,0,4,1,*(int *)((intptr_t)pvVar2 + 0x16f0),
                   DAT_00581128,DAT_005824e8,unaff_EDI);
      }
    }
  }
  ExceptionList = local_c;
  return;
}
