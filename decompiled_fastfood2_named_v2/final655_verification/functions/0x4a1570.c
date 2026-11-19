// rea decompile_all
// name: FUN_004a1570
// address: 0x4a1570
// body: available
// range: 0x4a1570-0x4a1930 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a1570(void *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  LPCSTR lpFileName;
  char *pcVar2;
  FILE *pFVar3;
  void *pvVar4;
  char *pcVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  CHAR *pCVar10;
  LPCSTR pCVar11;
  CHAR *pCVar12;
  char *pcVar13;
  undefined4 *local_630;
  char *local_62c;
  HANDLE local_628;
  int local_624;
  undefined4 local_618;
  undefined4 local_614;
  SYSTEMTIME local_610;
  char local_600 [128];
  undefined1 local_580 [88];
  SYSTEMTIME local_528;
  int local_514;
  char local_510 [63];
  undefined1 local_4d1;
  CHAR local_4d0 [64];
  CHAR local_490 [64];
  char local_450 [260];
  _WIN32_FIND_DATAA local_34c;
  char local_20c [512];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055885c;
  local_c = ExceptionList;
  local_630 = &local_618;
  local_62c = (char *)0x0;
  local_618 = param_2;
  local_614 = param_3;
  local_624 = 2;
  ExceptionList = &local_c;
  do {
    lpFileName = (LPCSTR)*local_630;
    if (lpFileName != (LPCSTR)0x0) {
      local_628 = FindFirstFileA(lpFileName,&local_34c);
      if (local_628 != (HANDLE)0xffffffff) {
        do {
          uVar7 = 0xffffffff;
          pCVar11 = lpFileName;
          do {
            pcVar2 = pCVar11;
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            pcVar2 = pCVar11 + 1;
            cVar1 = *pCVar11;
            pCVar11 = pcVar2;
          } while (cVar1 != '\0');
          uVar7 = ~uVar7;
          pcVar2 = pcVar2 + -uVar7;
          pcVar5 = local_450;
          for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar5 = *(undefined4 *)pcVar2;
            pcVar2 = pcVar2 + 4;
            pcVar5 = pcVar5 + 4;
          }
          for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *pcVar5 = *pcVar2;
            pcVar2 = pcVar2 + 1;
            pcVar5 = pcVar5 + 1;
          }
          pcVar2 = _strrchr(local_450,0x5c);
          if (pcVar2 != (char *)0x0) {
            pcVar2[1] = '\0';
          }
          uVar7 = 0xffffffff;
          pCVar10 = local_34c.cFileName;
          do {
            pCVar12 = pCVar10;
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            pCVar12 = pCVar10 + 1;
            cVar1 = *pCVar10;
            pCVar10 = pCVar12;
          } while (cVar1 != '\0');
          uVar7 = ~uVar7;
          iVar9 = -1;
          pcVar2 = local_450;
          do {
            pcVar5 = pcVar2;
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            pcVar5 = pcVar2 + 1;
            cVar1 = *pcVar2;
            pcVar2 = pcVar5;
          } while (cVar1 != '\0');
          pCVar10 = pCVar12 + -uVar7;
          pcVar2 = pcVar5 + -1;
          for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar2 = *(undefined4 *)pCVar10;
            pCVar10 = pCVar10 + 4;
            pcVar2 = pcVar2 + 4;
          }
          for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *pcVar2 = *pCVar10;
            pCVar10 = pCVar10 + 1;
            pcVar2 = pcVar2 + 1;
          }
          pFVar3 = (FILE *)FUN_0054dfe0(local_450,&DAT_00563184);
          if (pFVar3 != (FILE *)0x0) {
            FUN_0054e978(local_600,1,0xf0,(int *)pFVar3);
            FUN_0054dee4(pFVar3);
            if (local_514 == 0x13738317) {
              _strncpy(local_510,local_600,0x3f);
              local_4d1 = 0;
              GetDateFormatA(0x800,1,&local_528,(LPCSTR)0x0,local_4d0,0x40);
              GetTimeFormatA(0x800,2,&local_528,(LPCSTR)0x0,local_490,0x40);
              FUN_0054dd83(local_20c,(byte *)s__s____s__s__d__s__d__d__d__d__s___00568d34,local_580)
              ;
              uVar7 = 0xffffffff;
              pcVar2 = local_450;
              do {
                if (uVar7 == 0) break;
                uVar7 = uVar7 - 1;
                cVar1 = *pcVar2;
                pcVar2 = pcVar2 + 1;
              } while (cVar1 != '\0');
              pcVar5 = operator_new(~uVar7);
              uVar7 = 0xffffffff;
              pcVar2 = local_450;
              do {
                pcVar13 = pcVar2;
                if (uVar7 == 0) break;
                uVar7 = uVar7 - 1;
                pcVar13 = pcVar2 + 1;
                cVar1 = *pcVar2;
                pcVar2 = pcVar13;
              } while (cVar1 != '\0');
              uVar7 = ~uVar7;
              pcVar2 = pcVar13 + -uVar7;
              pcVar13 = pcVar5;
              for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *(undefined4 *)pcVar13 = *(undefined4 *)pcVar2;
                pcVar2 = pcVar2 + 4;
                pcVar13 = pcVar13 + 4;
              }
              for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                *pcVar13 = *pcVar2;
                pcVar2 = pcVar2 + 1;
                pcVar13 = pcVar13 + 1;
              }
              pvVar4 = operator_new(0x58);
              local_4 = 1;
              if (pvVar4 == (void *)0x0) {
                pcVar2 = (char *)0x0;
              }
              else {
                pcVar2 = UI_ListEntry_Construct(pvVar4,local_510,0);
              }
              local_4 = 0xffffffff;
              FUN_00403420(pcVar2,pcVar5);
              FUN_004033c0(pcVar2,local_20c);
              if (local_62c == (char *)0x0) {
LAB_004a187f:
                local_610.wYear = local_528.wYear;
                local_610.wMonth = local_528.wMonth;
                local_610.wDayOfWeek = local_528.wDayOfWeek;
                local_610.wDay = local_528.wDay;
                local_610.wHour = local_528.wHour;
                local_610.wMinute = local_528.wMinute;
                local_610.wSecond = local_528.wSecond;
                local_610.wMilliseconds = local_528.wMilliseconds;
                local_62c = pcVar2;
              }
              else {
                iVar9 = FUN_004a14c0(&local_610.wYear,&local_528.wYear);
                if (iVar9 == -1) goto LAB_004a187f;
              }
              FUN_004014b0(param_1,pcVar2);
              FUN_0054dd78(pcVar5);
            }
            else {
              pvVar4 = operator_new(0x58);
              local_4 = 0;
              if (pvVar4 == (void *)0x0) {
                pcVar2 = (char *)0x0;
              }
              else {
                pcVar2 = UI_ListEntry_Construct(pvVar4,DAT_00582d34,0xffffffff);
              }
              local_4 = 0xffffffff;
              FUN_004033c0(pcVar2,DAT_005814f0);
              FUN_004014b0(param_1,pcVar2);
            }
          }
          BVar6 = FindNextFileA(local_628,&local_34c);
        } while (BVar6 != 0);
      }
    }
    local_630 = local_630 + 1;
    local_624 = local_624 + -1;
    if (local_624 == 0) {
      FindClose(local_628);
      if (local_62c != (char *)0x0) {
        local_62c[0x54] = '\0';
        local_62c[0x55] = '\0';
        local_62c[0x56] = -1;
        local_62c[0x57] = '\0';
      }
      ExceptionList = local_c;
      return;
    }
  } while( true );
}

