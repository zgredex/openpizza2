// Game_WindowProc: ported from Pizza Connection 2 at 0x4058d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4058d0
#include "pc2_port.h"

void __cdecl Game_WindowProc(int arg1,uint32_t arg2,int arg3,uint32_t *arg4)

{
  int value1;
  void *self;
  uint32_t uvalue2;
  int value3;
  char *pvVar4;
  uint32_t *uptr5;
  FILE *pFVar6;
  uint32_t uvalue7;
  int value8;
  int value9;
  uint16_t *uptr10;
  uint32_t unaff_EBX;
  uint32_t unaff_EBP;
  uint32_t unaff_ESI;
  uint32_t unaff_EDI;
  double fVar11;
  int value12;
  char cVar13;
  uint8_t local_13f [3];
  int in_stack_fffffec4;
  int in_stack_fffffec8;
  int in_stack_fffffed0;
  int in_stack_fffffed4;
  int local_128 [6];
  CHAR aCStack_110 [260];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557cfc;
  local_c = ExceptionList;
  cVar13 = '\x10';
  if (arg3 < -0x18608) {
    if (arg3 != -0x18609) {
      switch((intptr_t)arg3) {
      case -0x18684:
        if (DAT_0057c670 == (void *)0x0) {
          return;
        }
        uvalue7 = DAT_00581678;
        if (*(int *)(*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac) + 0xc0) != 0) {
          uvalue7 = DAT_00581798;
        }
        ExceptionList = &local_c;
        UI_ShowMessageDialog(DAT_0057c670,DAT_00582e4c,uvalue7);
        Sound_PlaySpeechStatement(DAT_0057ba0c,0x28);
        ExceptionList = local_c;
        return;
      case -0x18683:
        if (DAT_0057c670 == (void *)0x0) {
          return;
        }
        ExceptionList = &local_c;
        UI_ShowMessageDialog(DAT_0057c670,DAT_00582d68,DAT_00582e4c);
        Sound_PlaySpeechStatement(DAT_0057ba0c,0x2b);
        ExceptionList = local_c;
        return;
      default:
        return;
      case -0x1862c:
        goto switchD_0040593b_caseD_fffe79d4;
      case -0x18623:
        if (DAT_0057c670 == (void *)0x0) {
          return;
        }
        ExceptionList = &local_c;
        Game_AutoSaveTick(DAT_0057c670);
        ExceptionList = local_c;
        return;
      case -0x18622:
        ExceptionList = &local_c;
        if (DAT_0057c670 != (void *)0x0) {
          ExceptionList = &local_c;
          Game_EndOfHour(DAT_0057c670);
        }
        Sound_PlayStatusAdvisory(DAT_0057ba0c);
        ExceptionList = local_c;
        return;
      case -0x1861a:
        if (DAT_0057c670 == (void *)0x0) {
          return;
        }
        ExceptionList = &local_c;
        Game_SearchObjectsByName(DAT_0057c670,arg4);
        ExceptionList = local_c;
        return;
      case -0x18619:
        if (DAT_0057c670 == (void *)0x0) {
          return;
        }
        ExceptionList = &local_c;
        Game_OnObjectListSelection(DAT_0057c670);
        ExceptionList = local_c;
        return;
      case -0x18618:
        if (DAT_0057c670 == (void *)0x0) {
          return;
        }
        ExceptionList = &local_c;
        Game_SelectPlayer(DAT_0057c670,-1);
        ExceptionList = local_c;
        return;
      case -0x1860a:
        if (DAT_0057c670 == (void *)0x0) {
          return;
        }
        ExceptionList = &local_c;
        Game_ResumeSimulation(DAT_0057c670);
        ExceptionList = local_c;
        return;
      }
    }
    local_128[1] = 0x415;
    local_128[2] = 0x414;
    local_128[3] = 0x413;
    local_128[4] = 0x412;
    local_128[5] = 0x411;
    ExceptionList = &local_c;
    uvalue2 = Random_RangeFast(0,100);
    if ((intptr_t)uvalue2 < 0x4c) {
      ExceptionList = local_c;
      return;
    }
    if (DAT_0057c670 == (void *)0x0) {
      ExceptionList = local_c;
      return;
    }
    pvVar4 = *(void **)((intptr_t)DAT_0057c670 + 0x25c);
    if (pvVar4 == (void *)0x0) {
      ExceptionList = local_c;
      return;
    }
    uvalue2 = Random_Mod(5);
    value8 = local_128[uvalue2 + 1];
    value3 = Array_GetRecordByKeyPtr(pvVar4,value8);
    if (value3 == 0) {
      ExceptionList = local_c;
      return;
    }
    UI_SetButtonRecordVariant(pvVar4,value8,1);
    ExceptionList = local_c;
    return;
  }
  if (0x12 < arg3) {
    if (arg3 != 0x15) {
      if (arg3 == 0x17) {
        ExceptionList = &local_c;
        SetEvent(DAT_0057c0d8);
        ExceptionList = local_c;
        return;
      }
      if (arg3 != 0x20) {
        return;
      }
      if (DAT_0056b40c == 0) {
        ExceptionList = &local_c;
        Sound_SelectCurrentTrack(DAT_0057ba0c);
        ExceptionList = local_c;
        return;
      }
      return;
    }
    if (DAT_0057c670 == (void *)0x0) {
      return;
    }
    if (*(int *)((intptr_t)DAT_0057c670 + 0x290) != 5) {
      return;
    }
    if (DAT_00563870 != '\x01') {
      DAT_00563870 = 1;
      return;
    }
    pvVar4 = *(void **)((intptr_t)DAT_0057c5e0 + 0x8314);
    if (pvVar4 == (void *)0x0) {
      return;
    }
    ExceptionList = &local_c;
    value8 = UI_ResetInputHelper((intptr_t)DAT_0057c5e0);
    uptr10 = (uint16_t *)(value8 + 1U & 7);
    value8 = MapView_GetRotation((intptr_t)DAT_0057c5e0);
    UI_ApplyChildSpriteTint(DAT_0057c5e0,uptr10,value8);
    Object_GetChildOrigin(DAT_0057c5e0,(uint32_t *)(local_13f + 7),local_128 + -2);
    value3 = Sprite_TestCollision
                      (pvVar4,in_stack_fffffec8,in_stack_fffffed0,
                       *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0xa0) + 0x18));
    if (value3 == 0) {
      if (value8 == 0) {
        UI_ApplyChildSpriteTint(DAT_0057c5e0,uptr10,1);
        ExceptionList = local_c;
        return;
      }
      ExceptionList = local_c;
      return;
    }
    if (value8 == 1) {
      UI_ApplyChildSpriteTint(DAT_0057c5e0,uptr10,0);
      ExceptionList = local_c;
      return;
    }
    ExceptionList = local_c;
    return;
  }
  if (arg3 == 0x12) {
    if (DAT_0057c670 == (void *)0x0) {
      return;
    }
    if (*(int *)((intptr_t)DAT_0057c670 + 0x290) == 4) {
      if ((*(int *)((intptr_t)DAT_0057c670 + 0x2a8) != 3) && (*(int *)((intptr_t)DAT_0057c670 + 0x2d8) != 0xb)
         ) {
        return;
      }
      ExceptionList = &local_c;
      CS_Enter(*(int *)((intptr_t)DAT_0057c670 + 0x240));
      value8 = Game_ValidateObjectPlacement(DAT_0057c670,*arg4,arg4[1],0,0,-1,-1);
      if ((value8 != 0) &&
         ((Map_ScreenToGridCell
                     (*(void **)((intptr_t)DAT_0057c670 + 0x2fc),*arg4,arg4[1],local_128,
                      local_128 + -1,(int *)0x0),
          *(int *)((intptr_t)DAT_0057c670 + 0x348) != local_128[0] ||
          (*(int *)((intptr_t)DAT_0057c670 + 0x34c) != in_stack_fffffed4)))) {
        *(int *)((intptr_t)DAT_0057c670 + 0x348) = local_128[0];
        *(int *)((intptr_t)DAT_0057c670 + 0x34c) = in_stack_fffffed4;
      }
      CS_Leave(*(int *)((intptr_t)DAT_0057c670 + 0x240));
      SetEvent(DAT_0057c5ac);
      ExceptionList = local_c;
      return;
    }
    if (*(int *)((intptr_t)DAT_0057c670 + 0x290) != 5) {
      return;
    }
    ExceptionList = &local_c;
    if (*(int *)((intptr_t)DAT_0057c5e0 + 0x8314) != 0) {
      if (((intptr_t)*arg4 < 0x244) && ((intptr_t)arg4[1] < 0xb4)) {
        value8 = 0;
      }
      else {
        value8 = 1;
      }
      ExceptionList = &local_c;
      Game_SetObjectInfoWindowVisible(DAT_0057c670,value8);
    }
    pvVar4 = *(void **)((intptr_t)DAT_0057c5e0 + 0x8314);
    if (pvVar4 != (void *)0x0) {
      Object_GetChildOrigin(DAT_0057c5e0,(uint32_t *)(local_13f + 7),local_128 + -2);
      value8 = MapView_GetRotation((intptr_t)DAT_0057c5e0);
      if (*(int *)((intptr_t)DAT_0057c670 + 0x290) == 5) {
        value3 = Sprite_TestCollision
                          (pvVar4,in_stack_fffffec8,in_stack_fffffed0,
                           *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0xa0) + 0x18));
        if (value3 == 0) {
          if (value8 == 0) {
            uptr10 = (uint16_t *)UI_ResetInputHelper((intptr_t)DAT_0057c5e0);
            UI_ApplyChildSpriteTint(DAT_0057c5e0,uptr10,1);
          }
          DAT_0057c5e6 = '\0';
        }
        else {
          if (value8 == 1) {
            uptr10 = (uint16_t *)UI_ResetInputHelper((intptr_t)DAT_0057c5e0);
            UI_ApplyChildSpriteTint(DAT_0057c5e0,uptr10,0);
          }
          DAT_0057c5e6 = '\x01';
        }
      }
    }
    if (DAT_0057c5e4 == '\x01') {
      if ((intptr_t)*arg4 < 0x254) {
        ExceptionList = local_c;
        return;
      }
      UI_RefreshChildSprite(DAT_0057c5e0,0,-9999,-9999);
      DAT_0057c5e4 = 0;
      ExceptionList = local_c;
      return;
    }
    if (0x252 < (intptr_t)*arg4) {
      ExceptionList = local_c;
      return;
    }
    if (DAT_0057c5e5 == '\0') {
      UI_RefreshChildSprite(DAT_0057c5e0,1,-9999,-9999);
      DAT_0057c5e4 = 1;
      ExceptionList = local_c;
      return;
    }
    ExceptionList = local_c;
    return;
  }
  if (0xe < arg3) {
    if (arg3 != 0xf) {
      return;
    }
    value8 = 0;
    if (DAT_0057c670 == (void *)0x0) {
      return;
    }
    ExceptionList = &local_c;
    if ((*(int *)((intptr_t)DAT_0057c670 + 0x290) == 5) &&
       ((*(int *)((intptr_t)DAT_0057c670 + 0x2ac) == 2 ||
        (ExceptionList = &local_c, *(int *)((intptr_t)DAT_0057c670 + 0x2ac) == 7)))) {
      ExceptionList = &local_c;
      if ((*(void **)((intptr_t)DAT_0057c670 + 0x264) != (void *)0x0) &&
         (ExceptionList = &local_c, DAT_0057c5e6 != '\0')) {
        ExceptionList = &local_c;
        UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x264),-0x1866c,0x23,(intptr_t)arg4);
      }
    }
    if (*(int *)((intptr_t)DAT_0057c670 + 0x290) != 4) {
      ExceptionList = local_c;
      return;
    }
    if ((*(int *)((intptr_t)DAT_0057c670 + 0x2a8) != 3) && (*(int *)((intptr_t)DAT_0057c670 + 0x2d8) != 0xb))
    {
      ExceptionList = local_c;
      return;
    }
    if (*(int *)((intptr_t)DAT_0057c670 + 0x35c) != 0) {
      *(uint32_t *)((intptr_t)DAT_0057c670 + 0x35c) = 0;
      ExceptionList = local_c;
      return;
    }
    value3 = *(int *)((intptr_t)DAT_0057c670 + 0x34c);
    value1 = *(int *)((intptr_t)DAT_0057c670 + 0x348);
    value9 = Game_ValidateObjectPlacement(DAT_0057c670,value1,value3,1,1,*arg4,arg4[1]);
    if (value9 == 0) {
      ExceptionList = local_c;
      return;
    }
    pvVar4 = operator_new(0x24);
    local_4 = 0;
    if (pvVar4 != (void *)0x0) {
      value8 = ConstructionOrder_Construct
                        (pvVar4,*(uint32_t *)((intptr_t)DAT_0057c670 + 0x344),
                         *(uint32_t *)((intptr_t)DAT_0057c670 + 0x354));
    }
    local_4 = 0xffffffff;
    pvVar4 = *(void **)((intptr_t)DAT_0057c670 + 0x2fc);
    self = *(void **)((intptr_t)DAT_0057c670 + 0x9c);
    if (*(int *)((intptr_t)DAT_0057c670 + 0x2d8) != 0xb) {
      value12 = -1;
      cVar13 = '\0';
      value9 = Game_GetPlayerCity(*(int *)((intptr_t)DAT_0057c670 +
                                         *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200));
      fVar11 = Game_ComputeRecordCompanyPrice(value8,value9);
      Game_CanAfford(self,4,(float)(intptr_t)(fVar11),cVar13,value12);
    }
    Branch_EnqueueConstructionOrder(self,value8,value1,value3);
    value3 = Grid_GetCell(pvVar4,value1,value3);
    Map_SetTileFieldWithDefault(pvVar4,value3,*(int *)((intptr_t)pvVar4 + 0x68),1);
    IsoMap_MarkPlayerFootprints(pvVar4,(intptr_t)self);
    Game_CommitObjectPlacement(DAT_0057c670,(intptr_t)self,value8);
    if (*(int *)((intptr_t)DAT_0057c670 + 0x2d8) == 0xb) {
      *(uint32_t *)((intptr_t)DAT_0057c670 + 0x344) = 0xffffffff;
      *(uint32_t *)((intptr_t)pvVar4 + 0x60) = 0;
      *(int *)((intptr_t)DAT_0057c670 + 0x220) = value8;
      ExceptionList = local_c;
      return;
    }
    ExceptionList = local_c;
    return;
  }
  if (arg3 != 0xe) {
    if (arg3 == -0x18608) {
      if (DAT_0057c670 == (void *)0x0) {
        return;
      }
      ExceptionList = &local_c;
      Game_SetViewMode(DAT_0057c670,4,1);
      ExceptionList = local_c;
      return;
    }
    if (arg3 != -0x18607) {
      return;
    }
    if (DAT_0057c670 == (void *)0x0) {
      return;
    }
    ExceptionList = &local_c;
    Game_SetViewMode(DAT_0057c670,1,1);
    ExceptionList = local_c;
    return;
  }
  if ((DAT_0057c670 == (void *)0x0) || (value8 = *(int *)((intptr_t)DAT_0057c670 + 0x268), value8 == 0)) {
    ExceptionList = &local_c;
  }
  else {
    value3 = 0;
    ExceptionList = &local_c;
    (**(code **)(value8 + 0x48))(value8,arg4,0xfffe79a9,local_13f + 3);
    if (value3 != 0) {
      ExceptionList = local_c;
      return;
    }
    in_stack_fffffec4 = 0;
    arg1 = value8;
  }
  if (arg4 == (uint32_t *)(intptr_t)(char)local_13f[DAT_0057c608 + -5]) {
    if (local_13f[DAT_0057c608 + -4] == -1) {
      DAT_0057c5b4 = 1;
      DAT_0057c608 = 0;
      ExceptionList = local_c;
      return;
    }
    DAT_0057c608 = DAT_0057c608 + 1;
    ExceptionList = local_c;
    return;
  }
  if (arg1 != 0) {
    (**(code **)(arg1 + 0x48))(arg1,arg4,0xfffe79a9,local_13f + 3);
    if (in_stack_fffffec4 != 0) {
      ExceptionList = local_c;
      return;
    }
    in_stack_fffffec4 = 0;
  }
  if (DAT_0057df90 != 0) {
    (**(code **)(DAT_0057df90 + 0x48))(arg1,arg4,0xe,0);
    ExceptionList = local_c;
    return;
  }
  if (arg4 == (uint32_t *)0x10) {
    if (DAT_0057c5e0 != (void *)0x0) {
      pvVar4 = operator_new(0x11c);
      local_4 = 1;
      if (pvVar4 == (void *)0x0) {
        uptr5 = (uint32_t *)0x0;
      }
      else {
        uptr5 = Window_Construct(pvVar4,800,600,2);
      }
      local_4 = 0xffffffff;
      UI_RefreshAndCenter(DAT_0057c5e0,uptr5);
      while( true ) {
        value8 = DAT_0057c60c;
        DAT_0057c60c = DAT_0057c60c + 1;
        String_Format(aCStack_110,(uint8_t *)s_pizza_shot_d_tga_00563c20,value8);
        pFVar6 = (FILE *)CRT_Fopen(aCStack_110,&DAT_00563184);
        if (pFVar6 == (FILE *)0x0) break;
        CRT_Fclose(pFVar6);
      }
      Surface_SaveTga(DAT_0057c5c8,1,(uint32_t)aCStack_110,unaff_EDI,(char)unaff_ESI,unaff_EBP,
                      (short)unaff_EBX,0x1413,cVar13,in_stack_fffffec4,in_stack_fffffec8,
                      (uint32_t)pvVar4,(char)in_stack_fffffed0,(char)in_stack_fffffed4);
      MessageBeep(0);
      if (uptr5 != (uint32_t *)0x0) {
        (**(code **)*uptr5)(1);
      }
    }
  }
  else if ((arg4 == (uint32_t *)0x13f) && (DAT_0057c5b4 != 0)) {
    SoundSystem_Init(DAT_0057ba0c,(uint32_t)(*(char *)((intptr_t)DAT_0057ba0c + 0xfc) == '\0'));
  }
  if (DAT_0057c670 == (void *)0x0) {
    ExceptionList = local_c;
    return;
  }
  if ((intptr_t)arg4 < 0x132) {
    if (arg4 != (uint32_t *)0x131) {
      switch((intptr_t)arg4) {
      case 0x2:
        City_OpenBuildingDirectory(DAT_0057c670);
        ExceptionList = local_c;
        return;
      default:
        ExceptionList = local_c;
        return;
      case 0x6:
        Game_ShowFindPersonPrompt(DAT_0057c670);
        ExceptionList = local_c;
        return;
      case 0xb:
        if (DAT_0057c5b4 == 0) {
          ExceptionList = local_c;
          return;
        }
        UI_ShowAIStatusWindow((intptr_t)DAT_0057c670);
        ExceptionList = local_c;
        return;
      case 0xd:
        if (DAT_0057c5b4 == 0) {
          ExceptionList = local_c;
          return;
        }
        Mission_EvaluateGoals(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac),0,'\x01');
        ExceptionList = local_c;
        return;
      case 0x11:
        Game_HandleQueryEndSession();
        ExceptionList = local_c;
        return;
      case 0x20:
        goto switchD_00405dc8_caseD_20;
      case 0x67:
        if (DAT_0057c5b4 == 0) {
          ExceptionList = local_c;
          return;
        }
        MissionGoal_HandleEvent(*(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8),-1,-1,0);
        ExceptionList = local_c;
        return;
      case 0x6d:
        if (DAT_0057c5b4 == 0) {
          ExceptionList = local_c;
          return;
        }
        pvVar4 = *(void **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
        if (*(char *)((intptr_t)pvVar4 + 4) != '\0') {
          ExceptionList = local_c;
          return;
        }
        AI_InitActionPlan(pvVar4,0xffffffff,0xffffffff,-1,-1,-1,-1,-1);
        DAT_0057c5fc = DAT_0057c5fc + 1;
        if (0x23 < DAT_0057c5fc) {
          DAT_0057c5fc = 0;
        }
        value8 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
        uvalue7 = UI_Briefing_AddPinnedMessage
                          ((void *)((intptr_t)DAT_0057c670 + 0x304),0x21,1,-1,-1,0,DAT_00580d60,
                           DAT_00582e4c,unaff_EDI);
        *(uint32_t *)(value8 + 100) = uvalue7;
        *(uint8_t *)(*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8) + 4) = 1;
        ExceptionList = local_c;
        return;
      }
    }
switchD_00405f1d_caseD_133:
    value8 = *(int *)((intptr_t)DAT_0057c670 + 0x290);
    if (((value8 == 1) || (value8 == 3)) || (value8 == 2)) {
      value8 = *(int *)((intptr_t)DAT_0057c670 + 0x9c);
      if ((value8 == 0) &&
         (value8 = IDMap_Lookup((void *)(*(int *)((intptr_t)DAT_0057c670 +
                                                *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                                       0x148),0,(int *)0x0), value8 == 0)) {
        ExceptionList = local_c;
        return;
      }
      value8 = *(int *)(value8 + 0x16f0);
      if (value8 != 0) {
        *(uint32_t *)((intptr_t)DAT_0057c670 + 0x218) = 0;
        Game_SelectBuilding(value8,0);
        *(int *)((intptr_t)DAT_0057c670 + 0x218) = value8;
        Game_CenterViewOnObject(value8);
      }
    }
  }
  else {
    switch((intptr_t)arg4) {
    case 0x133:
      goto switchD_00405f1d_caseD_133;
    case 0x139:
      if ((*(int *)((intptr_t)DAT_0057c670 + 0x290) < 8) && (*(int *)((intptr_t)DAT_0057c670 + 0x290) != 1)) {
        Game_SetViewMode(DAT_0057c670,1,0);
      }
      break;
    case 0x13a:
      if (((*(int *)((intptr_t)DAT_0057c670 + 0x290) < 8) &&
          (0 < *(int *)(*(int *)((intptr_t)DAT_0057c670 + *(int *)((intptr_t)DAT_0057c670 + 0x2ec) * 4 + 0x200
                                ) + 0x15c))) && (*(int *)((intptr_t)DAT_0057c670 + 0x290) != 4)) {
        Game_SetViewMode(DAT_0057c670,4,0);
      }
      break;
    case 0x13b:
      if ((*(int *)((intptr_t)DAT_0057c670 + 0x290) < 8) && (*(int *)((intptr_t)DAT_0057c670 + 0x290) != 5)) {
        Game_SetViewMode(DAT_0057c670,5,0);
      }
      break;
    case 0x13c:
      if ((*(int *)((intptr_t)DAT_0057c670 + 0x290) < 8) && (*(int *)((intptr_t)DAT_0057c670 + 0x290) != 6)) {
        Game_SetViewMode(DAT_0057c670,6,0);
      }
      break;
    case 0x13d:
      if ((*(int *)((intptr_t)DAT_0057c670 + 0x290) < 8) && (*(int *)((intptr_t)DAT_0057c670 + 0x290) != 7)) {
        Game_SetViewMode(DAT_0057c670,7,0);
      }
      break;
    case 0x141:
      if (DAT_0057c5b4 != 0) {
        *(uint32_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 0x14) =
             (-(uint32_t)(*(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 0x14) != 0xc35) & 0xbd1) + 100;
      }
      break;
    case 0x191:
      if (DAT_0057c5b4 == 0) {
        if (*(int *)((intptr_t)DAT_0057c670 + 0x1508) == 0) {
          Game_SuspendSimulation(DAT_0057c670);
          DAT_0057c5c0 = 8;
          UI_ShowPauseDialog(DAT_00582e4c,DAT_005827e8);
        }
      }
      else if (*(int *)((intptr_t)DAT_0057c670 + 0x1508) == 0) {
        Game_SuspendSimulation(DAT_0057c670);
      }
      else {
        Game_ResumeSimulation(DAT_0057c670);
      }
    }
  }
  ExceptionList = local_c;
  return;
switchD_0040593b_caseD_fffe79d4:
  if (DAT_0057c670 == (void *)0x0) {
    return;
  }
  value8 = *(int *)((intptr_t)DAT_0057c670 + 0x288);
  if (value8 == 0) {
    return;
  }
  value3 = *(int *)((intptr_t)DAT_0057c670 + 0x290);
  if (((value3 == 1) || (value3 == 2)) || (value3 == 3)) {
    ExceptionList = &local_c;
    *(uint32_t *)((intptr_t)DAT_0057c670 + 0x218) = 0;
    Game_SelectBuilding(value8,0);
    *(int *)((intptr_t)DAT_0057c670 + 0x218) = value8;
    Game_CenterViewOnObject(value8);
    ExceptionList = local_c;
    return;
  }
  ExceptionList = &local_c;
  *(int *)((intptr_t)DAT_0057c670 + 0x218) = value8;
  Game_CenterViewOnObject(value8);
  Game_SetViewMode(DAT_0057c670,1,1);
  ExceptionList = local_c;
  return;
switchD_00405dc8_caseD_20:
  if (*(int *)((intptr_t)DAT_0057c670 + 0x290) != 4) {
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((intptr_t)DAT_0057c670 + 0x2a8) == 3) {
    Game_ClearSelectedObject(DAT_0057c670,1);
    ExceptionList = local_c;
    return;
  }
  ExceptionList = local_c;
  return;
}
