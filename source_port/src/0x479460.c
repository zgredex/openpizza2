// Map_CheckTileEdgeMatch: ported from Pizza Connection 2 at 0x479460.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x479460
#include "pc2_port.h"

uint32_t __thiscall
Map_CheckTileEdgeMatch(void *self,int arg1,int arg2,int arg3,int arg4)

{
  int value1;
  int value2;
  
  value2 = Grid_GetCell(*(void **)((intptr_t)self + 0x14e0),*(int *)(arg3 + 0x18),
                       *(int *)(arg3 + 0x1c));
  value2 = City_IndexOfListValue
                    (DAT_0057c670,*(int *)(*(int *)(value2 + 8) + 0x10),*(int *)(arg3 + 4),
                     *(int *)(arg3 + 8));
  if (value2 != -1) {
    value1 = arg4 + (arg1 * 0x50 + arg2) * 8;
    if (((*(short *)(value1 + 0x14) == 2) && (*(short *)(value1 + 0x294) == 2)) && (value2 == 1)) {
      return 1;
    }
    if (((*(short *)(value1 + -4) == 2) && (*(short *)(value1 + 0x27c) == 2)) && (value2 == 3)) {
      return 1;
    }
    if (((*(short *)(value1 + 0x504) == 2) && (*(short *)(value1 + 0x50c) == 2)) && (value2 == 0)) {
      return 1;
    }
    if (((*(short *)(value1 + -0x27c) == 2) && (*(short *)(value1 + -0x274) == 2)) && (value2 == 2)) {
      return 1;
    }
  }
  return 0;
}
