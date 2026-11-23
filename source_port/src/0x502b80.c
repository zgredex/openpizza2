// AI_SelectActionForType: ported from Pizza Connection 2 at 0x502b80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502b80
#include "pc2_port.h"

uint32_t __fastcall AI_SelectActionForType(int arg1)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  
  switch(*(uint32_t *)(arg1 + 0x40)) {
  case 1:
    uvalue2 = AI_SelectExpansionAction(arg1);
    return uvalue2;
  case 2:
    uvalue2 = AI_SelectStrategyAction(arg1);
    return uvalue2;
  case 3:
    uvalue1 = Random_RangeFast(0,100);
    if ((intptr_t)uvalue1 < 0x32) {
      uvalue2 = AI_SelectRandomAction(arg1);
      return uvalue2;
    }
    break;
  case 4:
    uvalue1 = Random_RangeFast(0,100);
    if (0x31 < (intptr_t)uvalue1) {
LAB_00502c1c:
      uvalue2 = AI_SelectStrategyAction(arg1);
      return uvalue2;
    }
    break;
  case 5:
    uvalue1 = Random_RangeFast(0,100);
    if ((intptr_t)uvalue1 < 0x32) {
      uvalue2 = AI_SelectStrategyAction(arg1);
      return uvalue2;
    }
    goto LAB_00502c0c;
  case 6:
    uvalue1 = Random_RangeFast(0,300);
    if (99 < (intptr_t)uvalue1) {
      if (200 < (intptr_t)uvalue1) goto LAB_00502c1c;
      break;
    }
  case 0:
LAB_00502c0c:
    uvalue2 = AI_SelectRandomAction(arg1);
    return uvalue2;
  default:
    return 0;
  }
  uvalue2 = AI_SelectExpansionAction(arg1);
  return uvalue2;
}
