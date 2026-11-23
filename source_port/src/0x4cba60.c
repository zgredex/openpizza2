// Config_WriteRegistryBlock: ported from Pizza Connection 2 at 0x4cba60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cba60
#include "pc2_port.h"


uint32_t __cdecl Config_WriteRegistryBlock(LPCSTR arg1,BYTE *arg2)

{
  HKEY pHVar1;
  uint32_t local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558bd8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  Clear_Ptr(&local_10);
  local_4 = 0;
  pHVar1 = RegistryKey_OpenOrCreate
                     (&local_10,(HKEY)0x80000002,s_SOFTWARE_Software2000_Pizza_Conn_00563c5c);
  if (pHVar1 == (HKEY)0x0) {
    local_4 = 0xffffffff;
    RegistryKey_CloseThunk(&local_10);
    ExceptionList = local_c;
    return 0;
  }
  RegistryKey_WriteValue(&local_10,arg1,arg2,0xcc);
  RegistryKey_Close(&local_10);
  local_4 = 0xffffffff;
  RegistryKey_CloseThunk(&local_10);
  ExceptionList = local_c;
  return 1;
}
