// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x5501c0.c:38:25: error: use of undeclared identifier 'LPOVERLAPPED'
// CRT_ReadCore: ported from Pizza Connection 2 at 0x5501c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5501c0
#include "pc2_port.h"

int __cdecl CRT_ReadCore(uint32_t arg1,char *arg2,char *arg3)

{
  int *ptr1;
  uint8_t *bptr2;
  char cVar3;
  uint8_t flag4;
  BOOL BVar5;
  DWORD DVar6;
  DWORD *pDVar7;
  char *cptr8;
  int value9;
  DWORD local_10;
  char *local_c;
  char local_5;
  
  local_c = (char *)0x0;
  if (arg3 != (char *)0x0) {
    ptr1 = &DAT_00586c20 + ((intptr_t)arg1 >> 5);
    value9 = (arg1 & 0x1f) * 0x24;
    flag4 = *(uint8_t *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + value9 + 4);
    if ((flag4 & 2) == 0) {
      cptr8 = arg2;
      if (((flag4 & 0x48) != 0) &&
         (cVar3 = *(char *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + value9 + 5), cVar3 != '\n')) {
        arg3 = arg3 + -1;
        *arg2 = cVar3;
        cptr8 = arg2 + 1;
        local_c = (char *)0x1;
        *(uint8_t *)(*ptr1 + 5 + value9) = 10;
      }
      BVar5 = ReadFile(*(HANDLE *)(*ptr1 + value9),cptr8,(DWORD)arg3,&local_10,
                       (LPOVERLAPPED)0x0);
      if (BVar5 == 0) {
        DVar6 = GetLastError();
        if (DVar6 == 5) {
          pDVar7 = CRT_GetErrnoPtr();
          *pDVar7 = 9;
          pDVar7 = CRT_GetDosErrnoPtr();
          *pDVar7 = 5;
        }
        else {
          if (DVar6 == 0x6d) {
            return 0;
          }
          CRT_MapWin32Error(DVar6);
        }
        return -1;
      }
      local_c = (char *)((intptr_t)local_c + local_10);
      flag4 = *(uint8_t *)(*ptr1 + 4 + value9);
      if ((flag4 & 0x80) != 0) {
        if ((local_10 == 0) || (*arg2 != '\n')) {
          flag4 = flag4 & 0xfb;
        }
        else {
          flag4 = flag4 | 4;
        }
        *(uint8_t *)(*ptr1 + 4 + value9) = flag4;
        arg3 = arg2;
        local_c = arg2 + (intptr_t)local_c;
        cptr8 = arg2;
        if (arg2 < local_c) {
          do {
            cVar3 = *arg3;
            if (cVar3 == '\x1a') {
              bptr2 = (uint8_t *)(*ptr1 + 4 + value9);
              flag4 = *bptr2;
              if ((flag4 & 0x40) == 0) {
                *bptr2 = flag4 | 2;
              }
              break;
            }
            if (cVar3 == '\r') {
              if (arg3 < local_c + -1) {
                if (arg3[1] == '\n') {
                  arg3 = arg3 + 2;
                  goto LAB_0055034b;
                }
                *cptr8 = '\r';
                cptr8 = cptr8 + 1;
                arg3 = arg3 + 1;
              }
              else {
                arg3 = arg3 + 1;
                BVar5 = ReadFile(*(HANDLE *)(*ptr1 + value9),&local_5,1,&local_10,(LPOVERLAPPED)0x0
                                );
                if (((BVar5 == 0) && (DVar6 = GetLastError(), DVar6 != 0)) || (local_10 == 0)) {
LAB_00550365:
                  *cptr8 = '\r';
LAB_00550368:
                  cptr8 = cptr8 + 1;
                }
                else if ((*(uint8_t *)(*ptr1 + 4 + value9) & 0x48) == 0) {
                  if ((cptr8 == arg2) && (local_5 == '\n')) {
LAB_0055034b:
                    *cptr8 = '\n';
                    goto LAB_00550368;
                  }
                  CRT_LseekLocked(arg1,-1,1);
                  if (local_5 != '\n') goto LAB_00550365;
                }
                else {
                  if (local_5 == '\n') goto LAB_0055034b;
                  *cptr8 = '\r';
                  cptr8 = cptr8 + 1;
                  *(char *)(*ptr1 + 5 + value9) = local_5;
                }
              }
            }
            else {
              *cptr8 = cVar3;
              cptr8 = cptr8 + 1;
              arg3 = arg3 + 1;
            }
          } while (arg3 < local_c);
        }
        local_c = (char *)((intptr_t)cptr8 - (intptr_t)arg2);
      }
      return (intptr_t)local_c;
    }
  }
  return 0;
}
