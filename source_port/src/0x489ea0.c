// UI_IsClickOccluded: ported from Pizza Connection 2 at 0x489ea0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x489ea0
#include "pc2_port.h"

uint32_t UI_IsClickOccluded(void *arg1,int arg2)

{
  int value1;
  char cVar2;
  int value3;
  int value4;
  int value5;
  
  cVar2 = Game_GetPlayerByte8(arg2);
  if (cVar2 == '\x01') {
    if (0 < *(int *)(arg2 + 0x10)) {
      return 1;
    }
  }
  else if (cVar2 == '\x02') {
    value1 = *(int *)(arg2 + 0x1c);
    value5 = *(int *)(arg2 + 0x18);
    value4 = value1 + -4;
    value3 = Game_FindRecordByPairChecked(arg1,value5 + -2,value4);
    if ((value3 != 0) && (0 < *(int *)(value3 + 0x10))) {
      return 1;
    }
    value3 = Game_FindRecordByPairChecked(arg1,value5 + -1,value4);
    if ((value3 != 0) && (0 < *(int *)(value3 + 0x10))) {
      return 1;
    }
    value4 = Game_FindRecordByPairChecked(arg1,value5,value4);
    if ((value4 != 0) && (0 < *(int *)(value4 + 0x10))) {
      return 1;
    }
    value4 = value5 + 2;
    value3 = Game_FindRecordByPairChecked(arg1,value4,value1 + -2);
    if ((value3 != 0) && (0 < *(int *)(value3 + 0x10))) {
      return 1;
    }
    value3 = Game_FindRecordByPairChecked(arg1,value4,value1 + -1);
    if ((value3 != 0) && (0 < *(int *)(value3 + 0x10))) {
      return 1;
    }
    value4 = Game_FindRecordByPairChecked(arg1,value4,value1);
    if ((value4 != 0) && (0 < *(int *)(value4 + 0x10))) {
      return 1;
    }
    value4 = value1 + 2;
    value3 = Game_FindRecordByPairChecked(arg1,value5 + -2,value4);
    if ((value3 != 0) && (0 < *(int *)(value3 + 0x10))) {
      return 1;
    }
    value3 = Game_FindRecordByPairChecked(arg1,value5 + -1,value4);
    if ((value3 != 0) && (0 < *(int *)(value3 + 0x10))) {
      return 1;
    }
    value4 = Game_FindRecordByPairChecked(arg1,value5,value4);
    if ((value4 != 0) && (0 < *(int *)(value4 + 0x10))) {
      return 1;
    }
    value5 = value5 + -4;
    value4 = Game_FindRecordByPairChecked(arg1,value5,value1 + -2);
    if ((value4 != 0) && (0 < *(int *)(value4 + 0x10))) {
      return 1;
    }
    value4 = Game_FindRecordByPairChecked(arg1,value5,value1 + -1);
    if ((value4 != 0) && (0 < *(int *)(value4 + 0x10))) {
      return 1;
    }
    value4 = Game_FindRecordByPairChecked(arg1,value5,value1);
    if ((value4 != 0) && (0 < *(int *)(value4 + 0x10))) {
      return 1;
    }
  }
  return 0;
}
