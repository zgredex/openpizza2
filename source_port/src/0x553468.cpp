// CRT_ResolveCatchObject: ported from Pizza Connection 2 at 0x553468.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553468
#include "pc2_port.h"

int __cdecl CRT_ResolveCatchObject(int arg1,int *arg2)

{
  int value1;
  int value2;
  
  value1 = arg2[1];
  value2 = *arg2 + arg1;
  if (-1 < value1) {
    value2 = value2 + *(int *)(*(int *)(value1 + arg1) + arg2[2]) + value1;
  }
  return value2;
}
