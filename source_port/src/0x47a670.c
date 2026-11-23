// Stats_GetGroupScore: ported from Pizza Connection 2 at 0x47a670.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a670
#include "pc2_port.h"

double __thiscall Stats_GetGroupScore(int arg1,uint32_t arg2,int arg3)

{
  double fVar1;
  double fVar2;
  double fVar3;
  double fVar4;
  double fVar5;
  
  fVar1 = (double)0.0;
  switch(arg2) {
  case 0:
    fVar1 = Stats_SumFilteredFloats2(arg1,1,-1,arg3);
    return fVar1;
  case 1:
    fVar1 = Stats_SumFilteredFloats2(arg1,6,-1,arg3);
    fVar5 = Stats_SumFilteredFloats2(arg1,7,-1,arg3);
    fVar2 = Stats_SumFilteredFloats2(arg1,8,-1,arg3);
    fVar3 = Stats_SumFilteredFloats2(arg1,10,-1,arg3);
    fVar4 = Stats_SumFilteredFloats2(arg1,0xd,-1,arg3);
    return fVar4 + (double)(float)(fVar3 + (double)(float)(fVar2 + (double)(float)(fVar5 + (
                                                  double)(float)fVar1)));
  case 2:
    fVar1 = Stats_SumFilteredFloats2(arg1,0xc,-1,arg3);
    return fVar1;
  case 3:
    fVar1 = Stats_SumFilteredFloats2(arg1,0x10,-1,arg3);
    fVar5 = Stats_SumFilteredFloats2(arg1,0x11,-1,arg3);
    return fVar5 + (double)(float)fVar1;
  case 4:
  case 5:
    break;
  case 6:
    fVar1 = Stats_SumFilteredFloats2(arg1,0x13,-1,arg3);
    return fVar1;
  default:
    NoOp_Stub();
    fVar1 = (double)(float)fVar1;
  }
  return fVar1;
}
