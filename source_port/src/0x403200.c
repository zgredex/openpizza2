// RegistryKey_ReadValue: ported from Pizza Connection 2 at 0x403200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403200
#include "pc2_port.h"

LPBYTE __thiscall RegistryKey_ReadValue(void *self,LPCSTR arg1,uint32_t *arg2)

{
  LPCSTR lpValueName;
  LSTATUS LVar1;
  LPBYTE lpData;
  DWORD local_4;
  
  lpValueName = arg1;
  *arg2 = 0;
  local_4 = 0;
  if (*(HKEY *)self == (HKEY)0x0) {
    return (LPBYTE)0x0;
  }
  LVar1 = RegQueryValueExA(*(HKEY *)self,arg1,(LPDWORD)0x0,(LPDWORD)&arg1,(LPBYTE)0x0,&local_4
                          );
  if (LVar1 != 0) {
    return (LPBYTE)0x0;
  }
  lpData = operator_new(local_4);
  LVar1 = RegQueryValueExA(*(HKEY *)self,lpValueName,(LPDWORD)0x0,(LPDWORD)&arg1,lpData,&local_4)
  ;
  if (LVar1 == 0) {
    *arg2 = local_4;
    return lpData;
  }
  Mem_Free(lpData);
  return (LPBYTE)0x0;
}
