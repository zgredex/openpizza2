// UI_CreateRestaurantInfoPanel: ported from Pizza Connection 2 at 0x443980.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x443980
#include "pc2_port.h"


void * __cdecl UI_CreateRestaurantInfoPanel(int *arg1)

{
  int value1;
  void *self;
  
  value1 = UI_CreateWindow(DAT_0057c5e0,0x237,0xf8,s_DUMMYSPRITE_spr_00563e10,&LAB_004d12c0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddImage(self,0x3f4,1,3,s_R_INFO__00_spr_00563e00,1,0);
  UI_AddImage(self,0x3f5,1,0x21,s_R_PERSONAL__00_spr_00563dec,1,0);
  UI_AddImage(self,0x3f6,1,0x3f,s_R_EINRICHTUNG__00_spr_00563dd4,1,0);
  UI_AddImage(self,0x3f7,1,0x5d,s_R_SPEISEKARTE__00_spr_00563dbc,1,0);
  UI_AddImage(self,0x3fd,1,0x111,s_R_LUPE__00_spr_00563d5c,1,0);
  UI_AddImage(self,0x3fe,1,0x7b,s_R_WETTBEWERB__00_spr_005662cc,1,0);
  UI_AddImage(self,0x3ff,1,0x99,s_R_AERGERN__00_spr_005662b8,1,0);
  UI_AddImage(self,0x400,1,0xb7,s_R_ANGREIFEN__00_spr_005662a4,1,0);
  UI_AddImage(self,0x401,1,0xd5,s_R_MANAGER__00_spr_00563d6c,1,0);
  return self;
}
