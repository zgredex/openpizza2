// Window_UpdateTooltip: ported from Pizza Connection 2 at 0x526100.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526100
#include "pc2_port.h"

void __fastcall Window_UpdateTooltip(void *arg1)

{
  int value1;
  DWORD DVar2;
  char *cptr3;
  int *ptr4;
  int value5;
  
  value5 = -1;
  if ((*(int *)((intptr_t)arg1 + 0x82dc) != 0) && (*(int *)((intptr_t)arg1 + 0x82f0) == 0)) {
    DVar2 = timeGetTime();
    if ((*(uint32_t *)((intptr_t)arg1 + 0x82e0) < DVar2) &&
       (*(int *)(*(int *)((intptr_t)arg1 + 0x244) + 0x14) == 0)) {
      cptr3 = (char *)Object_GetField0C(*(int *)((intptr_t)arg1 + 0x82dc));
      if (cptr3 != (char *)0x0) {
        UI_ShowTooltip(arg1,cptr3,-999,-999);
      }
      *(uint32_t *)((intptr_t)arg1 + 0x82e0) = 0xffffffff;
      *(uint32_t *)((intptr_t)arg1 + 0x82f0) = 1;
    }
  }
  if ((*(int *)((intptr_t)arg1 + 0x83ac) != 0) && (*(int *)(*(int *)((intptr_t)arg1 + 0x83ac) + 8) != 0)
     ) {
    *(uint32_t *)((intptr_t)arg1 + 0x234) = 1;
  }
  CS_Enter(*(int *)((intptr_t)arg1 + 0x1c8));
  if ((*(int *)((intptr_t)arg1 + 0x234) == 0) && (*(int *)((intptr_t)arg1 + 0x1a4) == -999)) {
    value5 = 0;
    if (0 < *(int *)((intptr_t)arg1 + 0x23c)) {
      ptr4 = (int *)((intptr_t)arg1 + 0x14);
      do {
        value1 = *ptr4;
        if (((value1 != 0) && (*(int *)(value1 + 0x4c) != 0)) &&
           ((*(int *)(value1 + 0xe0) != 0 || (*(int *)(value1 + 0x38) != -999)))) break;
        value5 = value5 + 1;
        ptr4 = ptr4 + 1;
      } while (value5 < *(int *)((intptr_t)arg1 + 0x23c));
    }
  }
  if (value5 < *(int *)((intptr_t)arg1 + 0x23c)) {
    Window_RenderFrame(arg1);
  }
  CS_Leave(*(int *)((intptr_t)arg1 + 0x1c8));
  return;
}
