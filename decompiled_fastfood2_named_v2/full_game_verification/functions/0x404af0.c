// rea decompile_all
// name: Game_RunSession
// address: 0x404af0
// body: available
// range: 0x404af0-0x4050d8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Type propagation algorithm not settling */

void Game_RunSession(void)

{
  char cVar1;
  DWORD DVar2;
  undefined4 *puVar3;
  int *this;
  HCURSOR pHVar4;
  void *this_00;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  undefined4 unaff_EBX;
  char *pcVar10;
  int unaff_EBP;
  undefined4 unaff_ESI;
  char *unaff_EDI;
  bool bVar11;
  longlong lVar12;
  undefined4 auStackY_397 [128];
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  char *pcVar16;
  char *pcVar17;
  char *pcVar18;
  int iVar19;
  char *pcVar20;
  undefined4 in_stack_fffffeb4;
  int iVar21;
  HANDLE pvVar22;
  undefined4 uVar23;
  char *pcVar24;
  undefined4 in_stack_fffffec4;
  undefined4 uVar25;
  int in_stack_fffffec8;
  undefined4 in_stack_fffffecc;
  undefined *in_stack_fffffed0;
  undefined4 in_stack_fffffed4;
  int in_stack_fffffed8;
  undefined4 in_stack_fffffedc;
  char *in_stack_fffffee0;
  undefined4 in_stack_fffffee4;
  int in_stack_fffffee8;
  undefined4 in_stack_fffffeec;
  undefined *in_stack_fffffef0;
  undefined4 in_stack_fffffef4;
  int in_stack_fffffef8;
  undefined4 in_stack_fffffefc;
  char *in_stack_ffffff00;
  undefined4 in_stack_ffffff04;
  int in_stack_ffffff08;
  undefined4 in_stack_ffffff0c;
  char *in_stack_ffffff10;
  undefined4 in_stack_ffffff14;
  int in_stack_ffffff18;
  undefined4 in_stack_ffffff1c;
  char *in_stack_ffffff20;
  undefined4 in_stack_ffffff24;
  int in_stack_ffffff28;
  undefined4 in_stack_ffffff2c;
  char *in_stack_ffffff30;
  undefined4 in_stack_ffffff34;
  int in_stack_ffffff38;
  undefined4 in_stack_ffffff3c;
  char *in_stack_ffffff40;
  undefined4 in_stack_ffffff44;
  int in_stack_ffffff48;
  undefined4 in_stack_ffffff4c;
  char *in_stack_ffffff50;
  undefined4 in_stack_ffffff54;
  int in_stack_ffffff58;
  undefined4 in_stack_ffffff5c;
  char *in_stack_ffffff60;
  undefined4 in_stack_ffffff64;
  int in_stack_ffffff68;
  undefined4 in_stack_ffffff6c;
  char *in_stack_ffffff70;
  undefined4 in_stack_ffffff74;
  int in_stack_ffffff78;
  undefined4 in_stack_ffffff7c;
  char *in_stack_ffffff80;
  undefined4 in_stack_ffffff84;
  int in_stack_ffffff88;
  undefined4 in_stack_ffffff8c;
  char *in_stack_ffffff90;
  undefined4 in_stack_ffffff94;
  int in_stack_ffffff98;
  undefined4 in_stack_ffffff9c;
  char *in_stack_ffffffa0;
  undefined4 in_stack_ffffffa4;
  int in_stack_ffffffa8;
  undefined4 in_stack_ffffffac;
  char *in_stack_ffffffb0;
  undefined4 in_stack_ffffffb4;
  int in_stack_ffffffb8;
  undefined4 in_stack_ffffffbc;
  char *in_stack_ffffffc0;
  undefined4 in_stack_ffffffc4;
  int in_stack_ffffffc8;
  undefined4 in_stack_ffffffcc;
  char *in_stack_ffffffd0;
  undefined4 in_stack_ffffffd4;
  int in_stack_ffffffd8;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Allocates, initializes, and runs the game session loop. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557ccc;
  pvStack_c = ExceptionList;
  uVar25 = CONCAT31((int3)((uint)in_stack_fffffec4 >> 8),DAT_00579aec);
  puVar3 = auStackY_397 + 0x97;
  for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  iVar6 = 0;
  iVar19 = 0;
  pcVar15 = (char *)0x0;
  pcVar20 = (char *)0x0;
  pcVar17 = (char *)0x1;
  pcVar14 = (char *)0x0;
  pcVar18 = (char *)0x0;
  iVar21 = 0;
  pcVar24 = (char *)0x0;
  ExceptionList = &pvStack_c;
  UI_ShowLoadingOverlay(1);
  DVar2 = timeGetTime();
  pcVar10 = (char *)(DVar2 + 1000);
  pcVar13 = pcVar10;
  Window_GadgetNotify_Slider_SetValue(DAT_0057c5f4,0x3f7,5,0);
  Window_ProcessMessageQueue(DAT_0057c5e0,0);
  puVar3 = operator_new(0x2e28);
  local_4 = 0;
  if (puVar3 == (undefined4 *)0x0) {
    DAT_0057c670 = (undefined4 *)0x0;
  }
  else {
    DAT_0057c670 = GameSession_Construct(puVar3);
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
    puVar3 = operator_new(0x5c);
    local_4 = 1;
    if (puVar3 == (undefined4 *)0x0) {
      this = (int *)0x0;
    }
    else {
      this = CRT_Ifstream_Construct();
    }
    local_4 = 0xffffffff;
    if (*(int *)(*(int *)(*(int *)(*this + 4) + 4 + (int)this) + 0x4c) == -1) {
      if (this != (int *)0x0) {
        (*(code *)**(undefined4 **)(*(int *)(*this + 4) + (int)this))(1);
      }
    }
    else {
      pHVar4 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
      SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar4);
      PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar4);
      CRT_Istream_Read(this,(int)register0x00000010 + -0xfc,0xf0);
      Game_SuspendSimulation(DAT_0057c670);
      Game_AcquireStateLock(DAT_0057c670,0);
      CS_Enter(DAT_0057c670[0x90]);
      puVar3 = (undefined4 *)
               Game_LoadSaveGame(DAT_0057c670,this,(undefined4 *)((int)auStackY_397 + 0x24b));
      CS_Leave(DAT_0057c670[0x90]);
      pcVar10 = pcVar13;
      if (this != (int *)0x0) {
        (*(code *)**(undefined4 **)((int)this + *(int *)(*this + 4)))(1);
        pcVar10 = pcVar13;
      }
      pHVar4 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
      SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar4);
      PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar4);
      if (puVar3 == (undefined4 *)0x0) {
        UI_MessageBoxf(DAT_0057c5e0,(byte *)s_Invalid_savegame___Errorpos__s_00563b98,
                       in_stack_fffffeb4);
        Window_UnlockState((int)DAT_0057c670);
        if (DAT_0057c670[0xb89] != 0) {
          SetEvent(DAT_0057c0d8);
        }
        DAT_0057bb54._0_1_ = '\0';
        pcVar13 = pcVar10;
      }
      else {
        Window_UnlockState((int)DAT_0057c670);
        Game_SetViewMode(DAT_0057c670,1,0);
        uVar7 = 0xffffffff;
        pcVar13 = s_geladen_00563b90;
        do {
          pcVar16 = pcVar13;
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          pcVar16 = pcVar13 + 1;
          cVar1 = *pcVar13;
          pcVar13 = pcVar16;
        } while (cVar1 != '\0');
        uVar7 = ~uVar7;
        pcVar16 = pcVar16 + -uVar7;
        pcVar9 = (char *)&DAT_0057bb54;
        for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar16;
          pcVar16 = pcVar16 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar7 = uVar7 & 3; pcVar13 = pcVar10, uVar7 != 0; uVar7 = uVar7 - 1) {
          *pcVar9 = *pcVar16;
          pcVar16 = pcVar16 + 1;
          pcVar9 = pcVar9 + 1;
        }
      }
    }
  }
  Game_InitScenario(DAT_0057c670,unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX,pcVar13,pcVar14,
                    (int)pcVar15,iVar6,pcVar17,puVar3,(int)pcVar18,iVar19,pcVar20,in_stack_fffffeb4,
                    iVar21);
  UI_CloseLoadingScreen();
  pcVar13 = (char *)0x1;
  this_00 = (void *)UI_LoadFontByName(DAT_0057c5e0,s_default_font_00563b80);
  cVar1 = *(char *)(DAT_0057c670 + 0xb65);
  pvVar22 = DAT_0057c0d8;
  uVar23 = DAT_0057c5ac;
  while ((cVar1 != '\0' &&
         (DVar2 = WaitForMultipleObjects(2,(HANDLE *)((int)auStackY_397 + 0x24f),0,0x14), DVar2 != 0
         ))) {
    pcVar16 = pcVar15;
    if (DAT_0057c5e0 != (void *)0x0) {
      Game_ApplyPendingScreen
                (DAT_0057c670,unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX,pcVar13,pcVar14,(int)pcVar15,
                 iVar6,pcVar17,puVar3,(int)pcVar18,iVar19,pcVar20,in_stack_fffffeb4,(int)pvVar22,
                 uVar23,pcVar24,uVar25,in_stack_fffffec8,in_stack_fffffecc,in_stack_fffffed0,
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
      lVar12 = Window_ProcessMessageQueue(DAT_0057c5e0,1);
      pcVar9 = (char *)lVar12;
      DAT_0057c670[0x93] = 0;
      bVar11 = pcVar13 != (char *)0x0;
      pcVar13 = (char *)0x0;
      if (bVar11) {
        pcVar13 = (char *)0x0;
        Game_ResumeSimulation(DAT_0057c670);
        Window_ShowWindowById(DAT_0057c5e0,DAT_0057c670[0xb6b]);
      }
      if (DAT_0057c5e8 != 0) {
        if ((pcVar9 == (char *)0x0) && (pcVar17 == (char *)0x0)) {
          iVar21 = Object_GetRootType((int)DAT_0057c5c8);
          if ((iVar21 == 0) && (this_00 != (void *)0x0)) {
            Surface_LockPrimary(DAT_0057c5c8);
            Text_SetMetrics(this_00,10,0x10,0);
            Set_Field9B8(this_00,0xffffff);
            Font_DrawTextLine(this_00,DAT_0057c5c8,(int)auStackY_397 + 0x25b);
            Surface_Unlock((int)DAT_0057c5c8);
          }
        }
        else {
          if (pcVar15 < pcVar9) {
            pcVar15 = pcVar9;
          }
          String_Format((undefined1 *)((int)auStackY_397 + 0x25b),
                        (byte *)s_fps__d_max__d_d__d_00563b6c,iVar19);
          iVar21 = Object_GetRootType((int)DAT_0057c5c8);
          if ((iVar21 == 0) && (this_00 != (void *)0x0)) {
            Surface_LockPrimary(DAT_0057c5c8);
            Text_SetMetrics(this_00,10,0x10,0);
            Set_Field9B8(this_00,0xffffff);
            Font_DrawTextLine(this_00,DAT_0057c5c8,(int)auStackY_397 + 0x25b);
            Surface_Unlock((int)DAT_0057c5c8);
          }
          pcVar17 = (char *)0x0;
        }
      }
      iVar21 = iVar6 + 1;
      pcVar9 = pcVar14 + (int)pcVar9;
      pcVar5 = (char *)timeGetTime();
      pcVar14 = pcVar9;
      pcVar16 = pcVar15;
      iVar6 = iVar21;
      if (pcVar10 <= pcVar5) {
        pcVar10 = pcVar10 + 1000;
        pcVar16 = (char *)0x0;
        iVar6 = 0;
        pcVar14 = (char *)0x0;
        pcVar17 = (char *)0x1;
        pcVar18 = pcVar9;
        iVar19 = iVar21;
        pcVar20 = pcVar15;
      }
    }
    cVar1 = *(char *)(DAT_0057c670 + 0xb65);
    pcVar15 = pcVar16;
  }
  DAT_0056b40c = 1;
  SoundBuffer_Release(DAT_0057ba0c);
  Game_RemoveScreenTimers((int)DAT_0057c670);
  UI_ReleaseRefCount(DAT_0057c5e0,(int)this_00);
  Game_DestroyCachedScreens(DAT_0057c670,-1);
  Game_DestroyEventWindow((int)DAT_0057c670);
  if (DAT_0057c670 != (undefined4 *)0x0) {
    (**(code **)*DAT_0057c670)(1);
  }
  DAT_0057c670 = (undefined4 *)0x0;
  DAT_0056b40c = 0;
  ExceptionList = pvStack_c;
  return;
}

