// Input_MouseHandler: ported from Pizza Connection 2 at 0x4894d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4894d0
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
Input_MouseHandler(void *self,uint32_t arg1,int arg2,int arg3,int *arg4)

{
  uint16_t uvalue1;
  HCURSOR lParam;
  DWORD DVar2;
  int value3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  
  if (arg2 == 0x2a) {
    if (arg3 == 8) {
      if (*(int *)((intptr_t)self + 0x2d98) != 0) {
        if (*(int *)((intptr_t)self + 0x2fc) != 0) {
          if (DAT_0057c658 == 0) {
            DAT_0057c660 = DAT_0057c660 + arg4[2];
            uvalue5 = arg4[3] >> 0x1f;
            uvalue4 = arg4[2];
            value3 = (arg4[3] ^ uvalue5) - uvalue5;
            DAT_0057c664 = DAT_0057c664 + arg4[3];
          }
          else {
            DAT_0057c660 = *arg4 - DAT_0057c628;
            uvalue4 = arg4[1] - DAT_0057c62c;
            value3 = (DAT_0057c660 ^ (intptr_t)DAT_0057c660 >> 0x1f) - ((intptr_t)DAT_0057c660 >> 0x1f);
            DAT_0057c664 = uvalue4;
          }
          DAT_0057c650 = ((uvalue4 ^ (intptr_t)uvalue4 >> 0x1f) - ((intptr_t)uvalue4 >> 0x1f)) + DAT_0057c650 +
                         value3;
          Input_CompleteEvent((void *)((intptr_t)self + 0x2d1c),*(int *)((intptr_t)self + 0x2da4));
        }
        if (DAT_0057c658 == 0) {
          Window_SetCursorPosition(DAT_0057c5e0,DAT_0057c628,DAT_0057c62c,0,0);
        }
      }
    }
    else {
      if (arg3 == 9) {
        *(uint32_t *)((intptr_t)self + 0x2da8) = 0;
        value3 = Input_HandleMapClickAtCell(self,9);
        DAT_0057c620 = *arg4;
        DAT_0057c624 = arg4[1];
        if (value3 == 0) {
          DAT_0057c628 = (DAT_00571950 >> 1) >> ((uint8_t)DAT_00580a50 & 0x1f);
          DAT_0057c62c = (DAT_00571954 >> 1) >> ((uint8_t)DAT_00580a50 & 0x1f);
        }
        else {
          DAT_0057c628 = DAT_0057c620;
          DAT_0057c62c = DAT_0057c624;
        }
        PostMessageA(DAT_0057c5d0,0x400,0,0);
        Window_SetCursorPosition(DAT_0057c5e0,DAT_0057c628,DAT_0057c62c,1,0);
        uvalue1 = GetAsyncKeyState(0x11);
        if ((uvalue1 & 0x8000) == 0) {
          *(uint32_t *)((intptr_t)self + 0x2d98) = 1;
        }
        else {
          *(uint32_t *)((intptr_t)self + 0x2d98) = 2;
        }
        DAT_0057c630 = timeGetTime();
        DAT_0057c664 = 0;
        DAT_0057c660 = 0;
        DAT_0057c650 = 0;
        _DAT_0057c690 = DAT_0057c630;
        _DAT_0057c648 = 0;
        _DAT_0057c64c = 0;
        return;
      }
      if (arg3 == 10) {
        Input_HandleMapClickAtCell(self,10);
        if (*(int *)((intptr_t)self + 0x2d98) != 0) {
          *(uint32_t *)((intptr_t)self + 0x2d98) = 0;
          Window_SetCursorPosition(DAT_0057c5e0,DAT_0057c620,DAT_0057c624,0,0);
          lParam = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
          PostMessageA(DAT_0057c5d0,0x400,0,(LPARAM)lParam);
        }
        if (DAT_0057c650 < 3) {
          DVar2 = timeGetTime();
          if (DVar2 - _DAT_0057c690 < 200) {
            City_OpenBuildingDirectory(self);
          }
        }
        DAT_0057c664 = 0;
        DAT_0057c660 = 0;
        return;
      }
    }
  }
  return;
}
