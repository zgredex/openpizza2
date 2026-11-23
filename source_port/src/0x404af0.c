// Game_RunSession: ported from Pizza Connection 2 at 0x404af0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x404af0
#include "pc2_port.h"

/* WARNING: Type propagation algorithm not settling */

void Game_RunSession(void)

{
  char cVar1;
  DWORD DVar2;
  uint32_t *uptr3;
  int *self;
  HCURSOR pHVar4;
  void *this_00;
  char *cptr5;
  int value6;
  uint32_t uvalue7;
  uint32_t uvalue8;
  char *cptr9;
  uint32_t unaff_EBX;
  char *cptr10;
  int unaff_EBP;
  uint32_t unaff_ESI;
  char *unaff_EDI;
  bool flag11;
  int64_t lvalue12;
  uint32_t auStackY_397 [128];
  char *cptr13;
  char *cptr14;
  char *cptr15;
  char *cptr16;
  char *cptr17;
  char *cptr18;
  int value19;
  char *cptr20;
  uint32_t in_stack_fffffeb4;
  int value21;
  HANDLE pvVar22;
  uint32_t uvalue23;
  char *cptr24;
  uint32_t in_stack_fffffec4;
  uint32_t uvalue25;
  int in_stack_fffffec8;
  uint32_t in_stack_fffffecc;
  uint8_t *in_stack_fffffed0;
  uint32_t in_stack_fffffed4;
  int in_stack_fffffed8;
  uint32_t in_stack_fffffedc;
  char *in_stack_fffffee0;
  uint32_t in_stack_fffffee4;
  int in_stack_fffffee8;
  uint32_t in_stack_fffffeec;
  uint8_t *in_stack_fffffef0;
  uint32_t in_stack_fffffef4;
  int in_stack_fffffef8;
  uint32_t in_stack_fffffefc;
  char *in_stack_ffffff00;
  uint32_t in_stack_ffffff04;
  int in_stack_ffffff08;
  uint32_t in_stack_ffffff0c;
  char *in_stack_ffffff10;
  uint32_t in_stack_ffffff14;
  int in_stack_ffffff18;
  uint32_t in_stack_ffffff1c;
  char *in_stack_ffffff20;
  uint32_t in_stack_ffffff24;
  int in_stack_ffffff28;
  uint32_t in_stack_ffffff2c;
  char *in_stack_ffffff30;
  uint32_t in_stack_ffffff34;
  int in_stack_ffffff38;
  uint32_t in_stack_ffffff3c;
  char *in_stack_ffffff40;
  uint32_t in_stack_ffffff44;
  int in_stack_ffffff48;
  uint32_t in_stack_ffffff4c;
  char *in_stack_ffffff50;
  uint32_t in_stack_ffffff54;
  int in_stack_ffffff58;
  uint32_t in_stack_ffffff5c;
  char *in_stack_ffffff60;
  uint32_t in_stack_ffffff64;
  int in_stack_ffffff68;
  uint32_t in_stack_ffffff6c;
  char *in_stack_ffffff70;
  uint32_t in_stack_ffffff74;
  int in_stack_ffffff78;
  uint32_t in_stack_ffffff7c;
  char *in_stack_ffffff80;
  uint32_t in_stack_ffffff84;
  int in_stack_ffffff88;
  uint32_t in_stack_ffffff8c;
  char *in_stack_ffffff90;
  uint32_t in_stack_ffffff94;
  int in_stack_ffffff98;
  uint32_t in_stack_ffffff9c;
  char *in_stack_ffffffa0;
  uint32_t in_stack_ffffffa4;
  int in_stack_ffffffa8;
  uint32_t in_stack_ffffffac;
  char *in_stack_ffffffb0;
  uint32_t in_stack_ffffffb4;
  int in_stack_ffffffb8;
  uint32_t in_stack_ffffffbc;
  char *in_stack_ffffffc0;
  uint32_t in_stack_ffffffc4;
  int in_stack_ffffffc8;
  uint32_t in_stack_ffffffcc;
  char *in_stack_ffffffd0;
  uint32_t in_stack_ffffffd4;
  int in_stack_ffffffd8;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Allocates, initializes, and runs the game session loop. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557ccc;
  pvStack_c = ExceptionList;
  uvalue25 = CONCAT31((int3)((uint32_t)in_stack_fffffec4 >> 8),DAT_00579aec);
  uptr3 = auStackY_397 + 0x97;
  for (value6 = 0xf; value6 != 0; value6 = value6 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  *(uint16_t *)uptr3 = 0;
  *(uint8_t *)((intptr_t)uptr3 + 2) = 0;
  value6 = 0;
  value19 = 0;
  cptr15 = (char *)0x0;
  cptr20 = (char *)0x0;
  cptr17 = (char *)0x1;
  cptr14 = (char *)0x0;
  cptr18 = (char *)0x0;
  value21 = 0;
  cptr24 = (char *)0x0;
  ExceptionList = &pvStack_c;
  UI_ShowLoadingOverlay(1);
  DVar2 = timeGetTime();
  cptr10 = (char *)(DVar2 + 1000);
  cptr13 = cptr10;
  Window_GadgetNotify_Slider_SetValue(DAT_0057c5f4,0x3f7,5,0);
  Window_ProcessMessageQueue(DAT_0057c5e0,0);
  uptr3 = operator_new(0x2e28);
  local_4 = 0;
  if (uptr3 == (uint32_t *)0x0) {
    DAT_0057c670 = (uint32_t *)0x0;
  }
  else {
    DAT_0057c670 = GameSession_Construct(uptr3);
  }
  local_4 = 0xffffffff;
  Window_GadgetNotify_Slider_SetValue(DAT_0057c5f4,0x3f7,0xf,0);
  Window_ProcessMessageQueue(DAT_0057c5e0,0);
  if ((char)DAT_0057bb54 == '\0') {
    if ((0 < DAT_0057bb40) && (DAT_0057bb20 == '\0')) {
      Game_SetGlobalWord16((void *)DAT_0057c670[0x25],(short)DAT_0057c24c + 1);
    }
  }
  else {
    uptr3 = operator_new(0x5c);
    local_4 = 1;
    if (uptr3 == (uint32_t *)0x0) {
      self = (int *)0x0;
    }
    else {
      self = CRT_Ifstream_Construct();
    }
    local_4 = 0xffffffff;
    if (*(int *)(*(int *)(*(int *)(*self + 4) + 4 + (intptr_t)self) + 0x4c) == -1) {
      if (self != (int *)0x0) {
        (*(code *)**(uint32_t **)(*(int *)(*self + 4) + (intptr_t)self))(1);
      }
    }
    else {
      pHVar4 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
      SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar4);
      PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar4);
      CRT_Istream_Read(self,(intptr_t)register0x00000010 + -0xfc,0xf0);
      Game_SuspendSimulation(DAT_0057c670);
      Game_AcquireStateLock(DAT_0057c670,0);
      CS_Enter(DAT_0057c670[0x90]);
      uptr3 = (uint32_t *)
               Game_LoadSaveGame(DAT_0057c670,self,(uint32_t *)((intptr_t)auStackY_397 + 0x24b));
      CS_Leave(DAT_0057c670[0x90]);
      cptr10 = cptr13;
      if (self != (int *)0x0) {
        (*(code *)**(uint32_t **)((intptr_t)self + *(int *)(*self + 4)))(1);
        cptr10 = cptr13;
      }
      pHVar4 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
      SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar4);
      PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar4);
      if (uptr3 == (uint32_t *)0x0) {
        UI_MessageBoxf(DAT_0057c5e0,(uint8_t *)s_Invalid_savegame___Errorpos__s_00563b98,
                       in_stack_fffffeb4);
        Window_UnlockState((intptr_t)DAT_0057c670);
        if (DAT_0057c670[0xb89] != 0) {
          SetEvent(DAT_0057c0d8);
        }
        DAT_0057bb54 = (DAT_0057bb54 & ~(0x0u << 8)) | ((('\0') & 0x0u) << 8);
        cptr13 = cptr10;
      }
      else {
        Window_UnlockState((intptr_t)DAT_0057c670);
        Game_SetViewMode(DAT_0057c670,1,0);
        uvalue7 = 0xffffffff;
        cptr13 = s_geladen_00563b90;
        do {
          cptr16 = cptr13;
          if (uvalue7 == 0) break;
          uvalue7 = uvalue7 - 1;
          cptr16 = cptr13 + 1;
          cVar1 = *cptr13;
          cptr13 = cptr16;
        } while (cVar1 != '\0');
        uvalue7 = ~uvalue7;
        cptr16 = cptr16 + -uvalue7;
        cptr9 = (char *)&DAT_0057bb54;
        for (uvalue8 = uvalue7 >> 2; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
          *(uint32_t *)cptr9 = *(uint32_t *)cptr16;
          cptr16 = cptr16 + 4;
          cptr9 = cptr9 + 4;
        }
        for (uvalue7 = uvalue7 & 3; cptr13 = cptr10, uvalue7 != 0; uvalue7 = uvalue7 - 1) {
          *cptr9 = *cptr16;
          cptr16 = cptr16 + 1;
          cptr9 = cptr9 + 1;
        }
      }
    }
  }
  Game_InitScenario(DAT_0057c670,unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX,cptr13,cptr14,
                    (intptr_t)cptr15,value6,cptr17,uptr3,(intptr_t)cptr18,value19,cptr20,in_stack_fffffeb4,
                    value21);
  UI_CloseLoadingScreen();
  cptr13 = (char *)0x1;
  this_00 = (void *)UI_LoadFontByName(DAT_0057c5e0,s_default_font_00563b80);
  cVar1 = *(char *)(DAT_0057c670 + 0xb65);
  pvVar22 = DAT_0057c0d8;
  uvalue23 = DAT_0057c5ac;
  while ((cVar1 != '\0' &&
         (DVar2 = WaitForMultipleObjects(2,(HANDLE *)((intptr_t)auStackY_397 + 0x24f),0,0x14), DVar2 != 0
         ))) {
    cptr16 = cptr15;
    if (DAT_0057c5e0 != (void *)0x0) {
      Game_ApplyPendingScreen
                (DAT_0057c670,unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX,cptr13,cptr14,(intptr_t)cptr15,
                 value6,cptr17,uptr3,(intptr_t)cptr18,value19,cptr20,in_stack_fffffeb4,(intptr_t)pvVar22,
                 uvalue23,cptr24,uvalue25,in_stack_fffffec8,in_stack_fffffecc,in_stack_fffffed0,
                 in_stack_fffffed4,in_stack_fffffed8,in_stack_fffffedc,in_stack_fffffee0,
                 in_stack_fffffee4,in_stack_fffffee8,in_stack_fffffeec,in_stack_fffffef0,
                 in_stack_fffffef4,in_stack_fffffef8,in_stack_fffffefc,in_stack_ffffff00,
                 in_stack_ffffff04,in_stack_ffffff08,in_stack_ffffff0c,in_stack_ffffff10,
                 in_stack_ffffff14,in_stack_ffffff18,in_stack_ffffff1c,in_stack_ffffff20,
                 in_stack_ffffff24,in_stack_ffffff28,in_stack_ffffff2c,in_stack_ffffff30,
                 in_stack_ffffff34,in_stack_ffffff38,in_stack_ffffff3c,in_stack_ffffff40,
                 in_stack_ffffff44,in_stack_ffffff48,in_stack_ffffff4c,in_stack_ffffff50,
                 in_stack_ffffff54,in_stack_ffffff58,in_stack_ffffff5c,in_stack_ffffff60,
                 in_stack_ffffff64,in_stack_ffffff68,in_stack_ffffff6c,in_stack_ffffff70,
                 in_stack_ffffff74,in_stack_ffffff78,in_stack_ffffff7c,in_stack_ffffff80,
                 in_stack_ffffff84,in_stack_ffffff88,in_stack_ffffff8c,in_stack_ffffff90,
                 in_stack_ffffff94,in_stack_ffffff98,in_stack_ffffff9c,in_stack_ffffffa0,
                 in_stack_ffffffa4,in_stack_ffffffa8,in_stack_ffffffac,in_stack_ffffffb0,
                 in_stack_ffffffb4,in_stack_ffffffb8,in_stack_ffffffbc,in_stack_ffffffc0,
                 in_stack_ffffffc4,in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0,
                 in_stack_ffffffd4,in_stack_ffffffd8);
      if (DAT_0057c670[0x93] == 0) {
        CS_Enter(DAT_0057c670[0x8f]);
        DAT_0057c670[0x93] = 1;
        CS_Leave(DAT_0057c670[0x8f]);
      }
      lvalue12 = Window_ProcessMessageQueue(DAT_0057c5e0,1);
      cptr9 = (char *)lvalue12;
      DAT_0057c670[0x93] = 0;
      flag11 = cptr13 != (char *)0x0;
      cptr13 = (char *)0x0;
      if (flag11) {
        cptr13 = (char *)0x0;
        Game_ResumeSimulation(DAT_0057c670);
        Window_ShowWindowById(DAT_0057c5e0,DAT_0057c670[0xb6b]);
      }
      if (DAT_0057c5e8 != 0) {
        if ((cptr9 == (char *)0x0) && (cptr17 == (char *)0x0)) {
          value21 = Object_GetRootType((intptr_t)DAT_0057c5c8);
          if ((value21 == 0) && (this_00 != (void *)0x0)) {
            Surface_LockPrimary(DAT_0057c5c8);
            Text_SetMetrics(this_00,10,0x10,0);
            Set_Field9B8(this_00,0xffffff);
            Font_DrawTextLine(this_00,DAT_0057c5c8,(intptr_t)auStackY_397 + 0x25b);
            Surface_Unlock((intptr_t)DAT_0057c5c8);
          }
        }
        else {
          if (cptr15 < cptr9) {
            cptr15 = cptr9;
          }
          String_Format((uint8_t *)((intptr_t)auStackY_397 + 0x25b),
                        (uint8_t *)s_fps__d_max__d_d__d_00563b6c,value19);
          value21 = Object_GetRootType((intptr_t)DAT_0057c5c8);
          if ((value21 == 0) && (this_00 != (void *)0x0)) {
            Surface_LockPrimary(DAT_0057c5c8);
            Text_SetMetrics(this_00,10,0x10,0);
            Set_Field9B8(this_00,0xffffff);
            Font_DrawTextLine(this_00,DAT_0057c5c8,(intptr_t)auStackY_397 + 0x25b);
            Surface_Unlock((intptr_t)DAT_0057c5c8);
          }
          cptr17 = (char *)0x0;
        }
      }
      value21 = value6 + 1;
      cptr9 = cptr14 + (intptr_t)cptr9;
      cptr5 = (char *)timeGetTime();
      cptr14 = cptr9;
      cptr16 = cptr15;
      value6 = value21;
      if (cptr10 <= cptr5) {
        cptr10 = cptr10 + 1000;
        cptr16 = (char *)0x0;
        value6 = 0;
        cptr14 = (char *)0x0;
        cptr17 = (char *)0x1;
        cptr18 = cptr9;
        value19 = value21;
        cptr20 = cptr15;
      }
    }
    cVar1 = *(char *)(DAT_0057c670 + 0xb65);
    cptr15 = cptr16;
  }
  DAT_0056b40c = 1;
  SoundBuffer_Release(DAT_0057ba0c);
  Game_RemoveScreenTimers((intptr_t)DAT_0057c670);
  UI_ReleaseRefCount(DAT_0057c5e0,(intptr_t)this_00);
  Game_DestroyCachedScreens(DAT_0057c670,-1);
  Game_DestroyEventWindow((intptr_t)DAT_0057c670);
  if (DAT_0057c670 != (uint32_t *)0x0) {
    (**(code **)*DAT_0057c670)(1);
  }
  DAT_0057c670 = (uint32_t *)0x0;
  DAT_0056b40c = 0;
  ExceptionList = pvStack_c;
  return;
}
