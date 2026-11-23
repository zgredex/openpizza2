// UI_WarpCursorToControl: ported from Pizza Connection 2 at 0x4c6780.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c6780
#include "pc2_port.h"

void __cdecl UI_WarpCursorToControl(void *arg1,int arg2)

{
  void *self;
  int value1;
  
  self = arg1;
  value1 = Array_GetRecordByKeyPtr(arg1,arg2);
  if (value1 != 0) {
    arg1 = (void *)((*(int *)(value1 + 0x30) - *(int *)(value1 + 0x28) >> 1) +
                      *(int *)(value1 + 0x38));
    arg2 = (*(int *)(value1 + 0x34) - *(int *)(value1 + 0x2c) >> 1) + *(int *)(value1 + 0x3c);
    UI_OffsetPoint(self,(int *)&arg1,&arg2);
    Window_SetCursorPosition(DAT_0057c5e0,(intptr_t)arg1,arg2,1,1);
  }
  return;
}
