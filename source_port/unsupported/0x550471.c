// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x550471.c:18:3: error: use of undeclared identifier '_STARTUPINFOA'
// CRT_IOInit: ported from Pizza Connection 2 at 0x550471.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x550471
#include "pc2_port.h"

void CRT_IOInit(void)

{
  uint32_t *uptr1;
  uint32_t *uptr2;
  uint32_t *uptr3;
  DWORD DVar4;
  HANDLE hFile;
  UINT *pUVar5;
  int value6;
  uint32_t uvalue7;
  UINT UVar8;
  _STARTUPINFOA local_4c;
  uint8_t *local_8;
  
  uptr2 = _malloc(0x480);
  if (uptr2 == (uint32_t *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_00586d20 = 0x20;
  DAT_00586c20 = uptr2;
  for (; uptr2 < DAT_00586c20 + 0x120; uptr2 = uptr2 + 9) {
    *(uint8_t *)(uptr2 + 1) = 0;
    *uptr2 = 0xffffffff;
    uptr2[2] = 0;
    *(uint8_t *)((intptr_t)uptr2 + 5) = 10;
  }
  GetStartupInfoA(&local_4c);
  if ((local_4c.cbReserved2 != 0) && ((UINT *)local_4c.lpReserved2 != (UINT *)0x0)) {
    UVar8 = *(UINT *)local_4c.lpReserved2;
    pUVar5 = (UINT *)((intptr_t)local_4c.lpReserved2 + 4);
    local_8 = (uint8_t *)((intptr_t)pUVar5 + UVar8);
    if (0x7ff < (intptr_t)UVar8) {
      UVar8 = 0x800;
    }
    if ((intptr_t)DAT_00586d20 < (intptr_t)UVar8) {
      uptr2 = &DAT_00586c24;
      do {
        uptr3 = _malloc(0x480);
        if (uptr3 == (uint32_t *)0x0) {
          UVar8 = DAT_00586d20;
          break;
        }
        DAT_00586d20 = DAT_00586d20 + 0x20;
        *uptr2 = uptr3;
        uptr1 = uptr3;
        for (; uptr3 < uptr1 + 0x120; uptr3 = uptr3 + 9) {
          *(uint8_t *)(uptr3 + 1) = 0;
          *uptr3 = 0xffffffff;
          uptr3[2] = 0;
          *(uint8_t *)((intptr_t)uptr3 + 5) = 10;
          uptr1 = (uint32_t *)*uptr2;
        }
        uptr2 = uptr2 + 1;
      } while ((intptr_t)DAT_00586d20 < (intptr_t)UVar8);
    }
    uvalue7 = 0;
    if (0 < (intptr_t)UVar8) {
      do {
        if (((*(HANDLE *)local_8 != (HANDLE)0xffffffff) && ((*pUVar5 & 1) != 0)) &&
           (((*pUVar5 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)local_8), DVar4 != 0)))) {
          uptr2 = (uint32_t *)((intptr_t)(&DAT_00586c20)[(intptr_t)uvalue7 >> 5] + (uvalue7 & 0x1f) * 0x24);
          *uptr2 = *(uint32_t *)local_8;
          *(uint8_t *)(uptr2 + 1) = (uint8_t)*pUVar5;
        }
        local_8 = local_8 + 4;
        uvalue7 = uvalue7 + 1;
        pUVar5 = (UINT *)((intptr_t)pUVar5 + 1);
      } while ((intptr_t)uvalue7 < (intptr_t)UVar8);
    }
  }
  value6 = 0;
  do {
    uptr2 = DAT_00586c20 + value6 * 9;
    if (DAT_00586c20[value6 * 9] == -1) {
      *(uint8_t *)(uptr2 + 1) = 0x81;
      if (value6 == 0) {
        DVar4 = 0xfffffff6;
      }
      else {
        DVar4 = 0xfffffff5 - (value6 != 1);
      }
      hFile = GetStdHandle(DVar4);
      if ((hFile != (HANDLE)0xffffffff) && (DVar4 = GetFileType(hFile), DVar4 != 0)) {
        *uptr2 = hFile;
        if ((DVar4 & 0xff) != 2) {
          if ((DVar4 & 0xff) == 3) {
            *(uint8_t *)(uptr2 + 1) = *(uint8_t *)(uptr2 + 1) | 8;
          }
          goto LAB_00550616;
        }
      }
      *(uint8_t *)(uptr2 + 1) = *(uint8_t *)(uptr2 + 1) | 0x40;
    }
    else {
      *(uint8_t *)(uptr2 + 1) = *(uint8_t *)(uptr2 + 1) | 0x80;
    }
LAB_00550616:
    value6 = value6 + 1;
    if (2 < value6) {
      SetHandleCount(DAT_00586d20);
      return;
    }
  } while( true );
}
