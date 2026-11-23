// __CallSettingFrame@12: ported from Pizza Connection 2 at 0x553490.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553490
#include "pc2_port.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __CallSettingFrame_12(uint32_t arg1,uint32_t arg2,int arg3)

{
  code *cptr1;
  
  cptr1 = (code *)__NLG_Notify1(arg3);
  (*cptr1)();
  if (arg3 == 0x100) {
    arg3 = 2;
  }
  __NLG_Notify1(arg3);
  return;
}
