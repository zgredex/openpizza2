// SaveMenu_MenuFileExists: ported from Pizza Connection 2 at 0x49b880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49b880
#include "pc2_port.h"

uint32_t __cdecl SaveMenu_MenuFileExists(uint32_t arg1)

{
  FILE *pFVar1;
  uint32_t uvalue2;
  CHAR local_200 [512];
  
  String_Format(local_200,(uint8_t *)s_save_menu__s_men_00568a44,arg1);
  pFVar1 = (FILE *)CRT_Fopen(local_200,&DAT_00563184);
  if (pFVar1 == (FILE *)0x0) {
    return 0;
  }
  uvalue2 = CRT_Fclose(pFVar1);
  return CONCAT31((int3)((uint32_t)uvalue2 >> 8),1);
}
