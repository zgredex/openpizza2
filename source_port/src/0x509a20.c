// Branch_ComputeAdvisorTipId: ported from Pizza Connection 2 at 0x509a20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509a20
#include "pc2_port.h"

void __fastcall
Branch_ComputeAdvisorTipId(int arg1,uint32_t arg2,void *arg3,void *arg4,int arg5)

{
  int value1;
  int value2;
  uint32_t extraout_EDX;
  bool flag3;
  bool flag4;
  
                    /* Chooses the advisor tip id for a branch from its ratings and turnover. */
  value2 = *(int *)(arg1 + 0x34);
  if ((*(void **)((intptr_t)arg3 + 0x16f0) != (void *)0x0) &&
     (value1 = Game_CountFreeBuildingsByType(*(void **)((intptr_t)arg3 + 0x16f0),0x16),
     arg2 = extraout_EDX, 0 < value1)) {
    switch(value2) {
    case 0:
      flag4 = SBORROW4(value1,3);
      flag3 = value1 + -3 < 0;
      break;
    case 1:
      goto switchD_00509a46_caseD_1;
    case 2:
      flag4 = SBORROW4(value1,4);
      flag3 = value1 + -4 < 0;
      break;
    case 3:
      flag4 = SBORROW4(value1,5);
      flag3 = value1 + -5 < 0;
      break;
    default:
      goto switchD_00509a46_default;
    }
    if (flag4 == flag3) {
switchD_00509a46_default:
      *(uint32_t *)(arg1 + 0x9c) = 100;
      return;
    }
  }
switchD_00509a46_caseD_1:
  value1 = Branch_ComputeBuildingRating(arg3,arg2,value2);
  if (value1 < 0x1e) {
    *(uint32_t *)(arg1 + 0x9c) = 0x66;
    return;
  }
  value1 = Stats_GetAverage8(arg3,value2);
  if (value1 < 0x14) {
    *(uint32_t *)(arg1 + 0x9c) = 0x68;
    return;
  }
  value1 = Index_Map8To5(arg4,value2);
  if (value1 < 0x1e) {
    *(uint32_t *)(arg1 + 0x9c) = 0x65;
    return;
  }
  Game_InitStatBaselines(arg3,value2,'\x01');
  if (*(int *)((intptr_t)arg3 + value2 * 4 + 0x181c) < 0x14) {
    *(uint32_t *)(arg1 + 0x9c) = 0x67;
    return;
  }
  Game_InitStatBaselines(arg3,value2,'\0');
  value2 = City_HasRoomForBuilding(arg3);
  if (value2 != 0) {
    *(uint32_t *)(arg1 + 0x9c) = 0x6a;
    return;
  }
  if (arg5 < 0x55) {
    if (arg5 < 0x46) {
      if (arg5 < 0x37) {
        if (arg5 < 0x2d) {
          if (arg5 < 0x1e) {
            if (arg5 < 0xf) {
              *(uint32_t *)(arg1 + 0x9c) = 0x72;
            }
            else {
              *(uint32_t *)(arg1 + 0x9c) = 0x6d;
            }
          }
          else {
            *(uint32_t *)(arg1 + 0x9c) = 0x71;
          }
        }
        else {
          *(uint32_t *)(arg1 + 0x9c) = 0x70;
        }
      }
      else {
        *(uint32_t *)(arg1 + 0x9c) = 0x6f;
      }
    }
    else {
      *(uint32_t *)(arg1 + 0x9c) = 0x6e;
    }
  }
  else {
    *(uint32_t *)(arg1 + 0x9c) = 0x6d;
  }
  if ((0x45 < arg5) &&
     (value2 = *(int *)((intptr_t)arg3 + 0x30), value1 = Game_GetCurrentPlayerCompanyName(DAT_0057c670),
     value2 == value1)) {
    UI_AppendCommandIfActive(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x1d,1);
    MissionGoal_HandleEvent(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x1d,-1,-1);
  }
  return;
}
