// Screen_BuildOptionsSidebar: ported from Pizza Connection 2 at 0x425e70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x425e70
#include "pc2_port.h"


void * __cdecl Screen_BuildOptionsSidebar(int *arg1)

{
  int value1;
  void *self;
  
  value1 = UI_CreateWindow(DAT_0057c5e0,0x237,0xf8,s_DUMMYSPRITE_spr_00563e10,&LAB_004d19d0);
  *arg1 = value1;
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,value1,(int *)0x0);
  if (self == (void *)0x0) {
    return (void *)0x0;
  }
  UI_AddImage(self,0x3f0,1,0x5d,s_R_GRAFIK__00_spr_00564d0c,1,0);
  UI_AddImage(self,0x3f1,1,3,s_R_LADEN__00_spr_00564cfc,1,0);
  UI_AddImage(self,0x3f3,1,0x3f,s_R_SOUND__00_spr_00564cec,1,0);
  UI_AddImage(self,0x3f4,1,0x21,s_R_SPEICHERN__00_spr_00564cd8,1,0);
  UI_AddImage(self,0x3f5,1,0x7b,s_R_HELP__00_spr_00564cc8,1,0);
  return self;
}
