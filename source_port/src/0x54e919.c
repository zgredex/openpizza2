// __NLG_Notify1: ported from Pizza Connection 2 at 0x54e919.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e919
#include "pc2_port.h"

/* Library Function - Single Match
    __NLG_Notify1
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall __NLG_Notify1(uint32_t arg1)

{
  uint32_t in_EAX;
  uint32_t unaff_EBP;
  
  DAT_00576738 = arg1;
  DAT_00576734 = in_EAX;
  DAT_0057673c = unaff_EBP;
  return;
}
