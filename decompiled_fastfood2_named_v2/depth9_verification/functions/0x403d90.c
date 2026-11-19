// rea decompile_all
// name: FUN_00403d90
// address: 0x403d90
// body: available
// range: 0x403d90-0x4043d0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00403d90(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  char cVar2;
  ATOM AVar3;
  DWORD DVar4;
  HCURSOR pHVar5;
  HGDIOBJ pvVar6;
  LPSTR pCVar7;
  char *pcVar8;
  DWORD DVar9;
  void *pvVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined4 unaff_EBX;
  char *unaff_EBP;
  undefined4 unaff_ESI;
  int iVar15;
  int unaff_EDI;
  char *pcVar16;
  char *pcVar17;
  WNDCLASSA aWStackY_1684 [128];
  int in_stack_fffffdc8;
  undefined4 uVar18;
  code *pcVar19;
  undefined4 uVar20;
  int iVar21;
  char *pcVar22;
  char *pcVar23;
  char *pcVar24;
  undefined4 in_stack_fffffdf4;
  int in_stack_fffffdf8;
  undefined4 in_stack_fffffdfc;
  char *in_stack_fffffe00;
  undefined4 in_stack_fffffe04;
  int in_stack_fffffe08;
  undefined4 in_stack_fffffe0c;
  char *in_stack_fffffe10;
  undefined4 in_stack_fffffe14;
  int in_stack_fffffe18;
  char acStack_1e2 [2];
  undefined4 auStack_1e0 [55];
  char acStack_104 [260];
  
  DVar4 = timeGetTime();
  CRT_Srand(DVar4);
  DAT_0057c0d8 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  DAT_0057c5ac = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_0057b788);
  uVar18 = 0;
  DAT_0057b8a4 = param_1;
  pcVar19 = FUN_00525270;
  uVar20 = 0;
  iVar21 = 0;
  pcVar22 = (char *)0x0;
  pHVar5 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  pvVar6 = GetStockObject(4);
  pcVar23 = s_Pizza_Connection_2_00563a28;
  pcVar24 = s_Pizza_Connection_2_00563a28;
  AVar3 = RegisterClassA(aWStackY_1684 + 0x82);
  if (AVar3 == 0) {
    FUN_0048e0a0();
  }
  FUN_00406a90();
  pCVar7 = GetCommandLineA();
  if (*pCVar7 == '\"') {
    uVar12 = 0xffffffff;
    pcVar8 = pCVar7 + 1;
    do {
      pcVar17 = pcVar8;
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      pcVar17 = pcVar8 + 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar17;
    } while (cVar2 != '\0');
    uVar12 = ~uVar12;
    pcVar8 = pcVar17 + -uVar12;
    pcVar17 = (char *)&DAT_0057c37c;
    for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      *pcVar17 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar17 = pcVar17 + 1;
    }
    pcVar8 = _strchr((char *)&DAT_0057c37c,0x22);
  }
  else {
    uVar12 = 0xffffffff;
    do {
      pcVar8 = pCVar7;
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      pcVar8 = pCVar7 + 1;
      cVar2 = *pCVar7;
      pCVar7 = pcVar8;
    } while (cVar2 != '\0');
    uVar12 = ~uVar12;
    pcVar8 = pcVar8 + -uVar12;
    pcVar17 = (char *)&DAT_0057c37c;
    for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      *pcVar17 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar17 = pcVar17 + 1;
    }
    pcVar8 = _strchr((char *)&DAT_0057c37c,0x22);
  }
  if (pcVar8 != (char *)0x0) {
    *pcVar8 = '\0';
  }
  File_ReadHeaderDwords
            ((LPCSTR)&DAT_0057c37c,(undefined4 *)(acStack_1e2 + -0x2a),(undefined4 *)&DAT_0057c484);
  uVar12 = 0xffffffff;
  pcVar8 = (char *)&DAT_0057c37c;
  do {
    if (uVar12 == 0) break;
    uVar12 = uVar12 - 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  for (iVar14 = ~uVar12 - 2;
      ((0 < iVar14 && (*(char *)((int)&DAT_0057c37c + iVar14) != ':')) &&
      (*(char *)((int)&DAT_0057c37c + iVar14) != '\\')); iVar14 = iVar14 + -1) {
  }
  *(undefined1 *)((int)&DAT_0057c37c + iVar14 + 1) = 0;
  uVar12 = 0xffffffff;
  pcVar8 = (char *)&DAT_0057c37c;
  do {
    if (uVar12 == 0) break;
    uVar12 = uVar12 - 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  if (2 < ~uVar12 - 1) {
    uVar12 = 0xffffffff;
    pcVar8 = (char *)&DAT_0057c37c;
    do {
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    if ((&DAT_0057c37a)[~uVar12] != '\\') {
      uVar12 = 0xffffffff;
      pcVar8 = &DAT_00563278;
      do {
        pcVar17 = pcVar8;
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        pcVar17 = pcVar8 + 1;
        cVar2 = *pcVar8;
        pcVar8 = pcVar17;
      } while (cVar2 != '\0');
      uVar12 = ~uVar12;
      iVar14 = -1;
      pcVar8 = (char *)&DAT_0057c37c;
      do {
        pcVar16 = pcVar8;
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        pcVar16 = pcVar8 + 1;
        cVar2 = *pcVar8;
        pcVar8 = pcVar16;
      } while (cVar2 != '\0');
      pcVar8 = pcVar17 + -uVar12;
      pcVar17 = pcVar16 + -1;
      for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar17 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar17 = pcVar17 + 1;
      }
    }
  }
  uVar12 = 0xffffffff;
  pcVar8 = (char *)&DAT_0057c37c;
  do {
    pcVar17 = pcVar8;
    if (uVar12 == 0) break;
    uVar12 = uVar12 - 1;
    pcVar17 = pcVar8 + 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar17;
  } while (cVar2 != '\0');
  uVar12 = ~uVar12;
  pcVar8 = pcVar17 + -uVar12;
  pcVar17 = (char *)&DAT_0057c278;
  for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *pcVar17 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar17 = pcVar17 + 1;
  }
  uVar12 = 0xffffffff;
  pcVar8 = (char *)&DAT_0057c278;
  do {
    if (uVar12 == 0) break;
    uVar12 = uVar12 - 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  if (2 < ~uVar12 - 1) {
    uVar12 = 0xffffffff;
    pcVar8 = (char *)&DAT_0057c278;
    do {
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    if ((&DAT_0057c276)[~uVar12] != '\\') {
      uVar12 = 0xffffffff;
      pcVar8 = &DAT_00563278;
      do {
        pcVar17 = pcVar8;
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        pcVar17 = pcVar8 + 1;
        cVar2 = *pcVar8;
        pcVar8 = pcVar17;
      } while (cVar2 != '\0');
      uVar12 = ~uVar12;
      iVar14 = -1;
      pcVar8 = (char *)&DAT_0057c278;
      do {
        pcVar16 = pcVar8;
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        pcVar16 = pcVar8 + 1;
        cVar2 = *pcVar8;
        pcVar8 = pcVar16;
      } while (cVar2 != '\0');
      pcVar8 = pcVar17 + -uVar12;
      pcVar17 = pcVar16 + -1;
      for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar17 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar17 = pcVar17 + 1;
      }
    }
  }
  iVar14 = FUN_00557b12((LPCSTR)&DAT_0057c278);
  if (iVar14 == -1) {
    FUN_0048e0a0();
  }
  FUN_00557ae6(&DAT_005639dc);
  iVar14 = FUN_00557b12(&DAT_005639dc);
  if (iVar14 != -1) {
    FUN_00557ae6(s_Games_005639d4);
    FUN_00557ae6(&DAT_005639cc);
    FUN_00557ae6(&DAT_005639c8);
    FUN_00557b12(&DAT_005639c4);
  }
  iVar14 = 0;
  while (param_3 != 0) {
    cVar2 = *(char *)(iVar14 + param_3);
    iVar15 = iVar14;
    if (cVar2 < ' ') break;
    while (cVar2 == ' ') {
      cVar2 = *(char *)(iVar15 + 1 + param_3);
      iVar15 = iVar15 + 1;
    }
    cVar2 = *(char *)(iVar15 + param_3);
    iVar14 = iVar15;
    if (cVar2 == '\"') {
      iVar15 = iVar15 + 1;
      cVar2 = *(char *)(iVar15 + param_3);
      iVar14 = iVar15;
      while (('\x1f' < cVar2 && (cVar2 != '\"'))) {
        iVar1 = iVar14 + 1;
        iVar14 = iVar14 + 1;
        cVar2 = *(char *)(iVar1 + param_3);
      }
    }
    else {
      while (' ' < cVar2) {
        if (*(char *)(iVar14 + param_3) == '\"') {
          cVar2 = *(char *)(iVar14 + 1 + param_3);
          iVar1 = iVar14;
          while ((iVar14 = iVar1 + 1, '\x1f' < cVar2 && (cVar2 != '\"'))) {
            cVar2 = *(char *)(iVar1 + 2 + param_3);
            iVar1 = iVar14;
          }
        }
        cVar2 = *(char *)(iVar14 + 1 + param_3);
        iVar14 = iVar14 + 1;
      }
    }
    uVar12 = iVar14 - iVar15;
    if (uVar12 == 0) break;
    if (0x103 < (int)uVar12) {
      uVar12 = 0x103;
    }
    pcVar8 = (char *)(iVar15 + param_3);
    pcVar17 = acStack_1e2 + -0x26;
    for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar13 = uVar12 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar17 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar17 = pcVar17 + 1;
    }
    acStack_1e2[uVar12 - 0x26] = '\0';
    uVar12 = 0xffffffff;
    pcVar8 = acStack_1e2 + -0x26;
    do {
      pcVar17 = pcVar8;
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      pcVar17 = pcVar8 + 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar17;
    } while (cVar2 != '\0');
    uVar12 = ~uVar12;
    pcVar8 = pcVar17 + -uVar12;
    pcVar17 = (char *)&DAT_0057b7a0;
    for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      *pcVar17 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  DAT_0057c5d0 = (HWND)0x0;
  FUN_00404500();
  FUN_00404420();
  FUN_005145a0();
  DAT_0057c480 = 0;
  FUN_0054f167(0x4047b0,0,0);
  DVar4 = timeGetTime();
  while (DAT_0057c5d4 == 0) {
    DVar9 = timeGetTime();
    if (DVar4 + 1000000 < DVar9) {
      DAT_0057c480 = 1;
      FUN_0048e0a0();
    }
    Sleep(5);
  }
  DAT_0057c5c4 = '\0';
  FUN_004ce9d0(0,s_s2000_s_bik_00563990);
  iVar14 = _rand();
  FUN_004ce9d0(0,(&PTR_s_intro_bombe_s_bik_00563844)[iVar14 % 7]);
  DAT_0056b40c = 1;
  pvVar10 = operator_new(0x11c);
  if (pvVar10 == (void *)0x0) {
    puVar11 = (undefined4 *)0x0;
  }
  else {
    puVar11 = FUN_00535fc0(pvVar10,s_Pe_loading_tga_00563980,DAT_0057c5c8,DAT_0057c5d8,
                           &aWStackY_1684[0x81].lpszClassName,(undefined *)0x0);
  }
  if (in_stack_fffffdc8 != 0) {
    if (puVar11 != (undefined4 *)0x0) {
      (**(code **)*puVar11)(1);
    }
    puVar11 = (undefined4 *)0x0;
  }
  FUN_00523900(DAT_0057c5e0,puVar11);
  FUN_0054dd83(&DAT_0057ba18,(byte *)s__c___s_00563968,(int)DAT_0057c5c4);
  FUN_00406910(0);
  pvVar10 = operator_new(0x2f890);
  if (pvVar10 == (void *)0x0) {
    DAT_0057c5cc = (undefined4 *)0x0;
  }
  else {
    DAT_0057c5cc = FUN_004e64c0(pvVar10,DAT_0057c5dc);
  }
  DVar4 = WaitForSingleObject(DAT_0057c0d8,0);
  if (DVar4 == 0) {
    FUN_004055d0();
    FUN_0054f2dd(0);
  }
  FUN_004ea440((int)DAT_0057c5cc);
  DVar4 = WaitForSingleObject(DAT_0057c0d8,0);
  if (DVar4 == 0) {
    FUN_004055d0();
    FUN_0054f2dd(0);
  }
  *(undefined1 *)(DAT_0057c5cc + 0xafd2) = DAT_0057b9dc;
  DAT_0056b40c = 0;
  if (in_stack_fffffdc8 != 0) {
    FUN_0048e0a0();
    DestroyWindow(DAT_0057c5d0);
    DAT_0057c5d4 = 1;
    DAT_0057c480 = 1;
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0057b788);
    return 0;
  }
  FUN_00406a60();
  FUN_0054dd83(acStack_104,(byte *)s_Names__s_txt_00563930,DAT_00582530);
  pvVar10 = operator_new(0x18);
  if (pvVar10 == (void *)0x0) {
    DAT_0057ba10 = (undefined4 *)0x0;
  }
  else {
    DAT_0057ba10 = FUN_00402cf0(pvVar10,DAT_0057c5d8,acStack_104,(undefined4 *)0x0);
  }
  if ((DAT_0057c1f0 == 0) || (DAT_0057c1f4 == 0)) {
    FUN_0054a820((int)DAT_0057c1e0);
  }
  FUN_004043e0(unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX,in_stack_fffffdc8,uVar18,(char *)pcVar19,
               uVar20,iVar21,param_1,pcVar22,pHVar5,(int)pvVar6,pcVar23,pcVar24,in_stack_fffffdf4,
               in_stack_fffffdf8,in_stack_fffffdfc,in_stack_fffffe00,in_stack_fffffe04,
               in_stack_fffffe08,in_stack_fffffe0c,in_stack_fffffe10,in_stack_fffffe14,
               in_stack_fffffe18);
  FUN_0048e0a0();
  FUN_00406cd0();
  if (DAT_0057c5d8 != (undefined4 *)0x0) {
    (**(code **)*DAT_0057c5d8)(1);
  }
  if (DAT_0057c5dc != (undefined4 *)0x0) {
    (**(code **)*DAT_0057c5dc)(1);
  }
  FUN_004035d0();
  if (DAT_0057c1e0 != (undefined4 *)0x0) {
    (**(code **)*DAT_0057c1e0)(1);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0057b788);
  CloseHandle(DAT_0057c0d8);
  return 0;
}

