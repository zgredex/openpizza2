// COMDLG32.DLL::GetSaveFileNameA_Thunk: ported from Pizza Connection 2 at 0x54cb80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cb80
#include "pc2_port.h"

BOOL GetSaveFileNameA_Thunk(LPOPENFILENAMEA arg1)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0054cb80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetSaveFileNameA(arg1);
  return BVar1;
}
