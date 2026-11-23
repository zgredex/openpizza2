// Person_DecideWaitOrLeaveHouse: ported from Pizza Connection 2 at 0x506c00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x506c00
#include "pc2_port.h"

void __fastcall Person_DecideWaitOrLeaveHouse(void *arg1)

{
  uint32_t uvalue1;
  uint32_t unaff_ESI;
  void *pvVar2;
  int value3;
  
  switch(*(uint32_t *)((intptr_t)arg1 + 0x30)) {
  default:
    if ((*(int *)((intptr_t)arg1 + 0xd0) != 0) &&
       ((value3 = *(int *)(*(int *)((intptr_t)arg1 + 0xd0) + 4), value3 == 6 || (value3 == 5)))) {
      Object_SetState(arg1,0x1d);
      return;
    }
    uvalue1 = Game_GetTimeSegment(DAT_0057c670);
    switch(uvalue1) {
    case 0:
    case 1:
      pvVar2 = (void *)0x5a;
      break;
    case 2:
    case 6:
      pvVar2 = (void *)0x3c;
      break;
    case 3:
    case 5:
      pvVar2 = (void *)0x14;
      break;
    case 4:
      pvVar2 = (void *)0x28;
      break;
    case 7:
      pvVar2 = (void *)0x46;
      break;
    default:
      pvVar2 = arg1;
    }
    uvalue1 = Random_RangeFast(1,100);
    if ((intptr_t)pvVar2 < (intptr_t)uvalue1) goto switchD_00506c17_caseD_d;
  case 10:
  case 0xb:
  case 0xf:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x18:
  case 0x21:
  case 0x23:
    value3 = 4;
    break;
  case 0xd:
  case 0x10:
  case 0x16:
switchD_00506c17_caseD_d:
    value3 = 0x1d;
    break;
  case 0x17:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    value3 = *(int *)(*(int *)((intptr_t)arg1 + 0xcc) + 4);
    if (value3 == 0x17) goto switchD_00506c17_caseD_d;
    if (value3 != 0x1c) goto LAB_00506cbd;
    value3 = 4;
  }
  Object_SetState(arg1,value3);
LAB_00506cbd:
  if (*(void **)(DAT_0057c670 + 0x21c) == arg1) {
    if (*(int *)((intptr_t)arg1 + 0x38) == 4) {
      DebugConsole_Printf(DAT_0057c1e0,0,(uint8_t *)s_Status__Person_wartet__00572edc,unaff_ESI);
    }
    else if (*(int *)((intptr_t)arg1 + 0x38) == 0x1d) {
      DebugConsole_Printf(DAT_0057c1e0,0,&DAT_00572ef4,unaff_ESI);
      return;
    }
  }
  return;
}
