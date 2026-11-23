// Game_HasAdjacentOccupiedCell: ported from Pizza Connection 2 at 0x47ce50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47ce50
#include "pc2_port.h"

uint32_t __thiscall Game_HasAdjacentOccupiedCell(void *self,int arg1)

{
  char cVar1;
  void *this_00;
  int value2;
  int value3;
  int value4;
  
  cVar1 = Game_GetPlayerByte8(arg1);
  if (cVar1 != '\x01') {
    return 0;
  }
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(arg1 + 4),(int *)0x0);
  value3 = *(int *)(arg1 + 0x18);
  value4 = *(int *)(arg1 + 0x1c);
  value2 = Game_FindGroupSlot(this_00,*(int *)(*(int *)(*(int *)(*(int *)((intptr_t)self + 0x14e0) + 0x4c)
                                                       + *(int *)(arg1 + 0x20) * 0xc + 8) + 0x10)
                             ,*(int *)(arg1 + 8));
  switch(value2) {
  case 0:
    value4 = value4 + 4;
    value2 = Game_FindRecordByPairChecked(self,value3,value4);
    if ((value2 != 0) && (0 < *(int *)(value2 + 0xc))) {
      return 1;
    }
    value2 = Game_FindRecordByPairChecked(self,value3 + 1,value4);
    if ((value2 != 0) && (0 < *(int *)(value2 + 0xc))) {
      return 1;
    }
    value3 = value3 + 2;
    break;
  case 1:
    value3 = value3 + 4;
    value2 = Game_FindRecordByPairChecked(self,value3,value4 + 2);
    if ((value2 != 0) && (0 < *(int *)(value2 + 0xc))) {
      return 1;
    }
    value2 = Game_FindRecordByPairChecked(self,value3,value4 + 1);
    if ((value2 != 0) && (0 < *(int *)(value2 + 0xc))) {
      return 1;
    }
    break;
  case 2:
    value4 = value4 + -2;
    value2 = Game_FindRecordByPairChecked(self,value3 + 2,value4);
    if ((value2 != 0) && (0 < *(int *)(value2 + 0xc))) {
      return 1;
    }
    value2 = Game_FindRecordByPairChecked(self,value3 + 1,value4);
    if ((value2 != 0) && (0 < *(int *)(value2 + 0xc))) {
      return 1;
    }
    break;
  case 3:
    value3 = value3 + -2;
    value2 = Game_FindRecordByPairChecked(self,value3,value4 + 2);
    if ((value2 != 0) && (0 < *(int *)(value2 + 0xc))) {
      return 1;
    }
    value2 = Game_FindRecordByPairChecked(self,value3,value4 + 1);
    if ((value2 != 0) && (0 < *(int *)(value2 + 0xc))) {
      return 1;
    }
    break;
  default:
    goto switchD_0047ceb0_default;
  }
  value3 = Game_FindRecordByPairChecked(self,value3,value4);
  if ((value3 != 0) && (0 < *(int *)(value3 + 0xc))) {
    return 1;
  }
switchD_0047ceb0_default:
  return 0;
}
