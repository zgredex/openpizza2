// Object_SumFloat25: ported from Pizza Connection 2 at 0x401170.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401170
#include "pc2_port.h"

double __fastcall Object_SumFloat25(int arg1)

{
  float *fptr1;
  int value2;
  double fVar3;
  
  fVar3 = (double)0.0;
  fptr1 = (float *)(arg1 + 0x78);
  value2 = 0x19;
  do {
    fVar3 = fVar3 + (double)*fptr1;
    fptr1 = fptr1 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  return fVar3;
}
