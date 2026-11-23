// UI_CreateInfoPanel: ported from Pizza Connection 2 at 0x427a80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x427a80
#include "pc2_port.h"


void * __cdecl UI_CreateInfoPanel(int *arg1)

{
  int value1;
  void *self;
  
  value1 = UI_CreateWindow(DAT_0057c5e0,0x237,0xf8,s_DUMMYSPRITE_spr_00563e10,&LAB_004d02e0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddImage(self,0x3f4,1,3,s_R_INFO__00_spr_00563e00,1,0);
  UI_AddImage(self,0x3f8,1,0x7b,s_R_BILANZ__00_spr_00563da8,1,0);
  UI_AddImage(self,0x3f9,1,0x99,s_R_WERBUNG__00_spr_00563d94,1,0);
  UI_AddImage(self,0x3fd,1,0x111,s_R_LUPE__00_spr_00563d5c,1,0);
  UI_AddImage(self,0x3fe,1,0x21,s_R_CHARAKTER__00_spr_00564e78,1,0);
  UI_AddImage(self,0x401,1,0x5d,s_R_MISSIONEN__00_spr_00564e64,1,0);
  UI_AddImage(self,0x402,1,0x3f,s_R_FILIALBILANZ__00_spr_00564e24,1,0);
  UI_AddImage(self,0x404,1,0xd5,s_R_LIEFER__00_spr_00564ea4,1,0);
  UI_AddImage(self,0x403,1,0xf3,s_R_BAUEN_SP__00_spr_00564e10,1,0);
  return self;
}
