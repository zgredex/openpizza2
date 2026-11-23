// Renderer_FlipPrimarySurface: ported from Pizza Connection 2 at 0x539860.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x539860
#include "pc2_port.h"

void __fastcall Renderer_FlipPrimarySurface(int arg1)

{
  int *ptr1;
  DWORD DVar2;
  int value3;
  uint32_t uvalue4;
  
  uvalue4 = 1;
  if (DAT_005844fc != 0) {
    DVar2 = timeGetTime();
    uvalue4 = DVar2 + 30000;
    while ((DAT_00584500 != 0 && (DVar2 = timeGetTime(), DVar2 < uvalue4))) {
      Win32_PumpMessages();
      Sleep(0x14);
    }
    CRT_Exit(0x32);
  }
  while( true ) {
    while( true ) {
      while( true ) {
        ptr1 = *(int **)(*(int *)(arg1 + 0x40) + 4);
        value3 = (**(code **)(*ptr1 + 0x2c))(ptr1,0,1);
        if (-0x7789fe3e < value3) {
          if (value3 == 0) {
            *(uint32_t *)(arg1 + 0x80) = *(uint32_t *)(arg1 + 0x80) ^ 1;
            return;
          }
          return;
        }
        if (value3 != -0x7789fe3e) break;
        if (uvalue4 == 0) {
          Thread_WaitForExit(arg1);
        }
        else {
          Thread_WaitForExit(arg1);
          uvalue4 = 0;
        }
      }
      if (value3 != -0x7789ff1f) break;
      value3 = (**(code **)(*(int *)**(uint32_t **)(arg1 + 0x40) + 0x50))
                        ((int *)**(uint32_t **)(arg1 + 0x40),*(uint32_t *)(arg1 + 0x44),
                         0x13);
      if (value3 != 0) {
        return;
      }
    }
    if (value3 != -0x7789fe52) break;
    Sleep(1);
  }
  return;
}
