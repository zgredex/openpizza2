// Grid_GetDirectionBetweenNodes: ported from Pizza Connection 2 at 0x4f57f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f57f0
#include "pc2_port.h"

uint32_t Grid_GetDirectionBetweenNodes(int arg1,int arg2)

{
  int value1;
  int value2;
  bool flag3;
  
  value1 = *(int *)(arg1 + 0xc);
  value2 = *(int *)(arg2 + 0xc);
  if ((value1 == value2) && (*(int *)(arg2 + 0x10) < *(int *)(arg1 + 0x10))) {
    return 6;
  }
  flag3 = value1 - value2 < 0;
  if (value1 < value2) {
    if (*(int *)(arg2 + 0x10) < *(int *)(arg1 + 0x10)) {
      return 2;
    }
    flag3 = value1 - value2 < 0;
    if (value1 < value2) {
      if (*(int *)(arg1 + 0x10) == *(int *)(arg2 + 0x10)) {
        return 5;
      }
      flag3 = value1 - value2 < 0;
      if (value1 < value2) {
        if (*(int *)(arg1 + 0x10) < *(int *)(arg2 + 0x10)) {
          return 1;
        }
        flag3 = value1 - value2 < 0;
      }
    }
  }
  if (value1 == value2) {
    if (*(int *)(arg1 + 0x10) < *(int *)(arg2 + 0x10)) {
      return 4;
    }
    flag3 = value1 - value2 < 0;
  }
  if (value1 != value2 && SBORROW4(value1,value2) == flag3) {
    if (*(int *)(arg1 + 0x10) < *(int *)(arg2 + 0x10)) {
      return 0;
    }
    if (value2 < value1) {
      if (*(int *)(arg1 + 0x10) == *(int *)(arg2 + 0x10)) {
        return 7;
      }
      if ((value2 < value1) && (*(int *)(arg2 + 0x10) < *(int *)(arg1 + 0x10))) {
        return 3;
      }
    }
  }
  Debug_WarningMessageBox();
  return 0xffffffff;
}
