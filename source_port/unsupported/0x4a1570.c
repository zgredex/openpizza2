// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x4a1570.c:29:3: error: use of undeclared identifier 'SYSTEMTIME'
// SaveGame_ReadHeaderEntry: ported from Pizza Connection 2 at 0x4a1570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a1570
#include "pc2_port.h"

void __cdecl SaveGame_ReadHeaderEntry(void *arg1,uint32_t arg2,uint32_t arg3)

{
  char cVar1;
  LPCSTR lpFileName;
  char *cptr2;
  FILE *pFVar3;
  void *pvVar4;
  char *cptr5;
  BOOL BVar6;
  uint32_t uvalue7;
  uint32_t uvalue8;
  int value9;
  CHAR *pCVar10;
  LPCSTR pCVar11;
  CHAR *pCVar12;
  char *cptr13;
  uint32_t *local_630;
  char *local_62c;
  HANDLE local_628;
  int local_624;
  uint32_t local_618;
  uint32_t local_614;
  SYSTEMTIME local_610;
  char local_600 [128];
  uint8_t local_580 [88];
  SYSTEMTIME local_528;
  int local_514;
  char local_510 [63];
  uint8_t local_4d1;
  CHAR local_4d0 [64];
  CHAR local_490 [64];
  char local_450 [260];
  _WIN32_FIND_DATAA local_34c;
  char local_20c [512];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055885c;
  local_c = ExceptionList;
  local_630 = &local_618;
  local_62c = (char *)0x0;
  local_618 = arg2;
  local_614 = arg3;
  local_624 = 2;
  ExceptionList = &local_c;
  do {
    lpFileName = (LPCSTR)*local_630;
    if (lpFileName != (LPCSTR)0x0) {
      local_628 = FindFirstFileA(lpFileName,&local_34c);
      if (local_628 != (HANDLE)0xffffffff) {
        do {
          uvalue7 = 0xffffffff;
          pCVar11 = lpFileName;
          do {
            cptr2 = pCVar11;
            if (uvalue7 == 0) break;
            uvalue7 = uvalue7 - 1;
            cptr2 = pCVar11 + 1;
            cVar1 = *pCVar11;
            pCVar11 = cptr2;
          } while (cVar1 != '\0');
          uvalue7 = ~uvalue7;
          cptr2 = cptr2 + -uvalue7;
          cptr5 = local_450;
          for (uvalue8 = uvalue7 >> 2; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
            *(uint32_t *)cptr5 = *(uint32_t *)cptr2;
            cptr2 = cptr2 + 4;
            cptr5 = cptr5 + 4;
          }
          for (uvalue7 = uvalue7 & 3; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
            *cptr5 = *cptr2;
            cptr2 = cptr2 + 1;
            cptr5 = cptr5 + 1;
          }
          cptr2 = _strrchr(local_450,0x5c);
          if (cptr2 != (char *)0x0) {
            cptr2[1] = '\0';
          }
          uvalue7 = 0xffffffff;
          pCVar10 = local_34c.cFileName;
          do {
            pCVar12 = pCVar10;
            if (uvalue7 == 0) break;
            uvalue7 = uvalue7 - 1;
            pCVar12 = pCVar10 + 1;
            cVar1 = *pCVar10;
            pCVar10 = pCVar12;
          } while (cVar1 != '\0');
          uvalue7 = ~uvalue7;
          value9 = -1;
          cptr2 = local_450;
          do {
            cptr5 = cptr2;
            if (value9 == 0) break;
            value9 = value9 + -1;
            cptr5 = cptr2 + 1;
            cVar1 = *cptr2;
            cptr2 = cptr5;
          } while (cVar1 != '\0');
          pCVar10 = pCVar12 + -uvalue7;
          cptr2 = cptr5 + -1;
          for (uvalue8 = uvalue7 >> 2; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
            *(uint32_t *)cptr2 = *(uint32_t *)pCVar10;
            pCVar10 = pCVar10 + 4;
            cptr2 = cptr2 + 4;
          }
          for (uvalue7 = uvalue7 & 3; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
            *cptr2 = *pCVar10;
            pCVar10 = pCVar10 + 1;
            cptr2 = cptr2 + 1;
          }
          pFVar3 = (FILE *)CRT_Fopen(local_450,&DAT_00563184);
          if (pFVar3 != (FILE *)0x0) {
            CRT_FreadLocked(local_600,1,0xf0,(int *)pFVar3);
            CRT_Fclose(pFVar3);
            if (local_514 == 0x13738317) {
              _strncpy(local_510,local_600,0x3f);
              local_4d1 = 0;
              GetDateFormatA(0x800,1,&local_528,(LPCSTR)0x0,local_4d0,0x40);
              GetTimeFormatA(0x800,2,&local_528,(LPCSTR)0x0,local_490,0x40);
              String_Format(local_20c,(uint8_t *)s__s____s__s__d__s__d__d__d__d__s___00568d34,local_580
                           );
              uvalue7 = 0xffffffff;
              cptr2 = local_450;
              do {
                if (uvalue7 == 0) break;
                uvalue7 = uvalue7 - 1;
                cVar1 = *cptr2;
                cptr2 = cptr2 + 1;
              } while (cVar1 != '\0');
              cptr5 = operator_new(~uvalue7);
              uvalue7 = 0xffffffff;
              cptr2 = local_450;
              do {
                cptr13 = cptr2;
                if (uvalue7 == 0) break;
                uvalue7 = uvalue7 - 1;
                cptr13 = cptr2 + 1;
                cVar1 = *cptr2;
                cptr2 = cptr13;
              } while (cVar1 != '\0');
              uvalue7 = ~uvalue7;
              cptr2 = cptr13 + -uvalue7;
              cptr13 = cptr5;
              for (uvalue8 = uvalue7 >> 2; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
                *(uint32_t *)cptr13 = *(uint32_t *)cptr2;
                cptr2 = cptr2 + 4;
                cptr13 = cptr13 + 4;
              }
              for (uvalue7 = uvalue7 & 3; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
                *cptr13 = *cptr2;
                cptr2 = cptr2 + 1;
                cptr13 = cptr13 + 1;
              }
              pvVar4 = operator_new(0x58);
              local_4 = 1;
              if (pvVar4 == (void *)0x0) {
                cptr2 = (char *)0x0;
              }
              else {
                cptr2 = UI_ListEntry_Construct(pvVar4,local_510,0);
              }
              local_4 = 0xffffffff;
              String_SetField48(cptr2,cptr5);
              String_SetOwned(cptr2,local_20c);
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
                local_62c = cptr2;
              }
              else {
                value9 = SaveGame_CompareTime(&local_610.wYear,&local_528.wYear);
                if (value9 == -1) goto LAB_004a187f;
              }
              List_Add(arg1,cptr2);
              Mem_Free(cptr5);
            }
            else {
              pvVar4 = operator_new(0x58);
              local_4 = 0;
              if (pvVar4 == (void *)0x0) {
                cptr2 = (char *)0x0;
              }
              else {
                cptr2 = UI_ListEntry_Construct(pvVar4,DAT_00582d34,0xffffffff);
              }
              local_4 = 0xffffffff;
              String_SetOwned(cptr2,DAT_005814f0);
              List_Add(arg1,cptr2);
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
