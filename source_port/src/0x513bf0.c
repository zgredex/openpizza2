// Branch_ComputeRecipePrice: ported from Pizza Connection 2 at 0x513bf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513bf0
#include "pc2_port.h"

double __thiscall Branch_ComputeRecipePrice(int arg1,int arg2,int arg3)

{
  int value1;
  double fVar2;
  double fVar3;
  
  if (arg3 == -999) {
    arg3 = *(int *)(arg2 + 0x14a8);
  }
  value1 = *(int *)(arg2 + 0x14ac);
  fVar2 = Branch_GetBuildingValue(arg2);
  fVar3 = Get_Float44(arg1);
  return fVar3 * (double)(float)((double)arg3 * (double)0.01 * fVar2) + (double)value1;
}
