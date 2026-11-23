// Time_IsInActiveRange: ported from Pizza Connection 2 at 0x552775.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552775
#include "pc2_port.h"

bool __cdecl Time_IsInActiveRange(int *arg1)

{
  int value1;
  bool flag2;
  int value3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  
  if (DAT_00576a34 != 0) {
    uvalue6 = arg1[5];
    if ((uvalue6 != DAT_00576ac8) || (uvalue6 != DAT_00576ad8)) {
      if (DAT_00585670 == 0) {
        Game_SetDateTime(1,1,uvalue6,4,1,0,0,2,0,0,0);
        Game_SetDateTime(0,1,arg1[5],10,5,0,0,2,0,0,0);
      }
      else {
        if (DAT_00585710 != 0) {
          uvalue7 = (uint32_t)DAT_00585716;
          uvalue4 = 0;
          uvalue5 = 0;
        }
        else {
          uvalue4 = (uint32_t)DAT_00585714;
          uvalue7 = 0;
          uvalue5 = (uint32_t)DAT_00585716;
        }
        Game_SetDateTime(1,(uint32_t)(DAT_00585710 == 0),uvalue6,(uint32_t)DAT_00585712,uvalue5,uvalue4,uvalue7,
                         (uint32_t)DAT_00585718,(uint32_t)DAT_0058571a,(uint32_t)DAT_0058571c,(uint32_t)DAT_0058571e
                        );
        if (DAT_005856bc != 0) {
          uvalue7 = (uint32_t)DAT_005856c2;
          uvalue4 = 0;
          uvalue5 = 0;
          uvalue6 = arg1[5];
        }
        else {
          uvalue4 = (uint32_t)DAT_005856c0;
          uvalue7 = 0;
          uvalue5 = (uint32_t)DAT_005856c2;
          uvalue6 = arg1[5];
        }
        Game_SetDateTime(0,(uint32_t)(DAT_005856bc == 0),uvalue6,(uint32_t)DAT_005856be,uvalue5,uvalue4,uvalue7,
                         (uint32_t)DAT_005856c4,(uint32_t)DAT_005856c6,(uint32_t)DAT_005856c8,(uint32_t)DAT_005856ca
                        );
      }
    }
    value1 = arg1[7];
    if (DAT_00576acc < DAT_00576adc) {
      if ((DAT_00576acc <= value1) && (value1 <= DAT_00576adc)) {
        if ((DAT_00576acc < value1) && (value1 < DAT_00576adc)) {
          return true;
        }
LAB_005528ed:
        value3 = ((arg1[2] * 0x3c + arg1[1]) * 0x3c + *arg1) * 1000;
        if (value1 == DAT_00576acc) {
          flag2 = DAT_00576ad0 <= value3;
        }
        else {
          flag2 = value3 < DAT_00576ae0;
        }
        return flag2;
      }
    }
    else {
      if (value1 < DAT_00576adc) {
        return true;
      }
      if (DAT_00576acc < value1) {
        return true;
      }
      if ((value1 <= DAT_00576adc) || (DAT_00576acc <= value1)) goto LAB_005528ed;
    }
  }
  return false;
}
