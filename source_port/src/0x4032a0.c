// RegistryKey_WriteValue: ported from Pizza Connection 2 at 0x4032a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4032a0
#include "pc2_port.h"

bool __thiscall RegistryKey_WriteValue(void *self,LPCSTR arg1,BYTE *arg2,DWORD arg3)

{
  LSTATUS LVar1;
  
  if (*(HKEY *)self == (HKEY)0x0) {
    return false;
  }
  if (arg3 == 0) {
    return false;
  }
  LVar1 = RegSetValueExA(*(HKEY *)self,arg1,0,3,arg2,arg3);
  return (bool)('\x01' - (LVar1 != 0));
}
