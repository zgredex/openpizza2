// Rating_UpdateBarByKey: ported from Pizza Connection 2 at 0x4a80e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4a80e0
#include "pc2_port.h"

void __cdecl Rating_UpdateBarByKey(void *arg1,int arg2,int arg3,int arg4,int arg5)

{
  int value1;
  int value2;
  char local_100 [256];
  
                    /* Draws a 17-segment rating bar and caption. */
  local_100[0] = '\0';
  if (arg5 != 0) {
    if ((arg3 < 0) || (7 < arg3)) {
      String_Format(local_100,DAT_00580f54,arg5);
    }
    else {
      String_Format(local_100,DAT_00580f44,arg5);
    }
  }
  if (arg3 < 0) {
    arg3 = 0;
  }
  value2 = 0;
  value1 = (&DAT_00569288)[arg3] + -0x10 + arg2;
  do {
    UI_RemoveObjectByKey(arg1,value2 + value1);
    value2 = value2 + 1;
  } while (value2 < 0x11);
  if (arg4 < 0) {
    arg4 = 0;
  }
  else if (100 < arg4) {
    arg4 = 100;
  }
  value2 = (arg4 * 0x10 + 0x32) / 100;
  if (100 < value2) {
    value2 = 100;
  }
  value2 = value2 + value1;
  UI_ShowChildByID(arg1,value2);
  if (local_100[0] == '\0') {
    UI_ReleaseChildBufferByKey(arg1,value2);
    return;
  }
  UI_SetObjectTextByKey(arg1,value2,local_100);
  return;
}
