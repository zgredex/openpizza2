// GameLoop_DispatchScreens: ported from Pizza Connection 2 at 0x4052c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4052c0
#include "pc2_port.h"

void __cdecl
GameLoop_DispatchScreens
          (char *arg1,uint32_t arg2,int arg3,uint32_t arg4,char *arg5,
          uint32_t arg6,int arg7,uint32_t arg8,char *arg9,uint32_t arg10,
          int arg11,uint32_t arg12,char *arg13,uint32_t arg14,int arg15,
          uint32_t arg16,char *arg17,uint32_t arg18,int arg19,uint32_t arg20,
          char *arg21,uint32_t arg22,int arg23,uint32_t arg24,char *arg25,
          uint32_t arg26,int arg27)

{
  int value1;
  int *ptr2;
  int value3;
  uint8_t *uptr4;
  DWORD DVar5;
  uint32_t unaff_EBX;
  char *unaff_EBP;
  uint32_t unaff_ESI;
  char *cptr6;
  int unaff_EDI;
  int *ptr7;
  uint32_t unaff_retaddr;
  int aiStack_324 [128];
  int in_stack_fffffefc;
  uint32_t in_stack_ffffff00;
  char *in_stack_ffffff04;
  uint32_t in_stack_ffffff08;
  int in_stack_ffffff0c;
  uint32_t in_stack_ffffff10;
  char *in_stack_ffffff14;
  uint32_t in_stack_ffffff18;
  int in_stack_ffffff1c;
  uint32_t in_stack_ffffff20;
  char *in_stack_ffffff24;
  uint32_t in_stack_ffffff28;
  int in_stack_ffffff2c;
  uint32_t in_stack_ffffff30;
  char *in_stack_ffffff34;
  uint32_t in_stack_ffffff38;
  int in_stack_ffffff3c;
  uint32_t in_stack_ffffff40;
  char *in_stack_ffffff44;
  uint32_t in_stack_ffffff48;
  int in_stack_ffffff4c;
  uint32_t in_stack_ffffff50;
  char *in_stack_ffffff54;
  uint32_t in_stack_ffffff58;
  int in_stack_ffffff5c;
  uint32_t in_stack_ffffff60;
  uint8_t *in_stack_ffffff64;
  uint32_t in_stack_ffffff68;
  int in_stack_ffffff6c;
  uint32_t in_stack_ffffff70;
  char *in_stack_ffffff74;
  uint32_t in_stack_ffffff78;
  int in_stack_ffffff7c;
  uint32_t in_stack_ffffff80;
  uint8_t *in_stack_ffffff84;
  uint32_t in_stack_ffffff88;
  int in_stack_ffffff8c;
  uint32_t in_stack_ffffff90;
  char *in_stack_ffffff94;
  uint32_t in_stack_ffffff98;
  int in_stack_ffffff9c;
  uint32_t in_stack_ffffffa0;
  char *in_stack_ffffffa4;
  uint32_t in_stack_ffffffa8;
  int in_stack_ffffffac;
  uint32_t in_stack_ffffffb0;
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
  int in_stack_ffffffec;
  uint32_t in_stack_fffffff0;
  char *in_stack_fffffff4;
  uint32_t in_stack_fffffff8;
  int in_stack_fffffffc;
  
  cptr6 = (char *)0x0;
  ptr2 = Resource_Open(DAT_0057c5d8,s_mission_txt_00563bd8,0);
  if (ptr2 == (int *)0x0) {
    NoOp_Stub();
  }
  value3 = Resource_ReadLine(DAT_0057c5d8,(uint8_t *)(aiStack_324 + 0x89),0x100,(intptr_t)ptr2);
  while (value3 != -1) {
    value3 = -1;
    ptr7 = aiStack_324 + 0x89;
    do {
      if (value3 == 0) break;
      value3 = value3 + -1;
      value1 = *ptr7;
      ptr7 = (int *)((intptr_t)ptr7 + 1);
    } while ((char)value1 != '\0');
    if (value3 == -2) break;
    uptr4 = operator_new(0x20);
    String_Format(uptr4,&DAT_005630d0,aiStack_324 + 0x89);
    List_Add(&DAT_0057c590,uptr4);
    value3 = Resource_ReadLine(DAT_0057c5d8,(uint8_t *)(aiStack_324 + 0x89),0x100,(intptr_t)ptr2);
  }
  Resource_Close(DAT_0057c5d8,(intptr_t)ptr2);
  DAT_0057c5f0 = (void *)0x0;
LAB_00405377:
  DVar5 = WaitForSingleObject(DAT_0057c0d8,10);
  if (DVar5 == 0) {
    Game_ShutdownSubsystems();
    if (DAT_0057ba10 != (uint32_t *)0x0) {
      (**(code **)*DAT_0057ba10)(1);
    }
    if (DAT_0057c5cc != (uint32_t *)0x0) {
      (**(code **)*DAT_0057c5cc)(1);
    }
    DAT_0057c5cc = (uint32_t *)0x0;
    return;
  }
  if (DAT_0056386c != 0) {
    DAT_0057c5b8 = DAT_0056386c;
  }
  switch(DAT_0056386c) {
  case 0x15:
    Game_GenerateRandomPlayers();
    if (cptr6 != (char *)0x0) {
      Window_DestroyChild(DAT_0057c5e0,(uint32_t *)cptr6);
    }
    cptr6 = Screen_MainMenu(aiStack_324 + 0x88);
    break;
  case 0x16:
    if (cptr6 != (char *)0x0) {
      Window_DestroyChild(DAT_0057c5e0,(uint32_t *)cptr6);
    }
    ptr2 = aiStack_324 + 0x88;
    cptr6 = Screen_MissionBriefing(ptr2);
    Screen_MissionBriefing_Populate
              (cptr6,ptr2,unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX,in_stack_fffffefc,
               in_stack_ffffff00,in_stack_ffffff04,in_stack_ffffff08,in_stack_ffffff0c,
               in_stack_ffffff10,in_stack_ffffff14,in_stack_ffffff18,in_stack_ffffff1c,
               in_stack_ffffff20,in_stack_ffffff24,in_stack_ffffff28,in_stack_ffffff2c,
               in_stack_ffffff30,in_stack_ffffff34,in_stack_ffffff38,in_stack_ffffff3c,
               in_stack_ffffff40,in_stack_ffffff44,in_stack_ffffff48,in_stack_ffffff4c,
               in_stack_ffffff50,in_stack_ffffff54,in_stack_ffffff58,in_stack_ffffff5c,
               in_stack_ffffff60,in_stack_ffffff64,in_stack_ffffff68,in_stack_ffffff6c,
               in_stack_ffffff70,in_stack_ffffff74,in_stack_ffffff78,in_stack_ffffff7c,
               in_stack_ffffff80,in_stack_ffffff84,in_stack_ffffff88,in_stack_ffffff8c,
               in_stack_ffffff90,in_stack_ffffff94,in_stack_ffffff98,in_stack_ffffff9c,
               in_stack_ffffffa0,in_stack_ffffffa4,in_stack_ffffffa8,in_stack_ffffffac,
               in_stack_ffffffb0,in_stack_ffffffb4,in_stack_ffffffb8,in_stack_ffffffbc,
               in_stack_ffffffc0,in_stack_ffffffc4,in_stack_ffffffc8,in_stack_ffffffcc,
               in_stack_ffffffd0,in_stack_ffffffd4,in_stack_ffffffd8,in_stack_ffffffdc,
               in_stack_ffffffe0,in_stack_ffffffe4,in_stack_ffffffe8,in_stack_ffffffec,
               in_stack_fffffff0,in_stack_fffffff4,in_stack_fffffff8,in_stack_fffffffc,unaff_retaddr
               ,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,
               arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,
               arg20,arg21,arg22,arg23,arg24,arg25,arg26,arg27);
    break;
  case 0x17:
    if (cptr6 != (char *)0x0) {
      Window_DestroyChild(DAT_0057c5e0,(uint32_t *)cptr6);
    }
    DAT_0057c5c0 = 0;
    Game_RunSession();
    DAT_0057c5c0 = 0;
    cptr6 = (char *)0x0;
    Window_ProcessMessageQueue(DAT_0057c5e0,1);
    goto LAB_00405377;
  case 0x18:
    if (cptr6 != (char *)0x0) {
      Window_DestroyChild(DAT_0057c5e0,(uint32_t *)cptr6);
    }
    cptr6 = Screen_FreePlaySetup(aiStack_324 + 0x88);
    FreePlaySetup_InitWindow(cptr6);
    break;
  case 0x19:
    if (DAT_0057c5f0 != (void *)0x0) goto switchD_004053a3_default;
    DAT_0057c5f0 = Screen_SubStartMenu_A(aiStack_324 + 0x88);
    SubStartMenuA_InitSaveGamePage(DAT_0057c5f0);
    break;
  case 0x1a:
    goto switchD_004053a3_caseD_1a;
  case 0x1b:
    if (DAT_0057c5f0 != (void *)0x0) goto switchD_004053a3_default;
    DAT_0057c5f0 = Screen_SubStartMenu_B(aiStack_324 + 0x88);
    SubStartMenu_FillOptions(DAT_0057c5f0);
    break;
  case 0x1c:
    if (cptr6 != (char *)0x0) {
      Window_DestroyChild(DAT_0057c5e0,(uint32_t *)cptr6);
    }
    cptr6 = Screen_CharacterSelect(aiStack_324 + 0x88);
    CharacterSelect_UpdateScreen(cptr6);
    break;
  case 0x1d:
    Screen_CloseSubStartMenu();
    if (cptr6 != (char *)0x0) {
      Window_DestroyChild(DAT_0057c5e0,(uint32_t *)cptr6);
    }
    Window_ProcessMessageQueue(DAT_0057c5e0,1);
    if ((char)DAT_0057bb54 != '\0') {
      Game_RunSession();
    }
  default:
switchD_004053a3_default:
    Window_ProcessMessageQueue(DAT_0057c5e0,1);
    goto LAB_00405377;
  }
  Window_ShowWindowById(DAT_0057c5e0,in_stack_fffffefc);
  DAT_0056386c = 0;
  Window_ProcessMessageQueue(DAT_0057c5e0,1);
  goto LAB_00405377;
switchD_004053a3_caseD_1a:
  if (cptr6 != (char *)0x0) {
    Window_DestroyChild(DAT_0057c5e0,(uint32_t *)cptr6);
  }
  cptr6 = (char *)0x0;
  DAT_0056386c = 0;
  Window_ProcessMessageQueue(DAT_0057c5e0,1);
  goto LAB_00405377;
}
