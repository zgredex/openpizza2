// Window_BlitToDC: ported from Pizza Connection 2 at 0x5246e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5246e0
#include "pc2_port.h"

void __thiscall Window_BlitToDC(void *self,uint32_t *arg1,HDC arg2)

{
  int value1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  
  if (((*(int *)((intptr_t)self + 0x284) != 0) && (*(int *)((intptr_t)self + 0x1b4) == 0)) &&
     (*(char *)((intptr_t)DAT_0057c5c8 + 0x30) != '\0')) {
    if (*(int *)((intptr_t)self + 0x1bc) != 0) {
      Rect_ScaleAndOffset(DAT_0057c5c8,(int *)arg1);
      value1 = *(int *)((intptr_t)self + 0x1bc);
      Gfx_BlitClipped16(DAT_0057c5c8,*(HWND *)((intptr_t)self + 0x8320),*(int *)(value1 + 0x18),*arg1,
                        (HDC)arg1[1],arg1[2] - *arg1,arg1[3] - (intptr_t)arg1[1],
                        *(int *)(value1 + 4),*(uint16_t **)(value1 + 8),arg2,-1,(uint16_t *)0xffffffff)
      ;
      return;
    }
    if ((*(int *)((intptr_t)self + 0x1c0) != 0) && (DAT_00584504 != 0)) {
      uvalue3 = ((intptr_t)*arg1 < 0) - 1 & *arg1;
      uvalue5 = ((intptr_t)arg1[1] < 0) - 1 & arg1[1];
      *arg1 = uvalue3;
      arg1[1] = uvalue5;
      uvalue4 = arg1[2];
      if ((intptr_t)*(uint32_t *)((intptr_t)self + 0x270) < (intptr_t)arg1[2]) {
        uvalue4 = *(uint32_t *)((intptr_t)self + 0x270);
      }
      arg1[2] = uvalue4;
      uvalue2 = *(uint32_t *)((intptr_t)self + 0x274);
      if ((intptr_t)arg1[3] <= (intptr_t)*(uint32_t *)((intptr_t)self + 0x274)) {
        uvalue2 = arg1[3];
      }
      arg1[3] = uvalue2;
      Surface_BlitRectRetry
                (DAT_0057c5c8,uvalue3,uvalue5,uvalue4 - uvalue3,uvalue2 - uvalue5,0,*(int *)((intptr_t)self + 0x1c0))
      ;
    }
  }
  return;
}
