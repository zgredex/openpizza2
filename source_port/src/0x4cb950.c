// HighScore_ReadRegistryBlob: ported from Pizza Connection 2 at 0x4cb950.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cb950
#include "pc2_port.h"

uint32_t __cdecl HighScore_ReadRegistryBlob(LPCSTR arg1,BYTE *arg2)

{
  HKEY pHVar1;
  LPBYTE pBVar2;
  uint32_t uvalue3;
  LPBYTE pBVar4;
  uint32_t local_14;
  uint32_t local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558bb8;
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
    return 0;
  }
  pBVar2 = RegistryKey_ReadValue(&local_14,arg1,&local_10);
  RegistryKey_Close(&local_14);
  if (pBVar2 == (LPBYTE)0x0) {
    local_4 = 0xffffffff;
    RegistryKey_CloseThunk(&local_14);
    ExceptionList = local_c;
    return 0;
  }
  if (0xcb < local_10) {
    local_10 = 0xcc;
  }
  pBVar4 = pBVar2;
  for (uvalue3 = local_10 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *(uint32_t *)arg2 = *(uint32_t *)pBVar4;
    pBVar4 = pBVar4 + 4;
    arg2 = arg2 + 4;
  }
  for (local_10 = local_10 & 3; local_10 != 0; local_10 = local_10 - 1) {
    *arg2 = *pBVar4;
    pBVar4 = pBVar4 + 1;
    arg2 = arg2 + 1;
  }
  Mem_Free(pBVar2);
  local_4 = 0xffffffff;
  RegistryKey_CloseThunk(&local_14);
  ExceptionList = local_c;
  return 1;
}
