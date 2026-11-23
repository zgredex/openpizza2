// Config_SaveOptionsToRegistry: ported from Pizza Connection 2 at 0x406cd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x406cd0
#include "pc2_port.h"


void Config_SaveOptionsToRegistry(void)

{
  HKEY pHVar1;
  uint32_t local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557d78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  Clear_Ptr(&local_10);
  local_4 = 0;
  pHVar1 = RegistryKey_OpenOrCreate
                     (&local_10,(HKEY)0x80000002,s_SOFTWARE_Software2000_Pizza_Conn_00563c5c);
  if (pHVar1 != (HKEY)0x0) {
    DAT_0057b8a8 = 0x3ee;
    RegistryKey_WriteValue(&local_10,s_Options_00563c54,(BYTE *)&DAT_0057b8a8,0x164);
    RegistryKey_WriteValue(&local_10,s_Sound_00563c4c,(BYTE *)&DAT_00575090,0x10);
    RegistryKey_Close(&local_10);
  }
  local_4 = 0xffffffff;
  RegistryKey_CloseThunk(&local_10);
  ExceptionList = local_c;
  return;
}
