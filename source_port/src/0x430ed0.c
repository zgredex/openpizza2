// UI_CreateInfoPanelBranch: ported from Pizza Connection 2 at 0x430ed0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x430ed0
#include "pc2_port.h"


void * __cdecl UI_CreateInfoPanelBranch(int *arg1)

{
  int value1;
  void *self;
  
  value1 = UI_CreateWindow(DAT_0057c5e0,0x237,0xf8,s_DUMMYSPRITE_spr_00563e10,&LAB_004d1830);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddImage(self,1000,1,0x3f,s_R_FILIALEN__00_spr_00565844,1,0);
  UI_AddImage(self,0x3e9,1,0x21,s_R_PERSONAL__00_spr_00563dec,1,0);
  UI_AddImage(self,0x3ea,1,0x5d,s_R_REZEPTE__00_spr_00565830,1,0);
  UI_AddImage(self,0x3eb,1,0x7b,s_R_BILANZ__00_spr_00563da8,1,0);
  UI_AddImage(self,0x3ec,1,3,s_R_KONKURENT__00_spr_0056581c,1,0);
  UI_AddImage(self,0x3ed,1,0x99,s_R_GLOSSAR__00_spr_00565808,1,0);
  UI_AddImage(self,0x3f1,-4,-0x1e,s_R_CHARAKTER__00_spr_00564e78,1,0);
  return self;
}
