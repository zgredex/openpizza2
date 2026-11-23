// Object_ComputeInteractionCell: ported from Pizza Connection 2 at 0x50d4f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50d4f0
#include "pc2_port.h"

float __thiscall Object_ComputeInteractionCell(void *arg1,float arg2)

{
  int value1;
  uint32_t uvalue2;
  bool flag3;
  
                    /* Computes the cell a visitor should occupy next to an object. */
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x110));
  uvalue2 = UI_HitTestChildPoint(arg1,arg2);
  switch(*(uint32_t *)((intptr_t)arg1 + 0x30)) {
  case 0xd:
    value1 = Object_GetClampedLevel((intptr_t)arg1);
    if (value1 == 1) {
LAB_0050d570:
      arg2 = (float)(uvalue2 + 0x48);
      goto LAB_0050d579;
    }
    if (value1 == 2) {
LAB_0050d56b:
      arg2 = (float)(uvalue2 + 0x58);
      goto LAB_0050d579;
    }
    flag3 = value1 == 3;
    break;
  default:
    goto switchD_0050d52a_caseD_e;
  case 0x17:
    value1 = *(int *)(value1 + 100);
    if (value1 == 1) goto LAB_0050d570;
    if (value1 == 2) goto LAB_0050d56b;
    flag3 = value1 == 3;
    break;
  case 0x1d:
    value1 = *(int *)(value1 + 0x6c);
    if (value1 == 1) goto LAB_0050d570;
    if (value1 == 2) goto LAB_0050d56b;
    flag3 = value1 == 3;
    break;
  case 0x1e:
    arg2 = (float)(uvalue2 + 0x18);
    UI_SetChildRecordVariant(arg1,(intptr_t)arg2);
    goto LAB_0050d579;
  }
  if (flag3) {
    arg2 = (float)(uvalue2 + 0x50);
  }
  else {
switchD_0050d52a_caseD_e:
  }
LAB_0050d579:
  value1 = Game_GetPlayerSubmapValue
                    (DAT_0057c670,*(int *)(*(int *)((intptr_t)arg1 + 0xf4) + 8),
                     *(int *)(*(int *)((intptr_t)arg1 + 0xf4) + 0x2c));
  Sound_ProcessEventForSelectedObject(DAT_0057ba0c,value1,*(int *)((intptr_t)arg1 + 0x30),8,'\x01');
  return arg2;
}
