// CRT_WriteCore: ported from Pizza Connection 2 at 0x54ffd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ffd0
#include "pc2_port.h"

int __cdecl CRT_WriteCore(DWORD arg1,char *arg2,DWORD arg3)

{
  int *ptr1;
  char *cptr2;
  char cVar3;
  int value4;
  char *cptr5;
  BOOL BVar6;
  DWORD *pDVar7;
  char local_418 [1028];
  int local_14;
  DWORD local_10;
  DWORD local_c;
  char *local_8;
  
  local_c = 0;
  local_14 = 0;
  if (arg3 == 0) {
LAB_0054ffe9:
    value4 = 0;
  }
  else {
    ptr1 = &DAT_00586c20 + ((intptr_t)arg1 >> 5);
    value4 = (arg1 & 0x1f) * 0x24;
    if ((*(uint8_t *)(*ptr1 + 4 + value4) & 0x20) != 0) {
      CRT_LseekLocked(arg1,0,2);
    }
    if ((*(uint8_t *)((uint32_t *)(*ptr1 + value4) + 1) & 0x80) == 0) {
      BVar6 = WriteFile(*(HANDLE *)(*ptr1 + value4),arg2,arg3,&local_10,(LPOVERLAPPED)0x0);
      if (BVar6 == 0) {
        arg1 = GetLastError();
      }
      else {
        arg1 = 0;
        local_c = local_10;
      }
LAB_005500b8:
      if (local_c != 0) {
        return local_c - local_14;
      }
      if (arg1 == 0) goto LAB_0055012a;
      if (arg1 == 5) {
        pDVar7 = CRT_GetErrnoPtr();
        *pDVar7 = 9;
        pDVar7 = CRT_GetDosErrnoPtr();
        *pDVar7 = 5;
      }
      else {
        CRT_MapWin32Error(arg1);
      }
    }
    else {
      local_8 = arg2;
      arg1 = 0;
      if (arg3 != 0) {
        do {
          cptr5 = local_418;
          do {
            if (arg3 <= (uint32_t)((intptr_t)local_8 - (intptr_t)arg2)) break;
            cptr2 = local_8 + 1;
            cVar3 = *local_8;
            local_8 = cptr2;
            if (cVar3 == '\n') {
              local_14 = local_14 + 1;
              *cptr5 = '\r';
              cptr5 = cptr5 + 1;
            }
            *cptr5 = cVar3;
            cptr5 = cptr5 + 1;
          } while ((intptr_t)cptr5 - (intptr_t)local_418 < 0x400);
          BVar6 = WriteFile(*(HANDLE *)(*ptr1 + value4),local_418,(intptr_t)cptr5 - (intptr_t)local_418,
                            &local_10,(LPOVERLAPPED)0x0);
          if (BVar6 == 0) {
            arg1 = GetLastError();
            goto LAB_005500b8;
          }
          local_c = local_c + local_10;
          if (((intptr_t)local_10 < (intptr_t)cptr5 - (intptr_t)local_418) ||
             (arg3 <= (uint32_t)((intptr_t)local_8 - (intptr_t)arg2))) goto LAB_005500b8;
        } while( true );
      }
LAB_0055012a:
      if (((*(uint8_t *)(*ptr1 + 4 + value4) & 0x40) != 0) && (*arg2 == '\x1a')) goto LAB_0054ffe9;
      pDVar7 = CRT_GetErrnoPtr();
      *pDVar7 = 0x1c;
      pDVar7 = CRT_GetDosErrnoPtr();
      *pDVar7 = 0;
    }
    value4 = -1;
  }
  return value4;
}
