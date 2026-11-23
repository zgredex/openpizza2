// Game_InitScenario: ported from Pizza Connection 2 at 0x481d90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x481d90
#include "pc2_port.h"


/* WARNING (jumptable): Unable to track spacebase fully for stack */

void __thiscall
Game_InitScenario(void *self,char *arg1,uint32_t arg2,int arg3,uint32_t arg4,
                 char *arg5,uint32_t arg6,int arg7,uint32_t arg8,char *arg9,
                 uint32_t arg10,int arg11,uint32_t arg12,char *arg13,
                 uint32_t arg14,int arg15)

{
  char cVar1;
  int value2;
  double dVar3;
  int *ptr4;
  void *pvVar5;
  uint32_t *uptr6;
  int *ptr7;
  uint32_t *uptr8;
  uint32_t *uptr9;
  int value10;
  uint32_t uvalue11;
  uint32_t uvalue12;
  int value13;
  int value14;
  uint32_t unaff_EBX;
  int value15;
  int unaff_EBP;
  uint32_t unaff_ESI;
  char *cptr16;
  int value17;
  char *unaff_EDI;
  char *cptr18;
  int *ptr19;
  int64_t lvalue20;
  uint32_t unaff_retaddr;
  int aiStack_278 [128];
  char *in_stack_ffffffa4;
  uint32_t in_stack_ffffffa8;
  int in_stack_ffffffac;
  char *in_stack_ffffffb4;
  uint32_t in_stack_ffffffb8;
  int in_stack_ffffffbc;
  uint32_t in_stack_ffffffc0;
  char *in_stack_ffffffc4;
  uint32_t in_stack_ffffffc8;
  int in_stack_ffffffcc;
  uint32_t in_stack_ffffffd0;
  char *in_stack_ffffffd4;
  uint32_t in_stack_ffffffd8;
  int in_stack_ffffffdc;
  uint32_t in_stack_ffffffe0;
  char *in_stack_ffffffe4;
  uint32_t in_stack_ffffffe8;
  void *pvVar21;
  uint8_t *uptr22;
  uint32_t in_stack_fffffff8;
  
  pvVar21 = ExceptionList;
                    /* Builds a new scenario world, city, companies, and players. */
  ptr7 = aiStack_278 + 0x9d;
  uptr22 = &LAB_005581dc;
  ExceptionList = aiStack_278 + 0x99;
  value15 = 0;
  if ((char)DAT_0057bb44 == '\0') {
    uvalue11 = 0xffffffff;
    cptr16 = &DAT_0056809c;
    do {
      cptr18 = cptr16;
      if (uvalue11 == 0) break;
      uvalue11 = uvalue11 - 1;
      cptr18 = cptr16 + 1;
      cVar1 = *cptr16;
      cptr16 = cptr18;
    } while (cVar1 != '\0');
    uvalue11 = ~uvalue11;
    cptr16 = cptr18 + -uvalue11;
    cptr18 = (char *)&DAT_0057bb44;
    ExceptionList = aiStack_278 + 0x99;
    for (uvalue12 = uvalue11 >> 2; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
      *(uint32_t *)cptr18 = *(uint32_t *)cptr16;
      cptr16 = cptr16 + 4;
      cptr18 = cptr18 + 4;
    }
    for (uvalue11 = uvalue11 & 3; uvalue11 != 0; uvalue11 = uvalue11 - 1) {
      *cptr18 = *cptr16;
      cptr16 = cptr16 + 1;
      cptr18 = cptr18 + 1;
    }
  }
  Window_GadgetNotify_Slider_SetValue(DAT_0057c5f4,0x3f7,0x14,0);
  Window_ProcessMessageQueue(DAT_0057c5e0,0);
  CS_Enter(*(int *)((intptr_t)self + 0x240));
  if ((char)DAT_0057bb54 != '\0') goto LAB_00482524;
  ptr4 = &DAT_0057bdcc;
  do {
    if (ptr4[2] != 0) {
      if (ptr4[1] == DAT_0057bd10) {
        ptr4[1] = DAT_0057c270;
      }
      if (*ptr4 == DAT_0057bd0c) {
        *ptr4 = DAT_0057b780;
      }
    }
    ptr4 = ptr4 + 0x30;
  } while ((intptr_t)ptr4 < 0x57c18c);
  pvVar5 = operator_new(0x1158);
  if (pvVar5 == (void *)0x0) {
    uptr6 = (uint32_t *)0x0;
  }
  else {
    uptr6 = City_ConstructFromName
                       (pvVar5,(char *)&DAT_0057bb44,0,unaff_EDI,unaff_ESI,(intptr_t)ptr7,unaff_EBX,
                        in_stack_ffffffa4,in_stack_ffffffa8,in_stack_ffffffac,pvVar5,
                        in_stack_ffffffb4,in_stack_ffffffb8,in_stack_ffffffbc,in_stack_ffffffc0,
                        in_stack_ffffffc4,in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0,
                        in_stack_ffffffd4,in_stack_ffffffd8,in_stack_ffffffdc,in_stack_ffffffe0,
                        in_stack_ffffffe4,in_stack_ffffffe8,(intptr_t)pvVar21,uptr22,(char *)0x0,
                        in_stack_fffffff8,unaff_EBP,unaff_retaddr,arg1,arg2,arg3,arg4,
                        arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,
                        arg14,arg15);
  }
  value13 = 0;
  ptr7 = &DAT_0057bd14;
  do {
    if (*ptr7 != 0) {
      value13 = value13 + 1;
    }
    ptr7 = ptr7 + 0x30;
  } while ((intptr_t)ptr7 < 0x57c194);
  uptr9 = uptr6;
  if (DAT_0057bb20 == '\0') {
    City_Register(self,uptr6,uptr6[0x12],value13);
    Mission_ApplySettings((intptr_t)uptr6);
    value13 = uptr6[0x103] + 1;
    value14 = 0;
    if (0 < value13) {
      uptr8 = &DAT_0057bcd8;
      value14 = value13;
      do {
        uptr8[0xf] = 1;
        *uptr8 = 100;
        uptr8 = uptr8 + 0x30;
        value14 = value14 + -1;
      } while (value14 != 0);
      value14 = value13;
      if (5 < value13) goto LAB_00481f31;
    }
    uptr8 = &DAT_0057bd14 + value14 * 0x30;
    do {
      *uptr8 = 0;
      uptr8 = uptr8 + 0x30;
    } while ((intptr_t)uptr8 < 0x57c194);
  }
  else {
    City_Register(self,uptr6,DAT_0057bb28,value13);
  }
LAB_00481f31:
  Sound_InitSpeechVoice(DAT_0057ba0c);
  Window_GadgetNotify_Slider_SetValue(DAT_0057c5f4,0x3f7,0x32,0);
  Window_ProcessMessageQueue(DAT_0057c5e0,0);
  value13 = Game_GetStartingCapital();
  ptr7 = &DAT_0057bd10;
  do {
    if (ptr7[1] != 0) {
      pvVar5 = operator_new(0x1f0);
      if (pvVar5 == (void *)0x0) {
        uptr8 = (uint32_t *)0x0;
        uptr6 = uptr9;
      }
      else {
        uptr8 = Company_ConstructDefault(pvVar5,value15);
        uptr6 = uptr9;
      }
      *(uint32_t **)((intptr_t)self + value15 * 4 + 0x200) = uptr8;
      String_Format((uint8_t *)(aiStack_278 + 0x91),&DAT_005630d0,ptr7 + -0x1e);
      uvalue11 = 0xffffffff;
      ptr4 = aiStack_278 + 0x91;
      do {
        ptr19 = ptr4;
        if (uvalue11 == 0) break;
        uvalue11 = uvalue11 - 1;
        ptr19 = (int *)((intptr_t)ptr4 + 1);
        value14 = *ptr4;
        ptr4 = ptr19;
      } while ((char)value14 != '\0');
      uvalue11 = ~uvalue11;
      uptr9 = (uint32_t *)((intptr_t)ptr19 - uvalue11);
      uptr8 = (uint32_t *)(*(int *)((intptr_t)self + value15 * 4 + 0x200) + 8);
      for (uvalue12 = uvalue11 >> 2; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
        *uptr8 = *uptr9;
        uptr9 = uptr9 + 1;
        uptr8 = uptr8 + 1;
      }
      for (uvalue11 = uvalue11 & 3; uvalue11 != 0; uvalue11 = uvalue11 - 1) {
        *(uint8_t *)uptr8 = *(uint8_t *)uptr9;
        uptr9 = (uint32_t *)((intptr_t)uptr9 + 1);
        uptr8 = (uint32_t *)((intptr_t)uptr8 + 1);
      }
      *(int *)(*(int *)((intptr_t)self + value15 * 4 + 0x200) + 0x48) = value15;
      *(uint32_t *)(*(int *)((intptr_t)self + value15 * 4 + 0x200) + 0x1dc) = (&DAT_00563874)[*ptr7];
      *(int *)(*(int *)((intptr_t)self + value15 * 4 + 0x200) + 0x1e0) = ptr7[-1];
      if (value15 == 0) {
        if (DAT_0057bb20 == '\0') {
          value14 = *(int *)((intptr_t)self + 0x200);
          dVar3 = (double)(intptr_t)uptr6[0x102];
        }
        else {
          value14 = *(int *)((intptr_t)self + 0x200);
          dVar3 = (double)((DAT_0057bcd8 * value13) / 100);
        }
      }
      else {
        value14 = *(int *)((intptr_t)self + value15 * 4 + 0x200);
        dVar3 = (double)(((&DAT_0057bcd8)[value15 * 0x30] * 50000) / 100);
      }
      *(double *)(value14 + 0x108) = dVar3;
      pvVar5 = operator_new(0xb0);
      if (pvVar5 == (void *)0x0) {
        uptr9 = (uint32_t *)0x0;
      }
      else {
        uptr9 = Player_Construct(pvVar5,(int *)0x0);
      }
      *(uint32_t **)((intptr_t)self + value15 * 4 + 0x224) = uptr9;
      Object_SetField8(uptr9,value15);
      uvalue11 = 0xffffffff;
      ptr4 = ptr7 + -0x2e;
      do {
        ptr19 = ptr4;
        if (uvalue11 == 0) break;
        uvalue11 = uvalue11 - 1;
        ptr19 = (int *)((intptr_t)ptr4 + 1);
        value14 = *ptr4;
        ptr4 = ptr19;
      } while ((char)value14 != '\0');
      uvalue11 = ~uvalue11;
      uptr9 = (uint32_t *)((intptr_t)ptr19 - uvalue11);
      uptr8 = (uint32_t *)(*(int *)((intptr_t)self + value15 * 4 + 0x224) + 0xc);
      for (uvalue12 = uvalue11 >> 2; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
        *uptr8 = *uptr9;
        uptr9 = uptr9 + 1;
        uptr8 = uptr8 + 1;
      }
      for (uvalue11 = uvalue11 & 3; uvalue11 != 0; uvalue11 = uvalue11 - 1) {
        *(uint8_t *)uptr8 = *(uint8_t *)uptr9;
        uptr9 = (uint32_t *)((intptr_t)uptr9 + 1);
        uptr8 = (uint32_t *)((intptr_t)uptr8 + 1);
      }
      *(int *)(*(int *)((intptr_t)self + value15 * 4 + 0x224) + 0x3c) = ptr7[-0xc];
      *(int *)(*(int *)((intptr_t)self + value15 * 4 + 0x224) + 0x40) = ptr7[-0xb];
      *(int *)(*(int *)((intptr_t)self + value15 * 4 + 0x224) + 0x44) = ptr7[-10];
      *(int *)(*(int *)((intptr_t)self + value15 * 4 + 0x224) + 0x48) = ptr7[-9];
      *(int *)(*(int *)((intptr_t)self + value15 * 4 + 0x224) + 0x4c) = ptr7[-8];
      *(int *)(*(int *)((intptr_t)self + value15 * 4 + 0x224) + 0x50) = ptr7[-7];
      if (value15 == 0) {
        Player_AIState_Init(*(int *)((intptr_t)self + 0x224));
      }
      else {
        Player_ResetAiState(*(int *)((intptr_t)self + value15 * 4 + 0x224));
        value14 = 1;
        uvalue11 = ptr7[-0xd];
        if ((intptr_t)uvalue11 < 0) {
          value14 = -1;
        }
        value17 = (uvalue11 ^ (intptr_t)uvalue11 >> 0x1f) - ((intptr_t)uvalue11 >> 0x1f);
        while (0 < value17) {
          uvalue11 = Random_RangeFast(0,5);
          switch(uvalue11) {
          case 0:
            value2 = *(int *)((intptr_t)self + value15 * 4 + 0x224);
            value10 = *(int *)(value2 + 0x3c) + value14;
            if ((value10 < 4) && (-4 < value10)) {
              value17 = value17 + -1;
              *(int *)(value2 + 0x3c) = value10;
            }
            break;
          case 1:
            value2 = *(int *)((intptr_t)self + value15 * 4 + 0x224);
            value10 = *(int *)(value2 + 0x40) + value14;
            if ((value10 < 4) && (-4 < value10)) {
              value17 = value17 + -1;
              *(int *)(value2 + 0x40) = value10;
            }
            break;
          case 2:
            value2 = *(int *)((intptr_t)self + value15 * 4 + 0x224);
            value10 = *(int *)(value2 + 0x44) + value14;
            if ((value10 < 4) && (-4 < value10)) {
              value17 = value17 + -1;
              *(int *)(value2 + 0x44) = value10;
            }
            break;
          case 3:
            value2 = *(int *)((intptr_t)self + value15 * 4 + 0x224);
            value10 = *(int *)(value2 + 0x48) + value14;
            if ((value10 < 4) && (-4 < value10)) {
              value17 = value17 + -1;
              *(int *)(value2 + 0x48) = value10;
            }
            break;
          case 4:
            value2 = *(int *)((intptr_t)self + value15 * 4 + 0x224);
            value10 = *(int *)(value2 + 0x4c) + value14;
            if ((value10 < 4) && (-4 < value10)) {
              value17 = value17 + -1;
              *(int *)(value2 + 0x4c) = value10;
            }
            break;
          case 5:
            value2 = *(int *)((intptr_t)self + value15 * 4 + 0x224);
            value10 = *(int *)(value2 + 0x50) + value14;
            if ((value10 < 4) && (-4 < value10)) {
              value17 = value17 + -1;
              *(int *)(value2 + 0x50) = value10;
            }
          }
        }
      }
      pvVar5 = operator_new(0x828);
      if (pvVar5 == (void *)0x0) {
        uptr9 = (uint32_t *)0x0;
      }
      else {
        uptr9 = Character_Construct(pvVar5,-1,1);
      }
      value15 = value15 + 1;
      uptr9[9] = ptr7[-6];
      uptr9[10] = ptr7[-5];
      uptr9[0xb] = ptr7[-4];
      uptr9[0xc] = ptr7[-3];
      uptr9[0xd] = ptr7[-2];
      *(uint32_t **)(*(int *)((intptr_t)self + value15 * 4 + 0x220) + 4) = uptr9;
      uptr9 = uptr6;
    }
    ptr7 = ptr7 + 0x30;
  } while ((intptr_t)ptr7 < 0x57c190);
  if (((0 < DAT_0057bb40) && (DAT_0057bb20 == '\0')) &&
     (PlayerCompany_InitDefaults(*(int *)((intptr_t)self + 0x224)), DAT_0057bb40 == 9)) {
    if (DAT_0057c254 < 40000) {
      DAT_0057c254 = 40000;
    }
    *(double *)(*(int *)((intptr_t)self + 0x200) + 0x108) = (double)DAT_0057c254;
  }
  Game_InitCompanySlots(*(int *)((intptr_t)self + 0x90));
  UI_UpdateAllSlots(*(void **)((intptr_t)self + 0x90));
  if (DAT_0057bb20 == '\0') {
    if (uptr6 == (uint32_t *)0x0) {
      uptr9 = (uint32_t *)0x0;
    }
    else {
      uptr9 = uptr6 + 1;
    }
    Game_AddPoliceStations(uptr9[0xd1]);
    value13 = uptr6[0x103];
    if (uptr6 == (uint32_t *)0x0) {
      uptr6 = (uint32_t *)0x0;
    }
    else {
      uptr6 = uptr6 + 1;
    }
    value14 = uptr6[0xcf];
    if (value14 == 4) {
      if (-1 < value13) {
        value13 = value13 + 1;
        value14 = 0;
        do {
          value13 = value13 + -1;
          *(uint16_t *)(value14 + 0x128 + *(int *)((intptr_t)self + 0x90)) = 0x1e;
          *(uint16_t *)(value14 + 0x130 + *(int *)((intptr_t)self + 0x90)) = 0x14;
          value14 = value14 + 0x168;
        } while (value13 != 0);
      }
    }
    else if (value14 == 6) {
      if (-1 < value13) {
        value13 = value13 + 1;
        value14 = 0;
        do {
          value13 = value13 + -1;
          *(uint16_t *)(value14 + 0x128 + *(int *)((intptr_t)self + 0x90)) = 0x3c;
          *(uint16_t *)(value14 + 0x130 + *(int *)((intptr_t)self + 0x90)) = 0x28;
          value14 = value14 + 0x168;
        } while (value13 != 0);
      }
    }
    else if ((value14 == 9) && (-1 < value13)) {
      value13 = value13 + 1;
      value14 = 0;
      do {
        value13 = value13 + -1;
        *(uint16_t *)(value14 + 0x128 + *(int *)((intptr_t)self + 0x90)) = 0x5a;
        *(uint16_t *)(value14 + 0x130 + *(int *)((intptr_t)self + 0x90)) = 0x5a;
        value14 = value14 + 0x168;
      } while (value13 != 0);
    }
  }
  lvalue20 = __ftol();
  value13 = (intptr_t)lvalue20;
  if (value15 <= (intptr_t)lvalue20) {
    value13 = value15 + -1;
  }
  value14 = 0;
  value17 = 1;
  if (0 < value15) {
    ptr7 = aiStack_278 + 0x8b;
    do {
      if (value14 == value13) {
        *ptr7 = 0;
      }
      else {
        *ptr7 = value17;
        value17 = value17 + 1;
      }
      value14 = value14 + 1;
      ptr7 = ptr7 + 1;
    } while (value14 < value15);
    if (0 < value15) {
      value14 = 0x32;
      ptr7 = aiStack_278 + 0x8b;
      value13 = value15;
      do {
        Company_GenerateStartingRecipes(*(void **)((intptr_t)self + *ptr7 * 4 + 0x200));
        Window_GadgetNotify_Slider_SetValue(DAT_0057c5f4,0x3f7,value14 / value15 + 0x32,0);
        Window_ProcessMessageQueue(DAT_0057c5e0,0);
        value14 = value14 + 0x32;
        ptr7 = ptr7 + 1;
        value13 = value13 + -1;
      } while (value13 != 0);
    }
  }
  Map_RefreshObjectSprites((intptr_t)self);
LAB_00482524:
  CS_Leave(*(int *)((intptr_t)self + 0x240));
  Window_GadgetNotify_Slider_SetValue(DAT_0057c5f4,0x3f7,100,0);
  Window_ProcessMessageQueue(DAT_0057c5e0,0);
  Game_AddScreenTimer((intptr_t)self);
  Sound_UpdatePositionCountdown(DAT_0057ba0c);
  ExceptionList = pvVar21;
  return;
}
