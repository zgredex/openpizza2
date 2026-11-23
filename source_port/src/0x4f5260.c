// Map_PickRandomType355Cell: ported from Pizza Connection 2 at 0x4f5260.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5260
#include "pc2_port.h"

uint32_t __cdecl Map_PickRandomType355Cell(uint32_t arg1,uint8_t arg2)

{
  int value1;
  uint32_t uvalue2;
  int extraout_ECX;
  int value3;
  int value4;
  int *ptr5;
  int value6;
  int *ptr7;
  int *ptr8;
  int value9;
  uint8_t unaff_retaddr;
  
  __chkstk(unaff_retaddr);
  value1 = *(int *)(extraout_ECX + 0x20);
  value9 = 0;
  if (0 < value1) {
    value3 = 0;
    do {
      value6 = *(int *)(extraout_ECX + 0x1c);
      value4 = value3;
      if (0 < value6) {
        value4 = value3 + value6;
        ptr5 = (int *)(*(int *)(extraout_ECX + 0x4c) + 8 + value3 * 0xc);
        ptr7 = (int *)(&arg2 + value9 * 4);
        do {
          value3 = *ptr5;
          ptr8 = ptr7;
          if ((((value3 != 0) && (*(int *)(value3 + 4) == 0x355)) && (*(short *)(value3 + 0x24) != -1))
             && (*(int *)(value3 + 0x28) != 0)) {
            value9 = value9 + 1;
            ptr8 = ptr7 + 1;
            *ptr7 = *(int *)(extraout_ECX + 0x9c) + *(short *)(value3 + 0x24) * 0x28;
          }
          ptr5 = ptr5 + 3;
          value6 = value6 + -1;
          ptr7 = ptr8;
        } while (value6 != 0);
      }
      value1 = value1 + -1;
      value3 = value4;
    } while (value1 != 0);
    if (0 < value9) {
      uvalue2 = Random_RangeFast(0,value9 - 1);
      return *(uint32_t *)(&arg2 + uvalue2 * 4);
    }
  }
  return 0;
}
