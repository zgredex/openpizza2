// File_Exists: ported from Pizza Connection 2 at 0x4a19e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a19e0
#include "pc2_port.h"

uint32_t __cdecl File_Exists(LPCSTR arg1)

{
  FILE *pFVar1;
  uint32_t uvalue2;
  
  if (arg1 != (LPCSTR)0x0) {
    pFVar1 = (FILE *)CRT_Fopen(arg1,&DAT_00563184);
    if (pFVar1 != (FILE *)0x0) {
      uvalue2 = CRT_Fclose(pFVar1);
      return CONCAT31((int3)((uint32_t)uvalue2 >> 8),1);
    }
  }
  return 0;
}
