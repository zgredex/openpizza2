// FUN_0055752d: ported from Pizza Connection 2 at 0x55752d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55752d
#include "pc2_port.h"

struct pc2_obj_0x55752d_local_40 { intptr_t MaxCharSize; intptr_t DefaultChar[2]; intptr_t LeadByte[12]; };
int __cdecl
FUN_0055752d(LCID arg1,DWORD arg2,uint8_t *arg3,int arg4,uint8_t *arg5,int arg6,
            UINT arg7)

{
  int value1;
  BOOL BVar2;
  BYTE *pBVar3;
  int value4;
  uint8_t unaff_DI;
  uint8_t uStack00000000;
  BYTE aBStack_42 [2];
  struct pc2_obj_0x55752d_local_40 *local_40;
  uint8_t *local_2c;
  PCNZWCH local_28;
  int local_24;
  int local_20;
  uint8_t *local_1c;
  void *local_14;
  uint8_t *puStack_10;
  uint8_t *puStack_c;
  uint32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0055d330;
  puStack_10 = &LAB_00553be0;
  local_14 = ExceptionList;
  local_1c = (&local_40)[-1]->DefaultChar;
  ExceptionList = &local_14;
  pBVar3 = (&local_40)[-1]->DefaultChar;
  if (DAT_005859a0 == 0) {
    ExceptionList = &local_14;
    value1 = CompareStringW(0,0,L"",1,L"",1);
    if (value1 == 0) {
      value1 = CompareStringA(0,0,&DAT_0057ca0c,1,&DAT_0057ca0c,1);
      if (value1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_005859a0 = 2;
      pBVar3 = local_1c;
    }
    else {
      DAT_005859a0 = 1;
      pBVar3 = local_1c;
    }
  }
  local_1c = pBVar3;
  if (0 < arg4) {
    arg4 = FUN_005577aa((char *)arg3,arg4);
  }
  if (0 < arg6) {
    arg6 = FUN_005577aa((char *)arg5,arg6);
  }
  if (DAT_005859a0 == 2) {
    value1 = CompareStringA(arg1,arg2,(PCNZCH)arg3,arg4,(PCNZCH)arg5,arg6);
    ExceptionList = local_14;
    return value1;
  }
  if (DAT_005859a0 != 1) {
    ExceptionList = local_14;
    return 0;
  }
  if (arg7 == 0) {
    arg7 = DAT_005857dc;
  }
  if ((arg4 != 0) && (arg6 != 0)) {
LAB_005576ab:
    local_20 = MultiByteToWideChar(arg7,9,(LPCSTR)arg3,arg4,(LPWSTR)0x0,0);
    if (local_20 != 0) {
      local_8 = 0;
      __chkstk(unaff_DI);
      local_8 = 0xffffffff;
      if ((&uStack00000000 != (uint8_t *)0x50) &&
         (local_28 = (PCNZWCH)(&local_40)[-1]->DefaultChar, local_1c = (&local_40)[-1]->DefaultChar,
         value1 = MultiByteToWideChar(arg7,1,(LPCSTR)arg3,arg4,
                                     (LPWSTR)(&local_40)[-1]->DefaultChar,local_20), value1 != 0)) {
        value1 = MultiByteToWideChar(arg7,9,(LPCSTR)arg5,arg6,(LPWSTR)0x0,0);
        if (value1 != 0) {
          local_8 = 1;
          local_24 = value1;
          __chkstk(unaff_DI);
          local_8 = 0xffffffff;
          if ((&uStack00000000 != (uint8_t *)0x50) &&
             (local_2c = (&local_40)[-1]->DefaultChar, local_1c = (&local_40)[-1]->DefaultChar,
             value4 = MultiByteToWideChar(arg7,1,(LPCSTR)arg5,arg6,
                                         (LPWSTR)(&local_40)[-1]->DefaultChar,value1), value4 != 0)) {
            value1 = CompareStringW(arg1,arg2,local_28,local_20,
                                   (PCNZWCH)(&local_40)[-1]->DefaultChar,value1);
            ExceptionList = local_14;
            return value1;
          }
        }
      }
    }
    ExceptionList = local_14;
    return 0;
  }
  if (arg4 == arg6) {
    ExceptionList = local_14;
    return 2;
  }
  if (1 < arg6) {
    ExceptionList = local_14;
    return 1;
  }
  if (arg4 < 2) {
    BVar2 = GetCPInfo(arg7,&local_40);
    if (BVar2 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    if (arg4 < 1) {
      if (0 < arg6) {
        if (local_40->MaxCharSize < 2) {
          ExceptionList = local_14;
          return 1;
        }
        pBVar3 = local_40->LeadByte;
        while( true ) {
          if (local_40->LeadByte[0] == 0) {
            ExceptionList = local_14;
            return 1;
          }
          if (pBVar3[1] == 0) break;
          if ((*pBVar3 <= *arg5) && (*arg5 <= pBVar3[1])) {
            ExceptionList = local_14;
            return 2;
          }
          pBVar3 = pBVar3 + 2;
          local_40->LeadByte[0] = *pBVar3;
        }
        ExceptionList = local_14;
        return 1;
      }
      goto LAB_005576ab;
    }
    if (1 < local_40->MaxCharSize) {
      pBVar3 = local_40->LeadByte;
      while ((local_40->LeadByte[0] != 0 && (pBVar3[1] != 0))) {
        if ((*pBVar3 <= *arg3) && (*arg3 <= pBVar3[1])) {
          ExceptionList = local_14;
          return 2;
        }
        pBVar3 = pBVar3 + 2;
        local_40->LeadByte[0] = *pBVar3;
      }
    }
  }
  ExceptionList = local_14;
  return 3;
}
