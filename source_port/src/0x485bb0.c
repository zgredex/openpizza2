// Game_ApplyPendingScreen: ported from Pizza Connection 2 at 0x485bb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x485bb0
#include "pc2_port.h"

void __thiscall
Game_ApplyPendingScreen
          (void *self,char *arg1,uint32_t arg2,int arg3,uint32_t arg4,char *arg5,
          uint32_t arg6,int arg7,uint32_t arg8,char *arg9,uint32_t arg10,
          int arg11,uint32_t arg12,char *arg13,uint32_t arg14,int arg15,
          uint32_t arg16,char *arg17,uint32_t arg18,int arg19,uint32_t arg20,
          uint8_t *arg21,uint32_t arg22,int arg23,uint32_t arg24,char *arg25,
          uint32_t arg26,int arg27,uint32_t arg28,uint8_t *arg29,
          uint32_t arg30,int arg31,uint32_t arg32,char *arg33,uint32_t arg34,
          int arg35,uint32_t arg36,char *arg37,uint32_t arg38,int arg39,
          uint32_t arg40,char *arg41,uint32_t arg42,int arg43,uint32_t arg44,
          char *arg45,uint32_t arg46,int arg47,uint32_t arg48,char *arg49,
          uint32_t arg50,int arg51,uint32_t arg52,char *arg53,uint32_t arg54,
          int arg55,uint32_t arg56,char *arg57,uint32_t arg58,int arg59,
          uint32_t arg60,char *arg61,uint32_t arg62,int arg63,uint32_t arg64,
          char *arg65,uint32_t arg66,int arg67,uint32_t arg68,char *arg69,
          uint32_t arg70,int arg71,uint32_t arg72,char *arg73,uint32_t arg74,
          int arg75,uint32_t arg76,char *arg77,uint32_t arg78,int arg79,
          uint32_t arg80,char *arg81,uint32_t arg82,int arg83,uint32_t arg84,
          char *arg85,uint32_t arg86,int arg87)

{
  uint32_t uvalue1;
  bool flag2;
  int value3;
  void *pvVar4;
  int value5;
  void *pvVar6;
  uint32_t *uptr7;
  char *cptr8;
  void *pvVar9;
  DWORD DVar10;
  uint32_t unaff_EBX;
  char *unaff_EBP;
  uint32_t unaff_ESI;
  int unaff_EDI;
  uint32_t unaff_retaddr;
  int aiStack_234 [128];
  int *ptr11;
  int in_stack_ffffffec;
  int in_stack_fffffff0;
  char *in_stack_fffffff4;
  uint32_t in_stack_fffffff8;
  int in_stack_fffffffc;
  int value12;
  
                    /* Applies the pending game-screen change. */
  if (*(int *)((intptr_t)self + 0x2dc) == 0) goto LAB_0048651d;
  if (*(int *)((intptr_t)self + 0x268) != 0) {
    Game_CloseSelectionDialog((intptr_t)self);
  }
  if ((*(char *)((intptr_t)self + 0x294) != '\x01') ||
     ((*(int *)((intptr_t)self + 0x2dc) != 2 && (*(int *)((intptr_t)self + 0x2dc) != 3)))) {
    CS_EnterObject((intptr_t)self + 0x2d1c);
    *(uint32_t *)((intptr_t)self + 0x2fc) = 0;
    if (*(uint32_t **)((intptr_t)self + 0x300) != (uint32_t *)0x0) {
      (**(code **)**(uint32_t **)((intptr_t)self + 0x300))(1);
      *(uint32_t *)((intptr_t)self + 0x300) = 0;
    }
    Input_LeaveLock((intptr_t)self + 0x2d1c);
    UI_DestroyWindowAt((uint32_t *)((intptr_t)self + 0x25c));
  }
  uptr7 = (uint32_t *)((intptr_t)self + 0x260);
  UI_DestroyWindowAt(uptr7);
  uvalue1 = *(uint32_t *)((intptr_t)self + 0x21c);
  UI_DestroyWindowAt((uint32_t *)((intptr_t)self + 0x264));
  *(uint32_t *)((intptr_t)self + 0x21c) = uvalue1;
  *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
  UI_ClearTransientEntries(DAT_0057c5e0,1,1);
  *(uint32_t *)((intptr_t)self + 0x2e4) = 0;
  *(uint32_t *)((intptr_t)self + 0x290) = *(uint32_t *)((intptr_t)self + 0x2dc);
  switch(*(uint32_t *)((intptr_t)self + 0x2dc)) {
  case 1:
    pvVar9 = CityMapView_CreateWindow(aiStack_234 + 0x88);
    Screen_GameView_Construct(pvVar9);
    value5 = *(int *)((intptr_t)self + 0x21c);
    *(void **)((intptr_t)self + 0x25c) = pvVar9;
    if (value5 == 0) {
      value12 = *(int *)((intptr_t)self + 0x218);
    }
    else {
      value12 = 0;
    }
    value3 = *(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x290) * 4 + 0x298);
    if ((value3 == 10) || (value3 == 3)) {
      *(uint32_t *)((intptr_t)self + 700) = *(uint32_t *)((intptr_t)self + 0x29c);
      *(uint32_t *)((intptr_t)self + 0x29c) = 1;
      *(uint32_t *)((intptr_t)self + 0x218) = 0;
      *(uint32_t *)((intptr_t)self + 0x21c) = 0;
      *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
      *(uint32_t *)((intptr_t)self + 0x220) = 0;
    }
    GameView_SetupZoomedViewport(self,pvVar9);
    value3 = IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
    Game_ShowBranchInteriorDefaultZoom(self,*(void **)(value3 + 0xfa8));
    pvVar9 = SubMenu_BuildSelectedPage(self,(int *)0x0);
    pvVar6 = UI_CreateInfoPanel(aiStack_234 + 0x89);
    SubMenu_UpdateButtonStatesVariant1(pvVar6);
    *uptr7 = pvVar6;
    Window_ShowWindowById(DAT_0057c5e0,in_stack_ffffffec);
    Window_ShowWindowById(DAT_0057c5e0,(intptr_t)pvVar9);
    Window_ShowWindowById(DAT_0057c5e0,in_stack_fffffff0);
    *(uint8_t *)((intptr_t)self + 0x294) = 1;
    if (*(int *)((intptr_t)self + 0x2e0) != 0) {
      if (value12 == 0) {
        SubMenu_SetSelection(self,0,value5,0,1);
      }
      else {
        *(uint32_t *)((intptr_t)self + 0x218) = 0;
        Game_SelectBuilding(value12,0);
      }
    }
    break;
  case 2:
    if (*(char *)((intptr_t)self + 0x294) == '\0') {
      pvVar9 = CityMapView_CreateWindow(aiStack_234 + 0x88);
      Screen_GameView_Construct(pvVar9);
      *(void **)((intptr_t)self + 0x25c) = pvVar9;
      GameView_SetupZoomedViewport(self,pvVar9);
      value5 = IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
      Game_ShowBranchInteriorDefaultZoom(self,*(void **)(value5 + 0xfa8));
    }
    *(uint32_t *)((intptr_t)self + 0x2e4) = 10;
    value5 = SubMenu_BuildGangsterPanelPage((intptr_t)self);
    pvVar9 = UI_CreateInfoPanelGangster(aiStack_234 + 0x89);
    SubMenu_UpdateButtonStatesVariant2(pvVar9);
    *uptr7 = pvVar9;
    if (*(char *)((intptr_t)self + 0x294) == '\0') {
      Window_ShowWindowById(DAT_0057c5e0,in_stack_ffffffec);
    }
    Window_ShowWindowById(DAT_0057c5e0,value5);
    goto LAB_00485f22;
  case 3:
    if (*(char *)((intptr_t)self + 0x294) == '\0') {
      pvVar9 = CityMapView_CreateWindow(aiStack_234 + 0x88);
      Screen_GameView_Construct(pvVar9);
      *(void **)((intptr_t)self + 0x25c) = pvVar9;
      GameView_SetupZoomedViewport(self,pvVar9);
      value5 = IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
      Game_ShowBranchInteriorDefaultZoom(self,*(void **)(value5 + 0xfa8));
    }
    value5 = SubMenu_BuildPolicePanelPage((intptr_t)self);
    *(uint32_t *)((intptr_t)self + 0x2e4) = 0xc;
    pvVar9 = UI_CreateInfoPanelPolice(aiStack_234 + 0x89);
    CityAdminPanel_UpdateTabButtons(pvVar9);
    *uptr7 = pvVar9;
    if (*(char *)((intptr_t)self + 0x294) == '\0') {
      Window_ShowWindowById(DAT_0057c5e0,in_stack_ffffffec);
    }
    Window_ShowWindowById(DAT_0057c5e0,value5);
LAB_00485f22:
    Window_ShowWindowById(DAT_0057c5e0,in_stack_fffffff0);
    *(uint8_t *)((intptr_t)self + 0x294) = 1;
    break;
  case 4:
    value5 = *(int *)((intptr_t)self + 0x21c);
    *(uint32_t *)((intptr_t)self + 0x218) = 0;
    *(uint32_t *)((intptr_t)self + 0x21c) = 0;
    *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
    *(uint32_t *)((intptr_t)self + 0x220) = 0;
    if ((*(int *)((intptr_t)self + 0x9c) == 0) ||
       (flag2 = Game_IsCurrentPlayer(*(int *)((intptr_t)self + 0x9c)), !flag2)) {
      pvVar6 = CityDetailView_CreateForeignCityWindow(aiStack_234 + 0x88);
      pvVar9 = pvVar6;
      Screen_BranchView_Init(pvVar6);
      *(void **)((intptr_t)self + 0x25c) = pvVar6;
      if (*(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x290) * 4 + 0x298) == 10) {
        *(uint32_t *)((intptr_t)self + 0x2c8) = *(uint32_t *)((intptr_t)self + 0x2a8);
        *(uint32_t *)((intptr_t)self + 0x2a8) = 1;
      }
      if (*(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x290) * 4 + 0x298) == 10) {
        *(uint32_t *)((intptr_t)self + 0x2c8) = *(uint32_t *)((intptr_t)self + 0x2a8);
        *(uint32_t *)((intptr_t)self + 0x2a8) = 1;
      }
      if (*(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x290) * 4 + 0x298) == 9) {
        *(uint32_t *)((intptr_t)self + 0x2c8) = *(uint32_t *)((intptr_t)self + 0x2a8);
        *(uint32_t *)((intptr_t)self + 0x2a8) = 1;
      }
      pvVar6 = (void *)SubMenu_BuildBranchInteriorPage((intptr_t)self);
      pvVar4 = UI_CreateRestaurantInfoPanel(aiStack_234 + 0x89);
      BranchScreen_UpdateTabButtons(pvVar4);
    }
    else {
      pvVar6 = CityDetailView_CreateOwnCityWindow(aiStack_234 + 0x88);
      pvVar9 = pvVar6;
      Screen_BranchDetail_Construct(pvVar6);
      *(void **)((intptr_t)self + 0x25c) = pvVar6;
      if (*(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x290) * 4 + 0x298) == 10) {
        *(uint32_t *)((intptr_t)self + 0x2c8) = *(uint32_t *)((intptr_t)self + 0x2a8);
        *(uint32_t *)((intptr_t)self + 0x2a8) = 1;
      }
      if (*(int *)((intptr_t)self + *(int *)((intptr_t)self + 0x290) * 4 + 0x298) == 10) {
        *(uint32_t *)((intptr_t)self + 0x2c8) = *(uint32_t *)((intptr_t)self + 0x2a8);
        *(uint32_t *)((intptr_t)self + 0x2a8) = 1;
      }
      pvVar6 = SubMenu_CreateBuildingPage(self);
      pvVar4 = Screen_BuildGameSidebar(aiStack_234 + 0x89);
      RestaurantInfoPanel_UpdateTabButtons(pvVar4);
    }
    *uptr7 = pvVar4;
    GameView_SetupZoomedViewport(self,pvVar9);
    Game_EnterBranchInterior(self,*(int *)((intptr_t)self + 0x9c));
    Window_ShowWindowById(DAT_0057c5e0,in_stack_ffffffec);
    Window_ShowWindowById(DAT_0057c5e0,(intptr_t)pvVar6);
    Window_ShowWindowById(DAT_0057c5e0,in_stack_fffffff0);
    *(uint8_t *)((intptr_t)self + 0x294) = 0;
    if (*(int *)((intptr_t)self + 0x2e0) != 0) {
      SubMenu_SetSelection(self,0,value5,0,1);
    }
    break;
  case 5:
    *(uint32_t *)((intptr_t)self + 0x218) = 0;
    *(uint32_t *)((intptr_t)self + 0x21c) = 0;
    *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
    *(uint32_t *)((intptr_t)self + 0x220) = 0;
    pvVar9 = Screen_BuildOfficeDesk(aiStack_234 + 0x88);
    Screen_RecipeMenu_Construct(pvVar9);
    *(void **)((intptr_t)self + 0x25c) = pvVar9;
    value5 = SubMenu_BuildRecipePanelPage((intptr_t)self);
    pvVar9 = Screen_RecipeInfoPanel(aiStack_234 + 0x89);
    RecipeKitchen_UpdateTabButtons(pvVar9);
    *uptr7 = pvVar9;
    Window_ShowWindowById(DAT_0057c5e0,in_stack_ffffffec);
    Window_ShowWindowById(DAT_0057c5e0,value5);
    goto LAB_004862a4;
  case 6:
    *(uint32_t *)((intptr_t)self + 0x218) = 0;
    *(uint32_t *)((intptr_t)self + 0x21c) = 0;
    *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
    *(uint32_t *)((intptr_t)self + 0x220) = 0;
    pvVar9 = StatisticsView_CreateWindow(aiStack_234 + 0x88);
    *(void **)((intptr_t)self + 0x25c) = pvVar9;
    pvVar6 = Statistics_InitSelectedPage(self);
    Screen_Statistics_Construct(pvVar9);
    pvVar9 = UI_CreateInfoPanelBranch(aiStack_234 + 0x89);
    UI_InfoPanelBranch_InitTabStates(pvVar9);
    *uptr7 = pvVar9;
    Window_ShowWindowById(DAT_0057c5e0,in_stack_ffffffec);
    Window_ShowWindowById(DAT_0057c5e0,(intptr_t)pvVar6);
    goto LAB_004862a4;
  case 7:
    *(uint32_t *)((intptr_t)self + 0x218) = 0;
    *(uint32_t *)((intptr_t)self + 0x21c) = 0;
    *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
    *(uint32_t *)((intptr_t)self + 0x220) = 0;
    pvVar9 = OfficeView_CreateWindow(aiStack_234 + 0x88);
    Screen_CityView_Init(pvVar9);
    *(void **)((intptr_t)self + 0x25c) = pvVar9;
    pvVar9 = SubMenu_InitSelectedPage(self);
    pvVar6 = Screen_BuildOptionsSidebar(aiStack_234 + 0x89);
    Screen_OptionsSidebar_SelectPage(pvVar6);
    *uptr7 = pvVar6;
    Window_ShowWindowById(DAT_0057c5e0,in_stack_ffffffec);
    Window_ShowWindowById(DAT_0057c5e0,(intptr_t)pvVar9);
LAB_004862a4:
    Window_ShowWindowById(DAT_0057c5e0,in_stack_fffffff0);
    *(uint8_t *)((intptr_t)self + 0x294) = 0;
    break;
  case 9:
  case 10:
    if (*(int *)((intptr_t)self + 0x1508) == 0) {
      Game_SuspendSimulation(self);
    }
    Window_HideWindowById(DAT_0057c5e0,*(int *)((intptr_t)self + 0x2dac));
    uptr7 = (uint32_t *)UI_FindWindowByID(DAT_0057c5e0,*(int *)((intptr_t)self + 0x2dac),(int *)0x0);
    Window_DestroyChild(DAT_0057c5e0,uptr7);
    cptr8 = Screen_EndResults(aiStack_234 + 0x88);
    EndResults_RefreshScreen(cptr8);
    goto LAB_00486408;
  case 0xb:
    if (*(int *)((intptr_t)self + 0x1508) == 0) {
      Game_SuspendSimulation(self);
    }
    Window_HideWindowById(DAT_0057c5e0,*(int *)((intptr_t)self + 0x2dac));
    uptr7 = (uint32_t *)UI_FindWindowByID(DAT_0057c5e0,*(int *)((intptr_t)self + 0x2dac),(int *)0x0);
    Window_DestroyChild(DAT_0057c5e0,uptr7);
    cptr8 = SubMenu_BuildEndResult(aiStack_234 + 0x88);
    EndResultGraph_Fill(cptr8);
    goto LAB_00486408;
  case 0xc:
    Window_HideWindowById(DAT_0057c5e0,*(int *)((intptr_t)self + 0x2dac));
    uptr7 = (uint32_t *)UI_FindWindowByID(DAT_0057c5e0,*(int *)((intptr_t)self + 0x2dac),(int *)0x0);
    Window_DestroyChild(DAT_0057c5e0,uptr7);
    pvVar9 = MissionFailedScreen_Create(aiStack_234 + 0x88);
    Movie_PlayGameOverMovie(pvVar9);
    Window_ShowWindowById(DAT_0057c5e0,in_stack_ffffffec);
    *(void **)((intptr_t)self + 0x25c) = pvVar9;
    if (DAT_0056b40c == 0) {
      return;
    }
    do {
      Window_ProcessMessageQueue(DAT_0057c5e0,0);
      Sleep(1);
      DVar10 = WaitForSingleObject(DAT_0057c0d8,0);
      if (DVar10 == 0) {
        return;
      }
    } while (DAT_0056b40c != 0);
    return;
  case 0x16:
    if (*(int *)((intptr_t)self + 0x1508) == 0) {
      Game_SuspendSimulation(self);
    }
    Window_HideWindowById(DAT_0057c5e0,*(int *)((intptr_t)self + 0x2dac));
    uptr7 = (uint32_t *)UI_FindWindowByID(DAT_0057c5e0,*(int *)((intptr_t)self + 0x2dac),(int *)0x0);
    Window_DestroyChild(DAT_0057c5e0,uptr7);
    if ((DAT_0057c5c0 == 2) && (9 < DAT_0057bb40)) {
      Sound_StopCurrentBuffer(DAT_0057ba0c);
      Movie_Play(0,s_won_s_bik_00568120);
      Movie_Play(0,s_credits_s_bik_00568110);
      *(uint8_t *)((intptr_t)self + 0x2d94) = 0;
      DAT_0056386c = 0x15;
      return;
    }
    ptr11 = aiStack_234 + 0x88;
    cptr8 = Screen_MissionBriefing(ptr11);
    Screen_MissionBriefing_Populate
              (cptr8,ptr11,unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX,in_stack_ffffffec,
               in_stack_fffffff0,in_stack_fffffff4,in_stack_fffffff8,in_stack_fffffffc,unaff_retaddr
               ,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,
               arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,
               arg20,arg21,arg22,arg23,arg24,arg25,arg26,arg27,arg28,
               arg29,arg30,arg31,arg32,arg33,arg34,arg35,arg36,arg37,
               arg38,arg39,arg40,arg41,arg42,arg43,arg44,arg45,arg46,
               arg47,arg48,arg49,arg50,arg51,arg52,arg53,arg54,arg55,
               arg56,arg57,arg58,arg59,arg60,arg61,arg62,arg63,arg64,
               arg65,arg66,arg67,arg68,arg69,arg70,arg71,arg72,arg73,
               arg74,arg75,arg76,arg77,arg78,arg79,arg80,arg81,arg82,
               arg83,arg84,arg85,arg86,arg87);
LAB_00486408:
    Window_ShowWindowById(DAT_0057c5e0,in_stack_ffffffec);
    *(char **)((intptr_t)self + 0x25c) = cptr8;
    break;
  case 0x19:
    DAT_0057c688 = FreePlaySubMenu_BuildLoadSavegame(aiStack_234 + 0x88);
    FreePlaySubmenu_InitSaveGamePage(DAT_0057c688);
    Window_ShowWindowById(DAT_0057c5e0,in_stack_ffffffec);
    *(void **)((intptr_t)self + 0x25c) = DAT_0057c688;
    break;
  case 0x1d:
    *(uint8_t *)((intptr_t)self + 0x2d94) = 0;
  }
  *(uint32_t *)((intptr_t)self + 0x2dc) = 0;
  UI_RemoveWindowByID(DAT_0057c5e0,*(int *)((intptr_t)self + 0x2dac));
LAB_0048651d:
  *(uint32_t *)((intptr_t)self + 0x2e0) = 0;
  return;
}
