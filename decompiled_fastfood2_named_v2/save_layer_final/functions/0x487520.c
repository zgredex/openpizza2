// rea decompile_all
// name: SaveGame_Write
// address: 0x487520
// body: available
// range: 0x487520-0x487934 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool __thiscall SaveGame_Write(void *param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  HCURSOR pHVar2;
  DWORD DVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  int *this;
  char *pcVar9;
  bool bVar10;
  uint local_1c4;
  char *local_1c0;
  CHAR local_1bc [64];
  char local_17c [64];
  char local_13c [64];
  char local_fc [64];
  char local_bc;
  undefined1 auStack_bb [7];
  uint local_b4;
  int local_b0;
  uint local_ac;
  uint local_a8;
  _SYSTEMTIME local_a4;
  undefined4 local_94;
  undefined4 local_90;
  CHAR local_8c [64];
  CHAR local_4c [64];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Writes a .piz save: builds the 0xF0 header, writes
                       title/company/city/slots/date, then calls SaveGame_Serialize. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055824c;
  pvStack_c = ExceptionList;
  iVar7 = 0;
  bVar10 = *(int *)((int)param_1 + 0x1508) == 0;
  ExceptionList = &pvStack_c;
  if (bVar10) {
    ExceptionList = &pvStack_c;
    FUN_00488cc0(param_1);
  }
  local_1c4 = (uint)bVar10;
  FUN_00486be0(param_1,0);
  pcVar8 = local_17c;
  for (iVar4 = 0x3c; iVar4 != 0; iVar4 = iVar4 + -1) {
    pcVar8[0] = '\0';
    pcVar8[1] = '\0';
    pcVar8[2] = '\0';
    pcVar8[3] = '\0';
    pcVar8 = pcVar8 + 4;
  }
  pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
  SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar2);
  PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar2);
  FUN_0048b3c0(param_1,&local_b4,&local_b0);
  FUN_0048b3f0(param_1,&local_ac,&local_a8);
  if (param_2 == (char *)0x0) {
    FUN_0054dd83(local_1bc,(byte *)s_save_games_auto__03d_piz_005681c0,param_3);
    GetDateFormatA(0x800,1,(SYSTEMTIME *)0x0,(LPCSTR)0x0,local_8c,0x40);
    GetTimeFormatA(0x800,2,(SYSTEMTIME *)0x0,(LPCSTR)0x0,local_4c,0x40);
    FUN_0054dd83(local_17c,(byte *)s_auto__s__s_005681b4,local_8c);
  }
  else {
    FUN_0054dd83(local_1bc,(byte *)s_save_games_save__03d_piz_00568198,param_3);
    uVar5 = 0xffffffff;
    do {
      pcVar8 = param_2;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = param_2 + 1;
      cVar1 = *param_2;
      param_2 = pcVar8;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar8 = pcVar8 + -uVar5;
    pcVar9 = local_17c;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  local_bc = '\0';
  local_90 = 0x13738317;
  local_94 = 0x11;
  GetLocalTime(&local_a4);
  do {
    iVar4 = FUN_00488be0(param_1,iVar7);
    if (iVar4 == 0) {
      auStack_bb[iVar7] = 0;
    }
    else {
      if (iVar4 == *(int *)((int)param_1 + *(int *)((int)param_1 + 0x2ec) * 4 + 0x200)) {
        uVar5 = 0xffffffff;
        auStack_bb[iVar7] = 1;
        pcVar8 = (char *)(iVar4 + 8);
        do {
          pcVar9 = pcVar8;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar9 = pcVar8 + 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar9;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        local_1c0 = local_13c;
        pcVar8 = pcVar9 + -uVar5;
        pcVar9 = local_1c0;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar9 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar9 = pcVar9 + 1;
        }
        iVar4 = FUN_004ddcc0(iVar4);
        uVar5 = 0xffffffff;
        pcVar8 = (char *)(iVar4 + 0xc);
        do {
          pcVar9 = pcVar8;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar9 = pcVar8 + 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar9;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        pcVar8 = pcVar9 + -uVar5;
        pcVar9 = local_fc;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar9 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar9 = pcVar9 + 1;
        }
      }
      else {
        auStack_bb[iVar7] = 2;
      }
      local_bc = local_bc + '\x01';
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 6);
  local_1c0 = operator_new(0x58);
  this = (int *)0x0;
  local_4 = 0;
  if (local_1c0 != (void *)0x0) {
    this = FUN_0054d140();
  }
  local_4 = 0xffffffff;
  if ((*(byte *)(*(int *)(*this + 4) + 8 + (int)this) & 6) != 0) {
    DVar3 = GetFileAttributesA(local_1bc);
    if ((DVar3 & 1) != 0) {
      if (this != (int *)0x0) {
        (*(code *)**(undefined4 **)(*(int *)(*this + 4) + (int)this))(1);
      }
      SetFileAttributesA(local_1bc,DVar3 & 0xfffffffe);
      local_1c0 = operator_new(0x58);
      local_4 = 1;
      if (local_1c0 == (void *)0x0) {
        this = (int *)0x0;
      }
      else {
        this = FUN_0054d140();
      }
      local_4 = 0xffffffff;
    }
    if ((*(byte *)(*(int *)(*this + 4) + 8 + (int)this) & 6) != 0) {
      pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
      SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar2);
      PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar2);
      FUN_00486e00((int)param_1);
      if (local_1c4 != 0) {
        FUN_00488d20(param_1);
      }
      if (this != (int *)0x0) {
        (*(code *)**(undefined4 **)(*(int *)(*this + 4) + (int)this))(1);
      }
      goto LAB_0048791a;
    }
  }
  FUN_0054cc2b(this,local_17c,0xf0);
  SaveGame_Serialize(param_1,this);
  if (this != (int *)0x0) {
    (*(code *)**(undefined4 **)(*(int *)(*this + 4) + (int)this))(1);
  }
  pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  SetClassLongA(DAT_0057c5d0,-0xc,(LONG)pHVar2);
  PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)pHVar2);
  FUN_00486e00((int)param_1);
  if (local_1c4 != 0) {
    FUN_00488d20(param_1);
  }
LAB_0048791a:
  ExceptionList = pvStack_c;
  return (undefined1 *)0xfffffe3b < &local_1c4;
}

