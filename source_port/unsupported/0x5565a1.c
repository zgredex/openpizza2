// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x5565a1.c:25:3: error: use of undeclared identifier '_cpinfo'
// FUN_005565a1: ported from Pizza Connection 2 at 0x5565a1.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5565a1
#include "pc2_port.h"

uint32_t __cdecl FUN_005565a1(int arg1)

{
  BYTE *pBVar1;
  uint8_t *bptr2;
  uint8_t flag3;
  uint8_t flag4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint32_t uvalue7;
  uint32_t uvalue8;
  BYTE *pBVar9;
  int value10;
  uint8_t *bptr11;
  int value12;
  uint8_t *bptr13;
  uint32_t uvalue14;
  uint32_t *uptr15;
  _cpinfo local_1c;
  uint32_t local_8;
  
  CRT_Lock(0x19);
  CodePage = FUN_0055674e(arg1);
  if (CodePage != DAT_005859ac) {
    if (CodePage != 0) {
      value12 = 0;
      pUVar5 = &DAT_00577218;
LAB_005565de:
      if (*pUVar5 != CodePage) goto code_r0x005565e2;
      local_8 = 0;
      uptr15 = &DAT_00585ac0;
      for (value10 = 0x40; value10 != 0; value10 = value10 + -1) {
        *uptr15 = 0;
        uptr15 = uptr15 + 1;
      }
      value12 = value12 * 0x30;
      *(uint8_t *)uptr15 = 0;
      bptr13 = (uint8_t *)(value12 + 0x577228);
      do {
        flag3 = *bptr13;
        bptr11 = bptr13;
        while ((flag3 != 0 && (flag3 = bptr11[1], flag3 != 0))) {
          uvalue8 = (uint32_t)*bptr11;
          if (uvalue8 <= flag3) {
            flag4 = (&DAT_00577210)[local_8];
            do {
              bptr2 = (uint8_t *)((intptr_t)&DAT_00585ac0 + uvalue8 + 1);
              *bptr2 = *bptr2 | flag4;
              uvalue8 = uvalue8 + 1;
            } while (uvalue8 <= flag3);
          }
          bptr11 = bptr11 + 2;
          flag3 = *bptr11;
        }
        local_8 = local_8 + 1;
        bptr13 = bptr13 + 8;
      } while (local_8 < 4);
      DAT_005859bc = 1;
      DAT_005859ac = CodePage;
      DAT_00585bc4 = FUN_00556798(CodePage);
      DAT_005859b0 = *(uint32_t *)(value12 + 0x57721c);
      DAT_005859b4 = *(uint32_t *)(value12 + 0x577220);
      DAT_005859b8 = *(uint32_t *)(value12 + 0x577224);
      goto LAB_00556732;
    }
    goto LAB_0055672d;
  }
  goto LAB_005565c8;
code_r0x005565e2:
  pUVar5 = pUVar5 + 0xc;
  value12 = value12 + 1;
  if (0x577307 < (intptr_t)pUVar5) goto code_r0x005565ed;
  goto LAB_005565de;
code_r0x005565ed:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uvalue8 = 1;
  if (BVar6 == 1) {
    DAT_00585bc4 = 0;
    uptr15 = &DAT_00585ac0;
    for (value12 = 0x40; value12 != 0; value12 = value12 + -1) {
      *uptr15 = 0;
      uptr15 = uptr15 + 1;
    }
    *(uint8_t *)uptr15 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_005859bc = 0;
      DAT_005859ac = CodePage;
    }
    else {
      DAT_005859ac = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          flag3 = *pBVar9;
          if (flag3 == 0) break;
          for (uvalue7 = (uint32_t)pBVar9[-1]; uvalue7 <= flag3; uvalue7 = uvalue7 + 1) {
            bptr13 = (uint8_t *)((intptr_t)&DAT_00585ac0 + uvalue7 + 1);
            *bptr13 = *bptr13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        bptr13 = (uint8_t *)((intptr_t)&DAT_00585ac0 + uvalue8 + 1);
        *bptr13 = *bptr13 | 8;
        uvalue8 = uvalue8 + 1;
      } while (uvalue8 < 0xff);
      DAT_00585bc4 = FUN_00556798(CodePage);
      DAT_005859bc = 1;
    }
    DAT_005859b0 = 0;
    DAT_005859b4 = 0;
    DAT_005859b8 = 0;
  }
  else {
    if (DAT_0058596c == 0) {
      uvalue14 = 0xffffffff;
      goto LAB_0055673f;
    }
LAB_0055672d:
    FUN_005567cb();
  }
LAB_00556732:
  FUN_005567f4();
LAB_005565c8:
  uvalue14 = 0;
LAB_0055673f:
  CS_LeaveIndexed(0x19);
  return uvalue14;
}
