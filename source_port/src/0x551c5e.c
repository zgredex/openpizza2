// CRT_InsertDecimalPoint: ported from Pizza Connection 2 at 0x551c5e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551c5e
#include "pc2_port.h"

char * __cdecl CRT_InsertDecimalPoint(char *arg1,size_t arg2,int *arg3,char arg4)

{
  int value1;
  int value2;
  char *cptr3;
  
  value1 = arg3[1];
  if ((arg4 != '\0') && (value1 - 1U == arg2)) {
    value2 = *arg3;
    arg1[(uint32_t)(value2 == 0x2d) + (value1 - 1U)] = '0';
    (arg1 + (uint32_t)(value2 == 0x2d) + (value1 - 1U))[1] = '\0';
  }
  cptr3 = arg1;
  if (*arg3 == 0x2d) {
    *arg1 = '-';
    cptr3 = arg1 + 1;
  }
  if (arg3[1] < 1) {
    String_MakeRoomAtFront(cptr3,1);
    *cptr3 = '0';
    cptr3 = cptr3 + 1;
  }
  else {
    cptr3 = cptr3 + arg3[1];
  }
  if (0 < (intptr_t)arg2) {
    String_MakeRoomAtFront(cptr3,1);
    *cptr3 = DAT_00576cf4;
    value1 = arg3[1];
    if (value1 < 0) {
      if ((arg4 != '\0') || (-value1 <= (intptr_t)arg2)) {
        arg2 = -value1;
      }
      String_MakeRoomAtFront(cptr3 + 1,arg2);
      _memset(cptr3 + 1,0x30,arg2);
    }
  }
  return arg1;
}
