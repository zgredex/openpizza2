// FUN_00556a1e: ported from Pizza Connection 2 at 0x556a1e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x556a1e
#include "pc2_port.h"

uint32_t __cdecl FUN_00556a1e(DWORD *arg1)

{
  bool flag1;
  DWORD *pDVar2;
  uint32_t uvalue3;
  int value4;
  DWORD DVar5;
  DWORD extraout_ECX;
  int value6;
  code *cptr7;
  DWORD *pDVar8;
  DWORD local_10;
  DWORD local_c;
  
  flag1 = false;
  if (arg1 == (DWORD *)0x2) {
    pDVar8 = (DWORD *)&DAT_0058597c;
    cptr7 = DAT_0058597c;
LAB_00556aa4:
    flag1 = true;
    CRT_Lock(1);
    pDVar2 = arg1;
  }
  else {
    if (((arg1 != (DWORD *)0x4) && (arg1 != (DWORD *)0x8)) && (arg1 != (DWORD *)0xb)) {
      if (arg1 == (DWORD *)0xf) {
        pDVar8 = (DWORD *)&DAT_00585988;
        cptr7 = DAT_00585988;
      }
      else if (arg1 == (DWORD *)0x15) {
        pDVar8 = (DWORD *)&DAT_00585980;
        cptr7 = DAT_00585980;
      }
      else {
        if (arg1 != (DWORD *)0x16) {
          return 0xffffffff;
        }
        pDVar8 = (DWORD *)&DAT_00585984;
        cptr7 = DAT_00585984;
      }
      goto LAB_00556aa4;
    }
    pDVar2 = CRT_GetThreadData();
    uvalue3 = FUN_00556ba0((intptr_t)arg1,pDVar2[0x14]);
    pDVar8 = (DWORD *)(uvalue3 + 8);
    cptr7 = (code *)*pDVar8;
  }
  if (cptr7 == (code *)0x1) {
    if (flag1) {
      CS_LeaveIndexed(1);
      return 0;
    }
    return 0;
  }
  DVar5 = 0;
  if (cptr7 == (code *)0x0) {
    if (flag1) {
      CS_LeaveIndexed(1);
    }
    __exit(3);
    DVar5 = extraout_ECX;
  }
  if (((arg1 == (DWORD *)0x8) || (arg1 == (DWORD *)0xb)) || (arg1 == (DWORD *)0x4)) {
    local_c = pDVar2[0x15];
    pDVar2[0x15] = DVar5;
    if (arg1 == (DWORD *)0x8) {
      local_10 = pDVar2[0x16];
      pDVar2[0x16] = 0x8c;
      goto LAB_00556b18;
    }
  }
  else {
LAB_00556b18:
    if (arg1 == (DWORD *)0x8) {
      if (DAT_005770b8 < DAT_005770bc + DAT_005770b8) {
        value4 = DAT_005770b8 * 0xc;
        value6 = DAT_005770b8;
        do {
          value4 = value4 + 0xc;
          *(uint32_t *)((pDVar2[0x14] - 4) + value4) = 0;
          value6 = value6 + 1;
        } while (value6 < DAT_005770bc + DAT_005770b8);
      }
      goto LAB_00556b56;
    }
  }
  *pDVar8 = DVar5;
LAB_00556b56:
  if (flag1) {
    CS_LeaveIndexed(1);
  }
  if (arg1 == (DWORD *)0x8) {
    (*cptr7)(8,pDVar2[0x16]);
  }
  else {
    (*cptr7)(arg1);
    if ((arg1 != (DWORD *)0xb) && (arg1 != (DWORD *)0x4)) {
      return 0;
    }
  }
  pDVar2[0x15] = local_c;
  if (arg1 == (DWORD *)0x8) {
    pDVar2[0x16] = local_10;
  }
  return 0;
}
