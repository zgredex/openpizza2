// Settings_LoadFromRegistry: ported from Pizza Connection 2 at 0x406bb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x406bb0
#include "pc2_port.h"

bool Settings_LoadFromRegistry(void)

{
  HKEY pHVar1;
  LPBYTE pBVar2;
  LPBYTE pBVar3;
  uint32_t uvalue4;
  BYTE *pBVar5;
  uint32_t local_14;
  uint32_t local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557d58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  Clear_Ptr(&local_14);
  local_4 = 0;
  pHVar1 = RegistryKey_OpenOrCreate
                     (&local_14,(HKEY)0x80000002,s_SOFTWARE_Software2000_Pizza_Conn_00563c5c);
  if (pHVar1 == (HKEY)0x0) {
    local_4 = 0xffffffff;
    RegistryKey_CloseThunk(&local_14);
    ExceptionList = local_c;
    return false;
  }
  pBVar2 = RegistryKey_ReadValue(&local_14,s_Options_00563c54,&local_10);
  if (0x163 < local_10) {
    local_10 = 0x164;
  }
  pBVar3 = pBVar2;
  pBVar5 = (BYTE *)&DAT_0057b8a8;
  for (uvalue4 = local_10 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *(uint32_t *)pBVar5 = *(uint32_t *)pBVar3;
    pBVar3 = pBVar3 + 4;
    pBVar5 = pBVar5 + 4;
  }
  for (local_10 = local_10 & 3; local_10 != 0; local_10 = local_10 - 1) {
    *pBVar5 = *pBVar3;
    pBVar3 = pBVar3 + 1;
    pBVar5 = pBVar5 + 1;
  }
  if (pBVar2 == (LPBYTE)0x0) {
    Mem_Free((LPVOID)0x0);
  }
  pBVar3 = RegistryKey_ReadValue(&local_14,s_Sound_00563c4c,&local_10);
  if (pBVar3 != (LPBYTE)0x0) {
    DAT_00575090 = *(uint32_t *)pBVar3;
    DAT_00575094 = *(uint32_t *)(pBVar3 + 4);
    DAT_00575098 = *(uint32_t *)(pBVar3 + 8);
    DAT_0057509c = *(uint32_t *)(pBVar3 + 0xc);
  }
  RegistryKey_Close(&local_14);
  local_4 = 0xffffffff;
  RegistryKey_CloseThunk(&local_14);
  ExceptionList = local_c;
  return pBVar2 != (LPBYTE)0x0;
}
