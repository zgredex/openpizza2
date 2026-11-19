// rea decompile_all
// name: Game_InitScenario
// address: 0x481d90
// body: available
// range: 0x481d90-0x482574 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING (jumptable): Unable to track spacebase fully for stack */

void __thiscall
Game_InitScenario(void *this,char *param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 char *param_5,undefined4 param_6,int param_7,undefined4 param_8,char *param_9,
                 undefined4 param_10,int param_11,undefined4 param_12,char *param_13,
                 undefined4 param_14,int param_15)

{
  char cVar1;
  int iVar2;
  double dVar3;
  int *piVar4;
  void *pvVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  undefined4 unaff_EBX;
  int iVar15;
  int unaff_EBP;
  undefined4 unaff_ESI;
  char *pcVar16;
  int iVar17;
  char *unaff_EDI;
  char *pcVar18;
  int *piVar19;
  longlong lVar20;
  undefined4 unaff_retaddr;
  int aiStack_278 [128];
  char *in_stack_ffffffa4;
  undefined4 in_stack_ffffffa8;
  int in_stack_ffffffac;
  char *in_stack_ffffffb4;
  undefined4 in_stack_ffffffb8;
  int in_stack_ffffffbc;
  undefined4 in_stack_ffffffc0;
  char *in_stack_ffffffc4;
  undefined4 in_stack_ffffffc8;
  int in_stack_ffffffcc;
  undefined4 in_stack_ffffffd0;
  char *in_stack_ffffffd4;
  undefined4 in_stack_ffffffd8;
  int in_stack_ffffffdc;
  undefined4 in_stack_ffffffe0;
  char *in_stack_ffffffe4;
  undefined4 in_stack_ffffffe8;
  void *pvVar21;
  undefined1 *puVar22;
  undefined4 in_stack_fffffff8;
  
  pvVar21 = ExceptionList;
                    /* Builds a new scenario world, city, companies, and players. */
  piVar7 = aiStack_278 + 0x9d;
  puVar22 = &LAB_005581dc;
  ExceptionList = aiStack_278 + 0x99;
  iVar15 = 0;
  if ((char)DAT_0057bb44 == '\0') {
    uVar11 = 0xffffffff;
    pcVar16 = &DAT_0056809c;
    do {
      pcVar18 = pcVar16;
      if (uVar11 == 0) break;
      uVar11 = uVar11 - 1;
      pcVar18 = pcVar16 + 1;
      cVar1 = *pcVar16;
      pcVar16 = pcVar18;
    } while (cVar1 != '\0');
    uVar11 = ~uVar11;
    pcVar16 = pcVar18 + -uVar11;
    pcVar18 = (char *)&DAT_0057bb44;
    ExceptionList = aiStack_278 + 0x99;
    for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
      *(undefined4 *)pcVar18 = *(undefined4 *)pcVar16;
      pcVar16 = pcVar16 + 4;
      pcVar18 = pcVar18 + 4;
    }
    for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
      *pcVar18 = *pcVar16;
      pcVar16 = pcVar16 + 1;
      pcVar18 = pcVar18 + 1;
    }
  }
  Window_GadgetNotify_Slider_SetValue(DAT_0057c5f4,0x3f7,0x14,0);
  Window_ProcessMessageQueue(DAT_0057c5e0,0);
  CS_Enter(*(int *)((int)this + 0x240));
  if ((char)DAT_0057bb54 != '\0') goto LAB_00482524;
  piVar4 = &DAT_0057bdcc;
  do {
    if (piVar4[2] != 0) {
      if (piVar4[1] == DAT_0057bd10) {
        piVar4[1] = DAT_0057c270;
      }
      if (*piVar4 == DAT_0057bd0c) {
        *piVar4 = DAT_0057b780;
      }
    }
    piVar4 = piVar4 + 0x30;
  } while ((int)piVar4 < 0x57c18c);
  pvVar5 = operator_new(0x1158);
  if (pvVar5 == (void *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6 = City_ConstructFromName
                       (pvVar5,(char *)&DAT_0057bb44,0,unaff_EDI,unaff_ESI,(int)piVar7,unaff_EBX,
                        in_stack_ffffffa4,in_stack_ffffffa8,in_stack_ffffffac,pvVar5,
                        in_stack_ffffffb4,in_stack_ffffffb8,in_stack_ffffffbc,in_stack_ffffffc0,
                        in_stack_ffffffc4,in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0,
                        in_stack_ffffffd4,in_stack_ffffffd8,in_stack_ffffffdc,in_stack_ffffffe0,
                        in_stack_ffffffe4,in_stack_ffffffe8,(int)pvVar21,puVar22,(char *)0x0,
                        in_stack_fffffff8,unaff_EBP,unaff_retaddr,param_1,param_2,param_3,param_4,
                        param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12,param_13,
                        param_14,param_15);
  }
  iVar13 = 0;
  piVar7 = &DAT_0057bd14;
  do {
    if (*piVar7 != 0) {
      iVar13 = iVar13 + 1;
    }
    piVar7 = piVar7 + 0x30;
  } while ((int)piVar7 < 0x57c194);
  puVar9 = puVar6;
  if (DAT_0057bb20 == '\0') {
    City_Register(this,puVar6,puVar6[0x12],iVar13);
    Mission_ApplySettings((int)puVar6);
    iVar13 = puVar6[0x103] + 1;
    iVar14 = 0;
    if (0 < iVar13) {
      puVar8 = &DAT_0057bcd8;
      iVar14 = iVar13;
      do {
        puVar8[0xf] = 1;
        *puVar8 = 100;
        puVar8 = puVar8 + 0x30;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      iVar14 = iVar13;
      if (5 < iVar13) goto LAB_00481f31;
    }
    puVar8 = &DAT_0057bd14 + iVar14 * 0x30;
    do {
      *puVar8 = 0;
      puVar8 = puVar8 + 0x30;
    } while ((int)puVar8 < 0x57c194);
  }
  else {
    City_Register(this,puVar6,DAT_0057bb28,iVar13);
  }
LAB_00481f31:
  Sound_InitSpeechVoice(DAT_0057ba0c);
  Window_GadgetNotify_Slider_SetValue(DAT_0057c5f4,0x3f7,0x32,0);
  Window_ProcessMessageQueue(DAT_0057c5e0,0);
  iVar13 = Game_GetStartingCapital();
  piVar7 = &DAT_0057bd10;
  do {
    if (piVar7[1] != 0) {
      pvVar5 = operator_new(0x1f0);
      if (pvVar5 == (void *)0x0) {
        puVar8 = (undefined4 *)0x0;
        puVar6 = puVar9;
      }
      else {
        puVar8 = Company_ConstructDefault(pvVar5,iVar15);
        puVar6 = puVar9;
      }
      *(undefined4 **)((int)this + iVar15 * 4 + 0x200) = puVar8;
      String_Format((undefined1 *)(aiStack_278 + 0x91),&DAT_005630d0,piVar7 + -0x1e);
      uVar11 = 0xffffffff;
      piVar4 = aiStack_278 + 0x91;
      do {
        piVar19 = piVar4;
        if (uVar11 == 0) break;
        uVar11 = uVar11 - 1;
        piVar19 = (int *)((int)piVar4 + 1);
        iVar14 = *piVar4;
        piVar4 = piVar19;
      } while ((char)iVar14 != '\0');
      uVar11 = ~uVar11;
      puVar9 = (undefined4 *)((int)piVar19 - uVar11);
      puVar8 = (undefined4 *)(*(int *)((int)this + iVar15 * 4 + 0x200) + 8);
      for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
        *puVar8 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      *(int *)(*(int *)((int)this + iVar15 * 4 + 0x200) + 0x48) = iVar15;
      *(undefined4 *)(*(int *)((int)this + iVar15 * 4 + 0x200) + 0x1dc) = (&DAT_00563874)[*piVar7];
      *(int *)(*(int *)((int)this + iVar15 * 4 + 0x200) + 0x1e0) = piVar7[-1];
      if (iVar15 == 0) {
        if (DAT_0057bb20 == '\0') {
          iVar14 = *(int *)((int)this + 0x200);
          dVar3 = (double)(int)puVar6[0x102];
        }
        else {
          iVar14 = *(int *)((int)this + 0x200);
          dVar3 = (double)((DAT_0057bcd8 * iVar13) / 100);
        }
      }
      else {
        iVar14 = *(int *)((int)this + iVar15 * 4 + 0x200);
        dVar3 = (double)(((&DAT_0057bcd8)[iVar15 * 0x30] * 50000) / 100);
      }
      *(double *)(iVar14 + 0x108) = dVar3;
      pvVar5 = operator_new(0xb0);
      if (pvVar5 == (void *)0x0) {
        puVar9 = (undefined4 *)0x0;
      }
      else {
        puVar9 = Player_Construct(pvVar5,(int *)0x0);
      }
      *(undefined4 **)((int)this + iVar15 * 4 + 0x224) = puVar9;
      Object_SetField8(puVar9,iVar15);
      uVar11 = 0xffffffff;
      piVar4 = piVar7 + -0x2e;
      do {
        piVar19 = piVar4;
        if (uVar11 == 0) break;
        uVar11 = uVar11 - 1;
        piVar19 = (int *)((int)piVar4 + 1);
        iVar14 = *piVar4;
        piVar4 = piVar19;
      } while ((char)iVar14 != '\0');
      uVar11 = ~uVar11;
      puVar9 = (undefined4 *)((int)piVar19 - uVar11);
      puVar8 = (undefined4 *)(*(int *)((int)this + iVar15 * 4 + 0x224) + 0xc);
      for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
        *puVar8 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      *(int *)(*(int *)((int)this + iVar15 * 4 + 0x224) + 0x3c) = piVar7[-0xc];
      *(int *)(*(int *)((int)this + iVar15 * 4 + 0x224) + 0x40) = piVar7[-0xb];
      *(int *)(*(int *)((int)this + iVar15 * 4 + 0x224) + 0x44) = piVar7[-10];
      *(int *)(*(int *)((int)this + iVar15 * 4 + 0x224) + 0x48) = piVar7[-9];
      *(int *)(*(int *)((int)this + iVar15 * 4 + 0x224) + 0x4c) = piVar7[-8];
      *(int *)(*(int *)((int)this + iVar15 * 4 + 0x224) + 0x50) = piVar7[-7];
      if (iVar15 == 0) {
        Player_AIState_Init(*(int *)((int)this + 0x224));
      }
      else {
        Player_ResetAiState(*(int *)((int)this + iVar15 * 4 + 0x224));
        iVar14 = 1;
        uVar11 = piVar7[-0xd];
        if ((int)uVar11 < 0) {
          iVar14 = -1;
        }
        iVar17 = (uVar11 ^ (int)uVar11 >> 0x1f) - ((int)uVar11 >> 0x1f);
        while (0 < iVar17) {
          uVar11 = Random_RangeFast(0,5);
          switch(uVar11) {
          case 0:
            iVar2 = *(int *)((int)this + iVar15 * 4 + 0x224);
            iVar10 = *(int *)(iVar2 + 0x3c) + iVar14;
            if ((iVar10 < 4) && (-4 < iVar10)) {
              iVar17 = iVar17 + -1;
              *(int *)(iVar2 + 0x3c) = iVar10;
            }
            break;
          case 1:
            iVar2 = *(int *)((int)this + iVar15 * 4 + 0x224);
            iVar10 = *(int *)(iVar2 + 0x40) + iVar14;
            if ((iVar10 < 4) && (-4 < iVar10)) {
              iVar17 = iVar17 + -1;
              *(int *)(iVar2 + 0x40) = iVar10;
            }
            break;
          case 2:
            iVar2 = *(int *)((int)this + iVar15 * 4 + 0x224);
            iVar10 = *(int *)(iVar2 + 0x44) + iVar14;
            if ((iVar10 < 4) && (-4 < iVar10)) {
              iVar17 = iVar17 + -1;
              *(int *)(iVar2 + 0x44) = iVar10;
            }
            break;
          case 3:
            iVar2 = *(int *)((int)this + iVar15 * 4 + 0x224);
            iVar10 = *(int *)(iVar2 + 0x48) + iVar14;
            if ((iVar10 < 4) && (-4 < iVar10)) {
              iVar17 = iVar17 + -1;
              *(int *)(iVar2 + 0x48) = iVar10;
            }
            break;
          case 4:
            iVar2 = *(int *)((int)this + iVar15 * 4 + 0x224);
            iVar10 = *(int *)(iVar2 + 0x4c) + iVar14;
            if ((iVar10 < 4) && (-4 < iVar10)) {
              iVar17 = iVar17 + -1;
              *(int *)(iVar2 + 0x4c) = iVar10;
            }
            break;
          case 5:
            iVar2 = *(int *)((int)this + iVar15 * 4 + 0x224);
            iVar10 = *(int *)(iVar2 + 0x50) + iVar14;
            if ((iVar10 < 4) && (-4 < iVar10)) {
              iVar17 = iVar17 + -1;
              *(int *)(iVar2 + 0x50) = iVar10;
            }
          }
        }
      }
      pvVar5 = operator_new(0x828);
      if (pvVar5 == (void *)0x0) {
        puVar9 = (undefined4 *)0x0;
      }
      else {
        puVar9 = Character_Construct(pvVar5,-1,1);
      }
      iVar15 = iVar15 + 1;
      puVar9[9] = piVar7[-6];
      puVar9[10] = piVar7[-5];
      puVar9[0xb] = piVar7[-4];
      puVar9[0xc] = piVar7[-3];
      puVar9[0xd] = piVar7[-2];
      *(undefined4 **)(*(int *)((int)this + iVar15 * 4 + 0x220) + 4) = puVar9;
      puVar9 = puVar6;
    }
    piVar7 = piVar7 + 0x30;
  } while ((int)piVar7 < 0x57c190);
  if (((0 < DAT_0057bb40) && (DAT_0057bb20 == '\0')) &&
     (PlayerCompany_InitDefaults(*(int *)((int)this + 0x224)), DAT_0057bb40 == 9)) {
    if (DAT_0057c254 < 40000) {
      DAT_0057c254 = 40000;
    }
    *(double *)(*(int *)((int)this + 0x200) + 0x108) = (double)DAT_0057c254;
  }
  Game_InitCompanySlots(*(int *)((int)this + 0x90));
  UI_UpdateAllSlots(*(void **)((int)this + 0x90));
  if (DAT_0057bb20 == '\0') {
    if (puVar6 == (undefined4 *)0x0) {
      puVar9 = (undefined4 *)0x0;
    }
    else {
      puVar9 = puVar6 + 1;
    }
    Game_AddPoliceStations(puVar9[0xd1]);
    iVar13 = puVar6[0x103];
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6 = puVar6 + 1;
    }
    iVar14 = puVar6[0xcf];
    if (iVar14 == 4) {
      if (-1 < iVar13) {
        iVar13 = iVar13 + 1;
        iVar14 = 0;
        do {
          iVar13 = iVar13 + -1;
          *(undefined2 *)(iVar14 + 0x128 + *(int *)((int)this + 0x90)) = 0x1e;
          *(undefined2 *)(iVar14 + 0x130 + *(int *)((int)this + 0x90)) = 0x14;
          iVar14 = iVar14 + 0x168;
        } while (iVar13 != 0);
      }
    }
    else if (iVar14 == 6) {
      if (-1 < iVar13) {
        iVar13 = iVar13 + 1;
        iVar14 = 0;
        do {
          iVar13 = iVar13 + -1;
          *(undefined2 *)(iVar14 + 0x128 + *(int *)((int)this + 0x90)) = 0x3c;
          *(undefined2 *)(iVar14 + 0x130 + *(int *)((int)this + 0x90)) = 0x28;
          iVar14 = iVar14 + 0x168;
        } while (iVar13 != 0);
      }
    }
    else if ((iVar14 == 9) && (-1 < iVar13)) {
      iVar13 = iVar13 + 1;
      iVar14 = 0;
      do {
        iVar13 = iVar13 + -1;
        *(undefined2 *)(iVar14 + 0x128 + *(int *)((int)this + 0x90)) = 0x5a;
        *(undefined2 *)(iVar14 + 0x130 + *(int *)((int)this + 0x90)) = 0x5a;
        iVar14 = iVar14 + 0x168;
      } while (iVar13 != 0);
    }
  }
  lVar20 = __ftol();
  iVar13 = (int)lVar20;
  if (iVar15 <= (int)lVar20) {
    iVar13 = iVar15 + -1;
  }
  iVar14 = 0;
  iVar17 = 1;
  if (0 < iVar15) {
    piVar7 = aiStack_278 + 0x8b;
    do {
      if (iVar14 == iVar13) {
        *piVar7 = 0;
      }
      else {
        *piVar7 = iVar17;
        iVar17 = iVar17 + 1;
      }
      iVar14 = iVar14 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar14 < iVar15);
    if (0 < iVar15) {
      iVar14 = 0x32;
      piVar7 = aiStack_278 + 0x8b;
      iVar13 = iVar15;
      do {
        Company_GenerateStartingRecipes(*(void **)((int)this + *piVar7 * 4 + 0x200));
        Window_GadgetNotify_Slider_SetValue(DAT_0057c5f4,0x3f7,iVar14 / iVar15 + 0x32,0);
        Window_ProcessMessageQueue(DAT_0057c5e0,0);
        iVar14 = iVar14 + 0x32;
        piVar7 = piVar7 + 1;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
    }
  }
  Map_RefreshObjectSprites((int)this);
LAB_00482524:
  CS_Leave(*(int *)((int)this + 0x240));
  Window_GadgetNotify_Slider_SetValue(DAT_0057c5f4,0x3f7,100,0);
  Window_ProcessMessageQueue(DAT_0057c5e0,0);
  Game_AddScreenTimer((int)this);
  Sound_UpdatePositionCountdown(DAT_0057ba0c);
  ExceptionList = pvVar21;
  return;
}

