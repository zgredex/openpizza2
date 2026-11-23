// Screen_RecipeInfoPanel: ported from Pizza Connection 2 at 0x41a6d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x41a6d0
#include "pc2_port.h"


void * __cdecl Screen_RecipeInfoPanel(int *arg1)

{
  int value1;
  void *self;
  
  value1 = UI_CreateWindow(DAT_0057c5e0,0x237,0xf8,s_DUMMYSPRITE_spr_00563e10,&LAB_004d14d0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddImage(self,0x3f4,1,3,s_R_INFO__00_spr_00563e00,1,0);
  UI_AddImage(self,0x3fe,1,0x21,s_R_NEUREZEPT__00_spr_005648d4,1,0);
  UI_AddImage(self,0x3ff,1,0x3f,s_R_ZUTATEN__00_spr_005648c0,1,0);
  UI_AddImage(self,0x400,1,0x5d,s_R_SPEISEKARTE__00_spr_00563dbc,1,0);
  UI_AddImage(self,0x401,1,0x7b,s_R_REZAUTOMATIK__00_spr_005648a8,1,0);
  UI_AddImage(self,0x402,1,0x111,s_R_LUPE__00_spr_00563d5c,1,0);
  UI_AddImage(self,0x403,1,0xb7,s_R_INFOWETT__00_spr_00564894,1,0);
  UI_AddImage(self,0x404,1,0xd5,s_R_NEUREZEPTWETT__00_spr_0056487c,1,0);
  UI_AddImage(self,0x405,1,0xf3,s_R_ZUTATENWETT__00_spr_00564864,1,0);
  return self;
}
