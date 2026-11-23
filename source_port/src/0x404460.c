// ResourceManager_OpenArchivePath: ported from Pizza Connection 2 at 0x404460.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x404460
#include "pc2_port.h"

uint32_t __cdecl ResourceManager_OpenArchivePath(void *arg1)

{
  DWORD DVar1;
  uint32_t uvalue2;
  CHAR local_104 [260];
  
  String_Format(local_104,(uint8_t *)s__sresources__s_00563a50,&DAT_0057c278);
  DVar1 = GetFileAttributesA(local_104);
  if ((DVar1 != 0xffffffff) && ((DVar1 & 0x10) == 0)) {
LAB_004044d2:
    Pak_Open(arg1,local_104);
    return 1;
  }
  String_Format(local_104,(uint8_t *)s__c__resources__s_00563a3c,(intptr_t)DAT_0057c5c4);
  DVar1 = GetFileAttributesA(local_104);
  if (DVar1 != 0xffffffff) {
    uvalue2 = DVar1 & 0x8000000f;
    if ((intptr_t)uvalue2 < 0) {
      uvalue2 = (uvalue2 - 1 | 0xfffffff0) + 1;
    }
    if (uvalue2 == 0) goto LAB_004044d2;
  }
  return 0;
}
