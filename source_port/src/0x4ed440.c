// Map_SetScrollPosition: ported from Pizza Connection 2 at 0x4ed440.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed440
#include "pc2_port.h"

uint32_t __thiscall Map_SetScrollPosition(void *self,int arg1,int arg2)

{
  bool flag1;
  bool flag2;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  
  flag1 = UI_ClampScrollY(self,arg1);
  flag2 = Map_ClampScrollY(self,arg2);
  if ((CONCAT31(extraout_var,flag1) == 0) && (CONCAT31(extraout_var_00,flag2) == 0)) {
    return 0;
  }
  return 1;
}
