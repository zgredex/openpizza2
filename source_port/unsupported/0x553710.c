// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x553710.c:7:18: error: unknown type name 'LCID'
// CRT_LCMapStringA: ported from Pizza Connection 2 at 0x553710.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553710
#include "pc2_port.h"

int __cdecl
CRT_LCMapStringA(LCID arg1,DWORD arg2,char *arg3,int arg4,LPWSTR arg5,int arg6,
                UINT arg7,int arg8)

{
  int value1;
  int value2;
  uint8_t unaff_DI;
  uint8_t uStack00000000;
  WCHAR aWStack_2e [13];
  void *local_14;
  uint8_t *puStack_10;
  uint8_t *puStack_c;
  uint32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0055ce98;
  puStack_10 = &LAB_00553be0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_00585754 == 0) {
    ExceptionList = &local_14;
    value1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (value1 == 0) {
      value1 = LCMapStringA(0,0x100,&DAT_0057ca0c,1,(LPSTR)0x0,0);
      if (value1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_00585754 = 2;
    }
    else {
      DAT_00585754 = 1;
    }
  }
  if (0 < arg4) {
    arg4 = FUN_005577aa(arg3,arg4);
  }
  if (DAT_00585754 == 2) {
    value1 = LCMapStringA(arg1,arg2,arg3,arg4,(LPSTR)arg5,arg6);
    ExceptionList = local_14;
    return value1;
  }
  if (DAT_00585754 == 1) {
    if (arg7 == 0) {
      arg7 = DAT_005857dc;
    }
    value1 = MultiByteToWideChar(arg7,(-(uint32_t)(arg8 != 0) & 8) + 1,arg3,arg4,(LPWSTR)0x0,
                                0);
    if (value1 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    local_8 = 0;
    __chkstk(unaff_DI);
    local_8 = 0xffffffff;
    if (&uStack00000000 == (uint8_t *)0x3c) {
      ExceptionList = local_14;
      return 0;
    }
    value2 = MultiByteToWideChar(arg7,1,arg3,arg4,aWStack_2e + -7,value1);
    if (value2 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    value2 = LCMapStringW(arg1,arg2,aWStack_2e + -7,value1,(LPWSTR)0x0,0);
    if (value2 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    if ((arg2 & 0x400) == 0) {
      local_8 = 1;
      __chkstk(unaff_DI);
      local_8 = 0xffffffff;
      if (&uStack00000000 == (uint8_t *)0x3c) {
        ExceptionList = local_14;
        return 0;
      }
      value1 = LCMapStringW(arg1,arg2,aWStack_2e + -7,value1,aWStack_2e + -7,value2);
      if (value1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      if (arg6 == 0) {
        arg6 = 0;
        arg5 = (LPWSTR)0x0;
      }
      value2 = WideCharToMultiByte(arg7,0x220,aWStack_2e + -7,value2,(LPSTR)arg5,arg6,
                                  (LPCSTR)0x0,(LPBOOL)0x0);
      value1 = value2;
    }
    else {
      if (arg6 == 0) {
        ExceptionList = local_14;
        return value2;
      }
      if (arg6 < value2) {
        ExceptionList = local_14;
        return 0;
      }
      value1 = LCMapStringW(arg1,arg2,aWStack_2e + -7,value1,arg5,arg6);
    }
    if (value1 != 0) {
      ExceptionList = local_14;
      return value2;
    }
  }
  ExceptionList = local_14;
  return 0;
}
