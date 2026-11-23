// RegistryKey_OpenOrCreate: ported from Pizza Connection 2 at 0x4031b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4031b0
#include "pc2_port.h"

HKEY __thiscall RegistryKey_OpenOrCreate(void *self,HKEY arg1,LPCSTR arg2)

{
  LSTATUS LVar1;
  
  if (*(HKEY *)self != (HKEY)0x0) {
    RegCloseKey(*(HKEY *)self);
  }
  LVar1 = RegOpenKeyExA(arg1,arg2,0,0x2001f,self);
  if (LVar1 != 0) {
    LVar1 = RegCreateKeyA(arg1,arg2,self);
    if (LVar1 != 0) {
      return (HKEY)0x0;
    }
  }
  return *(HKEY *)self;
}
