// City_HasRoomForBuilding: ported from Pizza Connection 2 at 0x479c20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x479c20
#include "pc2_port.h"

uint32_t __fastcall City_HasRoomForBuilding(void *arg1)

{
  uint8_t flag1;
  int value2;
  char cVar3;
  int value4;
  int value5;
  
  value4 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)arg1 + 0x34),(int *)0x0);
  flag1 = *(uint8_t *)(*(int *)(DAT_0057c670 + 0x94) + 8);
  if (flag1 == 3 || flag1 < 3) {
    cVar3 = *(char *)(value4 + 0xa4 + (uint32_t)flag1 * 4);
  }
  else {
    cVar3 = '\0';
  }
  value4 = (intptr_t)cVar3;
  if (value4 < 0x10) {
    value5 = Game_CountRecordsByByteC(arg1,6);
    value2 = *(int *)((intptr_t)arg1 + 0x38);
    if ((-1 < value2) && (value2 < 3)) {
      value4 = value4 + *(int *)(&DAT_005675ac + value2 * 4) * value5;
    }
    if (value4 < 0x10) {
      return 1;
    }
  }
  return 0;
}
