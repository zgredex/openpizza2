// FUN_0055674e: ported from Pizza Connection 2 at 0x55674e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55674e
#include "pc2_port.h"

int __cdecl FUN_0055674e(int arg1)

{
  int value1;
  bool flag2;
  
  if (arg1 == -2) {
    DAT_0058596c = 1;
                    /* WARNING: Could not recover jumptable at 0x00556768. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    value1 = GetOEMCP();
    return value1;
  }
  if (arg1 == -3) {
    DAT_0058596c = 1;
                    /* WARNING: Could not recover jumptable at 0x0055677d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    value1 = GetACP();
    return value1;
  }
  flag2 = arg1 == -4;
  if (flag2) {
    arg1 = DAT_005857dc;
  }
  DAT_0058596c = (uint32_t)flag2;
  return arg1;
}
