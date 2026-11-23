// FUN_005567f4: ported from Pizza Connection 2 at 0x5567f4.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5567f4
#include "pc2_port.h"

struct pc2_obj_0x5567f4_local_18 { intptr_t LeadByte[1]; };
void FUN_005567f4(void)

{
  uint8_t *bptr1;
  BOOL BVar2;
  uint32_t uvalue3;
  char cVar4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  uint16_t *uptr7;
  uint8_t uvalue8;
  BYTE *pBVar9;
  CHAR *pCVar10;
  WORD local_518 [256];
  WCHAR local_318 [128];
  WCHAR local_218 [128];
  CHAR local_118 [256];
  struct pc2_obj_0x5567f4_local_18 *local_18;
  
  BVar2 = GetCPInfo(DAT_005859ac,&local_18);
  if (BVar2 == 1) {
    uvalue3 = 0;
    do {
      local_118[uvalue3] = (CHAR)uvalue3;
      uvalue3 = uvalue3 + 1;
    } while (uvalue3 < 0x100);
    local_118[0] = ' ';
    if (local_18->LeadByte[0] != 0) {
      pBVar9 = local_18->LeadByte + 1;
      do {
        uvalue3 = (uint32_t)local_18->LeadByte[0];
        if (uvalue3 <= *pBVar9) {
          uvalue5 = (*pBVar9 - uvalue3) + 1;
          uvalue6 = uvalue5 >> 2;
          pCVar10 = local_118 + uvalue3;
          while (uvalue6 != 0) {
            uvalue6 = uvalue6 - 1;
            builtin_memcpy(pCVar10,"    ",4);
            pCVar10 = pCVar10 + 4;
          }
          for (uvalue5 = uvalue5 & 3; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
            *pCVar10 = ' ';
            pCVar10 = pCVar10 + 1;
          }
        }
        local_18->LeadByte[0] = pBVar9[1];
        pBVar9 = pBVar9 + 2;
      } while (local_18->LeadByte[0] != 0);
    }
    FUN_00555dd9(1,local_118,0x100,local_518,DAT_005859ac,DAT_00585bc4,0);
    CRT_LCMapStringA(DAT_00585bc4,0x100,local_118,0x100,local_218,0x100,DAT_005859ac,0);
    CRT_LCMapStringA(DAT_00585bc4,0x200,local_118,0x100,local_318,0x100,DAT_005859ac,0);
    uvalue3 = 0;
    uptr7 = local_518;
    do {
      if ((*uptr7 & 1) == 0) {
        if ((*uptr7 & 2) != 0) {
          bptr1 = (uint8_t *)((intptr_t)&DAT_00585ac0 + uvalue3 + 1);
          *bptr1 = *bptr1 | 0x20;
          uvalue8 = *(uint8_t *)((intptr_t)local_318 + uvalue3);
          goto LAB_00556900;
        }
        (&DAT_005859c0)[uvalue3] = 0;
      }
      else {
        bptr1 = (uint8_t *)((intptr_t)&DAT_00585ac0 + uvalue3 + 1);
        *bptr1 = *bptr1 | 0x10;
        uvalue8 = *(uint8_t *)((intptr_t)local_218 + uvalue3);
LAB_00556900:
        (&DAT_005859c0)[uvalue3] = uvalue8;
      }
      uvalue3 = uvalue3 + 1;
      uptr7 = uptr7 + 1;
    } while (uvalue3 < 0x100);
  }
  else {
    uvalue3 = 0;
    do {
      if ((uvalue3 < 0x41) || (0x5a < uvalue3)) {
        if ((0x60 < uvalue3) && (uvalue3 < 0x7b)) {
          bptr1 = (uint8_t *)((intptr_t)&DAT_00585ac0 + uvalue3 + 1);
          *bptr1 = *bptr1 | 0x20;
          cVar4 = (char)uvalue3 + -0x20;
          goto LAB_0055694a;
        }
        (&DAT_005859c0)[uvalue3] = 0;
      }
      else {
        bptr1 = (uint8_t *)((intptr_t)&DAT_00585ac0 + uvalue3 + 1);
        *bptr1 = *bptr1 | 0x10;
        cVar4 = (char)uvalue3 + ' ';
LAB_0055694a:
        (&DAT_005859c0)[uvalue3] = cVar4;
      }
      uvalue3 = uvalue3 + 1;
    } while (uvalue3 < 0x100);
  }
  return;
}
