// FurnitureMenu_InitOvenPage: ported from Pizza Connection 2 at 0x4c3610.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c3610
#include "pc2_port.h"


void __cdecl FurnitureMenu_InitOvenPage(void *arg1)

{
  int value1;
  int value2;
  char local_100 [256];
  
                    /* Initializes the oven/furniture submenu page. */
  DAT_0057d738 = 0;
  DAT_0057d734 = *(int *)(DAT_0057c670 + 0x220);
  DAT_0057d73c = Branch_CollectOrdersByCategory(*(void **)(DAT_0057c670 + 0x9c),5);
  value2 = 0;
  if (0 < (intptr_t)DAT_0057d73c[5]) {
    do {
      value1 = IDMap_Lookup(DAT_0057d73c,value2,(int *)0x0);
      if (value1 == DAT_0057d734) {
        DAT_0057d738 = value2;
      }
      value2 = value2 + 1;
    } while (value2 < (intptr_t)DAT_0057d73c[5]);
  }
  UI_SetPosition(arg1,&LAB_004c32f0,0);
  if (DAT_0057d734 != 0) {
    OvenPage_FillStatistics(arg1);
    value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(DAT_0057d734 + 4),(int *)0x0);
    String_Format(local_100,(uint8_t *)s_moebel__s_spr_0056ae18,value2 + 0x40);
    UI_SetButtonSpriteByName(arg1,0x1f41,local_100);
  }
  return;
}
