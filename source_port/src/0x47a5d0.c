// Stats_SumFloatMatrix: ported from Pizza Connection 2 at 0x47a5d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a5d0
#include "pc2_port.h"

double __thiscall Stats_SumFloatMatrix(int arg1,int arg2,int arg3)

{
  int value1;
  float *fptr2;
  int value3;
  float *fptr4;
  double fVar5;
  
  fVar5 = (double)0.0;
  value3 = 0;
  fptr4 = (float *)(arg1 + 0x410);
  do {
    if ((value3 == arg3) || (arg3 == -1)) {
      value1 = 0;
      fptr2 = fptr4;
      do {
        if ((value1 == arg2) || (arg2 == -1)) {
          fVar5 = fVar5 + (double)*fptr2;
        }
        value1 = value1 + 1;
        fptr2 = fptr2 + 9;
      } while (value1 < 8);
    }
    value3 = value3 + 1;
    fptr4 = fptr4 + 1;
  } while (value3 < 9);
  return fVar5;
}
