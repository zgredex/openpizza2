// CRT_Strupr: ported from Pizza Connection 2 at 0x54f775.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f775
#include "pc2_port.h"

/* WARNING: Variable defined which should be unmapped: arg1 */

uint32_t * __cdecl CRT_Strupr(uint32_t *arg1)

{
  char cVar1;
  size_t _Size;
  int value2;
  uint32_t *uptr3;
  bool flag4;
  LPWSTR local_c;
  
  local_c = (LPWSTR)0x0;
  if (DAT_005857cc == 0) {
    cVar1 = (char)*arg1;
    uptr3 = arg1;
    while (cVar1 != '\0') {
      cVar1 = (char)*uptr3;
      if (('`' < cVar1) && (cVar1 < '{')) {
        *(char *)uptr3 = cVar1 + -0x20;
      }
      uptr3 = (uint32_t *)((intptr_t)uptr3 + 1);
      cVar1 = *(char *)uptr3;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_00585be8);
    flag4 = DAT_00585be4 == 0;
    if (!flag4) {
      InterlockedDecrement((LONG *)&DAT_00585be8);
      CRT_Lock(0x13);
    }
    if (DAT_005857cc == 0) {
      if (flag4) {
        InterlockedDecrement((LONG *)&DAT_00585be8);
      }
      else {
        CS_LeaveIndexed(0x13);
      }
      cVar1 = (char)*arg1;
      uptr3 = arg1;
      while (cVar1 != '\0') {
        cVar1 = (char)*uptr3;
        if (('`' < cVar1) && (cVar1 < '{')) {
          *(char *)uptr3 = cVar1 + -0x20;
        }
        uptr3 = (uint32_t *)((intptr_t)uptr3 + 1);
        cVar1 = *(char *)uptr3;
      }
    }
    else {
      _Size = CRT_LCMapStringA(DAT_005857cc,0x200,(char *)arg1,-1,(LPWSTR)0x0,0,0,1);
      if (((_Size != 0) && (local_c = _malloc(_Size), local_c != (LPWSTR)0x0)) &&
         (value2 = CRT_LCMapStringA(DAT_005857cc,0x200,(char *)arg1,-1,local_c,_Size,0,1),
         value2 != 0)) {
        _strcpy(arg1,(uint32_t *)local_c);
      }
      if (flag4) {
        InterlockedDecrement((LONG *)&DAT_00585be8);
      }
      else {
        CS_LeaveIndexed(0x13);
      }
      CRT_FreeInternal(local_c);
    }
  }
  return arg1;
}
