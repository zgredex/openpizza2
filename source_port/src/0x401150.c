// Record_SumFloatArray26: ported from Pizza Connection 2 at 0x401150.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401150
#include "pc2_port.h"

double __fastcall Record_SumFloatArray26(int arg1)

{
  float *fptr1;
  int value2;
  double fVar3;
  
  fVar3 = (double)0.0;
  fptr1 = (float *)(arg1 + 0x10);
  value2 = 0x1a;
  do {
    fVar3 = fVar3 + (double)*fptr1;
    fptr1 = fptr1 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  return fVar3;
}
