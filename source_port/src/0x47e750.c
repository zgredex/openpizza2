// Game_PickFreeConstructionPlot: ported from Pizza Connection 2 at 0x47e750.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47e750
#include "pc2_port.h"

int __fastcall Game_PickFreeConstructionPlot(int arg1)

{
  int value1;
  int value2;
  int value3;
  int *ptr4;
  int value5;
  uint32_t uvalue6;
  int value7;
  int local_1a8;
  int local_1a4;
  void *local_1a0;
  int *local_19c;
  int local_198;
  int local_194;
  int local_190 [100];
  
  value7 = 0;
  local_194 = *(int *)(arg1 + 0x19ac);
  value1 = *(int *)(arg1 + 0x1514);
  local_1a8 = 0;
  if (local_194 < 1) {
    return -1;
  }
  local_1a0 = (void *)(arg1 + 0x1998);
  local_19c = local_190;
  local_198 = arg1;
  do {
    value2 = local_198;
    value3 = IDMap_Lookup(local_1a0,value7,&local_1a4);
    if (*(int *)(value3 + 0x1c) == 0) {
      value3 = 0;
      if (0 < value1) {
        do {
          ptr4 = (int *)IDMap_Lookup((void *)(value2 + 0x1500),value3,(int *)0x0);
          value5 = *ptr4;
          if (((*(char *)(value5 + 0x824) == '\x03') && (*(char *)(value5 + 0x825) == '\x04')) &&
             (value5 = Game_GetRecordByField814(value5), *(int *)(value5 + 0x88) == local_1a4)) {
            if (value3 < value1) goto LAB_0047e80c;
            break;
          }
          value3 = value3 + 1;
        } while (value3 < value1);
      }
      local_1a8 = local_1a8 + 1;
      *local_19c = value7;
      local_19c = local_19c + 1;
    }
LAB_0047e80c:
    value7 = value7 + 1;
    if (local_194 <= value7) {
      if (local_1a8 == 0) {
        return -1;
      }
      uvalue6 = Random_RangeFast(0,local_1a8 - 1);
      IDMap_Lookup(local_1a0,local_190[uvalue6],&local_1a4);
      return local_1a4;
    }
  } while( true );
}
