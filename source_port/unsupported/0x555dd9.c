// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x555dd9.c:7:68: error: unknown type name 'LCID'
// FUN_00555dd9: ported from Pizza Connection 2 at 0x555dd9.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555dd9
#include "pc2_port.h"

BOOL __cdecl
FUN_00555dd9(DWORD arg1,LPCSTR arg2,int arg3,LPWORD arg4,UINT arg5,LCID arg6,
            int arg7)

{
  WCHAR *pWVar1;
  BOOL BVar2;
  int value3;
  uint8_t unaff_DI;
  uint8_t uStack00000000;
  WCHAR aWStack_2a [5];
  WORD local_20 [2];
  uint8_t *local_1c;
  void *local_14;
  uint8_t *puStack_10;
  uint8_t *puStack_c;
  uint32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0055d1a0;
  puStack_10 = &LAB_00553be0;
  local_14 = ExceptionList;
  local_1c = (uint8_t *)(aWStack_2a + -7);
  ExceptionList = &local_14;
  pWVar1 = aWStack_2a + -7;
  if (DAT_00585900 == 0) {
    value3 = 1;
    ExceptionList = &local_14;
    BVar2 = GetStringTypeW(1,L"",1,local_20);
    if (BVar2 == 0) {
      BVar2 = GetStringTypeA(0,1,&DAT_0057ca0c,1,local_20);
      if (BVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      value3 = 2;
    }
    DAT_00585900 = value3;
    pWVar1 = (WCHAR *)local_1c;
  }
  local_1c = (uint8_t *)pWVar1;
  if (DAT_00585900 == 2) {
    if (arg6 == 0) {
      arg6 = DAT_005857cc;
    }
    BVar2 = GetStringTypeA(arg6,arg1,arg2,arg3,arg4);
    ExceptionList = local_14;
    return BVar2;
  }
  if (DAT_00585900 == 1) {
    if (arg5 == 0) {
      arg5 = DAT_005857dc;
    }
    value3 = MultiByteToWideChar(arg5,(-(uint32_t)(arg7 != 0) & 8) + 1,arg2,arg3,(LPWSTR)0x0,
                                0);
    if (value3 != 0) {
      local_8 = 0;
      __chkstk(unaff_DI);
      local_1c = (uint8_t *)(aWStack_2a + -7);
      _memset(aWStack_2a + -7,0,value3 * 2);
      local_8 = 0xffffffff;
      if ((&uStack00000000 != (uint8_t *)0x38) &&
         (value3 = MultiByteToWideChar(arg5,1,arg2,arg3,aWStack_2a + -7,value3), value3 != 0))
      {
        BVar2 = GetStringTypeW(arg1,aWStack_2a + -7,value3,arg4);
        ExceptionList = local_14;
        return BVar2;
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}
