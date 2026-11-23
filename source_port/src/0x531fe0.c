// Dialog_SaveToFile: ported from Pizza Connection 2 at 0x531fe0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531fe0
#include "pc2_port.h"

uint32_t __thiscall Dialog_SaveToFile(void *self,LPCSTR arg1)

{
  char cVar1;
  FILE *pFVar2;
  int value3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  char *cptr6;
  char *cptr7;
  uint32_t local_45c;
  int local_458;
  char local_454 [8];
  uint32_t local_44c;
  uint32_t local_448;
  uint32_t local_444;
  uint32_t local_440;
  uint32_t local_43c;
  uint32_t local_438;
  uint32_t local_434;
  char local_430 [1036];
  uint32_t local_24;
  uint32_t local_20;
  uint32_t local_1c;
  uint32_t local_18;
  
  pFVar2 = (FILE *)CRT_Fopen(arg1,&DAT_00563114);
  if (pFVar2 == (FILE *)0x0) {
    return 0;
  }
  local_458 = *(int *)((intptr_t)self + 0xf0) + 1;
  CRT_FwriteLocked((char *)&local_458,1,4,(int *)pFVar2);
  local_1c = *(uint32_t *)((intptr_t)self + 0x104);
  cptr6 = local_454;
  for (value3 = 0x115; value3 != 0; value3 = value3 + -1) {
    cptr6[0] = '\0';
    cptr6[1] = '\0';
    cptr6[2] = '\0';
    cptr6[3] = '\0';
    cptr6 = cptr6 + 4;
  }
  local_20 = *(uint32_t *)((intptr_t)self + 0x100);
  local_454[0] = 'T';
  local_454[1] = '\x04';
  local_454[2] = '\0';
  local_454[3] = '\0';
  local_45c = 0x454;
  local_24 = *(uint32_t *)((intptr_t)self + 0xfc);
  local_18 = *(uint32_t *)((intptr_t)self + 0x108);
  if (*(int *)((intptr_t)self + 0x168) == 0) {
    if (*(int *)((intptr_t)self + 0x114) == 0) {
      if (*(int *)((intptr_t)self + 0x138) == 0) {
        if (*(int *)((intptr_t)self + 0x94) == 0) {
          local_44c = 1;
        }
        else {
          uvalue4 = 0xffffffff;
          local_44c = 2;
          local_434 = 3;
          cptr6 = *(char **)((intptr_t)self + 0xf8);
          do {
            cptr7 = cptr6;
            if (uvalue4 == 0) break;
            uvalue4 = uvalue4 - 1;
            cptr7 = cptr6 + 1;
            cVar1 = *cptr6;
            cptr6 = cptr7;
          } while (cVar1 != '\0');
          uvalue4 = ~uvalue4;
          cptr6 = cptr7 + -uvalue4;
          cptr7 = local_430;
          for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
            *(uint32_t *)cptr7 = *(uint32_t *)cptr6;
            cptr6 = cptr6 + 4;
            cptr7 = cptr7 + 4;
          }
          for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
            *cptr7 = *cptr6;
            cptr6 = cptr6 + 1;
            cptr7 = cptr7 + 1;
          }
        }
      }
      else {
        uvalue4 = 0xffffffff;
        local_44c = 4;
        local_434 = 2;
        cptr6 = *(char **)((intptr_t)self + 0xf8);
        do {
          cptr7 = cptr6;
          if (uvalue4 == 0) break;
          uvalue4 = uvalue4 - 1;
          cptr7 = cptr6 + 1;
          cVar1 = *cptr6;
          cptr6 = cptr7;
        } while (cVar1 != '\0');
        uvalue4 = ~uvalue4;
        cptr6 = cptr7 + -uvalue4;
        cptr7 = local_430;
        for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
          *(uint32_t *)cptr7 = *(uint32_t *)cptr6;
          cptr6 = cptr6 + 4;
          cptr7 = cptr7 + 4;
        }
        for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
          *cptr7 = *cptr6;
          cptr6 = cptr6 + 1;
          cptr7 = cptr7 + 1;
        }
      }
    }
    else {
      local_44c = 0;
    }
  }
  else {
    uvalue4 = 0xffffffff;
    local_44c = 3;
    local_434 = 0xc;
    cptr6 = *(char **)((intptr_t)self + 0xf8);
    do {
      cptr7 = cptr6;
      if (uvalue4 == 0) break;
      uvalue4 = uvalue4 - 1;
      cptr7 = cptr6 + 1;
      cVar1 = *cptr6;
      cptr6 = cptr7;
    } while (cVar1 != '\0');
    uvalue4 = ~uvalue4;
    cptr6 = cptr7 + -uvalue4;
    cptr7 = local_430;
    for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *(uint32_t *)cptr7 = *(uint32_t *)cptr6;
      cptr6 = cptr6 + 4;
      cptr7 = cptr7 + 4;
    }
    for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
      *cptr7 = *cptr6;
      cptr6 = cptr6 + 1;
      cptr7 = cptr7 + 1;
    }
  }
  local_444 = *(uint32_t *)((intptr_t)self + 0x2c);
  local_448 = *(uint32_t *)((intptr_t)self + 0x28);
  local_440 = *(uint32_t *)((intptr_t)self + 0x30);
  local_43c = *(uint32_t *)((intptr_t)self + 0x34);
  value3 = 0;
  local_438 = 0;
  CRT_FwriteLocked((char *)&local_45c,1,4,(int *)pFVar2);
  CRT_FwriteLocked(local_454,1,local_45c,(int *)pFVar2);
  if (0 < *(int *)((intptr_t)self + 0xf0)) {
    do {
      Dialog_WriteChildRecord(*(int **)(*(int *)((intptr_t)self + 0xec) + value3 * 8));
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)self + 0xf0));
  }
  CRT_Fclose(pFVar2);
  return 1;
}
