// Map_CountBuildableNeighbors: ported from Pizza Connection 2 at 0x479750.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x479750
#include "pc2_port.h"

int Map_CountBuildableNeighbors(int arg1,int arg2,int arg3)

{
  int value1;
  short svalue2;
  short svalue3;
  int value4;
  
  value4 = 0;
  value1 = arg3 + (arg1 * 0x50 + arg2) * 8;
  if (((((*(short *)(value1 + 0x14) == 0) || (*(short *)(value1 + 0x14) == 2)) &&
       ((*(short *)(value1 + 0x1c) == 0 || (*(short *)(value1 + 0x1c) == 2)))) &&
      ((*(short *)(value1 + 0x294) == 0 || (*(short *)(value1 + 0x294) == 2)))) &&
     ((*(short *)(value1 + 0x29c) == 0 || (*(short *)(value1 + 0x29c) == 2)))) {
    value4 = 1;
  }
  if ((((*(short *)(value1 + -4) == 0) || (*(short *)(value1 + -4) == 2)) &&
      ((*(short *)(value1 + -0xc) == 0 || (*(short *)(value1 + -0xc) == 2)))) &&
     (((*(short *)(value1 + 0x27c) == 0 || (*(short *)(value1 + 0x27c) == 2)) &&
      ((*(short *)(value1 + 0x274) == 0 || (*(short *)(value1 + 0x274) == 2)))))) {
    value4 = value4 + 1;
  }
  if (((((*(short *)(value1 + 0x504) == 0) || (*(short *)(value1 + 0x504) == 2)) &&
       ((*(short *)(value1 + 0x50c) == 0 || (*(short *)(value1 + 0x50c) == 2)))) &&
      ((*(short *)(value1 + 0x784) == 0 || (*(short *)(value1 + 0x784) == 2)))) &&
     ((*(short *)(value1 + 0x78c) == 0 || (*(short *)(value1 + 0x78c) == 2)))) {
    value4 = value4 + 1;
  }
  if (((((*(short *)(value1 + -0x27c) == 0) || (*(short *)(value1 + -0x27c) == 2)) &&
       ((*(short *)(value1 + -0x274) == 0 || (*(short *)(value1 + -0x274) == 2)))) &&
      ((*(short *)(value1 + -0x4fc) == 0 || (*(short *)(value1 + -0x4fc) == 2)))) &&
     ((*(short *)(value1 + -0x4f4) == 0 || (*(short *)(value1 + -0x4f4) == 2)))) {
    value4 = value4 + 1;
  }
  if ((((*(short *)(value1 + -0x26c) == 0) || (*(short *)(value1 + -0x26c) == 2)) &&
      ((*(short *)(value1 + -0x4ec) == 0 || (*(short *)(value1 + -0x4ec) == 2)))) &&
     (((*(short *)(value1 + -0x264) == 0 || (*(short *)(value1 + -0x264) == 2)) &&
      ((*(short *)(value1 + -0x4e4) == 0 || (*(short *)(value1 + -0x4e4) == 2)))))) {
    value4 = value4 + 1;
  }
  if ((((*(short *)(value1 + 0x514) == 0) || (*(short *)(value1 + 0x514) == 2)) &&
      ((*(short *)(value1 + 0x51c) == 0 || (*(short *)(value1 + 0x51c) == 2)))) &&
     (((*(short *)(value1 + 0x794) == 0 || (*(short *)(value1 + 0x794) == 2)) &&
      ((*(short *)(value1 + 0x79c) == 0 || (*(short *)(value1 + 0x79c) == 2)))))) {
    value4 = value4 + 1;
  }
  svalue2 = *(short *)(value1 + 0x4fc);
  svalue3 = *(short *)(value1 + 0x774);
  if (((((svalue2 == 0) || (svalue2 == 2)) && ((svalue3 == 0 || (svalue3 == 2)))) &&
      ((svalue2 == 0 || (svalue2 == 2)))) && ((svalue3 == 0 || (svalue3 == 2)))) {
    value4 = value4 + 1;
  }
  svalue2 = *(short *)(value1 + -0x284);
  svalue3 = *(short *)(value1 + -0x50c);
  if ((((svalue2 == 0) || (svalue2 == 2)) && ((svalue3 == 0 || (svalue3 == 2)))) &&
     (((svalue2 == 0 || (svalue2 == 2)) && ((svalue3 == 0 || (svalue3 == 2)))))) {
    value4 = value4 + 1;
  }
  return value4;
}
