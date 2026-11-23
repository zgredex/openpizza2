// Game_ComputeObjectValue: ported from Pizza Connection 2 at 0x50d310.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50d310
#include "pc2_port.h"

float __thiscall Game_ComputeObjectValue(void *arg1,float arg2)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  bool flag4;
  
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x110));
  uvalue2 = UI_HitTestChildPoint(arg1,arg2);
  value3 = Game_GetPlayerSubmapValue
                    (DAT_0057c670,*(int *)(*(int *)((intptr_t)arg1 + 0xf4) + 8),
                     *(int *)(*(int *)((intptr_t)arg1 + 0xf4) + 0x2c));
  switch(*(uint32_t *)((intptr_t)arg1 + 0x30)) {
  case 0xd:
    value1 = Object_GetClampedLevel((intptr_t)arg1);
    if (value1 == 1) {
LAB_0050d3e7:
      Sound_HandleEvent(DAT_0057ba0c,value3,0x29);
      return (float)(uvalue2 + 0x30);
    }
    if (value1 == 2) {
LAB_0050d3cd:
      Sound_HandleEvent(DAT_0057ba0c,value3,0x20);
      return (float)(uvalue2 + 0x40);
    }
    flag4 = value1 == 3;
    break;
  default:
    goto switchD_0050d36a_caseD_e;
  case 0x17:
    value1 = *(int *)(value1 + 100);
    if (value1 == 1) goto LAB_0050d3e7;
    if (value1 == 2) goto LAB_0050d3cd;
    flag4 = value1 == 3;
    break;
  case 0x1d:
    value1 = *(int *)(value1 + 0x6c);
    if (value1 == 1) goto LAB_0050d3e7;
    if (value1 == 2) goto LAB_0050d3cd;
    flag4 = value1 == 3;
    break;
  case 0x1e:
    Sound_HandleEvent(DAT_0057ba0c,value3,0x28);
    return (float)(uvalue2 + 0x10);
  }
  if (flag4) {
    Sound_HandleEvent(DAT_0057ba0c,value3,0x23);
    return (float)(uvalue2 + 0x38);
  }
switchD_0050d36a_caseD_e:
  return arg2;
}
