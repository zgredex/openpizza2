// Game_SetDateTime: ported from Pizza Connection 2 at 0x552921.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552921
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
Game_SetDateTime(int arg1,int arg2,uint32_t arg3,int arg4,int arg5,int arg6,
                int arg7,int arg8,int arg9,int arg10,int arg11)

{
  int value1;
  int value2;
  
  if (arg2 == 1) {
    if ((arg3 & 3) == 0) {
      value1 = *(int *)(&DAT_0057719c + arg4 * 4);
    }
    else {
      value1 = *(int *)(&DAT_005771d0 + arg4 * 4);
    }
    value2 = (intptr_t)(arg3 * 0x16d + -0x63db + value1 + 1 + ((intptr_t)(arg3 - 1) >> 2)) % 7;
    if (arg6 < value2) {
      value1 = value1 + 1 + (arg5 * 7 - value2) + arg6;
    }
    else {
      value1 = value1 + -6 + (arg5 * 7 - value2) + arg6;
    }
    if (arg5 == 5) {
      if ((arg3 & 3) == 0) {
        value2 = *(int *)(&DAT_005771a0 + arg4 * 4);
      }
      else {
        value2 = *(int *)(&DAT_005771d4 + arg4 * 4);
      }
      if (value2 < value1) {
        value1 = value1 + -7;
      }
    }
  }
  else {
    if ((arg3 & 3) == 0) {
      value1 = *(int *)(&DAT_0057719c + arg4 * 4);
    }
    else {
      value1 = *(int *)(&DAT_005771d0 + arg4 * 4);
    }
    value1 = value1 + arg7;
  }
  if (arg1 == 1) {
    DAT_00576ac8 = arg3;
    DAT_00576acc = value1;
    DAT_00576ad0 = ((arg8 * 0x3c + arg9) * 0x3c + arg10) * 1000 + arg11;
    return;
  }
  DAT_00576ae0 = ((arg8 * 0x3c + arg9) * 0x3c + _DAT_00576a38 + arg10) * 1000 + arg11;
  if (DAT_00576ae0 < 0) {
    DAT_00576ae0 = DAT_00576ae0 + 86400000;
    DAT_00576adc = value1 + -1;
  }
  else {
    if (DAT_00576ae0 < 86400000) {
      DAT_00576ad8 = arg3;
      DAT_00576adc = value1;
      return;
    }
    DAT_00576ae0 = DAT_00576ae0 + -86400000;
    DAT_00576adc = value1 + 1;
  }
  DAT_00576ad8 = arg3;
  return;
}
