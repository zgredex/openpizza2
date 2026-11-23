// Stats_GetGlobalMaximum: ported from Pizza Connection 2 at 0x4b0710.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b0710
#include "pc2_port.h"

int Stats_GetGlobalMaximum(void)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  int value4;
  int value5;
  int local_4;
  
  value4 = 0;
  uvalue3 = (uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10);
  local_4 = 0;
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,local_4);
    if (((value1 != 0) && ((&DAT_0056a644)[local_4] != '\0')) && (value5 = 0, uvalue3 != 0)) {
      do {
        value2 = IDMap_Lookup((void *)(value1 + 0x19c),value5,(int *)0x0);
        switch(DAT_0056a68c) {
        case 0:
          value2 = *(int *)(value2 + 300) + *(int *)(value2 + 0x128) + *(int *)(value2 + 0x124) +
                  *(int *)(value2 + 0x120);
          goto joined_r0x004b07e3;
        case 1:
          value2 = *(int *)(value2 + 0x13c) + *(int *)(value2 + 0x138) + *(int *)(value2 + 0x134) +
                  *(int *)(value2 + 0x130);
joined_r0x004b07e3:
          if (value2 <= value4) goto switchD_004b077c_default;
          goto LAB_004b08d2;
        case 2:
          value2 = *(int *)(value2 + 0x14c) + *(int *)(value2 + 0x148) + *(int *)(value2 + 0x144) +
                  *(int *)(value2 + 0x140);
          break;
        case 3:
          value2 = *(int *)(value2 + 0x19c) + *(int *)(value2 + 0x198) + *(int *)(value2 + 0x194) +
                  *(int *)(value2 + 400);
          break;
        case 4:
          value2 = *(int *)(value2 + 0x16c) + *(int *)(value2 + 0x168) + *(int *)(value2 + 0x164) +
                  *(int *)(value2 + 0x160);
          break;
        case 5:
          value2 = *(int *)(value2 + 0x17c) + *(int *)(value2 + 0x178) + *(int *)(value2 + 0x174) +
                  *(int *)(value2 + 0x170);
          break;
        case 6:
          value2 = *(int *)(value2 + 0x18c) + *(int *)(value2 + 0x188) + *(int *)(value2 + 0x184) +
                  *(int *)(value2 + 0x180);
          break;
        case 7:
          value2 = *(int *)(value2 + 0x15c) + *(int *)(value2 + 0x158) + *(int *)(value2 + 0x154) +
                  *(int *)(value2 + 0x150);
          break;
        case 0xffffffff:
          if (value4 < *(int *)(value2 + 0x11c)) {
            value4 = *(int *)(value2 + 0x11c);
          }
        default:
          goto switchD_004b077c_default;
        }
        if (value4 < value2) {
LAB_004b08d2:
          value4 = value2;
        }
switchD_004b077c_default:
        value5 = value5 + 1;
      } while (value5 < (intptr_t)uvalue3);
    }
    local_4 = local_4 + 1;
    if (5 < local_4) {
      return value4;
    }
  } while( true );
}
