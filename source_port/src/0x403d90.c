// WinMain: ported from Pizza Connection 2 at 0x403d90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403d90
#include "pc2_port.h"

uint32_t WinMain(uint32_t arg1,uint32_t arg2,int arg3)

{
  int value1;
  char cVar2;
  ATOM AVar3;
  DWORD DVar4;
  HCURSOR pHVar5;
  HGDIOBJ pvVar6;
  LPSTR pCVar7;
  char *cptr8;
  DWORD DVar9;
  void *pvVar10;
  uint32_t *uptr11;
  uint32_t uvalue12;
  uint32_t uvalue13;
  int value14;
  uint32_t unaff_EBX;
  char *unaff_EBP;
  uint32_t unaff_ESI;
  int value15;
  int unaff_EDI;
  char *cptr16;
  char *cptr17;
  WNDCLASSA aWStackY_1684 [128];
  int in_stack_fffffdc8;
  uint32_t uvalue18;
  code *cptr19;
  uint32_t uvalue20;
  int value21;
  char *cptr22;
  char *cptr23;
  char *cptr24;
  uint32_t in_stack_fffffdf4;
  int in_stack_fffffdf8;
  uint32_t in_stack_fffffdfc;
  char *in_stack_fffffe00;
  uint32_t in_stack_fffffe04;
  int in_stack_fffffe08;
  uint32_t in_stack_fffffe0c;
  char *in_stack_fffffe10;
  uint32_t in_stack_fffffe14;
  int in_stack_fffffe18;
  char acStack_1e2 [2];
  uint32_t auStack_1e0 [55];
  char acStack_104 [260];
  
  DVar4 = timeGetTime();
  CRT_Srand(DVar4);
  DAT_0057c0d8 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  DAT_0057c5ac = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_0057b788);
  uvalue18 = 0;
  DAT_0057b8a4 = arg1;
  cptr19 = Window_DefaultProc;
  uvalue20 = 0;
  value21 = 0;
  cptr22 = (char *)0x0;
  pHVar5 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  pvVar6 = GetStockObject(4);
  cptr23 = s_Pizza_Connection_2_00563a28;
  cptr24 = s_Pizza_Connection_2_00563a28;
  AVar3 = RegisterClassA(aWStackY_1684 + 0x82);
  if (AVar3 == 0) {
    NoOp_Stub();
  }
  Settings_InitDefaults();
  pCVar7 = GetCommandLineA();
  if (*pCVar7 == '\"') {
    uvalue12 = 0xffffffff;
    cptr8 = pCVar7 + 1;
    do {
      cptr17 = cptr8;
      if (uvalue12 == 0) break;
      uvalue12 = uvalue12 - 1;
      cptr17 = cptr8 + 1;
      cVar2 = *cptr8;
      cptr8 = cptr17;
    } while (cVar2 != '\0');
    uvalue12 = ~uvalue12;
    cptr8 = cptr17 + -uvalue12;
    cptr17 = (char *)&DAT_0057c37c;
    for (uvalue13 = uvalue12 >> 2; uvalue13 != 0; uvalue13 = uvalue13 - 1) {
      *(uint32_t *)cptr17 = *(uint32_t *)cptr8;
      cptr8 = cptr8 + 4;
      cptr17 = cptr17 + 4;
    }
    for (uvalue12 = uvalue12 & 3; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
      *cptr17 = *cptr8;
      cptr8 = cptr8 + 1;
      cptr17 = cptr17 + 1;
    }
    cptr8 = _strchr((char *)&DAT_0057c37c,0x22);
  }
  else {
    uvalue12 = 0xffffffff;
    do {
      cptr8 = pCVar7;
      if (uvalue12 == 0) break;
      uvalue12 = uvalue12 - 1;
      cptr8 = pCVar7 + 1;
      cVar2 = *pCVar7;
      pCVar7 = cptr8;
    } while (cVar2 != '\0');
    uvalue12 = ~uvalue12;
    cptr8 = cptr8 + -uvalue12;
    cptr17 = (char *)&DAT_0057c37c;
    for (uvalue13 = uvalue12 >> 2; uvalue13 != 0; uvalue13 = uvalue13 - 1) {
      *(uint32_t *)cptr17 = *(uint32_t *)cptr8;
      cptr8 = cptr8 + 4;
      cptr17 = cptr17 + 4;
    }
    for (uvalue12 = uvalue12 & 3; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
      *cptr17 = *cptr8;
      cptr8 = cptr8 + 1;
      cptr17 = cptr17 + 1;
    }
    cptr8 = _strchr((char *)&DAT_0057c37c,0x22);
  }
  if (cptr8 != (char *)0x0) {
    *cptr8 = '\0';
  }
  File_ReadHeaderDwords
            ((LPCSTR)&DAT_0057c37c,(uint32_t *)(acStack_1e2 + -0x2a),(uint32_t *)&DAT_0057c484);
  uvalue12 = 0xffffffff;
  cptr8 = (char *)&DAT_0057c37c;
  do {
    if (uvalue12 == 0) break;
    uvalue12 = uvalue12 - 1;
    cVar2 = *cptr8;
    cptr8 = cptr8 + 1;
  } while (cVar2 != '\0');
  for (value14 = ~uvalue12 - 2;
      ((0 < value14 && (*(char *)((intptr_t)&DAT_0057c37c + value14) != ':')) &&
      (*(char *)((intptr_t)&DAT_0057c37c + value14) != '\\')); value14 = value14 + -1) {
  }
  *(uint8_t *)((intptr_t)&DAT_0057c37c + value14 + 1) = 0;
  uvalue12 = 0xffffffff;
  cptr8 = (char *)&DAT_0057c37c;
  do {
    if (uvalue12 == 0) break;
    uvalue12 = uvalue12 - 1;
    cVar2 = *cptr8;
    cptr8 = cptr8 + 1;
  } while (cVar2 != '\0');
  if (2 < ~uvalue12 - 1) {
    uvalue12 = 0xffffffff;
    cptr8 = (char *)&DAT_0057c37c;
    do {
      if (uvalue12 == 0) break;
      uvalue12 = uvalue12 - 1;
      cVar2 = *cptr8;
      cptr8 = cptr8 + 1;
    } while (cVar2 != '\0');
    if ((&DAT_0057c37a)[~uvalue12] != '\\') {
      uvalue12 = 0xffffffff;
      cptr8 = &DAT_00563278;
      do {
        cptr17 = cptr8;
        if (uvalue12 == 0) break;
        uvalue12 = uvalue12 - 1;
        cptr17 = cptr8 + 1;
        cVar2 = *cptr8;
        cptr8 = cptr17;
      } while (cVar2 != '\0');
      uvalue12 = ~uvalue12;
      value14 = -1;
      cptr8 = (char *)&DAT_0057c37c;
      do {
        cptr16 = cptr8;
        if (value14 == 0) break;
        value14 = value14 + -1;
        cptr16 = cptr8 + 1;
        cVar2 = *cptr8;
        cptr8 = cptr16;
      } while (cVar2 != '\0');
      cptr8 = cptr17 + -uvalue12;
      cptr17 = cptr16 + -1;
      for (uvalue13 = uvalue12 >> 2; uvalue13 != 0; uvalue13 = uvalue13 - 1) {
        *(uint32_t *)cptr17 = *(uint32_t *)cptr8;
        cptr8 = cptr8 + 4;
        cptr17 = cptr17 + 4;
      }
      for (uvalue12 = uvalue12 & 3; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
        *cptr17 = *cptr8;
        cptr8 = cptr8 + 1;
        cptr17 = cptr17 + 1;
      }
    }
  }
  uvalue12 = 0xffffffff;
  cptr8 = (char *)&DAT_0057c37c;
  do {
    cptr17 = cptr8;
    if (uvalue12 == 0) break;
    uvalue12 = uvalue12 - 1;
    cptr17 = cptr8 + 1;
    cVar2 = *cptr8;
    cptr8 = cptr17;
  } while (cVar2 != '\0');
  uvalue12 = ~uvalue12;
  cptr8 = cptr17 + -uvalue12;
  cptr17 = (char *)&DAT_0057c278;
  for (uvalue13 = uvalue12 >> 2; uvalue13 != 0; uvalue13 = uvalue13 - 1) {
    *(uint32_t *)cptr17 = *(uint32_t *)cptr8;
    cptr8 = cptr8 + 4;
    cptr17 = cptr17 + 4;
  }
  for (uvalue12 = uvalue12 & 3; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
    *cptr17 = *cptr8;
    cptr8 = cptr8 + 1;
    cptr17 = cptr17 + 1;
  }
  uvalue12 = 0xffffffff;
  cptr8 = (char *)&DAT_0057c278;
  do {
    if (uvalue12 == 0) break;
    uvalue12 = uvalue12 - 1;
    cVar2 = *cptr8;
    cptr8 = cptr8 + 1;
  } while (cVar2 != '\0');
  if (2 < ~uvalue12 - 1) {
    uvalue12 = 0xffffffff;
    cptr8 = (char *)&DAT_0057c278;
    do {
      if (uvalue12 == 0) break;
      uvalue12 = uvalue12 - 1;
      cVar2 = *cptr8;
      cptr8 = cptr8 + 1;
    } while (cVar2 != '\0');
    if ((&DAT_0057c276)[~uvalue12] != '\\') {
      uvalue12 = 0xffffffff;
      cptr8 = &DAT_00563278;
      do {
        cptr17 = cptr8;
        if (uvalue12 == 0) break;
        uvalue12 = uvalue12 - 1;
        cptr17 = cptr8 + 1;
        cVar2 = *cptr8;
        cptr8 = cptr17;
      } while (cVar2 != '\0');
      uvalue12 = ~uvalue12;
      value14 = -1;
      cptr8 = (char *)&DAT_0057c278;
      do {
        cptr16 = cptr8;
        if (value14 == 0) break;
        value14 = value14 + -1;
        cptr16 = cptr8 + 1;
        cVar2 = *cptr8;
        cptr8 = cptr16;
      } while (cVar2 != '\0');
      cptr8 = cptr17 + -uvalue12;
      cptr17 = cptr16 + -1;
      for (uvalue13 = uvalue12 >> 2; uvalue13 != 0; uvalue13 = uvalue13 - 1) {
        *(uint32_t *)cptr17 = *(uint32_t *)cptr8;
        cptr8 = cptr8 + 4;
        cptr17 = cptr17 + 4;
      }
      for (uvalue12 = uvalue12 & 3; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
        *cptr17 = *cptr8;
        cptr8 = cptr8 + 1;
        cptr17 = cptr17 + 1;
      }
    }
  }
  value14 = FUN_00557b12((LPCSTR)&DAT_0057c278);
  if (value14 == -1) {
    NoOp_Stub();
  }
  FUN_00557ae6(&DAT_005639dc);
  value14 = FUN_00557b12(&DAT_005639dc);
  if (value14 != -1) {
    FUN_00557ae6(s_Games_005639d4);
    FUN_00557ae6(&DAT_005639cc);
    FUN_00557ae6(&DAT_005639c8);
    FUN_00557b12(&DAT_005639c4);
  }
  value14 = 0;
  while (arg3 != 0) {
    cVar2 = *(char *)(value14 + arg3);
    value15 = value14;
    if (cVar2 < ' ') break;
    while (cVar2 == ' ') {
      cVar2 = *(char *)(value15 + 1 + arg3);
      value15 = value15 + 1;
    }
    cVar2 = *(char *)(value15 + arg3);
    value14 = value15;
    if (cVar2 == '\"') {
      value15 = value15 + 1;
      cVar2 = *(char *)(value15 + arg3);
      value14 = value15;
      while (('\x1f' < cVar2 && (cVar2 != '\"'))) {
        value1 = value14 + 1;
        value14 = value14 + 1;
        cVar2 = *(char *)(value1 + arg3);
      }
    }
    else {
      while (' ' < cVar2) {
        if (*(char *)(value14 + arg3) == '\"') {
          cVar2 = *(char *)(value14 + 1 + arg3);
          value1 = value14;
          while ((value14 = value1 + 1, '\x1f' < cVar2 && (cVar2 != '\"'))) {
            cVar2 = *(char *)(value1 + 2 + arg3);
            value1 = value14;
          }
        }
        cVar2 = *(char *)(value14 + 1 + arg3);
        value14 = value14 + 1;
      }
    }
    uvalue12 = value14 - value15;
    if (uvalue12 == 0) break;
    if (0x103 < (intptr_t)uvalue12) {
      uvalue12 = 0x103;
    }
    cptr8 = (char *)(value15 + arg3);
    cptr17 = acStack_1e2 + -0x26;
    for (uvalue13 = uvalue12 >> 2; uvalue13 != 0; uvalue13 = uvalue13 - 1) {
      *(uint32_t *)cptr17 = *(uint32_t *)cptr8;
      cptr8 = cptr8 + 4;
      cptr17 = cptr17 + 4;
    }
    for (uvalue13 = uvalue12 & 3; uvalue13 != 0; uvalue13 = uvalue13 - 1) {
      *cptr17 = *cptr8;
      cptr8 = cptr8 + 1;
      cptr17 = cptr17 + 1;
    }
    acStack_1e2[uvalue12 - 0x26] = '\0';
    uvalue12 = 0xffffffff;
    cptr8 = acStack_1e2 + -0x26;
    do {
      cptr17 = cptr8;
      if (uvalue12 == 0) break;
      uvalue12 = uvalue12 - 1;
      cptr17 = cptr8 + 1;
      cVar2 = *cptr8;
      cptr8 = cptr17;
    } while (cVar2 != '\0');
    uvalue12 = ~uvalue12;
    cptr8 = cptr17 + -uvalue12;
    cptr17 = (char *)&DAT_0057b7a0;
    for (uvalue13 = uvalue12 >> 2; uvalue13 != 0; uvalue13 = uvalue13 - 1) {
      *(uint32_t *)cptr17 = *(uint32_t *)cptr8;
      cptr8 = cptr8 + 4;
      cptr17 = cptr17 + 4;
    }
    for (uvalue12 = uvalue12 & 3; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
      *cptr17 = *cptr8;
      cptr8 = cptr8 + 1;
      cptr17 = cptr17 + 1;
    }
  }
  DAT_0057c5d0 = (HWND)0x0;
  ResourceManager_Init();
  SetScreenRects();
  Language_LoadLDF();
  DAT_0057c480 = 0;
  CRT_BeginThread(0x4047b0,0,0);
  DVar4 = timeGetTime();
  while (DAT_0057c5d4 == 0) {
    DVar9 = timeGetTime();
    if (DVar4 + 1000000 < DVar9) {
      DAT_0057c480 = 1;
      NoOp_Stub();
    }
    Sleep(5);
  }
  DAT_0057c5c4 = '\0';
  Movie_Play(0,s_s2000_s_bik_00563990);
  value14 = _rand();
  Movie_Play(0,(&PTR_s_intro_bombe_s_bik_00563844)[value14 % 7]);
  DAT_0056b40c = 1;
  pvVar10 = operator_new(0x11c);
  if (pvVar10 == (void *)0x0) {
    uptr11 = (uint32_t *)0x0;
  }
  else {
    uptr11 = FullscreenImage_Load
                        (pvVar10,s_Pe_loading_tga_00563980,DAT_0057c5c8,DAT_0057c5d8,
                         &aWStackY_1684[0x81].lpszClassName,(uint8_t *)0x0);
  }
  if (in_stack_fffffdc8 != 0) {
    if (uptr11 != (uint32_t *)0x0) {
      (**(code **)*uptr11)(1);
    }
    uptr11 = (uint32_t *)0x0;
  }
  UI_ReplaceActiveObject(DAT_0057c5e0,uptr11);
  String_Format(&DAT_0057ba18,(uint8_t *)s__c___s_00563968,(intptr_t)DAT_0057c5c4);
  UI_ShowLoadingOverlay(0);
  pvVar10 = operator_new(0x2f890);
  if (pvVar10 == (void *)0x0) {
    DAT_0057c5cc = (uint32_t *)0x0;
  }
  else {
    DAT_0057c5cc = Game_Construct(pvVar10,DAT_0057c5dc);
  }
  DVar4 = WaitForSingleObject(DAT_0057c0d8,0);
  if (DVar4 == 0) {
    Game_ShutdownSubsystems();
    CRT_Exit(0);
  }
  Map_LoadIsodata((intptr_t)DAT_0057c5cc);
  DVar4 = WaitForSingleObject(DAT_0057c0d8,0);
  if (DVar4 == 0) {
    Game_ShutdownSubsystems();
    CRT_Exit(0);
  }
  *(uint8_t *)(DAT_0057c5cc + 0xafd2) = (uint8_t)DAT_0057b9dc;
  DAT_0056b40c = 0;
  if (in_stack_fffffdc8 != 0) {
    NoOp_Stub();
    DestroyWindow(DAT_0057c5d0);
    DAT_0057c5d4 = 1;
    DAT_0057c480 = 1;
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0057b788);
    return 0;
  }
  UI_CloseLoadingScreen();
  String_Format(acStack_104,(uint8_t *)s_Names__s_txt_00563930,DAT_00582530);
  pvVar10 = operator_new(0x18);
  if (pvVar10 == (void *)0x0) {
    DAT_0057ba10 = (uint32_t *)0x0;
  }
  else {
    DAT_0057ba10 = FileObject_Open(pvVar10,DAT_0057c5d8,acStack_104,(uint32_t *)0x0);
  }
  if ((DAT_0057c1f0 == 0) || (DAT_0057c1f4 == 0)) {
    Window_MoveToSidePanel((intptr_t)DAT_0057c1e0);
  }
  GameMain(unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX,in_stack_fffffdc8,uvalue18,(char *)cptr19,uvalue20,
           value21,arg1,cptr22,pHVar5,(intptr_t)pvVar6,cptr23,cptr24,in_stack_fffffdf4,
           in_stack_fffffdf8,in_stack_fffffdfc,in_stack_fffffe00,in_stack_fffffe04,in_stack_fffffe08
           ,in_stack_fffffe0c,in_stack_fffffe10,in_stack_fffffe14,in_stack_fffffe18);
  NoOp_Stub();
  Config_SaveOptionsToRegistry();
  if (DAT_0057c5d8 != (uint32_t *)0x0) {
    (**(code **)*DAT_0057c5d8)(1);
  }
  if (DAT_0057c5dc != (uint32_t *)0x0) {
    (**(code **)*DAT_0057c5dc)(1);
  }
  Profiler_DumpReport();
  if (DAT_0057c1e0 != (uint32_t *)0x0) {
    (**(code **)*DAT_0057c1e0)(1);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0057b788);
  CloseHandle(DAT_0057c0d8);
  return 0;
}
