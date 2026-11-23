// RenovationScreen_UpdatePage: ported from Pizza Connection 2 at 0x492390.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x492390
#include "pc2_port.h"

void __cdecl RenovationScreen_UpdatePage(void *arg1)

{
  int value1;
  uint32_t extraout_EDX;
  uint32_t uvalue2;
  uint32_t extraout_EDX_00;
  int value3;
  int value4;
  
                    /* Refreshes the renovation/decoration page. */
  DAT_0057c6b4 = *(void **)(DAT_0057c670 + 0x9c);
  UI_FillObjectWithPaletteColor(arg1,0x4ff,DAT_0057c6bc);
  RenovationScreen_UpdateCost(arg1);
  Array_SetField14ByKey(arg1,0x4ff,0);
  Gadget_SetText(arg1,0x1f45,(&DAT_0058319c)[DAT_0057c6c0]);
  Gadget_SetText(arg1,0x1f48,(&DAT_00583190)[DAT_0057c6c4]);
  value3 = 0;
  uvalue2 = extraout_EDX;
  do {
    value4 = DAT_00582320;
    value1 = Branch_ComputeBuildingRating(DAT_0057c6b4,uvalue2,value3);
    Rating_UpdateBarByKey(arg1,0x4f2,value3,value1,value4);
    value3 = value3 + 1;
    uvalue2 = extraout_EDX_00;
  } while (value3 < 8);
  return;
}
