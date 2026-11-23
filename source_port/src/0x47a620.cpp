// Grid_GetMaxValue: ported from Pizza Connection 2 at 0x47a620.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a620
#include "pc2_port.h"

double __fastcall Grid_GetMaxValue(int arg1)

{
  float *fptr1;
  int value2;
  float *fptr3;
  int value4;
  float local_4;
  
  local_4 = 0.0;
  fptr3 = (float *)(arg1 + 0x410);
  value4 = 9;
  do {
    value2 = 8;
    fptr1 = fptr3;
    do {
      if (local_4 < *fptr1) {
        local_4 = *fptr1;
      }
      fptr1 = fptr1 + 9;
      value2 = value2 + -1;
    } while (value2 != 0);
    fptr3 = fptr3 + 1;
    value4 = value4 + -1;
  } while (value4 != 0);
  return (double)local_4;
}
