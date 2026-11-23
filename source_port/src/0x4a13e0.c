// SaveGame_NextFreeSlot: ported from Pizza Connection 2 at 0x4a13e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a13e0
#include "pc2_port.h"

int SaveGame_NextFreeSlot(void)

{
  FILE *pFVar1;
  int value2;
  CHAR local_104 [260];
  
  value2 = 0;
  String_Format(local_104,(uint8_t *)s_save_games_save__03d_piz_00568198,0);
  pFVar1 = (FILE *)CRT_Fopen(local_104,&DAT_00563184);
  while (pFVar1 != (FILE *)0x0) {
    CRT_Fclose(pFVar1);
    value2 = value2 + 1;
    String_Format(local_104,(uint8_t *)s_save_games_save__03d_piz_00568198,value2);
    pFVar1 = (FILE *)CRT_Fopen(local_104,&DAT_00563184);
  }
  return value2;
}
