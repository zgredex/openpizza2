// UI_DrawTextControl: ported from Pizza Connection 2 at 0x52c320.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52c320
#include "pc2_port.h"

void __fastcall UI_DrawTextControl(void *arg1)

{
  char *cptr1;
  char cVar2;
  int value3;
  int value4;
  char *cptr5;
  int value6;
  
  if (*(int *)((intptr_t)arg1 + 0x7c) != 0) {
    value4 = UI_ProcessDialogInput(arg1,(void *)0x0,*(void **)((intptr_t)arg1 + 0x74));
    *(int *)((intptr_t)arg1 + 0x5c) = value4;
    return;
  }
  if ((*(short *)((intptr_t)arg1 + 100) != 0) && (*(short *)((intptr_t)arg1 + 0x66) != 0)) {
    Font_WrapText(*(void **)((intptr_t)arg1 + 0x54),*(char **)((intptr_t)arg1 + 0x74),
                  (intptr_t)*(short *)((intptr_t)arg1 + 100));
    *(uint32_t *)((intptr_t)arg1 + 0x5c) = 0xffffffff;
  }
  if (*(int *)((intptr_t)arg1 + 0x5c) == -1) {
    cptr5 = *(char **)((intptr_t)arg1 + 0x74);
    *(uint32_t *)((intptr_t)arg1 + 0x5c) = 1;
    cVar2 = *cptr5;
    while (cVar2 != '\0') {
      if ((cVar2 == '\n') || (cVar2 == '\r')) {
        *(int *)((intptr_t)arg1 + 0x5c) = *(int *)((intptr_t)arg1 + 0x5c) + 1;
      }
      cptr1 = cptr5 + 1;
      cptr5 = cptr5 + 1;
      cVar2 = *cptr1;
    }
  }
  if (*(short *)((intptr_t)arg1 + 100) < 1) {
    value6 = UI_MeasureTextMaxWidth((intptr_t)arg1);
    value4 = *(int *)((intptr_t)arg1 + 0x38);
    value3 = *(int *)((intptr_t)arg1 + 0x6c);
    *(int *)((intptr_t)arg1 + 0x28) = value4;
    if (value3 != 0) {
      if (value3 == 2) {
        value4 = value4 - value6 / 2;
      }
      else {
        if (value3 != 1) goto LAB_0052c3c7;
        value4 = value4 - value6;
      }
    }
    *(int *)((intptr_t)arg1 + 0x28) = value4;
  }
  else {
    value6 = (intptr_t)*(short *)((intptr_t)arg1 + 100);
  }
LAB_0052c3c7:
  if (*(short *)((intptr_t)arg1 + 0x66) < 1) {
    UI_SetAbsolutePosition(arg1,value6,*(int *)(*(int *)((intptr_t)arg1 + 0x54) + 0x9b0));
    return;
  }
  UI_SetAbsolutePosition(arg1,value6,(intptr_t)*(short *)((intptr_t)arg1 + 0x66));
  return;
}
