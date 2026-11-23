// File_ReadHeaderDwords: ported from Pizza Connection 2 at 0x403960.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403960
#include "pc2_port.h"

uint32_t __cdecl File_ReadHeaderDwords(LPCSTR arg1,uint32_t *arg2,uint32_t *arg3)

{
  FILE *pFVar1;
  char local_40 [28];
  uint32_t local_24;
  uint32_t local_20;
  
  pFVar1 = (FILE *)CRT_Fopen(arg1,&DAT_00563184);
  if (pFVar1 == (FILE *)0x0) {
    return 0;
  }
  CRT_FreadLocked(local_40,1,0x40,(int *)pFVar1);
  CRT_Fclose(pFVar1);
  *arg2 = local_24;
  *arg3 = local_20;
  return 1;
}
