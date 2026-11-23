// CRT_FtellLocked: ported from Pizza Connection 2 at 0x54ec7f.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ec7f
#include "pc2_port.h"

int __cdecl CRT_FtellLocked(char *arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  uint8_t flag3;
  DWORD *pDVar4;
  char *cptr5;
  DWORD DVar6;
  char *cptr7;
  char *cptr8;
  char *cptr9;
  int value10;
  int local_c;
  DWORD local_8;
  
  cptr8 = arg1;
  uvalue1 = *(uint32_t *)(arg1 + 0x10);
  if (*(int *)(arg1 + 4) < 0) {
    arg1[4] = '\0';
    arg1[5] = '\0';
    arg1[6] = '\0';
    arg1[7] = '\0';
  }
  local_8 = CRT_Lseek(uvalue1,0,1);
  if ((intptr_t)local_8 < 0) {
LAB_0054ed0d:
    local_c = -1;
  }
  else {
    uvalue2 = *(uint32_t *)(arg1 + 0xc);
    if ((uvalue2 & 0x108) == 0) {
      return local_8 - *(int *)(arg1 + 4);
    }
    cptr5 = *(char **)arg1;
    cptr7 = *(char **)(arg1 + 8);
    local_c = (intptr_t)cptr5 - (intptr_t)cptr7;
    if ((uvalue2 & 3) == 0) {
      if ((uvalue2 & 0x80) == 0) {
        pDVar4 = CRT_GetErrnoPtr();
        *pDVar4 = 0x16;
        goto LAB_0054ed0d;
      }
    }
    else if ((*(uint8_t *)((&DAT_00586c20)[(intptr_t)uvalue1 >> 5] + 4 + (uvalue1 & 0x1f) * 0x24) & 0x80) != 0)
    {
      for (cptr9 = cptr7; cptr9 < cptr5; cptr9 = cptr9 + 1) {
        if (*cptr9 == '\n') {
          local_c = local_c + 1;
        }
      }
    }
    if (local_8 != 0) {
      if ((arg1[0xc] & 1U) != 0) {
        if (*(int *)(arg1 + 4) == 0) {
          local_c = 0;
        }
        else {
          cptr5 = cptr5 + (*(int *)(arg1 + 4) - (intptr_t)cptr7);
          value10 = (uvalue1 & 0x1f) * 0x24;
          if ((*(uint8_t *)(value10 + 4 + (&DAT_00586c20)[(intptr_t)uvalue1 >> 5]) & 0x80) != 0) {
            DVar6 = CRT_Lseek(uvalue1,0,2);
            if (DVar6 == local_8) {
              cptr7 = *(char **)(arg1 + 8);
              cptr9 = cptr5 + (intptr_t)cptr7;
              arg1 = cptr5;
              for (; cptr7 < cptr9; cptr7 = cptr7 + 1) {
                if (*cptr7 == '\n') {
                  arg1 = arg1 + 1;
                }
              }
              flag3 = cptr8[0xd] & 0x20;
            }
            else {
              CRT_Lseek(uvalue1,local_8,0);
              cptr8 = (char *)0x200;
              if ((((char *)0x200 < cptr5) || ((*(uint32_t *)(arg1 + 0xc) & 8) == 0)) ||
                 ((*(uint32_t *)(arg1 + 0xc) & 0x400) != 0)) {
                cptr8 = *(char **)(arg1 + 0x18);
              }
              flag3 = *(uint8_t *)(value10 + 4 + (&DAT_00586c20)[(intptr_t)uvalue1 >> 5]) & 4;
              arg1 = cptr8;
            }
            cptr5 = arg1;
            if (flag3 != 0) {
              cptr5 = arg1 + 1;
            }
          }
          arg1 = cptr5;
          local_8 = local_8 - (intptr_t)arg1;
        }
      }
      local_c = local_c + local_8;
    }
  }
  return local_c;
}
