// Rating_GetComposite: ported from Pizza Connection 2 at 0x4d4000.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d4000
#include "pc2_port.h"

int __fastcall Rating_GetComposite(int arg1)

{
  int value1;
  int value2;
  int value3;
  uint32_t uvalue4;
  int value5;
  int value6;
  int value7;
  
  value1 = Rating_ClampAdjusted(arg1);
  value2 = Rating_AdjustA(arg1);
  value5 = *(int *)(arg1 + 0xc);
  value3 = Rating_AdjustB(arg1);
  value6 = value5 + value3 + value2 + value1;
  value7 = value6 >> 2;
  if (value2 <= value1) {
    value1 = value2;
  }
  if (value3 <= value1) {
    value1 = value3;
  }
  if (value5 <= value1) {
    value1 = value5;
  }
  uvalue4 = State_HasFlags(arg1);
  if ((char)uvalue4 != '\0') {
    value7 = value7 - (value6 >> 0x1f) >> 1;
  }
  value5 = value1 * 4;
  if (value7 <= value1 * 4) {
    value5 = value7;
  }
  return value5;
}
